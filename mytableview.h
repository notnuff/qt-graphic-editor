#ifndef MYTABLEVIEW_H
#define MYTABLEVIEW_H

#include <QTableView>

class MyTableView : public QTableView
{
    Q_OBJECT
public:
    MyTableView();
signals:
    void mPressed(QMouseEvent *e);
public slots:
    //void mousePressEvent(QMouseEvent *e) override;
};

#endif // MYTABLEVIEW_H
