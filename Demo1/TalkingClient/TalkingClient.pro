#-------------------------------------------------
#
# Project created by QtCreator 2017-04-24T11:26:18
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TalkingClient
TEMPLATE = app


SOURCES += main.cpp\
        talkingclient.cpp \
    screen/friendlist.cpp \
    screen/addfriend.cpp \
    screen/registuser.cpp \
    screen/talking.cpp \
    model/clientcommon.cpp

HEADERS  += talkingclient.h \
    screen/friendlist.h \
    screen/addfriend.h \
    screen/registuser.h \
    screen/talking.h \
    model/clientcommon.h \
    model/package.h

FORMS    += talkingclient.ui \
    screen/friendlist.ui \
    screen/addfriend.ui \
    screen/registuser.ui \
    screen/talking.ui

RESOURCES += \
    picture.qrc
