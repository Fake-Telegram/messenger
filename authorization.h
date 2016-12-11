#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "user.h"
#include "network.h"
#include "client.h"
#include "registration.h"
#include <string>
#include <QString>

extern Network net;

extern Client *client;

namespace Ui {
class Authorization;
}

class Authorization : public QDialog
{
	Q_OBJECT

public:
	explicit Authorization(QWidget *parent = 0);
	~Authorization();

signals:
	void auth_user(const string, const string,const unsigned);
	void open_registration();
	void quit();

public slots:
	void login_result(const bool result, const unsigned ID_User);
private slots:
	void on_Exit_clicked();

	void on_login_clicked();

	void on_registration_clicked();

private:
	Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
