#ifndef PROYECTIL_H
#define PROYECTIL_H

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <iostream>

using namespace std;


class proyectil: public QGraphicsPixmapItem
{
private:
    float velX, velY;
public:
    string ID; // Indica la naturaleza del proyectil. ej: Bala, PowerUp(escudos, mejoras de vida, etc), asteroide...
    int valor; // Daño o beneficio que genera el proyectil. Puede ser positivo(vida extra) o negativo (balas)
    proyectil(string tipo);
    void move(int posX, int posY, int posX2=10000, int posY2=10000); // Modela el movimiento acelerado de los proyectiles hacia la(s) nave(s).
};

class bala: public proyectil,
            public QGraphicsRectItem
{
public:
    bool amistoso; // Determina la dirección de movimiento del proyectil: Hacia arriba para los amistosos y hacia abajo de lo contrario.
    bala(bool friendly);
    void move(); // Movimiento rectilíneo vertical uniforme
};

#endif // PROYECTIL_H
