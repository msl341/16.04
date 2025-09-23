#ifndef DATETIMEWINDOW_H
#define DATETIMEWINDOW_H
#include "mykey.h"
namespace Ui {
class datetimewindow;
}

class datetimewindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit datetimewindow(QWidget *parent = nullptr);
    ~datetimewindow();

private:
    Ui::datetimewindow *ui;
public:

    int m_i_Year;
    int m_i_Month;
    int m_i_Day;
    int m_i_Hour;
    int m_i_Min;
signals:
    void sigReturnTowidget();

private slots:
    //年按上
    void On_Btn_Year_Up_Clicked();
    //年按下
    void On_Btn_Year_Down_Clicked();
    //月按上
    void On_Btn_Month_Up_Clicked();
    //月按下
    void On_Btn_Month_Down_Clicked();
    //日按上
    void On_Btn_Day_Up_Clicked();
    //日按下
    void On_Btn_Day_Down_Clicked();
    //时按上
    void On_Btn_Hour_Up_Clicked();
    //时按下
    void On_Btn_Hour_Down_Clicked();
    //分按上
    void On_Btn_Min_Up_Clicked();
    //分按下
    void On_Btn_Min_Down_Clicked();
    //保存
    void On_Btn_Save_Clicked();
    //返回
    void On_Btn_Return_Clicked();
};










#endif // DATETIMEWINDOW_H
