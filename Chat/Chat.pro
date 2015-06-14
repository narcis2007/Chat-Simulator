#-------------------------------------------------
#
# Project created by QtCreator 2015-06-14T11:13:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chat
TEMPLATE = app


SOURCES += main.cpp\
        main.cpp \
    chatrepository.cpp \
    chat.cpp \
    message.cpp \
    user.cpp \
    messagelist.cpp \
    graph.cpp \
    tablemodel.cpp \
    multiwindow.cpp \
    errorwindow.cpp

HEADERS  += main.h \
    chatrepository.h \
    chat.h \
    message.h \
    user.h \
    messagelist.h \
    graph.h \
    tablemodel.h \
    multiwindow.h \
    errorwindow.h

DISTFILES += \
    ../build-Chat-Desktop_Qt_5_4_1_MSVC2013_64bit-Debug/user.txt \
    ../build-Chat-Desktop_Qt_5_4_1_MSVC2013_64bit-Debug/messages.txt
