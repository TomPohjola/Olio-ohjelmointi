#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

    if (timer){
        timer->stop();
        delete timer;
        timer = nullptr;
    }
}

void MainWindow::on_startgame_clicked()
{
    if (gameTime > 0 && timerrunning == false)
{
        setGameInfoText("game ongoing",10);
    p1Time = gameTime;
    p2Time = gameTime;
    currentPlayer = 1;

    ui->p1progressBar->setRange(0, gameTime);
    ui->p2progressBar->setRange(0, gameTime);

    ui->p1progressBar->setValue(gameTime);
    ui->p2progressBar->setValue(gameTime);

    if (timerrunning == false){
    timer = new QTimer(this);
    connect
            (timer,
            &QTimer::timeout,
            this,
            &MainWindow::updateProgressBar);

    timer->setInterval(1000); //1000ms eli yks sekunti.
    timer->start();
    timerrunning = true;
    }
}
}

void MainWindow::updateProgressBar()
{
    if (currentPlayer == 1){
    p1Time = p1Time-1;
    ui->p1progressBar->setValue(p1Time);
    }

    else if (currentPlayer == 2) {
    p2Time = p2Time-1;
    ui->p2progressBar->setValue(p2Time);
    }
    if (p1Time == 0 || p2Time == 0)
    {
        qDebug() << "test";
        timeout();
    }
}


void MainWindow::on_p1end_clicked()
{
    currentPlayer = 2;
    qDebug() << currentPlayer;
}


void MainWindow::on_p2end_clicked()
{
    currentPlayer = 1;
    qDebug() << currentPlayer;

}


void MainWindow::on_gametime1_clicked()
{
    if (gameState == false)
    {
        gameState = true;
        gameTime = 120;
    }
}


void MainWindow::on_gametime2_clicked()
{
    if (gameState == false)
    {
        gameState = true;
        gameTime = 300;
    }
}

void MainWindow::timeout()
{
    if (p1Time > p2Time){

    qDebug() << "player 1 won";
        setGameInfoText("Player 1 won! replay?", 10);

    currentPlayer = 1;
    gameState = false;
    timerrunning = false;
    timer->stop();
    delete timer;
    timer = nullptr;

    }
    if (p1Time < p2Time){

        qDebug() << "player 2 won";
        setGameInfoText("Player 2 won! replay?", 10);

        currentPlayer = 1;
        gameState = false;
        timerrunning = false;
        timer->stop();
        delete timer;
        timer = nullptr;
    }
}

void MainWindow::setGameInfoText(QString text, short fontSize)
{

    QString printti = text;
    ui->gameInfoText->setText(printti);

}


void MainWindow::on_stopgame_clicked()
{
    if (gameState)
    {
        setGameInfoText("game stopped",10);
        currentPlayer = 1;
        gameState = false;
        timerrunning = false;
        timer->stop();
        delete timer;
        timer = nullptr;
    }
}

