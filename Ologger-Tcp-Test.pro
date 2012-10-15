#-------------------------------------------------
#
# Project created by QtCreator 2012-10-11T11:11:25
#
#-------------------------------------------------

QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Ologger-Tcp-Test
TEMPLATE = app


SOURCES += main.cpp\
        tcpserver.cpp

HEADERS  += tcpserver.h

FORMS    += tcpserver.ui
