<<<<<<< HEAD
//#pragma once
#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
enum commands{
	REGISTRATION,
	AUTHORIZATION,
	MESSAGE,
	ADD_FRIEND,
	FIND_FRIEND,

};
using namespace std;
class User
{
protected:
	string name;
	string login;
	bool status;
	unsigned userID;
public:
    User(const string &login,const string &name);//????
	//User() = default;// { User("", ""); };// { cout << "wtf"; };
	User(const User &);
	//User &operator=(User);//�� ������������ ������, ����� �� ���� ����������� � ������� ����� ���������� ������
	string get_name();
	string get_login();
	bool get_status();
	unsigned get_userID();
	void change_name(string);
	void change_status();
	virtual ~User();
    bool operator==(const User& right);
};
#endif // USER_H
=======
//#pragma once
#ifndef USER_H
#define USER_H


#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
enum commands{
	REGISTRATION,
	AUTHORIZATION,
	MESSAGE,
	ADD_FRIEND,
	FIND_FRIEND,
	CREAT_CHAT,
	EXIT
};
enum results{
	NEW_FRIEND,
	REQUST,
	NEW_CHAT,
	SENT,
	READ
};
using namespace std;
class User
{
protected:
	string name;
	bool status;
	unsigned int userID;
public:
    User(const unsigned int & _userID,const string &_name);//????
	//User() = default;// { User("", ""); };// { cout << "wtf"; };
	User(const User &);
	//User &operator=(User);//�� ������������ ������, ����� �� ���� ����������� � ������� ����� ���������� ������
	string get_name();
	bool get_status();
	unsigned int get_userID();
	void change_name(string);
	void change_status();
	virtual ~User();
    bool operator==(const User& right);
};
#endif // USER_H
>>>>>>> sec
