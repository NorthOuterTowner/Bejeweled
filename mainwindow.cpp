#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *imgLabel = new QLabel(this);
    imgLabel->resize(64,64);
    imgLabel->move(200,100);
    imgLabel->setPixmap(QPixmap(":/gemstone1.png").scaled(64,64));
}

MainWindow::~MainWindow()
{
    delete ui;
}
