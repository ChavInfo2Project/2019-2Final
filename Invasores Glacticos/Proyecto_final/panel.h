#ifndef PANEL_H
#define PANEL_H

#include <QWidget>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include "oponente.h"
#include "login.h"
#include "bala_jugador.h"
#include "player.h"
#include "wall.h"
#include "aliado_superior.h"
#include "aliado_inferior.h"

//Clase de el universo del juego
namespace Ui {
class Panel;
}

class Panel : public QWidget
{
    Q_OBJECT

public:
    explicit Panel(QWidget *parent = nullptr);
    ~Panel();    
    void setNombre1(const QString &value);
    void setNombre2(const QString &value);
    void keyPressEvent(QKeyEvent *event);
    void decrease(int t);

private slots:
    void on_Iniciar_clicked();
    void spawn_enemies();

private:
    Ui::Panel *ui;
    QString nombre1;
    QString nombre2;
    QGraphicsScene *scene;
    Player *p1;
    Player *p2;
    QList <Player *> jugadores;
    int vida1 = 200;
    int vida2 = 200;
    QTimer *timer_u;
    Aliado_superior *ally_1;
    Aliado_inferior *ally_2;
};

#endif // PANEL_H
