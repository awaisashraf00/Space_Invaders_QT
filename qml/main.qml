import QtQuick
import QtQuick.Controls
import PLayerControls 1.0

ApplicationWindow {
    width: 800
    height: 800
    visible: true
    title: qsTr("Space invaders")

    background: Rectangle {
        anchors.fill: parent

        gradient: Gradient {
            GradientStop { position: 0.0; color: "darkblue" }
            GradientStop { position: 1.0; color: "black" }
        }
    }

    PLAYER {
        id: battleship
    }

    Item {
        id: gameArea

        focus: true

        Rectangle {
            id: playerRectangle
            color: "transparent"

            width: battleship.player_width
            height: battleship.player_height

            x: battleship.player_x_pos
            y: battleship.player_y_pos

            Image {
                id: playerImage

                source: battleship.skin_patth

                anchors.fill: parent
                fillMode: Image.PreserveAspectFit
            }

            AnimatedImage {
                id: thrust

                source: "qrc:/player/pixels/thruster.gif"

                width: 30
                height: 30

                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: playerImage.bottom

                playing: true
                // loops: Animation.Infinite
            }
        }

        Repeater {
            model: battleship.bullets

            delegate: Bullet {
                required property var modelData
                bulletObject: modelData
            }
        }

        Repeater {
            model: battleship.enemie_bullets

            delegate: Bullet {
                required property var modelData
                bulletObject: modelData
            }
        }

        Repeater {
            model: battleship.enemie
            delegate: Enemy {
                required property var modelData
                enemyObject: modelData
            }
        }

        Keys.onRightPressed: function(event) {
            battleship.moveRight()
            event.accepted = true
        }

        Keys.onLeftPressed: function(event) {
            
            battleship.moveLeft()
            event.accepted = true
        }

        Keys.onUpPressed: function(event) {
            
            battleship.applyThrust()
            event.accepted = true
        }

        Keys.onSpacePressed: function(event) {
            battleship.fireBullet()
            event.accepted = true
        }

        Component.onCompleted: {
            forceActiveFocus()
            thrust.playing = true
        }
    }
}