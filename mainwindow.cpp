#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personaje.h"
#include "proyectil.h"
#include <QGraphicsRectItem>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    singlePlayer = false;

    jugador1 = new personaje("yo");
    jugador2 = new personaje("otro");
    jefe = new personaje("isaza");

    escena = new QGraphicsScene;
    escena->setSceneRect(0,0,800,600);
    ui->graphicsView->setScene(escena);
    ui->graphicsView->setFixedSize(800,600);


    animation_timer = new QTimer;
    spawn_timer = new QTimer;
    boss_shots_timer = new QTimer;
    timerOut_timer = new QTimer;

    timerOut_timer->start(50);
    connect(timerOut_timer,SIGNAL(timeout()),this,SLOT(timeOutEvent()));

    animation_timer->start(100);
    connect(animation_timer,SIGNAL(timeout()),this,SLOT(animar()));

    musica = new QMediaPlayer;
    disparo1 = new QMediaPlayer;
    disparo2 = new QMediaPlayer;

    escena->addItem(jugador1);

    escena->addItem(jugador2);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    teclas[event->key()]=true;
}

void MainWindow::keyReleaseEvent(QKeyEvent *ev)
{
    teclas[ev->key()]=false;
}

void MainWindow::timeOutEvent()
{
   // jugador1->setPos(x()+2,y());

    if(teclas[Qt::Key_Left]){
        if(jugador1->px>5){
            jugador1->moveHorizon(-5);
        }

    }
    if(teclas[Qt::Key_Right]){
        if(jugador1->px<715){
            jugador1->moveHorizon(5);
        }
    }
    if(teclas[Qt::Key_Space]){
        bala* balita = new bala;
        balita->setPos(jugador1->px+37,jugador1->py-15);
        escena->addItem(balita);
        balas.push_back(balita);
    }


    if(!singlePlayer){
        if(teclas[Qt::Key_A]){
            if(jugador2->x()>5) jugador2->setPos(x()-5,y());
        }
        if(teclas[Qt::Key_D]){
            if(jugador2->x()<715) jugador2->setPos(x()+5,y());
        }
        if(teclas[Qt::Key_Control]){
            bala* balita = new bala;
            balita->setPos(jugador2->x()+37,jugador2->y()-15);
            balas.push_back(balita);
        }
    }


}

void MainWindow::animar(){
    for(int i=0, n=balas.size(); i<n;i++){
        balas.at(i)->move();
    }
}


