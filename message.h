#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Message{
public:
    Message(string);
	Message() :text(""){};
    Message(const Message &other) = default;
	string get_text();
	tm get_datetime();
	bool getMessage(ostream &);
    ~Message();
private:
    unsigned messageID;
    string text;
    tm datetime;
};

#endif // MESSAGE_H
