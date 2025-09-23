#include "formatwindow.h"
#include "ui_formatwindow.h"
#include "widget.h"
formatwindow::formatwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::formatwindow)
{
    ui->setupUi(this);
    //窗体设置
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->m_pLb_Msg->setWordWrap(true);

    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
    {
        ui->m_pLb_Msg->setText("确定要格式化吗?");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
    {
        ui->m_pLb_Msg->setText("確定要格式化嗎?");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
    {
        ui->m_pLb_Msg->setText("Are you sure you want to format it?");

    }
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
    {
        ui->m_pLb_Msg->setText("Êtes - vous sûr de vouloir formater?");

    }
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
    {
        ui->m_pLb_Msg->setText("Sind Sie sicher, dass Sie es formatieren möchten?");

    }
    ui->m_pBtn_Confirm->show();
    ui->m_pBtn_Cancel->show();
    connect(ui->m_pBtn_Confirm,&QPushButton::clicked,this,&formatwindow::On_Btn_Confirm_Clicked);
    connect(ui->m_pBtn_Cancel,&QPushButton::clicked,this,&formatwindow::On_Btn_Cancel_Clicked);
    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
        ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/btn_confirm.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
        ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/btn_confirm_ft.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
        ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/btn_confirm_en.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
        ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/btn_confirm_fr.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
        ui->m_pBtn_Confirm->setStyleSheet("border-image: url(:/tu/Res/btn_confirm_gm.png);");

    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
        ui->m_pBtn_Cancel->setStyleSheet("border-image: url(:/tu/Res/btn_cancel.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
        ui->m_pBtn_Cancel->setStyleSheet("border-image: url(:/tu/Res/btn_cancel_ft.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
        ui->m_pBtn_Cancel->setStyleSheet("border-image: url(:/tu/Res/btn_cancel_en.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
        ui->m_pBtn_Cancel->setStyleSheet("border-image: url(:/tu/Res/btn_cancel_fr.png);");
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
        ui->m_pBtn_Cancel->setStyleSheet("border-image: url(:/tu/Res/btn_cancel_gm.png);");




}



formatwindow::~formatwindow()
{
    delete ui;
}

//确认
void formatwindow::On_Btn_Confirm_Clicked()
{

    system("mkfs.vfat  /dev/mmcblk0p1");
    system("sync");



    char cLngTextStr[150];

    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
       strcpy(cLngTextStr,"格式化完毕! 准备重启!");
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
        strcpy(cLngTextStr,"格式化完畢! 準備重啓!");
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
        strcpy(cLngTextStr,"Format completed! Get ready to restart!");
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
        strcpy(cLngTextStr,"Formatage terminé! Prêt à redémarrer!");
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
        strcpy(cLngTextStr,"Format abgeschlossen! Bereiten Sie sich zum Neustart vor!");

    QMessageBox messageBox(QMessageBox::NoIcon,"",cLngTextStr, QMessageBox::Yes, NULL);

    int iResult = messageBox.exec();

    system("reboot");

}
//取消
void formatwindow::On_Btn_Cancel_Clicked()
{

    emit sigReturnTowidget();


}
