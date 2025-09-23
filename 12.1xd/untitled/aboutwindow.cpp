#include "aboutwindow.h"
#include "ui_aboutwindow.h"
#include "widget.h"
aboutwindow::aboutwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::aboutwindow)
{
    ui->setupUi(this);
    m_i_SliderValue = 0;
    //窗体设置
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->m_pBtn_Confirm,&QPushButton::clicked,this,&aboutwindow::On_Btn_Confirm_Clicked);
    connect(ui->m_pBtn_Cancel,&QPushButton::clicked,this,&aboutwindow::On_Btn_Cancel_Clicked);

    ui->m_pLb_Verm->setAlignment(Qt::AlignCenter);
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label_2->setAlignment(Qt::AlignCenter);


    ui->m_pLb_Msg->setAlignment(Qt::AlignCenter);

    ui->m_pLb_Msg->setWordWrap(true);
    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
    {
        ui->m_pLb_Verm->setText("当前版本");
        ui->m_pLb_Msg->setText("固件升级中，不要关闭电源!");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
    {
        ui->m_pLb_Msg->setText("固件升級中，請勿關閉電源！");
        ui->m_pLb_Verm->setText("當前版本");

    }
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
    {
        ui->m_pLb_Msg->setText("Firmware update in progress. Do not turn off the power!");
        ui->m_pLb_Verm->setText("Current Version");

    }
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
    {
        ui->m_pLb_Msg->setText("Mise à jour du firmware en cours. Ne pas éteindre l’alimentation !");
        ui->m_pLb_Verm->setText("Version Actuelle");

    }
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
    {
        ui->m_pLb_Msg->setText("Firmware wird aktualisiert. Schalten Sie die Stromversorgung nicht aus!");
        ui->m_pLb_Verm->setText("Derzeitige Version");

    }
    // m_iEvent = startTimer(1000);

        if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
            ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/sj.png);");
        else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
            ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/sj-2.png);");
        else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
            ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/sj-3.png);");
        else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
            ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/sj-4.png);");
        else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
            ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/sj-5.png);");










}



aboutwindow::~aboutwindow()
{
    delete ui;
}

//确认
void aboutwindow::On_Btn_Confirm_Clicked()
{

    // 切换到 page_2
    ui->stackedWidget->setCurrentWidget(ui->page_2);
    // 启动定时器
    m_iEvent = startTimer(1000);


}


//取消
void aboutwindow::On_Btn_Cancel_Clicked()
{

    emit sigReturnTowidget();


}

//定时事件
void aboutwindow::timerEvent(QTimerEvent* ev)
{
    m_i_SliderValue++;
    if (m_i_SliderValue >= 10)
    {
        killTimer(m_iEvent);
        system("/etc/fw_setenv sdautoupgrade 1");
        usleep(20000);
        system("reboot");
    }
}
