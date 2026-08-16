#include "control.h"

void CONTROL::Fire_Bullets(double player_x , double player_y)
{
    BULLET *round = (BULLET*)malloc(sizeof(BULLET)); 
    round->m_bullet_x = x;
    round->m_bullet_y = y;
    Fired_Rounds.append(round);
    engine.rootContext()->setContextProperty("ammo", Fired_Rounds[round]);    
    t_round++;
}

void CONTROL::Destroy_Bullets()
{
    
    BULLET *b = Fire_Bullets.takeAt(0);
    b->deleteLater();
    t_round--;
}

explicit CONTROL::CONTROL(QObject *parent)
{
    QObject::connect()
}