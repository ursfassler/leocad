#include "MainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationName("bloc server");

	MainWindow w;
	w.show();

	return a.exec();
}
