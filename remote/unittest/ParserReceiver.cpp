#include "ParserReceiver.hpp"

ParserReceiver::ParserReceiver(QObject *parent) : QObject(parent)
{

}

void ParserReceiver::nop()
{
	this->command = "nop";
}

void ParserReceiver::add(const std::string &type, const std::string &color, const std::array<int,3> &pos, int rotation)
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

