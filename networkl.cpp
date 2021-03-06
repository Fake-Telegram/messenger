#include "network.h"

tm get_date_time(const string &datetime0);

Network:: Network(boost::shared_ptr<boost::asio::io_service> io_service)
	: socket(new boost::asio::ip::tcp::socket(*io_service))
	, resolver(*io_service)
	, query(
          "185.146.171.72",
          //"127.0.0.1",
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
		//QObject::connect(this, &Network::result_authorization, this, &Network::sign);
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
		std::string &buffer,
		std::size_t num_sent)
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
					 "] Sent " << num_sent << "bytes." <<std::endl;
		global_stream_lock.unlock();
		buffer.erase(num_sent);
		if (buffer.empty()) {
			socket->async_write_some(
						boost::asio::buffer(buffer),
						boost::bind(
							&Network::send_handler,
							this,
							boost::asio::placeholders::error,
							buffer,
							boost::asio::placeholders::bytes_transferred()
							)
						);
		}
	}
}

void Network:: send_message(std::string &buffer)
{
	socket->async_write_some(
				boost::asio::buffer(buffer),
				boost::bind(
					&Network::send_handler,
					this,
					boost::asio::placeholders::error,
					buffer,
					boost::asio::placeholders::bytes_transferred()
					)
				);
}

void Network::get_message()
{
	socket->async_read_some(
				boost::asio::buffer(recv_buffer, BUF_SIZE),
				boost::bind(
					&Network::get_handler,
					this,
					boost::asio::placeholders::error,
					boost::asio::placeholders::bytes_transferred()
					)
				);

}

void Network::get_handler(
		const boost::system::error_code &ec,
		std::size_t num_got
		)
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
					 "] Receive " << num_got << "bytes.\n" <<
					 std::string(recv_buffer, num_got) << std::endl;
		global_stream_lock.unlock();
		std::cerr << "@" << std::string(recv_buffer, num_got) << "@" << std::endl;
		get_signal(std::string(recv_buffer, num_got));
		//receive_string = receive_string + std::string(recv_buffer, num_got);
		//recv_buffer.erase();
		/*socket->async_read_some(
			boost::asio::buffer(recv_buffer),
			boost::bind(
				&Network::send_handler,
				this,
				boost::asio::placeholders::error,
				boost::asio::placeholders::bytes_transferred()
			)
		);*/
		get_message();
	}
}


void Network::get_signal(const string &json){
	unsigned ID_operation;
	rapidjson::Document doc;
	doc.SetObject();
	if(!doc.Parse(json.c_str()).HasParseError()){
		ID_operation = doc["operation"].GetInt();
		switch (ID_operation) {
		case AUTHORIZATION:
			//cout << "AUTHORIZATION\n";
			if(doc["result"].GetBool()){
				emit result_authorization(doc["result"].GetBool(), doc["id"].GetUint());
			}else{
				emit result_authorization(doc["result"].GetBool(), 0);
			}
			break;
		case MESSAGE:
			emit recv_mess(doc["chatId"].GetUint(), Message(0, doc["messID"].GetUint(),
					get_date_time(doc["datetime"].GetString()), doc["text"].GetString(), false));
			break;
		case REGISTRATION:
			emit result_registration(doc["result"].GetBool());
		}
	}
}

tm get_date_time(const string &datetime0){
	stringstream in;
	tm datetime;
	int tmp;
	in << datetime0;
	in >> datetime.tm_mday; in.ignore();
	in >> tmp; datetime.tm_mon = tmp - 1; in.ignore();
	in >> tmp; datetime.tm_year = tmp - 1900; in.ignore();
	in >> datetime.tm_hour; in.ignore();
	in >> datetime.tm_min; in.ignore();
	in >> datetime.tm_sec;
	return datetime;
}


