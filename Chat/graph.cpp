#include "graph.h"

Graph::Graph(Chat& controller,User user,QWidget *parent) :user(user),controller(controller), QWidget(parent)
{
    v=controller.get_messages_user(user.get_id());
    setMinimumSize(300,300);
    connect(&controller,SIGNAL(modified()),this,SLOT(update_graph()));
}
void Graph::paintEvent(QPaintEvent *event){
       QPainter painter(this);
       int w=width();
       int h=height();
       int baselineY=h-100;
       int barWidth=100;
       painter.drawLine(0,baselineY,w,baselineY);
       //for_each (v.begin(),v.end(),[&](const Product& i) {
           int barX = barWidth + barWidth / 2;
           painter.drawRect(barX, baselineY - v.size()*10 , barWidth/2 ,v.size()*10);
           painter.drawText(barX, baselineY + 20, QString(user.get_name().c_str()));
           painter.drawText(barX, baselineY + 40, QString::number(v.size()));

}
Graph::~Graph()
{

}

