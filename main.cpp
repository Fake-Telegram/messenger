#include "mainwindow.h"
#include "user.h"
#include "client_model.h"
#include <QApplication>

int main(int argc, char *argv[]){
	Network net();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
