#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "CommandParser.hpp"

#include <QStringList>

class CmdHello : public CommandParser
{
	public:
		CmdHello(CommandParserOutput &output);

		QString commmand() const;
		uint argumentCount() const;
		void parse(QStringList arg) const;
};

class CmdClear : public CommandParser
{
	public:
		CmdClear(CommandParserOutput &output);

		QString commmand() const;
		uint argumentCount() const;
		void parse(QStringList arg) const;
};

class CmdAdd : public CommandParser
{
	public:
		CmdAdd(CommandParserOutput &output);

		QString commmand() const;
		uint argumentCount() const;
		void parse(QStringList arg) const;

	private:
		QList<int> parseIntValues(QStringList args, QStringList argNames) const;
		void sendIntError(QString argName, QString text) const;
};

#endif // COMMANDS_HPP
