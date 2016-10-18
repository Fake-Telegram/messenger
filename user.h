//#pragma once
#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
using namespace std;
class User
{
protected:
	string name;
	string login;
	bool status;
	unsigned userID;
public:
	explicit User(string, string);//????
	//User() = default;// { User("", ""); };// { cout << "wtf"; };
	//User(const User &) = delete;
	//User &operator=(User);
	string get_name();
	string get_login();
	bool get_status();
	unsigned get_userID();
	void change_name(string);
	void change_status();
	virtual ~User();
	friend bool operator==(const User& left, const User& right);
};
#endif // USER_H
