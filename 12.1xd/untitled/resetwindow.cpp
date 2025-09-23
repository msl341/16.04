#include "resetwindow.h"
#include "ui_resetwindow.h"
#include "widget.h"
resetwindow::resetwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::resetwindow)
{
    ui->setupUi(this);
    //窗体设置
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);
    ui->m_pLb_Msg->setWordWrap(true);

    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
    {
        ui->m_pLb_Msg->setText("确定要复位吗?");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
    {
        ui->m_pLb_Msg->setText("確定要復位嗎?");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
    {
        ui->m_pLb_Msg->setText("Are you sure you want to reset it?");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
    {
        ui->m_pLb_Msg->setText("Êtes - vous sûr de vouloir Réinitialiser?");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
    {
        ui->m_pLb_Msg->setText("Sind Sie sicher, dass Sie es zurücksetzen möchten?");
    }
    ui->m_pBtn_Confirm->show();
    ui->m_pBtn_Cancel->show();
    connect(ui->m_pBtn_Confirm,&QPushButton::clicked,this,&resetwindow::On_Btn_Confirm_Clicked);
    connect(ui->m_pBtn_Cancel,&QPushButton::clicked,this,&resetwindow::On_Btn_Cancel_Clicked);

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



resetwindow::~resetwindow()
{
    delete ui;
}
//确认
void resetwindow::On_Btn_Confirm_Clicked()
{
    char cTemp[200];

        sprintf(cTemp,"rm %s%s;sync",PATH_PROC,"config.json");
        system(cTemp);





    char cLngTextStr[150];


    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)
       strcpy(cLngTextStr,"复位完毕! 准备重启!");
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)
        strcpy(cLngTextStr,"復位完畢! 準備重啓!");
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)
        strcpy(cLngTextStr,"Reset completed! Preparing to restart!");
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)
        strcpy(cLngTextStr,"Réinitialisation terminée! Prêt à redémarrer!");
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)
        strcpy(cLngTextStr,"Zurücksetzen abgeschlossen! Vorbereitung des Neustarts!");

    QMessageBox messageBox(QMessageBox::NoIcon,"",cLngTextStr, QMessageBox::Yes, NULL);

    int iResult = messageBox.exec();


    system("reboot");


 /*   QMessageBox messageBox(QMessageBox::NoIcon,"Reset Default","Reset Default Success,Now will restart and take effect!", QMessageBox::Yes, NULL);
    int iResult = messageBox.exec();
*/
}

//取消
void resetwindow::On_Btn_Cancel_Clicked()
{
   emit sigReturnTowidget();
}
