#ifndef NETWORK_H
#define NETWORK_H
/*#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#define MAX_BUF 1024*/
#include <string>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/lexical_cast.hpp>
#include <QObject>
#include <message.h>
#define BUF_SIZE 2048

extern boost::mutex global_stream_lock;

class Network : public QObject{
	Q_OBJECT

signals:
	void recv_mess(const unsigned ID_chat, const Message& mess);
public:
    boost::shared_ptr <boost::asio::ip::tcp::socket> socket;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::resolver::query query;
    boost::asio::ip::tcp::resolver::iterator iterator;
    boost::asio::ip::tcp::endpoint endpoint;
    char recv_buffer[BUF_SIZE];
    std::string receive_string;
    //int socket_fd;

    Network(boost::shared_ptr<boost::asio::io_service> io_service);
	~Network();

    void connect_handle(
        const boost::system::error_code &ec);
    void send_message(std::string &buffer);
    void get_message();
    void send_handler(
        const boost::system::error_code &ec,
        std::string &buffer,
        std::size_t num_sent);
    void get_handler(
        const boost::system::error_code &ec,
        std::size_t num_got);
};

#endif //NETWORK_H
