#include "tablemodel.h"

TableModel::TableModel(Chat& controller,User user, QObject *parent):user(user),controller(controller),QAbstractTableModel(parent){
    vm=controller.get_messages_user(user.get_id());
    /*
    connect(&game,SIGNAL(guessed()),this,SLOT(update()));
    connect(&game,SIGNAL(not_guessed()),this,SLOT(update()));*/
    connect(&controller,SIGNAL(modified()),this,SLOT(update()));

}
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        if (orientation == Qt::Horizontal) {
            switch (section)
            {
            case 0:
                return QString("name");
            case 1:
                return QString("message");
            }
        }
    }
    return QVariant();
}
QVariant TableModel::data(const QModelIndex &index, int role) const
{

    if (role == Qt::DisplayRole) {
        if(index.column()==0)
            return QString(user.get_name().c_str());
        if(index.column()==1)
            return QString(vm[index.row()].get_message().c_str());
    }
    return QVariant();
}
void TableModel::setVectorData(std::vector<Message> v2){
    vm.clear();
    vm=v2;

    beginResetModel();
    endResetModel();
}

void TableModel::update(){
    vm.clear();
   // v=controller.get_sorted_by_name();
    vm=controller.get_messages_user(user.get_id());
    beginResetModel();
    endResetModel();
}
TableModel::~TableModel()
{
    ;
}

