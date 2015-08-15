#ifndef COMMANDSERVER_HPP
#define COMMANDSERVER_HPP

#include "Parser.hpp"

#include <QObject>
#include <QTcpServer>


class CommandServer : public QObject
{
		Q_OBJECT
	public:
		explicit CommandServer(QObject *parent = 0);
		void initialize();

	signals:
		void add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation);
		void clear();

	public slots:

	private slots:
		void newConnection();
		void readyRead();

	private:
		const quint16 mPort;
		QTcpServer mServer;
		Parser mParser;

};

#endif // COMMANDSERVER_HPP
