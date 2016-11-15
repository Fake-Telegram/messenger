#include "chat.h"
Chat::Chat(const User &new_companion) :companion(new_companion), otr_status(false)
{
	string filename = companion.get_login();
	ifstream in;
	in.open(filename + ".txt");
	system("pause");
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
			in >> datetime.tm_mday;
			in >> tmp; datetime.tm_mon = tmp - 1;
			in >> tmp; datetime.tm_year = tmp - 1900;
			in >> datetime.tm_hour;
			in >> datetime.tm_min;
			in >> datetime.tm_sec;

			in >> text; //getline(in, text, "\n");???

			Message mes = Message(messageID,datetime,text,sendORrecv);
			talk.push_back(mes);
		}
	}
	in.close();
	system("pause");
}

Chat::~Chat()
{
	/*
	string filename = "";// companion.get_login();
	ofstream out;
	out.open(filename + "1.txt", ios::app);
	for (list<Message>::iterator i = talk.begin(); i != talk.end(); i++)
		(*i).getMessage(out);
		*/
	talk.clear();
}

bool Chat::send_message(const string& _mes)
{
	Message mes(_mes,false);
	talk.push_back(mes);//send to server

	if (otr_status)
	{
		//criptographer;
	}
	else
	{

		string filename = companion.get_login();
		ofstream out;
		out.open(filename + ".txt", ios::app);
		mes.getMessage(out);
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
	writer.Key("toUser");
	writer.String(companion.get_login().c_str());
	writer.Key("otr");
	writer.Bool(otr_status);
	writer.Key("datetime");
	writer.String(mes.get_string_datetime().c_str());
	writer.Key("text");
	writer.String(mes.get_text().c_str());

	writer.EndObject();
	string json = buffer.GetString();
	//*/
	
	cout << json << endl;
	//send(json);
	system("pause");
	recv_message(json);
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
		string filename = companion.get_login();
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
			find_mes.push_back(*i);// ???? проверить будет ли удаляться элемент из talk при удалении find_mes 
	}
	return find_mes;
}

bool Chat::operator==(const Chat& right)
{
	return companion == right.companion;
}
