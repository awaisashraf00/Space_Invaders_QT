#include "bullets.h"

BULLET::BULLET(QObject *parent, double x , double y) : m_bullet_x(x) , m_bullet_y(y)
{
    QObject::connect(&time,&QTimer::timeout,this,&BULLET::Ascend);
    time.start(16);
}