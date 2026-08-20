import QtQuick

Rectangle {
    id:bullet
    property var bulletObject
    color: "transparent"
    width: 15
    height: 15

    x: bulletObject.x
    y: bulletObject.y
    
    Image {
        anchors.fill: parent
        source: "qrc:/bullet/pixels/bullet.png"
        fillMode: Image.PreserveAspectFit
    }
}