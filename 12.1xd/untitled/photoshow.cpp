#include "photoshow.h"
#include "ui_photoshow.h"
#include "widget.h"
photoshow::photoshow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::photoshow)
{
    ui->setupUi(this);

    //窗体设置
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->label_left,SIGNAL(clicked()),this,SLOT(On_Btn_Pre_Photo_Clicked()));
    connect(ui->label_right,SIGNAL(clicked()),this,SLOT(On_Btn_Next_Photo_Clicked()));

    connect(ui->label_delete,SIGNAL(clicked()),this,SLOT(On_Btn_Del_File_Clicked()));
    connect(ui->label_return,SIGNAL(clicked()),this,SLOT(On_Btn_Return_Clicked()));


    m_iCurrIndex = 0;
    RefreshFileAndShow();



}



photoshow::~photoshow()
{
    delete ui;
}
void photoshow::refreshPhotos() {
    qDebug() << "触发图片刷新，当前目录：" << m_PhotoDir.path();
    RefreshFileAndShow();
}
//刷新文件信息
void photoshow::RefreshFileMsg()
{
    char cTemp[100];
    //int iCount = m_PhotoDir.count();
    int iCount = m_photoFiles.count();
    //刷新文件索引以及总数
    if (iCount > 0)
    {
        sprintf(cTemp,"%d/%d",m_iCurrIndex+1,iCount);
    }
    else
    {
        //sprintf(cTemp,"%d/%d",0,0);
        sprintf(cTemp,"0/0");

    }
    ui->m_pLb_FileIndTotal->setText(cTemp);
    ui->m_pLb_FileIndTotal->show();

    //刷新文件名字
    if (iCount > 0)
    {
        //ui->m_pLb_FileName->setText(QString("%1").arg(m_PhotoDir[m_iCurrIndex]));
        ui->m_pLb_FileName->setText(m_photoFiles[m_iCurrIndex]);
        ui->m_pLb_FileName->show();
    }
    else
    {
        ui->m_pLb_FileName->setText("");
        ui->m_pLb_FileName->show();
    }
}
//刷新文件并显示
void photoshow::RefreshFileAndShow()
{

    m_PhotoDir.setPath(PATH_PHOTO);
    if (!m_PhotoDir.exists()) {
        qDebug() << "图片目录不存在：" << PATH_PHOTO; // 排查路径是否正确
        return;
    }
    m_PhotoDir.refresh(); // 强制刷新目录，获取最新内容


    QStringList filters;
    filters<<"*.jpg";
    //m_PhotoDir.setNameFilters(filters);
    // 按修改时间倒序排列（最新生成的图片排在最前面）
    m_photoFiles = m_PhotoDir.entryList(
                filters,
                QDir::Files,
                QDir::Name
                );
    // 调整当前索引
    if (m_iCurrIndex >= m_photoFiles.count()) {
        m_iCurrIndex = qMax(0, m_photoFiles.count() - 1);
    }

    // 加载并显示当前图片
    if (!m_photoFiles.isEmpty()) {
        QString currentFile = m_photoFiles[m_iCurrIndex];
        QImage mImage;
        // 使用filePath获取完整路径，避免路径拼接错误
        if (mImage.load(m_PhotoDir.filePath(currentFile))) {
            ui->m_pLb_PhotoShow->setScaledContents(true);
            ui->m_pLb_PhotoShow->setPixmap(QPixmap::fromImage(mImage));
            ui->m_pLb_PhotoShow->show();
        } else {
            ui->m_pLb_PhotoShow->hide();
        }
    } else {
        ui->m_pLb_PhotoShow->hide();
    }

    RefreshFileMsg();
}


//上一张图片
void photoshow::On_Btn_Pre_Photo_Clicked()
{
    if (m_photoFiles.isEmpty()) return;

    if (m_iCurrIndex > 0) {
        m_iCurrIndex--;
        QImage mImage;
        QString currentFile = m_photoFiles[m_iCurrIndex];
        if (mImage.load(m_PhotoDir.filePath(currentFile))) {
            ui->m_pLb_PhotoShow->setPixmap(QPixmap::fromImage(mImage));
            ui->m_pLb_PhotoShow->show();
        }
        RefreshFileMsg();
    }

}

//下一张图片
void photoshow::On_Btn_Next_Photo_Clicked()
{
    if (m_photoFiles.isEmpty()) return;

    if (m_iCurrIndex < m_photoFiles.count() - 1) {
        m_iCurrIndex++;
        QImage mImage;
        QString currentFile = m_photoFiles[m_iCurrIndex];
        if (mImage.load(m_PhotoDir.filePath(currentFile))) {
            ui->m_pLb_PhotoShow->setPixmap(QPixmap::fromImage(mImage));
            ui->m_pLb_PhotoShow->show();
        }
        RefreshFileMsg();
    }

}

//删除文件
void photoshow::DelFile()
{
    if (m_photoFiles.isEmpty()) return;

    // 使用QFile删除更安全，避免路径问题
    QString currentFile = m_photoFiles[m_iCurrIndex];
    QFile file(m_PhotoDir.filePath(currentFile));
    if (file.remove()) {
        system("sync"); // 同步文件系统
    }

    // 调整索引
    if (m_iCurrIndex >= m_photoFiles.count() - 1) {
        m_iCurrIndex = qMax(0, m_iCurrIndex - 1);
    }

    RefreshFileAndShow(); // 重新刷新列表

}

//删除文件确认
void photoshow::On_Btn_Del_File_Clicked()
{

    int iCount = m_PhotoDir.count();
    if (iCount == 0)
        return;

    char cLngTextStr[100];
    strcpy(cLngTextStr,"确定删除该相片吗?");
    QMessageBox messageBox(QMessageBox::NoIcon,"",cLngTextStr, QMessageBox::Yes|QMessageBox::No, NULL);

    int iResult = messageBox.exec();
        switch (iResult) {
        case QMessageBox::Yes:
            DelFile();
            break;
        case QMessageBox::No:
            break;
        default:
            break;
    }
}

//返回
void photoshow::On_Btn_Return_Clicked()
{
    emit sigReturnTowidget();

}








