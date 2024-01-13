#ifndef CUBESHAPE_H
#define CUBESHAPE_H

#include "line.h"
#include "rectangle.h"

class CubeShape : public Line, public Rectangle
{
private:
public:
    CubeShape(){};
    ~CubeShape();
    CubeShape(QPointF position);
    Shape* newShape(QPointF position) override;
    void draw(QPainter &painter) const override;
    void drawRubber(QPainter &painter) override;
    virtual QString getName() override;
};
#endif // CUBESHAPE_H
