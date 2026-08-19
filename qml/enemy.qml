import QtQuick

Rectangle {
    id: enemy

    required property var enemyObject

    width: 40
    height: 40

    color: "red"

    x: enemyObject.x
    y: enemyObject.y

}