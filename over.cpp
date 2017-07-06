#include "Over.h"

Over::Over(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    // set graphic
    setPixmap(QPixmap(":/images/over.png"));

    oversound = new QMediaPlayer();
    oversound->setMedia(QUrl("qrc:/sounds/gameover.mp3"));

    oversound->play();
}
