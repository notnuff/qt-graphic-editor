#include "rectangle.h"

Rectangle::Rectangle(QPointF topLeft) {
    name = "Rect";
    this->topLeft = topLeft;
    this->bottomRight = topLeft;
    setPenBrush(QPen(Qt::black, 2, Qt::SolidLine), QBrush(Qt::white, Qt::SolidPattern));
}
Shape* Rectangle::newShape(QPointF position){
    return new Rectangle(position);
};
void Rectangle::draw(QPainter &painter) const {
    painter.drawRect(QRectF(topLeft, bottomRight));
}

void Rectangle::draw(QPainter &painter, QPointF start, QPointF end) const{
    QPen pen(Qt::black, 2, Qt::SolidLine);
    QBrush brush(Qt::white, Qt::SolidPattern);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(QRectF(start, end));
};
void Rectangle::drawRubber(QPainter &painter, QPointF start, QPointF end) const{
    QPen pen(Qt::blue, 2, Qt::DashLine);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(pen);
    painter.drawRect(QRectF(start, end));
};
void Rectangle::setEndLocation(QPointF bottomRight) {
    this->bottomRight = bottomRight;
};
QRectF Rectangle::getPosition(){
    return QRectF(topLeft, bottomRight);
}

