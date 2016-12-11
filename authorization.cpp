#include "authorization.h"
#include "ui_authorization.h"

Authorization::Authorization(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Authorization)
{
	connect(&net, &Network::result_authorization, this, &Authorization::login_result);
	ui->setupUi(this);
}

Authorization::~Authorization()
{
	delete ui;
}

void Authorization::on_Exit_clicked()
{
	emit quit();
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
	//close();
}

void Authorization::login_result(const bool result, const unsigned ID_User){
	cout << "login result: " << result << "\nID: " << ID_User << endl;
	if(result){
		emit auth_user(ui->Login->text().toStdString(), ui->Password->text().toStdString(), ID_User);
		ui->Password->clear();
		hide();
		emit close();
	}else{
		ui->infomation->setStyleSheet("QLabel {color: red}");
		ui->infomation->setText("Неверный логин или пароль.");
		ui->Password->clear();
	}
}

void Authorization::on_registration_clicked()
{

	emit open_registration();
	hide();
}
