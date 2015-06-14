#include<QtWidgets>
#include"chatrepository.h"
#include"chat.h"
#include"messagelist.h"
#include"multiwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatRepository repo("user.txt","messages.txt");
    Chat controller(repo);
    MultiWindow mw(controller);

    return a.exec();
}
