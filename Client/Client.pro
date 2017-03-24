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
        client.cpp

HEADERS  += client.h \
    model/package.h

FORMS    += client.ui
