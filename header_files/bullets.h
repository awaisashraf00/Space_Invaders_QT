#pragma once 
#include<QObject>
#include<QTimer>


class BULLET:QObject
{
    Q_OBJECT

    Q_PROPERTY(uint16_t length READ bullet_size_x)
    Q_PROPERTY(uint16_t wideness READ bullet_size_y)
    Q_PROPERTY(uint16_t velocity READ velocity_of_bullet)

private:

    uint16_t m_bullet_width;
    uint16_t m_bullet_height;
    uint16_t m_bullet_position;
    uint16_t m_bullet_velocity{-10};
    void Ascend() const {m_bullet_position + m_bullet_height;};
    
public:
    QTimer time;
    uint16_t bullet_size_x() const {return m_bullet_height;};
    uint16_t bullet_size_y() const {return m_bullet_width;};
    uint16_t velocity_of_bullet() const {return m_bullet_width;};
    
    explicit BULLET(QObject *parent = nullptr);

signals:


};