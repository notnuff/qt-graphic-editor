#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editor.h"
#include "mytable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setCorrectChecking(int shape);
private slots:
    void on_line_edit_triggered(bool checked);
    void on_rect_edit_triggered(bool checked);
    void on_ellipse_edit_triggered(bool checked);
    void on_dot_edit_triggered(bool checked);
    void on_action_Toolbar_triggered();
    void on_dotButton_clicked(bool checked);
    void on_lineButton_clicked(bool checked);
    void on_ellipseButton_clicked(bool checked);
    void on_rectButton_clicked(bool checked);

    void on_dumbbellButton_clicked(bool checked);

    void on_dumbbell_edit_triggered(bool checked);

    void on_cubeButton_clicked(bool checked);

    void on_cube_edit_triggered(bool checked);

    void on_action_triggered();

    void on_action_2_triggered();

private:
    Ui::MainWindow *ui;
    SingletonEditor *editor;
    MyTable *table;


};
#endif // MAINWINDOW_H
