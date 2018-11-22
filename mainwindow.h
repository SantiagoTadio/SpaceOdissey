#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include <QMediaPlayer>
#include <QGraphicsScene>
#include <QList>
#include <QMap>
#include "personaje.h"
#include "proyectil.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void disparar(int Px, int Py, bool friendly);
    void keyPressEvent(QKeyEvent *event) ;
    void keyReleaseEvent(QKeyEvent *ev) ;
    void timeOutEvent();

public slots:
    void animar();
    void spawn();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* escena;

    QTimer * animation_timer, * spawn_timer;
    QMediaPlayer* musica, * disparo1, *disparo2;
    personaje * jugador1, *jugador2, *jefe;

    QList<proyectil*> proyectiles;
    QList<bala*> balas;
    QMap<int,bool> teclas;

};

#endif // MAINWINDOW_H
