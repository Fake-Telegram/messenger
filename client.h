//#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <list>
#include "user.h"
#include "chat.h"

class Client : public User{
private:
	string login;
	string password;
	
public:
	list<User> friends;
	list<Chat> room;

	Client(const unsigned &_userID, const string &_name, const string& _login, const string& _password);
	~Client();
    bool add_friend(const User&);
	bool delete_friend(const User&);
	bool add_chat(const User&, unsigned int &chatID);
	bool open_chat(const Chat&);//??????
	bool close_chat(const Chat&);//??????
	bool delete_chat(const User&, unsigned int &chatID);
    bool change_password(const string&, const string&);
    bool autorization(const string&);
};
#endif // CLIENT_H
