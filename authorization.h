#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>
#include <string>

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
	Q_OBJECT

public:
	explicit Authorization(QWidget *parent = 0);
	~Authorization();

private slots:
	void on_pushButton_clicked();

private:
	bool authorization(const string &login, const string & password);
	Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
