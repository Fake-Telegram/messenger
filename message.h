#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Message{
private:
	unsigned messageID;
	string text;
	bool sendORrecv;//true-send, false - recv
	tm datetime;
public:
    Message(const string&,const bool&);
	//Message() :text(" "){};
    Message(const Message &other);
	string get_text();
	bool get_sendORrecv();
	tm get_datetime();
	bool getMessage(ostream &);
    ~Message();
};

#endif // MESSAGE_H
