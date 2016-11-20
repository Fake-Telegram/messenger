#ifndef AUTORIZATION_H
#define AUTORIZATION_H

#include <QWidget>

namespace Ui {
class Autorization;
}

class Autorization : public QWidget
{
	Q_OBJECT

public:
	explicit Autorization(QWidget *parent = 0);
	~Autorization();

private:
	Ui::Autorization *ui;
};

#endif // AUTORIZATION_H
