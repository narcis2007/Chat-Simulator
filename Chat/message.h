#ifndef MESSAGE_H
#define MESSAGE_H
#include<string>

class Message
{
    int id;
    std::string message;
public:
    Message(int id,std::string message):id(id),message(message){}
    ~Message();
    int get_id(){return id;}
    const std::string& get_message()const{return message;}
};

#endif // MESSAGE_H
