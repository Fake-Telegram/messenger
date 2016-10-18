#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addfriend.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);
    //ui->listWidget_2->setContextMenuPolicy(Qt::CustomContextMenu);
    //connect(listWidget_2, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(ShowContextMenu(const QPoint&)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	QString text = ui->lineEdit->text();
	ui->lineEdit->clear();
	if(text.count(' ') == text.size()) return;
	ui->listWidget_2->addItem(text);
}




void MainWindow::on_listWidget_2_activated(const QModelIndex &index)
{

}


void MainWindow::on_pushButton_2_clicked()
{
    AddFriend *pAddFriend = new AddFriend;
    if(pAddFriend->exec() == QDialog::Accepted){

    }

}
