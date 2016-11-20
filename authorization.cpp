#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Authorization)
{
	ui->setupUi(this);
}

Authorization::~Authorization()
{
	delete ui;
}

void Authorization::on_pushButton_clicked()
{
	exit(5);
}

void Authorization::on_pushButton_2_clicked()
{
	close();
}
