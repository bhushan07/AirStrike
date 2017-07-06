#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"
#include <typeinfo>
extern Game * game; // external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //  bullet graphics
    setPixmap(QPixmap(":/images/fire.png"));


    //connect a timer to move() the bullet every time
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move())); //after time out in generate signal


    timer->start(15);// start the timer
}

void Bullet::move()
{
    // list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i)
    {
         if (typeid(*(colliding_items[i])) == typeid(Enemy))
         {

            game->score->increase();

            blastsound = new QMediaPlayer();
            blastsound->setMedia(QUrl("qrc:/sounds/blast.mp3"));
             blastsound->play();

            // remove them from the scene
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to free memory
            delete colliding_items[i];
            delete this;


            return;
        }
    }

    // if there was no collision , move the bullet forward
    setPos(x(),y()-5);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
