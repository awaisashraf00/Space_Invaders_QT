#include "player.h"

PLAYER::PLAYER(QObject *parent)
    : QObject(parent)
{
    QObject::connect(&timing, &QTimer::timeout, this, &PLAYER::Resistance);
    QObject::connect(&timing,&QTimer::timeout,&fire_arms,[&](){fire_arms.Check_for_Impact(m_player_x_pos,m_player_y_pos);});
    QObject::connect(&e_timer,&QTimer::timeout,&fire_arms,&CONTROL::Spawn_Enemies);
    QObject::connect(&enemy_bullet_timer, &QTimer::timeout, &fire_arms, &CONTROL::Spawn_Random_Bullets);
    timing.start(fps);
    e_timer.start(3000);
    enemy_bullet_timer.start(1000);
    QObject::connect(&fire_arms, &CONTROL::bulletsChanged, this, &PLAYER::bulletsChanged);
    QObject::connect(&fire_arms,&CONTROL::enemies_updated,this,&PLAYER::enemies_updated);
    // QObject::connect(&timing, &QTimer::timeout, th is, [](){});
}
// ###########################################
// ###########################################

void PLAYER::set_player_x_pos(double new_x)
{
    double max_x = window_x - m_player_width;

    if (new_x < 0){
        m_velocity_left_x = 0;
        new_x = 0;
    }
    if (new_x > max_x){
        new_x = max_x;
        m_velocity_right_x = 0;
    }
    if (m_player_x_pos == new_x){
    
        return;
    }

    m_player_x_pos = new_x;
    emit player_x_changed();
}

void PLAYER::set_player_y_pos(double new_y)
{
    if(new_y > window_y/2){
        if (m_player_y_pos == new_y){
            return;
        }
        m_player_y_pos = new_y;
        emit player_y_changed();
    }else{
        m_velocity_y = 0;
    }
}


// ###########################################
// ###########################################

void PLAYER::fireBullet()
{
    fire_arms.Fire_Bullets(m_player_x_pos + m_player_width /2 ,m_player_y_pos);
}


// ###########################################
// ###########################################

void PLAYER::moveRight()
{    
    m_velocity_left_x = 0;
    m_velocity_right_x = 20;
}

void PLAYER::moveLeft()
{
    m_velocity_right_x = 0;
    m_velocity_left_x = -20;
}

void PLAYER::applyThrust()
{
    m_velocity_y = -15.0;
}

void PLAYER::Resistance()
{
    m_velocity_y += gravity;

    set_player_y_pos(m_player_y_pos + m_velocity_y);

    if (m_player_y_pos + m_player_height >= window_y)
    {
        set_player_y_pos(window_y - m_player_height);
        m_velocity_y = 0;

    }else if(m_player_y_pos + m_velocity_y <= 0){
        set_player_y_pos(0);
        m_velocity_y = 0;
    }
    if(m_velocity_right_x > 0){
        m_velocity_right_x -= gravity;
    
        set_player_x_pos(m_player_x_pos + m_velocity_right_x);

        
    }else if(m_velocity_left_x < 0){
        m_velocity_left_x += gravity;
    
        set_player_x_pos( m_player_x_pos + m_velocity_left_x);
    }
}

