#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLCDNumber>


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
public slots:
    void startPlantTimer();
    void decrementAll();
    void getSun();
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
    QTimer* timer;
    int selected;//Current selected plant index
    int isAvailable[8];//holds current time remaining before planting.
    int cooldown[8];
    QLCDNumber *lcds[8];
    enum{GAMESPEED = 500};
    int sunStore;
};

#endif // MAINWINDOW_H
