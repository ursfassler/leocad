#ifndef PARSERRECEIVER_HPP
#define PARSERRECEIVER_HPP

#include <QObject>

#include <QString>
#include <array>

class ParserReceiver : public QObject
{
		Q_OBJECT
	public:
		explicit ParserReceiver(QObject *parent = 0);

		QString errorMsg;

		QString command;
		QString plate;
		QString server;
		QString type;
		QString color;
		int x;
		int y;
		int z;
		int rotation;

	signals:

	public slots:
		void error(QString msg);
		void nop();
		void hello(QString plate, QString color, QString serverName);
		void add(QString type, QString color, const std::array<int,3> &pos, int rotation);
		void clear();

};

#endif // PARSERRECEIVER_HPP
