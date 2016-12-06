#include "user.h"

User::User() : m_userId(0), m_name("user"), m_status(false)
{}
User::User(const unsigned int & userId, const string &name) : m_name(name), m_userId(userId), m_status(false)
{}
User::User(const User &user)
{
	m_name = user.m_name;
	m_userId = user.m_userId;
	m_status = user.m_status;
}
User::~User()
{
	//cout << "Delete User";
}
string User::get_name()
{
	return m_name;
}
void User::set_userId(const unsigned int userId)
{
	m_userId = userId;
}
bool User::get_status()
{
	return m_status;
}
unsigned int User::get_id()
{
	return m_userId;
}
void User::change_name(const string &newName)
{
	m_name = newName;
}
void User::change_status()
{
	m_status = !m_status;
}
bool User::operator==(const User& right)
{
	return m_userId == right.m_userId;
}
