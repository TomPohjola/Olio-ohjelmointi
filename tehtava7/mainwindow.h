#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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

private:
    int timesPressed;
    double firstNum;
    double secondNum;
    double result;

    bool opState = true;

private slots:
    void digitPressed();
    void on_clear_released();
    void enter();
    void binaryOperationPressed();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
