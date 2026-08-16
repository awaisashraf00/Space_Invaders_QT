#pragma once
#include<QObject>
#include<QList>
#include "bullets.h"


class CONTROL : public QObject
{
    Q_OBJECT
private:
    QList<BULLET*> Fired_Rounds;
    uint16_t t_rounds;
    void Destroy_Bullets();
public:
    explicit CONTROL(QObject *parent = nullptr);
public slots:
    void Fire_Bullets(double player_x , double player_y);
signals:
    void bullet_destroyed();
};