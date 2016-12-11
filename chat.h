//#pragma once
#ifndef CHAT_H
#define CHAT_H

#include <list>
#include <cstdio>
#include "user.h"
#include "message.h"
#include "fstream"
#include "network.h"


extern Network net;

class Chat
{
private:
	User m_companion;
	unsigned int m_chatId;
	bool m_otr_status;
	list <Message> m_talk;
	//Criptographer my_otr;
public:
	Chat(const User &companion, const unsigned int &chatId);
	//Chat(const Chat &chat);
	~Chat();
	bool open();
	string get_companion_name();
	bool send_message(Message&);
	bool recv_message(const Message&);
	void change_otr_status();
	unsigned int get_chatId();
	list <Message> find_message(const string&);
	bool operator==(const Chat& right);
};

#endif // CHAT_H
