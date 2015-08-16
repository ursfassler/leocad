#include "Parser.hpp"

#include <QStringList>
#include <QRegExp>

Parser::Parser(QObject *parent) :
	QObject(parent)
{
}

void Parser::parse(const QList<QString> &command)
{
	if (command.empty())
	{
		nop();
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
	if (command == "hello")
	{
		cmdHello(arg);
	}
	else if (command == "add")
	{
		cmdAdd(arg);
	}
	else if(command == "clear")
	{
		cmdClear(arg);
	}
	else
	{
		nullHandler(arg);
	}
}

void Parser::cmdHello(const QList<QString> &cmd)
{
	if (cmd.size() != 2)
	{
		return;
	}

	hello(cmd[0].toStdString(), cmd[1].toStdString());
}

void Parser::cmdAdd(const QList<QString> &cmd)
{
	if (cmd.size() != 6)
	{
		return;
	}

	bool ok = true;

	const QString type = cmd[0];
	const QString color = cmd[1];
	const std::array<int,3> pos = { cmd[2].toInt(&ok), cmd[3].toInt(&ok), cmd[4].toInt(&ok) };
	const int rot = cmd[5].toInt(&ok);

	if (!ok)
	{
		return;
	}

	add(type.toStdString(), color.toStdString(), pos, rot);
}

void Parser::cmdClear(const QList<QString> &cmd)
{
	if (!cmd.empty())
	{
		return;
	}

	clear();
}

void Parser::nullHandler(const QList<QString> &)
{
}

