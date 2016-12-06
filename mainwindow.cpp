#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addfriend.h"
#include "authorization.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
	ui->setupUi(this);
//	_client = client;
	active_chat = new Chat(User(0, "Name"), 12);
//	Chat comp;
//	foreach (comp, _client->room) {
//		ui->listWidget->addItem(comp.get_companion_name());
//	}


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
	QString text = ui->textEdit->toPlainText();
	Message new_mess(text.toStdString(), false);
	ui->textEdit->clear();
	if((text.count(' ') == text.size()) || (text.size() == 0)) return ;
	else{
		active_chat->send_message(new_mess);
		text = QString::fromStdString(new_mess.get_string_datetime() + "\n") + text + "\n";
		ui->messeg->addItem(text);
	}
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
