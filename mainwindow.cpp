#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QMenu* fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction("&New",this,SLOT(StartGame()));
    fileMenu->addAction("&Close",this,SLOT(close()));
    // ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::StartGame() {
    QGraphicsScene* scene = new QGraphicsScene();
    Player *ply = new Player;

    scene->addItem(ply);


    //to make a player focusable in scene
    ply->setFlag(QGraphicsItem::ItemIsFocusable);
    ply->setFocus();

    QGraphicsView* view = new QGraphicsView(scene);

    //view.setRenderHint(QPainter::Antialiasing);
    //view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Asteroids"));
    view->resize(1024, 768);
    setCentralWidget(view);
    view->show();
}



