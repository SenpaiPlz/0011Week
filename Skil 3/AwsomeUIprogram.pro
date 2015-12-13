#-------------------------------------------------
#
# Project created by QtCreator 2015-12-11T09:52:25
#
#-------------------------------------------------

QT       += core gui\
            sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AwsomeUIprogram
TEMPLATE = app
CONFIG += c++11


SOURCES += main.cpp\
        UI/mainwindow.cpp \
    The_Children/computer.cpp \
    The_Children/computerscientist.cpp \
    domain/helper.cpp \
    Data/computerdata.cpp \
    Data/scientistdata.cpp \
    Data/sqlconnect.cpp \
    domain/domain.cpp \
    UI/deleteoptions.cpp \
    UI/add_scientist.cpp

HEADERS  += UI/mainwindow.h \
    The_Children/computer.h \
    The_Children/computerscientist.h \
    domain/helper.h \
    Data/computerdata.h \
    Data/scientistdata.h \
    Data/sqlconnect.h \
    domain/domain.h \
    UI/deleteoptions.h \
    UI/add_scientist.h

FORMS    += UI/mainwindow.ui \
    UI/deleteoptions.ui \
    UI/add_scientist.ui
