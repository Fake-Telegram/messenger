#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>
#include <QString>
#include <QtGui>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QWidget>

class authorization : public QDialog
{
public:
    authorization(QWidget* pwgt = 0);
private:
    QLineEdit *_login;
    QLineEdit *_password;
};

#endif // AUTHORIZATION_H
