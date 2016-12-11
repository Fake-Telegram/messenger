#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "message.h"
#include "chat.h"
#include "user.h"
#include "client.h"
#include "authorization.h"
#include "registration.h"
#include "addfriend.h"
#include "model_chats.h"
#include <QMainWindow>
#include <QTextEdit>
#include <QAction>
#include <ctime>

//#include "mylistwidget.h"
extern Client *client;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
//	explicit MainWindow(QWidget *parent = 0, const Client *client);
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

signals:
	void close_client();
	void quit_client();

public slots:
	void create_client(const string login, const string password, const unsigned ID);

private slots:
	void on_pushButton_clicked();

//	void on_listWidget_2_activated(const QModelIndex &index);

	void on_pushButton_2_clicked();

	void on_action_3_triggered();


	void on_quit_user_triggered();

	void on_chats_clicked(const QModelIndex &index);

private:
	//Client* client;
	Chat* active_chat;
	Authorization auth;
	Registration reg;
	Model_Chats *model;
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
