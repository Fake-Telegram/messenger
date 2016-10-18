//#pragma once
#ifndef CHAT_H
#define CHAT_H

#include <list>
#include "user.h"
#include "message.h"
#include "fstream"

class Chat :
	public Message
{
private:
	User companion;
	bool otr_status;
	list <Message> talk;
	//Criptographer my_otr;
public:
	Chat(User);
	~Chat();
	bool send_message(string);
	//Message recv_message(string);
	void change_otr_status();
	list <Message> find_message(string);
	friend bool operator==(const Chat& left, const Chat& right);
};

#endif // CHAT_H
