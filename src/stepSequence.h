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

#ifndef _STEPSEQUENCE_H_
#define _STEPSEQUENCE_H_

#include <qstring.h>
#include <fstream>

#define MAX_SEQUENCES 16
#define MAX_STEPS 128

class step
	{	
	public:
		int isOn;
		int noteNumber;
		int noteLength;
		int noteVelocity;
		int noteTonality;
		step();
		step(int,int,int,int,int);
		~step();
		void serialise(FILE*);
	};


class stepSequence
	{
	//TODO: do these need to be QStrings?
	QString sequenceName;
	QString sequenceType;
	
	int muted;	

	int sequenceLength;
	
	int selectedStep;
		
	step* stepArray[MAX_STEPS];
	step* arpArray[MAX_STEPS];
	
	int arpCounter;
	int arp;
	int arpLength;

	public:
		
		int midiChannel;
		int drumSequence;
		int drumNote;
		
		
		stepSequence();
		~stepSequence();
		
		const char* getSequenceName();
		//QString* getSequenceName();
		void setSequenceName(const char*);
		
		const char* getSequenceType();
		//QString* getSequenceType();
		void setSequenceType(const char*);
		
		void setSequenceLength(int);
		int getMidiChannel();
		void setMidiChannel(int);
		int getMuted();
		void setMuted(int);
			
		step* getStep(int);
		step* getArpStep(int);
		void serialise(FILE*);

		void arpeggiate();
		void clearArp();
		int getNextArpOffset(int);
		int isArp();
	};




class stepPattern
	{
	
	int activeSequenceId;
	int patternTempo;
	int globalTempo;
	stepSequence* sequences[MAX_SEQUENCES];	
	int patternSteps;

	QString patternName;
	
	int drumAccentSequence;
	
	
	
	public:
		stepPattern();
		~stepPattern();
			
	
		stepSequence* getActiveSequence();
		stepSequence* getSequence(int index);	
	
		void setActiveSequence(int);
		
		int addSequence(const char*,const char*,int);
		void removeSequence(int);
		
		int getPatternLength();
		void setPatternLength(int);
		
		
		int getPatternTempo();

		void setGlobalTempo(int);
		void setPatternTempo(int);
		
		//TODO: Should really be a sequence attribute
		void setDrumAccentSequence(int);
		stepSequence* getDrumAccentSequence();

		int getCurrentStepIndex();
		void setCurrentStepIndex(int);
			
		int nextStep();
		void serialise(FILE*);
		
	private:
		int nextFreeId();
		int nextAssignedId();
		
		int currentStepIndex;
	};



class stepPatternChain
	{
	
	int partsMuted[MAX_SEQUENCES];
	
	public:
		stepPatternChain();
		~stepPatternChain();		
		void setPattern(int,int);
		
		int getCurrentPattern();
		int getCurrentPatternIndex();
		int getNextPattern();
		int getPatternIndex(int);

		void resetPatternMutes();
		void setPartMuted(int, int);
		
		
		
		void serialise(FILE*);

	private:
		int patternArray[16];
		int currentPattern;
		bool loopMode;
	};

#endif
