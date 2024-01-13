#ifndef EDITOR_H
#define EDITOR_H

#include <QWidget>
#include <QPainter>
#include <vector>
#include <QMouseEvent>
#include <QColor>
#include <QColorDialog>

#include "shape.h"
#include "rectangle.h"
#include "dot.h"
#include "line.h"
#include "ellipse.h"
#include "lineooshape.h"
#include "cubeshape.h"

class SingletonEditor : public QWidget {
    Q_OBJECT
private:
    QColor *choosenColor = nullptr;
    static SingletonEditor *p_editor;
    std::vector<Shape*> shapes;
    Shape* tempShape = nullptr;
    Shape* currentShapeT = nullptr;
    int drawAsActive = -1;
    QPointF startPoint;
    SingletonEditor(QWidget *parent = nullptr);
signals:
    void shapeAdded(QString type, int x1, int x2, int y1, int y2);
public slots:
    void setDrawAsActive(int index);
    void deleteElement(int index);
public:
    SingletonEditor(SingletonEditor &other) = delete;
    void operator=(const SingletonEditor &) = delete;
    static SingletonEditor *getInstance();
    ~SingletonEditor();
    std::vector<Shape*> getShapes();
    void start(Shape*);
protected:
    #ifndef QT_NO_CONTEXTMENU
        void contextMenuEvent(QContextMenuEvent *event) override;
    #endif // QT_NO_CONTEXTMENU
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
};
#endif // EDITOR_H
