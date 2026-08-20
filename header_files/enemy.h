#pragma once
#include "bullets.h"
#include <qfile.h>


class ENEMY : public QObject
{
    Q_OBJECT

    Q_PROPERTY(double x READ get_x NOTIFY x_changed)
    Q_PROPERTY(double y READ get_y NOTIFY y_changed)
    
    Q_PROPERTY(uint8_t width READ get_width )
    Q_PROPERTY(uint8_t height READ get_height )
    Q_PROPERTY(QString skin_path READ get_skin_path CONSTANT)

public:
    explicit ENEMY(QObject *parent = nullptr , uint8_t id = 0 , uint8_t skin = 0);
    double opp_x;
    double opp_y;
    
    double rand_x;
    double rand_y;

    double velocity{1.5};

    uint8_t enemie_size_x{40};
    uint8_t enemie_size_y{40};
    
    uint8_t enemie_id{0};
    
    double get_x(){ return opp_x;};
    double get_y(){ return opp_y;};
    
    double get_width(){ return enemie_size_x;};
    double get_height(){ return enemie_size_y;};
    QString get_skin_path(){ return skin_path; };

    void updatePosition();

signals:
    void spawner();
    void Destruct_Enemie(uint16_t id);
    void x_changed();
    void y_changed();
    void enemies_updated();
private:
    QTimer time;
    QTimer positiontime;
    void random_position();
    QHash<int,QString> skin_map = {
        {1,"qrc:/enemy/enemy1.png"},
        {2,"qrc:/enemy/enemy2.png"},
        {3,"qrc:/enemy/enemy3.png"},
        {4,"qrc:/enemy/enemy4.png"},
        {5,"qrc:/enemy/enemy5.png"},
    };
    QString skin_path;

};