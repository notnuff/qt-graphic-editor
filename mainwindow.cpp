#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFileDialog>

enum Shapes
{
    dot,
    line,
    ellipse,
    rect,
    dumbbell,
    cube,
};

class {
private:
    struct ActionType
    {
        int shapeType;
        QAction *shapeEdit;
        QRadioButton *shapeButton;
    };
    std::vector<ActionType> actions;
public:
    void setChecked(int shapeType){
        for (auto curr : actions){
            curr.shapeButton->setChecked(curr.shapeType == shapeType);
            curr.shapeEdit->setChecked(curr.shapeType == shapeType);
        }
    }
    void addAction(int shapeType, QAction *shapeEdit, QRadioButton *shapeButton){
        actions.push_back((ActionType){shapeType, shapeEdit, shapeButton});
    }
} Handler;

//ButtonsHandler Handler;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    table = new MyTable(this);
    editor = SingletonEditor::getInstance();
    editor->setStyleSheet("border: 1px solid black; "
                                     "background-color: white;"
                                     "border-radius: 10px");
    editor->resize(500, 500);
    editor->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->centralwidget->layout()->addWidget(editor);

    ui->dotButton->setToolTip("Draw a dot");
    ui->lineButton->setToolTip("Draw a line");
    ui->ellipseButton->setToolTip("Draw a ellipse");
    ui->rectButton->setToolTip("Draw a rectangle");

    QObject::connect(table, &MyTable::deletedElement, editor, &SingletonEditor::deleteElement);
    QObject::connect(editor, &SingletonEditor::shapeAdded, table, &MyTable::addRow);
    QObject::connect(table, &MyTable::drawAsActive, editor, &SingletonEditor::setDrawAsActive);

    Handler.addAction(Shapes::dot, ui->dot_edit, ui->dotButton);
    Handler.addAction(Shapes::line, ui->line_edit, ui->lineButton);
    Handler.addAction(Shapes::rect, ui->rect_edit, ui->rectButton);
    Handler.addAction(Shapes::ellipse, ui->ellipse_edit, ui->ellipseButton);
    Handler.addAction(Shapes::dumbbell, ui->dumbbell_edit, ui->dumbbellButton);
    Handler.addAction(Shapes::cube, ui->cube_edit, ui->cubeButton);
}

MainWindow::~MainWindow()
{
    delete table;
    delete editor;
    delete ui;
}


void MainWindow::on_line_edit_triggered(bool checked)
{
    Handler.setChecked(Shapes::line);
    editor->start(new Line);

}
void MainWindow::on_rect_edit_triggered(bool checked)
{
    Handler.setChecked(Shapes::rect);
    editor->start(new Rectangle);
}
void MainWindow::on_ellipse_edit_triggered(bool checked)
{
    Handler.setChecked(Shapes::ellipse);
    editor->start(new Ellipse);
}
void MainWindow::on_dot_edit_triggered(bool checked)
{
    Handler.setChecked(Shapes::dot);
    editor->start(new Dot);
}
void MainWindow::on_dumbbell_edit_triggered(bool checked)
{
    Handler.setChecked(Shapes::dumbbell);
    editor->start((Line*)new LineOOShape);
}
void MainWindow::on_cube_edit_triggered(bool checked)
{
    Handler.setChecked(Shapes::cube);
    editor->start((Line*)new CubeShape);
}

void MainWindow::on_dotButton_clicked(bool checked)
{
    on_dot_edit_triggered(true);
}

void MainWindow::on_lineButton_clicked(bool checked)
{
    on_line_edit_triggered(true);
}

void MainWindow::on_ellipseButton_clicked(bool checked)
{
    on_ellipse_edit_triggered(true);
}

void MainWindow::on_rectButton_clicked(bool checked)
{
    on_rect_edit_triggered(true);
}

void MainWindow::on_dumbbellButton_clicked(bool checked)
{
    on_dumbbell_edit_triggered(true);
}
void MainWindow::on_cubeButton_clicked(bool checked)
{
    on_cube_edit_triggered(true);
}

void MainWindow::on_action_Toolbar_triggered()
{
    if(ui->frame->isVisible()){
        ui->action_Toolbar->setText("Показати toolbar");
        ui->frame->setVisible(false);
    } else {
        ui->action_Toolbar->setText("Сховати toolbar");
        ui->frame->setVisible(true);
    }
}

void MainWindow::on_action_triggered()
{
    table->show();
}


void MainWindow::on_action_2_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save File"), "",
                                                    tr("Text files (*.txt);;All Files (*)"));
    if (fileName.isEmpty())
        return;
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this,
                                 tr("Unable to open file"),
                                 file.errorString()
                                 );
        return;
    }
    QDataStream out(&file);
    std::vector<Shape *> shapes = editor->getShapes();
    for (uint i = 0; i < shapes.size(); i++) {
        // Get the coordinates in a fixed width format
        QString posX = QString("%1").arg((int)shapes[i]->getPosition().x(), 5);
        QString posY = QString("%1").arg((int)shapes[i]->getPosition().y(), 5);
        QString width = QString("%1").arg((int)shapes[i]->getPosition().width(), 5);
        QString height = QString("%1").arg((int)shapes[i]->getPosition().height(), 5);

        // Write the formatted data to the file
        out << QString(shapes[i]->getName()) << "\t" <<
            posX << "\t" <<
            posY << "\t" <<
            width << "\t" <<
            height << "\n";
    }

}

