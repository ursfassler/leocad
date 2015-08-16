#ifndef PARSER_HPP
#define PARSER_HPP

#include <QObject>
#include <QString>
#include <QHash>
#include <QList>

#include <array>

class Parser : public QObject
{
		Q_OBJECT
	public:
		explicit Parser(QObject *parent = 0);

	signals:
		void nop();
		void hello(const std::string &sub, const std::string &whom);
		void add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation);
		void clear();

	public slots:
		void parse(const QList<QString> &command);

	private:
		void parse(const QString &command, const QList<QString> &arg);
		void cmdHello(const QList<QString> &cmd);
		void cmdAdd(const QList<QString> &cmd);
		void cmdClear(const QList<QString> &cmd);
		void nullHandler(const QList<QString> &cmd);
};

#endif // PARSER_HPP
