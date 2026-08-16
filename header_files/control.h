#pragma once
#include "bullets.h"


class BULLET;

class CONTROL : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QQmlListProperty<BULLET> bullets
               READ bullets
               NOTIFY bulletsChanged)

public:
    explicit CONTROL(QObject *parent = nullptr);

    void Fire_Bullets(double player_x, double player_y);
    void Destroy_Bullets(uint16_t id);

    QQmlListProperty<BULLET> bullets() const;

signals:
    void bulletsChanged();

private:
    QList<BULLET*> Fired_Rounds;
    uint16_t t_rounds = 0;
};