#include "bullets.h"

BULLET::BULLET(QObject *parent, double x, double y, uint16_t id , bool player_bullet)
    : QObject(parent), m_bullet_x(x), m_bullet_y(y), bullet_id(id)
{
    if (player_bullet)
    {
        QObject::connect(&time, &QTimer::timeout, this, &BULLET::Ascend);
    }
    else
    {
        QObject::connect(&time, &QTimer::timeout, this, &BULLET::Descend);
    }
    time.start(16);
}

void BULLET::Ascend()
{
    if(m_bullet_y > 0){
        m_bullet_y += m_bullet_velocity;
        emit bullet_y_changed();
    }else{
        emit Destruct_Bullet(bullet_id);
    }
}

void BULLET::Descend()
{
    if(m_bullet_y < 795){
        m_bullet_y -= m_bullet_velocity;
        emit bullet_y_changed();
    }else{
        emit Destruct_Bullet(bullet_id);
    }
}