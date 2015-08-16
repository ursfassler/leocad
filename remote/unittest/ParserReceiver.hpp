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

		QString sub;
		QString whom;

		QString command;
		QString type;
		QString color;
		int x;
		int y;
		int z;
		int rotation;

	signals:

	public slots:
		void error(const QString &msg);
		void nop();
		void hello(const QString &sub, const QString &whom);
		void add(const QString &type, const QString &color, const std::array<int,3> &pos, int rotation);
		void clear();

};

#endif // PARSERRECEIVER_HPP
