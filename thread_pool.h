#ifndef THREAD_POOL_H
#define THREAD_POOL_H
#include <string>
//#include <memory>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/enable_shared_from_this.hpp>
#include "thread_pool.h"


extern boost::mutex global_stream_lock;

class Thread_pool:
public boost::enable_shared_from_this<Thread_pool>
{
public:
    boost::shared_ptr<boost::asio::io_service> io_service;
    boost::thread_group thread_group;
    Thread_pool(boost::shared_ptr<boost::asio::io_service> initial_io_service);
    ~Thread_pool();
    void thread_start(void);
    void start(void);

};

#endif // THREAD_POOL_H
