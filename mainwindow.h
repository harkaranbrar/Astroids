#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QStyleOption>
<<<<<<< HEAD
=======
#include <QPushButton>
>>>>>>> harkaran

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    //QObject Macro to receive the signals.
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

<<<<<<< HEAD
public slots:
    void StartGame();

=======

public slots:
    void StartGame();
    void on_pushButton_clicked();

//private slots:
//    void on_pushButton_clicked();
>>>>>>> harkaran
};

#endif // MAINWINDOW_H
