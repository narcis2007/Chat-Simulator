#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QWidget>
#include"chat.h"
class TableModel : public QAbstractTableModel
{
    Q_OBJECT
    Chat& controller;
    User user;
    std::vector<Message> vm;
private slots:
    void update();
public:
    TableModel(Chat& controller,User user,QObject* parent=0);
    int rowCount(const QModelIndex&) const
    {
        return vm.size();
    }
    int columnCount(const QModelIndex&) const
    {
        return 2;
    }
    void setVectorData(std::vector<Message> v2);
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    ~TableModel();
};

#endif // TABLEMODEL_H
