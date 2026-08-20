import QtQuick

Item {
    id: enemy

    required property var enemyObject

    width: 40
    height: 40

    x: enemyObject.x
    y: enemyObject.y

    Image {
        anchors.fill: parent
        source: enemy.enemyObject.skin_path
        fillMode: Image.PreserveAspectFit
    }
}