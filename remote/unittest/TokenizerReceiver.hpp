#ifndef TOKENIZERRECEIVER_HPP
#define TOKENIZERRECEIVER_HPP

#include <QObject>

class TokenizerReceiver : public QObject
{
		Q_OBJECT
	public:

	public slots:
		void tokens(const QList<QString> &list);

	public:
		QList<QString> token;

};

#endif // TOKENIZERRECEIVER_HPP
