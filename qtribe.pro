SUBDIRS += src
TEMPLATE = subdirs 
CONFIG += release \
          warn_on \
          qt \
          thread 
QT += qt3support