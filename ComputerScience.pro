QT += core
QT -= gui

TARGET = ComputerScience
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    computerscientist.cpp \
    databank.cpp \
    ui.cpp \
    search.cpp

HEADERS += \
    computerscientist.h \
    databank.h \
    ui.h \
    search.h

DISTFILES +=

