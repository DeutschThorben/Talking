#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T17:38:04
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    screen/talking.cpp \
    screen/resign.cpp \
    model/clientcommon.cpp \
    screen/talkinglistscreen.cpp \
    screen/addnewfriend.cpp \
    screen/makemasses.cpp \
    model/friendlist.cpp

HEADERS  += client.h \
    model/package.h \
    screen/talking.h \
    screen/resign.h \
    model/clientcommon.h \
    screen/talkinglistscreen.h \
    screen/addnewfriend.h \
    screen/makemasses.h \
    model/friendlist.h

FORMS    += client.ui \
    screen/talking.ui \
    screen/resign.ui \
    screen/talkinglistscreen.ui \
    screen/addnewfriend.ui \
    screen/makemasses.ui

DISTFILES +=

RESOURCES += \
    picture.qrc
