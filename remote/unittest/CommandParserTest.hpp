#ifndef COMMANDPARSERTEST_HPP
#define COMMANDPARSERTEST_HPP

#include <CommandParser.hpp>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class TestCommandParser : public CommandParser
{
	public:
		TestCommandParser(CommandParserOutput &output, bool &destructorCalled);
		~TestCommandParser();

		QString commmand() const;
		uint argumentCount() const;
		void parse(const QStringList &arg) const;

	private:
		bool &mDestructorCalled;

};

class CommandParserTest : public CPPUNIT_NS::TestFixture
{
		CPPUNIT_TEST_SUITE( CommandParserTest );

		CPPUNIT_TEST(destructor_is_virtual);
		CPPUNIT_TEST(construct_with_parser);

		CPPUNIT_TEST(has_command);
		CPPUNIT_TEST(has_argumentCount);
		CPPUNIT_TEST(has_parse);

		CPPUNIT_TEST(parseInteger);
		CPPUNIT_TEST(parseInteger_with_string);
		CPPUNIT_TEST(parseInteger_with_empty);
		CPPUNIT_TEST(parseInteger_with_negative);
		CPPUNIT_TEST(parseInteger_with_float);

		CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void tearDown();

		void destructor_is_virtual();
		void construct_with_parser();

		void has_command();
		void has_argumentCount();
		void has_parse();

		void parseInteger();
		void parseInteger_with_string();
		void parseInteger_with_empty();
		void parseInteger_with_negative();
		void parseInteger_with_float();

	private:
		CommandParser *parser = nullptr;
		CommandParserOutput *output = nullptr;
		bool destructorCalled = false;

};

CPPUNIT_TEST_SUITE_REGISTRATION( CommandParserTest );

#endif // COMMANDPARSERTEST_HPP
