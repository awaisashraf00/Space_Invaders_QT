import QtQuick.Controls
import QtQuick
import PLayerControls 1.0
import QtQuick.Layouts


ApplicationWindow {
    width: 800
    height: 800
    visible: true
    title : qsTr("Space invaders")

    PLAYER {
        id: battleship
    }

    Rectangle {
        id: playerRectangle

        width: battleship.player_width
        height: battleship.player_height
        
        battleship.initializePosition();

    }
    
    Keys.onRightPressed: {
        battleship.moveRight()
    }

    Keys.onLeftPressed: {
        battleship.moveLeft()
    }

    Keys.onUpPressed: {
        battleship.moveUp()
    }

    Keys.onDownPressed: {
        battleship.moveDown()
    }
}