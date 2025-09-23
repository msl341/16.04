#ifndef LOWBATTERY_H
#define LOWBATTERY_H

#include <QDialog>

namespace Ui {
class LowBattery;
}

class LowBattery : public QDialog
{
    Q_OBJECT

public:
    explicit LowBattery(QWidget *parent = nullptr);
    ~LowBattery();

    void refreshUI();

private slots:
    void on_closeBtn_clicked();

private:
    Ui::LowBattery *ui;
};

#endif // LOWBATTERY_H
