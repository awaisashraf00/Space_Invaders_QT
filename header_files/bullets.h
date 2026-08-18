#pragma once

#include <cstdlib> 
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QList>
#include <QQmlListProperty>
#include <cstdint>

class BULLET : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double x READ bullet_x NOTIFY bullet_x_changed)
    Q_PROPERTY(double y READ bullet_y NOTIFY bullet_y_changed)

public:
    explicit BULLET(QObject *parent = nullptr, double x = 0.0, double y = 0.0, uint16_t id = 0);

    double bullet_x() const { return m_bullet_x; }
    double bullet_y() const { return m_bullet_y; }

    double m_bullet_x = 0.0;
    double m_bullet_y = 0.0;
    uint16_t bullet_id = 0;

signals:
    void bullet_x_changed();
    void bullet_y_changed();
    void Destruct_Bullet(uint16_t id);

public slots:
    void Ascend()
    {
        if(m_bullet_y > 0){
            m_bullet_y += m_bullet_velocity;
            emit bullet_y_changed();
        }else{
            emit Destruct_Bullet(bullet_id);
        }
    }

private:
    QTimer time;
    double m_bullet_velocity = -10.0;
};