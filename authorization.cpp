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

void Authorization::on_Exit_clicked()
{
	exit(5);
}

void Authorization::on_login_clicked()
{
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

	writer.StartObject();

	writer.Key("operation");
	writer.Int(AUTHORIZATION);
    writer.Key("login");
	writer.String(ui->Login->text().toStdString().c_str());
    writer.Key("password");
	writer.String(ui->Password->text().toStdString().c_str());
	writer.EndObject();
    string json = buffer.GetString() + string("\0");
	cout << json << endl;
    net.send_message(json);
	close();
}
