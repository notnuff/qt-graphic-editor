#include "line.h"

Line::Line(QPointF start) {
    name = "Line";
    this->start = start;
    this->end = start;
    setPenBrush(QPen(Qt::black, 2, Qt::SolidLine), QBrush(Qt::NoBrush));
}
Shape* Line::newShape(QPointF position){
    return new Line(position);
};

void Line::draw(QPainter &painter) const {
    painter.drawLine(start,end);
}

void Line::draw(QPainter &painter, QPointF start, QPointF end) const{
    QPen pen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(pen);
    painter.drawLine(start,end);
};
void Line::drawRubber(QPainter &painter, QPointF start, QPointF end) const{
    QPen pen(Qt::black, 2, Qt::DashLine);
    painter.setPen(pen);
    painter.drawLine(start,end);
};
void Line::setEndLocation(QPointF end){
    this->end = end;
}
QRectF Line::getPosition(){
    return QRectF(start, end);
}
