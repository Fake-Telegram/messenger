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

void Authorization::on_Login_clicked()
{
	close();
}

void Authorization::on_login_clicked()
{
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

	writer.StartObject();

	writer.Key("operation");
	writer.Int(AUTHORIZATION);
	writer.Key("Login");
	writer.String(ui->Login->text().toStdString().c_str());
	writer.Key("Password");
	writer.String(ui->Password->text().toStdString().c_str());
	writer.EndObject();
    string json = string("5") + buffer.GetString() + string("\0");
	cout << json << endl;
    net.send_message(json);
	close();
}
