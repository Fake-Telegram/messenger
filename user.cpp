#include "user.h"

User::User(const string &_name, const string &_login) : name(_name),login(_login)
{
	userID = 1;// CreateID(); ? ? ? ? ? ? ?
}
User::User(const User &user)
{
	name = user.name;
	login = user.login;
	userID = user.userID;
	status = user.status;
}
User::~User()
{
	cout << "Delete User";
}
string User::get_name()
{
	return name;
}
string User::get_login()
{
	return login;
}
bool User::get_status()
{
	return status;
}
unsigned User::get_userID()
{
	return userID;
}
void User::change_name(string newname)
{
	name = newname;
}
void User::change_status()
{
	status = !status;
}
bool User::operator==(const User& right)
{
    return login == right.login;
}
