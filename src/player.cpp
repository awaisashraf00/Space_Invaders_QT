#include "player.h"

PLAYER::PLAYER(QObject *parent)
    : QObject(parent)
{
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
    m_player_x_pos += 10;
}

void PLAYER::moveLeft()
{
    m_player_x_pos -= 10;
}

void PLAYER::moveDown()
{
    m_player_y_pos += 10;
}

void PLAYER::moveUp()
{
    m_player_y_pos -= 10;
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
