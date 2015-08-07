#include "Parser.hpp"

#include <QStringList>

Parser::Parser(QObject *parent) :
	QObject(parent),
	mCommand({
		{"add", &Parser::cmdAdd}
	})
{
}

void Parser::parse(QString command)
{
	const QStringList cmdlst = command.split(' ', QString::SkipEmptyParts);

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

void Parser::nullHandler(const QList<QString> &)
{
}

