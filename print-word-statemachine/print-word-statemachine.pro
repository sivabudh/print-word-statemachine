QT += core
QT -= gui

CONFIG += c++14

TARGET = print-word-statemachine
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    filereader.cpp \
    charstreamstatemachine.cpp

HEADERS += \
    filereader.h \
    charstreamstatemachine.h

DISTFILES += \
    sample_input.txt
