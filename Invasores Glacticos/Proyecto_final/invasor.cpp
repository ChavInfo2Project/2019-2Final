#include "invasor.h"
#include <QDebug>

//Aliado invasor
Invasor::Invasor()
{
    //Dibuja el invasor
   //setRect(0,0,30,60);
   setPixmap(QPixmap(":/images/Aliado Invasor.png"));

   timer = new QTimer();
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));

   timer->start(1000);
}

//Funcion para detener el movimiento del invasor y su bala
void Invasor::detener()
{
    timer->stop();
    bala->detener();
}

//Funcion para el movimiento; va de abajo a arriba
void Invasor::move()
{
    //Se mueve y dispara
    setPos(x(),y()-60);
    bala = new Proyectil_invasor(this->x()-20, this->y());
    //bala->setPixmap(QPixmap(":/images/Bala pasiva invasor.png"));
    scene()->addItem(bala);
    //Se elimina el objeto cuando sale de los limites de la escena
    if (pos().y()<40.0){
        scene()->removeItem(this);
        delete this;
    }
}
