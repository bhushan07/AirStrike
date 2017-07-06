#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>        //widget used to visualise the scene
#include <QWidget>
#include <QGraphicsScene>       //container to contain all objects like player,enemy etc.
#include "Player.h"
#include "Score.h"
#include "Health.h"
#include "Over.h"
class Game: public QGraphicsView
{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;



};

#endif // GAME_H
