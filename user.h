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
	//User &operator=(User);//не динамическая память, нужно ли явно прописывать и удалять ранее выделенную память
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
