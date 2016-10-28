//#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <list>
#include "user.h"
#include "chat.h"

class Client : public User{
private:
	string password;
	list<User> friends;
	list<Chat> room;
public:
    Client(const string&, const string&, const string&);
	~Client();
    bool add_friend(const User&);
	bool delete_friend(const User&);
	bool add_chat(const User&);
	bool open_chat(const Chat&);//??????
	bool close_chat(const Chat&);//??????
	bool delete_chat(const User&);
    bool change_password(const string&, const string&);
    bool autorization(const string&);
};
#endif // CLIENT_H
