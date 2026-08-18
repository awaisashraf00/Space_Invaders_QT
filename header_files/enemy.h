#pragma once
#include "bullets.h"


class ENEMY : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double x READ get_x NOTIFY x_changed)
    Q_PROPERTY(double y READ get_y NOTIFY y_changed)
    
    Q_PROPERTY(uint8_t width READ get_width )
    Q_PROPERTY(uint8_t height READ get_height )

public:
    explicit ENEMY(QObject *parent = nullptr);
    double opp_x;
    double opp_y;
    
    double rand_x;
    double rand_y;

    double velocity{0.5};

    uint8_t enemie_size_x{20};
    uint8_t enemie_size_y{20};

    double get_x(){ return opp_x;};
    double get_y(){ return opp_y;};
    
    double get_width(){ return enemie_size_x;};
    double get_height(){ return enemie_size_y;};

    void updatePosition();

signals:
    void spawner();
    void x_changed();
    void y_changed();
private:
    QTimer time;
    QTimer positiontime;
    void random_position();

};