//#pragma once
#ifndef CHAT_H
#define CHAT_H

#include <list>
#include "user.h"
#include "message.h"
#include "fstream"

class Chat
{
private:
	User companion;
	bool otr_status;
	list <Message> talk;
	//Criptographer my_otr;
public:
	Chat(const User&);
	~Chat();
	bool send_message(const string&);
	bool recv_message(const string&);
	void change_otr_status();
	list <Message> find_message(const string&);
	bool operator==(const Chat& right);
};

#endif // CHAT_H
