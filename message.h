#ifndef MESSAGE_H
#define MESSAGE_H
#include <ctring>
#include <ctime>

class Message
{
public:
    Message();
    Message(const Message &other) = default;
    ~Message();
private:
    unsigned _id;
    string _text;
    tm _datetime;
};

#endif // MESSAGE_H
