//#pragma once
#ifndef CLIENT_H
#define CLIENT_H

#include <list>
#include "user.h"
#include "chat.h"

class Client :
	virtual public User//??????
{
private:
	string password;
	list<User> friends;
	list<Chat> room;
public:
	Client(string, string, string);
	~Client();
	inline bool add_friend(User);//inline --experiment???
	bool delete_friend(const User&);
	bool add_chat(const User&);
	bool open_chat(const Chat&);//??????
	bool close_chat(const Chat&);//??????
	bool delete_chat(const User&);
	bool change_password(string, string);
	bool autorization(string);
};
#endif // CLIENT_H
