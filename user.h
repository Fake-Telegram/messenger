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
	string name;
	bool status;
	unsigned int userID;
public:
    User(const unsigned int & _userID, const string &_name);//????
	//User() = default;// { User("", ""); };// { cout << "wtf"; };
	User(const User &);
	//User();
	//User &operator=(User);//�� ������������ ������, ����� �� ���� ����������� � ������� ����� ���������� ������
	string get_name();
	bool get_status();
	void set_UserID(const unsigned int _UserID);
	unsigned int get_userID();
	void change_name(string);
	void change_status();
	virtual ~User();
    bool operator==(const User& right);
};
#endif // USER_H
