#include "Tokenizer.hpp"

void Tokenizer::tokenize(const QString &cmd) const
{
	QList<QString> token;

	int pos = 0;
	while (hasToken(cmd, pos))
	{
		token.append(nextToken(cmd, pos));
	}

	tokens(token);
}

bool Tokenizer::hasToken(const QString &cmd, int &pos) const
{
	for (; pos < cmd.length(); pos++)
	{
		if (cmd.at(pos) != ' ')
		{
			return true;
		}
	}

	return false;
}

QString Tokenizer::nextToken(const QString &cmd, int &pos) const
{
	const bool quoted = cmd.at(pos) == '"';
	const char endchar = quoted ? '"' : ' ';
	const int start = quoted ? pos+1 : pos;
	const int idx = cmd.indexOf(endchar, start);
	const int end = idx >= 0 ? idx : cmd.length();
	Q_ASSERT(end > start);
	pos = quoted ? end+1 : end;
	const int length = end-start;
	return cmd.mid(start, length);
}
