#ifndef LANSETWINDOW_H
#define LANSETWINDOW_H
#include "mykey.h"
namespace Ui {
class lansetwindow;
}

class lansetwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit lansetwindow(QWidget *parent = nullptr);
    ~lansetwindow();

private:
    Ui::lansetwindow *ui;
public:
    //选择按钮
    void SelBtn(int iFlag);
    //设置文字
    void SetText();

private slots:
    //简体中文
    void On_Btn_SimpleCh_Clicked();
    //繁体中文
    void On_Btn_TraditionCh_Clicked();
    //英语
    void On_Btn_English_Clicked();
    //法语
    void On_Btn_French_Clicked();
    //德语
    void On_Btn_German_Clicked();
    //取消
    void On_Btn_Cancel_Clicked();
signals:
    void sigReturnTowidget();




};


#endif // LANSETWINDOW_H
