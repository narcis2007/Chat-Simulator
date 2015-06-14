#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include"chat.h"
class Graph : public QWidget
{
    Q_OBJECT
    std::vector<Message> v;
    Chat& controller;
    User user;
    void paintEvent(QPaintEvent *event);
public:
    explicit Graph(Chat& controller,User user,QWidget *parent = 0);
    ~Graph();


signals:

public slots:
    void update_graph(){
        v=controller.get_messages_user(user.get_id());
        update();
    }
};

#endif // GRAPH_H
