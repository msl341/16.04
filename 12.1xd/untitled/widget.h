#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mykey.h"
#include "UsbMcu.h"
#include "photoshow.h"
#include "videoshow.h"
#include "videoshow_sel.h"
#include "datetimewindow.h"
#include "formatwindow.h"
#include "resetwindow.h"
#include "aboutwindow.h"
#include "lansetwindow.h"
#include "gpiodeal.h"

#include <QPainter>
#include "zhukuang.h"
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QMovie>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>
#include <QPropertyAnimation>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    static Widget *mywidget;

    void Confirm_folder();


    void verify_usbflash();
    void Clear_record_usbflash();
    void Confirm_folder_usbflash();
    static void sd_in_re(int num);
    static void usb_in_re(int num);

    //获取磁盘信息并做处理
    qint8  GetDiskInfoAndDeal();

    qint8 m_i_UsbChargeIn_OpenFlag;
    qint8 m_i_Take_Photo;
    qint8 m_i_Take_Photo_Show_Time_Count;

    qint8 m_i_Record_Video;
    qint8 m_i_Record_Video_Show_Time_Count;

    QWidget *m_pWdg_Panel_RecordVideo;

    int m_iEvent;

    int m_i_Usb_Mcu_Dev_Open_Count;
    void GetCmdDataOfUsbMcuAndDeal();

    void timerEvent(QTimerEvent* ev);
public:
    int m_i_Recording;         // 0=未录像，1=正在录像
    qint8 m_i_DateTimeShowFlag = 0;
protected:
    //void paintEvent(QPaintEvent *event) override; // 重写绘制事件
private:
    Ui::Widget *ui;
private:
    zhukuang *zhukuang_widget;
    photoshow*photoshow_widget;
    //    videoshow*videoshow_widget;
    QPointer<videoshow> videoshow_widget;
    videoshow_sel* videoshow_sel_widget;
    datetimewindow* datetimewindow_widget;
    formatwindow* formatwindow_widget;
    resetwindow* resetwindow_widget;
    aboutwindow* aboutwindow_widget;
    lansetwindow* lansetwindow_widget;
    void asyncMkdir();
    // 录像核心状态

    qint64 m_i_StartRecordTime ;  // 录像开始时间戳（秒）

    QLabel *m_pLb_VideoTime = nullptr; // 时间显示标签
    int m_timerId; // 定时器ID
    const int m_brightnessLevels[3] = {2, 32, 62};
    // 当前亮度级别索引（0=2，1=32，2=62）
    int m_i_CurrentBrightLevel;
    // 原有的亮度值变量（保持，用于适配原有消息发送逻辑）
    int m_i_BrightVal;
    // 原有的+键第一次按下标记
    int m_i_SetBrightUp_Flag;
public slots:
    void On_Btn_TakePhoto_Clicked(); // 触发异步任务
    void onSeekPhotoClicked();
    void onSeekVideoClicked();
    void onReturnTowidget();
    //录像停止处理
    void RecordVideo_Stop_Deal(int iFlag);
    void On_Btn_RecordVideo_Clicked(); // 录像按钮点击（双状态切换）
    void onVideoselClicked();
    void onVideoClicked();
    //录像停止
    void On_Btn_RecordVideo_Stop_Clicked();
    void onsettimeClicked();
    void onlansetClicked();

    void onformatClicked();
    void onresetClicked();
    void onaboutClicked();
private slots:



signals:
    void showVideoTime(bool show); // 控制视频时间标签显示
    void updateVideoTimeText(const QString &text); // 更新时间文本
    void sig_AsyncMkdir();
    void sigRefreshPhotos();
    void sig_AsyncStartRecord(); // 异步创建录像文件夹
};

#endif // WIDGET_H
