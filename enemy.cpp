#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> large int
#include "Game.h"
#include <QApplication>
#include <QThread>
extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //set random x position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // draw the enemyS
    setPixmap(QPixmap(":/images/enemy.png"));
    setTransformOriginPoint(50,50);
    setRotation(180);

    // make/connect a timer to move()
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));


    timer->start(30);    // start the timer
}

void Enemy::move()
{
    // move enemy down
    setPos(x(),y()+3);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600)
    {
        //decrease the health
        game->health->decrease();
        if(game->health->getHealth()<0) //to exit the game
        {
            over =new Over();
            scene()->addItem(over);

        }
        scene()->removeItem(this);

        delete this;
    }
}
