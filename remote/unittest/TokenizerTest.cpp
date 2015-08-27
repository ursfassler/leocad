#include "TokenizerTest.hpp"

void TokenizerTest::setUp()
{
	receiver = new TokenizerReceiver();
	tokenizer = new Tokenizer();

	QObject::connect(tokenizer, SIGNAL(tokens(QStringList)), receiver, SLOT(tokens(QStringList)));
}

void TokenizerTest::tearDown()
{
	delete tokenizer;
	tokenizer = nullptr;
	delete receiver;
	receiver = nullptr;
}

void TokenizerTest::tokenize_empty()
{
	tokenizer->tokenize("");
	CPPUNIT_ASSERT_EQUAL(0, receiver->token.size());
}

void TokenizerTest::tokenize_whitespaces()
{
	tokenizer->tokenize("    ");
	CPPUNIT_ASSERT_EQUAL(0, receiver->token.size());
}

void TokenizerTest::tokenize_single_string()
{
	tokenizer->tokenize("hello");
	CPPUNIT_ASSERT_EQUAL(1, receiver->token.size());
	CPPUNIT_ASSERT_EQUAL(std::string("hello"), receiver->token[0].toStdString());
}

void TokenizerTest::tokenize_single_number()
{
	tokenizer->tokenize("7");
	CPPUNIT_ASSERT_EQUAL(1, receiver->token.size());
	CPPUNIT_ASSERT_EQUAL(std::string("7"), receiver->token[0].toStdString());
}

void TokenizerTest::tokenize_two_items()
{
	tokenizer->tokenize("2 test");
	CPPUNIT_ASSERT_EQUAL(2, receiver->token.size());
	CPPUNIT_ASSERT_EQUAL(std::string("2"), receiver->token[0].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("test"), receiver->token[1].toStdString());
}

void TokenizerTest::tokenize_three_items()
{
	tokenizer->tokenize("3 hello world");
	CPPUNIT_ASSERT_EQUAL(3, receiver->token.size());
	CPPUNIT_ASSERT_EQUAL(std::string("3"), receiver->token[0].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("hello"), receiver->token[1].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("world"), receiver->token[2].toStdString());
}

void TokenizerTest::tokenize_ignore_multiple_spaces()
{
	tokenizer->tokenize("1     2");
	CPPUNIT_ASSERT_EQUAL(2, receiver->token.size());
	CPPUNIT_ASSERT_EQUAL(std::string("1"), receiver->token[0].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("2"), receiver->token[1].toStdString());
}

void TokenizerTest::tokenize_ignore_spaces_at_front()
{
	tokenizer->tokenize("    x");
	CPPUNIT_ASSERT_EQUAL(1, receiver->token.size());
	CPPUNIT_ASSERT_EQUAL(std::string("x"), receiver->token[0].toStdString());
}

void TokenizerTest::tokenize_ignore_spaces_at_end()
{
	tokenizer->tokenize("x    ");
	CPPUNIT_ASSERT_EQUAL(1, receiver->token.size());
	CPPUNIT_ASSERT_EQUAL(std::string("x"), receiver->token[0].toStdString());
}

void TokenizerTest::tokenize_string_with_spaces_is_not_possible()
{
	tokenizer->tokenize("\"hello world\"");
	CPPUNIT_ASSERT_EQUAL(2, receiver->token.size());
	CPPUNIT_ASSERT_EQUAL(std::string("\"hello"), receiver->token[0].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("world\""), receiver->token[1].toStdString());
}
