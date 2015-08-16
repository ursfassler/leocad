#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP

#include <QObject>

class TokenizerTest;

class Tokenizer : public QObject
{
		Q_OBJECT
	signals:
		void tokens(const QList<QString> &list) const;

	public slots:
		void tokenize(const QString &cmd) const;

	private:
		bool hasToken(const QString &cmd, int &pos) const;
		QString nextToken(const QString &cmd, int &pos) const;

		friend TokenizerTest;
};

#endif // TOKENIZER_HPP
