#include "client.h"

Client::Client(const string &_name,const string& _login, const string& _password) : User(_name, _login), password(_password){ cout << "newUser"; }
Client::~Client()
{
	cout << "Delete Client";
}
inline bool Client::add_friend(const User &newUser)
{
	try
	{
		friends.push_back(newUser);
	}
	catch (exception ex)
	{
		return false;
	}
	return true;
}
bool Client::delete_friend(const User &oldUser)
{
	try
	{
		friends.remove(oldUser);
	}
	catch (exception ex)
	{
		return false;
	}
	return true;
}

bool Client::add_chat(const User &newUser)
{
	try
	{
		room.push_back(Chat(newUser));
	}
	catch (exception ex)
	{
		cout << "Error add_chat";
		return false;
	}
	return true;
}
bool Client::open_chat(const Chat&){ return true; }//??????
bool Client::close_chat(const Chat&){ return true; }//??????
bool Client::delete_chat(const User &oldUser)
{
	try
	{
		room.remove(Chat(oldUser));
	}
	catch (exception ex)
	{
		cout << "Error delete_chat";
		return false;
	}
	return true;
}
bool Client::change_password(const string& curr_pas,const string& new_pas)
{
	if (password != curr_pas) return false;
	password = new_pas;	//send to server???
	return true;
}
bool Client::autorization(const string&){ cout << "df"; return true; }//?????????????????????????
