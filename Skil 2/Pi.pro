TEMPLATE = app
CONFIG += console c++11
CONFIG += static
CONFIG -= app_bundle
QT += sql

SOURCES += \
    main.cpp \
    sqlconnect.cpp \
    computersabstract.cpp \
    computerscientist.cpp \
    sqlquerydata.cpp

HEADERS += \
    sqlconnect.h \
    computersabstract.h \
    computerscientist.h \
    sqlquerydata.h

