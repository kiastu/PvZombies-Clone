#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gv = new QGraphicsScene(this);
    ui->gameView->setScene(gv);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawBoard(){

}

void MainWindow::on_seed_1_clicked()
{
    PeaShooter* ps = new PeaShooter();
    this->gv->addItem(ps);
}
