#ifndef TOKENIZERTEST_HPP
#define TOKENIZERTEST_HPP

#include <Tokenizer.hpp>
#include "TokenizerReceiver.hpp"

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>


class TokenizerTest : public CPPUNIT_NS::TestFixture
{
		CPPUNIT_TEST_SUITE( TokenizerTest );

		CPPUNIT_TEST(nextToken_string);
		CPPUNIT_TEST(nextToken_quoted_string);

		CPPUNIT_TEST(tokenize_empty);
		CPPUNIT_TEST(tokenize_whitespaces);
		CPPUNIT_TEST(tokenize_single_string);
		CPPUNIT_TEST(tokenize_single_number);
		CPPUNIT_TEST(tokenize_two_items);
		CPPUNIT_TEST(tokenize_three_items);
		CPPUNIT_TEST(tokenize_ignore_multiple_spaces);
		CPPUNIT_TEST(tokenize_ignore_spaces_at_front);
		CPPUNIT_TEST(tokenize_ignore_spaces_at_end);
		CPPUNIT_TEST(tokenize_string_with_spaces);

		CPPUNIT_TEST_SUITE_END();

	public:
		void setUp();
		void tearDown();

		void nextToken_string();
		void nextToken_quoted_string();

		void tokenize_empty();
		void tokenize_whitespaces();
		void tokenize_single_string();
		void tokenize_single_number();
		void tokenize_two_items();
		void tokenize_three_items();
		void tokenize_ignore_multiple_spaces();
		void tokenize_ignore_spaces_at_front();
		void tokenize_ignore_spaces_at_end();
		void tokenize_string_with_spaces();

	private:
		Tokenizer *tokenizer = nullptr;
		TokenizerReceiver *receiver = nullptr;


};

CPPUNIT_TEST_SUITE_REGISTRATION( TokenizerTest );

#endif // TOKENIZERTEST_HPP
