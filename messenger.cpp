#include "messenger.h"
#include <QObject>

messenger::messenger()
{
	QObject::connect(&reg, &Registration::close_registration, &auth, &Authorization::show);
	QObject::connect(&auth, &Authorization::open_registration, &reg, &Registration::show);
	QObject::connect(&auth, &Authorization::auth_user, &window, &MainWindow::create_client);
	QObject::connect(&window, &MainWindow::close_client, &auth, &Authorization::show);
	QObject::connect(&window, &MainWindow::quit_client, this, &messenger::slot_quit);
	QObject::connect(&auth, &Authorization::quit, this, &messenger::slot_quit);

}

void messenger::init(){
	auth.exec();
}

void messenger::slot_quit(){
	emit quit();
}
