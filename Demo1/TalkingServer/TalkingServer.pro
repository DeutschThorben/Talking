#-------------------------------------------------
#
# Project created by QtCreator 2017-04-18T14:09:58
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TalkingServer
TEMPLATE = app


SOURCES += main.cpp\
        talkingserver.cpp \
    model/servercommon.cpp \
    control/clientcontrol.cpp \
    model/controltable.cpp \
    model/tablecommon.cpp \
    control/socketmessage.cpp \
    model/userinformation.cpp

HEADERS  += talkingserver.h \
    model/servercommon.h \
    control/clientcontrol.h \
    control/usertablecontrol.h \
    model/package.h \
    model/controltable.h \
    model/tablecommon.h \
    control/socketmessage.h \
    model/userinformation.h

FORMS    += talkingserver.ui

RESOURCES += \
    picture.qrc
