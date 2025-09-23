# 虛擬鍵盤使用須知

## 前置準備 (ARM)

首先檢查當初build ARM的編譯環境時是否有skip SVG模組(-skip qtsvg)，如果有skip，需要重新編譯一次，建議不要skip任何模組，以免未來又要再重新編譯一次。

詳細編譯方法請參考：[嵌入式QT移植](https://blog.csdn.net/kiss_youi/article/details/123507368)

到qtvirtualkeyboard的源碼資料夾，設定qmake -> make -> make install
```sh
cd /path/to/qtvirtualkeyboard
/path/to/arm-build/bin/qmake qtvirtualkeyboard.pro -spec linux-arm-gnueabi-g++ CONFIG+=release && /usr/bin/make qmake_all
# 加快make的速度以及只顯示錯誤訊息
make -j16 2>&1 | tee build.log | grep --color=auto -i "error"
make install
```

將 [src](./src/) 中的檔案以及資料夾放進機器，存放的位置取決於設定的路徑，例如：
```sh
export LD_LIBRARY_PATH=/customer/lib/plugins:$LD_LIBRARY_PATH;

export QT_ROOT=/customer/lib/plugins;
export QT_QPA_FONTDIR=/customer/fonts/;
export QT_QPA_PLATFORM_PLUGIN_PATH=$QT_ROOT;
export QML2_IMPORT_PATH=/customer/qml;

export PATH=$PATH:/bin;
export LD_LIBRARY_PATH=/config/lib/:$LD_LIBRARY_PATH;
export LD_LIBRARY_PATH=/customer/ffmpeg/lib/:$LD_LIBRARY_PATH;
```
從這份設定檔可以得知 /customer/lib/plugins 是主要放QT會用到的一些library的資料夾，因此上述所提到的檔案和資料夾建議都放在這。

當上述的檔案及資料夾都放好後，記得到設定路徑的設定檔中增加qml的import path：
```sh
export QML2_IMPORT_PATH=/path/to/qml;
```
路徑取決於qml的存放路徑。

## 使用方法

### 一般使用：

在 .pro 中加入virtualkeyboard的模組：
```pro
QT += virtualkeyboard
```

在main.cpp中加入：
```cpp
qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));
```

注意該行程式必須加在main function的最前面，如：
```cpp
int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
```
做完這些，當點擊輸入框(如QLineEdit)，虛擬鍵盤就會跳出並可供輸入了

### 在機器中使用：

前面"一般使用"要加的東西，這裡也要加，不同的是由於一些不確定的因素(目前個人推測是由於ARM架構的問題)，導致當虛擬鍵盤跳出來的時候，原先的UI會被隱藏，使得畫面上只有虛擬鍵盤而已，而當虛擬鍵盤關閉時，UI就會正常顯示，同時由於虛擬鍵盤的預設大小太大、位置無法變更，因此需要用另外的方法來顯示虛擬鍵盤。

**解決方法**：使用QQuickWidget來存放虛擬鍵盤

首先創建一份.qml，import虛擬鍵盤：
```qml
import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.VirtualKeyboard 2.0

Rectangle {
    id: window
    color: "transparent"

    InputPanel {
        id: inputPanel
        z: 99
        x: 0
        y: window.height
        width: window.width

        states: [
            State {
                name: "visible"
                when: inputPanel.active
                PropertyChanges {
                    target: inputPanel
                    y: window.height - inputPanel.height
                }
            },
            State {
                name: "invisible"
                when: !inputPanel.active
                PropertyChanges {
                    target: inputPanel
                    y: window.height
                }
            }
        ]
    }
}
```
再把該.qml放進QQuickWidget，並設定QQuickWidget的位置和大小，這樣當點擊輸入框時，虛擬鍵盤就會在指定的位置顯示出來，而不會隱藏原先的UI。

QQuickWidget的使用方法以及範例請參考：[簡單易懂玩QT：QQuickWidget學習](https://blog.csdn.net/qq_36553707/article/details/110879312)

若有兩份或以上的.cpp會使用到虛擬鍵盤，假設是A.cpp和B.cpp，直覺會分別在A.ui和B.ui加入QQuickWidget，並把前面寫好的.qml分別放進QQuickWidget裡，但這樣會導致只有一份.cpp可以正常使用虛擬鍵盤，至於是哪份可以正常使用則取決於哪份.cpp比較晚編譯，最晚編譯的那份才可以正常使用。

簡單來說，就是一個project只能有一個存放虛擬鍵盤的QQuickWidget，至於該如何讓多個.cpp都可以正常使用虛擬鍵盤就根據project的寫法來解決。

**<span style="color:red; font-weight:bold;">注意</span>**：這個方法只是暫時的解決方案，未來可能會有更好的方法來解決這個問題，例如直接修改QtVirtualKeyboard的source code。