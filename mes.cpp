// mes.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace std;
using namespace rapidjson;


bool jsonParse(string json)
{
	Document document;
	document.Parse(json.c_str());
	switch (document["operation"].GetInt())
	{
	case REGISTRATION:
		//registration(json); or registration(document["login"].GetString(),document["name"].GetString(),document["password"].GetString());????
		break;
	case AUTHORIZATION:
		//authorization(document["login"].GetString(),document["password"].GetString())


		break;
	case MESSAGE:
		//if(!document["OTRstatus"].GetBool());
		//{saveMessage(json); or saveMessage(loginFrom,document["chatID"].GetString(),document["text"].GetString(),document["datetime"].GetString());}
		//sendMessage(json, loginFrom) or sendMessage(loginFrom,document["chat"].GetString(),document["text"].GetString(),document["datetime"].GetString());
		break;
	case ADD_FRIEND:

		break;
	case FIND_FRIEND:
		break;

	case CREAT_CHAT:
		//create_chat()
		//return chatID
		break;

	case EXIT:
		break;
	default:
		cout << "Error\n";
		return false;
		break;
	}
	return true;
}
bool registration(const string &login, const string &name, const string & password)
{
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

	writer.StartObject();

	writer.Key("operation");
	writer.Int(REGISTRATION);
	writer.Key("login");
	writer.String(login.c_str());
	writer.Key("name");
	writer.String(name.c_str());
	writer.Key("password");
	writer.String(password.c_str());

	writer.EndObject();
	string json = buffer.GetString();

	//send(json);
	//ответ???
	return 0;
}
bool authorization(const string &login, const string & password)
{
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

	writer.StartObject();

	writer.Key("operation");
	writer.Int(AUTHORIZATION);
	writer.Key("login");
	writer.String(login.c_str());
	writer.Key("password");
	writer.String(password.c_str());

	writer.EndObject();
	string json = buffer.GetString();

	//send(json);
	//ответ???
	return 0;
}
/*
//message
string rapidJSON(){
	Document document;
	document.SetObject();
	document.AddMember("operation", MESSAGE, document.GetAllocator());
	document.AddMember("otr_status", otr_status, document.GetAllocator());
	document.AddMember("text", text, document.GetAllocator());
	document.AddMember("operation", MESSAGE, document.GetAllocator());

	
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	document.Accept(writer);
	return buffer.GetString();
}*/
int _tmain(int argc, _TCHAR* argv[])
{
	string json = "{\"type\":\"test\",\"number\":1}";
	string as;

	Document doc,document;
	doc.SetObject();
	document.SetObject();
	
	Value val("operation");
	doc.AddMember(val, FIND_FRIEND, doc.GetAllocator());
	
	document.AddMember("\"adss", doc, document.GetAllocator());
	val.SetInt(1);val = 1;
	//doc.AddMember("asd","das",document.GetAllocator());
StringBuffer buffer;
Writer<StringBuffer> writer(buffer);
document.Accept(writer);
/*writer.StartObject();
writer.Key("fas");
writer.String("fass");
writer.EndObject();*/
//document.GetString();
cout << buffer.GetString() << endl;
//cout << doc["operation"].GetInt();

	
/*
	document.Parse(json.c_str());
	cout<<document.IsString();
	// Example 1: Json modification, writing Json to console
	Value& s = document["number"];
	s.SetInt(s.GetInt() + 1);
	document.AddMember("asd", true, document.GetAllocator());
	document["asd"] = false;
	cout<<document["asd"].IsBool();
	//Valuedocument.Key("low");
	cout<<document.IsObject();
	cout << as;
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	document.Accept(writer);
	//document.GetString();
	cout << buffer.GetString() << endl;
	cout << document["type"].GetString();
	as = buffer.GetString();
	cout << as;
	*/
	//User Pit = User("Pit","YoPit");
	Client PC(12,"Pit","PC","132");
	Message m=Message("What's up",true);
	ofstream in;
	in.open("hk.txt",ios::app);
	cout << m.get_datetime().tm_mday;
	m.getMessage(in);
	cout<<m.get_string_datetime();
	User *lol=new User(12,"lop");
	Chat *room=new Chat(*lol,16);
	room->send_message(Message("pop",false));
	cout << "lk"<<PC.get_name() << "ssa " << PC.get_userID()<<"asd "<<PC.get_status();
	//cout << Pit.get_name() << " " << Pit.get_login();
	in.close();
	return 0;
}