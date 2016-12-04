#include <thread_pool.h>

void
Thread_pool::thread_start(void)
{
    global_stream_lock.lock();
    std::cerr << "[" << boost::this_thread::get_id() <<
        "] Thread Start\n";
    global_stream_lock.unlock();
    while (true) {
        try {
            boost::system::error_code ec;

            io_service->run(ec);
            if (ec) {
                global_stream_lock.lock();
                std::cerr << "[" << boost::this_thread::get_id() <<
                    "] Error: " << ec  << std::endl;
                global_stream_lock.unlock();
            }
            break;
        } catch (std::exception &ex) {
            global_stream_lock.lock();
            std::cerr << "[" << boost::this_thread::get_id() <<
                "] Exception: " << ex.what() << std::endl;
            global_stream_lock.unlock();
        }
    }
    global_stream_lock.lock();
    std::cerr << "[" << boost::this_thread::get_id() <<
        "] Thread Finish\n";
    global_stream_lock.unlock();
}

Thread_pool::Thread_pool(boost::shared_ptr<boost::asio::io_service> initial_io_service)
{
    io_service = initial_io_service;
}

void Thread_pool::start(void) {
    for (int i = 0;i < 2; i++) {
        thread_group.create_thread(boost::bind(
            &Thread_pool::thread_start,
            this
        ));
    }
}

Thread_pool::~Thread_pool() {
    io_service->stop();
    thread_group.join_all();
}


