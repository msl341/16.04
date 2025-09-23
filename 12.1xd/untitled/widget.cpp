#include "widget.h"
#include "ui_widget.h"
int g_i_Need_Check_Usb = 0;
int g_i_Need_Deal_UsbMcu = 0;


Widget *Widget::mywidget=nullptr;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mywidget=this;
    San_ReadConfig(&g_S_CfgData);
    zhukuang_widget=new zhukuang(this);
   // photoshow_widget=new photoshow(this);
    lansetwindow_widget=new lansetwindow(this);
    lansetwindow_widget->hide();

    videoshow_sel_widget = new videoshow_sel();


    ui->one_stack->addWidget(zhukuang_widget);
    ui->one_stack->addWidget(videoshow_sel_widget);


    ui->one_stack->setVisible(false);
    ui->one_stack->setCurrentWidget(zhukuang_widget);
    ui->one_stack->setVisible(true);







    ui->two_stack->setVisible(false);




    mMsgGlobalVal.qRecvTKId = -1;
    mMsgGlobalVal.iRecvTKMsgkey = 0x1234;
    IniMsg(&(mMsgGlobalVal.qRecvTKId),mMsgGlobalVal.iRecvTKMsgkey);

    mMsgGlobalVal.qSendTKId = -1;
    mMsgGlobalVal.iSendTKMsgkey = 0x1235;
    IniMsg(&(mMsgGlobalVal.qSendTKId),mMsgGlobalVal.iSendTKMsgkey);

    pthread_mutex_init(&i_g_UsbMcuLock, NULL);

//    pthread_mutex_lock(&i_g_UsbMcuLock);
//    SendMsgToUvc("TakePhoto",CMD_TAKE_PHOTO_TAKE,0,""); // 仅此处需要锁
//    pthread_mutex_unlock(&i_g_UsbMcuLock);

    m_i_UsbChargeIn_OpenFlag = 0;
    m_i_Usb_Mcu_Dev_Open_Count = 0;
    //m_iEvent = startTimer(300);
    m_i_Recording = 0; // 初始化为未录制状态
    m_i_StartRecordTime = 0;
    m_i_DateTimeShowFlag = 1;




    // 关键：让窗口背景透明
    setAttribute(Qt::WA_TranslucentBackground);  // 启用透明背景
    //   setWindowFlags(Qt::FramelessWindowHint);      //去除窗口边框

    QThread* diskThread = new QThread(this);
    connect(this, &Widget::sig_AsyncMkdir, this, &Widget::asyncMkdir, Qt::QueuedConnection);
    diskThread->start();

    connect(zhukuang_widget, &zhukuang::seekPhotoClicked, this, &Widget::onSeekPhotoClicked);
    connect(zhukuang_widget, &zhukuang::seekVideoClicked, this, &Widget::onSeekVideoClicked);
    //    connect(videoshow_widget, &videoshow::sigShowVideoPlayer, this, &Widget::onVideoselClicked);
    connect(videoshow_sel_widget, &videoshow_sel::sigReturnToVideoShow, this, &Widget::onVideoClicked);
    connect(zhukuang_widget, &zhukuang::settimeClicked, this, &Widget::onsettimeClicked);
    connect(zhukuang_widget, &zhukuang::formatClicked, this, &Widget::onformatClicked);
    connect(zhukuang_widget, &zhukuang::resetClicked, this, &Widget::onresetClicked);
    connect(zhukuang_widget, &zhukuang::aboutClicked, this, &Widget::onaboutClicked);
    connect(zhukuang_widget, &zhukuang::setlansetClicked, this, &Widget::onlansetClicked);
    connect(this, &Widget::showVideoTime, zhukuang_widget, &zhukuang::showVideoTime);
    connect(this, &Widget::updateVideoTimeText, zhukuang_widget, &zhukuang::updateVideoTimeText);


    m_i_CurrentBrightLevel = 0; // 索引0对应亮度2
    m_i_BrightVal = m_brightnessLevels[m_i_CurrentBrightLevel]; // 初始亮度=2
    m_i_SetBrightUp_Flag = 1; // 初始允许+键正常切换（避免首次按下无效）
    SetGpioValue(40,0);
    m_iEvent = startTimer(300);
    //开启接收消息线程
    pthread_create(&g_t_Revmsg_Tid, NULL, RevMseFromUvc, NULL);

    //开启摄像头按键处理线程
    pthread_create(&g_t_RevUsbMcu_Tid, NULL, CameraKeyDeal, NULL);
    //开启关机处理线程
    pthread_create(&g_t_Close_Tid, NULL, CloseDeal, NULL);
//    //开启接收UsbMcu数据线程
   pthread_create(&g_t_RevUsbMcu_Tid, NULL, RevDataFromUsbMcu, NULL);
    //开启监控处理线程
    pthread_create(&g_t_Monitor_Tid, NULL, MonitorDeal, NULL);
    printf("@@@@@@@@@@@@@@1111111111111\n");
}
Widget::~Widget()
{
    delete ui;
}


// 视频按钮点击处理
void Widget::On_Btn_RecordVideo_Clicked() {
    if (m_i_Recording == 0) {

        // 创建视频所需文件夹
        char cTemp[100];
        if (GetDiskInfoAndDeal() == 1) return; // 检查磁盘空间


        if (folderExist(PATH_VIDEO) == -1)
        {
            sprintf(cTemp,"mkdir %s",PATH_VIDEO);
            system(cTemp);
            system("sync");
        }
        if (folderExist(PATH_SYS) == -1)
        {
            sprintf(cTemp,"mkdir %s",PATH_SYS);
            system(cTemp);
            system("sync");
        }
        if (folderExist(PATH_VIDEO_SMALL) == -1)
        {
            sprintf(cTemp,"mkdir %s",PATH_VIDEO_SMALL);
            system(cTemp);
            system("sync");
        }

        // 记录开始时间并发送开始命令
        m_i_StartRecordTime = QDateTime::currentMSecsSinceEpoch();
        m_i_Recording = 1;
        g_i_Rec_Video_Flag = 1;

        SendMsgToUvc("VideoRecord", CMD_VIDEO_RECORD_START, 0, g_c_FilePath);
        emit showVideoTime(true); // 显示时间标签
    } else {
        On_Btn_RecordVideo_Stop_Clicked();

    }
}

//录像停止
void Widget::On_Btn_RecordVideo_Stop_Clicked()
{
    RecordVideo_Stop_Deal(1);
}


//录像停止处理
void Widget::RecordVideo_Stop_Deal(int iFlag)
{
    m_i_Recording = 0;
    g_i_Rec_Video_Flag = 0;

    if (iFlag == 1)
        SendMsgToUvc("VideoRecord",CMD_VIDEO_RECORD_STOP,0,g_c_FilePath);

    emit showVideoTime(false); // 隐藏时间标签

    if (videoshow_widget && videoshow_widget->isValid()) {
            // 切换到主线程执行（避免线程安全问题）
            QMetaObject::invokeMethod(videoshow_widget, [this]() {
                videoshow_widget->CheckFileAndDeal_F();
                videoshow_widget->RefreshFileAndShow();
            }, Qt::QueuedConnection);
        }

    m_i_Record_Video = 1;
    m_i_Record_Video_Show_Time_Count = 0;
}


void Widget::onReturnTowidget() {
    ui->two_stack->setVisible(false);
    ui->one_stack->setVisible(true);
    ui->one_stack->setCurrentWidget(zhukuang_widget);
}
void Widget::onSeekPhotoClicked()
{
    photoshow_widget=new photoshow(this);
    ui->two_stack->addWidget(photoshow_widget);
    connect(this, &Widget::sigRefreshPhotos, photoshow_widget, &photoshow::refreshPhotos, Qt::QueuedConnection);

    connect(photoshow_widget, &photoshow::sigReturnTowidget, this, [=](){
        ui->two_stack->removeWidget(photoshow_widget); // 从栈窗口移除
        ui->one_stack->setVisible(true);
        ui->one_stack->setCurrentWidget(zhukuang_widget);
        photoshow_widget->close(); // 触发WA_DeleteOnClose销毁
    });
    // 隐藏当前栈部件，显示photoshow所在的栈部件
    ui->one_stack->setVisible(false);
    ui->two_stack->setVisible(true);
    // 确保切换到photoshow_widget
    ui->two_stack->setCurrentWidget(photoshow_widget);
}

void Widget::onSeekVideoClicked()
{
    // 主线程创建videoshow_widget（避免跨线程对象创建）

      QMetaObject::invokeMethod(this, [this]() {
           videoshow_widget = new videoshow(this);
           ui->two_stack->addWidget(videoshow_widget);
           // 连接信号时指定QueuedConnection，确保槽函数在主线程执行
           connect(videoshow_widget, &videoshow::sigShowVideoPlayer, this, &Widget::onVideoselClicked, Qt::QueuedConnection);
           connect(videoshow_widget, &videoshow::sigReturnTowidget, this, [=](){
               ui->two_stack->removeWidget(videoshow_widget);
               videoshow_widget->close();

               ui->one_stack->setVisible(true);
               ui->one_stack->setCurrentWidget(zhukuang_widget);
           }, Qt::QueuedConnection);
           ui->one_stack->setVisible(false);
           ui->two_stack->setVisible(true);
           ui->two_stack->setCurrentWidget(videoshow_widget);
       }, Qt::QueuedConnection);

}
//连接设置时间
void Widget::onsettimeClicked()
{
    datetimewindow_widget=new datetimewindow(this);
    ui->two_stack->addWidget(datetimewindow_widget);
    connect(datetimewindow_widget, &datetimewindow::sigReturnTowidget, this, [=](){
        ui->two_stack->removeWidget(datetimewindow_widget); // 从栈窗口移除
        ui->one_stack->setVisible(true);
        ui->one_stack->setCurrentWidget(zhukuang_widget);
        datetimewindow_widget->close(); // 触发WA_DeleteOnClose销毁
    });
    // 隐藏当前栈部件，显示photoshow所在的栈部件
    ui->one_stack->setVisible(false);
    ui->two_stack->setVisible(true);
    // 确保切换到photoshow_widget
    ui->two_stack->setCurrentWidget(datetimewindow_widget);
}
//连接格式化
void Widget::onformatClicked()
{
    formatwindow_widget=new formatwindow(this);
    ui->two_stack->addWidget(formatwindow_widget);
    connect(formatwindow_widget, &formatwindow::sigReturnTowidget, this, [=](){
        ui->two_stack->removeWidget(formatwindow_widget); // 从栈窗口移除
        ui->one_stack->setVisible(true);
        ui->one_stack->setCurrentWidget(zhukuang_widget);
        formatwindow_widget->close(); // 触发WA_DeleteOnClose销毁
    });
    // 隐藏当前栈部件，显示photoshow所在的栈部件
    ui->one_stack->setVisible(false);
    ui->two_stack->setVisible(true);
    // 确保切换到photoshow_widget
    ui->two_stack->setCurrentWidget(formatwindow_widget);
}
//连接复位
void Widget::onresetClicked()
{
    resetwindow_widget=new resetwindow(this);
    ui->two_stack->addWidget(resetwindow_widget);
    connect(resetwindow_widget, &resetwindow::sigReturnTowidget, this, [=](){
        ui->two_stack->removeWidget(resetwindow_widget); // 从栈窗口移除
        ui->one_stack->setVisible(true);
        ui->one_stack->setCurrentWidget(zhukuang_widget);
        resetwindow_widget->close(); // 触发WA_DeleteOnClose销毁
    });
    // 隐藏当前栈部件，显示photoshow所在的栈部件
    ui->one_stack->setVisible(false);
    ui->two_stack->setVisible(true);
    // 确保切换到photoshow_widget
    ui->two_stack->setCurrentWidget(resetwindow_widget);
}
//连接升级
void Widget::onaboutClicked()
{
    aboutwindow_widget=new aboutwindow(this);
    ui->two_stack->addWidget(aboutwindow_widget);
    connect(aboutwindow_widget, &aboutwindow::sigReturnTowidget, this, [=](){
        ui->two_stack->removeWidget(aboutwindow_widget); // 从栈窗口移除
        ui->one_stack->setVisible(true);
        ui->one_stack->setCurrentWidget(zhukuang_widget);
        aboutwindow_widget->close(); // 触发WA_DeleteOnClose销毁
    });
    // 隐藏当前栈部件，显示photoshow所在的栈部件
    ui->one_stack->setVisible(false);
    ui->two_stack->setVisible(true);
    // 确保切换到photoshow_widget
    ui->two_stack->setCurrentWidget(aboutwindow_widget);
}
//连接语言
void Widget::onlansetClicked()
{
    lansetwindow_widget=new lansetwindow(this);
    lansetwindow_widget->show();
//    ui->two_stack->addWidget(lansetwindow_widget);
//    connect(lansetwindow_widget, &lansetwindow::sigReturnTowidget, this, [=](){
//        ui->two_stack->removeWidget(lansetwindow_widget); // 从栈窗口移除
//        ui->one_stack->setVisible(true);
//        ui->one_stack->setCurrentWidget(zhukuang_widget);
//        lansetwindow_widget->close(); // 触发WA_DeleteOnClose销毁
//    });
//    // 隐藏当前栈部件，显示photoshow所在的栈部件
//    ui->one_stack->setVisible(false);
//    ui->two_stack->setVisible(true);
//    // 确保切换到photoshow_widget
//    ui->two_stack->setCurrentWidget(lansetwindow_widget);
}
// 连接videoshow的信号：切换到视频播放界面
void Widget::onVideoselClicked()
{


    ui->one_stack->setCurrentWidget(videoshow_sel_widget);

    // 1. 先隐藏当前栈并开始动画
    ui->two_stack->setVisible(false);
    // 2. 切换到目标部件
    ui->one_stack->setVisible(true);
    // 3. 播放淡入动画
    videoshow_sel_widget->On_Btn_VideoPlayerPlay_Play_Clicked();


}
// 连接videoshow_sel的信号：返回视频列表界面
void Widget::onVideoClicked()
{

    ui->two_stack->setCurrentWidget(videoshow_widget);

    qDebug() << "接收sigReturnToVideoShow，切换到videoshow_widget";


    // 1. 隐藏当前栈并开始动画
    ui->one_stack->setVisible(false);

    // 2. 切换到目标部件
    ui->two_stack->setVisible(true);
    // 3. 播放淡入动画
    videoshow_widget->RefreshFileAndShow();


}


// 拍照
void Widget::On_Btn_TakePhoto_Clicked() {
    if (GetDiskInfoAndDeal() == 1) return;
    zhukuang::myzhukuang->DrawShapeClose();//画图形状面板关闭
    if (zhukuang::myzhukuang) {
          zhukuang::myzhukuang->showPromptPhoto();
      }
    emit sig_AsyncMkdir();
    QTimer::singleShot(1000, [=]() {
           if (zhukuang::myzhukuang) {
               zhukuang::myzhukuang->hidePromptPhoto();  // 使用隐藏函数
           }
       });
}
void Widget::asyncMkdir() {
    char cTemp[100];
    if (GetDiskInfoAndDeal() == 1)//获取磁盘信息并做处理
        return;

    if (folderExist(PATH_PHOTO) == -1)
    {
        sprintf(cTemp,"mkdir %s",PATH_PHOTO);
        system(cTemp);
        system("sync");
    }
    if (folderExist(PATH_SYS) == -1)
    {
        sprintf(cTemp,"mkdir %s",PATH_SYS);
        system(cTemp);
        system("sync");
    }

    SendMsgToUvc("TakePhoto",CMD_TAKE_PHOTO_TAKE,0,"");
    QTimer::singleShot(500, this, [=]() {
        emit sigRefreshPhotos(); // 延迟500ms，确保文件已保存
        if (zhukuang_widget) {
            zhukuang_widget->hidePromptPhoto();
        }
    });
}





//获取磁盘信息并做处理
qint8  Widget::GetDiskInfoAndDeal()
{
    qint8 iRet = 0;


    SDiskInfo_T mDiskInfo;
    GetDiskInfo(&mDiskInfo);

    if (mDiskInfo.iFreedisk < 10)
    {

        iRet = 1;
        if (zhukuang_widget) {
            zhukuang_widget->hidePromptPhoto();
            QMessageBox::warning(this, "错误", "磁盘空间不足，无法拍照！");
        }

    }
    return iRet;
}


//获取UsbMcu命令与数据并处理
void Widget::GetCmdDataOfUsbMcuAndDeal()
{

//    if (g_m_UsbMcuBuf.REC_FLAG == 1)
//    {
//        //获取命令与数据
//        unsigned char iHostData[30];
//        g_i_Get_Usb_Mcu_Cmd = GetCmdDataOfUsbMcu(iHostData);


//        printf("GetCmdDataOfUsbMcuDeal %d\r\n",g_i_Get_Usb_Mcu_Cmd);

//        //处理命令与数据
//        switch (g_i_Get_Usb_Mcu_Cmd)
//        {
//        case HOST_CMD_SET_TIME://设置时间
//        {
//            int iSetTimeResult = iHostData[2];
//            break;
//        }
//        case HOST_CMD_TAKE_PHOTO://拍照
//        {
//            if (g_i_Stream_Usb_Flag == 1)//usb摄像头已插上
//                On_Btn_TakePhoto_Clicked();
//            break;
//        }
//        case HOST_CMD_RECORD_VIDEO://录像
//        {
//            if (g_i_Stream_Usb_Flag == 1)//usb摄像头已插上
//            {
//                if (m_i_Recording == 1)
//                {
//                    On_Btn_RecordVideo_Stop_Clicked();
//                }
//                else
//                {
//                    On_Btn_RecordVideo_Clicked();
//                }
//            }
//            break;
//        }
//        }
//        g_m_UsbMcuBuf.REC_FLAG = 0;
//    }
    if (g_m_UsbMcuBuf.REC_FLAG == 1)
    {
            //获取命令与数据
            unsigned char iHostData[30];
            g_i_Get_Usb_Mcu_Cmd = GetCmdDataOfUsbMcu(iHostData);


            printf("GetCmdDataOfUsbMcuDeal %d\r\n",g_i_Get_Usb_Mcu_Cmd);
        //    char cTempBuf[20];
            //处理命令与数据
            switch (g_i_Get_Usb_Mcu_Cmd)
            {
                  case HOST_CMD_SET_TIME://设置时间
                  {
                        int iSetTimeResult = iHostData[2];
                        break;
                  }
                  case HOST_CMD_GET_TIME://获取时间
                  {
                        int iRemainTime = 0;
                        iRemainTime |= (iHostData[2] << 24);
                        iRemainTime |= (iHostData[3] << 16);
                        iRemainTime |= (iHostData[4] << 8);
                        iRemainTime |= (iHostData[5] << 0);
                        char cTemp[30];
                        iRemainTime =  iRemainTime / 60;
                        sprintf(cTemp,"Remain %d min \r\n  ",iRemainTime);
          //              m_pLb_RemainTime->setText(cTemp);
          //              m_pLb_RemainTime->show();
                        break;
                  }
                  case HOST_CMD_TAKE_PHOTO://拍照
                  {
                        if (g_i_Stream_Usb_Flag == 1)//usb摄像头已插上
                            On_Btn_TakePhoto_Clicked();
                        break;
                  }
                  case HOST_CMD_RECORD_VIDEO://录像
                  {
                        if (g_i_Stream_Usb_Flag == 1)//usb摄像头已插上
                        {
                                if (m_i_Recording == 1)
                                {
                                    On_Btn_RecordVideo_Stop_Clicked();
                                }
                                else
                                {
                                    On_Btn_RecordVideo_Clicked();
                                }
                        }
                        break;
                  }
            }
            g_m_UsbMcuBuf.REC_FLAG = 0;
     }



}
//定时事件

void Widget::timerEvent(QTimerEvent* ev) {
    if(ev->timerId() == m_iEvent) {
        //检测usb摄像头拔插状态
        if (g_i_Check_Stream_Usb_Flag == 1)//可以开始检测usb摄像头拔插状态了
        {
               if (g_i_Stream_Usb_Flag == 0)//usb摄像头已拔掉，显示usb摄像头已经拔掉动画
                {
                    if (g_p_Usb_Mcu_Dev_handle != NULL)
                        CloseUsbMcu(1);
                    m_i_Usb_Mcu_Dev_Open_Count = 0;
               }
               else if (g_i_Stream_Usb_Flag == 1)//usb摄像头已插上，关闭usb摄像头已经拔掉动画
               {
                    if (m_i_Usb_Mcu_Dev_Open_Count <= 30)//打开UsbMcu
                    {
                        if ((m_i_Usb_Mcu_Dev_Open_Count++ % 3) == 0)//900毫秒尝试打开一次,30的话就是大概9秒
                        {
                                if (g_p_Usb_Mcu_Dev_handle == NULL)
                                    OpenUsbMcu();
                        }
                    }
               }
        }
        // 仅标记状态，移除非UI操作到子线程
//        g_i_Need_Check_Usb = 1; // 标记需要检测USB，由子线程处理
//        g_i_Need_Deal_UsbMcu = 1; // 标记需要处理命令，由子线程处理
        // 视频计时（仅在录制中更新）
        if (m_i_Recording == 1) {
            qint64 currentTime = QDateTime::currentMSecsSinceEpoch();
            qint64 elapsed = currentTime - m_i_StartRecordTime; // 已录制毫秒数

            // 转换为时分秒
            int hours = (elapsed / 3600000) % 24;
            int minutes = (elapsed / 60000) % 60;
            int seconds = (elapsed / 1000) % 60;

            // 格式化时间字符串（补零）
            QString timeText = QString("%1:%2:%3")
                    .arg(hours, 2, 10, QLatin1Char('0'))
                    .arg(minutes, 2, 10, QLatin1Char('0'))
                    .arg(seconds, 2, 10, QLatin1Char('0'));

            emit updateVideoTimeText(timeText); // 更新UI

            SDiskInfo_T mDiskInfo;
            GetDiskInfo(&mDiskInfo);

            if (mDiskInfo.iFreedisk < 10)
            {
                On_Btn_RecordVideo_Stop_Clicked();//录像停止
            }
        }
        //录像停止
        if (g_i_Rec_Video_Flag == 0)
        {
            if (m_i_Recording == 1)
                RecordVideo_Stop_Deal(0);
        }
        //旋转按钮恢复正常
        if (g_i_Rotate_Flag == 0)
        {
            if (g_S_CfgData.iRot > 0)
                zhukuang::myzhukuang->Rot_0_Deal(0);
        }
        //显示系统日期时间
        if (m_i_DateTimeShowFlag == 1)
        {
            m_i_DateTimeShowFlag = 0;
            QDateTime currentDate = QDateTime::currentDateTime();
            QString strTemp = currentDate.toString("yyyy-MM-dd hh:mm:ss");
            zhukuang::myzhukuang->setDateLabelText(strTemp);
        }
        else {
            m_i_DateTimeShowFlag = 1;
        }
       // printf("g_i_FirstCheck_Gpio_Count: %d\n", g_i_FirstCheck_Gpio_Count);
        //if (g_i_FirstCheck_Gpio_Count >= 3)//刚开机1秒左右先不检测按键
        {
            //获取Gpio按键(Mode按键检测)
            int iKeyCode = GetGpioValue(6);
            if (iKeyCode == 0)//按键检测为按下
            {
                m_i_BrightVal = 2;
                SendMsgToUvc("SetBrightness",CMD_SET_BRIGHTNESS,m_i_BrightVal,"");
                printf("#################@@@@@@@@@@\n");
            }

            //获取Gpio按键(-按键检测)
            iKeyCode = GetGpioValue(7);
            if (iKeyCode == 0)//按键检测为按下
            {
                if (m_i_BrightVal > 2)
                {
                    m_i_BrightVal -= 6;
                    SendMsgToUvc("SetBrightness",CMD_SET_BRIGHTNESS,m_i_BrightVal,"");
                }
            }

            //获取Gpio按键(+按键检测)
            iKeyCode = GetGpioValue(8);
            if (iKeyCode == 0)//按键检测为按下
            {
                if (m_i_SetBrightUp_Flag == 1)//第一次要去除
                {
                    if (m_i_BrightVal < 60)
                    {
                        m_i_BrightVal += 6;
                        SendMsgToUvc("SetBrightness",CMD_SET_BRIGHTNESS,m_i_BrightVal,"");
                    }
                }
                else
                {
                    m_i_SetBrightUp_Flag = 1;
                }
            }
        }



        //获取UsbMcu命令与数据并处理
        GetCmdDataOfUsbMcuAndDeal();
        if (g_i_TakePhoto == 1)//拍照
        {
            printf("###############333￥￥￥￥￥￥￥￥￥￥\n");
            On_Btn_TakePhoto_Clicked();
            g_i_TakePhoto = 0;
        }
    }
}

// 新增子线程处理USB检测和命令（避免阻塞主线程）
void *CheckUsbAndDealCmd(void *arg) {
    while(1) {
        if (g_i_Need_Check_Usb) {
            //检测usb摄像头拔插状态
            if (g_i_Check_Stream_Usb_Flag == 1)//可以开始检测usb摄像头拔插状态了
            {
                if (g_i_Stream_Usb_Flag == 0)//usb摄像头已拔掉，显示usb摄像头已经拔掉动画
                {
                     printf("g_i_Stream_Usb_Flag: %d\n", g_i_Stream_Usb_Flag);
                    if (g_p_Usb_Mcu_Dev_handle != NULL)
                        CloseUsbMcu(1);
                    Widget::mywidget->m_i_Usb_Mcu_Dev_Open_Count = 0;
                }
                else if (g_i_Stream_Usb_Flag == 1)//usb摄像头已插上，关闭usb摄像头已经拔掉动画
                {
                     printf("g_i_Stream_Usb_Flag: %d\n", g_i_Stream_Usb_Flag);
                    if (Widget::mywidget->m_i_Usb_Mcu_Dev_Open_Count <= 30)//打开UsbMcu
                    {
                        if ((Widget::mywidget->m_i_Usb_Mcu_Dev_Open_Count++ % 3) == 0)//900毫秒尝试打开一次,30的话就是大概9秒
                        {
                            if (g_p_Usb_Mcu_Dev_handle == NULL)
                                OpenUsbMcu();
                        }
                    }
                }
            }



            g_i_Need_Check_Usb = 0;
        }
        if (g_i_Need_Deal_UsbMcu) {
            Widget::mywidget->GetCmdDataOfUsbMcuAndDeal();
            g_i_Need_Deal_UsbMcu = 0;
        }

        usleep(100000); // 100ms轮询
    }
}





