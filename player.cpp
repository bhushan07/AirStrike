#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>        //to respond to key press ed
#include "Bullet.h"
#include "Enemy.h"
#include "Health.h"
#include "Game.h"

extern Game * game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    // set bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/fire.mp3"));

    // set graphic
    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    // move the player left and right
    if (event->key() == Qt::Key_Left)
    {
        if (pos().x() > 0)
        setPos(x()-25,y());
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + 100 < 800)
        setPos(x()+25,y());
    }
    else if (event->key() == Qt::Key_Up)
    {
        if (pos().y() >300)
            setPos(x(),y()-25);
    }
    else if (event->key() == Qt::Key_Down)
    {
        if (pos().y() <480)
            setPos(x(),y()+25);
    }
    // shoot with the spacebar
    else if (event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet * bullet = new Bullet();
        bullet->setPos(x()+30,y());
        scene()->addItem(bullet);  //() after scene() return refference to the scene

        // play bulletsound
        if (bulletsound->state() == QMediaPlayer::PlayingState)//for repeated play sound
        {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }

    }
}

void Player::spawn()
{
    // create an enemy
    if(game->health->getHealth()>=0)
    {

    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
    }
}
