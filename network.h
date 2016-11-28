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

extern boost::mutex global_stream_lock;

class Network {
public:
    boost::shared_ptr <boost::asio::ip::tcp::socket> socket;
    boost::asio::ip::tcp::resolver resolver;
    boost::asio::ip::tcp::resolver::query query;
    boost::asio::ip::tcp::resolver::iterator iterator;
    boost::asio::ip::tcp::endpoint endpoint;
    //int socket_fd;

    Network(boost::shared_ptr<boost::asio::io_service> io_service);
    ~Network();
    //	int send_message(const char *buffer, int buf_len);
    //    int get_message(char *buffer, int buf_len);
    void OnConnect(
        const boost::system::error_code &ec);
    void send_message(std::string buffer);
    void send_handler(
        const boost::system::error_code &ec,
        std::string &buffer);
};

#endif //NETWORK_H
