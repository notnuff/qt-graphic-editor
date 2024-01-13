#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

class Ellipse : public Shape {
    QPointF center, corner;
public:
    Ellipse(QPointF center);
    Ellipse(){};
    Shape* newShape(QPointF position) override;
    void draw(QPainter &painter) const override;
    void setEndLocation(QPointF corner) override;
    virtual QRectF getPosition() override;
};
#endif
