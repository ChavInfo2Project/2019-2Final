#ifndef BALA_JUGADOR_H
#define BALA_JUGADOR_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QTimer>
#include "panel.h"
#include "player.h"
#include "wall.h"

//Clase de la bala de los jugadores
class Bala_jugador: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bala_jugador(int t);

public slots:
    void bullet_move_rigth();
    void bullet_move_left();

};

#endif // BALA_JUGADOR_H
