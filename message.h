#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

class Message{
private:
	unsigned int messageID;
	string text;
	bool sendORrecv;//true-send, false - recv
	tm datetime;
public:
    Message(const string &_text,const bool &status);
	Message(const tm &_datetime, const string &_text, const bool &status);
	Message(const unsigned int &_messageID, const tm &_datetime, const string &_text, const bool &status);
	Message();
	//Message() :text(""){};
    Message(const Message &other);
	string get_text();
	bool get_sendORrecv();
	tm get_datetime();
	string get_string_datetime();
	bool getMessage(ostream &);
    ~Message();
};

#endif // MESSAGE_H
