#include "messagelist.h"

MessageList::MessageList(Chat& controller,User user,QWidget *parent):QWidget(parent),controller(controller),user(user){
    setWindowTitle(user.get_name().c_str());

    layout=new QVBoxLayout();

    error=0;

    text=new QLineEdit();
    layout->addWidget(text);

    add=new QPushButton("add");
    connect(add,SIGNAL(clicked()),this,SLOT(add_message()));
    layout->addWidget(add);

    view=new QTableView();
    model=new TableModel(controller,user);
    view->setModel(model);
    layout->addWidget(view);

    graph=new Graph(controller,user);
    layout->addWidget(graph);

    clear=new QPushButton("clear");
    layout->addWidget(clear);
    connect(clear,SIGNAL(clicked()),this,SLOT(clear_messages()));

    setLayout(layout);
}


