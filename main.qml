import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.0

Window {

    property string icon: "qrc:/resources/icon.ico"
    Connections
    {
        target: control

        onNewImage: {
            icon = filename
            console.log("icon",icon)
        }
    }
    minimumWidth: 300
    minimumHeight: 300
    visible: true
    title: qsTr("astcViewer")
    color: "black"

    Image {
        id: astc
        x:0
        y:0
        anchors.centerIn: parent
        source: icon
        rotation:  180
        mirror: true
    }
    Button
    {
        id: nextButton
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        width: 50
        height: 50

        background: Rectangle {
            color: "black"
        }
         text: "Next"
        onClicked: control.nextImage()
    }
    Button
    {
        id: prevButton
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        width: 50
        height: 50

        background: Rectangle {
            color: "black"
        }
         text: "Previuos"
        onClicked: control.prevImage()
    }
}
