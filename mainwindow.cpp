#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addfriend.h"
#include "authorization.h"
#include "registration.h"


MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent), auth(), reg(),
    ui(new Ui::MainWindow)
{
	//QObject::connect(ui->quit_user, &QAction::triggered, &aut, &Authorization::exec());
	ui->setupUi(this);
//	_client = client;

	model = new Model_Chats();
	ui->chats->setModel(model);
	ui->chats->setSelectionMode(QAbstractItemView::SingleSelection);
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
	emit quit_client();
}

void MainWindow::create_client(const string login, const string password, const unsigned ID){
	client = new Client(ID, login, login, password);
	active_chat = &(*(client->room.begin()));
	show();
}

void MainWindow::on_quit_user_triggered()
{
	delete client;
	active_chat = nullptr;
	emit close_client();
	hide();
}

void MainWindow::on_chats_clicked(const QModelIndex &index)
{

}
