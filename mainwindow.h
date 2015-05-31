#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void print();
    void DOWN();
    void UP();
    void RIGHT();
    void LEFT();
    void num();
    void keyPressEvent(QKeyEvent *event);
    void GAMEOVER();

    void TEST_left();
    void TEST_right();
    void TEST_up();
    void TEST_down();
    void rclicked();
    void WIN();
    void AWIN();
    //void quit();
public slots:
    void setzero();
    void undo();
    void setzero_no();
    void Auto();
private slots:
    //void on_restart_clicked();

    //void on_restart_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    int block[4][4];
    int undoblock[4][4];
    int x, r;
    int score;
    //QPushButton *PushButton;
};

#endif // MAINWINDOW_H
