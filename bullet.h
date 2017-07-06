#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>
class Bullet: public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT  //macro to handle signals
public:
    Bullet(QGraphicsItem * parent=0);
public slots:
    void move();
private:
    QMediaPlayer * blastsound;
};

#endif // BULLET_H
