#include "player.h"

PLAYER::PLAYER(QObject *parent)
    : QObject(parent)
{
    QObject::connect(&timing,&QTimer::timeout,this,&PLAYER::thrust);
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
    if (m_player_x_pos == new_x)
        return;

    m_player_x_pos = new_x;

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
    if(m_player_x_pos + speed_xy < window_x - m_player_width) {set_player_x_pos(m_player_x_pos + speed_xy);}
    else{return;}
}

void PLAYER::moveLeft()
{
    if(m_player_x_pos - speed_xy > 0){set_player_x_pos(m_player_x_pos - speed_xy);}
    else{return;}
}

void PLAYER::moveUp()
{
    if(m_player_y_pos - speed_xy > 0 ) {set_player_y_pos(m_player_y_pos - speed_xy);}
    else{return;}
}
// ###########################################
// ###########################################

uint32_t PLAYER::window_width() const
{
    return window_x;
}

uint32_t PLAYER::window_height() const
{
    return window_y;
}

uint32_t PLAYER::player_width() const
{
    return m_player_width;
}

uint32_t PLAYER::player_height() const
{
    return m_player_height;
}
// ###########################################
// ###########################################
