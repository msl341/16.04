#ifndef ZHUKUANG_H
#define ZHUKUANG_H

#include <QWidget>
#include "mykey.h"
#include <QTouchEvent>
namespace Ui {
class zhukuang;
}

class zhukuang : public QWidget
{
    Q_OBJECT

public:
    explicit zhukuang(QWidget *parent = nullptr);
    ~zhukuang();

    void refreshUI();
signals:
    void clicked_start();
    void clicked_photo();
    void clicked_video();
    void clicked_system();
    void clicked_enter_preview();
    void clicked_addReport();
    void clicked_browseReport();

    void nosd_card();
private slots:
    void on_addReportBtn_clicked();

    void on_browseReportBtn_clicked();

private:
    Ui::zhukuang *ui;

};


class Label_start : public QLabel
{
    Q_OBJECT
public:
    explicit Label_start(QWidget *parent = nullptr);

signals:
    void clicked_1();

protected:
    virtual void mousePressEvent(QMouseEvent* event);//重写mousePressEvent事件
};
class Label_photo : public QLabel
{
    Q_OBJECT
public:
    explicit Label_photo(QWidget *parent = nullptr);

signals:
    void clicked_1();

protected:
    virtual void mousePressEvent(QMouseEvent* event);//重写mousePressEvent事件
};
class Label_video : public QLabel
{
    Q_OBJECT
public:
    explicit Label_video(QWidget *parent = nullptr);

signals:
    void clicked_1();

protected:
    virtual void mousePressEvent(QMouseEvent* event);//重写mousePressEvent事件
};
class Label_system : public QLabel
{
    Q_OBJECT
public:
    explicit Label_system(QWidget *parent = nullptr);

signals:
    void clicked_1();

protected:
    virtual void mousePressEvent(QMouseEvent* event);//重写mousePressEvent事件
};
class AW2 : public QLabel
{
    Q_OBJECT
public:
    explicit AW2(QWidget *parent = nullptr);

signals:
    void clicked_1();

protected:
    virtual void mousePressEvent(QMouseEvent* event);//重写mousePressEvent事件
};
#endif // ZHUKUANG_H
