#include "enemy.h"

ENEMY::ENEMY(QObject *parent)
{
    opp_x = (rand() % 800) + enemie_size_x;
    opp_y = (rand() % 350) + enemie_size_y;
    emit x_changed();
    emit y_changed();
    QObject::connect(&time,&QTimer::timeout,this,&ENEMY::random_position);
    time.start(3000);
    QObject::connect(&positiontime,&QTimer::timeout,this,&ENEMY::updatePosition);
    time.start(16);
}

void ENEMY::updatePosition(){
    if(opp_x > rand_x && opp_y >rand_y){
        opp_x -= velocity;
        opp_y -= velocity;
    }else if(opp_x < rand_x && opp_y < rand_y){
        opp_x += velocity;
        opp_y += velocity;
    }else if(opp_x > rand_x && opp_y < rand_y){
        opp_x -= velocity;
        opp_y += velocity;
    }else if(opp_x < rand_x && opp_y > rand_y){
        opp_x += velocity;
        opp_y -= velocity;
    }
    qDebug()<<opp_x;
    qDebug()<<opp_y;
}


void ENEMY::random_position()
{
    opp_x = (rand() % 800) + enemie_size_x;
    opp_y = (rand() % 350) + enemie_size_y;
}
