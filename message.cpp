#include "message.h"
//helper.cpp----------------------
tm convertStringToTm(const string &datetime0){
	istringstream in(datetime0);
	tm datetime;
	int tmp;
	in >> datetime.tm_mday; in.ignore();
	in >> tmp; datetime.tm_mon = tmp - 1; in.ignore();
	in >> tmp; datetime.tm_year = tmp - 1900; in.ignore();
	in >> datetime.tm_hour; in.ignore();
	in >> datetime.tm_min; in.ignore();
	in >> datetime.tm_sec;
	return datetime;
}
string convertTmToString(const tm &datetime){
	ostringstream oss;
	oss << datetime.tm_mday << "/" << datetime.tm_mon + 1 << "/" << datetime.tm_year + 1900 << " "
		<< datetime.tm_hour << ":" << datetime.tm_min << ":" << datetime.tm_sec;
	return oss.str();
}
//---------------------

Message::Message(const string &text, const bool &sendORrecv) : m_text(text), m_sendORrecv(sendORrecv)
{
	time_t t = time(NULL);
	m_datetime = *localtime(&t);
	m_Id = 1;
	m_localId = 1;//CreateMessageId ???
	//cout << asctime(&datetime) << " "<< text;
}
Message::Message(
	const tm &datetime,
	const string &text,
	const bool &sendORrecv
	)
	: m_text(text)
	, m_sendORrecv(sendORrecv)
	, m_datetime(datetime)
{
	m_Id = 1;
	m_localId = 1;//CreateMessageId ???
}
Message::Message(
	const unsigned int &localId,
	const unsigned int &Id,
	const tm &datetime,
	const string &text,
	const bool &sendORrecv
	)
	: m_localId(localId)
	, m_Id(Id)
	, m_text(text)
	, m_sendORrecv(sendORrecv)
	, m_datetime(datetime)
{}
Message::Message(
	const unsigned int &localId,
	const unsigned int &Id,
	const string &datetime,
	const string &text,
	const bool &sendORrecv
	)
	: m_localId(localId)
	, m_Id(Id)
	, m_text(text)
	, m_sendORrecv(sendORrecv)
	, m_datetime(convertStringToTm(datetime))
{}
Message::Message()
{
	m_text = "";
	m_sendORrecv = false;
	time_t t = time(NULL);
	m_datetime = *localtime(&t);
	m_Id = 1;
	m_localId = 1;//CreateMessageID ???
}
Message::Message(const Message &mes)
{
	m_sendORrecv = mes.m_sendORrecv;
	m_text = mes.m_text;
	m_datetime = mes.m_datetime;
	m_Id = mes.m_Id;
	m_localId = mes.m_localId;
}
Message::~Message()
{
	//cout << "Delete message";
}

unsigned int Message::get_localId()
{
	return m_localId;
}
string Message::get_text()
{
	return m_text;
}

bool Message::get_sendORrecv()
{
	return m_sendORrecv;
}
tm Message::get_datetime()
{
	return m_datetime;
}
string Message::get_string_datetime()
{
	return convertTmToString(m_datetime);
}
bool Message::getMessage(ostream &s)
{
	s << m_localId << " " << m_Id << " " << m_sendORrecv << " " << convertTmToString(m_datetime) << " " << m_text << endl;
	//s << messageID << " " << sendORrecv << " " << datetime.tm_mday << "/" << datetime.tm_mon + 1 << "/" << datetime.tm_year + 1900 << " "
	//	<< datetime.tm_hour << ":" << datetime.tm_min << ":" << datetime.tm_sec << " " << text << endl;
	//return false;

	return true;
}
