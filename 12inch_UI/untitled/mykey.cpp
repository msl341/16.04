#include "mykey.h"
int iRemainTime=0;
int iTotalCount=0;
int usb_mcu_flag=0;

int mipi3_in_flag=-1;

bool click_key_flag;
SocketData_photo data_photo;

Time_set time_num;
int time_flag=1;

int custom_show_flag=0;
int custom1_flag=0;//0无 1白平衡  2冻结  3AE  4气泵
int custom2_flag=0;//0无 1白平衡  2冻结  3AE  4气泵
int custom3_flag=0;//0无 1白平衡  2冻结  3AE  4气泵
int sensor_flag=0;//0~1 2
int awb_atom_flag=0;//自动
int picture_flag=1;
int display_flag=1;
int language_flag=1;
//int language_flag=2;
int ae_flag=3;//1~5
int freeze_flag=0;//0~1
int rotate_flag=1;//1~5
int video_flag=0;//0~1
int led_host_flag=2;//0~4
int led_flag=2;//0~4
int pump_flag=1;//1~3

int photo_select_flag=0;
int photo_select_all_flag=0;
int photo_deselect_all_flag=0;
int photo_delete_flag=0;
int photo_totality;
int photo_num=1;
int photo_max=0;
int photo_labelnum=0;

int video_select_flag=0;
int video_select_all_flag=0;
int video_deselect_all_flag=0;
int void_delete_flag=0;//删除
int video_totality;//页面总数
int video_num=1;//当前页面
int video_max=0;//单张总数
int video_labelnum=0;//单击label记录
int  video_play_flag=1;
int progress_time=1;//0;//进度条
int progress_flag_time=0;//进度条
int hours_progress=0;
int minutes_progress=0;
int seconds_progress=0;
char playback_video_name[64];

int clicked_frames_flag=0;
int sensorless_flag=1;

int sensor_num=-1;
QStringList photo_name;
QStringList video_name;

int in_control_flag=0;//在操作界面的标志
int flag_SD = 0;
int flag_USB = 0;
int current_interface_flag=0;//1拍照预览  2拍照放大  3录像预览  4录像放大
int switchable_flag=0;

int switchable_delete_flag=0;
int zoom_num=1;
int fd_uartkey=0;//按键板串口

usb_mcu::usb_mcu(QObject *parent) : QObject(parent)
{

}

//获取UsbMcu命令与数据
int usb_mcu::GetCmdDataOfUsbMcu(uint8_t *pData)
{
     int iLen;
     int iCmd = -1;

     iCmd = g_m_UsbMcuBuf.RX_BUF_DEAL[0];
     iLen = g_m_UsbMcuBuf.RX_BUF_DEAL[1];
     memcpy((char *)pData,(char *)(g_m_UsbMcuBuf.RX_BUF_DEAL),iLen+2);

     return iCmd;
}

//获取UsbMcu命令与数据并处理
void usb_mcu::GetCmdDataOfUsbMcuAndDeal()
{
    if (g_m_UsbMcuBuf.REC_FLAG == 1)
    {
            //获取命令与数据
            unsigned char iHostData[30];
            g_i_Get_Usb_Mcu_Cmd = GetCmdDataOfUsbMcu(iHostData);

            //处理命令与数据
            switch (g_i_Get_Usb_Mcu_Cmd)
            {
                case HOST_CMD_GET_TIME_COUNT://获取时间
                {
                   //int iRemainTime = 0;
                    iRemainTime |= (iHostData[2] << 24);
                    iRemainTime |= (iHostData[3] << 16);
                    iRemainTime |= (iHostData[4] << 8);
                    iRemainTime |= (iHostData[5] << 0);

                    //int iTotalCount = 0;
                    iTotalCount |= (iHostData[6] << 24);
                    iTotalCount |= (iHostData[7] << 16);
                    iTotalCount |= (iHostData[8] << 8);
                    iTotalCount |= (iHostData[9] << 0);

                    emit update_display();

                    //char cTemp[30];
                    //iRemainTime =  iRemainTime / 60;
                    //printf("%d min %d count\r\n  ++++++++++++======",iRemainTime,iTotalCount);
                    //printf(cTemp);
                    break;
                }
                case HOST_CMD_TAKE_PHOTO://拍照
                {
                    emit  key_photo();
                    break;
                }
                case HOST_CMD_RECORD_VIDEO://录像
                {
                    emit  key_video();
                    break;
                }

            }
            g_m_UsbMcuBuf.REC_FLAG = 0;
    }
}

void usb_mcu::mythread_work()
{
USB_M:
    while(usb_mcu_flag==0)
    {
        usleep(1000*50);
    }

    pthread_mutex_init(&i_g_UsbMcuLock, NULL);

    if (g_p_Usb_Mcu_Dev_handle == NULL)
        OpenUsbMcu();

    while(1)
    {
        if(usb_mcu_flag==1)
        {
            GetCmdDataOfUsbMcuAndDeal();
        }
        else if(usb_mcu_flag==0)
        {
            iRemainTime=0;
            iTotalCount=0;
            emit update_display();
            break;
        }
        usleep(100000);
    }

    if (g_p_Usb_Mcu_Dev_handle != NULL)
        CloseUsbMcu(1);

goto USB_M;
}

rev_usb_mcu::rev_usb_mcu(QObject *parent) : QObject(parent)
{

}

void rev_usb_mcu::mythread_work()
{
    while(1)
    {
        RevDataFromUsbMcu();
    }
}



key_thread::key_thread(QObject *parent) : QObject(parent)
{

}

void key_thread::mythread_work()
{
    ADC_CONFIG_READ_ADC stCfg;
    int sar_fd = -1;
    double time_Start;
    double time_End;
    sar_fd= open("/dev/sar", O_RDWR);
    if (sar_fd < 0)
    {
       perror("/dev/sar open error\n");
    }
    ioctl(sar_fd, MS_SAR_INIT, 0);
    memset(&stCfg, 0, sizeof(ADC_CONFIG_READ_ADC));
    stCfg.channel_value=1;//sensor9734
    while (1)
    {
       ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
       //printf("qwer 9734 stCfg.adc_value=:%d\n", stCfg.adc_value);
       if (FIRST_KEY)
       {
           time_Start = (double)clock();
           while(stCfg.adc_value < 790 )
           {
               ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
               time_End = (double)clock();
               if((time_End - time_Start)/1000000.0 >= 1)
               {
                   emit first_key();
                   usleep(150*1000);
                   click_key_flag=true;
               }
           }
           time_End = (double)clock();
           if ((time_End - time_Start)/1000000.0 < 1)
           {
               emit first_key();
               click_key_flag=true;
           }
       }
       else if (SECOND_KEY)
       {
           time_Start = (double)clock();
           while(stCfg.adc_value < 790 )
           {
               ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
               time_End = (double)clock();
               if((time_End - time_Start)/1000000.0 >= 1)
               {
                   emit second_key();
                   usleep(150*1000);
                   click_key_flag=true;
               }
           }
           time_End = (double)clock();
           if ((time_End - time_Start)/1000000.0 < 1)
           {
               emit second_key();
               click_key_flag=true;
           }
       }
       else if (THIRD_KEY)
       {
           time_Start = (double)clock();
           while(stCfg.adc_value < 790 )
           {
               ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
               time_End = (double)clock();
               if((time_End - time_Start)/1000000.0 >= 1)
               {
                   emit third_key();
                   usleep(150*1000);
                   click_key_flag=true;
               }
           }
           time_End = (double)clock();
           if ((time_End - time_Start)/1000000.0 < 1)
           {
               emit third_key();
               click_key_flag=true;
           }
       }
       else if (FOURTH_KEY)
       {
           time_Start = (double)clock();
           while(stCfg.adc_value < 790 )
           {
               ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
               time_End = (double)clock();
               if((time_End - time_Start)/1000000.0 >= 1)
               {
               emit fourth_key_long();
                   usleep(150*1000);
                   click_key_flag=true;
               }
           }
           time_End = (double)clock();
           if ((time_End - time_Start)/1000000.0 < 1)
           {
               emit fourth_key();
               click_key_flag=true;
           }
       }
       else if(INSERTION_KEY && mipi1_flag==1)
       {
           mipi1_flag=0;
           unmipi1_flag=1;
           emit insertion_key();
       }
       else if(PULL_OUT_KEY && unmipi1_flag==1)
       {
           mipi1_flag=1;
           unmipi1_flag=0;
           if(!init){
               emit uninsertion_key();
           }
           else{
               init = false;
           }
       }
       click_key_flag=false;
       usleep(1000*100);
    }
    close(sar_fd);
}

key_thread_mipi0::key_thread_mipi0(QObject *parent) : QObject(parent)
{

}

void key_thread_mipi0::mythread_work()
{
    ADC_CONFIG_READ_ADC stCfg;
    int sar_fd = -1;
    double time_Start;
    double time_End;
    sar_fd= open("/dev/sar", /*O_RDONLY*/O_RDWR);
    if (sar_fd < 0)
    {
       perror("/dev/sar open error\n");
    }
    ioctl(sar_fd, MS_SAR_INIT, 0);
    memset(&stCfg, 0, sizeof(ADC_CONFIG_READ_ADC));
    stCfg.channel_value=0;//sensor6946
    while (1)
    {
       ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
       //printf("qwer 6946 stCfg.adc_value=:%d\n", stCfg.adc_value);
       if (MIPI0_KEY)
       {
           time_Start = (double)clock();
           while(stCfg.adc_value < 600 )
           {
               ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
               time_End = (double)clock();
               if((time_End - time_Start)/1000000.0 >= 1)
               {
                   emit first_long_key();
                   usleep(150*1000);
                   click_key_flag=true;
               }
           }
           time_End = (double)clock();
           if ((time_End - time_Start)/1000000.0 < 1)
           {
               emit first_key();
               click_key_flag=true;
           }
       }
       else if(INSERTION_MIPI0_KEY && mipi0_flag==1)
       {
           mipi0_flag=0;
           unmipi0_flag=1;
           emit insertion_key();
       }
       else if(PULL_OUT_MIPI0_KEY && unmipi0_flag==1)
       {
           mipi0_flag=1;
           unmipi0_flag=0;
           if(!init){
               emit uninsertion_key();
           }
           else{
               init = false;
           }
       }
       click_key_flag=false;
       usleep(1000*100);
    }
    close(sar_fd);
}

key_thread_mipi3::key_thread_mipi3(QObject *parent) : QObject(parent)
{

}

void key_thread_mipi3::mythread_work()
{
    ADC_CONFIG_READ_ADC stCfg;
    int sar_fd = -1;
//    double time_Start;
//    double time_End;
    sar_fd= open("/dev/sar", /*O_RDONLY*/O_RDWR);
    if (sar_fd < 0)
    {
       perror("/dev/sar open error\n");
    }
    ioctl(sar_fd, MS_SAR_INIT, 0);
    memset(&stCfg, 0, sizeof(ADC_CONFIG_READ_ADC));
    stCfg.channel_value=3;//sensor290
    while (1)
    {
        ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
        //printf("qwer 290 stCfg.adc_value=:%d\n", stCfg.adc_value);
        if(INSERTION_MIPI3_KEY && mipi3_flag==1)
        {
           mipi3_flag=0;
           unmipi3_flag=1;
           mipi3_in_flag=1;
           emit insertion_key();
        }
        else if(PULL_OUT_MIPI3_KEY && unmipi3_flag==1)
        {
           mipi3_flag=1;
           unmipi3_flag=0;
           mipi3_in_flag=0;
           if(!init){
               emit uninsertion_key();
           }
           else{
               init = false;
           }
        }
        click_key_flag=false;
        usleep(1000*100);
    }
    close(sar_fd);
}

void key_thread_290::open_uart(char *file)
{
    fd_uart1 =open(file,O_RDWR|O_NOCTTY|O_NDELAY);

    if(fd_uart1==-1){
        printf("Benis:open %s fail\n",file);
        return;
    }
    if(fcntl(fd_uart1,F_SETFL,0)<0){
        printf("Benis:fcntl faild!\n");
    }
    isatty(STDIN_FILENO);
}
void key_thread_290::init_uart(int baudrate_cmd)
{
    struct termios opt;

    tcgetattr(fd_uart1,&opt);
    switch(baudrate_cmd)
    {
        case 0:
            cfsetispeed(&opt,B4800);
            cfsetospeed(&opt,B4800);
            printf("Benis:baudrate = 4800 \n");
            break;
        case 1:
            cfsetispeed(&opt,B9600);
            cfsetospeed(&opt,B9600);
            printf("Benis:baudrate = 9600 \n");
            break;
        case 2:
            cfsetispeed(&opt,B115200);
            cfsetospeed(&opt,B115200);
            printf("Benis:baudrate = 115200 \n");
            break;
    }

    //add
    opt.c_iflag &= ~(ICRNL | IXON);
    opt.c_cflag &= ~CSIZE;
    opt.c_cflag |= CS8;
    opt.c_cflag |= CLOCAL|CREAD;
    opt.c_cflag &= ~PARENB;
    opt.c_iflag &= ~INPCK;
    opt.c_cflag &= ~CSTOPB;
    opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    opt.c_cc[VTIME]=1;//0
    opt.c_cc[VMIN]=5;//0  22


    opt.c_iflag &= ~(INLCR | ICRNL | IGNCR);
    opt.c_oflag &= ~(ONLCR | OCRNL | ONOCR | ONLRET);

    tcflush(fd_uart1,TCIOFLUSH);

    tcsetattr(fd_uart1,TCSANOW,&opt);
}
void key_thread_290::close_uart()
{
    if(fd_uart1!=-1)
        close(fd_uart1);
}
int key_thread_290::uart_send_fv()
{
    int baudrate_opt=2,tty_port=3;
    char file_name[20];
    memset(file_name,0,sizeof(file_name));
    sprintf(file_name,"%s%d","/dev/ttyS",tty_port);
    printf("Benis:file name is %s\n",file_name);
    open_uart(file_name);

    init_uart(baudrate_opt);
    return 0;
}
key_thread_290::key_thread_290(QObject *parent) : QObject(parent)
{

}
void key_thread_290::mythread_work()
{
    char take_photo[] =  {0x03,0x33,0x01,0x01,0x03};
    char take_video[] =  {0x03,0x33,0x02,0x01,0x03};
    char zoom_in[] 	  =  {0x03,0x33,0x03,0x01,0x03};
    char zoom_out[]   =  {0x03,0x33,0x04,0x01,0x03};
    char rec_buf[64];
    int ret = 0;

    uart_send_fv();

    while(1)
    {
        usleep(1000*50);
        memset(rec_buf,0,sizeof(rec_buf));
        ret = read(fd_uart1,rec_buf,sizeof(rec_buf));
        if(ret > 0)
        {
            if(strncmp(take_photo,rec_buf,sizeof(take_photo)) == 0)
            {
                printf("======3986===%s==\n",take_photo);
                emit key_photo();
            }
            else if(strncmp(take_video,rec_buf,sizeof(take_video)) == 0)
            {
                printf("======3986===video  %s==\n",take_video);
                emit key_video();
            }
            else if(strncmp(zoom_in,rec_buf,sizeof(zoom_in)) == 0)
            {
                printf("======3986===zoom_in  %s==\n",zoom_in);
                emit key_zoom_in();
            }
            else if(strncmp(zoom_out,rec_buf,sizeof(zoom_out)) == 0)
            {
                printf("======3986===zoom_out  %s==\n",zoom_out);
                emit key_zoom_out();
            }
        }
        else
        {
            printf("=====没读到东西=====\n");
        }
        usleep(1000*50);
    }
}


void shortcut_key::open_uart(char *file)
{
    fd_uartkey =open(file,O_RDWR|O_NOCTTY|O_NDELAY);

    if(fd_uartkey==-1){
        printf("Benis:open %s fail\n",file);
        return;
    }
    if(fcntl(fd_uartkey,F_SETFL,0)<0){
        printf("Benis:fcntl faild!\n");
    }
    isatty(STDIN_FILENO);
}
void shortcut_key::init_uart(int baudrate_cmd)
{
    struct termios opt;

    tcgetattr(fd_uartkey,&opt);
    switch(baudrate_cmd)
    {
        case 0:
            cfsetispeed(&opt,B4800);
            cfsetospeed(&opt,B4800);
            printf("Benis:baudrate = 4800 \n");
            break;
        case 1:
            cfsetispeed(&opt,B9600);
            cfsetospeed(&opt,B9600);
            printf("Benis:baudrate = 9600 \n");
            break;
        case 2:
            cfsetispeed(&opt,B115200);
            cfsetospeed(&opt,B115200);
            printf("Benis:baudrate = 115200 \n");
            break;
    }

    //add
    opt.c_iflag &= ~(ICRNL | IXON);
    opt.c_cflag &= ~CSIZE;
    opt.c_cflag |= CS8;
    opt.c_cflag |= CLOCAL|CREAD;
    opt.c_cflag &= ~PARENB;
    opt.c_iflag &= ~INPCK;
    opt.c_cflag &= ~CSTOPB;
    opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    opt.c_cc[VTIME]=1;//0
    opt.c_cc[VMIN]=5;//0  22


    opt.c_iflag &= ~(INLCR | ICRNL | IGNCR);
    opt.c_oflag &= ~(ONLCR | OCRNL | ONOCR | ONLRET);

    tcflush(fd_uartkey,TCIOFLUSH);

    tcsetattr(fd_uartkey,TCSANOW,&opt);
}
void shortcut_key::close_uart()
{
    if(fd_uartkey!=-1)
        close(fd_uartkey);
}
int shortcut_key::uart_send_fv()
{
    int baudrate_opt=2,tty_port=1;
    char file_name[20];
    memset(file_name,0,sizeof(file_name));
    sprintf(file_name,"%s%d","/dev/ttyS",tty_port);
    printf("Benis:file name is %s\n",file_name);
    open_uart(file_name);

    init_uart(baudrate_opt);
    return 0;
}
shortcut_key::shortcut_key(QObject *parent) : QObject(parent)
{

}
void shortcut_key::mythread_work()
{
    char rec_buf[64];
    int ret = 0;
    uart_send_fv();
    while(1)
    {
        memset(rec_buf,0,sizeof(rec_buf));
        ret = read(fd_uartkey,rec_buf,sizeof(rec_buf));
        if(ret > 0)
        {
//            printf("========%s========\n",rec_buf);
            if(strcmp(rec_buf, "Kp")==0)
            {
                printf("========S1========\n");
                emit key_photo();
            }
            else if(strcmp(rec_buf, "KR")==0)
            {
                printf("========S2========\n");
                emit key_video();
            }
            else if(strcmp(rec_buf, "KF")==0)
            {
                printf("========S3========\n");
                emit key_freeze();
            }
            else if(strcmp(rec_buf, "KM")==0)
            {
                printf("========S4========\n");
                emit key_mode();
            }
            else if(strcmp(rec_buf, "KD")==0)
            {
                printf("========S5========\n");
                emit key_led_minus();
            }
            else if(strcmp(rec_buf, "KU")==0)
            {
                printf("========S6========\n");
                emit key_led_add();
            }
            else if(strcmp(rec_buf, "KP")==0)
            {
                printf("========S7========\n");
                emit key_pump();
            }
            else if(strcmp(rec_buf, "KA")==0)
            {
                printf("========S8========\n");
                emit key_wb();
            }
            else if(strcmp(rec_buf, "KZ")==0)
            {
                printf("========S9========\n");
                emit key_zoom();
            }
            else
            {
                printf("========S110========\n");
            }
        }
        else
        {
            printf("========no=========\n");
        }
        usleep(1000*100);
    }
}

//容量检测
int check_disk()
{
    struct statfs diskInfo;

    int kjd_ret;

    if(flag_USB==1)
    {
        kjd_ret = statfs("/mnt/USB_FLASH", &diskInfo);
        if (0 != kjd_ret)
        {
            printf("statfs fail! usb\n");
            return -1;
        }
    }
    else if(flag_USB==0 && flag_SD==1)
    {
        kjd_ret = statfs("/mnt/SD_CARD", &diskInfo);
        if (0 != kjd_ret)
        {
            printf("statfs fail! sd\n");
            return -1;
        }
    }

    unsigned long long blocksize = diskInfo.f_bsize; //每个block里包含的字节数

    unsigned long long totalsize = blocksize * diskInfo.f_blocks; //总的字节数，f_blocks为block的数目

    unsigned long long freeDisk = diskInfo.f_bfree * blocksize; //剩余空间的大小

    unsigned long long availableDisk = diskInfo.f_bavail * blocksize; //可用空间大小

    if(freeDisk>>20 < 200)
        return -1;
    return 0;
}

void simulateClick(QWidget* widget, const QPoint& localPos) {
    // 取得 widget 相對應的全域座標
    QPoint globalPos = widget->mapToGlobal(localPos);
    // 模擬滑鼠按下事件
    QMouseEvent pressEvent(QEvent::MouseButtonPress, localPos, globalPos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    bool pressed = QCoreApplication::sendEvent(widget, &pressEvent);

    // 模擬滑鼠釋放事件
    QMouseEvent releaseEvent(QEvent::MouseButtonRelease, localPos, globalPos, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    bool released = QCoreApplication::sendEvent(widget, &releaseEvent);

//    qDebug() << "Press event sent:" << pressed << ", Release event sent:" << released;
}

DraggableGraphicsView::DraggableGraphicsView(QWidget *parent)
{
    parentptr = parent;
}

void DraggableGraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        lastMousePosition = event->pos();
    }
    QGraphicsView::mousePressEvent(event);
}

void DraggableGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (isDragging) {
        // Calculate the offset of mouse movement
        QPoint delta = event->pos() - lastMousePosition;
        lastMousePosition = event->pos();

        // scroll the scroll bar
        verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
        QPixmapCache::clear();
    }
    QGraphicsView::mouseMoveEvent(event);
}

void DraggableGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
    }
    QGraphicsView::mouseReleaseEvent(event);
}



DraggableListWidget::DraggableListWidget(QWidget *parent)
{
    parentptr = parent;
}

void DraggableListWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        lastMousePosition = event->pos();
    }
    QListWidget::mousePressEvent(event);
}

void DraggableListWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (isDragging) {
        // Calculate the offset of mouse movement
        QPoint delta = event->pos() - lastMousePosition;
        lastMousePosition = event->pos();
        floatDelta += (delta.y() / 10.0);

        // scroll the scroll bar
        if(floatDelta >= 1 || floatDelta <= -1){
            verticalScrollBar()->setValue(verticalScrollBar()->value() - floatDelta);
            floatDelta = 0.0;
        }

        QPixmapCache::clear();
    }
    QListWidget::mouseMoveEvent(event);
}

void DraggableListWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
    }
    QListWidget::mouseReleaseEvent(event);
}

DraggableWidget::DraggableWidget(QWidget *parent)
{
    parentptr = parent;
}

void DraggableWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = true;
        lastMousePosition = event->pos();
    }
    QWidget::mousePressEvent(event);
}

void DraggableWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (isDragging) {
        // Calculate the offset of mouse movement
        QPoint delta = event->pos() - lastMousePosition;
        lastMousePosition = event->pos();

        // scroll the scroll bar
        int x = this->x() - delta.x();
        int y = this->y() - delta.y();
        setGeometry(x, y, this->width(), this->height());
    }
    QWidget::mouseMoveEvent(event);
}

void DraggableWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        isDragging = false;
    }
    QWidget::mouseReleaseEvent(event);
}

Battery::Battery(QObject *parent) : QObject(parent)
{
    qDebug() << "init setting";
    system("echo 44 > /sys/class/gpio/export");
    system("echo in > /sys/class/gpio/gpio44/direction");
    sar_fd = open("/dev/sar", O_RDWR);
    if (sar_fd < 0)
    {
       perror("/dev/sar open error\n");
    }
    ioctl(sar_fd, MS_SAR_INIT, 0);
    memset(&stCfg, 0, sizeof(ADC_CONFIG_READ_ADC));
    stCfg.channel_value = 2; //battery
    for(int i = 0; i < 10; i++){
        stCfg.channel_value = 2;
        ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
        batVal[i] = stCfg.adc_value;
    }
//    QFile file("/customer/output.csv");
//    if (file.exists()) {
//        if (file.remove()) {
//            qDebug() << "remove csv : " << "/customer/output.csv";
//        } else {
//            qDebug() << "remove csv error : " << file.errorString();
//            return;
//        }
//    }

//    // 創建新的檔案並寫入資料
//    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
//        qDebug() << "create csv error:" << file.errorString();
//        return;
//    }
//    else{
//        QTextStream out(&file);
//        out << "count," << "BatADC," << "Avg," << ",\n";
//        file.close();
//    }
}

void Battery::batteryCheck()
{
    int index = 0, batAvgVal = 0, count = 1;
    while(1){
//        QFile file("/customer/output.csv");
//        if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
//        {
//            qDebug("Cannot open file for writing: %s",qPrintable(file.errorString()));
//            return;
//        }
//        QTextStream out(&file);

        GpioFile = fopen("/sys/class/gpio/gpio44/value","r"); //Charge
        if(NULL != GpioFile)
        {
            fread(&ChargeGpioVal, 1, 1, GpioFile);
//            qDebug() << "ChargeGpioVal : " << ChargeGpioVal;
            if('1' == ChargeGpioVal)
            {
                ChargeMode = true;
            }
            else{
                ChargeMode = false;
            }
            fclose(GpioFile);
        }
        else{
            qDebug() << "error on open gpio";
        }
        batAvgVal = 0;
        stCfg.channel_value = 2;
        ioctl(sar_fd, MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC, &stCfg);
        batVal[index] = stCfg.adc_value;
        for(int i = 0; i < 10; i++){
            batAvgVal += batVal[i];
        }
        batAvgVal = batAvgVal / 10;
//        qDebug() << "count : " << count
//                 << ", BatADC : " << stCfg.adc_value
//                 << ", Avg : " << batAvgVal;

//        out << count << "," << stCfg.adc_value << "," << batAvgVal << "\n";

        index ++;
        count ++;
        if(index == 10){
            index = 0;
        }

        if(!ChargeMode){
            if(batAvgVal > 828){
                emit batteryStatus(4);
            }
            else if(batAvgVal > 773 && batAvgVal <= 828){
                emit batteryStatus(3);
            }
            else if(batAvgVal > 718 && batAvgVal <= 773){
                emit batteryStatus(2);
            }
            else if(batAvgVal > 663 && batAvgVal <= 718){
                emit batteryStatus(1);
                if(!isWarning){
                    emit warning();
                    isWarning = true;
                }
            }
            else{
                emit batteryStatus(1);
                if(!isWarning){
                    emit warning();
                    isWarning = true;
                }
            }
        }
        else{
            emit charging();
        }
//        file.close();
        usleep(1000 * 3000);
    }
}
