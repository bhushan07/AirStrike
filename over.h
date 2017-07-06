#ifndef OVER_H
#define OVER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Over:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Over(QGraphicsItem * parent=0);
private:
    QMediaPlayer * oversound;

};

#endif // OVER_H
