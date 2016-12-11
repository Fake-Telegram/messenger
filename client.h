//#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <list>
#include "user.h"
#include "chat.h"

class Client : public User{
private:
	string m_login;
	string m_password;

public:
	list<User> friends;
	list<Chat> room;

	Client(const string& login, const string& password);
	Client(const unsigned &userId, const string &name, const string& login, const string& password);
	~Client();
	bool add_friend(const User&);
	bool delete_friend(const User&);
	bool find_chat(const unsigned int &chatId, Chat *chat);
	bool add_chat(const User&, const unsigned int &chatId);
	bool open_chat(const Chat&);//??????
	bool close_chat(const Chat&);//??????
	bool delete_chat(const User&, const unsigned int &chatId);
	bool change_password(const string&, const string&);
	bool authorization(const string&);
	bool add_message(const unsigned int chatId, const Message& mes);
	unsigned chats_count();
};
#endif // CLIENT_H
