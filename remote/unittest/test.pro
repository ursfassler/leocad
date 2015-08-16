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
    TokenizerReceiver.cpp \
    CommandParserTest.cpp \
    CommandsTest.cpp \
    ../CommandParser.cpp \
    ../Commands.cpp

HEADERS += \
    ParserTest.hpp \
    ../Parser.hpp \
    ParserReceiver.hpp \
    TokenizerTest.hpp \
    ../Tokenizer.hpp \
    TokenizerReceiver.hpp \
    CommandParserTest.hpp \
    CommandsTest.hpp \
    ../CommandParser.hpp \
    ../Commands.hpp
