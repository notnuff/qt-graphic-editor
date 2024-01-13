#ifndef SHAPE_H
#define SHAPE_H

#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>
class Shape {
protected:
    QString name;
    QPen thisPen;
    QBrush thisBrush;
public:
    virtual ~Shape() {};
    virtual Shape *newShape(QPointF position) = 0;
    virtual void draw(QPainter &painter) const = 0;
    virtual void drawRubber(QPainter &painter){
        QPen pen(Qt::black, 2, Qt::DashLine);
        QBrush brush(Qt::white, Qt::SolidPattern);
        painter.setPen(pen);
        painter.setBrush(brush);
        draw(painter);
    };
    virtual void drawBase(QPainter &painter){
        painter.setPen(thisPen);
        painter.setBrush(thisBrush);
        draw(painter);
    };
    virtual void drawActive(QPainter &painter){
        QPen pen(Qt::red, 2, Qt::SolidLine);
        painter.setPen(pen);
        draw(painter);
    };
    virtual void setEndLocation(QPointF end) = 0;
    virtual void setFinal(bool isFinal){};
    virtual QRectF getPosition() = 0;
    virtual QString getName() {
        return this->name;
    };
    virtual void setPenBrush(QPen pen, QBrush brush){
        thisPen = pen;
        thisBrush = brush;
    };
    virtual void setColor(QColor col){
        thisPen.setColor(col);
    }

};
#endif // SHAPE_H
