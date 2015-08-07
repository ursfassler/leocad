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
