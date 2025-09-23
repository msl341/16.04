#include "UsbMcu.h"
#include <linux/input.h>
#include "zhukuang.h"

//配置信息
San_S_CfgData g_S_CfgData;

//文件路径
char g_c_FilePath[500];
//文件序号
int g_i_FileIndex;
//消息全局变量
SMsgGlobalVal_T  mMsgGlobalVal;

//拍照
qint8 g_i_TakePhoto = 0;
//usb摄像头拔插状态
qint8 g_i_Stream_Usb_Flag = 1;

//usb摄像头拔插状态可否检测标志
qint8 g_i_Check_Stream_Usb_Flag = 0;

//usb摄像头断开窗口是否打开标志
qint8 g_i_Win_UsbCamera_Out_OpenFlag = 0;
//录像状态标志
qint8 g_i_Rec_Video_Flag = 0;
//电压检测驱动文件句柄
int g_i_Vol_Fd = -1;
//摄像头旋转标志
qint8 g_i_Rotate_Flag = 0;
//电压显示标志
qint8 g_i_Show_Vol_Flag = -1;

//电压可否检测标志
qint8 g_i_Check_Vol_Flag = 0;
//刚开机检测按键前的等待计数
qint8 g_i_FirstCheck_Gpio_Count = 0;


//电压值
float g_f_Vol = 0.01;

//录像文件总时间长度(秒)
int g_i_Video_Player_Time;

//接收消息线程ID
pthread_t g_t_Revmsg_Tid;

//接收UsbMcu线程ID
pthread_t g_t_RevUsbMcu_Tid;

//关机线程ID
pthread_t g_t_Close_Tid;

//监控线程ID
pthread_t g_t_Monitor_Tid;

//UsbMcu设备变量
libusb_device **g_pp_Usb_Mcu_Devs;	//pointer to pointer of device, used to retrieve a list of devices
libusb_context *g_p_Usb_Mcu_Ctx = NULL; //a libusb session
libusb_device_handle *g_p_Usb_Mcu_Dev_handle = NULL;
//UsbMcu缓存
SUSB_MCU_BUF_T g_m_UsbMcuBuf;
//发送和接收UsbMcu命令和数据各变量
qint8 g_i_Send_Usb_Mcu_Flag;
int g_i_Usb_Mcu_Cmd;
unsigned char g_i_Usb_Mcu_Data[30];
int g_i_Usb_Mcu_Len;
unsigned long g_i_Send_Usb_Mcu_StartTime;
qint8 g_i_Send_Usb_Mcu_Count;
int g_i_Get_Usb_Mcu_Cmd;

pthread_mutex_t i_g_UsbMcuLock;
//转为设备位置(DevRect)
San_S_DevRect San_F_DevRect(int x,int y,int w,int h)
{
    San_S_DevRect mDevRect;
    mDevRect.x = ((double)x / (double)SAN_SCREEN_WIDTH) * (double)SAN_DEV_WIDTH;
    mDevRect.y = ((double)y / (double)SAN_SCREEN_HIGHT) * (double)SAN_DEV_HIGHT;
    mDevRect.w = ((double)w / (double)SAN_SCREEN_WIDTH) * (double)SAN_DEV_WIDTH;
    mDevRect.h = ((double)h / (double)SAN_SCREEN_HIGHT) * (double)SAN_DEV_HIGHT;
    return mDevRect;
}
//初始化消息
int IniMsg(int *pid,int msgkey)
{
#ifdef SYS_WIN
#else
    if (*pid < 0)
    {
        // 获取或者创建一个key，并设置权限
        *pid = msgget(msgkey, IPC_CREAT | 0666);
        if (*pid == -1) {
            printf("msgget fail, id = %d\n", *pid);
            return -1;
        }
        else {
            printf("msgget success, id = %d\n", *pid);
        }
    }
#endif
    return 0;
}

//初始化Config
void San_InitConfig(San_S_CfgData *pSCfgData)
{
    pSCfgData->iAe = 1;//曝光
    pSCfgData->iRot = 0;//翻转
    pSCfgData->iDrawShape = DS_FX;//画图形状
    pSCfgData->iLanSetLan = LAN_SIMPLE_CH;//语言设置
}
//写Config
void San_WriteConfig(San_S_CfgData *pSCfgData)
{
    QJsonObject jSonObj;

    jSonObj.insert("Ae",pSCfgData->iAe);//曝光
    jSonObj.insert("Rot",pSCfgData->iRot);//翻转
    jSonObj.insert("DrawShape",pSCfgData->iDrawShape);//画图形状
    jSonObj.insert("LanSet",pSCfgData->iLanSetLan);//语言设置

    QJsonDocument jSonDocu(jSonObj);
    QByteArray jSonData = jSonDocu.toJson();

    QFile mFile(SAN_PATH_CFG);
    if(mFile.open(QIODevice::WriteOnly)){
        mFile.write(jSonData);
        mFile.close();

        system("sync");
    }
}
//读Config
void San_ReadConfig(San_S_CfgData *pSCfgData)
{
    San_InitConfig(pSCfgData);
    QFile mFile(SAN_PATH_CFG);
    QByteArray jSonData;
    if(mFile.open(QIODevice::ReadOnly)){
        jSonData = mFile.readAll();
        mFile.close();
    }

    QJsonDocument jSonDocu = QJsonDocument::fromJson(jSonData);

    if(jSonDocu.isObject()){
        QJsonObject objRoot = jSonDocu.object();
        QStringList keys = objRoot.keys();
        QJsonValue Value;
        for(auto key : keys)
        {
            Value = objRoot.value("Ae");//曝光
            if (!(Value.isUndefined()))
                pSCfgData->iAe = Value.toInt();
            Value = objRoot.value("Rot");//翻转
            if (!(Value.isUndefined()))
                pSCfgData->iRot = Value.toInt();
            if (pSCfgData->iRot == 0)
                g_i_Rotate_Flag = 0;
            else
                g_i_Rotate_Flag = 1;
            Value = objRoot.value("DrawShape");//画图形状
            if (!(Value.isUndefined()))
                pSCfgData->iDrawShape = Value.toInt();
            Value = objRoot.value("LanSet");//语言设置
            if (!(Value.isUndefined()))
                pSCfgData->iLanSetLan = Value.toInt();
        }
    }
}
//接收消息
int RevMsg(int *pid,int msgkey,SMsgBuf_T *pmsg)
{
    int iRet = -1;
    int msgtype = 1;

#ifdef SYS_WIN
#else
    if (*pid < 0)
    {
        // 获取或者创建一个key，并设置权限
        *pid = msgget(msgkey, IPC_CREAT | 0666);
        if (*pid == -1) {
            printf("msgget fail, id = %d\n", *pid);
            return -1;
        }
        else {
            printf("msgget success, id = %d\n", *pid);
        }
    }

    //接收消息
    iRet = msgrcv(*pid, pmsg, sizeof(pmsg->cText), msgtype, 0);//IPC_NOWAIT
#endif
    return iRet;
}

//发送消息
int SendMsg(int *pid,int msgkey,SMsgBuf_T *pmsg,int iLen)
{
    int iRet = -1;
    int msgtype = 1;

    if (*pid < 0)
    {
        // 获取或者创建一个key，并设置权限
        *pid = msgget(msgkey, IPC_CREAT | 0666);
        if (*pid == -1) {
            printf("msgget fail, id = %d\n", *pid);
            return -1;
        }
        else {
            printf("msgget success, id = %d\n", *pid);
        }
    }

    pmsg->lType = msgtype;
    if (msgsnd(*pid, pmsg, iLen, IPC_NOWAIT) == -1){
        qDebug() << "消息队列满，暂时缓存";
        iRet = 0;
    }
    else
        iRet = 1;




    return iRet;
}



//接收消息从Uvc
void *RevMseFromUvc(void *arg)
{
    unsigned char *pBuf;
    SMsgBuf_T mMsgBuf;
    while (1)
    {
        if (RevMsg(&(mMsgGlobalVal.qRecvTKId),mMsgGlobalVal.iRecvTKMsgkey,&mMsgBuf) > 0)//接收消息
        {
            SMenu_Msg_T* pMenuMsg = (SMenu_Msg_T*)(mMsgBuf.cText + sizeof(Comm_Header_T));
            printf("ui get cmd = %s flag = %d var = %d\n",pMenuMsg->cCmd,pMenuMsg->iFlag,pMenuMsg->iVar);

            switch (pMenuMsg->iFlag)
            {
                case CMD_STREAM_USB_FLAG://usb摄像头拔插状态
                {
                    g_i_Stream_Usb_Flag = pMenuMsg->iVar;
                    printf("g_iStream_Usb_Flag = %d\n",g_i_Stream_Usb_Flag);
                    if (g_i_Stream_Usb_Flag == 0) {
                           // 隐藏label_18
                        emit zhukuang::myzhukuang->sigSetLabel18Visible(false);
                       } else {
                           // 显示label_18
                        emit zhukuang::myzhukuang->sigSetLabel18Visible(true);
                       }

                    break;
                }
                case CMD_VIDEO_PLAYER_TIME://播放时间长度(秒)
                {
                    g_i_Video_Player_Time = pMenuMsg->iVar/1000000;
                    printf("*************************%d",g_i_Video_Player_Time);
                    break;
                }
                case CMD_TAKE_PHOTO_FILE://拍照返回的文件名
                {
                    char cPhoto[120];
                    char cPhotoSmall[120];

                    if (strcmp(pMenuMsg->cCmd,"TakePhoto") == 0)//拍照返回的相片
                    {
                        sprintf(cPhoto,"%s%s",PATH_PHOTO,pMenuMsg->cText);
                    }
                    else//录像返回的相片
                    {
                        sprintf(cPhoto,"%s%s",PATH_PHOTO,pMenuMsg->cText);
                        sprintf(cPhotoSmall,"%s%s",PATH_VIDEO_SMALL,pMenuMsg->cText);
                        char cTemp[130];
                        sprintf(cTemp,"mv %s %s",cPhoto,cPhotoSmall);
                        system(cTemp);
                        system("sync");
                    }
                    break;
                }
                case CMD_REC_VIDEO_FLAG://录像状态
                {
                    g_i_Rec_Video_Flag = pMenuMsg->iVar;
                    break;
                }
                case CMD_ROTATE_FLAG://摄像头旋转状态
                {
                    g_i_Rotate_Flag = pMenuMsg->iVar;
                    break;
                }
            }



        }
    }
    return 0;
}
//发送消息给Uvc
void SendMsgToUvc(char *pCmd,int iFlag,int iVar,char *pText)
{
    SMsgBuf_T mMsgBuf;
    Comm_Header_T* pCommHeader = (Comm_Header_T*)(mMsgBuf.cText);
    pCommHeader->iType = 0;
    pCommHeader->iTotal = 1;
    pCommHeader->iIndex = 0;
    pCommHeader->iSize = sizeof(SMenu_Msg_T);
    SMenu_Msg_T* pMenuMsg = (SMenu_Msg_T*)(mMsgBuf.cText + sizeof(Comm_Header_T));
    strcpy(pMenuMsg->cCmd,pCmd);
    pMenuMsg->iFlag = iFlag;
    pMenuMsg->iVar = iVar;
    strcpy(pMenuMsg->cText,pText);
    SendMsg(&(mMsgGlobalVal.qSendTKId),mMsgGlobalVal.iSendTKMsgkey,&mMsgBuf,sizeof(Comm_Header_T) + sizeof(SMenu_Msg_T));
}



//打开UsbMcu
int OpenUsbMcu()
{
    int r;				//for return values
    ssize_t cnt;		//holding number of devices in list
    r = libusb_init(&g_p_Usb_Mcu_Ctx);	//initialize a library session
    if(r < 0)
    {
        printf("Init Error \r\n");
        g_p_Usb_Mcu_Dev_handle = NULL;
        return -1;
    }

    libusb_set_debug(g_p_Usb_Mcu_Ctx, 3); //set verbosity level to 3, as suggested in the documentation
    cnt = libusb_get_device_list(g_p_Usb_Mcu_Ctx, &g_pp_Usb_Mcu_Devs); //get the list of devices
    if(cnt < 0)
    {
        printf("Get Device Error\r\n"); //there was an error
    }

    g_p_Usb_Mcu_Dev_handle = libusb_open_device_with_vid_pid(g_p_Usb_Mcu_Ctx, 0x04d9, 0xb534);

    if(g_p_Usb_Mcu_Dev_handle == NULL)
    {
        printf("Cannot open device\r\n");
        libusb_free_device_list(g_pp_Usb_Mcu_Devs, 1); //free the list, unref the devices in it
        //  libusb_exit(g_p_Usb_Mcu_Ctx);	//close the session
        g_p_Usb_Mcu_Dev_handle = NULL;
        return -2;
    }
    else
    {
        printf("Device Opened\r\n");
        libusb_free_device_list(g_pp_Usb_Mcu_Devs, 1);	//free the list, unref the devices in it
        if(libusb_kernel_driver_active(g_p_Usb_Mcu_Dev_handle, 0) == 1) { //find out if kernel driver is attached
            printf("Kernel Driver Active\r\n");

            if(libusb_detach_kernel_driver(g_p_Usb_Mcu_Dev_handle, 0) == 0) //detach it
                printf("Kernel Driver Detached!\r\n");
        }
        r = libusb_claim_interface(g_p_Usb_Mcu_Dev_handle, 0);	//claim interface 0 (the first) of device (mine had jsut 1)
        if(r < 0) {
            printf("Cannot Claim Interface\r\n");
            g_p_Usb_Mcu_Dev_handle = NULL;
            return -3;
        }
        printf("Claimed Interface\r\n");
    }
    return 0;
}


//接收数据从UsbMcu
void *RevDataFromUsbMcu(void *arg)
{
    int size;
    int iStartFlag = 0;
    int iPos;
    int iIndex;
    int iLen;
    int iFlagFlag = 1;

    unsigned char datain[USB_MCU_MAX_RX_LEN]="\0";
    while (1)
    {
        if (g_p_Usb_Mcu_Dev_handle == NULL)
        {
            g_m_UsbMcuBuf.REC_COUNT = 0;
            iStartFlag = 0;
            usleep(20000);
            iFlagFlag = 1;
            continue;
        }

        if (iFlagFlag == 1)
        {
            usleep(2000000);
            iFlagFlag = 2;
        }

        // 向指定端点接收数据
        pthread_mutex_lock(&i_g_UsbMcuLock);
        int rr = libusb_bulk_transfer(g_p_Usb_Mcu_Dev_handle,
                0x83,
                datain,
                1024,
                &size,
                1000);
        pthread_mutex_unlock(&i_g_UsbMcuLock);
        if (rr >= 0)
        {
                for(int j=0; j<size; j++)
                {
                    printf("usb_mcu_prn rev %x\r\n",datain[j]);

                    g_m_UsbMcuBuf.RX_BUF[g_m_UsbMcuBuf.REC_COUNT] = datain[j];
                    g_m_UsbMcuBuf.REC_COUNT++;
                    if (g_m_UsbMcuBuf.REC_COUNT >= 2 )//检测并获取数据
                    {
                        if (g_m_UsbMcuBuf.REC_COUNT >= (USB_MCU_MAX_RX_LEN-10))//不正常数据，抛弃该数据，重新接收
                        {
                            g_m_UsbMcuBuf.REC_COUNT = 0;
                            g_m_UsbMcuBuf.REC_FLAG = 0;
                            iStartFlag = 0;
                            continue;
                        }

                        if (iStartFlag == 0)//表示检测起始符号
                        {
                              if ((g_m_UsbMcuBuf.RX_BUF[g_m_UsbMcuBuf.REC_COUNT-2] == 0xAA)&&(g_m_UsbMcuBuf.RX_BUF[g_m_UsbMcuBuf.REC_COUNT-1] == 0x55))//表示检测到起始符号
                              {
                                  g_m_UsbMcuBuf.REC_FLAG = 0;
                                  iStartFlag = 1;
                              }
                        }
                        else if (iStartFlag == 1)//表示获取命令
                        {
                              iPos = 0;
                              g_m_UsbMcuBuf.RX_BUF_DEAL[iPos++] = g_m_UsbMcuBuf.RX_BUF[g_m_UsbMcuBuf.REC_COUNT - 1];
                              iStartFlag = 2;
                        }
                        else if (iStartFlag == 2)//表示获取长度
                        {
                              iLen = g_m_UsbMcuBuf.RX_BUF[g_m_UsbMcuBuf.REC_COUNT - 1];

                              if (iLen >=  (USB_MCU_MAX_RX_LEN-10))//表示不正常数据，抛弃该数据，重新接收
                              {
                                  g_m_UsbMcuBuf.REC_COUNT = 0;
                                  g_m_UsbMcuBuf.REC_FLAG = 0;
                                  iStartFlag = 0;
                              }
                              else//表示正常数据
                              {
                                  iIndex = g_m_UsbMcuBuf.REC_COUNT;
                                  g_m_UsbMcuBuf.RX_BUF_DEAL[iPos++] = iLen;
                                  iStartFlag = 3;
                                  if (iLen == 0)//表示数据获取完成
                                  {
                                      g_m_UsbMcuBuf.RX_BUF_DEAL_COUNT = 2;
                                      g_m_UsbMcuBuf.REC_COUNT = 0;
                                      g_m_UsbMcuBuf.REC_FLAG = 1;
                                      iStartFlag = 0;
                                      printf("UsbMcu Rev Data Complete\r\n");
                                  }
                              }
                        }
                        else if (iStartFlag == 3)//表示获取数据
                        {
                              if ((g_m_UsbMcuBuf.REC_COUNT - iIndex) <= iLen)
                              {
                                   g_m_UsbMcuBuf.RX_BUF_DEAL[iPos++] = g_m_UsbMcuBuf.RX_BUF[g_m_UsbMcuBuf.REC_COUNT - 1];
                                   if ((g_m_UsbMcuBuf.REC_COUNT - iIndex) == iLen)//表示数据获取完成
                                   {
                                       g_m_UsbMcuBuf.RX_BUF_DEAL_COUNT = 2 + iLen;
                                       g_m_UsbMcuBuf.REC_COUNT = 0;
                                       g_m_UsbMcuBuf.REC_FLAG = 1;
                                       iStartFlag = 0;
                                       printf("UsbMcu Rev Data Complete\r\n");
                                   }
                              }
                        }
                    }
                }
        }

        usleep(20000);
    }
}


//发送数据给UsbMcu
int SendDataToUsbMcu(int iCmd,char *pData,int iLen)
{
    if (g_p_Usb_Mcu_Dev_handle == NULL)
        return -1;

    pthread_mutex_lock(&i_g_UsbMcuLock);

    char cTempData[iLen + 8];
    cTempData[0] = 0xAA;
    cTempData[1] = 0x55;
    cTempData[2] = iCmd;
    cTempData[3] = iLen;
    if (iLen > 0)
        memcpy((char *)&(cTempData[4]),pData,iLen);
    for(int i=0;i<(iLen+4);i++)
    {
        printf("usb_mcu_prn send deal %x\r\n",cTempData[i]);

        int nActualBytes = 0;
        //        int nRet = libusb_bulk_transfer(g_p_Usb_Mcu_Dev_handle, 0x02, (unsigned char *)&(cTempData[i]), 1, &nActualBytes, 1000);
        int nRet = libusb_bulk_transfer(g_p_Usb_Mcu_Dev_handle, 0x02, (unsigned char *)&(cTempData[i]), 1, &nActualBytes, 1000);
        if (nRet < 0)
        {
            printf("libusb_bulk_transfer(0x02) write failed:[%s] \n", libusb_strerror(nRet));
            /*libusb_release_interface(g_p_Usb_Mcu_Dev_handle, 0);
            libusb_close(g_p_Usb_Mcu_Dev_handle);
            libusb_exit(NULL);*/
            pthread_mutex_unlock(&i_g_UsbMcuLock);
            return -1;
        }
        usleep(20000);
    }

    pthread_mutex_unlock(&i_g_UsbMcuLock);

    return 0;
}

//发送数据给UsbMcu_N
int SendDataToUsbMcu_N(int iCmd,char *pData,int iLen)
{
    int iRet = -1;

    if (g_p_Usb_Mcu_Dev_handle == NULL)
        return iRet;

    if (g_i_Send_Usb_Mcu_Flag == 0)
    {
        g_i_Usb_Mcu_Cmd = iCmd;
        if (iLen > 0)
            memcpy(g_i_Usb_Mcu_Data,pData,iLen);
        g_i_Usb_Mcu_Len = iLen;
        g_i_Send_Usb_Mcu_Flag = 1;
        g_i_Send_Usb_Mcu_Count = 0;
        iRet = 0;
    }
    return iRet;
}


//获取UsbMcu命令与数据
int GetCmdDataOfUsbMcu(uint8_t *pData)
{
    int i;
    int iLen;
    int iCmd = -1;

    iCmd = g_m_UsbMcuBuf.RX_BUF_DEAL[0];
    iLen = g_m_UsbMcuBuf.RX_BUF_DEAL[1];
    memcpy((char *)pData,(char *)(g_m_UsbMcuBuf.RX_BUF_DEAL),iLen+2);

    return iCmd;
}


//关闭UsbMcu
int CloseUsbMcu(int iFlag)
{
    // pthread_mutex_lock(&i_g_UsbMcuLock);
    int r;
    r = libusb_release_interface(g_p_Usb_Mcu_Dev_handle, 0); //release the claimed interface
    if(r!=0) {
        printf("Cannot Release Interface\r\n");
        if (iFlag == 0)
        {
            //   pthread_mutex_unlock(&i_g_UsbMcuLock);
            return -1;
        }
    }
    printf("Released Interface\r\n");

    libusb_attach_kernel_driver(g_p_Usb_Mcu_Dev_handle, 0);
    libusb_close(g_p_Usb_Mcu_Dev_handle);
    //  libusb_exit(g_p_Usb_Mcu_Ctx); //close the session
    g_p_Usb_Mcu_Dev_handle = NULL;
    // pthread_mutex_unlock(&i_g_UsbMcuLock);
    return 0;
}





//检测并处理usb摄像头拔插状态
void CheckAndDealUsbCameraOutIn(quint32 iStartCountTime)
{
    if ((GetTickCountForSec() - iStartCountTime) >= 3)
    {
        // printf("usb camera status = %d\n",g_i_Stream_Usb_Flag);
        g_i_Check_Stream_Usb_Flag = 1;
    }
}


//初始话电压检测
int InitCheckVoltage()
{

    if (g_i_Check_Vol_Flag == 1)
        return 0;

    g_i_Vol_Fd = open("/dev/sar", O_RDWR);
    if (g_i_Vol_Fd < 0)
    {
        printf("open voltage error");
        return -1;
    }

    if (0 > ioctl(g_i_Vol_Fd, MS_SAR_INIT))
    {
        printf("ioctl MS_SAR_INIT error");
        close(g_i_Vol_Fd);
        return -2;
    }

    g_i_Check_Vol_Flag = 1;

    return 0;
}


//电压检测
int CheckVoltage()
{

    SAdc_Config_Read_Adc_T stCfg;

    if  (InitCheckVoltage() >= 0)
    {
        memset(&stCfg, 0, sizeof(SAdc_Config_Read_Adc_T));

        stCfg.channel_value = 3;
        if (0 > ioctl(g_i_Vol_Fd,MS_SAR_SET_CHANNEL_READ_VALUE, &stCfg))
        {
            printf("ioctl MDRV_SARADC_SET_CHANNEL_MODE_READ_ADC error");
            close(g_i_Vol_Fd);
            g_i_Check_Vol_Flag = -1;
            return -1;
        }

        g_f_Vol = ((float)(stCfg.adc_value)/(float)0x3FF) * 3.3;

    }

    return 0;
}

//关机处理线程
void *CloseDeal(void *arg)
{
    FILE *File;
    char readBuf[1024]={0};
    int i =0;
    //printf("%c\n",readBuf[35]);
    while(1)
    {
        File = popen("/customer/riu_r 0x34 12","r");
        fread(readBuf,1024,1,File);
        pclose(File);
        if(readBuf[35]=='4')
        {
            i++;
            if(i==8)
            {
                break;
            }
        }
        else
        {
            i=0;
        }
        usleep(1000*200);
    }
    //printf("%s\n",readBuf);
    system("echo 12>/sys/class/gpio/export");
    system("echo 13>/sys/class/gpio/export");
    usleep(1000*100);
    system("echo out >/sys/class/gpio/gpio12/direction");
    system("echo 0>/sys/class/gpio/gpio12/value");
    system("echo out >/sys/class/gpio/gpio13/direction");
    system("echo 0>/sys/class/gpio/gpio13/value");
    system("poweroff");
    //  pthread_exit(&close mem);
}

//监控处理线程
void *MonitorDeal(void *arg)
{
    quint32 iStartCountTime = GetTickCountForSec();//刚启动的系统时间
    while (1)
    {
        //检测usb摄像头拔插状态
        CheckAndDealUsbCameraOutIn(iStartCountTime);
        //初始话电压检测
        CheckVoltage();
        usleep(100);
    }
    return 0;
}

//获取系统启动到当前的时间(秒)
unsigned long GetTickCountForSec()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC,&ts);
    return ts.tv_sec;
}


//获取系统启动到当前的时间(毫秒)
unsigned long GetTickCountForMSec()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC,&ts);
    return (ts.tv_sec * 1000 +ts.tv_nsec/1000000);
}

//某目录是否存在
int folderExist(char *pathName)
{
    if (opendir(pathName) == NULL)
    {
        printf("folder not exist\n");
        return -1;
    }
    return 0;
}

//获取磁盘信息
void GetDiskInfo(SDiskInfo_T *pDiskInfo)
{
    struct statfs diskInfo;
    statfs("/mnt", &diskInfo);
    unsigned long long totalBlocks = diskInfo.f_bsize;
    unsigned long long totalSize = totalBlocks * diskInfo.f_blocks;
    size_t mbTotalsize = totalSize>>20;
    unsigned long long freeDisk = diskInfo.f_bfree*totalBlocks;
    size_t mbFreedisk = freeDisk>>20;
    printf ("/mnt  total=%dMB, free=%dMB\n", mbTotalsize, mbFreedisk);
    pDiskInfo->iTotalsize = mbTotalsize;
    pDiskInfo->iFreedisk = mbFreedisk;


}

//摄像头按键处理线程
void *CameraKeyDeal(void *arg)
{
    struct input_event camera_key={0};
    int ret;
    int event1_fd ;
    while(1){
        event1_fd = open("/dev/event1",O_RDWR);
        if(event1_fd < 0){
                printf ("open /dev/event1 err: %d \r\n",event1_fd);
        }
        else {
            printf("open /dev/event1 success \r\n");
            while(1){
                memset(&camera_key, 0, sizeof(struct input_event));
                ret = read( event1_fd ,&camera_key,sizeof(camera_key));
                if( ret == sizeof(camera_key)){
                    printf("type %d, code %d, value %d \r\n",camera_key.type ,camera_key.code, camera_key.value );
                    if (camera_key.code == 212)//拍照
                        g_i_TakePhoto = 1;
                  //  if(camera_key.type == EV_KEY && camera_key.code ==  KEY_CAMERA && camera_key.value  == 1 ){
                       /*   按键拍照处理*/
                    //}
                }else {
                     printf("read err : ret %d \r\n", ret);
                     close(event1_fd);
                     break;
                }
            }
        }
        usleep(1000*500);
    }
    return NULL;
}


