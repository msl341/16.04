#include "datetimewindow.h"
#include "ui_datetimewindow.h"
#include "widget.h"
datetimewindow::datetimewindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::datetimewindow)
{
    ui->setupUi(this);
    //窗体设置
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    char cTemp[200];
    //初始化

    QDateTime currentDate = QDateTime::currentDateTime();
    currentDate.date().getDate(&m_i_Year,&m_i_Month,&m_i_Day);
    m_i_Hour = currentDate.time().hour();
    m_i_Min = currentDate.time().minute();

    connect(ui->m_pBtn_Year_Up,&QPushButton::clicked,this,&datetimewindow::On_Btn_Year_Up_Clicked);
    connect(ui->m_pBtn_Year_Down,&QPushButton::clicked,this,&datetimewindow::On_Btn_Year_Down_Clicked);

    connect(ui->m_pBtn_Month_Up,&QPushButton::clicked,this,&datetimewindow::On_Btn_Month_Up_Clicked);
    connect(ui->m_pBtn_Month_Down,&QPushButton::clicked,this,&datetimewindow::On_Btn_Month_Down_Clicked);

    connect(ui->m_pBtn_Day_Up,&QPushButton::clicked,this,&datetimewindow::On_Btn_Day_Up_Clicked);
    connect(ui->m_pBtn_Day_Down,&QPushButton::clicked,this,&datetimewindow::On_Btn_Day_Down_Clicked);

    connect(ui->m_pBtn_Hour_Up,&QPushButton::clicked,this,&datetimewindow::On_Btn_Hour_Up_Clicked);
    connect(ui->m_pBtn_Hour_Down,&QPushButton::clicked,this,&datetimewindow::On_Btn_Hour_Down_Clicked);

    connect(ui->m_pBtn_Min_Up,&QPushButton::clicked,this,&datetimewindow::On_Btn_Min_Up_Clicked);
    connect(ui->m_pBtn_Min_Down,&QPushButton::clicked,this,&datetimewindow::On_Btn_Min_Down_Clicked);


    connect(ui->m_pBtn_Save,&QPushButton::clicked,this,&datetimewindow::On_Btn_Save_Clicked);
    connect(ui->m_pBtn_Return,&QPushButton::clicked,this,&datetimewindow::On_Btn_Return_Clicked);

    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
        ui->m_pBtn_Save->setStyleSheet("border-image: url(:/tu/Res/save.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
        ui->m_pBtn_Save->setStyleSheet("border-image: url(:/tu/Res/save.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
        ui->m_pBtn_Save->setStyleSheet("border-image: url(:/tu/Res/save-1.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
        ui->m_pBtn_Save->setStyleSheet("border-image: url(:/tu/Res/save-2.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
        ui->m_pBtn_Save->setStyleSheet("border-image: url(:/tu/Res/save-3.png);");
    sprintf(cTemp,"%02d",m_i_Year);
    ui->m_pLb_Year->setText(cTemp);
    ui->m_pLb_Year->show();
    sprintf(cTemp,"%02d",m_i_Month);
    ui->m_pBtn_Month->setText(cTemp);
    ui->m_pBtn_Month->show();
    sprintf(cTemp,"%02d",m_i_Day);
    ui->m_pBtn_Day->setText(cTemp);
    ui->m_pBtn_Day->show();
    sprintf(cTemp,"%02d",m_i_Hour);
    ui->m_pBtn_Hour->setText(cTemp);
    ui->m_pBtn_Hour->show();
    sprintf(cTemp,"%02d",m_i_Min);
    ui->m_pBtn_Min->setText(cTemp);
    ui->m_pBtn_Min->show();
}



datetimewindow::~datetimewindow()
{
    delete ui;
}

//年按上
void datetimewindow::On_Btn_Year_Up_Clicked()
{
    m_i_Year += 1;
    char cTemp[10];
    sprintf(cTemp,"%d",m_i_Year);
    ui->m_pLb_Year->setText(cTemp);
    ui->m_pLb_Year->show();
}
//年按下
void datetimewindow::On_Btn_Year_Down_Clicked()
{
    if (m_i_Year == 1970)
        return;
    m_i_Year -= 1;
    char cTemp[10];
    sprintf(cTemp,"%d",m_i_Year);
    ui->m_pLb_Year->setText(cTemp);
    ui->m_pLb_Year->show();
}

//月按上
void datetimewindow::On_Btn_Month_Up_Clicked()
{
    if (m_i_Month == 12)
        return;
    m_i_Month += 1;
    char cTemp[10];
    sprintf(cTemp,"%02d",m_i_Month);
    ui->m_pBtn_Month->setText(cTemp);
    ui->m_pBtn_Month->show();
}


//月按下
void datetimewindow::On_Btn_Month_Down_Clicked()
{
    if (m_i_Month == 1)
        return;
    m_i_Month -= 1;
    char cTemp[10];
    sprintf(cTemp,"%02d",m_i_Month);
    ui->m_pBtn_Month->setText(cTemp);
    ui->m_pBtn_Month->show();
}

//日按上
void datetimewindow::On_Btn_Day_Up_Clicked()
{
    if (m_i_Day == 31)
        return;
    m_i_Day += 1;
    char cTemp[10];
    sprintf(cTemp,"%02d",m_i_Day);
    ui->m_pBtn_Day->setText(cTemp);
    ui->m_pBtn_Day->show();
}


//日按下
void datetimewindow::On_Btn_Day_Down_Clicked()
{
    if (m_i_Day == 1)
        return;
    m_i_Day -= 1;
    char cTemp[10];
    sprintf(cTemp,"%02d",m_i_Day);
    ui->m_pBtn_Day->setText(cTemp);
    ui->m_pBtn_Day->show();
}


//时按上
void datetimewindow::On_Btn_Hour_Up_Clicked()
{
    if (m_i_Hour == 23)
        return;
    m_i_Hour += 1;
    char cTemp[10];
    sprintf(cTemp,"%02d",m_i_Hour);
    ui->m_pBtn_Hour->setText(cTemp);
    ui->m_pBtn_Hour->show();
}


//时按下
void datetimewindow::On_Btn_Hour_Down_Clicked()
{
    if (m_i_Hour == 0)
        return;
    m_i_Hour -= 1;
    char cTemp[10];
    sprintf(cTemp,"%02d",m_i_Hour);
    ui->m_pBtn_Hour->setText(cTemp);
    ui->m_pBtn_Hour->show();
}


//分按上
void datetimewindow::On_Btn_Min_Up_Clicked()
{
    if (m_i_Min == 59)
        return;
    m_i_Min += 1;
    char cTemp[10];
    sprintf(cTemp,"%02d",m_i_Min);
    ui->m_pBtn_Min->setText(cTemp);
    ui->m_pBtn_Min->show();
}


//分按下
void datetimewindow::On_Btn_Min_Down_Clicked()
{
    if (m_i_Min == 0)
        return;
    m_i_Min -= 1;
    char cTemp[10];
    sprintf(cTemp,"%02d",m_i_Min);
    ui->m_pBtn_Min->setText(cTemp);
    ui->m_pBtn_Min->show();
}


//保存
void datetimewindow::On_Btn_Save_Clicked()
{
    char cTemp[200];
    sprintf(cTemp,"date %02d%02d%02d%02d%04d.%02d",m_i_Month,m_i_Day,m_i_Hour,m_i_Min,m_i_Year,0);
    system(cTemp);
    usleep(10000);
    system("hwclock -w");
}

//返回
void datetimewindow::On_Btn_Return_Clicked()
{

emit sigReturnTowidget();


}









