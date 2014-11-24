#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "peashooter.h"
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void drawBoard();
    ~MainWindow();

private slots:
    void on_seed_1_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *gv;
};

#endif // MAINWINDOW_H