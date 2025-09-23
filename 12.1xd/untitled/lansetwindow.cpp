#include "lansetwindow.h"
#include "ui_lansetwindow.h"
#include "widget.h"
lansetwindow::lansetwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::lansetwindow)
{
    ui->setupUi(this);
    //窗体设置
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->m_pBtn_SimpleCh->move(50,10);
    ui->m_pBtn_SimpleCh->setFixedSize(QSize(300,81));
    ui->m_pBtn_SimpleCh->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
    ui->m_pBtn_SimpleCh->setIconSize(QSize(300,81));

    ui->m_pBtn_TraditionCh->move(50,110);
    ui->m_pBtn_TraditionCh->setFixedSize(QSize(300,81));
    ui->m_pBtn_TraditionCh->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
    ui->m_pBtn_TraditionCh->setIconSize(QSize(300,81));

    ui->m_pBtn_English->move(50,210);
    ui->m_pBtn_English->setFixedSize(QSize(300,81));
    ui->m_pBtn_English->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
    ui->m_pBtn_English->setIconSize(QSize(300,81));

    ui->m_pBtn_French->move(50,310);
    ui->m_pBtn_French->setFixedSize(QSize(300,81));
    ui->m_pBtn_French->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
    ui->m_pBtn_French->setIconSize(QSize(300,81));

    ui->m_pBtn_German->move(50,410);
    ui->m_pBtn_German->setFixedSize(QSize(300,81));
    ui->m_pBtn_German->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
    ui->m_pBtn_German->setIconSize(QSize(300,81));


    connect(ui->m_pBtn_SimpleCh,&QPushButton::clicked,this,&lansetwindow::On_Btn_SimpleCh_Clicked);
    connect(ui->m_pBtn_TraditionCh,&QPushButton::clicked,this,&lansetwindow::On_Btn_TraditionCh_Clicked);
    connect(ui->m_pBtn_English,&QPushButton::clicked,this,&lansetwindow::On_Btn_English_Clicked);
    connect(ui->m_pBtn_French,&QPushButton::clicked,this,&lansetwindow::On_Btn_French_Clicked);
    connect(ui->m_pBtn_German,&QPushButton::clicked,this,&lansetwindow::On_Btn_German_Clicked);

    connect(ui->m_pBtn_Return,&QPushButton::clicked,this,&lansetwindow::On_Btn_Cancel_Clicked);

    if (g_S_CfgData.iLanSetLan == 0) g_S_CfgData.iLanSetLan = LAN_SIMPLE_CH;

    SelBtn(1);

    SetText();

}




lansetwindow::~lansetwindow()
{
    delete ui;
}

//选择按钮
void lansetwindow::SelBtn(int iFlag)
{

    switch (g_S_CfgData.iLanSetLan)
    {
        case LAN_SIMPLE_CH://简体中文
        {
//        QSize btnSize = ui->m_pBtn_SimpleCh->size(); // 自动适配按钮大小

            if (iFlag == 0)
                ui->m_pBtn_SimpleCh->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
            else
                ui->m_pBtn_SimpleCh->setIcon(QIcon(":/tu/Res/btn_sel.png"));
//            ui->m_pBtn_SimpleCh->setIconSize(btnSize);

            ui->m_pBtn_SimpleCh->show();
            break;
        }
        case LAN_TRADITION_CH://繁体中文
        {

            if (iFlag == 0)
                ui->m_pBtn_TraditionCh->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
            else
                ui->m_pBtn_TraditionCh->setIcon(QIcon(":/tu/Res/btn_sel.png"));
            ui->m_pBtn_TraditionCh->show();
            break;
        }
        case LAN_ENGLISH://英语
        {

            if (iFlag == 0)
                ui->m_pBtn_English->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
            else
                ui->m_pBtn_English->setIcon(QIcon(":/tu/Res/btn_sel.png"));
            ui->m_pBtn_English->show();
            break;
        }
        case LAN_FRENCH://法国
        {

            if (iFlag == 0)
                ui->m_pBtn_French->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
            else
                ui->m_pBtn_French->setIcon(QIcon(":/tu/Res/btn_sel.png"));
            ui->m_pBtn_French->show();

            break;
        }
        case LAN_GERMAN://德国
        {

            if (iFlag == 0)
                ui->m_pBtn_German->setIcon(QIcon(":/tu/Res/btn_nosel.png"));
            else
                ui->m_pBtn_German->setIcon(QIcon(":/tu/Res/btn_sel.png"));
            ui->m_pBtn_German->show();
            break;
        }
    }
}



//设置文字
void lansetwindow::SetText()
{
    // return;
    San_S_DevRect mDevRect;
    char cTemp[100];
    if (g_S_CfgData.iLanSetLan == LAN_SIMPLE_CH)//简体中文
    {
        //语言设置
        ui->m_pBtn_SimpleCh->setText("简体中文");
        ui->m_pBtn_TraditionCh->setText("繁體中文");
        ui->m_pBtn_English->setText("English");
        ui->m_pBtn_French->setText("French");
        ui->m_pBtn_German->setText("German");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_TRADITION_CH)//繁体中文
    {
        //语言设置
        ui->m_pBtn_SimpleCh->setText("简体中文");
        ui->m_pBtn_TraditionCh->setText("繁體中文");
        ui->m_pBtn_English->setText("English");
        ui->m_pBtn_French->setText("French");
        ui->m_pBtn_German->setText("German");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_ENGLISH)//英语
    {
        //语言设置
        ui->m_pBtn_SimpleCh->setText("简体中文");
        ui->m_pBtn_TraditionCh->setText("繁體中文");
        ui->m_pBtn_English->setText("English");
        ui->m_pBtn_French->setText("French");
        ui->m_pBtn_German->setText("German");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_FRENCH)//法国
    {
        //语言设置
        ui->m_pBtn_SimpleCh->setText("简体中文");
        ui->m_pBtn_TraditionCh->setText("繁體中文");
        ui->m_pBtn_English->setText("English");
        ui->m_pBtn_French->setText("French");
        ui->m_pBtn_German->setText("German");
    }
    else if (g_S_CfgData.iLanSetLan == LAN_GERMAN)//德国
    {
        //语言设置
        ui->m_pBtn_SimpleCh->setText("简体中文");
        ui->m_pBtn_TraditionCh->setText("繁體中文");
        ui->m_pBtn_English->setText("English");
        ui->m_pBtn_French->setText("French");
        ui->m_pBtn_German->setText("German");
    }
}


//简体中文
void lansetwindow::On_Btn_SimpleCh_Clicked()
{
    SelBtn(0);

    g_S_CfgData.iLanSetLan = LAN_SIMPLE_CH;
    San_WriteConfig(&g_S_CfgData);

    SelBtn(1);

    SetText();

    if (zhukuang::myzhukuang) {
        zhukuang::myzhukuang->SetLanguageText();
    }
}


//繁体中文
void lansetwindow::On_Btn_TraditionCh_Clicked()
{
    SelBtn(0);

    g_S_CfgData.iLanSetLan = LAN_TRADITION_CH;
    San_WriteConfig(&g_S_CfgData);

    SelBtn(1);

    SetText();
    if (zhukuang::myzhukuang) {
        zhukuang::myzhukuang->SetLanguageText();
    }
}


//英语
void lansetwindow::On_Btn_English_Clicked()
{
    SelBtn(0);

    g_S_CfgData.iLanSetLan = LAN_ENGLISH;
    San_WriteConfig(&g_S_CfgData);

    SelBtn(1);

    SetText();
    if (zhukuang::myzhukuang) {
        zhukuang::myzhukuang->SetLanguageText();
    }
}

//法语
void lansetwindow::On_Btn_French_Clicked()
{
    SelBtn(0);

    g_S_CfgData.iLanSetLan = LAN_FRENCH;
    San_WriteConfig(&g_S_CfgData);

    SelBtn(1);

    SetText();
    if (zhukuang::myzhukuang) {
        zhukuang::myzhukuang->SetLanguageText();
    }
}

//德语
void lansetwindow::On_Btn_German_Clicked()
{
    SelBtn(0);

    g_S_CfgData.iLanSetLan = LAN_GERMAN;
    San_WriteConfig(&g_S_CfgData);

    SelBtn(1);

    SetText();
    if (zhukuang::myzhukuang) {
        zhukuang::myzhukuang->SetLanguageText();
    }
}

//取消
void lansetwindow::On_Btn_Cancel_Clicked()
{
    this->hide();
    this->close();
    //emit sigReturnTowidget();
}
