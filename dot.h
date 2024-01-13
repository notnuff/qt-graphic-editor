#ifndef DOT_H
#define DOT_H

#include "shape.h"

class Dot : public Shape {
protected:
    int x, y;
    void draw(QPainter &painter, QPointF position) const;
public:
    Dot(QPointF position);
    Dot(){};
    Shape* newShape(QPointF position) override;
    void draw(QPainter &painter) const override;
    void setEndLocation(QPointF end) override;
    virtual QRectF getPosition() override;
};

#endif // DOT_H
