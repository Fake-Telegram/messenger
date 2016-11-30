#include "network.h"



Network:: Network(boost::shared_ptr<boost::asio::io_service> io_service)
    : socket(new boost::asio::ip::tcp::socket(*io_service))
    , resolver(*io_service)
    , query(
		  "185.146.171.72",
          boost::lexical_cast<std::string>(7000)
      )
{
    try {
      iterator = resolver.resolve(query);
        endpoint = *iterator;
        global_stream_lock.lock();
        std::cerr << "connecting to: " << endpoint << std::endl;
        global_stream_lock.unlock();
        socket->async_connect(endpoint, boost::bind(
            &Network::connect_handle, this,  _1)
        );
    } catch(std:: exception &ex) {
        global_stream_lock.lock();
        std::cerr  << "[" << boost::this_thread::get_id() <<
            "] Exception: " << ex.what() << std::endl;
        global_stream_lock.unlock();
    }
}    

Network:: ~Network()
{
    boost::system::error_code ec;
    socket->shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);
    socket->close(ec);
}

void
Network::connect_handle(
    const boost::system::error_code &ec
)
{
    if (ec) {
        global_stream_lock.lock();
        std::cerr << "[" << boost::this_thread::get_id() <<
            "] Error: " << ec << std::endl;
        global_stream_lock.unlock();
    } else {
        global_stream_lock.lock();
        std::cerr << "[" << boost::this_thread::get_id() <<
            "] Connected!" << std::endl;
        global_stream_lock.unlock();
    }
}

void Network::send_handler(
    const boost::system::error_code &ec,
    std::string &buffer)
{
    if (ec) {
        global_stream_lock.lock();
        std::cout << "[" << boost::this_thread::get_id() <<
        "] Error: " << ec << std::endl;
        global_stream_lock.unlock();
        //Close();
    } else {
        global_stream_lock.lock();
        std::cout << "[" <<boost::this_thread::get_id() <<
        "] Sent " << buffer.length() << "bytes." <<std::endl;
        global_stream_lock.unlock();
    }
    //buffer.erase(iterator);
/*    if (!m_send_buffer.empty()) {
        boost::asio::async_write(
            m_socket,
            boost::asio::buffer(m_send_buffer.front()),
            boost::bind(
                &Network::send_handler,
                this,
                boost::asio::placeholders::error,
                m_send_buffer.begin()
            )
        );
    }*/
}

void Network:: send_message(std::string buffer)
{
/*    int error_flag;
///!!!!  handler is needed
    error_flag = write(socket_fd, buffer, buf_len);*/
/*    if (error_flag == (-1)) {
        perror("write");
        exit(errno);
    } else if (error_flag == 0) {
        return (-1);
    }*/
	//buffer[0] = 0;
//    return error_flag;
    boost::asio::async_write(
        *socket,
        boost::asio::buffer(buffer, buffer.length()),
        boost::bind(
            &Network::send_handler,
            this,
            boost::asio::placeholders::error,
            buffer
        )
        //[this](){return;}
    );
}

/*int Network:: get_message(char *buffer, int buf_len)
{
    int error_flag;
    error_flag = read(socket_fd, buffer, buf_len);
    if (error_flag == -1) {
        perror("read");
        exit(errno);
    }
    buffer[error_flag] = 0;
    error_flag = fputs(buffer, stdout);
    if (error_flag == EOF) {
        return -1;
    }
    buffer[0] = 0;
    return 1;
}*/
