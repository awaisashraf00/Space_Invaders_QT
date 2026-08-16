#pragma once 
#include<QObject>
#include<QTimer>

class BULLET : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double x READ bullet_x NOTIFY bullet_x_changed)
    Q_PROPERTY(double y READ bullet_y NOTIFY bullet_y_changed)


public:
    explicit BULLET(QObject *parent = nullptr , double x , double y);

    double bullet_x() const {return m_bullet_x;};
    double bullet_y() const {return m_bullet_y;};

private:
    QTimer time;
    double m_bullet_x = 0;
    double m_bullet_y = 0;
    double m_bullet_velocity = -10;

signals:
    void bullet_x_changed();
    void bullet_y_changed();

public slots:
    void Ascend(){m_bullet_y+=m_bullet_velocity;};
};