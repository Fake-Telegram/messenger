#include "chat.h"

Chat::Chat(User new_companion) :companion(new_companion), otr_status(false){}

Chat::~Chat()
{
	string filename = "";// companion.get_login();
	ofstream out;
	out.open(filename + ".txt", ios::app);
	for (list<Message>::iterator i = talk.begin(); i != talk.end(); i++)
		(*i).getMessage(cout);
	talk.clear();
}

bool Chat::send_message(string _mes)
{
	try
	{
		Message mes(_mes);
		talk.push_back(mes);//send to server
	}
	catch (exception ex)
	{
		cout << "Error send_message\n";
		return false;
	}
	return true;
}

void Chat::change_otr_status() { otr_status = !otr_status; }

list <Message> Chat::find_message(string _message)
{
	list <Message> find_mes;
	for (list<Message>::iterator i = talk.begin(); i != talk.end(); i++)
	{
		string s = (*i).get_text();
		if (_message ==s)//change to _message in s
			find_mes.push_back(*i);// ???? проверить будет ли удаляться элемент из talk при удалении find_mes 
	}
	return find_mes;
}

bool operator==(const Chat& left, const Chat& right)
{
	return left.companion == right.companion;
}