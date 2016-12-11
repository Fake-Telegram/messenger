#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "network.h"
#include "settings.h"
#include <QDialog>

extern Network net;

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
	Q_OBJECT

signals:
	void close_registration();

public slots:
	void registration_status(const bool result);

public:
	explicit Registration(QWidget *parent = 0);
	~Registration();

private slots:
	void on_double_password_textChanged(const QString &arg1);

	void on_pushButton_clicked();

	void on_pushButton_2_clicked();

private:
	Ui::Registration *ui;
};

#endif // REGISTRATION_H
