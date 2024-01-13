#include "dot.h"

Dot::Dot(QPointF position) {
    name = "Dot";
    setEndLocation(position);
    setPenBrush(QPen(Qt::black, Qt::SolidLine), QBrush(Qt::black, Qt::SolidPattern));
}

Shape* Dot::newShape(QPointF position){
    return new Dot(position);
}

void Dot::draw(QPainter &painter) const {
    painter.drawEllipse(x - 5, y - 5, 10, 10);
}

void Dot::draw(QPainter &painter, QPointF position) const {
    painter.drawEllipse(position.x() - 5, position.y() - 5, 10, 10);
}

void Dot::setEndLocation(QPointF end){
    this->x = end.rx();
    this->y = end.ry();
}
QRectF Dot::getPosition(){
    return QRectF(x, y, x, y);
}
