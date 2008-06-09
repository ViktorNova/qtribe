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

#include "sequencerCore.h"
#include "stepsequencerwidget.h"
#include "jackIO.h"

#include <stdio.h>
#include <iostream>
#include <fstream>

#include <qstring.h>
#include <qstringlist.h>

extern int backendInitialised;

//sequencer globals


	
sequencerCore::sequencerCore()
	{
	//constructor
	backendInitialised=0;
	backendInitialised=initJACK();
	
	

	if (backendInitialised)
		{fprintf(stderr,"Backend Init. successful.\n");}
    	else
		{fprintf(stderr,"Backend Failed to Init.\n");}
	playing=0;
	alive=1;
	sequenceId=0;
	myPatternNumber=1;
	}

sequencerCore::~sequencerCore()
	{
	//destructor
	}


void sequencerCore::cleanup()
	{	
	playing=0;
	alive=0;
	wait();	
	}


void sequencerCore::playSequence()
	{
	playing=1;
	}

void sequencerCore::stopSequence()
	{
	playing=0;
	myPattern->setCurrentStepIndex(0);
	}

void sequencerCore::setPattern(int i)
	{
	myPatternNumber=i;
	myPattern=patterns[i-1];
	}

int sequencerCore::getCurrentPatternIndex()
	{
	return myPatternNumber;
	}


stepPattern* sequencerCore::getCurrentPattern()
	{
	return myPattern;
	}

void sequencerCore::run()
	{
	double last_time=0;
	
	while(alive)
		{
		if(playing)
			{
			double thisStepTime=getJackTime();
			
			//was going to offset multiple notes played at same time by 1ms.. but not
			//sure if necessary.. JACK does odd things from time to time
			int seq_note_inc=0;
			
			double stepDelta= ((double(60)/(double)myPattern->getPatternTempo())/(double)4 )*1000; //ms
			if (thisStepTime >= (last_time+stepDelta))
				{
				
				for (int i=0;i<12;i++)
					{
					stepSequence* mySequence=myPattern->getSequence(i+1);
					if (! mySequence->getMuted())
						{
						int patternStep=myPattern->getCurrentStepIndex();
						//play our step
						step* myStep=mySequence->getStep(patternStep);
						if (myStep->isOn)
							{
							if (mySequence->drumSequence==1)
								{
								stepSequence* myAccents=myPattern->getDrumAccentSequence();
								step* accentStep=myAccents->getStep(patternStep);
								int modVelocity=myStep->noteVelocity;
								
								if (accentStep->isOn)
									{
									//implement simple accenting.
									modVelocity=modVelocity*2;
									if (modVelocity > 127)
										{modVelocity=127;}
									}
								
								queue_message(thisStepTime+seq_note_inc,mySequence->getMidiChannel()-1,144,mySequence->drumNote,modVelocity); //note on
								
								queue_message(thisStepTime+(myStep->noteLength*stepDelta),mySequence->getMidiChannel()-1,128,mySequence->drumNote,0); //note off
								
								seq_note_inc+=1;

								}
							else
								{
								queue_message(thisStepTime+seq_note_inc,mySequence->getMidiChannel()-1,144,myStep->noteNumber,myStep->noteVelocity); //note on
			
								queue_message(thisStepTime+(myStep->noteLength*stepDelta),mySequence->getMidiChannel()-1,128,myStep->noteNumber,0); //note off}
								
								seq_note_inc+=1;
								
								//fprintf(stderr,"Note length %d: on / off queued: %d %d\n",myStep->noteLength,thisStepTime,thisStepTime+(myStep->noteLength*stepDelta));
								}
							}
						}	
					}
					//move our pattern pointer along
					myPattern->nextStep();

					last_time=thisStepTime;
					
					
				}
			else
				{
				usleep(5000);
				}
		
			}
		else
			{
			usleep(10000);
			}
		}
	}

stepPattern* sequencerCore::createBlankPattern()
	{
	int ret;	
	//lets try calling some of our API
	stepPattern* newPattern=new stepPattern();	
	//add our sequences
	ret=newPattern->addSequence("synth","synthPart_1",-1);
	newPattern->setActiveSequence(ret);
	ret=newPattern->addSequence("synth","synthPart_2",-1);
	ret=newPattern->addSequence("synth","synthPart_3",-1);
	ret=newPattern->addSequence("synth","synthPart_4",-1);
	ret=newPattern->addSequence("drum","drumPart_1",32);
	ret=newPattern->addSequence("drum","drumPart_2",33);
	ret=newPattern->addSequence("drum","drumPart_3",34);
	ret=newPattern->addSequence("drum","drumPart_4",35);
	ret=newPattern->addSequence("drum","drumPart_5",36);
	ret=newPattern->addSequence("drum","drumPart_6",37);
	ret=newPattern->addSequence("drum","drumPart_7",38);
	ret=newPattern->addSequence("drum","drumPart_8",39);
	ret=newPattern->addSequence("accent","drumAccent_1",-1);
	newPattern->setDrumAccentSequence(ret);
	//set our pattern length to 16 steps
	newPattern->setPatternLength(16);

	return newPattern;

	}

void sequencerCore::initSequencer()
	{
	
	//if we can't open our default file, construct a minimal empty bank
	for (int i=0;i<16;i++)
		{
		patterns[i]=createBlankPattern();
		}
	myPattern=patterns[0];
	myPatternNumber=1;
	}


void sequencerCore::saveBank(char* fileName)
	{
	FILE* file;
	file = fopen (fileName,"w");
	for (int i=0;i<16;i++)
		{
		patterns[i]->serialise(file);
		}
	fclose(file);
	}


void sequencerCore::createBank()
	{
	for (int i=0;i<16;i++)
		{
		patterns[i]=createBlankPattern();
		}
	}


void sequencerCore::loadBank(char* fileName)
	{
	std::ifstream fin(fileName);
  	const int LINE_LENGTH = 100;
  	char str[LINE_LENGTH];
	
	//trash all our patterns in memory
	for (int i=0;i<16;i++)
		{
		delete patterns[i];	
		patterns[i]=NULL;
		}
	myPattern=NULL;
	stepPattern* currentPattern=NULL;
	stepSequence* currentSequence=NULL;	
	step* currentStep;
	int currentStepIndex=0;
	int patternLength=0;
	int currentPatternIndex=0;

  	while( fin.getline(str,LINE_LENGTH) ) 
		{
    		//use QStrings to make this easy
		QString line(str);
		QStringList parts = QStringList::split( ":", line );
		if (parts[0]=="pattern")
			{
			//fprintf(stderr,"FOUND PATTERN\n");
			currentPattern=new stepPattern();
			patterns[currentPatternIndex]=currentPattern;
			currentPatternIndex++;
			QStringList data = QStringList::split( "|", parts[1] );
			//currentStepIndex,patternSteps,patternTempo,drumAccentSequence
			patternLength=atoi(data[1]);
			currentPattern->setPatternTempo(atoi(data[2]));
			currentPattern->setDrumAccentSequence(atoi(data[3]));
			}
		if (parts[0]=="sequence")
			{
			//fprintf(stderr,"FOUND SEQUENCE\n");
			QStringList data = QStringList::split( "|", parts[1] );
			//sequenceName.ascii(),sequenceType.ascii(),muted,selectedStep,midiChannel,drumSequence,drumNote

			//type, name, drumnote
			int seqindex=currentPattern->addSequence(data[0],data[1],atoi(data[6]));
			currentSequence=currentPattern->getSequence(seqindex);
			currentSequence->setMuted(atoi(data[2]));
			
			currentSequence->setMidiChannel(atoi(data[4]));
			if (seqindex==1)
				{
				currentPattern->setActiveSequence(seqindex);
				}
			currentStepIndex=0;
			}
		if (parts[0]=="step")
			{
			
			QStringList data = QStringList::split( "|", parts[1] );
			currentStep=currentSequence->getStep(currentStepIndex);
			currentStep->isOn=atoi(data[0]);
			currentStep->noteNumber=atoi(data[1]);
			currentStep->noteLength=atoi(data[2]);
			currentStep->noteVelocity=atoi(data[3]);
			currentStepIndex++;
			//fprintf(stderr,"STEP: %d %d\n",currentStep->isOn,currentStep->noteNumber);
			}

  		}
	currentPattern->setPatternLength(patternLength);	
	myPattern=patterns[0];
	myPatternNumber=1;
	}


















