#include "ParserReceiver.hpp"

ParserReceiver::ParserReceiver(QObject *parent) : QObject(parent)
{

}

void ParserReceiver::error(QString msg)
{
	this->command = "error";
	this->errorMsg = msg;
}

void ParserReceiver::nop()
{
	this->command = "nop";
}

void ParserReceiver::hello(QString plate, QString color, QString serverName)
{
	this->command = "hello";
	this->plate = plate;
	this->color = color;
	this->server = serverName;
}

void ParserReceiver::add(QString type, QString color, const std::array<int,3> &pos, int rotation)
{
	this->command = "add";
	this->type = type;
	this->color = color;
	this->x = pos[0];
	this->y = pos[1];
	this->z = pos[2];
	this->rotation = rotation;
}

void ParserReceiver::clear()
{
	this->command = "clear";
}

