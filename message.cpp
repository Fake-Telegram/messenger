#include "message.h"

Message::Message(const string &_text,const bool &status) :text(_text), sendORrecv(status)
{
	time_t t = time(NULL);
	datetime = *localtime(&t);
	messageID = 1;//CreateMessageID ???
	//cout << asctime(&datetime) << " "<< text;
}
Message::Message(const Message &mes)
{
	sendORrecv = mes.sendORrecv;
	text = mes.text;
	datetime = mes.datetime;
	messageID = mes.messageID;
}
Message::~Message()
{
	cout << "Delete message";
}

string Message::get_text()
{
	return text;
}

bool Message::get_sendORrecv()
{
	return sendORrecv;
}
tm Message::get_datetime()
{
	return datetime;
}
bool Message::getMessage(ostream &s)
{
	s << messageID << " " << sendORrecv << " " << datetime.tm_mday << "/" << datetime.tm_mon + 1 << "/" << datetime.tm_year + 1900 << " "
		<< datetime.tm_hour << ":" << datetime.tm_min << ":" << datetime.tm_sec << " " << text << endl;
		//return false;

	return true;
}
