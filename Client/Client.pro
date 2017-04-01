#-------------------------------------------------
#
# Project created by QtCreator 2017-03-23T17:38:04
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app


SOURCES += main.cpp\
        client.cpp \
    screen/talking.cpp \
    screen/resign.cpp \
    model/clientcommon.cpp

HEADERS  += client.h \
    model/package.h \
    screen/talking.h \
    screen/resign.h \
    model/clientcommon.h

FORMS    += client.ui \
    screen/talking.ui \
    screen/resign.ui

DISTFILES +=

RESOURCES += \
    picture.qrc
