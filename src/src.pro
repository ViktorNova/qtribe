
#uncomment this if you are using an older version of JACK
#DEFINES +=OLD_JACK


SOURCES += qtribe.cpp \
           main.cpp \
 jackIO.cpp \
 sequencerCore.cpp \
 stepSequence.cpp \
 stepsequencerwidget.cpp
HEADERS += qtribe.h \
 jackIO.h \
 sequencerCore.h \
 stepSequence.h \
 stepsequencerwidget.h
TEMPLATE = app
CONFIG += release \
          warn_on \
	  thread \
          qt
TARGET = ../bin/qtribe
#The following line was changed from FORMS to FORMS3 by qt3to4
FORMS3 += stepsequencerwidgetbase.ui

LIBS += -ljack

#The following line was inserted by qt3to4
QT +=  qt3support 
#The following line was inserted by qt3to4
CONFIG += uic3

