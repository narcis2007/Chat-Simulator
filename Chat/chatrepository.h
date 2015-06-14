#ifndef CHATREPOSITORY_H
#define CHATREPOSITORY_H
#include<string>
#include"message.h"
#include"user.h"
#include<vector>
#include<fstream>
#include<future>
#include<algorithm>

using namespace std;
class ChatRepository
{
    vector<User> vu;
    vector<Message> vm;
    string user_file,message_file;
public:
    ChatRepository(string user_file,string message_file):user_file(user_file),message_file(message_file){

        std::future<void> f=std::async(&ChatRepository::load_users,this);
        f.get();
        //load_users();
    }
    ~ChatRepository();
    void load_users(){
        ifstream f(user_file.c_str());
        int id;
        string username;
        while(f>>id>>username){
            vu.push_back(User(id,username));

        }
        f.close();
    }
    void add_message(int id,string message){
        vm.push_back(Message(id,message));
        ofstream g(message_file.c_str(),std::ofstream::app);
        g<<id<<" "<<message<<endl;
        g.close();
    }
    void clear_messages(int id){
        ofstream g(message_file.c_str());
        vector<Message> vm2;
        for_each(vm.begin(),vm.end(),[&](Message m)
        {
            if(m.get_id()!=id){
                vm2.push_back(m);
                g<<m.get_id()<<" "<<m.get_message()<<endl;
            }
         }
                 );
        vm.clear();
        vm=vm2;
    }

    int get_count(){return vu.size();}
    vector<User> get_users(){return vu;}
    vector<Message> get_messages(){return vm;}

};

#endif // CHATREPOSITORY_H
