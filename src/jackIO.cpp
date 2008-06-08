/***************************************************************************
 *   Copyright (C) 2008 by Pete Black   *
 *   pete@marchingcubes.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "jackIO.h"

//JACK-specific structures
jack_port_t* jackOut;
jack_client_t* jackClientObject;
jack_ringbuffer_t* jackBuffer;
jack_options_t clientOptions=JackNullOption;
jack_nframes_t sampleRate;

int backendInitialised=0;

//MIDI output requires rate limiting?
double rateLimit=0.0;
int time_offsets_are_zero=0;


int midiChannel=0;
//default buffersize
int bufferSize=1024*sizeof(struct midiMessage);



double nframes_to_ms(jack_nframes_t nframes)
	{
	return (nframes * 1000.0) / (double)sampleRate;
	}

//-----------BEGIN MIDI functions - constructing and sending MIDI events-----------------------------------


//this is suitable for queuing future events in the buffer
void queue_message(struct midiMessage* ev)
	{
	int		written;

	if (jack_ringbuffer_write_space(jackBuffer) < sizeof(*ev)) 
		{
		fprintf(stderr,"WARNING: Not enough space in the ringbuffer, NOTE LOST.\n");
		return;
		}

	//Write the event to our JACK buffer
	written = jack_ringbuffer_write(jackBuffer, (char*)ev, sizeof(*ev));
	
	//fprintf(stderr,"Wrote midiMessage to ringBuffer\n");
	if (written != sizeof(*ev))
		{fprintf(stderr,"WARNING: jack_ringbuffer_write failed, NOTE LOST.\n");}
	}


void queue_message(double ms,int c,int b0, int b1, int b2)
	{
	struct midiMessage ev;

	/* For MIDI messages that specify a channel number, filter the original
	   channel number out and add our own. */
	if (b0 >= 0x80 && b0 <= 0xEF) {
		b0 &= 0xF0;
		b0 += c;
	}

	if (b1 == -1) {
		ev.length = 1;
		ev.midiData[0] = b0;

	} else if (b2 == -1) {
		ev.length = 2;
		ev.midiData[0] = b0;
		ev.midiData[1] = b1;

	} else {
		ev.length = 3;
		ev.midiData[0] = b0;
		ev.midiData[1] = b1;
		ev.midiData[2] = b2;
	}

	if (backendInitialised)
		{
		ev.timestamp = ms*sampleRate/1000;
		//fprintf(stderr,"DEBUG queue_message: %d %d %d %d %d\n",ev.timestamp,c,b0,b1,b2);
		queue_message(&ev);
		}
	else
		{
		fprintf(stderr,"DEBUG: %f %d %d %d %d\n",ms,c,b0,b1,b2);
		}
	
	}


//this is suitable for realtime note playback - assigning a timestamp of 'now'
void queue_new_message(int c,int b0, int b1, int b2)
	{
	struct midiMessage ev;

	/* For MIDI messages that specify a channel number, filter the original
	   channel number out and add our own. */
	if (b0 >= 0x80 && b0 <= 0xEF) {
		b0 &= 0xF0;
		b0 += c;
	}

	if (b1 == -1) {
		ev.length = 1;
		ev.midiData[0] = b0;

	} else if (b2 == -1) {
		ev.length = 2;
		ev.midiData[0] = b0;
		ev.midiData[1] = b1;

	} else {
		ev.length = 3;
		ev.midiData[0] = b0;
		ev.midiData[1] = b1;
		ev.midiData[2] = b2;
	}

	if (backendInitialised)
		{
		ev.timestamp = jack_frame_time(jackClientObject);
		queue_message(&ev);
		}
	else
		{
		fprintf(stderr,"DEBUG: %d %d %d\n",b0,b1,b2);
		}
}


double getJackTime()
	{
	return nframes_to_ms(jack_last_frame_time(jackClientObject));
	}

//-----------END   MIDI functions - constructing and sending MIDI events-----------------------------------





//-----------BEGIN jack Callback functions - these are invoked by JACK once a client is registered.--------



//This is where most of the work gets done, iterating through our queued events and stuffing them into
//the JACK output port if their timestamps match with the current timeframe that JACK is grabbing frames for.

void process_midi_output(jack_nframes_t nframes)
	{
	//TODO: remove the fprintfs from this function, as they could trigger unwanted xruns.
	
	int read, t;
	
	unsigned char* buffer;
	
	void* port_buffer;
	
	jack_nframes_t last_frame_time;
	
	struct midiMessage ev;

	
	//the last frame # that JACK played.
	last_frame_time = jack_last_frame_time(jackClientObject);

	//get our output port buffer from JACK
	port_buffer = jack_port_get_buffer(jackOut, nframes);
	
	if (port_buffer == NULL) 
		{
		fprintf(stderr,"WARNING: jack_port_get_buffer failed, cannot send anything.\n");
		return;
		}
	
	//if theres anything in the port_buffer (there shouldnt be?), destroy it.
	jack_midi_clear_buffer(port_buffer);

	/* We may push at most one byte per 0.32ms to stay below 31.25 Kbaud limit.  - only true for legacy hardware?*/
	//bytes_remaining = nframes_to_ms(nframes) * rateLimit;

	//we need to loop over the midiEvents we have queued in the JACK ring buffer
	//fprintf(stderr,"calling process_midi_output_ at nframes: %d\n",last_frame_time+nframes);
	int looped=0;
	jack_nframes_t first_message_in_buffer=0;
	
	while (jack_ringbuffer_read_space(jackBuffer) && looped==0) 
		{
		//fprintf(stderr,"in process_midi_output\n");
		//Check we have a complete event sitting in our JACK buffer
		read = jack_ringbuffer_peek(jackBuffer, (char *)&ev, sizeof(ev));

		if (read != sizeof(ev)) 
			{
			//we have an event fragment in the ringbuffer, throw it away.
			fprintf(stderr,"WARNING: Short read from the ringbuffer, possible note loss.\n");
			jack_ringbuffer_read_advance(jackBuffer, read);
			continue;
			}

		if (first_message_in_buffer==ev.timestamp)
			{
			//fprintf(stderr,"looped, breaking\n");
			looped=1;
			break;
			}
		
		//bytes_remaining -= ev.length;

		//if (rateLimit > 0.0 && bytes_remaining <= 0) 
		//		{
		//	fprintf(stderr,"WARNING: Rate limiting in effect\n");
		//	break;
		//	}
		
		//figure out at what time the last byte in the buffer will be played
		t = ev.timestamp + nframes - last_frame_time;
		//fprintf(stderr,"ev.timestamp: %d, last_frame_time: %d\n",ev.timestamp,last_frame_time);
		/* If computed time is too much into the future, we'll need
		   to send it later. */
		if (t >= (int)nframes)
			{
			//fprintf(stderr,"Event in future! t %d ev.timestamp %d nframes %d lasT_frame_time %d \n",t,ev.timestamp,nframes,last_frame_time);
			jack_ringbuffer_read_advance(jackBuffer, sizeof(ev));
			if (! first_message_in_buffer)
				{
				first_message_in_buffer=ev.timestamp;
				}
			//tack our future event onto the end of our ringbuffer for future processing.
			queue_message(&ev);
			//break;
			}
		else
			{
			/* If computed time is < 0, we missed a cycle because of xrun. */
			if (t < 0)
				t = 0;

			//TODO: not sure what this does - remove?
			//if (time_offsets_are_zero)
			//	t = 0;
		
			//pull our event out of our JACK buffer
			//fprintf(stderr,"Advancing to next event in buffer\n");
			jack_ringbuffer_read_advance(jackBuffer, sizeof(ev));
		

			//ensure we have space to write our event into the JACK output port
			buffer = jack_midi_event_reserve(port_buffer, t, ev.length);
			
			//
				
			if (buffer == NULL) 
				{
				fprintf(stderr,"t %d, ev.timestamp: %d, last_frame_time: %d\n",t,ev.timestamp,last_frame_time);
				fprintf(stderr,"WARNING: jack_midi_event_reserve failed, NOTE LOST.\n");
				break;
				}

			//do the actual memcopy to send the event to JACK.
			//fprintf(stderr,"Sending midi event\n");
			memcpy(buffer, ev.midiData, ev.length);
			}
		}
	}



int jack_processCallback (jack_nframes_t nframes, void* arg)
	{
	process_midi_output(nframes);			   
  	return 0;      
	}

int jack_setSampleRate (jack_nframes_t nframes, void *arg)
	{
	fprintf (stderr,"JACK: the sample rate is now %lu/sec\n", (long)nframes);
  	sampleRate=nframes;
  	return 0;
	}

void jack_errorCallback (const char* desc)
	{
	fprintf (stderr, "ERROR (JACK): %s\n", desc);
	}

void jack_shutdown (void* arg)
	{
	fprintf(stderr,"Got JACK shutdown signal!");
	//exit(1);
	}

//-----------END jack Callback functions - these are invoked by JACK once a client is registered.--------


int initJACK()
	{
        //Setup our JACK MIDI interface
	
	//Register an error handler
	jack_set_error_function (jack_errorCallback);
        
	//Attempt to open a client handle for our application
	jackClientObject=jack_client_open(appName,clientOptions,NULL);
	
	//jack_client_open returns 0 on failure
	if (jackClientObject)
		{
		//create our ringbuffer
		jackBuffer = jack_ringbuffer_create(bufferSize);
		
		//register the handler that will do the work of filling our buffer
		jack_set_process_callback (jackClientObject, jack_processCallback, 0);
		
		//in case our sample rate changes, we need to update our timing 
		jack_set_sample_rate_callback (jackClientObject, jack_setSampleRate, 0);
		
		//when jack shuts down, this routine will be called
		jack_on_shutdown (jackClientObject, jack_shutdown, 0);
		
		//initialise our sampleRate variable
		sampleRate=jack_get_sample_rate (jackClientObject);
		
		//Notify user of sample rate
		fprintf (stderr,"JACK: engine sample rate: %lu\n",(long)sampleRate);
		
		//Attempt to register a MIDI port for output
		jackOut=jack_port_register(jackClientObject,"stepsequencer_out",JACK_DEFAULT_MIDI_TYPE,JackPortIsOutput,bufferSize);
		
		//jack_activate signals JACK we are ready for it to start invoking our callbacks
		if (jack_activate (jackClientObject)) 
			{
    			//We were not able to activate JACK. 
			fprintf (stderr, "ERROR: JACK client activation error!");
  			return 0;
			}
		}
	else
		{
		//If we can't even jack_client_open, all bets are off.
		fprintf (stderr, "ERROR: JACK Client creation error.\n\n");
		return 0;
		}	
	//return 1 for success
	backendInitialised=1;
	return 1;
	}

//misc functions

int disconnectJACK()
	{
	//fprintf(stderr,"Unregister port\n");
	jack_port_unregister(jackClientObject,jackOut);	
	//fprintf(stderr,"close client\n");
	jack_client_close(jackClientObject);
	//fprintf(stderr,"free ringbuffer\n");
	jack_ringbuffer_free(jackBuffer);
	return 0;
	}

