#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->count, SIGNAL(released()), this, SLOT(count()));
    connect(ui->reset, SIGNAL(released()), this, SLOT(reset()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::count()
{
    QPushButton *button = (QPushButton *)sender();


        countAmount++;
        qDebug() << "countamount:" << countAmount;  //debug tietoa
        QString countText = QString::number(countAmount);   //luodaan qstring tyyppinen muuttuja counttext, jonka avulla saadaan näytölle countamount.
        ui->screen->setText(countText); //printataan näytölle countamountti countTextin avulla



}

void MainWindow::reset()
{
    countAmount = 0;
    QPushButton *button = (QPushButton *)sender();

    qDebug() << "countamount:" << countAmount;
    QString countText = QString::number(countAmount);
    ui->screen->setText(countText);
}
