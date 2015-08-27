#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <QObject>
#include <QStringList>


class TokenizerTest;

class Tokenizer : public QObject
{
		Q_OBJECT
	signals:
		void tokens(const QStringList &list) const;

	public slots:
		void tokenize(QString cmd) const;

	private:

		friend TokenizerTest;
};

#endif // TOKENIZER_HPP
