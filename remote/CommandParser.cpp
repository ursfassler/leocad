#include "CommandParser.hpp"

void CommandParserOutput::emitError(QString msg)
{
	error(msg);
}

void CommandParserOutput::emitNop()
{
	nop();
}

void CommandParserOutput::emitHello(QString plate, QString color, QString serverName)
{
	hello(plate, color, serverName);
}

void CommandParserOutput::emitAdd(QString type, QString color, const std::array<int,3> &pos, int rotation)
{
	add(type, color, pos, rotation);
}

void CommandParserOutput::emitClear()
{
	clear();
}



CommandParser::CommandParser(CommandParserOutput &output) :
	mOutput(output)
{
}

CommandParser::~CommandParser()
{
}

CommandParserOutput &CommandParser::output() const
{
	return mOutput;
}

QPair<bool, int> CommandParser::parseInteger(QString value) const
{
	QPair<bool,int> result;

	result.second = value.toInt(&result.first);

	return result;
}



