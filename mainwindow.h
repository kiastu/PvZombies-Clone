#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "peashooter.h"
#include "sunflower.h"
#include "cherrybomb.h"
#include "wallnut.h"
#include "potatomine.h"
#include "snowpea.h"
#include "chomper.h"
#include "repeater.h"

#include "board.h"

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
    void on_seed_2_clicked();
    void on_seed_3_clicked();
    void on_seed_4_clicked();
    void on_seed_5_clicked();
    void on_seed_6_clicked();
    void on_seed_7_clicked();
    void on_seed_8_clicked();

private:
    Board *game;//instance of QGraphicsView
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
