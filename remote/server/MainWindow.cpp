#include "MainWindow.hpp"

#include "ScriptEdit.hpp"

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	mServerInfo = new QLabel("not started");
	statusBar()->addWidget(mServerInfo);
	mNumberOfClient = new QLabel();
	statusBar()->addWidget(mNumberOfClient);

	connect(&mClientConnector, SIGNAL(started(QHostAddress,quint16)), this, SLOT(serverStarted(QHostAddress,quint16)));
	connect(&mClientConnector, SIGNAL(clientNumberChanged(uint)), this, SLOT(clientNumberChanged(uint)));

	ScriptEdit	*scriptEdit = new ScriptEdit();
	setCentralWidget(scriptEdit);

	connect(scriptEdit, SIGNAL(command(QString)), &mClientConnector, SLOT(send(QString)));

	mClientConnector.start(29994);
}

MainWindow::~MainWindow()
{
}

void MainWindow::serverStarted(QHostAddress address, quint16 port)
{
	mServerInfo->setText(address.toString() + ":" + QString::number(port));
}

void MainWindow::clientNumberChanged(uint clients)
{
	mNumberOfClient->setText(QString("clients: %1").arg(clients));
}
