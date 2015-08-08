#ifndef PARSER_HPP
#define PARSER_HPP

#include <QObject>
#include <QString>
#include <QHash>
#include <QList>

#include <functional>
#include <array>

class ParserTest;

class Parser : public QObject
{
		Q_OBJECT
	public:
		explicit Parser(QObject *parent = 0);

	signals:
		void add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation);
		void clear();

	public slots:
		void parse(QString command);

	private:
		typedef std::function<void(Parser &, const QList<QString> &cmd)> PartParser;
		const QHash<QString,PartParser> mCommand;

		void cmdAdd(const QList<QString> &cmd);
		void cmdClear(const QList<QString> &cmd);
		void nullHandler(const QList<QString> &);

		QList<QString> tokenize(const QString &cmd) const;
		bool hasToken(const QString &cmd, int &pos) const;
		QString nextToken(const QString &cmd, int &pos) const;

		friend ParserTest;

};

#endif // PARSER_HPP
