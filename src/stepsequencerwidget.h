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


#ifndef _STEPSEQUENCERWIDGET_H_
#define _STEPSEQUENCERWIDGET_H_

#include "stepsequencerwidgetbase.h"
#include "qtribe.h"

class stepsequencerWidget : public stepsequencerWidgetBase
{
    Q_OBJECT
    
public:
    stepsequencerWidget(QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0 );
    ~stepsequencerWidget();
    /*$PUBLIC_FUNCTIONS$*/
     
     void setBankFile(char* c);
	
     //callback for step update notification
     //void stepChanged();

private:
	qTribe* mySequencer;
	sequencerCore* mySequencerThread;
	int selectedStep;
	int selectedChainStep;
	
	int patternStepSong;
	int stepMode;
	int patternMode;

	int playing;
	
	int delayedPatternChange;
	
	int muteMode;
	int selectedMeasure;
	QPalette pal;
	QColor buttonOffColor;
	QColor buttonOnColor;
	QColor buttonPlayColor;
	QColor selectedChainColor;
	QString bankFile;
	void setStepButtonColors();
	void chainClearStepButtonColors();
	void setSynthPartButtonColors();
	void setDrumPartButtonColors();
	void updatePlaybackPosition();





protected:
    /*$PROTECTED_FUNCTIONS$*/
public slots:
    virtual void muteParts_toggled(bool);
public slots:
    virtual void stepModeGroup_clicked(int);
public slots:
    virtual void synthParts_clicked(int);

protected slots:
    /*$PROTECTED_SLOTS$*/


public slots:
    virtual void dataDial_valueChanged(int);
public slots:
    virtual void sequence_clicked(int);
    virtual void drumParts_clicked(int);
public slots:
    virtual void play_toggled(bool);

public slots:
    virtual void patternModeGroup_clicked(int);
    virtual void editPositionGroup_clicked(int);
    virtual void bpm_valueChanged(int);
    virtual void updateGui();
    virtual void writeButton_clicked();
    virtual void loadButton_clicked();
    virtual void chainGroup_clicked(int);
    virtual void arpOn_stateChanged(bool);

};
#endif

