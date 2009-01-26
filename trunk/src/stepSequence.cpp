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

#include "stepSequence.h"


step::step()
	{
	//constructor
	//set to defaults
	//fprintf(stderr,"DEBUG: step::step() - Creating step\n");
	isOn=0;
	noteNumber=64;
	noteLength=1;
	noteVelocity=64;
	noteTonality=0;
	}

step::step(int o,int nN, int nL, int nV,int nT)
	{
	//fprintf(stderr,"DEBUG: step::step(int,int,int,int) - Creating step\n");
	isOn=o;
	noteNumber=nN;
	noteLength=nL;
	noteVelocity=nV;
	noteTonality=nT;
	}

step::~step()
	{
	//destructor
	//fprintf(stderr,"DEBUG: step::~step() - Destroying step\n");
	}

void step::serialise(FILE* file)
	{
	fprintf(file,"step:%d|%d|%d|%d|%d\n",isOn,noteNumber,noteLength,noteVelocity,noteTonality);
	}

stepSequence::stepSequence()
	{
	//fprintf(stderr,"DEBUG: stepSequence::stepSequence() - Creating stepSequence\n");
		
	
	sequenceName=QString("Default Sequence Name");
	sequenceType=QString("synth part");
	
	muted=0;
	midiChannel=0;		
	selectedStep=-1;
	drumSequence=0;
	drumNote=0;
	arp=false;
	arpCounter=0;
	
	//fill our sequence with steps
	for (int i=0;i<MAX_STEPS;i++)
		{
		stepArray[i]=new step(0,40,1,64,0); //default - E2, 1 step length, 64 velocity, no tonality
		arpArray[i]=new step(0,40,1,64,0); //init arpArray to something, even though we will overwrite this when we calculate our arp pattern.
		}

	}

stepSequence::~stepSequence()
	{
	//destructor
	for (int i=0;i<MAX_STEPS;i++)
		{
		if (stepArray[i])
			{
			delete stepArray[i];
			}
		else
			{
			fprintf(stderr,"EPIC FAIL: Delete-ing a null step. This should never happen.");
			}
		}
	}



step* stepSequence::getStep(int stepId)
	{
	step* myStep;
	myStep=stepArray[stepId];
	return myStep;
	}

step* stepSequence::getArpStep(int stepId)
	{
	step* myStep;
	myStep=arpArray[stepId];
	return myStep;
	}


const char* stepSequence::getSequenceName()
	{
	return sequenceName.ascii();
	}

const char* stepSequence::getSequenceType()
	{
	return sequenceType.ascii();
	}

void stepSequence::setMuted(int m)
	{
	muted=m;
	}

int stepSequence::getMidiChannel()
	{
	return midiChannel;
	}

void stepSequence::setMidiChannel(int c)
	{
	midiChannel=c;
	}

int stepSequence::getMuted()
	{
	return muted;
	}

void stepSequence::setSequenceName(const char* name)
	{
	//TODO: using QString for brain-dead simplicity, but maybe use a char* for non-Qt portability.
	sequenceName=name;
	}

void stepSequence::setSequenceType(const char* type)
	{
	//TODO: using QString for brain-dead simplicity, but maybe use a char* for non-Qt portability.
	sequenceType=type;
	}

void stepSequence::setSequenceLength(int steps)
	{
	//fprintf(stderr,"DEBUG: stepSequence::setSequenceLength setting sequence %s length to %d steps\n",getSequenceName(),steps);
	sequenceLength=steps;
	}

void stepSequence::serialise(FILE* file)
	{
	fprintf(file,"sequence:%s|%s|%d|%d|%d|%d|%d\n",sequenceName.ascii(),sequenceType.ascii(),muted,selectedStep,midiChannel,drumSequence,drumNote);
	for (int i=0;i<MAX_STEPS;i++)
		{
		stepArray[i]->serialise(file);
		}
	}

void stepSequence::clearArp()
	{
	for (int i=0;i < MAX_STEPS;i++)
		{
		step* arpStep=arpArray[i];
		arpStep->isOn=0;
		}
	}

void stepSequence::arpeggiate()
	{
	//TODO: stub method for testing - this should take some arguments for tonality, note length, speed and direction.
	
	//for now lets just construct an ascending minor arpeggio on 16th notes
	int baseNote=0;
	int tonality=0;
	//clear our arpeggio data
	for (int i=0;i < MAX_STEPS;i++)
		{
		step* arpStep=arpArray[i];
		arpStep->isOn=0;
		}

	//now lets write some notes into our arp buffer.
	for (int i=0;i < MAX_STEPS;i++)
		{
		step* myStep=stepArray[i];
		if (myStep->isOn == 1)
			{
			baseNote=myStep->noteNumber;
			tonality=myStep->noteTonality;
			arpCounter=0;
			}
		else
			{
			//for now, lets just echo the notes an octave up into our arpArray
			step* arpStep=arpArray[i];
			arpStep->noteNumber=baseNote+getNextArpOffset(tonality);
			//fprintf(stderr,"setting step %d to note %d\n",i,arpStep->noteNumber);
			baseNote=arpStep->noteNumber;
			arpStep->noteLength=1;
			arpStep->isOn=1;
			}
		}
	

	
	}

int stepSequence::getNextArpOffset(int tonality)
	{
	//major - W W H W W W H W W H W W W H
	//minor - W H W W W H W W H W W W H W
	//default to an ping-pong octave thing
	
	int patternLength=3;
	int defaultArray[] = {12,24,-12,-24};	
	int arpOffset=defaultArray[arpCounter];

	int majArray[] = {4,3,4,3,-14};
        int minArray[] = {3,4,3,4,-14};
	
	if (tonality==1)
		{
		patternLength=4;
		arpOffset=majArray[arpCounter];
		
		}
	
	else if (tonality == 2)
		{
		patternLength=4;
		arpOffset=minArray[arpCounter];
		
		}
	
	arpCounter++;
	if (arpCounter > patternLength)
		{arpCounter=0;}
	return arpOffset;
	}


stepPattern::stepPattern()
	{
	//constructor
	//the stepPattern is our main building block
	//this is a container for all the sequenced tracks - synth lines, chords and drums.
	
	currentStepIndex=0;
	
	patternSteps=16; //initial default length
	globalTempo=0; //TODO: implement global tempo locking
	patternTempo=120; //initial default tempo
	
	//clear out our sequence array.
	for (int i=0;i<MAX_SEQUENCES;i++)
		{
		sequences[i]=NULL;
		}
	
	}

stepPattern::~stepPattern()
	{
	//destructor
	}
void stepPattern::serialise(FILE* file)
	{
	fprintf(file,"pattern:%d|%d|%d|%d\n",currentStepIndex,patternSteps,patternTempo,drumAccentSequence);
	for (int i=0;i<MAX_SEQUENCES;i++)
		{
		if (sequences[i])
			{	
			sequences[i]->serialise(file);
			}
		}
	}
 
int stepPattern::getPatternTempo()
	{
	if (globalTempo)
		{return globalTempo;}
	else
		{return patternTempo;}
	}

void stepPattern::setPatternTempo(int t)
	{
	//fprintf(stderr,"stepPattern::setPatternTempo to %d\n",t);
	patternTempo=t;
	}

void stepPattern::setGlobalTempo(int t)
	{
	globalTempo=t;
	}



int stepPattern::nextStep()
	{
	currentStepIndex++;
	if (currentStepIndex >= patternSteps)
		{
		currentStepIndex=0;
		}
	//fprintf(stderr,"stepPattern::nextStep() current step index is %d\n",currentStepIndex);
	return currentStepIndex;
	}

int stepPattern::getCurrentStepIndex()
	{
	//fprintf(stderr,"stepPattern::getCurrentStepIndex() current step index is %d\n",currentStepIndex);
	return currentStepIndex;
	}

void stepPattern::setCurrentStepIndex(int step)
	{
	//fprintf(stderr,"stepPattern::setCurrentStepIndex() setting current index to %d from %d\n",step,currentStepIndex);
	currentStepIndex=step;
	}


int stepPattern::getPatternLength()
	{
	return patternSteps;
	}

void stepPattern::setPatternLength(int steps)
	{
	//fprintf(stderr,"DEBUG: stepPattern::setPatternLength setting pattern length to %d steps\n",steps);
	patternSteps=steps;
	//not sure if i need to do this, but probably useful for copying existing notes when
	//extending pattern length
	for (int i=0;i<MAX_SEQUENCES;i++)
		{
		stepSequence* s=sequences[i];
		if (s)
			{
			s->setSequenceLength(steps);
			}
		}
	}


int stepPattern::nextFreeId()
	{
	//returns 'human' sequence ID - from 1 to 16, 0 for error.
	for (int i=0;i < MAX_SEQUENCES;i++)
		{
		if (! sequences[i])
			{
			return i+1;
			}
		}
	return 0;
	}

int stepPattern::nextAssignedId()
	{
	for (int i=0;i < MAX_SEQUENCES;i++)
		{
		if ( sequences[i])
			{
			return i+1;
			}
		}
	return 0;
	
	}

stepSequence* stepPattern::getActiveSequence()
	{
	//fprintf(stderr,"DEBUG: stepPattern::getActiveSequence %d\n",activeSequenceId);
	return getSequence(activeSequenceId);
	}


void stepPattern::setActiveSequence(int sequenceId)
	{
	//fprintf(stderr,"DEBUG: stepPattern::setActiveSequence setting active sequence to %d\n",sequenceId);
	//TODO: check bounds/whether sequence array id is null
	activeSequenceId=sequenceId;
	}

int stepPattern::addSequence(const char* type, const char* name, int drumNote)
	{

	//add a sequence object to our container, returning an integer index we can use to address
	//the pattern. also assign a name, so we can tag the sequence in the gui.

	int seq_array_index;
	int nextId;
	//fprintf(stderr,"DEBUG: stepPattern::addSequence  adding Sequence %s %s %d\n",type,name,drumNote);
	nextId=nextFreeId();
	if (nextId)
		{
		seq_array_index=nextId-1;
		stepSequence* s=new stepSequence();
		s->setSequenceName(name);
		s->setSequenceType(type);
		s->setMidiChannel(1);
		if (drumNote > 0)
			{
			s->setMidiChannel(10);
			s->drumSequence=1;
			s->drumNote=drumNote;
			}
		
		sequences[seq_array_index]=s;
		//fprintf(stderr,"DEBUG: stepPattern::addSequence  assigned to id %d\n",nextId);
		}
	else
		{
		fprintf(stderr,"ERROR: stepPattern::addSequence No free Sequence ids\n");
		}
	
	return nextId;
	}

void stepPattern::removeSequence(int sequenceId)
	{
	//remove sequence with id seq_id
	int seq_array_index=sequenceId-1;
	//fprintf(stderr,"DEBUG: stepPattern::removeSequence  removing Sequence %d\n",sequenceId);
	stepSequence* s=sequences[seq_array_index];
	delete s;
	sequences[seq_array_index]=NULL;
	
	if (sequenceId==activeSequenceId)
		{
		//TODO: may want to handle this closer to the GUI so we can update.
		activeSequenceId=nextAssignedId();
		//fprintf(stderr,"DEBUG: stepPattern::removeSequence  active sequence removed. setting active sequence to  %d\n",activeSequenceId);
		}
	}


stepSequence* stepPattern::getSequence(int sequenceId)
	{
	unsigned int seq_array_index=sequenceId-1;
	//fprintf(stderr,"DEBUG: stepPattern::getSequence  getting Sequence %d\n",sequenceId);
	if (sequences[seq_array_index] != NULL && sequenceId <= MAX_SEQUENCES)
		{return sequences[seq_array_index];}
	else
		{
		//fprintf(stderr,"ERROR: stepPattern::getSequence  INVALID REQUEST FOR sequenceId %d\n",sequenceId);
		return NULL;
		}
	}

void stepPattern::setDrumAccentSequence(int i)
	{
	drumAccentSequence=i;
	}

stepSequence* stepPattern::getDrumAccentSequence()
	{
	return getSequence(drumAccentSequence);
	}













stepPatternChain::stepPatternChain()
	{
	for (int i=0;i < 16;i++)
		{
		patternArray[i]=0;
		partsMuted[i]=0;
		}
	currentPattern=1;
	}

void stepPatternChain::resetPatternMutes()
	{
	for (int i=0;i<16;i++)
		{
		setPartMuted(i,0);
		}
	}

void stepPatternChain::setPartMuted(int i, int j)
	{
	fprintf(stderr,"Setting part[%d] to %d\n",i,j); 
	partsMuted[i]=j;
	}

int stepPatternChain::getCurrentPattern()
	{
	fprintf(stderr,"in getCurrentPattern() - returning index %d(%d)\n",currentPattern-1,patternArray[currentPattern-1]);
	return patternArray[currentPattern-1];
	}

int stepPatternChain::getCurrentPatternIndex()
	{
	fprintf(stderr,"in getCurrentPatternIndex() - returning index %d\n",currentPattern-1);
	return currentPattern-1;
	}

int stepPatternChain::getPatternIndex(int i)
	{
	return patternArray[i];
	}

int stepPatternChain::getNextPattern()
	{
	//fprintf(stderr,"in getNextPattern()\n");
	currentPattern++;
	if (currentPattern > 16)
		{
		currentPattern=1;
		}
	if (patternArray[currentPattern-1]==0)
		{
		currentPattern=1;
		fprintf(stderr,"DEBUG: getNextPattern() Looping returning 1st pattern (%d)\n",patternArray[0]);
		return patternArray[0];
		}
	else	
		{
		fprintf(stderr,"DEBUG: getNextPattern() returning current pattern  - %d\n",currentPattern-1);
		return patternArray[currentPattern-1];
		}
	}

void stepPatternChain::setPattern(int i, int j)
	{
	patternArray[i]=j;
	}

void stepPatternChain::serialise(FILE* file)
	{
	fprintf(file,"patternchain:");
	for (int i=0;i < 16;i++)
		{
		fprintf(file,"%d|",patternArray[i]);
		}
	fprintf(file,"\n");

	fprintf(file,"mutes:");
	for (int i=0;i<MAX_SEQUENCES;i++)
		{
		fprintf(file,"%d|",partsMuted[i]);
		}
	fprintf(file,"\n");
	}



stepPatternChain::~stepPatternChain()
	{

	}
