QT += core
QT -= gui

TARGET = lastButNotLeast
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app
QT += sql

SOURCES += main.cpp \
    computerscientist.cpp \
    computer.cpp \
    computerdomain.cpp \
    scientistdomain.cpp \
    helper.cpp \
    sqlconnect.cpp \
    scientistdata.cpp \
    computerdata.cpp \
    scientistui.cpp \
    computerui.cpp \
    mainui.cpp \
    ui.cpp

HEADERS += \
    computerscientist.h \
    computer.h \
    computerdomain.h \
    scientistdomain.h \
    helper.h \
    sqlconnect.h \
    scientistdata.h \
    computerdata.h \
    scientistui.h \
    computerui.h \
    mainui.h \
    ui.h

