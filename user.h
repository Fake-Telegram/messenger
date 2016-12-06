//#pragma once
#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
#include "settings.h"

using namespace std;
class User
{
protected:
	string m_name;
	unsigned int m_userId;
	bool m_status;
public:
	User(const unsigned int & userId, const string &name);//????
	User(const User &user);
	User();
	//User &operator=(User);
	string get_name();
	bool get_status();
	void set_userId(const unsigned int userId);
	unsigned int get_id();
	void change_name(const string &newName);
	void change_status();
	virtual ~User();
	bool operator==(const User& right);
};
#endif // USER_H
