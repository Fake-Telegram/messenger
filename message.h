#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

class Message{
private:
	unsigned int m_localId;
	unsigned int m_Id;
	string m_text;
	bool m_sendORrecv;//true-send, false - recv
	tm m_datetime;
public:
	Message(const string &text, const bool &sendORrecv);
	Message(const tm &datetime, const string &text, const bool &sendORrecv);
	Message(const unsigned int &localId, const unsigned int &Id, const tm &datetime, const string &text, const bool &sendORrecv);
	Message(const unsigned int &localId, const unsigned int &Id, const string &datetime, const string &text, const bool &sendORrecv);
	Message();
	//Message() :text(""){};
	Message(const Message &other);
	bool set_id_time(const unsigned int &Id, const tm &datetime);
	unsigned int get_localId();
	string get_text();
	bool get_sendORrecv();
	tm get_datetime();
	string get_string_datetime();
	bool getMessage(ostream &);
	~Message();
};

#endif // MESSAGE_H
