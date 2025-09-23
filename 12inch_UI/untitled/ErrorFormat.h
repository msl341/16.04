#ifndef ERRORFORMAT_H
#define ERRORFORMAT_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class ErrorFormat;
}

class ErrorFormat : public QWidget
{
    Q_OBJECT

public:
    explicit ErrorFormat(QWidget *parent = nullptr);
    ~ErrorFormat();

    void setErrroMsg(QString errMsg);

signals:
    void hideErrorFormat();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::ErrorFormat *ui;
};

#endif // ERRORFORMAT_H
