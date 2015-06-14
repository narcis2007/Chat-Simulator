#ifndef CHAT_H
#define CHAT_H

#include <QtWidgets>
#include"chatrepository.h"
#include<vector>
#include<stdexcept>
#include<exception>
class MyException : public std::exception
{
public:
    std::string what(){return "void text";}
private:
};

class Chat : public QWidget
{
    Q_OBJECT
    ChatRepository& repository;
public:
    explicit Chat(ChatRepository& repository,QWidget *parent = 0):repository(repository),QWidget(parent){}
    ~Chat();
    vector<User> get_users(){return repository.get_users();}
    int get_count(){return repository.get_count();}
    void add_message(int id,string message){
        if(message.size()==0)
            throw MyException();
        repository.add_message(id,message);
        emit modified();
    }
    vector<Message> get_messages_user(int id){
        auto v=repository.get_messages();
        vector<Message> v2;
        for_each(v.begin(),v.end(),[&](Message& m)
        {
            if(m.get_id()==id)
                v2.push_back(m);
         }
                 );
        return v2;
    }
    void clear_messages(int id){
        repository.clear_messages(id);
        emit modified();
    }


signals:
    void modified();//pot pune id ca parametru

public slots:
};

#endif // CHAT_H
