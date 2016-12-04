//#pragma once
#ifndef CHAT_H
#define CHAT_H

#include <list>
#include "user.h"
#include "message.h"
#include "fstream"
#include "network.h"


extern Network net;

class Chat
{
private:
	User companion;
	unsigned int chatID;
	bool otr_status;
	list <Message> talk;
	//Criptographer my_otr;
public:
	Chat(const User &_companion, const unsigned int &_chatID);
	//Chat(const Chat &);
	~Chat();
	string get_companion_name();
	bool send_message(Message&);
	bool recv_message(const Message&);
	void change_otr_status();
	unsigned int get_chatID();
	list <Message> find_message(const string&);
	bool operator==(const Chat& right);
};

#endif // CHAT_H
