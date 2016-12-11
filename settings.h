#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <ctime>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace std;
enum commands{
	REGISTRATION,
	AUTHORIZATION,
	MESSAGE,
	ADD_FRIEND,
	FIND_FRIEND,
	CREATE_CHAT,
	EXIT,
	// Servsr's answer.
	NEW_FRIEND,
	REQUST,
	NEW_CHAT,
	SENT,
	READ
};

#endif // SETTINGS_H
