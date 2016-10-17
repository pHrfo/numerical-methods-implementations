QT += core
QT -= gui

CONFIG += c++11

TARGET = metodos2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    matrix.cpp \
    genvector.cpp

HEADERS += \
    matrix.h \
    general.h \
    genvector.h
