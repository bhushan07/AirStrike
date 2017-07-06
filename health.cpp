#include "Health.h"
#include <QFont>
#include <QTimer>


Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the health
    health = 3;


    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3           //write the text
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",20));
}

void Health::decrease()
{
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2

}

int Health::getHealth()
{
    return health;
}

