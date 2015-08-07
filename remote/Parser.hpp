#ifndef PARSER_HPP
#define PARSER_HPP

#include <QObject>
#include <QString>
#include <QHash>
#include <QList>

#include <functional>
#include <array>

class Parser : public QObject
{
		Q_OBJECT
	public:
		explicit Parser(QObject *parent = 0);

	signals:
		void add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation);

	public slots:
		void parse(QString command);

	private:
		typedef std::function<void(Parser &, const QList<QString> &cmd)> PartParser;
		const QHash<QString,PartParser> mCommand;

		void cmdAdd(const QList<QString> &cmd);
		void nullHandler(const QList<QString> &);

};

#endif // PARSER_HPP
