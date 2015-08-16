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

		std::string errorMsg;

		std::string sub;
		std::string whom;

		std::string command;
		std::string type;
		std::string color;
		int x;
		int y;
		int z;
		int rotation;

	signals:

	public slots:
		void error(const std::string &msg);
		void nop();
		void hello(const std::string &sub, const std::string &whom);
		void add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation);
		void clear();

};

#endif // PARSERRECEIVER_HPP
