#include "lineooshape.h"

Shape* LineOOShape::newShape(QPointF position){
    Line* lineOOShape = new LineOOShape(position);
    Line::name = "LineOOShape";
    return lineOOShape;
};

void LineOOShape::draw(QPainter &painter) const{
    Dot::draw(painter);
    Dot::draw(painter, end);
    Line::draw(painter);
};

LineOOShape::LineOOShape(QPointF position):Line(position){
    Line::name = "LineOOShape";
    Dot::setEndLocation(position);

    Line::setPenBrush(QPen(Qt::black, 2, Qt::SolidLine), QBrush(Qt::SolidPattern));
};
LineOOShape::~LineOOShape(){

};
QString LineOOShape::getName(){
    return Line::name;
};
