import QtQuick
import QtQuick.Controls
import PLayerControls 1.0

ApplicationWindow {
    width: 800
    height: 800
    visible: true
    title: qsTr("Space invaders")

    PLAYER {
        id: battleship
    }

    Item {
        id: gameArea

        anchors.fill: parent
        focus: true

        Component.onCompleted: {
            forceActiveFocus()
        }

        Rectangle {
            id: playerRectangle
            width: battleship.player_width
            height: battleship.player_height

            x: battleship.player_x_pos
            y: battleship.player_y_pos
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

        
    }
}