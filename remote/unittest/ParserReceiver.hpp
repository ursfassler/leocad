#ifndef PARSERRECEIVER_HPP
#define PARSERRECEIVER_HPP

#include <QObject>

#include <string>
#include <array>

class ParserReceiver : public QObject
{
		Q_OBJECT
	public:
		explicit ParserReceiver(QObject *parent = 0);

		std::string command;
		std::string type;
		std::string color;
		int x;
		int y;
		int z;
		int rotation;

	signals:

	public slots:
		void add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation);

};

#endif // PARSERRECEIVER_HPP
