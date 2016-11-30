#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "message.h"
#include "chat.h"
#include "user.h"
#include "client.h"
#include <QMainWindow>
#include <QTextEdit>
#include <ctime>

//#include "mylistwidget.h"

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

private slots:
	void on_pushButton_clicked();

	void on_listWidget_2_activated(const QModelIndex &index);

	void on_pushButton_2_clicked();

	void on_action_3_triggered();

private:
	const Client* _client;
	Chat* active_chat;
	Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
