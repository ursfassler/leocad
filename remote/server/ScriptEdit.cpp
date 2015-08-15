#include "ScriptEdit.hpp"

#include <QVBoxLayout>

ScriptEdit::ScriptEdit(QWidget *parent) :
	QWidget(parent)
{
	mHistory.setReadOnly(true);

	connect(&mInput, SIGNAL(returnPressed()), this, SLOT(newInput()));

	QLayout *layout = new QVBoxLayout(this);
	layout->addWidget(&mHistory);
	layout->addWidget(&mInput);
	this->setLayout(layout);
}

void ScriptEdit::newInput()
{
	QLineEdit *input = dynamic_cast<QLineEdit*>(sender());
	if (input == nullptr)
	{
		return;
	}

	const QString line = input->text();
	input->clear();

	mHistory.append(line);
	command(line);
}

