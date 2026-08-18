import QtQuick

Rectangle {
    property var enemyObject
    
    width: enemyObject.width
    height: enemyObject.height

    x: enemyObject.x
    y: enemyObject.y
}