#ifndef VIDEOSHOW_SEL_H
#define VIDEOSHOW_SEL_H

#include "mykey.h"
#include <QTimer>

namespace Ui {
class videoshow_sel;
}

class videoshow_sel : public QMainWindow
{
    Q_OBJECT

public:
    explicit videoshow_sel(QWidget *parent = nullptr);
    ~videoshow_sel();

private:
    Ui::videoshow_sel *ui;
    unsigned long m_i_PauseTime;
    unsigned long m_i_PauseStartTime;
    QTimer *m_pDelayTimer;  // 新增：延迟播放定时器
    void showFirstFrame();
public:
    //void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent* ev);

public:
QPixmap *m_pixmap;
QPainterPath m_globalPath;

qint8 m_i_Panel_Open;
qint8 m_i_VideoPlaying;
qint8 m_i_Panel_Bg;
int m_i_SliderValue;
int m_i_OldVideoPlayTime;
int m_i_StartVideoPlayTime;
int m_i_Video_Player_Max_Time;
unsigned long m_i_PlayStartTime;
int m_iEvent;
private slots:

    void onDelayPlayTimeout();  // 新增：延迟超时后播放视频的槽函数

    void On_Btn_PlayPause_Toggle_Clicked();

    //播放停止
    void On_Btn_VideoPlayerPlay_Stop_Clicked();
    //返回
    void On_Btn_Return_Clicked();
signals:

    void sigReturnToVideoShow();
 public slots:
    //播放播放
    void On_Btn_VideoPlayerPlay_Play_Clicked();
    void On_Btn_VideoPlayerPlay_Pause_Clicked();
};











#endif // VIDEOSHOW_SEL_H
