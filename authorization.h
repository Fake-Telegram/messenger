#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
	Q_OBJECT

public:
	explicit Autorization(QWidget *parent = 0);
	~Autorization();

private:
	Ui::Authorization *ui;
};

#endif // AUTHORIZATION_H
