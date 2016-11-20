#include "chat.h"

Chat::Chat(const User &_companion,const unsigned int &_chatID) :companion(_companion), chatID(_chatID), otr_status(false)
{
	string filename = to_string(_chatID);
	ifstream in;
	in.open(filename + ".txt"); 
	if (in.is_open())
	{
		while (!in.eof())
		{
			unsigned messageID;
			bool sendORrecv;
			tm datetime;
			string text;
			int tmp;

			in >> messageID;
			in >> sendORrecv;
			in >> datetime.tm_mday; in.ignore();
			in >> tmp; datetime.tm_mon = tmp - 1; in.ignore();
			in >> tmp; datetime.tm_year = tmp - 1900; in.ignore();
			in >> datetime.tm_hour; in.ignore();
			in >> datetime.tm_min; in.ignore();
			in >> datetime.tm_sec;

			in >> text; //getline(in, text, "\n");???
			in.ignore();
			Message mes = Message(messageID,datetime,text,sendORrecv);
			talk.push_back(mes);
		}
	}
	in.close();
	
}/*
Chat::Chat(const Chat &_Chat)
{
	companion=_Chat.companion;
	chatID=_Chat.chatID;
	otr_status=_Chat.otr_status;
	talk = _Chat.talk;
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
	//talk.clear();
}

bool Chat::send_message(Message& _mes)
{
	Network net;
	talk.push_back(_mes);//send to server

	if (otr_status)
	{
		//criptographer;
	}
	else
	{

		string filename = to_string(chatID);
		ofstream out;
		out.open("1.txt", ios::app);
		_mes.getMessage(out);
		out.close();
	}
	/*1
	rapidjson::Document doc;
	doc.SetObject();

	rapidjson::Value val("operation");
	doc.AddMember(val, MESSAGE, doc.GetAllocator());
	doc.AddMember("text", mes, doc.GetAllocator());
	//doc.AddMember("asd","das",document.GetAllocator());
	
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);
	string json = buffer.GetString();
	*/
	//or
	
	//*2
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

	writer.StartObject();
	
	writer.Key("operation");
	writer.Int(MESSAGE);
	writer.Key("chatID");
	writer.Uint(chatID);
	//writer.Key("toUser");
	//writer.Uint(companion.get_userID());
	writer.Key("otr");
	writer.Bool(otr_status);
	writer.Key("datetime");
	writer.String(_mes.get_string_datetime().c_str());
	writer.Key("text");
	writer.String(_mes.get_text().c_str());

	writer.EndObject();
	string json = buffer.GetString();
	//*/

	cout << json << endl;
	net.send_message(json.c_str(), json.length() + 1);
	//send(json);
	//recv_message(json);
	return true;
}

bool Chat::recv_message(const string& _mes)
{
	rapidjson::Document doc;
	//doc.SetObject();

	doc.Parse(_mes.c_str());

	Message mes(doc["text"].GetString(), true);
	cout << doc["datetime"].GetString();
	talk.push_back(mes);
	if (otr_status)//doc["otr"].GetBool();
	{
		//uncriptographer;
	}
	{
		string filename = to_string(chatID);
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

void Chat::change_otr_status() { otr_status = !otr_status; }

list <Message> Chat::find_message(const string& _message)
{
    list <Message> find_mes;
	for (list<Message>::iterator i = talk.begin(); i != talk.end(); i++)
	{
        string s = (*i).get_text();
        if (s.find(_message) != string::npos)//change to _message in s
			find_mes.push_back(*i);// ???? ��������� ����� �� ��������� ������� �� talk ��� �������� find_mes 
	}
	return find_mes;
}
unsigned int Chat::get_chatID()
{
	return chatID;
}
bool Chat::operator==(const Chat& right)
{
	return chatID == right.chatID;
}
