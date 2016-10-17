QT += core
QT -= gui

CONFIG += c++11

TARGET = Metodos2
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    function.cpp

HEADERS += \
    function.h \
    general.h
