#ifndef BULLET_DEFENSOR_H
#define BULLET_DEFENSOR_H

#include <QObject>
#include <QGraphicsRectItem>
#include <math.h>
#include <QTimer>
#include <QMediaPlayer>
#include "panel.h"

//Clase de la bala del defensor
class Bullet_defensor: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Bullet_defensor(double px, double py);
    void detener();

public slots:
    void move();

private:
    //Atributos para el movimiento parabolico y gravitacional
    double g = 9.8;
    double delta = 0.1;
    double posy, posx, ang, vel, vel_x, vel_y;
    QTimer *bala_timer;
    QMediaPlayer *sonido_choque;
};

#endif // BULLET_DEFENSOR_H