#pragma once
#include "bullets.h"


class ENEMY : public QObject
{
    Q_OBJECT

    // Q_PROPERTY()

public:
    explicit ENEMY(QObject *parent = nullptr);
    double opp_x{0};
    double opp_y{0};
signals:
    void spawner();

private:
    QList<BULLET*> Fired_Rounds;
    uint16_t t_rounds = 0;
};