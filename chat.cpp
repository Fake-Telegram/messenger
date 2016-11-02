#include "chat.h"

Chat::Chat(const User &new_companion) :companion(new_companion), otr_status(false){}

Chat::~Chat()
{
	string filename = "";// companion.get_login();
	ofstream out;
	out.open(filename + "1.txt", ios::app);
	for (list<Message>::iterator i = talk.begin(); i != talk.end(); i++)
		(*i).getMessage(cout);
	talk.clear();
}

bool Chat::send_message(const string& _mes)
{
	Message mes(_mes,false);
	talk.push_back(mes);//send to server
	
	//cout << "Error send_message\n";
	//return false;

	return true;
}

bool Chat::recv_message(const string& _mes)
{
	Message mes(_mes, true);
	talk.push_back(mes);
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
