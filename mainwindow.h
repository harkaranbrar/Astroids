#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QStatusBar>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsItem>
#include <QPushButton>
//#include <QStyleOption>

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


public slots:
    void StartGame();

private slots:
    void on_PlayButton_clicked();
    void on_QuitButton_clicked();
    void on_New_triggered();
    void on_Close_triggered();
};

#endif // MAINWINDOW_H
