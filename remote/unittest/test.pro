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
    ParserReceiver.cpp \
    TokenizerTest.cpp \
    ../Tokenizer.cpp \
    TokenizerReceiver.cpp

HEADERS += \
    ParserTest.hpp \
    ../Parser.hpp \
    ParserReceiver.hpp \
    TokenizerTest.hpp \
    ../Tokenizer.hpp \
    TokenizerReceiver.hpp
