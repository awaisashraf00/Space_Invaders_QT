#include "bullets.h"

BULLET::BULLET(QObject *parent)
{
    QObject::connect(&time,&QTimer::timeout,this,&BULLET::Ascend);
    time.start(16);
}