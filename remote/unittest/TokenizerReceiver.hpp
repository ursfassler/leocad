#ifndef TOKENIZERRECEIVER_HPP
#define TOKENIZERRECEIVER_HPP

#include <QObject>
#include <QStringList>

class TokenizerReceiver : public QObject
{
		Q_OBJECT
	public:

	public slots:
		void tokens(QStringList list);

	public:
		QStringList token;

};

#endif // TOKENIZERRECEIVER_HPP
