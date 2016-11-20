#include "user.h"

User::User(const unsigned int & _userID, const string &_name) : userID(_userID), name(_name)
{
}
User::User(const User &user)
{
	name = user.name;
	userID = user.userID;
	status = user.status;
}
User::~User()
{
	cout << "Delete User aaa";
}
string User::get_name()
{
	return name;
}
bool User::get_status()
{
	return status;
}
unsigned int User::get_userID()
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
    return userID == right.userID;
}
