#ifndef PARSER_HPP
#define PARSER_HPP

#include "CommandParser.hpp"

#include <QObject>
#include <QString>
#include <QHash>
#include <QList>
#include <QStringList>
#include <QSet>

#include <array>


class ParserTest;

class Parser : public CommandParserOutput
{
		Q_OBJECT
	public:
		Parser();
		~Parser();

		CommandParser *getCmdParser(QString cmd);

	public slots:
		void parse(const QList<QString> &command);

	private:
		QSet<CommandParser*> mCmdParser;

		void parse(const QString &command, const QList<QString> &arg);

		QString unknownCommandMsg(const QString &command, const QList<QString> &arg) const;
		QString argCountErrorMsg(QString command, int expected, int received) const;

		friend ParserTest;
};

#endif // PARSER_HPP
