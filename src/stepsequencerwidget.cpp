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


#include <qlabel.h>
#include <qstring.h>
#include <qtoolbutton.h>
#include <q3buttongroup.h>
#include <qpalette.h>
#include <qtimer.h>
#include <qspinbox.h>
#include <qcheckbox.h>
#include "stepsequencerwidget.h"

const char* noteNames[]={"C-","C#-","D-","D#-","E-","F-","F#-","G-","G#-","A-","A#-","B-","C0","C#0","D0","D#0","E0","F0","F#0","G0","G#0","A0","A#0","B0","C1","C#1","D1","D#1","E1","F1","F#1","G1","G#1","A1","A#1","B1","C2","C#2","D2","D#2","E2","F2","F#2","G2","G#2","A2","A#2","B2","C3","C#3","D3","D#3","E3","F3","F#3","G3","G#3","A3","A#3","B3","C4","C#4","D4","D#4","E4","F4","F#4","G4","G#4","A4","A#4","B4","C5","C#5","D5","D#5","E5","F5","F#5","G5","G#5","A5","A#5","B5","C6","C#6","D6","D#6","E6","F6","F#6","G6","G#6","A6","A#6","B6","C7","C#7","D7","D#7","E7","F7","F#7","G7","G#7","A7","A#7","B7","C8","C#8","D8","D#8","E8","F8","F#8","G8","G#8","A8","A#8","B8","C9","C#9","D9","D#9","E9","F9","F#9","G9","G#9","A9","A#9","B9","ERR"};


stepsequencerWidget::stepsequencerWidget(QWidget* parent, const char* name, Qt::WFlags fl)
        : stepsequencerWidgetBase(parent,name,fl)
{
//constructor



//fprintf(stderr,"Constructing stepsequencerWidget\n");
mySequencer=(qTribe*) parent;
mySequencerThread=mySequencer->getSequencerThread();
//fprintf(stderr,"Constructing stepsequencerWidget parent %s thread pointer: %d\n",parent->className(),mySequencerThread);

bankFile=QString();

playing=0;

selectedStep=0;
selectedChainStep=0;
selectedMeasure=0;

patternStepSong=0;
delayedPatternChange=0;

//initially set our mode to pattern length
patternMode=2;
stepMode=0;


buttonOffColor=QColor(240,240,240);
buttonOnColor=QColor(200,255,128);
buttonPlayColor=QColor(255,128,128);
selectedChainColor=QColor(255,192,128);

pal = synthPart1->palette();


stepModeGroup_clicked(stepMode);
patternModeGroup_clicked(patternMode);


setStepButtonColors();
setSynthPartButtonColors();
setDrumPartButtonColors();
 

muteMode=0;




//create a timer to periodically refresh our gui while our sequencer
//plays in our sequncerThread

QTimer *uiTimer = new QTimer( this );
connect( uiTimer, SIGNAL(timeout()), SLOT(updateGui()) );
uiTimer->start( 75, FALSE );


}

stepsequencerWidget::~stepsequencerWidget()
{
//destructor
}

void stepsequencerWidget::setBankFile(char* c)
	{
	bankFile=c;
	}

void stepsequencerWidget::bpm_valueChanged(int bpm)
{
stepPattern* myPattern=mySequencerThread->getCurrentPattern();
myPattern->setPatternTempo(bpm);
}

void stepsequencerWidget::play_toggled(bool b)
	{
	if (b)
		{
		//fprintf(stderr,"Playing Sequence in thread %d\n",mySequencerThread);
		mySequencerThread->playSequence();
		stepPatternChain* myPatternChain=mySequencerThread->getPatternChain();
		playing=1;
		if (patternStepSong==2)
			{
			chainClearStepButtonColors();
			mySequencerThread->setPattern(myPatternChain->getCurrentPattern());
			dataDisplay->setText(QString("P%1").arg(myPatternChain->getCurrentPattern()));
			delayedPatternChange=myPatternChain->getCurrentPattern();
			}
		else
			{
			setStepButtonColors();
			}
		}
	else
		{
		//fprintf(stderr,"Stopping Sequencein thread %d\n",mySequencerThread);
		mySequencerThread->stopSequence();
		playing=0;
		if (patternStepSong==2)
			{
			chainClearStepButtonColors();
			}
		else
			{
			setStepButtonColors();
			}
		}

	}

void stepsequencerWidget::sequence_clicked(int step_array_index)
	{
	//depending on what mode we are in we want different behaviour here.
	//for now lets just implement the step editing facility.
	if (patternStepSong==2)
		{
		stepPatternChain* myPatternChain=mySequencerThread->getPatternChain();
		//handle chain-mode functions
		selectedChainStep=step_array_index;
		chainClearStepButtonColors();
		dataDisplay->setText(QString("P%1").arg(myPatternChain->getPatternIndex(step_array_index)));

		}
	else
		{
		patternStepSong=1;
		step* myStep;
		stepPattern* myPattern=mySequencerThread->getCurrentPattern();
		stepSequence* mySequence=myPattern->getActiveSequence();
		myStep=mySequence->getStep(step_array_index+(selectedMeasure*16));	

		dataDisplay->setText(QString("%1").arg("qTribe"));
		//fprintf(stderr,"STEP INFO: stepMode: %d On: %d Note Number %d Length %d Vel %d\n",stepMode,myStep->isOn,myStep->noteNumber,myStep->noteLength,myStep->noteVelocity);
		selectedStep=step_array_index+1;
		if (stepMode==0) //note on/off
			{
			QButton* myButton=sequenceGroup->find(step_array_index);
			if (! myStep->isOn)
				{
				myStep->isOn=1;	
				pal.setColor( QPalette::Active, QColorGroup::Button, buttonOnColor);
				myButton ->setPalette( pal );
				}
			else
				{
				fprintf(stderr,"Turning step off\n");
				myStep->isOn=0;
				pal.setColor( QPalette::Active, QColorGroup::Button, buttonOffColor);
				myButton ->setPalette( pal );
				}
			}
		

		if (stepMode==1) //note number
			{
		
			//ensure this button is on, even if we clicked on it when it was on.
			sequenceGroup->setButton(step_array_index);
			dataDisplay->setText(QString("%1").arg(noteNames[myStep->noteNumber]));
			//fprintf(stderr,"STEP DISPLAY INFO: %d",myStep->noteNumber);
			}
	
	
		if (stepMode==2) //length
			{
		
			//ensure this button is on, even if we clicked on it when it was on.
			sequenceGroup->setButton(step_array_index);
			dataDisplay->setText(QString("%1").arg(myStep->noteLength));
			}
	
		if (stepMode==3) //note velocity
			{
		
			//ensure this button is on, even if we clicked on it when it was on.
			sequenceGroup->setButton(step_array_index);
			dataDisplay->setText(QString("%1").arg(myStep->noteVelocity));
			}
		}
	}


void stepsequencerWidget::dataDial_valueChanged(int dataVal)
	{
	//here we need to update our backed data to reflect our new selection.

	if (patternStepSong==0)
		{	
		
		if (patternMode==0)
			{
			int modDataVal=(dataVal+9)/9;
			dataDisplay->setText(QString("P%1").arg(modDataVal));
			if (playing)
				{
				//queue switching of pattern at next step 0.
				delayedPatternChange=modDataVal;
				dataDisplay->setText(QString(">P%1").arg(modDataVal));
				}
			else
				{
				mySequencerThread->setPattern(modDataVal);
				stepModeGroup_clicked(stepMode);
				patternModeGroup_clicked(patternMode);
				setSynthPartButtonColors();
				setDrumPartButtonColors();
				setStepButtonColors();
				}
			}

		if (patternMode==1)
			{
			
			int modDataVal=(dataVal+9)/9;
			//fprintf(stderr,"Setting MIDI Channel %d orig %d\n",modDataVal,dataVal);
			stepPattern* myPattern=mySequencerThread->getCurrentPattern();
			stepSequence* mySequence=myPattern->getActiveSequence();
			if (mySequence->getMidiChannel() != modDataVal)
				{
				mySequence->setMidiChannel(modDataVal);
				}
			dataDisplay->setText(QString("%1").arg(modDataVal));
			}

		if (patternMode==2)
			{
			int modDataVal=(dataVal+18)/17;
			stepPattern* myPattern=mySequencerThread->getCurrentPattern();
			if (myPattern->getPatternLength() != modDataVal)
				{
				myPattern->setPatternLength(modDataVal*16);
				}
			dataDisplay->setText(QString("%1").arg(modDataVal));

			}
		
		
		
		}
		
	//do we have a note selected in note mode? 
	if (patternStepSong==1)
		{
		stepPattern* myPattern=mySequencerThread->getCurrentPattern();
		stepSequence* mySequence=myPattern->getActiveSequence();
		
		if (mySequence->drumSequence==1 && stepMode==1)
			{
			mySequence->drumNote=dataVal;
			dataDisplay->setText(QString("%1").arg(noteNames[dataVal]));
			//fprintf(stderr,"We're supposedly a drum sequence\n"	);
			}
		else	
			{
			if (selectedStep && stepMode==1)
				{
				int step_array_index=selectedStep-1;
				step* myStep;
				myStep=mySequence->getStep(step_array_index+(selectedMeasure*16));	
				myStep->noteNumber=dataVal;
				dataDisplay->setText(QString("%1").arg(noteNames[dataVal]));
				//fprintf(stderr,"STEP INFO: On: %d Note Number %d Length %d Vel %d\n",myStep->isOn,myStep->noteNumber,myStep->noteLength,myStep->noteVelocity);
				}
			
			if (selectedStep && stepMode==3)
				{
				int step_array_index=selectedStep-1;
				step* myStep;
				myStep=mySequence->getStep(step_array_index+(selectedMeasure*16));	
				myStep->noteVelocity=dataVal;
				dataDisplay->setText(QString("%1").arg(dataVal));
	
				}
			if (selectedStep && stepMode==4)
				{
				int step_array_index=selectedStep-1;
				step* myStep;
				myStep=mySequence->getStep(step_array_index+(selectedMeasure*16));	
				myStep->noteTonality=dataVal;
				dataDisplay->setText(QString("%1").arg(dataVal));
	
				}

			}
		if (selectedStep && stepMode==2)
			{
			int modDataVal=dataVal; //max 128 steps note length
			int step_array_index=selectedStep-1;
			step* myStep;
			myStep=mySequence->getStep(step_array_index+(selectedMeasure*16));	
			myStep->noteLength=modDataVal;
			dataDisplay->setText(QString("%1").arg(modDataVal));
			}	
		
		

		}

	if (patternStepSong==2)
		{
		//chain mode
		//if we have a selected step, assign the selected pattern to it.
		
		stepPatternChain* myPatternChain=mySequencerThread->getPatternChain();
		int modDataVal=(dataVal+8)/9;
		dataDisplay->setText(QString("P%1").arg(modDataVal));
		myPatternChain->setPattern(selectedChainStep, modDataVal) ;
		}

}

void stepsequencerWidget::stepModeGroup_clicked(int mode)
	{
	//we are in step mode (arg is 0 - on./off, 1 - note - 2- length 3 -velocity)
	stepMode=mode;
	patternStepSong=1;
	if (stepMode==0)
		{
		sequenceGroup->setExclusive(FALSE);
		dataDisplay->setText("qTribe");
		//now we need to go through our steps and set them on or off depending on our underlying step model.
		QToolButton* myButton;
		step* myStep;
		stepPattern* myPattern=mySequencerThread->getCurrentPattern();
		stepSequence* mySequence=myPattern->getActiveSequence();
		for (int i=0;i< 16;i++)
			{
			myButton=(QToolButton*) sequenceGroup->find(i);
			//fprintf(stderr,"BUTTON: %s\n",myButton->className());
			myStep=mySequence->getStep(i+(selectedMeasure*16));
			if (myStep->isOn)
				{
				myButton->setOn(TRUE);
				pal.setColor( QPalette::Active, QColorGroup::Button, buttonOnColor);
				myButton ->setPalette( pal ); 
				}
			else
				{
				myButton->setOn(FALSE);
				pal.setColor( QPalette::Active, QColorGroup::Button, buttonOffColor);
				myButton ->setPalette( pal );
				}
			}
		}

	else if (stepMode==1 || stepMode==2 || stepMode==3 || stepMode==4)
		{
		sequenceGroup->setExclusive(TRUE);
		dataDisplay->setText("---");
		step* myStep;
		stepPattern* myPattern=mySequencerThread->getCurrentPattern();
		stepSequence* mySequence=myPattern->getActiveSequence();
	
		for (int i=0;i< 16;i++)
			{
			QToolButton* myButton=(QToolButton*) sequenceGroup->find(i);
			myButton->setOn(FALSE);
			}

		if (selectedStep)
			{
		
			int step_array_index=selectedStep-1;
			sequenceGroup->setButton(step_array_index);
			myStep=mySequence->getStep(step_array_index+(selectedMeasure*16));
			
			if (stepMode==1)
				{
				dataDisplay->setText(QString("%1").arg(noteNames[myStep->noteNumber]));		
				}
			if (stepMode==2)
				{
				dataDisplay->setText(QString("%1").arg(myStep->noteLength));		
				}
			if (stepMode==3)
				{
				dataDisplay->setText(QString("%1").arg(myStep->noteVelocity));		
				}
			if (stepMode==4)
				{
				dataDisplay->setText(QString("%1").arg(myStep->noteTonality));		
				}

			}
		if (mySequence->drumSequence==1)
			{
			//drum part
			if (stepMode==1)
				{
				dataDisplay->setText(QString("%1").arg(noteNames[mySequence->drumNote]));		
				}

			}

		}
	else
		{
		sequenceGroup->setExclusive(TRUE);
		}


	}

void stepsequencerWidget::synthParts_clicked(int sequencer_part_index)
	{
	int sequencerPart=sequencer_part_index+1;
	//we need to switch our active sequence and update our display depending on the mode
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	stepSequence* mySequence=myPattern->getSequence(sequencerPart);
	QToolButton* myButton=(QToolButton*) synthParts->find(sequencer_part_index);
	
	if (muteMode)
		{
		if (! mySequence->getMuted())
			{mySequence->setMuted(1);}
		else
			{mySequence->setMuted(0);}
		
		
		}
	myPattern->setActiveSequence(sequencerPart);
	myButton->setOn(TRUE);
	
	
	fprintf(stderr,"wtf? %d\n",mySequence->isArp());
	if (mySequence->isArp()==TRUE)
		{
		arpOn->setChecked(TRUE);
		}
	else
		{
		arpOn->setChecked(FALSE);
		}

	if (patternStepSong==0)
		{patternModeGroup_clicked(patternMode);}
	else if (patternStepSong==1)
		{stepModeGroup_clicked(stepMode);}
	else if (patternStepSong==2)
		{mySequencerThread->setActiveSequence(sequencer_part_index);}
	setSynthPartButtonColors();
	setDrumPartButtonColors();
	setStepButtonColors();
	}


void stepsequencerWidget::chainClearStepButtonColors()
	{
	stepPatternChain* myPatternChain=mySequencerThread->getPatternChain();
	for (int i=0;i< 16;i++)
		{
		QToolButton* myButton=(QToolButton*) sequenceGroup->find(i);
		myButton->setOn(FALSE);
		
		if (myPatternChain->getPatternIndex(i) != 0)
			{
			pal.setColor( QPalette::Active, QColorGroup::Button, buttonOnColor);
			myButton ->setPalette( pal );
			}
		else
			{
			pal.setColor( QPalette::Active, QColorGroup::Button, buttonOffColor);
			myButton ->setPalette( pal );
			}
		}	
	
	//light up the currently playing chain index
	int myButtonIndex=myPatternChain->getCurrentPatternIndex();
				
	QToolButton* chainButton=(QToolButton*) sequenceGroup->find(myButtonIndex);
	pal.setColor( QPalette::Active, QColorGroup::Button, buttonPlayColor);
	chainButton ->setPalette( pal );

	//we're in chain mode so we need to light up the currentsly selected chain step			
	QToolButton* myButton=(QToolButton*) sequenceGroup->find(selectedChainStep);
	pal.setColor( QPalette::Active, QColorGroup::Button,selectedChainColor);
	myButton ->setPalette( pal );
		

	}

void stepsequencerWidget::setStepButtonColors()
	{
	step* myStep;
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	stepSequence* mySequence=myPattern->getActiveSequence();

	for (int i=0;i< 16;i++)
		{
		QToolButton* myButton=(QToolButton*) sequenceGroup->find(i);
		myStep=mySequence->getStep(i+(selectedMeasure*16));
		if (myButton->isOn())
			{myButton->setOn(FALSE);}
		
		if ((selectedStep-1)==i)
			{
			myButton->setOn(TRUE);
			}
		if (myStep->isOn)
			{
 			pal.setColor( QPalette::Active, QColorGroup::Button, buttonOnColor);
			myButton ->setPalette( pal ); 
			}
		else
			{
			pal.setColor( QPalette::Active, QColorGroup::Button, buttonOffColor);
			myButton ->setPalette( pal );
			}
		}	
	}

void stepsequencerWidget::setSynthPartButtonColors()
	{
	stepSequence* mySequence;
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	stepSequence* activeSequence=myPattern->getActiveSequence();
	for (int i=0;i< 4;i++)
		{
		QToolButton* myButton=(QToolButton*) synthParts->find(i);
		mySequence=myPattern->getSequence(i+1);

		myButton->setOn(FALSE);

		if (! mySequence->getMuted())
			{
 			pal.setColor( QPalette::Active, QColorGroup::Button, buttonOnColor);
			myButton ->setPalette( pal ); 
			}
		else
			{
			pal.setColor( QPalette::Active, QColorGroup::Button, buttonOffColor);
			myButton ->setPalette( pal );
			}
		
		if (mySequence==activeSequence)
			{
			myButton->setOn( TRUE );
			}	
		
		}

	}


void stepsequencerWidget::setDrumPartButtonColors()
	{
	stepSequence* mySequence;
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	stepSequence* activeSequence=myPattern->getActiveSequence();
	for (int i=0;i< 9;i++)
		{
		QToolButton* myButton=(QToolButton*) drumParts->find(i);
		//offset for 0-base and synthParts
		mySequence=myPattern->getSequence(i+5);

		myButton->setOn(FALSE);

		if (! mySequence->getMuted())
			{
 			pal.setColor( QPalette::Active, QColorGroup::Button, buttonOnColor);
			myButton ->setPalette( pal ); 
			}
		else
			{
			pal.setColor( QPalette::Active, QColorGroup::Button, buttonOffColor);
			myButton ->setPalette( pal );
			}
		
		if (mySequence==activeSequence)
			{
			myButton->setOn( TRUE );
			}	
		
		}

	}


void stepsequencerWidget::muteParts_toggled(bool b)
	{
	if (b)
		{muteMode=1;}
	else
		{muteMode=0;}
}

void stepsequencerWidget::updatePlaybackPosition()
	{
	stepPatternChain* myPatternChain=mySequencerThread->getPatternChain();
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	stepSequence* activeSequence=myPattern->getActiveSequence();
	int s=myPattern->getCurrentStepIndex();
	//fprintf(stderr,"DEBUG: patternStepsong %d\n",patternStepSong);
	if (patternStepSong==2)
		{
		//chain mode functions 
		if ( s==15)
			{
			//this is here to ensure we dont update multiple times per step - enable delayedPatternchange
			//on the last step in song/chain mode so we can be sure our chain incrementing call below
			//will not get called more than once.
			delayedPatternChange=1;
			}	

		if (s==0 && delayedPatternChange)	
			{
			//we're in song mode, so we need to switch to the next pattern in the chain,
			//and update the step key to show the current pattern
			
			delayedPatternChange=0;
			myPatternChain->getNextPattern();
			setSynthPartButtonColors();
			setDrumPartButtonColors();
			chainClearStepButtonColors();
			mySequencerThread->setPattern(myPatternChain->getCurrentPattern());
			dataDisplay->setText(QString("P%1").arg(myPatternChain->getCurrentPattern()));
			//we're in chain mode so we need to light up the step currently playing
			//int myButtonIndex=myPatternChain->getCurrentPatternIndex();
				
			//QToolButton* myButton=(QToolButton*) sequenceGroup->find(myButtonIndex);
			//pal.setColor( QPalette::Active, QColorGroup::Button, buttonPlayColor);
			//myButton ->setPalette( pal );
				
					
			
			}
		
		}
	else
		{

		if (delayedPatternChange && s==0)
			{
			mySequencerThread->setPattern(delayedPatternChange);
			dataDisplay->setText(QString("P%1").arg(mySequencerThread->getCurrentPatternIndex()));
			delayedPatternChange=0;
			fprintf(stderr,"DEBUG: about to call patternModeGroup_clicked %d\n",patternMode);
			patternModeGroup_clicked(patternMode);
			setSynthPartButtonColors();
			setDrumPartButtonColors();
			setStepButtonColors();
			}
	
		
		//fprintf(stderr,"stepPos: %d\n",s % 16);
		
		//setStepButtonColors();
		if (playing)
			{
			
				int myButtonIndex=s % 16;
				int myPrevButtonIndex=myButtonIndex-1;
				if (myPrevButtonIndex < 0)
					{myPrevButtonIndex=15;}
				QToolButton* myButton=(QToolButton*) sequenceGroup->find(myButtonIndex);
				pal.setColor( QPalette::Active, QColorGroup::Button, buttonPlayColor);
				myButton ->setPalette( pal ); 
				myButton=(QToolButton*) sequenceGroup->find(myPrevButtonIndex);
				step* myStep=activeSequence->getStep(myPrevButtonIndex+(selectedMeasure*16));
				if (myStep->isOn)
					{
 					pal.setColor( QPalette::Active, QColorGroup::Button, buttonOnColor);
					myButton ->setPalette( pal ); 
					}
				else
					{
					pal.setColor( QPalette::Active, QColorGroup::Button, buttonOffColor);
					myButton ->setPalette( pal );
					}		
				}
				
		}
	//doesnt matter what mode we are in, we should always uplate the playback indicator
	if (playing)
		{
		if (s > -1 and s < 16)
			{playPositionGroup->setButton(0);}
		else if (s > 15 and s < 32)
			{playPositionGroup->setButton(1);}
		else if (s > 31 and s < 48)
			{playPositionGroup->setButton(2);}
		else if (s > 47 and s < 64)
			{playPositionGroup->setButton(3);}
		else if (s > 63 and s < 80)
			{playPositionGroup->setButton(4);}
		else if (s > 79 and s < 96)
			{playPositionGroup->setButton(5);}
		else if (s > 95 and s < 112)
			{playPositionGroup->setButton(6);}
		else
			{playPositionGroup->setButton(7);}
		}
	}	

void stepsequencerWidget::updateGui()
	{
	//fprintf(stderr,"UPDATE GUI FROM TIMER\n");
	if (playing)
		{
		statusline->setText(QString("Status: %1").arg(patternStepSong));
		updatePlaybackPosition();
		}
	
	}

void stepsequencerWidget::editPositionGroup_clicked(int s)
	{
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	//fprintf(stderr,"DEBUG:%d %d\n",myPattern->getPatternLength(),selectedMeasure*16);
	if (myPattern->getPatternLength() > s*16)
		{
		//fprintf(stderr,"DEBUG:%d %d\n",selectedMeasure,s);
		selectedMeasure=s;
		stepModeGroup_clicked(stepMode);
		setStepButtonColors();
		}
	else
		{
		editPositionGroup->setButton(selectedMeasure);
		}
	}

void stepsequencerWidget::patternModeGroup_clicked(int i)
	{
	fprintf(stderr,"DEBUG:patternModeGroup_clicked\n");
	patternStepSong=0;
	patternMode=i;
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	stepSequence* activeSequence=myPattern->getActiveSequence();
	
	if (patternMode==0)
		{
		dataDisplay->setText(QString("P%1").arg(mySequencerThread->getCurrentPatternIndex()));
		}
	

	if (patternMode==1)
		{
		dataDisplay->setText(QString("%1").arg(activeSequence->getMidiChannel()));
		}
	
	if (patternMode==2)
		{
		dataDisplay->setText(QString("%1").arg((myPattern->getPatternLength()+9)/16));
		}
	
	setStepButtonColors();
	}

void stepsequencerWidget::drumParts_clicked(int drum_part_index)
	{
	//skip  over our synth parts and add once to convert from 0-based index
	int sequencer_part_index=drum_part_index+5;


	//we need to switch our active sequence and update our display depending on the mode
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	stepSequence* mySequence=myPattern->getSequence(sequencer_part_index);
	QToolButton* myButton=(QToolButton*) drumParts->find(drum_part_index);
	
	if (muteMode)
		{
		if (! mySequence->getMuted())
			{mySequence->setMuted(1);}
		else
			{mySequence->setMuted(0);}
		
		
		}
	//else
	//	{
		myPattern->setActiveSequence(sequencer_part_index);
		myButton->setOn(TRUE);
	//	}
	if (patternStepSong==0)
		{patternModeGroup_clicked(patternMode);}
	else if (patternStepSong==1)
		{stepModeGroup_clicked(stepMode);}
	else if (patternStepSong==2)
		{mySequencerThread->setActiveSequence(sequencer_part_index);}
	setSynthPartButtonColors();
	setDrumPartButtonColors();
	setStepButtonColors();

	}

void stepsequencerWidget::writeButton_clicked()
	{
	mySequencerThread->saveBank((char*)bankFile.ascii());
	}

void stepsequencerWidget::loadButton_clicked()
	{
	//Currently no GUI widget for this.
	mySequencerThread->stopSequence();
	playing=0;
	mySequencerThread->loadBank((char*)bankFile.ascii());
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	
	//set up our UI state to something resembling the default.
	play->setOn(FALSE);
	bpm->setValue((int)myPattern->getPatternTempo());
	patternStepSong=1;
	stepMode=0;
	
	stepModeGroup_clicked(stepMode);
	setSynthPartButtonColors();
	setDrumPartButtonColors();
	setStepButtonColors();
	}

void stepsequencerWidget::chainGroup_clicked(int i)
	{
	fprintf(stderr,"DEBUG:chainGroup_clicked %d\n",i);
	stepPatternChain* myPatternChain=mySequencerThread->getPatternChain();
	patternStepSong=2;
	mySequencerThread->setPattern(myPatternChain->getCurrentPattern());
	dataDisplay->setText(QString("P%1").arg(mySequencerThread->getCurrentPatternIndex()));
	delayedPatternChange=0;
	setSynthPartButtonColors();
	setDrumPartButtonColors();
	chainClearStepButtonColors();
	}

void stepsequencerWidget::arpOn_stateChanged(bool b)
	{
	fprintf(stderr,"DEBUG:arpOn_stateChanged %d\n",b);
	stepPattern* myPattern=mySequencerThread->getCurrentPattern();
	stepSequence* mySequence=myPattern->getActiveSequence();
	// this is annoying - since Qt fires this signal no matter how the
	// widget is updated (user click or programmatic rest on part change,
	// we need to do extra checking to see if we really need to take
	// action here
	if (b)
		{
		if (mySequence->isArp() == 0){mySequence->arpeggiate();}
		}
	else
		{
		if (mySequence->isArp() > 0){mySequence->clearArp();}		
		}
	}













