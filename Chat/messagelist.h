#ifndef MESSAGELIST_H
#define MESSAGELIST_H

#include <QtWidgets>
#include"chat.h"
#include"tablemodel.h"
#include"graph.h"
#include"errorwindow.h"
class MessageList : public QWidget
{
    Q_OBJECT
    Chat& controller;
    User user;
    QPushButton *add,*clear;
    QLineEdit *text;
    QVBoxLayout *layout;
    QTableView *view;
    TableModel *model;
    Graph *graph;
    ErrorWindow *error;
public:
    explicit MessageList(Chat& controller,User user,QWidget *parent = 0);

    ~MessageList(){
        delete layout,text,add,view,model,graph,clear;
    }

signals:

public slots:
    void add_message(){
        try{
            std::future<void> f=std::async(&Chat::add_message,&controller,user.get_id(),text->text().toStdString());
            f.get();
            //controller.add_message(user.get_id(),text->text().toStdString());
        }
        catch(MyException &e){
            if(error==0)
                error=new ErrorWindow(e.what());
            error->show();
        }
    }
    void clear_messages(){
        std::future<void> f=std::async(&Chat::clear_messages,&controller,user.get_id());
        f.get();
        //controller.clear_messages(user.get_id());
    }

};

#endif // MESSAGELIST_H
