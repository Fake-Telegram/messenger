#ifndef MESSENGER_H
#define MESSENGER_H

#include "authorization.h"
#include "registration.h"
#include "mainwindow.h"
#include <QObject>

class messenger: public QObject
{
	Q_OBJECT
signals:
	void quit();

public slots:
	void slot_quit();

public:
	messenger();
	void init();
private:
	Authorization auth;
	Registration reg;
	MainWindow window;
	Client *client;
};

#endif // MESSENGER_H
