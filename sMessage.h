#ifndef SMESSAGE_H
#define SMESSAGE_H

#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class sMessage{
private:
	unsigned messageID;
	string text;
	string from_user;
	string to_user;
	tm datetime;
public:
	sMessage(const tm &_datetime, const string &_userf, const string &_usert, const string &_text);
	sMessage(const unsigned &_messageID, const tm &_datetime, const string &_userf, const string &_usert, const string &_text);
	sMessage(const sMessage &other);
	string get_text();
	string get_userf();
	string get_usert();
	tm get_datetime();
	string get_string_datetime();
	bool getMessage(ostream &);
	~sMessage();
};

#endif // SMESSAGE_H
