#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape {
protected:
    QPointF start, end;
    void draw(QPainter &painter, QPointF start, QPointF end) const;
    void drawRubber(QPainter &painter, QPointF start, QPointF end) const;
public:
    Line(QPointF start);
    Line(){};
    Shape* newShape(QPointF position) override;
    void draw(QPainter &painter) const override;
    void setEndLocation(QPointF end) override;
    virtual QRectF getPosition() override;
};

#endif
