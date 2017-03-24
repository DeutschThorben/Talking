#-------------------------------------------------
#
# Project created by QtCreator 2017-03-21T11:56:37
#
#-------------------------------------------------

QT       += core gui
QT       += network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app


SOURCES += main.cpp\
        server.cpp \
    control/socketmessage.cpp \
    control/socketclient.cpp \
    model/userlist.cpp \
    model/userinformation.cpp \
    model/controlsqlite.cpp

HEADERS  += server.h \
    control/socketmessage.h \
    control/socketclient.h \
    control/package.h \
    model/userlist.h \
    model/userinformation.h \
    model/controlsqlite.h

FORMS    += server.ui
