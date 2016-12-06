#include "mainwindow.h"
#include "authorization.h"
#include "client.h"
#include "user.h"
#include "network.h"
#include <QObject>
#include <QApplication>
#include <thread_pool.h>

boost::mutex global_stream_lock;
boost::shared_ptr<boost::asio::io_service> io_service(
		new boost::asio::io_service
		);
Network net(io_service);


int main(int argc, char *argv[]){


	//	Client *client = nullptr;

	boost::shared_ptr<boost::asio::io_service::work> work(
				new boost::asio::io_service::work(*io_service)
				);
	Thread_pool thread_pool(io_service);
	thread_pool.start();
	net.get_message();
	QApplication a(argc, argv);
	Authorization aut;
	QObject::connect(&net, &Network::result_authorization, &aut, &Authorization::login_result);
	aut.exec();

	MainWindow w;
	//    io_service->dispatch(boost::bind(&MainWindow::show, &w));
	w.show();
	io_service->dispatch(boost::bind(&MainWindow::show, &w));
	return a.exec();
}
