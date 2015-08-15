#ifndef SCRIPTEDIT_HPP
#define SCRIPTEDIT_HPP

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>

class ScriptEdit : public QWidget
{
		Q_OBJECT
	public:
		explicit ScriptEdit(QWidget *parent = 0);

	signals:
		void command(QString cmd);

	public slots:

	private slots:
		void newInput();

	private:
		QTextEdit	mHistory;
		QLineEdit	mInput;
};

#endif // SCRIPTEDIT_HPP
