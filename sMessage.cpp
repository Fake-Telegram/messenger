#include "stdafx.h"
#include "sMessage.h"


sMessage::sMessage(const tm &_datetime, const string &_userf, const string &_usert, const string &_text) : datetime(_datetime), text(_text), from_user(_userf), to_user(_usert)
{
	messageID = 1;//CreatesMessageID ???
}
sMessage::sMessage(const unsigned &_messageID, const tm &_datetime, const string &_userf, const string &_usert, const string &_text) : messageID(_messageID), datetime(_datetime), text(_text), from_user(_userf), to_user(_usert)
{}
sMessage::sMessage(const sMessage &mes)
{
	text = mes.text;
	datetime = mes.datetime;
	messageID = mes.messageID;
	from_user = mes.from_user;
	to_user = mes.to_user;
}
sMessage::~sMessage()
{
	cout << "Delete message";
}

string sMessage::get_text()
{
	return text;
}
string sMessage::get_userf()
{
	return from_user;
}
string sMessage::get_usert()
{
	return to_user;
}

tm sMessage::get_datetime()
{
	return datetime;
}
string sMessage::get_string_datetime()
{
	stringstream ss;
	ss << datetime.tm_mday << "/" << datetime.tm_mon + 1 << "/" << datetime.tm_year + 1900 << " "
		<< datetime.tm_hour << ":" << datetime.tm_min << ":" << datetime.tm_sec << endl;
	return  ss.str();
}
bool sMessage::getMessage(ostream &s)
{
	s << messageID << " " << from_user << " " << to_user << " " << datetime.tm_mday << "/" << datetime.tm_mon + 1 << "/" << datetime.tm_year + 1900 << " "
		<< datetime.tm_hour << ":" << datetime.tm_min << ":" << datetime.tm_sec << " " << text << endl;
	//return false;

	return true;
}
