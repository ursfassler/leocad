#include "ServerConnection.hpp"

#include <QApplication>

ServerConnection::ServerConnection(QObject *parent) :
	QObject(parent)
{
	QObject::connect(&mSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));
	QObject::connect(&mSocket, SIGNAL(connected()), this, SLOT(connected()));
	QObject::connect(&mSocket, SIGNAL(readyRead()), this, SLOT(readyRead()));

	QObject::connect(&mTokenizer, SIGNAL(tokens(QStringList)), &mParser, SLOT(parse(QStringList)));

	QObject::connect(&mParser, SIGNAL(hello(QString,QString,QString)), this, SIGNAL(hello(QString,QString,QString)));
	QObject::connect(&mParser, SIGNAL(add(QString,QString,std::array<int,3>,int)), this, SIGNAL(add(QString,QString,std::array<int,3>,int)));
	QObject::connect(&mParser, SIGNAL(clear()), this, SIGNAL(clear()));
	QObject::connect(&mParser, SIGNAL(error(QString)), this, SLOT(parseError(QString)));
}

void ServerConnection::connect(QString hostName, quint16 port)
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
	QString whoami = inst->applicationName() + " " + inst->applicationVersion();
	whoami.replace(' ', '_');
	mSocket.write(("hello from " + whoami + "\n").toUtf8());
	qDebug() << "connected";
}

void ServerConnection::readyRead()
{
	while (mSocket.canReadLine())
	{
		const QString line = mSocket.readLine().trimmed();
		mTokenizer.tokenize(line);
	}
}

void ServerConnection::parseError(QString msg)
{
	qDebug() << msg;
}
