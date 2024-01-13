#ifndef LINEOOSHAPE_H
#define LINEOOSHAPE_H

#include "line.h"
#include "dot.h"

class LineOOShape : public Line, public Dot
{
public:
    LineOOShape(){};
    ~LineOOShape();
    LineOOShape(QPointF position);
    Shape* newShape(QPointF position) override;
    void draw(QPainter &painter) const override;
    virtual QString getName() override;
};

#endif // LINEOOSHAPE_H
