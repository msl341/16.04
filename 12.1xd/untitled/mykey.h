#ifndef MYKEY_H
#define MYKEY_H



#include "UsbMcu.h"
#include <QSettings>
#include <QObject>
#include <QDebug>
#include <QThread>
#include <QFile>
#include <QTranslator>
#include <QLabel>
#include <QMouseEvent>
#include <QtDebug>
#include <QDir>
#include <QTimer>
#include <QList>
#include <QDateTime>
#include <QElapsedTimer>
#include <QGraphicsView>

#include <QGesture>
#include <QGestureEvent>
#include <QPinchGesture>

#include <QHostAddress>
#include <iostream>
#include <cstring>
#include <QtNetwork/QTcpSocket>
#include <QNetworkProxy>



#include <QPixmapCache>

#include <QScrollBar>
#include <QListWidget>
#include <QWidget>
#include <QPushButton>


#include <QGuiApplication>



//通讯命令
#define CMD_STREAM_USB_FLAG     1
#define CMD_VIDEO_PLAYER_TIME   10
#define CMD_VIDEO_PLAYER_START  11
#define CMD_VIDEO_PLAYER_PAUSE  12
#define CMD_VIDEO_PLAYER_PLAY   13
#define CMD_VIDEO_PLAYER_PRE    14
#define CMD_VIDEO_PLAYER_NEXT   15
#define CMD_VIDEO_PLAYER_STOP   16
#define CMD_TAKE_PHOTO_TAKE     20
#define CMD_TAKE_PHOTO_FILE     21
#define CMD_VIDEO_RECORD_START  30
#define CMD_VIDEO_RECORD_PAUSE  31
#define CMD_VIDEO_RECORD_RECORD 32
#define CMD_VIDEO_RECORD_STOP   33
#define CMD_VIDEO_RECORD_FILE   34
#define CMD_SET_BRIGHTNESS      35
#define CMD_SET_SATURATION      36

#define CMD_SET_AE              62
#define CMD_SET_AWB             63
#define CMD_SET_ROTATE          64
#define CMD_SET_NEGATIVE        66
#define CMD_SET_FREEZE          67

#define CMD_REC_VIDEO_FLAG      100
#define CMD_ROTATE_FLAG         101

#define CMD_CHANGE_MAIN_CAM     102


//电压检测
#define SARADC_IOC_MAGIC               'a'
#define MS_SAR_INIT   _IO(SARADC_IOC_MAGIC, 0)
#define MS_SAR_SET_CHANNEL_READ_VALUE  _IO(SARADC_IOC_MAGIC, 1)

//UsbMcu通讯命令
#define HOST_CMD_SET_TIME      0  //设置时间
#define HOST_CMD_GET_TIME      1  //获取时间
#define HOST_CMD_TAKE_PHOTO    2  //拍照
#define HOST_CMD_RECORD_VIDEO  3  //录像
//相片和录像存储路径

#define PATH_SYS           "/mnt/Sys/"
#define PATH_PHOTO         "/mnt/Photo/"
#define PATH_PHOTO_SMALL   "/mnt/Sys/Photo-Small/"
#define PATH_VIDEO         "/mnt/Video/"
#define PATH_VIDEO_SMALL   "/mnt/Sys/Video-Small/"



#endif
