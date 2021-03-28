import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.0

Window {

    property string icon: ""
       Connections
       {
          target: control

          onNewImage: {
               icon = filename
               console.log("icon",icon)
           }
       }

    width: astc.width
    height: astc.height
    visible: true
    title: qsTr("astcViewer")

    Image {
        id: astc
        x:0
        y:0
        source: icon
        rotation:  180
        mirror: true
    }
    Button
    {
               id: mainButton
               anchors.centerIn: parent
               text: "button"
               onClicked: control.nextImage()
   }
}
