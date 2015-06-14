#include "errorwindow.h"

ErrorWindow::ErrorWindow(const std::string& str,QWidget *parent) : QWidget(parent)
{
    error=new QLabel();
    error->setText(QString(str.c_str()));
    layout=new QGridLayout();
    layout->addWidget(error);
    setLayout(layout);
}

ErrorWindow::~ErrorWindow()
{
    delete error;
    delete layout;
}

