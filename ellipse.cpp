#include "ellipse.h"

Ellipse::Ellipse(QPointF center) {
    name = "Ellipse";
    this->center = center;
    this->corner = center;
    setPenBrush(QPen(Qt::black, 2, Qt::SolidLine), QBrush(Qt::NoBrush));

}
Shape* Ellipse::newShape(QPointF position){
    return new Ellipse(position);
};
void Ellipse::draw(QPainter &painter) const {
    QPointF oppositeCorner = 2*center - corner;
    painter.drawEllipse(QRectF(oppositeCorner, corner));
}

void Ellipse::setEndLocation(QPointF corner){
    this->corner = corner;
}
QRectF Ellipse::getPosition(){
    return QRectF(center, corner);
}

