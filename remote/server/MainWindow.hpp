#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "ClientConnector.hpp"

#include <QMainWindow>
#include <QLabel>

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:
		MainWindow(QWidget *parent = 0);
		~MainWindow();

	private slots:
		void serverStarted(QHostAddress address, quint16 port);
		void clientNumberChanged(uint clients);

	private:
		ClientConnector	mClientConnector;
		QLabel		*mServerInfo;
		QLabel		*mNumberOfClient;
};

#endif // MAINWINDOW_HPP
