#ifndef PHOTOSHOW_H
#define PHOTOSHOW_H
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QFileDialog>
#include <QMessageBox>
#include "UsbMcu.h"

#include "mykey.h"


namespace Ui {
class photoshow;
}

class photoshow : public QMainWindow
{
    Q_OBJECT

public:
    explicit photoshow(QWidget *parent = nullptr);
    ~photoshow();

public:

    QDir m_PhotoDir;
    int m_iCurrIndex;
    QStringList m_photoFiles;

signals:
    void sigReturnTowidget();

public:

    //刷新文件信息
    void RefreshFileMsg();
    //刷新文件并显示
    void RefreshFileAndShow();
    //删除文件
    void DelFile();
private slots:
    //上一张图片
    void On_Btn_Pre_Photo_Clicked();
    //下一张图片
    void On_Btn_Next_Photo_Clicked();
    //删除文件确认
    void On_Btn_Del_File_Clicked();
    //返回
    void On_Btn_Return_Clicked();
public slots:
    void refreshPhotos();
private:
    Ui::photoshow *ui;


};


#endif // PHOTOSHOW_H
