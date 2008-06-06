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
FORMS += stepsequencerwidgetbase.ui

LIBS += -ljack

