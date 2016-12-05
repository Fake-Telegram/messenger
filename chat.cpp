#include "chat.h"



Chat::Chat(const User &companion, const unsigned int &chatId) :m_companion(companion), m_chatId(chatId), m_otr_status(false)
{}/*
  Chat::Chat(const Chat &chat)
  {
  m_companion=chat.m_companion;
  m_chatId=chat.chatId;
  m_otr_status=chat.m_otr_status;
  m_talk = chat.m_talk;
  }*/
Chat::~Chat()
{
	/*
	string filename = "";// companion.get_login();
	ofstream out;
	out.open(filename + "1.txt", ios::app);
	for (list<Message>::iterator i = talk.begin(); i != talk.end(); i++)
	(*i).getMessage(out);
	*/
	//m_talk.clear();
}
bool Chat::open()
{
	string filename = to_string(m_chatId);
	ifstream in;
	in.open(filename + ".txt");
	if (in.is_open())
	{
		while (!in.eof())
		{
			unsigned int localId;
			unsigned int Id;
			bool sendORrecv;
			tm datetime;
			string text;
			int tmp;

			in >> localId;
			in >> Id;
			in >> sendORrecv;
			in >> datetime.tm_mday; in.ignore();
			in >> tmp; datetime.tm_mon = tmp - 1; in.ignore();
			in >> tmp; datetime.tm_year = tmp - 1900; in.ignore();
			in >> datetime.tm_hour; in.ignore();
			in >> datetime.tm_min; in.ignore();
			in >> datetime.tm_sec;

			in >> text; //getline(in, text, "\n");???
			in.ignore();
			Message mes = Message(localId, Id, datetime, text, sendORrecv);
			m_talk.push_back(mes);
		}
	}
	in.close();
	return true;
}

bool Chat::send_message(Message& mes)
{
	//Network net;
	m_talk.push_back(mes);//send to server

	if (m_otr_status)
	{
		//criptographer;
	}
	else
	{

		string filename = to_string(m_chatId);
		ofstream out;
		out.open(filename + ".txt", ios::app);
		mes.getMessage(out);
		out.close();
	}

	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

	writer.StartObject();

	writer.Key("operation");
	writer.Int(MESSAGE);
	writer.Key("chatId");
	writer.Uint(m_chatId);
	writer.Key("localId");
	writer.Uint(mes.get_localId());
	writer.Key("otr");
	writer.Bool(m_otr_status);
	writer.Key("text");
	writer.String(mes.get_text().c_str());

	writer.EndObject();
	string json = buffer.GetString();
	//*/

	cout << json << endl;
	//	net.send_message(json.c_str(), json.length() + 1);
	string buf(json);
	//we need shared_ptr here
	net.send_message(buf);
	//send(json);
	return true;
}

bool Chat::recv_message(const Message &_mes)
{
	//rapidjson::Document doc;
	//doc.SetObject();

	//	doc.Parse(_mes.c_str());

	Message mes(_mes);
	//	cout << doc["datetime"].GetString();
	m_talk.push_back(mes);
	if (m_otr_status)//doc["otr"].GetBool();
	{
		//uncriptographer;
	}
	{
		string filename = to_string(m_chatId);
		ofstream out;
		out.open(filename + ".txt", ios::app);
		mes.getMessage(out);
		out.close();
	}
	//send to server that message received
	//cout << "Error send_message\n";
	//return false;


	return true;
}

void Chat::change_otr_status() { m_otr_status = !m_otr_status; }

list <Message> Chat::find_message(const string& message)
{
	list <Message> find_mes;
	for (list<Message>::iterator i = m_talk.begin(); i != m_talk.end(); i++)
	{
		string s = (*i).get_text();
		if (s.find(message) != string::npos)//change to _message in s
			find_mes.push_back(*i);// ???? 
	}
	return find_mes;
}
unsigned int Chat::get_chatId()
{
	return m_chatId;
}
bool Chat::operator==(const Chat& right)
{
	return m_chatId == right.m_chatId;
}

string Chat::get_companion_name(){
	return m_companion.get_name();
}
