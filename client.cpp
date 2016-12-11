#include "client.h"

Client::Client(const string& login, const string& password) : m_login(login), m_password(password)
{
	cout << "newClient0";
}
Client::Client(const unsigned &userId, const string &name, const string& login, const string& password) : User(userId, name), m_login(login), m_password(password)
{
	Chat chat(User(1, "123"), 1);
	room.push_back(chat);
	Chat chat_2(User(10, "rembo@mail.ru"), 3);
	room.push_back(chat_2);
	cout << "room.size = " << room.size() << endl;
	cout << "newUser\n";
}
Client::~Client()
{
	cout << "Delete Client";
}
bool Client::add_friend(const User &newUser)
{
	friends.push_back(newUser);
	//return false;

	return true;
}
bool Client::delete_friend(const User &oldUser)
{
	friends.remove(oldUser);
	//return false;
	return true;
}
bool Client::find_chat(const unsigned int &chatId, Chat *chat)
{
	for (list<Chat>::iterator i = room.begin(); i != room.end(); i++)
	{
		if (chatId == (*i).get_chatId())//change to _message in s
			chat = &(*i);// ????
		return true;
	}
	//send_to_server WHAT THE FUCK

	return false;
}
bool Client::add_chat(const User &newUser, const unsigned int &chatId)
{
	room.push_back(Chat(newUser, chatId));
	//	cout << "Error add_chat";
	//	return false;
	return true;
}
bool Client::open_chat(const Chat&){ return true; }//??????
bool Client::close_chat(const Chat&){ return true; }//??????
bool Client::delete_chat(const User &oldUser, const unsigned int &chatId)
{
	room.remove(Chat(oldUser, chatId));
	//	cout << "Error delete_chat";
	//	return false;
	return true;
}
bool Client::change_password(const string& curr_pas, const string& new_pas)
{
	if (m_password != curr_pas) return false;
	m_password = new_pas;	//send to server???
	return true;
}
bool Client::authorization(const string&){ cout << "df"; return true; }//?????????????????????????

bool Client::add_message(const unsigned chatId, const Message &mes){
	Chat *temp;
	if (find_chat(chatId, temp)){
		temp->recv_message(mes);
		return true;
	}
	return false;
}

unsigned Client::chats_count(){
	return room.size();
}
