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

#ifndef _SEQUENCERCORE_H_
#define _SEQUENCERCORE_H_

#include <qthread.h>

#include "stepSequence.h"

class sequencerCore : public QThread
	{
	
	public:
        	virtual void run();
		void cleanup();
		void initSequencer();
		void setPattern(int i);
		stepPattern* getCurrentPattern();
		int getCurrentPatternIndex();
		
		//pass a stepsequenceWidget* for step update callback
		void setStepHandler(void*);

		void playSequence();
		void stopSequence();

		
		void loadBank(char*);
		void saveBank(char*);

		sequencerCore();
		~sequencerCore();
	private:
		stepPattern* createBlankPattern();
		QMutex patternMutex;
		int playing;
		int alive;
		int sequenceId;
		void* stepHandler;
		stepPattern* myPattern;
		int myPatternNumber;
		stepPattern* patterns[16];

	};

#endif



