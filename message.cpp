#include "message.h"

Message::Message(string _text):text(_text)
{
	time_t t = time(NULL);
	datetime = *localtime(&t);
	messageID = 1;//CreateMessageID ???
	//cout << asctime(&datetime) << " "<< text;
}
Message::~Message()
{
	cout << "Delete message";
}

string Message::get_text()
{
	return text;
}
tm Message::get_datetime()
{
	return datetime;
}
bool Message::getMessage(ostream &s)
{
	try
	{
		s << messageID << " " << datetime.tm_mday << "/" << datetime.tm_mon+1 << "/" << datetime.tm_year+1900<<" "
			<< datetime.tm_hour << ":" << datetime.tm_min << ":" << datetime.tm_sec<<" "<< text << endl;
	}
	catch (exception ex)
	{
		return false;
	}
	return true;
}
