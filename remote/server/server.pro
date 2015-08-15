#-------------------------------------------------
#
# Project created by QtCreator 2015-08-15T17:12:20
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        MainWindow.cpp \
    ClientConnector.cpp \
    ScriptEdit.cpp

HEADERS  += MainWindow.hpp \
    ClientConnector.hpp \
    ScriptEdit.hpp
