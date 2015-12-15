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
    UI/add_scientist.cpp \
    UI/add_computer.cpp \
    UI/deletecomputer.cpp \
    UI/deletelink.cpp \
    UI/deletescientist.cpp \
    UI/editcomputers.cpp \
    UI/editscientist.cpp \
    UI/addlink.cpp \
    UI/logobox.cpp

HEADERS  += UI/mainwindow.h \
    The_Children/computer.h \
    The_Children/computerscientist.h \
    domain/helper.h \
    Data/computerdata.h \
    Data/scientistdata.h \
    Data/sqlconnect.h \
    domain/domain.h \
    UI/add_scientist.h \
    UI/add_computer.h \
    UI/deletecomputer.h \
    UI/deletelink.h \
    UI/deletescientist.h \
    UI/editcomputers.h \
    UI/editscientist.h \
    UI/addlink.h \
    UI/logobox.h

FORMS    += UI/mainwindow.ui \
    UI/add_scientist.ui \
    UI/add_computer.ui \
    UI/deletecomputer.ui \
    UI/deletelink.ui \
    UI/deletescientist.ui \
    UI/editcomputers.ui \
    UI/editscientist.ui \
    UI/addlink.ui \
    UI/logobox.ui

RESOURCES += \
    themelogo.qrc

DISTFILES +=
