#include "Parser.hpp"

#include <QStringList>
#include <QRegExp>

Parser::Parser(QObject *parent) :
	QObject(parent),
	mCommand({
		{"add", &Parser::cmdAdd},
		{"clear", &Parser::cmdClear}
	})
{
}

void Parser::parse(QString command)
{
	const QStringList cmdlst = tokenize(command);

	if (cmdlst.empty())
	{
		return;
	}

	const QString cmd = cmdlst[0];
	const PartParser parser = mCommand.value(cmd, &Parser::nullHandler);
	parser(*this, cmdlst.mid(1, -1));
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

QList<QString> Parser::tokenize(const QString &cmd) const
{
	QList<QString> token;

	int pos = 0;
	while (hasToken(cmd, pos))
	{
		token.append(nextToken(cmd, pos));
	}

	return token;
}

bool Parser::hasToken(const QString &cmd, int &pos) const
{
	for (; pos < cmd.length(); pos++)
	{
		if (cmd.at(pos) != ' ')
		{
			return true;
		}
	}

	return false;
}

QString Parser::nextToken(const QString &cmd, int &pos) const
{
	const bool quoted = cmd.at(pos) == '"';
	const char endchar = quoted ? '"' : ' ';
	const int start = quoted ? pos+1 : pos;
	const int idx = cmd.indexOf(endchar, start);
	const int end = idx >= 0 ? idx : cmd.length();
	Q_ASSERT(end > start);
	pos = quoted ? end+1 : end;
	const int length = end-start;
	return cmd.mid(start, length);
}
