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

#ifndef _JACKIO_H_
#define _JACKIO_H_

#include <sys/time.h>

#include <jack/jack.h>
#include <jack/midiport.h>
#include <jack/ringbuffer.h>

#include <stdio.h>
#include <string.h>

extern const char* appName;

struct midiMessage 
	{
	unsigned char	midiData[3];
	int		length;
	jack_nframes_t	timestamp;
	};


//alias our sample typedef to something easier to type
typedef jack_default_audio_sample_t sample_t;

double nframes_to_ms(jack_nframes_t);
void queue_message(struct midiMessage*);
void queue_message(double ms,int c,int b0, int b1, int b2);
void queue_new_message(int,int, int, int);
void process_midi_output(jack_nframes_t);
int jack_processCallback (jack_nframes_t, void*);
int jack_setSampleRate (jack_nframes_t, void*);
void jack_errorCallback (const char*);
void jack_shutdown (void*);

double getJackTime();

int initJACK();
int disconnectJACK();



#endif //_JACKIO_H_
