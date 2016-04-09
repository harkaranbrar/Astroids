#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>

#include <QObject>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&New",this,SLOT(StartGame()));
    fileMenu->addAction("&Close",this,SLOT(close()));
    // ui->setupUi(this);

  //QObject::connect(on_pushButton_clicked, SIGNAL (released()), this, SLOT (StartGame()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartGame() {
    QGraphicsScene* scene = new QGraphicsScene();
    Player *ply = new Player;

    scene->addItem(ply);


    QGraphicsView* view = new QGraphicsView(scene);

    //to make a player focusable in scene
    ply->setFlag(QGraphicsItem::ItemIsFocusable);
    ply->setFocus();

    //to remove the scrol bar
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view.setRenderHint(QPainter::Antialiasing);
    //view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Asteroids"));
    view->resize(1024, 768);
    setCentralWidget(view);
    view->show();

    //fixes the size of the window
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    //play get center in window to get its position
    ply->setPos(view->width()/2,view->height() - ply->boundingRect().height());

}







void MainWindow::on_pushButton_clicked()
{

}

