#ifndef USBMCU_H
#define USBMCU_H
#include "libusb.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <QtGlobal>
#include <QPoint>
#include <QMainWindow>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/statfs.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/ioctl.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "mykey.h"

//配置信息
typedef struct San_S_CfgData_
{
    quint8 iAe;
    quint8 iRot;
    quint8 iDrawShape;
    int iLanSetLan;
}San_S_CfgData;
//设置保存的文件
#define SAN_PATH_CFG  "./config.json"
//屏幕坐标
#define SAN_SCREEN_WIDTH 1280
#define SAN_SCREEN_HIGHT 800
//设备坐标
#define SAN_DEV_WIDTH 1280
#define SAN_DEV_HIGHT 800
#define MAX_DATA    500
//录像播放进度
#define SAN_POS_VIDEO_PLAYER_PROG_X  288
#define SAN_POS_VIDEO_PLAYER_PROG_Y  18
#define SAN_POS_VIDEO_PLAYER_PROG_W  775
#define SAN_POS_VIDEO_PLAYER_PROG_H  80

#define PATH_PROC         "/customer/"
//画图形状
#define DS_FX     0
#define DS_YX     1
#define DS_BJX    2
//语言
#define LAN_SIMPLE_CH      0
#define LAN_TRADITION_CH   1
#define LAN_ENGLISH        2
#define LAN_FRENCH         3
#define LAN_GERMAN         4
//BtnSel
#define SAN_PATH_BTN_SEL "./Res/btn_sel.png"


//刚开机检测按键前的等待计数
extern qint8 g_i_FirstCheck_Gpio_Count;


//BtnNoSel
#define SAN_PATH_BTN_NOSEL "./Res/btn_nosel.png"
//设备位置
typedef struct San_S_DevRect_
{
   int x;
   int y;
   int w;
   int h;
}San_S_DevRect;


//转为设备位置
extern San_S_DevRect San_F_DevRect(int x,int y,int w,int h);
//通讯头
typedef struct Comm_Header_T_
{
    int iType;
    int iTotal;
    int iIndex;
    int iFlag;
    int iSize;
}Comm_Header_T;

//消息结构体
typedef struct SMsgBuf_T_
{
    long lType;
    char cText[sizeof(Comm_Header_T) + MAX_DATA];
}SMsgBuf_T;

//菜单消息
typedef struct SMenu_Msg_T_
{
    char cCmd[50];
    int iFlag;
    int iVar;
    char cText[260];
}SMenu_Msg_T;

//消息全局变量
typedef struct SMsgGlobalVal_T_
{
    int qRecvTKId;
    int iRecvTKMsgkey;
    int qSendTKId;
    int iSendTKMsgkey;
}SMsgGlobalVal_T;


//电压检测
typedef struct SAdc_Config_Read_Adc_T_
{
    int channel_value;
    int adc_value;
} SAdc_Config_Read_Adc_T;

//磁盘信息
typedef struct SDiskInfo_T_
{
   size_t iTotalsize;
   size_t iFreedisk;
}SDiskInfo_T;

//UsbMcu缓存
#define USB_MCU_MAX_TX_LEN    50  	//定义最大发送字节数
#define USB_MCU_MAX_RX_LEN    50  	//定义最大接收字节数
typedef struct SUSB_MCU_BUF_T_
{
  uint8_t REC_FLAG;
  uint16_t REC_COUNT;
//  uint8_t TX_BUF[USB_MCU_MAX_TX_LEN];	//发送缓冲
  uint8_t RX_BUF[USB_MCU_MAX_RX_LEN];	//接收缓冲
  uint16_t RX_BUF_DEAL_COUNT;
  uint8_t RX_BUF_DEAL[USB_MCU_MAX_RX_LEN];	//接收处理缓冲
}SUSB_MCU_BUF_T;


//消息全局变量
extern SMsgGlobalVal_T  mMsgGlobalVal;
//拍照
extern qint8 g_i_TakePhoto;
//文件路径
extern char g_c_FilePath[500];
//文件序号
extern int g_i_FileIndex;
//录像状态标志
extern qint8 g_i_Rec_Video_Flag;
//文件序号
extern int g_i_FileIndex;
//录像文件总时间长度(秒)
extern int g_i_Video_Player_Time;
//usb摄像头拔插状态
extern qint8 g_i_Stream_Usb_Flag;
//摄像头旋转标志
extern qint8 g_i_Rotate_Flag;
//usb摄像头拔插状态可否检测标志
extern qint8 g_i_Check_Stream_Usb_Flag;

//usb摄像头断开窗口是否打开标志
extern qint8 g_i_Win_UsbCamera_Out_OpenFlag;

//电压检测驱动文件句柄
extern int g_i_Vol_Fd;

//电压显示标志
extern qint8 g_i_Show_Vol_Flag;

//电压可否检测标志
extern qint8 g_i_Check_Vol_Flag;

//电压值
extern float g_f_Vol;

//接收消息线程ID
extern pthread_t g_t_Revmsg_Tid;

//接收UsbMcu线程ID
extern pthread_t g_t_RevUsbMcu_Tid;

//关机线程ID
extern pthread_t g_t_Close_Tid;

//监控线程ID
extern pthread_t g_t_Monitor_Tid;



extern pthread_mutex_t i_g_UsbMcuLock;
//UsbMcu设备变量
extern libusb_device **g_pp_Usb_Mcu_Devs;	//pointer to pointer of device, used to retrieve a list of devices
extern libusb_context *g_p_Usb_Mcu_Ctx; //a libusb session
extern libusb_device_handle *g_p_Usb_Mcu_Dev_handle;
//UsbMcu缓存
extern SUSB_MCU_BUF_T g_m_UsbMcuBuf;
//发送和接收UsbMcu命令和数据各变量
extern qint8 g_i_Send_Usb_Mcu_Flag;
extern int g_i_Usb_Mcu_Cmd;
extern unsigned char g_i_Usb_Mcu_Data[30];
extern int g_i_Usb_Mcu_Len;
extern unsigned long g_i_Send_Usb_Mcu_StartTime;
extern qint8 g_i_Send_Usb_Mcu_Count;
extern int g_i_Get_Usb_Mcu_Cmd;




//初始化消息
extern int IniMsg(int *pid,int msgkey);
//接收消息
extern int RevMsg(int *pid,int msgkey,SMsgBuf_T *pmsg);
//发送消息
extern int SendMsg(int *pid,int msgkey,SMsgBuf_T *pmsg,int iLen);
//接收消息从Uvc
extern void *RevMseFromUvc(void *arg);
//发送消息给Uvc
extern void SendMsgToUvc(char *pCmd,int iFlag,int iVar,char *pText);

//打开UsbMcu
extern int OpenUsbMcu();
//摄像头按键处理线程
extern void *CameraKeyDeal(void *arg);
//接收数据从UsbMcu
extern void *RevDataFromUsbMcu(void *arg);
//发送数据给UsbMcu
extern int SendDataToUsbMcu(int iCmd,char *pData,int iLen);
//发送数据给UsbMcu_N
extern int SendDataToUsbMcu_N(int iCmd,char *pData,int iLen);
//获取UsbMcu命令与数据
extern int GetCmdDataOfUsbMcu(uint8_t *pData);
//关闭UsbMcu
extern int CloseUsbMcu(int iFlag);

//配置信息
extern San_S_CfgData g_S_CfgData;
//写Config
extern void San_WriteConfig(San_S_CfgData *pSCfgData);

//读Config
extern void San_ReadConfig(San_S_CfgData *pSCfgData);
//关机处理线程
void *CloseDeal(void *arg);
//监控处理线程
extern void *MonitorDeal(void *arg);
//获取系统启动到当前的时间(秒)
extern unsigned long GetTickCountForSec();
//获取系统启动到当前的时间(毫秒)
extern unsigned long GetTickCountForMSec();
//某目录是否存在
int folderExist(char *pathName);
//获取磁盘信息
void GetDiskInfo(SDiskInfo_T *pDiskInfo);
#endif // USBMCU_H
