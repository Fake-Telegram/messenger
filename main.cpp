#include "mainwindow.h"
#include "authorization.h"
#include "client.h"
#include "user.h"
#include "client_model.h"
#include <QApplication>

int main(int argc, char *argv[]){

//	Network net();
//	Client *client = nullptr;
	QApplication a(argc, argv);
	//Authorization aut;
	//aut.exec();
    MainWindow w;
    w.show();

	return a.exec();
}
