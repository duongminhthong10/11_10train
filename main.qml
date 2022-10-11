import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.VirtualKeyboard 2.2
ApplicationWindow {
    id: appwin
    visible: true
    width: 1280
    height: 800
    //    visibility: "FullScreen"
    title: qsTr("Hello World")
    property int num
    property alias wW: appwin.width
    property alias wH: appwin.height
    property string level1: file.getColor(0)
    property string level2: file.getColor(1)
    property string level3: file.getColor(2)
    property string level4: file.getColor(3)
    property string level5: file.getColor(4)
    property bool checkID: false
    property bool checkLevel: false
    property bool checkAccount: false
    property bool checkCountry: false
    property int  limit: 20
    property string str4: ""
    property string str1: ""
    property string str2: ""
    property string str3: ""
    Rectangle
    {
        width: wW
        height: wH
        anchors.fill: parent
        //        color: "red"
        Column {
            id: mainView
            spacing: 3
            anchors.topMargin: 3
            //            anchors.horizontalCenter: parent.horizontalCenter
            anchors.centerIn: parent
            Row {
                id: filterOption
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: 2
                Repeater
                {
                    model : 3
                    Rectangle {

                        width: wW * 0.1985
                        height: wH * 0.05
                        border.color: "black"
                        border.width: 1
                        color: "white"
                        TextField {
                            id: textEdit
                            anchors.fill: parent
                            color: "black"
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            font.pointSize: parent.height * 0.3
                            onTextChanged:
                            {
                                if (length > limit) {
                                    remove (limit, length)
                                }
                                if (index === 0)
                                {
                                    str1 = textEdit.text
                                }
                                else if (index === 1)
                                {
                                    str2 = textEdit.text
                                }
                                else if (index === 2)
                                {
                                    str3 = textEdit.text
                                }
                                console.log("str4 " + str4)
                                file.filterStringGroup(str1, str2, str3, str4)
                            }
                            placeholderText:  "Filter"
                            inputMethodHints: Qt.ImhNoAutoUppercase | Qt.ImhPreferLowercase | Qt.ImhSensitiveData | Qt.ImhNoPredictiveText
                        }
                    }
                }
                ComboBox {
                    id: filterLevel
                    displayText: "Level"
                    visible: true
                    width: wW * 0.1985
                    height: wH * 0.05
                    model: ["ALL", "1", "2","3","4","5"]
                    background: Rectangle {
                        anchors.fill: parent
                        color: "white"
                        border.width: 1
                        border.color: "black"
                    }
                    onActivated:
                    {
                        str4 = index
                        console.log("str4: " + str4)
                        file.filterStringGroup(str1, str2, str3, str4)
                        if (index === 0)
                        {
                            displayText = "ALL"
                        }
                        else {
                            displayText = index
                        }
                        //                        file.filterID(parseInt(index))
                    }
                }

            }
            /*header*/
            Row {
                Rectangle {
                    id: rectID
                    width: wW * 0.2
                    height: wH * 0.05
                    border.color: "white"
                    border.width: 3
                    color: "black"
                    Text {
                        text: "Id"
                        color: "white"
                        font.pixelSize: 15
                        anchors.centerIn: parent
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            iconSortLv.opacity = 0
                            iconSortAdd.opacity = 0
                            iconSortID.opacity = 1
                            iconSortAcc.opacity = 0
                            if(iconSortID.source == "qrc:/file/up.png")
                            {
                                iconSortID.source = "qrc:/file/down.png"
                            }
                            else {
                                iconSortID.source = "qrc:/file/up.png"
                            }
                            if (checkID == true)
                            {
                                file.sapXep(2)
                                checkID = false
                            }
                            else {
                                file.sapXep(1)
                                checkID = true
                            }
                        }
                    }
                    Image {
                        id: iconSortID
                        opacity: 0
                        source: "qrc:/file/down.png"
                        width: 0.01 * wW
                        height: 0.018 * wH
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }
                }
                Rectangle {
                    id: rectAcc
                    width: wW * 0.2
                    height: wH * 0.05
                    border.color: "white"
                    border.width: 3
                    color: "black"
                    Text {
                        text: "Account"
                        color: "white"
                        font.pixelSize: 15
                        anchors.centerIn: parent
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            iconSortLv.opacity = 0
                            iconSortAdd.opacity = 0
                            iconSortID.opacity = 0
                            iconSortAcc.opacity = 1
                            if(iconSortAcc.source == "qrc:/file/up.png")
                            {
                                iconSortAcc.source = "qrc:/file/down.png"
                            }
                            else {
                                iconSortAcc.source = "qrc:/file/up.png"
                            }
                            if (checkAccount == true)
                            {
                                file.sapXep(6)
                                checkAccount = false
                            }
                            else {
                                file.sapXep(5)
                                checkAccount = true
                            }
                        }
                    }
                    Image {
                        id: iconSortAcc
                        opacity: 0
                        source: "qrc:/file/down.png"
                        width: 0.01 * wW
                        height: 0.018 * wH
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }
                }
                Rectangle {
                    id: rectAdd
                    width: wW * 0.2
                    height: wH * 0.05
                    border.color: "white"
                    border.width: 3
                    color: "black"
                    Text {
                        text: "Country"
                        color: "white"
                        font.pixelSize: 15
                        anchors.centerIn: parent
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            iconSortLv.opacity = 0
                            iconSortAdd.opacity = 1
                            iconSortID.opacity = 0
                            iconSortAcc.opacity = 0
                            if(iconSortAdd.source == "qrc:/file/up.png")
                            {
                                iconSortAdd.source = "qrc:/file/down.png"
                            }
                            else {
                                iconSortAdd.source = "qrc:/file/up.png"
                            }
                            if (checkCountry == true)
                            {
                                file.sapXep(8)
                                checkCountry = false
                            }
                            else {
                                file.sapXep(7)
                                checkCountry = true
                            }
                        }
                    }
                    Image {
                        id: iconSortAdd
                        opacity: 0
                        source: "qrc:/file/down.png"
                        width: 0.01 * wW
                        height: 0.018 * wH
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }
                }
                Rectangle {
                    id: rectlv
                    width: wW * 0.2
                    height: wH * 0.05
                    border.color: "white"
                    border.width: 3
                    color: "black"
                    Text {
                        text: "Level"
                        color: "white"
                        font.pixelSize: 15
                        anchors.centerIn: parent
                    }
                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            iconSortLv.opacity = 1
                            iconSortAdd.opacity = 0
                            iconSortID.opacity = 0
                            iconSortAcc.opacity = 0
                            if(iconSortLv.source == "qrc:/file/up.png")
                            {
                                iconSortLv.source = "qrc:/file/down.png"
                            }
                            else {
                                iconSortLv.source = "qrc:/file/up.png"
                            }
                            if (checkLevel == true)
                            {
                                file.sapXep(4)
                                checkLevel = false
                            }
                            else {
                                file.sapXep(3)
                                checkLevel = true
                            }
                        }
                    }
                    Image {
                        id: iconSortLv
                        opacity: 0
                        source: "qrc:/file/down.png"
                        width: 0.01 * wW
                        height: 0.018 * wH
                        anchors.verticalCenter: parent.verticalCenter
                        anchors.left: parent.left
                        anchors.leftMargin: 10
                    }
                }
            }

            Grid {
                id: option
                //columns: file.getColumn()
                //rows: file.getRow()
                //                spacing: 3
                Repeater {
                    id: itemData
                    model: file.getColumn() * file.getRow()
                    Rectangle {
                        id: bg
                        Component.onCompleted: {
                            for (var i = 0; i < file.getColumn() * file.getRow(); i++) {
                                textData.text = file.getData(parseInt(index/4),parseInt(index%4))
                                //                                textData.color = "red"
                            }
                        }
                        width: wW * 0.2
                        height: wH * 0.05
                        border.color: "white"
                        border.width: 3
                        color: "black"
//                        function colorset() {
//                            switch (textData.text)
//                            {
//                            case "1":
//                                textData.color = level1
//                                break;
//                            case "2":
//                                textData.color = level2
//                                break;
//                            case "3":
//                                textData.color = level3
//                                break;
//                            case "4":
//                                textData.color = level4
//                                break;
//                            case "5":
//                                textData.color = level5
//                                break;
//                            default:
//                                textData.color = "white"
//                                break;
//                            }
//                        }
                        Text {
//                            Component.onCompleted: {
//                                colorset()
//                            }
                            id: textData
                            //color: "white"
                            font.pixelSize: 15
                            anchors.centerIn: parent
                            color: file.getColorString(parseInt(index))
                            Timer {
                                id: reload
                                interval: 100; running: true; repeat: true
                                onTriggered: {
                                    textData.text = file.getData(parseInt(index/4),parseInt(index%4))
                                    //colorset()
                                    textData.color = file.getColorString(parseInt(index))
                                }
                            }
                        }
                    }
                }
            }
        }

    }
}

