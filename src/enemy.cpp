#include "enemy.h"

ENEMY::ENEMY(QObject *parent , uint8_t id) : QObject(parent) , enemie_id(id)
{
    opp_x = (rand() % 800 - enemie_size_x) + enemie_size_x;
    opp_y = (rand() % 350 - enemie_size_y) + enemie_size_y;
    emit x_changed();
    emit y_changed();
    QObject::connect(&time,&QTimer::timeout,this,&ENEMY::random_position);
    time.start(1000);
    QObject::connect(&positiontime,&QTimer::timeout,this,&ENEMY::updatePosition);
    positiontime.start(16);
    qDebug()<<id;
}
void ENEMY::updatePosition()
{
    if (opp_x < rand_x)
        opp_x += velocity;
    else if (opp_x > rand_x)
        opp_x -= velocity;

    if (opp_y < rand_y)
        opp_y += velocity;
    else if (opp_y > rand_y)
        opp_y -= velocity;

    emit x_changed();
    emit y_changed();
}

void ENEMY::random_position()
{
    rand_x = (rand() % 800) + enemie_size_x;
    rand_y = (rand() % 350) + enemie_size_y;
}
