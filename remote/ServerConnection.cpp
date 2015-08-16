#include "ServerConnection.hpp"

#include <QApplication>

ServerConnection::ServerConnection(QObject *parent) :
	QObject(parent)
{
	QObject::connect(&mSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));
	QObject::connect(&mSocket, SIGNAL(connected()), this, SLOT(connected()));
	QObject::connect(&mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

	QObject::connect(&mTokenizer, SIGNAL(tokens(QList<QString>)), &mParser, SLOT(parse(QList<QString>)));

	QObject::connect(&mParser, SIGNAL(add(std::string,std::string,std::array<int,3>,int)), this, SIGNAL(add(std::string,std::string,std::array<int,3>,int)));
	QObject::connect(&mParser, SIGNAL(clear()), this, SIGNAL(clear()));
}

void ServerConnection::connect(const QString &hostName, quint16 port)
{
	qDebug() << "connect to " << hostName << port;
	mSocket.connectToHost(hostName, port);
}

void ServerConnection::socketError(QAbstractSocket::SocketError error)
{
	qDebug() << mSocket.errorString();
}

void ServerConnection::connected()
{
	const QCoreApplication *inst = QApplication::instance();
	const QString whoami = inst->applicationName() + " " + inst->applicationVersion();
	mSocket.write(("hello from \"" + whoami + "\"\n").toUtf8());
	qDebug() << "connected";
}

void ServerConnection::readyRead()
{
	while (mSocket.canReadLine())
	{
		const QString line = mSocket.readLine().trimmed();
		qDebug() << line;
		mTokenizer.tokenize(line);
	}
}

