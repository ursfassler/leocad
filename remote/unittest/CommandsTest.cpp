#include "CommandsTest.hpp"

void BaseCmdTest::setUp()
{
	receiver = new ParserReceiver();
	output = new CommandParserOutput();
	parser = createParser(*output);

	QObject::connect(output, SIGNAL(error(QString)), receiver, SLOT(error(QString)));
	QObject::connect(output, SIGNAL(nop()), receiver, SLOT(nop()));
	QObject::connect(output, SIGNAL(hello(QString,QString)), receiver, SLOT(hello(QString,QString)));
	QObject::connect(output, SIGNAL(add(QString,QString,std::array<int,3>,int)), receiver, SLOT(add(QString,QString,std::array<int,3>,int)));
	QObject::connect(output, SIGNAL(clear()), receiver, SLOT(clear()));
}

void BaseCmdTest::tearDown()
{
	delete parser;
	parser = nullptr;
	delete output;
	output = nullptr;
	delete receiver;
	receiver = nullptr;
}


CommandParser *CmdHelloTest::createParser(CommandParserOutput &output) const
{
	return new CmdHello(output);
}

void CmdHelloTest::command()
{
	CPPUNIT_ASSERT_EQUAL(std::string("hello"), parser->commmand().toStdString());
}

void CmdHelloTest::argumentCount()
{
	CPPUNIT_ASSERT_EQUAL(uint(2), parser->argumentCount());
}

void CmdHelloTest::parse()
{
	parser->parse({"from", "Parser Unit Test"});

	CPPUNIT_ASSERT_EQUAL(std::string("hello"), receiver->command.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("from"), receiver->sub.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("Parser Unit Test"), receiver->whom.toStdString());
}




CommandParser *CmdClearTest::createParser(CommandParserOutput &output) const
{
	return new CmdClear(output);
}

void CmdClearTest::command()
{
	CPPUNIT_ASSERT_EQUAL(std::string("clear"), parser->commmand().toStdString());
}

void CmdClearTest::argumentCount()
{
	CPPUNIT_ASSERT_EQUAL(uint(0), parser->argumentCount());
}

void CmdClearTest::parse()
{
	parser->parse({});

	CPPUNIT_ASSERT_EQUAL(std::string("clear"), receiver->command.toStdString());
}


CommandParser *CmdAddTest::createParser(CommandParserOutput &output) const
{
	return new CmdAdd(output);
}

void CmdAddTest::command()
{
	CPPUNIT_ASSERT_EQUAL(std::string("add"), parser->commmand().toStdString());
}

void CmdAddTest::argumentCount()
{
	CPPUNIT_ASSERT_EQUAL(uint(6), parser->argumentCount());
}

void CmdAddTest::parse()
{
	parser->parse({"3001", "red",  "2", "3", "4", "1"});

	CPPUNIT_ASSERT_EQUAL(std::string("add"), receiver->command.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("3001"), receiver->type.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("red"), receiver->color.toStdString());
	CPPUNIT_ASSERT_EQUAL(2, receiver->x);
	CPPUNIT_ASSERT_EQUAL(3, receiver->y);
	CPPUNIT_ASSERT_EQUAL(4, receiver->z);
	CPPUNIT_ASSERT_EQUAL(1, receiver->rotation);
}

void CmdAddTest::cmd_add_expects_integer_for_x()
{
	parser->parse({"3001", "red", "text", "3", "4", "1"});

	CPPUNIT_ASSERT_EQUAL(std::string("error"), receiver->command.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("command add expects integer for x, got text"), receiver->errorMsg.toStdString());
}

void CmdAddTest::cmd_add_expects_integer_for_y()
{
	parser->parse({"3001", "red", "2", "hello", "4", "1"});

	CPPUNIT_ASSERT_EQUAL(std::string("error"), receiver->command.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("command add expects integer for y, got hello"), receiver->errorMsg.toStdString());
}

void CmdAddTest::cmd_add_expects_integer_for_z()
{
	parser->parse({"3001", "red", "2", "3", "", "1"});

	CPPUNIT_ASSERT_EQUAL(std::string("error"), receiver->command.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("command add expects integer for z, got "), receiver->errorMsg.toStdString());
}

void CmdAddTest::cmd_add_expects_integer_for_rotation()
{
	parser->parse({"3001", "red", "2", "3", "4", "13.4"});

	CPPUNIT_ASSERT_EQUAL(std::string("error"), receiver->command.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("command add expects integer for rotation, got 13.4"), receiver->errorMsg.toStdString());
}
