import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.VirtualKeyboard 2.0

import QtQuick.VirtualKeyboard.Settings 2.1

Rectangle {
    id: window
    color: "transparent"

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        signal keyboardVisibilityChanged(bool visible)

        Component.onCompleted: {
            // 允许的语言，重要！
            VirtualKeyboardSettings.activeLocales = ["en_GB","zh_CN"]
            // 默认的语言，重要！
            VirtualKeyboardSettings.locale = "zh_CN"
        }

        states: [
            State {
                name: "shown"
                when: inputPanel.active
                PropertyChanges {
                    target: inputPanel
                    y: window.height - inputPanel.height
                }
            },
            State {
                name: "unshown"
                when: !inputPanel.active
                PropertyChanges {
                    target: inputPanel
                    y: window.height
                }
            }
        ]
        onActiveChanged: {
//            if(inputPanel.active){
//                console.log("active")
//            }
//            else{
//                console.log("inactive")
//            }

            keyboardVisibilityChanged(inputPanel.active);
        }
    }
}
