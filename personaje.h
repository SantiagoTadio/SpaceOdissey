#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <QGraphicsPixmapItem>

using namespace std;


class personaje: public QGraphicsPixmapItem
{
public:
    personaje();
    string nombre;
    int vida;
};






#endif // PERSONAJE_H
