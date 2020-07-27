#include "bala_aliado_superior.h"
#include <QDebug>

extern Panel *p;//Panel del juego

//Bala del aliado superior izquierdo
Bala_aliado_superior::Bala_aliado_superior(double px, double py)
{
    posx=px;
    posy=py;
    vel=60.0;
    ang=45;
    setRect(posx,posy,20,20);
    b_a_timer = new QTimer();
    connect(b_a_timer,SIGNAL(timeout()),this,SLOT(move()));

    b_a_timer->start(50);
}

//Funcion para detener el movimiento de la bala
void Bala_aliado_superior::detener()
{
    b_a_timer->stop();
}

//Funcion de movimiento: Parabolico + Gravitacional
void Bala_aliado_superior::move()
{
    vel_x=vel*cos(ang);
    vel_y=vel*sin(ang)-g*delta;
    ang=atan2(vel_y,vel_x);
    vel= sqrt(vel_x*vel_x+ vel_y*vel_y);
    posx=posx+vel*cos(ang)*delta;
    posy=posy+vel*sin(ang)*delta-(0.5*g*delta*delta);
    setPos(posx,-posy);
    //qDebug()<< this->x()<<"and"<<this->y();
    QList <QGraphicsItem *> colliding_items = collidingItems();
    for (int i=0, n=colliding_items.size(); i < n; i++){
        if (typeid (*(colliding_items[i])) == typeid (Player)){
           //Cuando las balas impactan, quitan vida y desaparecen
           p->decrease(1);
           scene()->removeItem(this);
           delete this;
        }
    }
    //Si la bala se sale de la escena se elimina
    if (pos().y() > 400){
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"se elimino la bala del aliado 1";
    }
}

