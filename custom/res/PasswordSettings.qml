import QtQml 2.12

import QtQuick          2.3
import QtQuick.Layouts  1.11

import QGroundControl               1.0
import QGroundControl.Controls      1.0
import QGroundControl.Palette       1.0
import QGroundControl.ScreenTools   1.0

Rectangle {
    id: passwordMain
    color:          qgcPal.window
    anchors.fill:   parent

    readonly property real _margins: ScreenTools.defaultFontPixelHeight
    property string currentAccessType: QGroundControl.corePlugin.accessType

    QGCPalette { 
        id: qgcPal
        colorGroupEnabled: true
    }

    Timer {
        id: timer
        function setTimeout(ms, callback) {
            timer.interval = ms;
            timer.repeat = false;
            timer.triggered.connect(callback);
            timer.triggered.connect(function destroy() {
                timer.triggered.disconnect(callback);
                timer.triggered.disconnect(destroy);
            });
            timer.start();
        }
    }


    QGCFlickable {
        anchors.margins:    _margins
        anchors.fill:       parent
        clip:               true

        ColumnLayout {
            id:         mainLayout
            spacing:    _columnSpacing

            QGCGroupBox {
                title: "Enter the code provided to unlock features."

                QGCTextField {
                    id:                     passcodeField
                    Layout.preferredWidth:  _secondColumnWidth
                    Layout.fillWidth:       true
                    text:                   ""
                }
            }

            QGCButton {
                width:      ScreenTools.defaultFontPixelWidth * 10
                text:       qsTr("Submit")
                enabled:    passcodeField.text !== ""
                property string accessType: ""

                onClicked: {
                    accessType = PasscodeManager.submitPasscode(passcodeField.text)
                    CustomCorePlugin.setAccessType(accessType)
                    if (accessType != "" && accessType != currentAccessType) {
                        passcodeField.text = ""
                        currentAccessType = accessType
                        loginMessage.color = qgcPal.statusPassedText
                        loginMessage.text = "Access type changed to " + accessType
                    } else if (accessType == currentAccessType) {
                        passcodeField.text = ""
                    } else {
                        loginMessage.color = qgcPal.statusFailedText
                        loginMessage.text = "Check the passcode entered and try again"
                    }
                    timer.setTimeout(5000, () => { loginMessage.text = "" });
                }
            }
            Text {
                id: loginMessage
                text: ""
                color: qgcPal.text
            }
        }
    }
}
