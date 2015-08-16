#include "CommandParserTest.hpp"

#include <QStringList>


TestCommandParser::TestCommandParser(CommandParserOutput &output, bool &destructorCalled) :
	CommandParser(output),
	mDestructorCalled(destructorCalled)
{
}

TestCommandParser::~TestCommandParser()
{
	mDestructorCalled = true;
}

QString TestCommandParser::commmand() const
{
	return "testCommand";
}

uint TestCommandParser::argumentCount() const
{
	return 42;
}

void TestCommandParser::parse(const QStringList &) const
{
}


void CommandParserTest::setUp()
{
	output = new CommandParserOutput();
	destructorCalled = false;
	parser = new TestCommandParser(*output, destructorCalled);
}

void CommandParserTest::tearDown()
{
	delete parser;
	parser = nullptr;
	delete output;
	output = nullptr;
}

void CommandParserTest::destructor_is_virtual()
{
	CommandParser *parser = new TestCommandParser(*output, destructorCalled);
	delete parser;
	CPPUNIT_ASSERT(destructorCalled);
}

void CommandParserTest::construct_with_parser()
{
	CPPUNIT_ASSERT_EQUAL(output, &parser->output());
}

void CommandParserTest::has_command()
{
	CPPUNIT_ASSERT_EQUAL(std::string("testCommand"), parser->commmand().toStdString());
}

void CommandParserTest::has_argumentCount()
{
	CPPUNIT_ASSERT_EQUAL(uint(42), parser->argumentCount());
}

void CommandParserTest::has_parse()
{
	const QStringList list;
	parser->parse(list);
}

void CommandParserTest::parseInteger()
{
	const QPair<bool,int> result = parser->parseInteger("42");
	CPPUNIT_ASSERT_EQUAL(true, result.first);
	CPPUNIT_ASSERT_EQUAL(42, result.second);
}

void CommandParserTest::parseInteger_with_string()
{
	const QPair<bool,int> result = parser->parseInteger("hallo");
	CPPUNIT_ASSERT_EQUAL(false, result.first);
}

void CommandParserTest::parseInteger_with_empty()
{
	const QPair<bool,int> result = parser->parseInteger("");
	CPPUNIT_ASSERT_EQUAL(false, result.first);
}

void CommandParserTest::parseInteger_with_negative()
{
	const QPair<bool,int> result = parser->parseInteger("-42");
	CPPUNIT_ASSERT_EQUAL(true, result.first);
	CPPUNIT_ASSERT_EQUAL(-42, result.second);
}

void CommandParserTest::parseInteger_with_float()
{
	const QPair<bool,int> result = parser->parseInteger("12.34");
	CPPUNIT_ASSERT_EQUAL(false, result.first);
}

