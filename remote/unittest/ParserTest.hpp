#ifndef PARSERTEST_HPP
#define PARSERTEST_HPP

#include <Parser.hpp>
#include "ParserReceiver.hpp"

#include <QStringList>

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>


class ParserTest : public CPPUNIT_NS::TestFixture
{
		CPPUNIT_TEST_SUITE( ParserTest );

		CPPUNIT_TEST(cmd_nop);
		CPPUNIT_TEST(cmd_hello);
		CPPUNIT_TEST(cmd_add);
		CPPUNIT_TEST(cmd_clear);

		CPPUNIT_TEST(argCountErrorMsg_0_1);
		CPPUNIT_TEST(argCountErrorMsg_1_0);
		CPPUNIT_TEST(argCountErrorMsg_4_9);
		CPPUNIT_TEST(send_error_on_wrong_argument_count);

		CPPUNIT_TEST(unknownCommandMsg);
		CPPUNIT_TEST(unknownCommandMsg_with_arguments);
		CPPUNIT_TEST(send_error_on_on_unknown_cmd);

		CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void tearDown();

		void cmd_nop();
		void cmd_hello();
		void cmd_add();
		void cmd_clear();

		void argCountErrorMsg_0_1();
		void argCountErrorMsg_1_0();
		void argCountErrorMsg_4_9();
		void send_error_on_wrong_argument_count();

		void unknownCommandMsg();
		void unknownCommandMsg_with_arguments();
		void send_error_on_on_unknown_cmd();

	private:
		Parser *parser = nullptr;
		ParserReceiver *receiver = nullptr;

};

CPPUNIT_TEST_SUITE_REGISTRATION( ParserTest );

#endif // PARSERTEST_HPP
