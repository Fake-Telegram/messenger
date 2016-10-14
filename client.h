#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <list>
#include "user.h"

class Client: public User{
public:
    Client();
    Client(const Client &other);
    ~Client();
private:
    string password;
    list<User> friends;
};

#endif // CLIENT_H
