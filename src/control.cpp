#include <control.h>


CONTROL::CONTROL(QObject *parent)
    : QObject(parent){}


void CONTROL::Fire_Bullets(double player_x, double player_y)
{
    auto *round = new BULLET(this, player_x, player_y, t_rounds);
    QObject::connect(round, &BULLET::Destruct_Bullet, this, &CONTROL::Destroy_Bullets);
    // qDebug()<<Fired_Rounds.size();  
    Fired_Rounds.append(round);
    t_rounds++;
    emit bulletsChanged();
}

void CONTROL::Check_for_Impact()
{
    struct E_pos
    {
        double e_x_start;
        double e_x_end;
        double e_y_start;
        double e_y_end;
    };

    QList<uint16_t> bulletsToDestroy;
    QList<uint16_t> enemiesToDestroy;

    for (auto *enemy : Enemies_alive)
    {
        E_pos e_coords{
            enemy->opp_x,
            enemy->opp_x + enemy->enemie_size_x,
            enemy->opp_y,
            enemy->opp_y + enemy->enemie_size_y
        };

        for (auto *shot : Fired_Rounds)
        {
            if (shot->m_bullet_x >= e_coords.e_x_start &&
                shot->m_bullet_x <= e_coords.e_x_end &&
                shot->m_bullet_y >= e_coords.e_y_start &&
                shot->m_bullet_y <= e_coords.e_y_end)
            {
                bulletsToDestroy.append(shot->bullet_id);
                enemiesToDestroy.append(enemy->enemie_id);

                break;
            }
        }
    }

    for (uint16_t id : bulletsToDestroy)
    {
        Destroy_Bullets(id);
    }

    for (uint16_t id : enemiesToDestroy)
    {
        Destroy_Enemie(id);
    }
}

void CONTROL::Spawn_Enemies()
{
    if(t_enemies>10){
        return;
    }
    qDebug()<<"Enemie spawner called";  
    auto *enemy = new ENEMY(this,t_enemies);
    QObject::connect(enemy, &ENEMY::Destruct_Enemie, this, &CONTROL::Destroy_Enemie);
    Enemies_alive.append(enemy);
    t_enemies++;
    emit enemies_updated();
}

void CONTROL::Spawn_Random_Bullets()
{
    for(auto *e:Enemies_alive){
        uint8_t guess = std::ceil(rand()%4);
        
        auto enemie_x = (e->opp_x + e->enemie_size_x/2);
        auto enemie_y = (e->opp_y + e->enemie_size_y);

        if(guess == 3){
            auto *round = new BULLET(this, enemie_x, enemie_y, t_rounds, false);
            QObject::connect(round, &BULLET::Destruct_Bullet, this, &CONTROL::Destroy_Bullets);

            Enemies_Fired_Rounds.append(round);
            t_rounds++;
            emit bulletsChanged();
        }
    }
}

void CONTROL::Destroy_Enemie(uint16_t id)
{
    // qDebug()<<"called destroy" ;
    t_enemies--;
    for (int i = 0; i < Enemies_alive.size(); ++i)
    {
        if (Enemies_alive[i]->enemie_id == id)
        {
            ENEMY *b = Enemies_alive.takeAt(i);
            emit enemies_updated();
            b->deleteLater();
            return;
        }
    }

}
void CONTROL::Destroy_Bullets(uint16_t id)
{
    // qDebug()<<"called destroy" ;
    for (int i = 0; i < Fired_Rounds.size(); ++i)
    {
        if (Fired_Rounds[i]->bullet_id == id)
        {
            BULLET *b = Fired_Rounds.takeAt(i);
            emit bulletsChanged();
            b->deleteLater();
            return;
        }
    }

    for (int i = 0; i < Enemies_Fired_Rounds.size(); ++i)
    {
        if (Enemies_Fired_Rounds[i]->bullet_id == id)
        {
            BULLET *b = Enemies_Fired_Rounds.takeAt(i);
            emit bulletsChanged();
            b->deleteLater();
            return;
        }
    }
}

QQmlListProperty<BULLET> CONTROL::bullets() const
{
    return QQmlListProperty<BULLET>(const_cast<CONTROL*>(this), const_cast<QList<BULLET*>*>(&Fired_Rounds));
}

QQmlListProperty<BULLET> CONTROL::enemie_bullets() const
{
    return QQmlListProperty<BULLET>(const_cast<CONTROL*>(this), const_cast<QList<BULLET*>*>(&Enemies_Fired_Rounds));
}

QQmlListProperty<ENEMY> CONTROL::enemies() const
{
    return QQmlListProperty<ENEMY>(const_cast<CONTROL*>(this), const_cast<QList<ENEMY*>*>(&Enemies_alive));
}

