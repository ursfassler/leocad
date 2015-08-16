#include "ClientConnector.hpp"

#include <QApplication>

ClientConnector::ClientConnector(QObject *parent) :
	QObject(parent)
{
}

void ClientConnector::start(quint16 port)
{
	connect(&mServer, SIGNAL(newConnection()), this, SLOT(newConnection()));

	if (mServer.listen(QHostAddress::Any, port))
	{
		started(mServer.serverAddress(), mServer.serverPort());
		clientNumberChanged(mClients.size());
	}
	else
	{
		qWarning("server can not listen");
	}
}

void ClientConnector::send(QString msg)
{
	const QByteArray line = (msg + "\n").toUtf8();

	foreach (QTcpSocket *socket, mClients)
	{
		socket->write(line);
	}
}

void ClientConnector::newConnection()
{
	while (mServer.hasPendingConnections())
	{
		QTcpSocket *socket = mServer.nextPendingConnection();
		connect(socket, SIGNAL(disconnected()), this, SLOT(removeConnection()));
		mClients.append(socket);
		clientNumberChanged(mClients.size());

		const QCoreApplication *inst = QApplication::instance();
		const QString whoami = inst->applicationName() + " " + inst->applicationVersion();
		socket->write(("hello from \"" + whoami + "\"\n").toUtf8());
	}
}

void ClientConnector::removeConnection()
{
	QTcpSocket *socket = dynamic_cast<QTcpSocket*>(sender());
	if (socket != nullptr)
	{
		mClients.removeOne(socket);
		socket->deleteLater();
		clientNumberChanged(mClients.size());
	}
}

