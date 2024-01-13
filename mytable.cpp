#include "mytable.h"
#include "ui_mytable.h"


namespace ColumnTypes {
enum {Name, x1, x2, y1, y2};
}

class TableRow
{
public:
    QString type;
    int x1, x2, y1, y2;
    TableRow(QString type, int x1, int x2, int y1, int y2){
        this->type = type;
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
};

class MyTableModel : public QAbstractTableModel
{
private:
    int colums = 5, rows = 0;
    std::vector<TableRow*> tableRows;
public:
    MyTableModel(){};
    int rowCount(const QModelIndex &parent) const{
        return rows;
    };
    int columnCount(const QModelIndex &parent) const{
        return colums;
    };
    QVariant data(const QModelIndex &index, int role) const{
        if (role == Qt::DisplayRole){
            QString answer;
                switch (index.column())
                {
                case ColumnTypes::Name :
                    return tableRows.at(index.row())->type;
                    break;
                case ColumnTypes::x1 :
                    return tableRows.at(index.row())->x1;
                    break;
                case ColumnTypes::x2:
                    return tableRows.at(index.row())->x2;
                    break;
                case ColumnTypes::y1:
                    return tableRows.at(index.row())->y1;
                    break;
                case ColumnTypes::y2:
                    return tableRows.at(index.row())->y2;
                    break;
                }
        }
        return QVariant();
    };
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const{
        if (role == Qt::DisplayRole)
        {
            if (orientation == Qt::Horizontal) {
                switch (section)
                {
                case ColumnTypes::Name :
                    return QString("Name");
                    break;
                case ColumnTypes::x1:
                    return QString("x1");
                    break;
                case ColumnTypes::x2:
                    return QString("x2");
                    break;
                case ColumnTypes::y1:
                    return QString("y1");
                    break;
                case ColumnTypes::y2:
                    return QString("y2");
                    break;
                default:
                    return QString("");
                    break;
                }
            }
        }
        return QVariant();
    };
    void addRow(QString type, int x1, int x2, int y1, int y2) {
        beginInsertRows (QModelIndex(), rows, rows);
        TableRow* thisRow = new TableRow(type, x1, x2, y1, y2);
        tableRows.push_back(thisRow);
        rows++;
        endInsertRows();
    }
    void deleteRow(int row) {
        beginRemoveRows(QModelIndex(), rows-1, rows-1);
        tableRows.erase(tableRows.begin() + row);
        rows--;
        endRemoveRows();
    }
    bool isValidIndex(int i){
        if (i < 0 || i >= tableRows.size()) return false;
        return true;
    }
} tableModel;

MyTable::MyTable(QWidget *parent) :
    QWidget(parent, Qt::Window),
    ui(new Ui::MyTable)
{
    ui->setupUi(this);
    tableView = new MyTableView();
    tableView->setParent(this);
    tableView->horizontalHeader()->
        setSectionResizeMode(QHeaderView::Stretch);
    tableView->setModel(&tableModel);

    createActions();
    QString message = tr("A context menu is available by right-clicking");
    this->setStatusTip(message);
    ui->horizontalLayout->addWidget(tableView);

}

void MyTable::addRow(QString type, int x1, int x2, int y1, int y2){
    tableModel.addRow(type, x1, x2, y1, y2);
};

void MyTable::createActions(){
    delAct = new QAction(tr("&Delete"), this);
    delAct->setShortcuts(QKeySequence::Delete);
    delAct->setStatusTip(tr("Delete an object"));
    connect(delAct, &QAction::triggered, this, &MyTable::delFile);
    connect(tableView, &MyTableView::pressed, this, &MyTable::mousePressed);
};
int currRow = -1;
#ifndef QT_NO_CONTEXTMENU
void MyTable::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(delAct);
    QPoint p = tableView->mapFromGlobal(event->pos());
    p.setY(p.y() - tableView->horizontalHeader()->height() - 3);
    currRow = tableView->indexAt(p).row();
    menu.exec(event->globalPos());
}

#endif // QT_NO_CONTEXTMENU

void MyTable::keyPressEvent(QKeyEvent *e){
    //currRow = tableView->currentIndex().row();
    delFile();
}

void MyTable::delFile()
{
    if(!tableModel.isValidIndex(currRow)) {
        return;
    }
    emit deletedElement(currRow);
    tableModel.deleteRow(currRow);
}
void MyTable::mousePressed() {
    currRow = tableView->currentIndex().row();
    if (QGuiApplication::mouseButtons() == Qt::LeftButton)
        emit drawAsActive(currRow);
};
MyTable::~MyTable()
{
    delete ui;
}

