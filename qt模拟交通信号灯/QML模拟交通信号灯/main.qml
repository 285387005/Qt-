import QtQuick 2.0

Rectangle {
    width: 130
    height: 390
    color: "black"
    Rectangle {
        id: redLight
        x: 5
        y: 5
        width: 120
        height: 120
        radius: 60
        smooth: true
    }
    Rectangle {
        id: yellowLight
        x: redLight.x
        y: redLight.y+redLight.height+10
        width: redLight.width
        height: redLight.height
        radius: redLight.radius
        smooth: true
    }
    Rectangle {
        id: greenLight
        x: redLight.x
        y: yellowLight.y+yellowLight.height+10
        width: redLight.width
        height: redLight.height
        radius: redLight.radius
        smooth: true
    }

    states: [
        State{
            name: "stop"
            PropertyChanges {
                target: redLight; color: "red"
            }
            PropertyChanges {
                target: yellowLight; color: "lightslategrey"
            }
            PropertyChanges {
                target: greenLight; color: "lightslategrey"
            }
            PropertyChanges {
                target: time; interval: 10000
            }
        },
        State{
            name: "go"
            PropertyChanges {
                target: redLight; color: "lightslategrey"
            }
            PropertyChanges {
                target: yellowLight; color: "lightslategrey"
            }
            PropertyChanges {
                target: greenLight; color: "green"
            }
            PropertyChanges {
                target: time; interval: 8000
            }
        },
        State{
            name: "wait"
            PropertyChanges {
                target: redLight; color: "lightslategrey"
            }
            PropertyChanges {
                target: yellowLight; color: "yellow"
            }
            PropertyChanges {
                target: greenLight; color: "lightslategrey"
            }
            PropertyChanges {
                target: time; interval: 3000
            }
        }
    ]
    state: "stop"
    transitions: [
        Transition {
            from: "stop"
            to: "go"
            ParallelAnimation{
                PropertyAnimation{
                    target: redLight
                    properties: "color"
                    duration: 1000
                }
                PropertyAnimation{
                    target: greenLight
                    properties: "color"
                    duration: 1000
                }
            }
        },
        Transition {
            from: "go"
            to: "yellow"
            ParallelAnimation{
                PropertyAnimation{
                    target: greenLight
                    properties: "color"
                    duration: 1000
                }
                PropertyAnimation{
                    target: yellowLight
                    properties: "color"
                    duration: 1000
                }
            }
        },
        Transition {
            from: "yellow"
            to: "stop"
            ParallelAnimation{
                PropertyAnimation{
                    target: redLight
                    properties: "color"
                    duration: 1000
                }
                PropertyAnimation{
                    target: yellowLight
                    properties: "color"
                    duration: 1000
                }
            }
        }
    ]
    Timer {
        id: time
//        interval: 10000
        running: true;
        repeat: true;
        onTriggered: parent.state == "stop"? parent.state = "go" :(parent.state == "go"?parent.state = "wait":parent.state = "stop")
    }

    MouseArea {
        anchors.fill: parent
        onClicked: Qt.quit();
    }
}
