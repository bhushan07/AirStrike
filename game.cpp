#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>



Game::Game(QWidget *parent)
{
   // create the scene
   scene = new QGraphicsScene();
   scene->setSceneRect(0,0,800,600); // scene 800x600 instead of infinity by infinity (default)
   setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

   //  newly created scene to visualize (since Game is a QGraphicsView Widget,it can be used to visualize scenes

   setScene(scene);
   setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   setFixedSize(800,600);   //view is set to fixed size

   // create the player
   player = new Player();
   player->setPos(400,490);            // in the middle bottom of screen

   player->setFlag(QGraphicsItem::ItemIsFocusable);    // make the player focusable and focusable makes object to respond to keyevent

   player->setFocus();                 // set it to be the current focus
   scene->addItem(player);             // add the player to the scene

   // create the score/health
   score = new Score();
   scene->addItem(score);
   health = new Health();
   health->setPos(health->x(),health->y()+25);
   scene->addItem(health);

   // spawn enemies
   QTimer * timer = new QTimer();
   QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
   timer->start(2000);

   // play background music
   QMediaPlayer * music = new QMediaPlayer();
   music->setMedia(QUrl("qrc:/sounds/bgs.mp3"));
   music->play();

   show();
}
