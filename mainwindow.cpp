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
	Message new_mess(text.toStdString(), false);
	active_chat->send_message(new_mess);
	ui->lineEdit->clear();
	if(text.count(' ') == text.size()) return;
	text = QString::fromStdString(new_mess.get_string_datetime() + "\n") + text;
	ui->listWidget_2->addItem(text);

}




//void MainWindow::on_listWidget_2_activated(const QModelIndex &index)
//{

//}


void MainWindow::on_pushButton_2_clicked()
{
    AddFriend *pAddFriend = new AddFriend;
	pAddFriend->show();

}

void MainWindow::on_action_3_triggered()
{
	close();
}

void MainWindow::on_listWidget_2_activated(const QModelIndex &index)
{

}
