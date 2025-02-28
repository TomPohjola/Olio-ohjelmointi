#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_startgame_clicked();
    void updateProgressBar();
    void on_p1end_clicked();
    void on_p2end_clicked();
    void on_gametime1_clicked();
    void on_gametime2_clicked();
    void on_stopgame_clicked();


public slots:

    void timeout();

private:
    Ui::MainWindow *ui;

    short p1Time;
    short p2Time;
    short currentPlayer = 1;
    short gameTime = 0;
    bool gameState = false; //lisäsin sitä varten ettei useampi timeri pyöri yhtäaikaa ja
    bool timerrunning = false;// jotta voin estää startin painamisen useasti.

    QTimer *timer = nullptr;

    void setGameInfoText(QString,short);

};
#endif // MAINWINDOW_H
