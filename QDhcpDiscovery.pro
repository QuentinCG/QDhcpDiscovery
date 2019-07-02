QT += core
QT += network

QT -= gui

CONFIG += c++11

TARGET = QDhcpDiscovery
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
           main.cpp \
           src/QDhcpDiscovery.cpp

HEADERS += \
           include/QDhcpDiscovery.h

INCLUDEPATH  =  include
