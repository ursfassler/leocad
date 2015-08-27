#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include <QObject>
#include <QPair>

#include <array>

class CommandParserOutput : public QObject
{
		Q_OBJECT
	public:
		void emitError(QString msg);
		void emitNop();
		void emitHello(QString plate, QString color, QString serverName);
		void emitAdd(QString type, QString color, const std::array<int,3> &pos, int rotation);
		void emitClear();

	signals:
		void error(QString msg);
		void nop();
		void hello(QString plate, QString color, QString serverName);
		void add(QString type, QString color, const std::array<int,3> &pos, int rotation);
		void clear();
};

class CommandParser
{
	public:
		CommandParser(CommandParserOutput &output);
		virtual ~CommandParser();

		CommandParserOutput &output() const;

		virtual QString commmand() const = 0;
		virtual uint argumentCount() const = 0;
		virtual void parse(QStringList arg) const = 0;

		QPair<bool,int> parseInteger(QString value) const;

	private:
		CommandParserOutput &mOutput;
};

#endif // COMMANDPARSER_HPP
