#pragma once

#include <bullets.h>
#include <enemy.h>
#include <QKeyEvent>
#include <control.h>
#include <cstdint>

class PLAYER : public QObject
{
    Q_OBJECT
    
    Q_PROPERTY(uint16_t window_width READ window_width)
    Q_PROPERTY(uint16_t window_height READ window_height)
    
    Q_PROPERTY(uint16_t player_width READ player_width CONSTANT)
    Q_PROPERTY(uint16_t player_height READ player_height CONSTANT)
    
    Q_PROPERTY(QString skin_patth READ skin_patth CONSTANT)
    
    Q_PROPERTY(QQmlListProperty<BULLET> bullets READ bullets NOTIFY bulletsChanged)
    Q_PROPERTY(QQmlListProperty<ENEMY> enemie READ enemie NOTIFY enemies_updated)
    Q_PROPERTY(QQmlListProperty<BULLET> enemie_bullets READ enemie_bullets NOTIFY bulletsChanged)
    
    Q_PROPERTY(double player_x_pos
        READ player_x_pos
        WRITE set_player_x_pos
        NOTIFY player_x_changed)
        
    Q_PROPERTY(double player_y_pos
        READ player_y_pos
        WRITE set_player_y_pos
        NOTIFY player_y_changed)

public:
    explicit PLAYER(QObject *parent = nullptr);
    
    double player_x_pos() const {return m_player_x_pos;};
    double player_y_pos() const {return m_player_y_pos;};
    
    void set_player_x_pos(double new_x);
    void set_player_y_pos(double new_y);
    
    uint16_t window_width() const {return window_x;};
    uint16_t window_height() const {return window_y;};
    
    uint16_t player_width() const {return m_player_width;};
    uint16_t player_height() const {return m_player_height;};
    
    QString skin_patth(){return(m_skin_patth);}; 

    
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void applyThrust();
    Q_INVOKABLE void fireBullet();

    QQmlListProperty<BULLET> bullets() const { return fire_arms.bullets(); }
    QQmlListProperty<ENEMY> enemie() const { return fire_arms.enemies(); }
    QQmlListProperty<BULLET> enemie_bullets() const { return fire_arms.enemie_bullets(); }

private:
    CONTROL fire_arms;

// ##############################
// ##############################

    double window_to_object_ratio = 10.0;

// ##############################
// ##############################

    QTimer timing;
    QTimer e_timer;
    QTimer enemy_bullet_timer;
// ##############################
// ##############################
    double fps {16.67};
    double gravity {0.5};
    double m_velocity_y {0.0};
    uint16_t speed_xy {20};
    
    double m_velocity_right_x {0.0};
    double m_velocity_left_x {0.0};


// ##############################
// ##############################

    uint16_t window_x = 800;
    uint16_t window_y = 800;

// ##############################
// ##############################

    uint16_t m_player_width = 80;
    uint16_t m_player_height = 80;
    QString m_skin_patth = "qrc:/player/pixels/rocket.png"; 
    // QString m_skin_patth = "qrc:/enemy/enemy1.png"; 

// ##############################
// ##############################

    double m_player_x_pos =(( window_x ) / 2) - (m_player_width/2);
    double m_player_y_pos = ((window_y)-(window_y)/3) + (m_player_width/2) ;

// ##############################
// ##############################


private slots:
    void Resistance();
    
signals:
    void bulletsChanged();
    void enemies_updated();
    void player_x_changed();
    void player_y_changed();
    void Bullet_Destroy();

};