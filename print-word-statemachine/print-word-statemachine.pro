QT += core
QT -= gui

CONFIG += c++14

TARGET = print-word-statemachine
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    filereader.cpp \
    charstreamprocessor.cpp \
    newchartransition.cpp \
    printstate.cpp \
    accumulatestate.cpp \
    nonspacetransition.cpp \
    clearstate.cpp

HEADERS += \
    filereader.h \
    charstreamprocessor.h \
    newchartransition.h \
    newcharevent.h \
    printstate.h \
    accumulatestate.h \
    nonspacetransition.h \
    clearstate.h

DISTFILES += \
    sample_input.txt
