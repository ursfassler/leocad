#ifndef COMMANDSTEST_HPP
#define COMMANDSTEST_HPP

#include <Commands.hpp>
#include "ParserReceiver.hpp"

#include <QStringList>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>


class BaseCmdTest : public CPPUNIT_NS::TestFixture
{
	public:
		virtual CommandParser *createParser(CommandParserOutput &output) const = 0;
		void setUp();
		void tearDown();

	protected:
		CommandParser *parser = nullptr;
		CommandParserOutput *output = nullptr;
		ParserReceiver *receiver = nullptr;

};


class CmdHelloTest : public BaseCmdTest
{
		CPPUNIT_TEST_SUITE( CmdHelloTest );

		CPPUNIT_TEST(command);
		CPPUNIT_TEST(argumentCount);
		CPPUNIT_TEST(parse);

		CPPUNIT_TEST_SUITE_END();

	public:
		CommandParser *createParser(CommandParserOutput &output) const;

		void command();
		void argumentCount();
		void parse();

};

CPPUNIT_TEST_SUITE_REGISTRATION( CmdHelloTest );


class CmdClearTest : public BaseCmdTest
{
		CPPUNIT_TEST_SUITE( CmdClearTest );

		CPPUNIT_TEST(command);
		CPPUNIT_TEST(argumentCount);
		CPPUNIT_TEST(parse);

		CPPUNIT_TEST_SUITE_END();

	public:
		CommandParser *createParser(CommandParserOutput &output) const;

		void command();
		void argumentCount();
		void parse();

};

CPPUNIT_TEST_SUITE_REGISTRATION( CmdClearTest );


class CmdAddTest : public BaseCmdTest
{
		CPPUNIT_TEST_SUITE( CmdAddTest );

		CPPUNIT_TEST(command);
		CPPUNIT_TEST(argumentCount);
		CPPUNIT_TEST(parse);

		CPPUNIT_TEST(cmd_add_expects_integer_for_x);
		CPPUNIT_TEST(cmd_add_expects_integer_for_y);
		CPPUNIT_TEST(cmd_add_expects_integer_for_z);
		CPPUNIT_TEST(cmd_add_expects_integer_for_rotation);

		CPPUNIT_TEST_SUITE_END();

	public:
		CommandParser *createParser(CommandParserOutput &output) const;

		void command();
		void argumentCount();
		void parse();

		void cmd_add_expects_integer_for_x();
		void cmd_add_expects_integer_for_y();
		void cmd_add_expects_integer_for_z();
		void cmd_add_expects_integer_for_rotation();

};

CPPUNIT_TEST_SUITE_REGISTRATION( CmdAddTest );


#endif // COMMANDSTEST_HPP
