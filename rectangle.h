    #ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
    QPointF topLeft, bottomRight;
protected:
    void draw(QPainter &painter, QPointF start, QPointF end) const;
    void drawRubber(QPainter &painter, QPointF start, QPointF end) const;
public:
    Rectangle(QPointF start);
    Rectangle(){};
    Shape* newShape(QPointF position) override;
    void draw(QPainter &painter) const override;
    void setEndLocation(QPointF bottomRight) override;
    virtual QRectF getPosition() override;
};

#endif // RECTANGLE_H
