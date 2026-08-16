#include "bullets.h"

BULLET::BULLET(QObject *parent, double x, double y, uint16_t id)
    : QObject(parent), m_bullet_x(x), m_bullet_y(y), bullet_id(id)
{
    QObject::connect(&time, &QTimer::timeout, this, &BULLET::Ascend);
    time.start(16);
}