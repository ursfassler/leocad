#ifndef SERVERCONNECTION_HPP
#define SERVERCONNECTION_HPP

#include "Parser.hpp"
#include "Tokenizer.hpp"

#include <QObject>
#include <QTcpSocket>


class ServerConnection : public QObject
{
		Q_OBJECT
	public:
		explicit ServerConnection(QObject *parent = 0);
		void connect(QString hostName, quint16 port);

	signals:
		void hello(QString plate, QString color, QString serverName);
		void add(QString type, QString color, const std::array<int,3> &pos, int rotation);
		void clear();

	public slots:

	private slots:
		void socketError(QAbstractSocket::SocketError error);
		void connected();
		void readyRead();

		void parseError(QString msg);

	private:
		QTcpSocket mSocket;
		Tokenizer mTokenizer;
		Parser mParser;

};

#endif
