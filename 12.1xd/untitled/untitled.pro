#-------------------------------------------------
#
# Project created by QtCreator 2025-08-12T13:56:11
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = San_Gyp12
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        widget.cpp \
    UsbMcu.cpp \
    mykey.cpp \
    zhukuang.cpp \
    photoshow.cpp \
    videoshow.cpp \
    videoshow_sel.cpp \
    datetimewindow.cpp \
    formatwindow.cpp \
    resetwindow.cpp \
    aboutwindow.cpp \
    lansetwindow.cpp \
    gpiodeal.cpp

HEADERS += \
        widget.h \
    UsbMcu.h \
    libusb.h \
    mykey.h \
    zhukuang.h \
    photoshow.h \
    videoshow.h \
    videoshow_sel.h \
    datetimewindow.h \
    formatwindow.h \
    resetwindow.h \
    aboutwindow.h \
    lansetwindow.h \
    gpiodeal.h

FORMS += \
        widget.ui \
    zhukuang.ui \
    photoshow.ui \
    videoshow.ui \
    videoshow_sel.ui \
    datetimewindow.ui \
    formatwindow.ui \
    resetwindow.ui \
    aboutwindow.ui \
    lansetwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    sp.qrc
unix:!macx: LIBS += -L$$PWD/../lib/ -lusb-1.0 \

message("当前 PWD 路径：$$PWD")
INCLUDEPATH += $$PWD/../lib
DEPENDPATH += $$PWD/../lib
#JPEG_HOME=/home/kjd/8836/project/image/output/customer/jpeg

#LIBS +=  -L$$JPEG_HOME/lib
#             -ljpeg
#linux: {
#    JPEG_HOME=/home/kjd/8836/project/image/output/customer/jpeg
#    USB_HOME=/home/kjd/12inch_UI/untitled





#    #设置导入库的目录一边程序可以找到导入库
#    # -L ：指定导入库的目录
#    # -l ：指定要导入的 库名称
#    LIBS +=  -L$$JPEG_HOME/lib
#             -ljpeg
#    LIBS +=  -L$$USB_HOME/lib
#             -lusb-1.0


#}
