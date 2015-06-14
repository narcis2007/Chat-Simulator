#ifndef MULTIWINDOW_H
#define MULTIWINDOW_H

#include <QWidget>
#include"chat.h"
#include"messagelist.h"
class MultiWindow : public QWidget
{
    Q_OBJECT
    Chat& controller;
    vector<MessageList*> vml;
public:
    explicit MultiWindow(Chat& controller,QWidget *parent = 0);
    ~MultiWindow();

signals:

public slots:
};

#endif // MULTIWINDOW_H
