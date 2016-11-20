#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QWidget>

namespace Ui {
class AddFriend;
}

class AddFriend : public QWidget
{
	Q_OBJECT

public:
	explicit AddFriend(QWidget *parent = 0);
	~AddFriend();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_3_clicked();

private:
	Ui::AddFriend *ui;
};

#endif // ADDFRIEND_H
