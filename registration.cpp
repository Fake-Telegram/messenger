#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Registration)
{
	QObject::connect(&net, &Network::result_registration, this, &Registration::registration_status);
	ui->setupUi(this);
}

Registration::~Registration()
{
	delete ui;
}

void Registration::registration_status(const bool result){
	if(result){
		emit close_registration();
		close();
	}else{
		ui->error->setStyleSheet("QLabel {color: red}");
		ui->error->setText("Данный логин уже используется.");
	}
}



void Registration::on_double_password_textChanged(const QString &arg1)
{
	if(ui->password->text() != arg1){
		ui->error->setText("Не совпадат пароли.");
	}else{
		ui->error->clear();
	}
}

void Registration::on_pushButton_clicked()
{
	if(ui->password != ui->double_password){
		rapidjson::StringBuffer buffer;
		rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

		writer.StartObject();

		writer.Key("operation");
		writer.Int(REGISTRATION);
		writer.Key("login");
		writer.String(ui->email->text().toStdString().c_str());
		writer.Key("password");
		writer.String(ui->password->text().toStdString().c_str());
		writer.Key("name");
		writer.String(ui->nickname->text().toStdString().c_str());
		writer.EndObject();
		string json = buffer.GetString();
		cout << json << endl;
		net.send_message(json);
	}
}

void Registration::on_pushButton_2_clicked()
{
	hide();
	emit close_registration();
}
