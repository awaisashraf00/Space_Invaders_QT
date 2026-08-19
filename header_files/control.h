#pragma once
#include "bullets.h"
#include "enemy.h"

class CONTROL : public QObject
{
    Q_OBJECT
public:
    explicit CONTROL(QObject *parent = nullptr);

    void Fire_Bullets(double player_x, double player_y);
    void Spawn_Enemies();
    
    void Spawn_Random_Bullets();
    
    void Destroy_Bullets(uint16_t id);
    void Destroy_Enemie(uint16_t id);

    QQmlListProperty<BULLET> bullets() const;
    QQmlListProperty<ENEMY> enemies() const;
    QQmlListProperty<BULLET> enemie_bullets() const;
    void Check_for_Impact();

signals:
    void bulletsChanged();
    void enemies_updated();
private:
    QList<BULLET*> Fired_Rounds;
    QList<BULLET*> Enemies_Fired_Rounds;
    QList<ENEMY*> Enemies_alive;
    uint16_t t_rounds = 0;
    uint16_t t_enemies = 0;
};