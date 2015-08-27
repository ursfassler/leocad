#include "Tokenizer.hpp"

void Tokenizer::tokenize(QString cmd) const
{
	const QStringList token = cmd.split(' ', QString::SkipEmptyParts);
	tokens(token);
}
