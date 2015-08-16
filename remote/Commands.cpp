#include "Commands.hpp"

CmdHello::CmdHello(CommandParserOutput &output) :
	CommandParser(output)
{
}

QString CmdHello::commmand() const
{
	return "hello";
}

uint CmdHello::argumentCount() const
{
	return 2;
}

void CmdHello::parse(const QStringList &arg) const
{
	output().hello(arg[0], arg[1]);
}


CmdClear::CmdClear(CommandParserOutput &output):
	CommandParser(output)
{
}

QString CmdClear::commmand() const
{
	return "clear";
}

uint CmdClear::argumentCount() const
{
	return 0;
}

void CmdClear::parse(const QStringList &) const
{
	output().clear();
}


CmdAdd::CmdAdd(CommandParserOutput &output):
	CommandParser(output)
{
}

QString CmdAdd::commmand() const
{
	return "add";
}

uint CmdAdd::argumentCount() const
{
	return 6;
}

void CmdAdd::parse(const QStringList &args) const
{
	const QString type = args[0];
	const QString color = args[1];

	const QStringList names(QStringList() << "x" << "y" << "z" << "rotation");
	const QList<int> intValues = parseIntValues(args.mid(2,-1), names);
	if (intValues.size() != 4)
	{
		return;
	}

	const std::array<int,3> pos = { intValues[0], intValues[1], intValues[2] };

	output().add(type, color, pos, intValues[3]);
}

QList<int> CmdAdd::parseIntValues(const QStringList &args, const QStringList &argNames) const
{
	if (args.size() != argNames.size())
	{
		return QList<int>();
	}

	QList<int> ret;
	for (int i = 0; i < argNames.size(); i++)
	{
		const QString arg = args[i];
		const QPair<bool,int> res = parseInteger(arg);
		if (!res.first)
		{
			sendIntError(argNames[i], arg);
			return QList<int>();
		}
		ret.append(res.second);
	}
	return ret;
}

void CmdAdd::sendIntError(QString argName, QString text) const
{
	const QString msg = "command add expects integer for " + argName + ", got " + text;
	output().error(msg);
}

