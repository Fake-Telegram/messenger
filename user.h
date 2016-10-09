#ifndef USER_H
#define USER_H

#include <string>

class User{
public:
    User(const string);
    User(const string, const string);
    User(const User &other);
    ~User();
    unsigned get_id();
    string get_name();
    string get_login();
    bool get_status();
    void change_name(const string);
private:
    unsigned id;
    string name;
    string login;
    bool status;
};

#endif // USER_H
