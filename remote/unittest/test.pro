TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11

QMAKE_CXXFLAGS = -g -Wall -Wextra -pedantic -Werror

LIBS += -lcppunit

INCLUDEPATH += ../

SOURCES += main.cpp \
    ParserTest.cpp \
    ../Parser.cpp \
    ParserReceiver.cpp

HEADERS += \
    ParserTest.hpp \
    ../Parser.hpp \
    ParserReceiver.hpp
