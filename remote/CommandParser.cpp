#include "CommandParser.hpp"

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

