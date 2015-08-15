#ifndef CLIENTCONNECTOR_HPP
#define CLIENTCONNECTOR_HPP

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>

class ClientConnector : public QObject
{
		Q_OBJECT
	public:
		explicit ClientConnector(QObject *parent = 0);

		void start(quint16 port);

	signals:
		void started(QHostAddress address, quint16 port);
		void clientNumberChanged(uint clients);

	public slots:
		void send(QString msg);

	private slots:
		void newConnection();
		void removeConnection();

	private:
		QTcpServer		mServer;

		QList<QTcpSocket*>	mClients;

};

#endif // CLIENTCONNECTOR_HPP
