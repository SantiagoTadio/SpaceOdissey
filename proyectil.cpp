#include "proyectil.h"
#include <QGraphicsRectItem>
#include <math.h>
#include <tgmath.h>

void proyectil::move(int posX, int posY, int posX2, int posY2)
{
    float Ax, Ay, angulo, rcuad, dx, dy;
    if(posX2!= 10000){
        dx= posX-x();  dy= posY-y();
        rcuad = (dx*dx)+(dy*dy);
        angulo = atan2(dy,dx);
        Ax+= (10000*cos(angulo))/rcuad;    Ay+= (10000*sin(angulo))/rcuad;

        dx= posX2-x();  dy= posY2-y();
        rcuad = (dx*dx)+(dy*dy);
        angulo = atan2(dy,dx);
        Ax+= (10000*cos(angulo))/rcuad;    Ay+= (10000*sin(angulo))/rcuad;
    }
    else{
        dx= posX-x();  dy= posY-y();
        rcuad = (dx*dx)+(dy*dy);
        angulo = atan2(dy,dx);
        Ax+= (10000*cos(angulo))/rcuad;    Ay+= (10000*sin(angulo))/rcuad;
    }
}
