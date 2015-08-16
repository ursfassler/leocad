#include "ParserTest.hpp"

void ParserTest::setUp()
{
	receiver = new ParserReceiver();
	parser = new Parser();

	QObject::connect(parser, SIGNAL(nop()), receiver, SLOT(nop()));
	QObject::connect(parser, SIGNAL(hello(std::string,std::string)), receiver, SLOT(hello(std::string,std::string)));
	QObject::connect(parser, SIGNAL(add(std::string,std::string,std::array<int,3>,int)), receiver, SLOT(add(std::string,std::string,std::array<int,3>,int)));
	QObject::connect(parser, SIGNAL(clear()), receiver, SLOT(clear()));
}

void ParserTest::tearDown()
{
	delete parser;
	parser = nullptr;
	delete receiver;
	receiver = nullptr;
}

void ParserTest::cmd_nop()
{
	parser->parse({});

	CPPUNIT_ASSERT_EQUAL(std::string("nop"), receiver->command);
}

void ParserTest::cmd_hello()
{
	parser->parse({"hello", "from", "Parser Unit Test"});

	CPPUNIT_ASSERT_EQUAL(std::string("hello"), receiver->command);
	CPPUNIT_ASSERT_EQUAL(std::string("from"), receiver->sub);
	CPPUNIT_ASSERT_EQUAL(std::string("Parser Unit Test"), receiver->whom);
}

void ParserTest::add()
{
	parser->parse({"add", "3001", "red",  "2", "3", "4", "1"});

	CPPUNIT_ASSERT_EQUAL(std::string("add"), receiver->command);
	CPPUNIT_ASSERT_EQUAL(std::string("3001"), receiver->type);
	CPPUNIT_ASSERT_EQUAL(std::string("red"), receiver->color);
	CPPUNIT_ASSERT_EQUAL(2, receiver->x);
	CPPUNIT_ASSERT_EQUAL(3, receiver->y);
	CPPUNIT_ASSERT_EQUAL(4, receiver->z);
	CPPUNIT_ASSERT_EQUAL(1, receiver->rotation);
}

void ParserTest::cmd_clear()
{
	parser->parse({"clear"});

	CPPUNIT_ASSERT_EQUAL(std::string("clear"), receiver->command);
}

void ParserTest::clear_does_not_allow_arguments()
{
	parser->parse({"clear", "all"});

	CPPUNIT_ASSERT_EQUAL(std::string(""), receiver->command);
}
