#ifndef PARSERTEST_HPP
#define PARSERTEST_HPP

#include <Parser.hpp>
#include "ParserReceiver.hpp"

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ParserTest : public CPPUNIT_NS::TestFixture
{
		CPPUNIT_TEST_SUITE( ParserTest );

		CPPUNIT_TEST(cmd_nop);

		CPPUNIT_TEST(cmd_hello);

		CPPUNIT_TEST(add);

		CPPUNIT_TEST(cmd_clear);
		CPPUNIT_TEST(clear_does_not_allow_arguments);

		CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void tearDown();

		void cmd_nop();

		void cmd_hello();

		void add();

		void cmd_clear();
		void clear_does_not_allow_arguments();

	private:
		Parser *parser = nullptr;
		ParserReceiver *receiver = nullptr;


};

CPPUNIT_TEST_SUITE_REGISTRATION( ParserTest );

#endif // PARSERTEST_HPP
