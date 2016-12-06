#include "registration.h"
#include "ui_registration.h"

Registration::Registration(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::Registration)
{
	ui->setupUi(this);
}

Registration::~Registration()
{
	delete ui;
}

void Registration::registration_status(const bool result){
	if(!result){
		ui->error->setStyleSheet("QLabel {color: red}");
		ui->error->setText("Неверный логин или пароль.");
	}
}



void Registration::on_double_password_textChanged(const QString &arg1)
{
	if(ui->password->text() != ui->double_password->text()){
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

		writer.Key("nickname");
		writer.Int(REGISTRATION);
		writer.Key("email");
		writer.String(ui->email->text().toStdString().c_str());
		writer.Key("password");
		writer.String(ui->password->text().toStdString().c_str());
		writer.EndObject();
		string json = buffer.GetString() + string("\0");
		cout << json << endl;
		net.send_message(json);
	}
}

void Registration::on_pushButton_2_clicked()
{
	close();
}
