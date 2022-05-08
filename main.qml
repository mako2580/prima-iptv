import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import Process 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Prima IPTV")

    ProcessStarter {
        id: process
    }

    RowLayout{
        ColumnLayout {
            Button {
                text: "-5 sec"
                onClicked: process.changeTime(5)
            }

            Button {
                text: "-10 sec"
                onClicked: process.changeTime(10)
            }

            Button {
                text: "-30 sec"
                onClicked: process.changeTime(30)
            }

            Button {
                text: "-1 min"
                onClicked: process.changeTime(60)
            }

            Button {
                text: "-2 min"
                onClicked: process.changeTime(120)
            }

            Button {
                text: "-5 min"
                onClicked: process.changeTime(300)
            }

            Button {
                text: "-15 min"
                onClicked: process.changeTime(900)
            }

            Button {
                text: "-30 min"
                onClicked: process.changeTime(1800)
            }

            Button {
                text: "-1 hour"
                onClicked: process.changeTime(3600)
            }
        }

        ColumnLayout {
            Button {
                text: "+5 sec"
                onClicked: process.changeTime(-5)
            }

            Button {
                text: "+10 sec"
                onClicked: process.changeTime(-10)
            }

            Button {
                text: "+30 sec"
                onClicked: process.changeTime(-30)
            }

            Button {
                text: "+1 min"
                onClicked: process.changeTime(-60)
            }

            Button {
                text: "+2 min"
                onClicked: process.changeTime(-120)
            }

            Button {
                text: "+5 min"
                onClicked: process.changeTime(-300)
            }

            Button {
                text: "+15 min"
                onClicked: process.changeTime(-900)
            }

            Button {
                text: "+30 min"
                onClicked: process.changeTime(-1800)
            }

            Button {
                text: "+1 hour"
                onClicked: process.changeTime(-3600)
            }
        }
    }
}
