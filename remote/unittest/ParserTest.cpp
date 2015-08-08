#include "ParserTest.hpp"

void ParserTest::setUp()
{
	receiver = new ParserReceiver();
	parser = new Parser();

	QObject::connect(parser, SIGNAL(add(std::string,std::string,std::array<int,3>,int)), receiver, SLOT(add(std::string,std::string,std::array<int,3>,int)));
}

void ParserTest::tearDown()
{
	delete parser;
	parser = nullptr;
	delete receiver;
	receiver = nullptr;
}

void ParserTest::nextToken_string()
{
	int pos = 0;
	const QString token = parser->nextToken("hallo  ", pos);
	CPPUNIT_ASSERT_EQUAL(std::string("hallo"), token.toStdString());
	CPPUNIT_ASSERT_EQUAL(5, pos);
}

void ParserTest::nextToken_quoted_string()
{
	int pos = 0;
	const QString token = parser->nextToken("\"hello world\"  ", pos);
	CPPUNIT_ASSERT_EQUAL(std::string("hello world"), token.toStdString());
	CPPUNIT_ASSERT_EQUAL(13, pos);
}

void ParserTest::tokenize_empty()
{
	const QList<QString> tokens = parser->tokenize("");
	CPPUNIT_ASSERT_EQUAL(0, tokens.size());
}

void ParserTest::tokenize_single_string()
{
	const QList<QString> tokens = parser->tokenize("hello");
	CPPUNIT_ASSERT_EQUAL(1, tokens.size());
	CPPUNIT_ASSERT_EQUAL(std::string("hello"), tokens[0].toStdString());
}

void ParserTest::tokenize_single_number()
{
	const QList<QString> tokens = parser->tokenize("7");
	CPPUNIT_ASSERT_EQUAL(1, tokens.size());
	CPPUNIT_ASSERT_EQUAL(std::string("7"), tokens[0].toStdString());
}

void ParserTest::tokenize_two_items()
{
	const QList<QString> tokens = parser->tokenize("2 test");
	CPPUNIT_ASSERT_EQUAL(2, tokens.size());
	CPPUNIT_ASSERT_EQUAL(std::string("2"), tokens[0].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("test"), tokens[1].toStdString());
}

void ParserTest::tokenize_three_items()
{
	const QList<QString> tokens = parser->tokenize("3 hello world");
	CPPUNIT_ASSERT_EQUAL(3, tokens.size());
	CPPUNIT_ASSERT_EQUAL(std::string("3"), tokens[0].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("hello"), tokens[1].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("world"), tokens[2].toStdString());
}

void ParserTest::tokenize_ignore_multiple_spaces()
{
	const QList<QString> tokens = parser->tokenize("1     2");
	CPPUNIT_ASSERT_EQUAL(2, tokens.size());
	CPPUNIT_ASSERT_EQUAL(std::string("1"), tokens[0].toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("2"), tokens[1].toStdString());
}

void ParserTest::tokenize_ignore_spaces_at_front()
{
	const QList<QString> tokens = parser->tokenize("    x");
	CPPUNIT_ASSERT_EQUAL(1, tokens.size());
	CPPUNIT_ASSERT_EQUAL(std::string("x"), tokens[0].toStdString());
}

void ParserTest::tokenize_ignore_spaces_at_end()
{
	const QList<QString> tokens = parser->tokenize("x    ");
	CPPUNIT_ASSERT_EQUAL(1, tokens.size());
	CPPUNIT_ASSERT_EQUAL(std::string("x"), tokens[0].toStdString());
}

void ParserTest::tokenize_string_with_spaces()
{
	const QList<QString> tokens = parser->tokenize("\"hello world\"");
	CPPUNIT_ASSERT_EQUAL(1, tokens.size());
	CPPUNIT_ASSERT_EQUAL(std::string("hello world"), tokens[0].toStdString());
}

void ParserTest::add()
{
	parser->parse("add 3001 red 2 3 4 1");

	CPPUNIT_ASSERT_EQUAL(std::string("add"), receiver->command);
	CPPUNIT_ASSERT_EQUAL(std::string("3001"), receiver->type);
	CPPUNIT_ASSERT_EQUAL(std::string("red"), receiver->color);
	CPPUNIT_ASSERT_EQUAL(2, receiver->x);
	CPPUNIT_ASSERT_EQUAL(3, receiver->y);
	CPPUNIT_ASSERT_EQUAL(4, receiver->z);
	CPPUNIT_ASSERT_EQUAL(1, receiver->rotation);
}

void ParserTest::add_with_quoted_type()
{
	parser->parse("add \"the brick\" red 2 3 4 1");

	CPPUNIT_ASSERT_EQUAL(std::string("add"), receiver->command);
	CPPUNIT_ASSERT_EQUAL(std::string("the brick"), receiver->type);
	CPPUNIT_ASSERT_EQUAL(std::string("red"), receiver->color);
	CPPUNIT_ASSERT_EQUAL(2, receiver->x);
	CPPUNIT_ASSERT_EQUAL(3, receiver->y);
	CPPUNIT_ASSERT_EQUAL(4, receiver->z);
	CPPUNIT_ASSERT_EQUAL(1, receiver->rotation);
}

void ParserTest::add_with_quoted_color()
{
	parser->parse("add brick \"light red\" 2 3 4 1");

	CPPUNIT_ASSERT_EQUAL(std::string("add"), receiver->command);
	CPPUNIT_ASSERT_EQUAL(std::string("brick"), receiver->type);
	CPPUNIT_ASSERT_EQUAL(std::string("light red"), receiver->color);
	CPPUNIT_ASSERT_EQUAL(2, receiver->x);
	CPPUNIT_ASSERT_EQUAL(3, receiver->y);
	CPPUNIT_ASSERT_EQUAL(4, receiver->z);
	CPPUNIT_ASSERT_EQUAL(1, receiver->rotation);
}
