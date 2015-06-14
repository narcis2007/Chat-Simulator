#ifndef USER_H
#define USER_H
#include<string>

class User
{
    int id;
    std::string name;
public:
    User(int id,std::string name):id(id),name(name){}
    ~User();
    int get_id(){return id;}
    const std::string& get_name()const{return name;}
};

#endif // USER_H
