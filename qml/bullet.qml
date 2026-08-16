import QtQuick

Item {
    required property var modelData

    width: 5
    height: 15

    x: modelData.bullet_x
    y: modelData.bullet_y

    Rectangle {
        anchors.fill: parent
        color: "red"
    }
}