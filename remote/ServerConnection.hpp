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
		void connect(const QString &hostName, quint16 port);

	signals:
		void add(const QString &type, const QString &color, const std::array<int,3> &pos, int rotation);
		void clear();

	public slots:

	private slots:
		void socketError(QAbstractSocket::SocketError error);
		void connected();
		void readyRead();

		void parseError(const QString &msg);
		void hello(const QString &sub, const QString &from);

	private:
		QTcpSocket mSocket;
		Tokenizer mTokenizer;
		Parser mParser;

};

#endif
