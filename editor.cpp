#include "editor.h"

//робимо інтерфейс для створення об'єктів прямо в editor.cpp
//бо цей інтерфейс тільки тут використовується
//і мені лінь його переносити по різним файлам))
QPen basicPen(Qt::black, 2, Qt::SolidLine);
QBrush basicBrush(Qt::black, Qt::SolidPattern);

SingletonEditor *SingletonEditor::p_editor = nullptr;
SingletonEditor::SingletonEditor(QWidget *parent)
    : QWidget(parent)
    {

    };

SingletonEditor *SingletonEditor::getInstance()
{
    if (p_editor == nullptr){
        p_editor = new SingletonEditor();
    }
    return p_editor;
}

SingletonEditor::~SingletonEditor()
{
    for (auto shape : shapes)
        delete shape;
    delete tempShape;
    delete currentShapeT;
}

void SingletonEditor::start(Shape* currShape){
    delete currentShapeT;
    currentShapeT = currShape;
};

void SingletonEditor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for (uint i = 0; i < shapes.size(); i++){
        Shape *currShape = shapes[i];
        if (currShape != nullptr){
            if (i == drawAsActive){
                currShape->drawActive(painter);
            }
            else {
                currShape->drawBase(painter);
            }
        }
    }
    if (tempShape != nullptr) {
        tempShape->drawRubber(painter);
    }
}

void SingletonEditor::mousePressEvent(QMouseEvent *event)
{
    if(!currentShapeT) return;
    tempShape = currentShapeT->newShape(event->position());
}

void SingletonEditor::mouseMoveEvent(QMouseEvent *event)
{
    if(!tempShape) return;
    tempShape->setEndLocation(event->position());
    update();
}

void SingletonEditor::mouseReleaseEvent(QMouseEvent *event)
{
    if(!tempShape) return;
    if(choosenColor) tempShape->setColor(*choosenColor);

    shapes.push_back(tempShape);
    QRectF pos = tempShape->getPosition();
    emit shapeAdded(tempShape->getName(), pos.x(), pos.y(), pos.height(), pos.width());
    tempShape = nullptr;
    update();
}
void SingletonEditor::deleteElement(int index){
    delete shapes.at(index);
    shapes.erase(shapes.begin() + index);
    update();
};
void SingletonEditor::setDrawAsActive(int index){
    qDebug() << index;
    drawAsActive = index;
    update();
};
std::vector<Shape*> SingletonEditor::getShapes(){
    return this->shapes;
};

void SingletonEditor::contextMenuEvent(QContextMenuEvent *event)
{
    if (choosenColor) delete choosenColor;
    QColor col = QColorDialog::getColor();

    choosenColor = col.isValid() ?
            new QColor(col) :
            nullptr;
}
