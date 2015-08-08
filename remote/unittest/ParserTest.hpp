#ifndef PARSERTEST_HPP
#define PARSERTEST_HPP

#include <Parser.hpp>
#include "ParserReceiver.hpp"

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

class ParserTest : public CPPUNIT_NS::TestFixture
{
		CPPUNIT_TEST_SUITE( ParserTest );

		CPPUNIT_TEST(nextToken_string);
		CPPUNIT_TEST(nextToken_quoted_string);

		CPPUNIT_TEST(tokenize_empty);
		CPPUNIT_TEST(tokenize_single_string);
		CPPUNIT_TEST(tokenize_single_number);
		CPPUNIT_TEST(tokenize_two_items);
		CPPUNIT_TEST(tokenize_three_items);
		CPPUNIT_TEST(tokenize_ignore_multiple_spaces);
		CPPUNIT_TEST(tokenize_ignore_spaces_at_front);
		CPPUNIT_TEST(tokenize_ignore_spaces_at_end);
		CPPUNIT_TEST(tokenize_string_with_spaces);

		CPPUNIT_TEST(add);
		CPPUNIT_TEST(add_with_quoted_type);
		CPPUNIT_TEST(add_with_quoted_color);

		CPPUNIT_TEST(cmd_clear);
		CPPUNIT_TEST(clear_does_not_allow_arguments);

		CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void tearDown();

		void nextToken_string();
		void nextToken_quoted_string();

		void tokenize_empty();
		void tokenize_single_string();
		void tokenize_single_number();
		void tokenize_two_items();
		void tokenize_three_items();
		void tokenize_ignore_multiple_spaces();
		void tokenize_ignore_spaces_at_front();
		void tokenize_ignore_spaces_at_end();
		void tokenize_string_with_spaces();

		void add();
		void add_with_quoted_type();
		void add_with_quoted_color();

		void cmd_clear();
		void clear_does_not_allow_arguments();

	private:
		Parser *parser = nullptr;
		ParserReceiver *receiver = nullptr;


};

CPPUNIT_TEST_SUITE_REGISTRATION( ParserTest );

#endif // PARSERTEST_HPP
