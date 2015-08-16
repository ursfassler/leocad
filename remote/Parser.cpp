#include "Parser.hpp"

#include "Commands.hpp"

#include <QStringList>


Parser::Parser()
{
	mCmdParser.insert(new CmdHello(*this));
	mCmdParser.insert(new CmdAdd(*this));
	mCmdParser.insert(new CmdClear(*this));
}

Parser::~Parser()
{
	foreach (CommandParser *itr, mCmdParser)
	{
		delete itr;
	}
	mCmdParser.clear();
}

CommandParser *Parser::getCmdParser(QString cmd)
{
	foreach (CommandParser *itr, mCmdParser)
	{
		if (itr->commmand() == cmd)
		{
			return itr;
		}
	}
	return nullptr;
}

void Parser::parse(const QList<QString> &command)
{
	if (command.empty())
	{
		emitNop();
	}
	else
	{
		const QString cmd = command[0];
		const QList<QString> arg = command.mid(1, -1);
		parse(cmd, arg);
	}
}

void Parser::parse(const QString &command, const QList<QString> &arg)
{
	CommandParser *parser = getCmdParser(command);
	if (parser == nullptr)
	{
		const QString msg = unknownCommandMsg(command, arg);
		emitError(msg);
		return;
	}

	if (arg.size() != int(parser->argumentCount()))
	{
		const QString msg = argCountErrorMsg(command, parser->argumentCount(), arg.size());
		emitError(msg);
		return;
	}

	parser->parse(arg);
}

QString Parser::unknownCommandMsg(const QString &command, const QList<QString> &arg) const
{
	QString msg = "unknown command: " + command;
	foreach (const QString &itr, arg)
	{
		msg += " " + itr;
	}
	return msg;
}

QString Parser::argCountErrorMsg(QString command, int expected, int received) const
{
	return
		"command " + command + " expects " +
		QString::number(expected) + " arguments, got " +
		QString::number(received);
}
