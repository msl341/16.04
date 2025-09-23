#ifndef RESETWINDOW_H
#define RESETWINDOW_H
#include "mykey.h"
namespace Ui {
class resetwindow;
}

class resetwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit resetwindow(QWidget *parent = nullptr);
    ~resetwindow();

private:
    Ui::resetwindow *ui;
public:


signals:
    void sigReturnTowidget();


private slots:
    //确认
    void On_Btn_Confirm_Clicked();
    //取消
    void On_Btn_Cancel_Clicked();

};














#endif // RESETWINDOW_H
