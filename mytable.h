#ifndef MYTABLE_H
#define MYTABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QMenu>
#include <QContextMenuEvent>
#include <QHeaderView>
#include "mytableview.h"

namespace Ui {
class MyTable;
}

class MyTable : public QWidget
{
    Q_OBJECT

public:
    explicit MyTable(QWidget *parent = nullptr);
    ~MyTable();
public slots:
    void addRow(QString type, int x1, int x2, int y1, int y2);
signals:
    void drawAsActive(int index);
    void deletedElement(int index);
private:
    Ui::MyTable *ui;
    MyTableView *tableView;
    //QAbstractTableModel *tableModel;

    void createActions();
    QAction *newAct;
    QAction *delAct;
protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private slots:
    void keyPressEvent(QKeyEvent *e) override;
    void mousePressed();
    void delFile();
};

#endif // MYTABLE_H
