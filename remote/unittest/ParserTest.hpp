#ifndef PARSERTEST_HPP
#define PARSERTEST_HPP

#include <Parser.hpp>
#include "ParserReceiver.hpp"

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ParserTest : public CPPUNIT_NS::TestFixture
{
		CPPUNIT_TEST_SUITE( ParserTest );

		CPPUNIT_TEST(add);

		CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void tearDown();

		void add();

	private:
		Parser *parser = nullptr;
		ParserReceiver *receiver = nullptr;


};

CPPUNIT_TEST_SUITE_REGISTRATION( ParserTest );

#endif // PARSERTEST_HPP
