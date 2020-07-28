#ifndef PROYECTIL_INVASOR_H
#define PROYECTIL_INVASOR_H

#include <QObject>
#include <QGraphicsRectItem>
#include <math.h>
#include <QTimer>
#include "panel.h"

//Clase de la bala del invasor
class Proyectil_invasor: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Proyectil_invasor(double px, double py);
    void detener();

public slots:
    void move();

private:
    double fi, w, alfa, delta, posx, posy;
    QTimer *b_a_timer;
};

#endif // PROYECTIL_INVASOR_H
