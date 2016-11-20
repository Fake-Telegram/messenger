<<<<<<< HEAD
#include "client.h"

Client::Client(const string &_name,const string& _login, const string& _password) : User(_name, _login), password(_password){ cout << "newUser"; }
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

bool Client::add_chat(const User &newUser)
{
	room.push_back(Chat(newUser));
	//	cout << "Error add_chat";
	//	return false;
	return true;
}
bool Client::open_chat(const Chat&){ return true; }//??????
bool Client::close_chat(const Chat&){ return true; }//??????
bool Client::delete_chat(const User &oldUser)
{
	room.remove(Chat(oldUser));
	//	cout << "Error delete_chat";
	//	return false;
	return true;
}
bool Client::change_password(const string& curr_pas,const string& new_pas)
{
	if (password != curr_pas) return false;
	password = new_pas;	//send to server???
	return true;
}
bool Client::autorization(const string&){ cout << "df"; return true; }//?????????????????????????
=======
#include "client.h"

Client::Client(const unsigned &_userID, const string &_name,const string& _login, const string& _password) : User(_userID, _name), login(_login), password(_password)
{ 
	cout << "newUser"; 
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
Chat Client::find_chat(const unsigned int &chatID)
{
	for (list<Chat>::iterator i = room.begin(); i != room.end(); i++)
	{
		if (chatID == (*i).get_chatID())//change to _message in s
			return (*i);// ???? проверить будет ли удаляться элемент из talk при удалении find_mes 
	}
		//send_to_server WHAT THE FUCK

	return ;
}
bool Client::add_chat(const User &newUser,unsigned int &chatID)
{
	room.push_back(Chat(newUser,chatID));
	//	cout << "Error add_chat";
	//	return false;
	return true;
}
bool Client::open_chat(const Chat&){ return true; }//??????
bool Client::close_chat(const Chat&){ return true; }//??????
bool Client::delete_chat(const User &oldUser, unsigned int &chatID)
{
	room.remove(Chat(oldUser,chatID));
	//	cout << "Error delete_chat";
	//	return false;
	return true;
}
bool Client::change_password(const string& curr_pas,const string& new_pas)
{
	if (password != curr_pas) return false;
	password = new_pas;	//send to server???
	return true;
}
bool Client::autorization(const string&){ cout << "df"; return true; }//?????????????????????????
>>>>>>> sec
