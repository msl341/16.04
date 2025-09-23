#include "videoshow_sel.h"
#include "ui_videoshow_sel.h"
#include "widget.h"
#include <QFileInfo>
videoshow_sel::videoshow_sel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::videoshow_sel)
{

    ui->setupUi(this);
    //窗体设置
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setAttribute(Qt::WA_DeleteOnClose);
    m_pDelayTimer = new QTimer(this); // 初始化定时器
    //初始化
    m_i_Panel_Open = 1;
    m_i_VideoPlaying = 0;
    g_i_Video_Player_Time = -1;
    m_i_Panel_Bg = 1;
    QString style = "QSlider::groove:horizontal {"
                    "height: 20px;"                  // 滑槽高度
            "background-color: #00A0E9;"     // 滑槽背景色
            "}"
            "QSlider::handle {"
            "width: 10px;"
            "height: 40px;"
            "background-color: #00A0E9;"

            "}"
            "QSlider::add-page:horizontal {"
            "background: #A0A0A0;"
            "}"
            "QSlider::sub-page:horizontal {"
            "background: #00A0E9;"
            "}";

    ui->m_pSlider_Progress->setStyleSheet(style);

    m_iEvent = startTimer(300);

    connect(ui->m_pBtn_Return,SIGNAL(clicked()),this,SLOT(On_Btn_Return_Clicked()));
    // 连接定时器超时信号到播放槽函数
    connect(m_pDelayTimer, &QTimer::timeout, this, &videoshow_sel::onDelayPlayTimeout);

    // 关键修改：将按键连接到切换槽，而非单独的暂停槽
    connect(ui->m_pBtn_Pause, &QPushButton::clicked, this, &videoshow_sel::On_Btn_PlayPause_Toggle_Clicked);
    ui->m_pBtn_Pause->setStyleSheet("border-image: url(:/tu/Res/Video/videoplayer_pause.png);");
    ui->m_pBtn_Pause->setParent(this);
    ui->m_pBtn_Pause->raise(); // 强制置于顶层
    ui->m_pSlider_Progress->raise();
    ui->m_pLb_Time->raise();
    ui->m_pBtn_Return->raise();


}

videoshow_sel::~videoshow_sel()
{
    killTimer(m_iEvent);
    delete m_pDelayTimer;  // 释放定时器
    delete ui;
}

// 播放/暂停切换逻辑
void videoshow_sel::On_Btn_PlayPause_Toggle_Clicked()
{
    if (m_i_VideoPlaying == 0) {
        // 状态：停止 → 执行播放
        On_Btn_VideoPlayerPlay_Play_Clicked();
        ui->m_pBtn_Pause->setStyleSheet("border-image: url(:/tu/Res/Video/videoplayer_pause.png);");
    } else if (m_i_VideoPlaying == 1) {
        // 状态：播放中 → 执行暂停
        On_Btn_VideoPlayerPlay_Pause_Clicked();
        ui->m_pBtn_Pause->setStyleSheet("border-image: url(:/tu/Res/Video/videoplayer_play.png);");
    } else if (m_i_VideoPlaying == 2) {
        // 状态：暂停中 → 执行继续播放
        On_Btn_VideoPlayerPlay_Play_Clicked();
        ui->m_pBtn_Pause->setStyleSheet("border-image: url(:/tu/Res/Video/videoplayer_pause.png);");

    }
}


// 新增：延迟超时后执行真正的播放逻辑
void videoshow_sel::onDelayPlayTimeout()
{
    m_pDelayTimer->stop();  // 停止定时器
    ui->label->hide();



}

void videoshow_sel::timerEvent(QTimerEvent* ev)
{
    // 设置录像进度最大值(秒)：仅在首次获取到有效时长时初始化
    if (g_i_Video_Player_Time > 0)  // 确保是有效时长（>0）
    {
        ui->m_pSlider_Progress->setMaximum(g_i_Video_Player_Time);
        m_i_Video_Player_Max_Time = g_i_Video_Player_Time;  // 保存总时长
        m_i_StartVideoPlayTime = GetTickCountForSec();  // 记录开始播放的系统时间
        m_i_OldVideoPlayTime = m_i_StartVideoPlayTime;
        m_i_SliderValue = 0;
        g_i_Video_Player_Time = -1;  // 避免重复初始化
        m_i_VideoPlaying = 1;  // 标记为播放中
        qDebug() << "视频总时长初始化：" << m_i_Video_Player_Max_Time << "秒";
    }

    // 播放中才更新进度
    if (m_i_VideoPlaying == 1)
    {
        int currentSysTime = GetTickCountForSec();
        // 计算实际播放秒数（当前系统时间 - 开始播放时间）
        int playSeconds = currentSysTime - m_i_StartVideoPlayTime;

        // 防止进度超过总时长
        if (playSeconds > m_i_Video_Player_Max_Time)
        {
            playSeconds = m_i_Video_Player_Max_Time;
            On_Btn_VideoPlayerPlay_Stop_Clicked();
            //emit sigReturnToVideoShow(); // 发送返回信号
            showFirstFrame();
            m_i_VideoPlaying = 0;
            return;
        }

        // 更新进度条
        m_i_SliderValue = playSeconds;
        ui->m_pSlider_Progress->setValue(m_i_SliderValue);

        // 更新时间显示（时:分:秒）
        int hour = playSeconds / 3600;
        int min = (playSeconds % 3600) / 60;
        int sec = playSeconds % 60;
        ui->m_pLb_Time->setText(QString("%1:%2:%3")
                                .arg(hour, 2, 10, QChar('0'))
                                .arg(min, 2, 10, QChar('0'))
                                .arg(sec, 2, 10, QChar('0')));

        m_i_OldVideoPlayTime = currentSysTime;  // 记录当前时间，用于暂停补偿
    }

    // 黑板状态判断（保持原逻辑）
    if ((m_i_VideoPlaying == 1) || (m_i_VideoPlaying == 2))
    {
        if (m_i_Panel_Bg == 1 && (GetTickCountForMSec() - m_i_PlayStartTime) > 500)
        {
            m_i_Panel_Bg = 0;
        }
    }

}


//暂停
void videoshow_sel::On_Btn_VideoPlayerPlay_Pause_Clicked()
{
    if (m_i_VideoPlaying != 1) {
        qDebug() << "暂停失败：当前状态不是播放中（状态：" << m_i_VideoPlaying << "）";
        return;
    }
    m_i_VideoPlaying = 2;  // 标记为暂停
    m_i_PauseStartTime = GetTickCountForSec();  // 记录暂停开始时间
    QString videoPath = QString(g_c_FilePath);
    QFileInfo fileInfo(videoPath);
    SendMsgToUvc("VideoPlayer", CMD_VIDEO_PLAYER_PAUSE, 0,
                 const_cast<char*>(fileInfo.fileName().toUtf8().constData()));
    qDebug() << "发送暂停命令：" << fileInfo.fileName();

}

//播放播放
void videoshow_sel::On_Btn_VideoPlayerPlay_Play_Clicked()
{
    if (m_i_VideoPlaying == 2)  // 从暂停恢复
    {

        int pauseDuration = GetTickCountForSec() - m_i_PauseStartTime;  // 计算暂停时长
        m_i_StartVideoPlayTime += pauseDuration;  // 补偿开始时间（跳过暂停的时长）
        m_i_VideoPlaying = 1;  // 标记为播放中
        QString videoPath = QString(g_c_FilePath);
        QFileInfo fileInfo(videoPath);
        SendMsgToUvc("VideoPlayer", CMD_VIDEO_PLAYER_PLAY, 0,
                     const_cast<char*>(fileInfo.fileName().toUtf8().constData()));
        qDebug() << "恢复播放，发送命令：" << fileInfo.fileName();
    }
    else if (m_i_VideoPlaying == 0)  // 从停止开始播放
    {
        ui->label->hide();
        // 重置所有状态
        ui->m_pLb_Time->setText("00:00:00");
        ui->m_pSlider_Progress->setValue(0);
        m_i_SliderValue = 0;
        m_i_PlayStartTime = GetTickCountForMSec();
        m_i_VideoPlaying = 0;  // 先标记为停止，等待时长初始化

        ui->m_pBtn_Pause->setStyleSheet("border-image: url(:/tu/Res/Video/videoplayer_pause.png);");
        // 2. 上层显示视频第一帧（缩略图），并确保在最顶层（覆盖底层视频区域）
        QString videoPath = QString(g_c_FilePath);
        QFileInfo fileInfo(videoPath);
        QString baseName = fileInfo.baseName();  // 获取视频文件名（无后缀）
        QString thumbnailPath = QString("%1%2.jpg").arg(PATH_VIDEO_SMALL).arg(baseName);  // 第一帧图像路径
        QImage thumbnail;
        if (thumbnail.load(thumbnailPath)) {
            ui->label->setScaledContents(true);  // 图像自适应label大小（避免拉伸变形）
            ui->label->setPixmap(QPixmap::fromImage(thumbnail));
            ui->label->raise();  // 关键：确保label在最上层，覆盖底层未准备好的视频区域
            ui->label->show();   // 显示第一帧，作为过渡
        } else {
            qDebug() << "警告：无法加载视频第一帧图像，路径：" << thumbnailPath;
            ui->label->hide();   // 加载失败则不显示label，避免空白
        }

        // 3. 立即发送播放命令！让底层开始读取视频数据（与上层显示并行，不阻塞）
        SendMsgToUvc("VideoPlayer", CMD_VIDEO_PLAYER_START, 0,
                     const_cast<char*>(fileInfo.fileName().toUtf8().constData()));
        qDebug() << "已发送播放命令，底层开始读取视频数据：" << fileInfo.fileName();

        // 4. 延迟1秒后隐藏label，切换到底层视频画面（无闪屏核心）
        m_pDelayTimer->start(1000);  // 1000ms=1秒，时间到后执行onDelayPlayTimeout
    }
}


void videoshow_sel::showFirstFrame()
{
    // 1. 获取当前视频路径并生成缩略图路径（与播放时的逻辑一致）
    QString videoPath = QString(g_c_FilePath);
    QFileInfo fileInfo(videoPath);
    QString baseName = fileInfo.baseName();  // 提取视频文件名（无后缀）
    QString thumbnailPath = QString("%1%2.jpg").arg(PATH_VIDEO_SMALL).arg(baseName);  // 缩略图路径

    // 2. 加载并显示第一帧
    QImage thumbnail;
    if (thumbnail.load(thumbnailPath)) {
        ui->m_pBtn_Pause->setParent(this);
        ui->m_pBtn_Pause->raise();  // 强制置于顶层
        ui->m_pSlider_Progress->raise();
        ui->m_pLb_Time->raise();
        ui->m_pBtn_Return->raise();
        ui->label->setScaledContents(true);
        ui->label->setPixmap(QPixmap::fromImage(thumbnail));
        ui->label->show();   // 显示第一帧
        qDebug() << "视频播放结束，显示第一帧：" << thumbnailPath;
    } else {
        qDebug() << "无法加载第一帧，路径：" << thumbnailPath;
        ui->label->hide();  // 加载失败则隐藏
    }
}



//播放停止
void videoshow_sel::On_Btn_VideoPlayerPlay_Stop_Clicked()
{
    if (m_i_VideoPlaying == 0)//当前在停止状态
    {
        return;
    }
    else if (m_i_VideoPlaying == 1)//当前在播放状态
    {
    }
    else if (m_i_VideoPlaying == 2)//当前在暂停状态
    {
        On_Btn_VideoPlayerPlay_Play_Clicked();
        usleep(200);
    }


    m_i_Panel_Bg = 1;

    m_i_VideoPlaying = 0;
    m_i_SliderValue = 0;

    ui->m_pSlider_Progress->setValue(0);
    ui->m_pLb_Time->setText("00:00:00");
    g_i_Video_Player_Time = -1;  // 允许下一个视频设置新时长
    SendMsgToUvc("VideoPlayer", CMD_VIDEO_PLAYER_STOP, 0, "");

    ui->m_pBtn_Pause->setStyleSheet("border-image: url(:/tu/Res/Video/videoplayer_play.png);");
}


//返回
void videoshow_sel::On_Btn_Return_Clicked()
{
    On_Btn_VideoPlayerPlay_Stop_Clicked();
    // 发送返回信号给widget
    qDebug() << "发送sigReturnToVideoShow";
    emit sigReturnToVideoShow();

}
