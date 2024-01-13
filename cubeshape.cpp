#include "cubeshape.h"

Shape* CubeShape::newShape(QPointF position){
    Line* cubeShape = new CubeShape(position);
    Line::name = "Cube";
    return cubeShape;
};

void CubeShape::draw(QPainter &painter) const{
    QPointF middlePoint = start + (end - start) * 0.7;
    Rectangle::draw(painter, start, middlePoint);
    Rectangle::draw(painter, start + ( end - middlePoint), end);
    QPointF firstLineStart = QPointF(start.x(), middlePoint.y());
    QPointF firstLineEnd = firstLineStart + (end - middlePoint);
    Line::draw(painter, firstLineStart, firstLineEnd);
    QPointF secondLineStart = start;
    QPointF secondLineEnd = secondLineStart + (end - middlePoint);
    Line::draw(painter, secondLineStart, secondLineEnd);
    QPointF thirdLineStart = QPointF(middlePoint.x(), start.y());;
    QPointF thirdLineEnd = thirdLineStart + (end - middlePoint);
    Line::draw(painter, thirdLineStart, thirdLineEnd);

};
void CubeShape::drawRubber(QPainter &painter) {
    QPointF middlePoint = start + (end - start) * 0.7;
    Line::drawRubber(painter, middlePoint, end);
    Rectangle::drawRubber(painter, start + ( end - middlePoint), end);
    Rectangle::drawRubber(painter, start, middlePoint);
    QPointF firstLineStart = QPointF(start.x(), middlePoint.y());
    QPointF firstLineEnd = firstLineStart + (end - middlePoint);
    Line::drawRubber(painter, firstLineStart, firstLineEnd);
    QPointF secondLineStart = middlePoint;
    QPointF secondLineEnd = secondLineStart + (end - middlePoint);
    Line::drawRubber(painter, secondLineStart, secondLineEnd);
    QPointF thirdLineStart = QPointF(middlePoint.x(), start.y());;
    QPointF thirdLineEnd = thirdLineStart + (end - middlePoint);
    Line::drawRubber(painter, thirdLineStart, thirdLineEnd);
    Line::drawRubber(painter, start, start + (end - middlePoint));
}
CubeShape::CubeShape(QPointF position){
    Line::name = "Cube";
    start = position;
    end = position;
};
QString CubeShape::getName(){
    return Line::name;
};
CubeShape::~CubeShape(){

};

