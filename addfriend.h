#ifndef ADDFRIEND_H
#define ADDFRIEND_H

#include <QDialog>
#include <QString>
#include <QtGui>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class AddFriend : public QDialog{
    Q_OBJECT
public:
    AddFriend(QWidget* pwgt = 0);
    QString getLogin();
private:
    QLineEdit *_login;
    bool _stat = false;
};

#endif // ADDFRIEND_H
