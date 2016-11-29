#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "user.h"
#include "network.h"
#include <string>
#include <QString>

extern Network net;

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
	Q_OBJECT

public:
	explicit Authorization(QWidget *parent = 0);
	~Authorization();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

	void on_Login_clicked();

	void on_login_clicked();

private:
	Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
