#include <control.h>

void CONTROL::Fire_Bullets(double player_x, double player_y)
{
    auto *round = new BULLET(this, player_x, player_y, t_rounds);
    QObject::connect(round, &BULLET::Destruct_Bullet, this, &CONTROL::Destroy_Bullets);
    Fired_Rounds.append(round);
    t_rounds++;
    emit bulletsChanged();
}

void CONTROL::Destroy_Bullets(uint16_t id)
{
    for (int i = 0; i < Fired_Rounds.size(); ++i)
    {
        if (Fired_Rounds[i]->bullet_id == id)
        {
            BULLET *b = Fired_Rounds.takeAt(i);
            b->deleteLater();
            emit bulletsChanged();
            return;
        }
    }
}

QQmlListProperty<BULLET> CONTROL::bullets() const
{
    return QQmlListProperty<BULLET>(const_cast<CONTROL*>(this), const_cast<QList<BULLET*>*>(&Fired_Rounds));
}

CONTROL::CONTROL(QObject *parent)
    : QObject(parent)
{
}
