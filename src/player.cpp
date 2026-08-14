#include "player.h"

PLAYER::PLAYER(QObject *parent)
    : QObject(parent)
{
    QObject::connect(&timing,&QTimer::timeout,this,&PLAYER::Resistance);
    // QObject::connect(this,&PLAYER::player_x_changed,this,&PLAYER::moveRight);
    timing.start(fps);
}
// ###########################################
// ###########################################

double PLAYER::player_x_pos() const
{
    return m_player_x_pos;
}

double PLAYER::player_y_pos() const
{
    return m_player_y_pos;
}

// ###########################################
// ###########################################

void PLAYER::set_player_x_pos(double new_x)
{
    if(m_player_x_pos + m_velocity_right_x + m_player_width < window_x && m_player_x_pos - (-m_velocity_left_x) > 0){
        if (m_player_x_pos == new_x)
            return;
    
        m_player_x_pos = new_x;
    }else{
        qDebug()<<"you have reached the limit possible";
        return;
    }

    emit player_x_changed();
}

void PLAYER::set_player_y_pos(double new_y)
{
    if (m_player_y_pos == new_y)
        return;

    m_player_y_pos = new_y;

    emit player_y_changed();
}

// ###########################################
// ###########################################
void PLAYER::initializePosition(double x, double y)
{
    set_player_x_pos(x);
    set_player_y_pos(y);

}
// ###########################################
// ###########################################

void PLAYER::moveRight()
{    
    m_velocity_right_x = 10;
}

void PLAYER::moveLeft()
{
    m_velocity_left_x = -10;
}

void PLAYER::applyThrust()
{
    m_velocity_y = -20.0;
}

void PLAYER::Resistance()
{
    m_velocity_y += gravity;

    set_player_y_pos(m_player_y_pos + m_velocity_y);

    if (m_player_y_pos + m_player_height >= window_y)
    {
        set_player_y_pos(window_y - m_player_height);
        m_velocity_y = 0;
    }
    if(m_velocity_right_x > 0){
        m_velocity_right_x -= gravity;
        qDebug()<<m_velocity_right_x;

        set_player_x_pos(m_player_x_pos + m_velocity_right_x);
        
    }else if(m_velocity_left_x < 0){
        m_velocity_left_x += gravity;
        qDebug()<<m_velocity_left_x;
        set_player_x_pos( m_player_x_pos - -(m_velocity_left_x));
    }
}


// ###########################################
// ###########################################

uint16_t PLAYER::window_width() const
{
    return window_x;
}

uint16_t PLAYER::window_height() const
{
    return window_y;
}

uint16_t PLAYER::player_width() const
{
    return m_player_width;
}

uint16_t PLAYER::player_height() const
{
    return m_player_height;
}
// ###########################################
// ###########################################
