#pragma once

#include <QObject>
#include <QTimer>
#include <cstdint>

class PLAYER : public QObject
{
    Q_OBJECT

    Q_PROPERTY(uint32_t window_width READ window_width)
    Q_PROPERTY(uint32_t window_height READ window_height)

    Q_PROPERTY(uint32_t player_width READ player_width)
    Q_PROPERTY(uint32_t player_height READ player_height)

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

    double player_x_pos() const;
    double player_y_pos() const;

    void set_player_x_pos(double new_x);
    void set_player_y_pos(double new_y);

    Q_INVOKABLE void initializePosition(double x, double y);
    
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveLeft();
    Q_INVOKABLE void moveUp();


private slots:
    void thrust(){

    }

signals:
    void player_x_changed();
    void player_y_changed();

private:
    double window_to_object_ratio = 10.0;

// ##############################
// ##############################

    double fps {16.67};
    double gravity {0.5};
    uint32_t speed_xy {20};

    QTimer timing;

// ##############################
// ##############################

    uint32_t window_x = 800;
    uint32_t window_y = 800;

// ##############################
// ##############################

    uint32_t m_player_width = 80;
    uint32_t m_player_height = 80;
// ##############################
// ##############################

    double m_player_x_pos =(( window_x ) / 2) - (m_player_width/2);
    double m_player_y_pos = ((window_y)-(window_y)/3) + (m_player_width/2) ;

// ##############################
// ##############################
    uint32_t window_width() const;
    uint32_t window_height() const;
// ##############################
// ##############################

    uint32_t player_width() const;
    uint32_t player_height() const;
};