#include "autorization.h"
#include "ui_autorization.h"

Autorization::Autorization(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Autorization)
{
	ui->setupUi(this);
}

Autorization::~Autorization()
{
	delete ui;
}
