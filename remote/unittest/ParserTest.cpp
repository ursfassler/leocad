#include "ParserTest.hpp"

#include "Commands.hpp"

void ParserTest::setUp()
{
	receiver = new ParserReceiver();
	parser = new Parser();

	QObject::connect(parser, SIGNAL(error(QString)), receiver, SLOT(error(QString)));
	QObject::connect(parser, SIGNAL(nop()), receiver, SLOT(nop()));
	QObject::connect(parser, SIGNAL(hello(QString,QString,QString)), receiver, SLOT(hello(QString,QString,QString)));
	QObject::connect(parser, SIGNAL(add(QString,QString,std::array<int,3>,int)), receiver, SLOT(add(QString,QString,std::array<int,3>,int)));
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

	CPPUNIT_ASSERT_EQUAL(std::string("nop"), receiver->command.toStdString());
}

void ParserTest::cmd_hello()
{
	CommandParser *cmd = parser->getCmdParser("hello");
	CPPUNIT_ASSERT(dynamic_cast<CmdHello*>(cmd) != nullptr);
}

void ParserTest::cmd_add()
{
	CommandParser *cmd = parser->getCmdParser("add");
	CPPUNIT_ASSERT(dynamic_cast<CmdAdd*>(cmd) != nullptr);
}

void ParserTest::cmd_clear()
{
	CommandParser *cmd = parser->getCmdParser("clear");
	CPPUNIT_ASSERT(dynamic_cast<CmdClear*>(cmd) != nullptr);
}

void ParserTest::argCountErrorMsg_0_1()
{
	const QString msg = parser->argCountErrorMsg("CMD", 0, 1);
	CPPUNIT_ASSERT_EQUAL(std::string("command CMD expects 0 arguments, got 1"), msg.toStdString());
}

void ParserTest::argCountErrorMsg_1_0()
{
	const QString msg = parser->argCountErrorMsg("test test", 1, 0);
	CPPUNIT_ASSERT_EQUAL(std::string("command test test expects 1 arguments, got 0"), msg.toStdString());
}

void ParserTest::argCountErrorMsg_4_9()
{
	const QString msg = parser->argCountErrorMsg("", 4, 9);
	CPPUNIT_ASSERT_EQUAL(std::string("command  expects 4 arguments, got 9"), msg.toStdString());
}

void ParserTest::send_error_on_wrong_argument_count()
{
	parser->parse("clear", {"this"});
	CPPUNIT_ASSERT_EQUAL(std::string("error"), receiver->command.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("command clear expects 0 arguments, got 1"), receiver->errorMsg.toStdString());
}

void ParserTest::unknownCommandMsg()
{
	const QString msg = parser->unknownCommandMsg("CMD", {});
	CPPUNIT_ASSERT_EQUAL(std::string("unknown command: CMD"), msg.toStdString());
}

void ParserTest::unknownCommandMsg_with_arguments()
{
	const QString msg = parser->unknownCommandMsg("CMD", {"arg1", "arg2"});
	CPPUNIT_ASSERT_EQUAL(std::string("unknown command: CMD arg1 arg2"), msg.toStdString());
}

void ParserTest::send_error_on_on_unknown_cmd()
{
	parser->parse("lala", {});
	CPPUNIT_ASSERT_EQUAL(std::string("error"), receiver->command.toStdString());
	CPPUNIT_ASSERT_EQUAL(std::string("unknown command: lala"), receiver->errorMsg.toStdString());
}


