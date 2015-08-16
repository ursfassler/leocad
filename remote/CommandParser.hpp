#ifndef COMMANDPARSER_HPP
#define COMMANDPARSER_HPP

#include <QObject>
#include <QPair>

#include <array>

class CommandParserOutput : public QObject
{
		Q_OBJECT
	signals:
		void error(const std::string &msg);
		void nop();
		void hello(const std::string &sub, const std::string &whom);
		void add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation);
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
		virtual void parse(const QStringList &arg) const = 0;

		QPair<bool,int> parseInteger(QString value) const;

	private:
		CommandParserOutput &mOutput;
};

#endif // COMMANDPARSER_HPP
