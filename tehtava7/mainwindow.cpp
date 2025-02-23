#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timesPressed(0)
    , firstNum(0)
    , secondNum(0)
    , result(0)
{
    ui->setupUi(this);

    //tän harjotuksen toteuttamiseen on katsoin youtube tutoriaalia niin voi olla hieman erillä tavalla tehty.

    connect(ui->nolla, SIGNAL(released()), this, SLOT(digitPressed())); // Kytketään napit funktioihin
    connect(ui->yksi, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->kaksi, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->kolme, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->nelja, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->viisi, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->kuusi, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->seitseman, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->kahdeksan, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->yhdeksan, SIGNAL(released()), this, SLOT(digitPressed()));

    connect(ui->plus, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->miinus, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->jako, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->kerto, SIGNAL(released()), this, SLOT(binaryOperationPressed()));
    connect(ui->enter, SIGNAL(released()), this, SLOT(enter()));

    ui->plus->setCheckable(true);
    ui->miinus->setCheckable(true);
    ui->jako->setCheckable(true);
    ui->kerto->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitPressed()
{
    QPushButton *button = (QPushButton *)sender();

    if(opState)         //opstatella vaihdetaan kumpi operandi on käytössä
    {
        QString newop;
        firstNum = (ui->operand1->text() + button->text()).toDouble();
        newop = QString::number(firstNum, 'g', 15);
        ui->operand1->setText(newop);
        qDebug() << "firstNum:" << firstNum;
    }
    else
    {
        QString newop2;
        secondNum = (ui->operand2->text() + button->text()).toDouble();
        newop2 = QString::number(secondNum, 'g', 15);
        ui->operand2->setText(newop2);
        qDebug() << "secondNum:" << secondNum;
    }
}

void MainWindow::on_clear_released()        //nollataan kaikki tällä
{
    timesPressed = 0;
    firstNum = 0;
    secondNum = 0;
    result = 0;
    opState = true;
    ui->operand1->clear();
    ui->operand2->clear();
    ui->tulos->clear();
    ui->plus->setCheckable(true);
    ui->miinus->setCheckable(true);
    ui->jako->setCheckable(true);
    ui->kerto->setCheckable(true);
}


void MainWindow::enter()
{
    qDebug() << "timesPressed:" << timesPressed;
    opState = false;
    timesPressed++;
    if(timesPressed == 2)
    {
        qDebug() << "result:" << result;
        QString resultStr = QString::number(result);
        ui->tulos->setText(resultStr);
        timesPressed = 0;
        opState = true;
    }
}

void MainWindow::binaryOperationPressed()
{
    QPushButton *button = (QPushButton *)sender();

    firstNum = ui->operand1->text().toDouble();
    secondNum = ui->operand2->text().toDouble();

    button->setChecked(true);

    if (ui->plus->isChecked())
    {
        result = firstNum + secondNum;
        ui->plus->setCheckable(false);
        qDebug() << "result:" << result;
    }
    else if (ui->miinus->isChecked())
    {
        result = firstNum - secondNum;
        ui->miinus->setCheckable(false);
    }
    else if (ui->jako->isChecked())
    {
        result = firstNum / secondNum;
        ui->jako->setCheckable(false);
    }
    else if (ui->kerto->isChecked())
    {
        result = firstNum * secondNum;
        ui->kerto->setCheckable(false);
    }
}
