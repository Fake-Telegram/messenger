#ifndef CLIENT_H
#define CLIENT_H

#include <list>
#include "user.h"

class Client :
	virtual public User//??????
{
private:
	std::string password;
	std::list<User> friends;
	//std::list<Chat> room;
public:
	Client(std::string, std::string, std::string);
	~Client();
	inline bool add_friend(User);//inline --experiment???
	bool delete_friend(User);
	bool add_chat(User);
	//bool open_chat(Chat);//??????
	//bool close_chat(Chat);//??????
	bool delete_chat(User);
	unsigned change_password(std::string, std::string);
	bool autorization(std::string);
};
Client::Client(std::string _name, std::string _login, std::string _password)
{
	password = _password;
	User(_name, _login);
}
Client::~Client()
{
	std::cout << "Delete Client";
}
inline bool Client::add_friend(const User newUser)
{
	friends.push_back(newUser);
	return true;
}

#endif // CLIENT_H
