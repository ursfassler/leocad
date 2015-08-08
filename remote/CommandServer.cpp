#include "CommandServer.hpp"

#include <QTcpSocket>
#include <QApplication>

CommandServer::CommandServer(QObject *parent) : QObject(parent)
{
}

void CommandServer::initialize()
{
	connect(&mParser, SIGNAL(add(std::string,std::string,std::array<int,3>,int)), this, SIGNAL(add(std::string,std::string,std::array<int,3>,int)));

	if (!mServer.listen(QHostAddress::Any, mPort))
	{
		qWarning("server can not listen");
	}

	connect(&mServer, SIGNAL(newConnection()), this, SLOT(newConnection()));
}

void CommandServer::newConnection()
{
	while (mServer.hasPendingConnections())
	{
		QTcpSocket *socket = mServer.nextPendingConnection();
		const QCoreApplication *inst = QApplication::instance();
		const QString whoami = inst->applicationName() + " " + inst->applicationVersion();
		connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
		socket->write(("hello from " + whoami + "\n").toUtf8());
	}
}

void CommandServer::readyRead()
{
	QTcpSocket *socket = dynamic_cast<QTcpSocket*>(sender());
	if (socket == nullptr)
	{
		return;
	}

	while (socket->canReadLine())
	{
		const QString line = socket->readLine().trimmed();
		mParser.parse(line);
	}
}

