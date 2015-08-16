#ifndef SERVERCONNECTION_HPP
#define SERVERCONNECTION_HPP

#include "Parser.hpp"

#include <QObject>
#include <QTcpSocket>


class ServerConnection : public QObject
{
		Q_OBJECT
	public:
		explicit ServerConnection(QObject *parent = 0);
		void connect(const QString &hostName, quint16 port);

	signals:
		void add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation);
		void clear();

	public slots:

	private slots:
		void socketError(QAbstractSocket::SocketError error);
		void connected();
		void readyRead();

	private:
		QTcpSocket mSocket;
		Parser mParser;

};

#endif
