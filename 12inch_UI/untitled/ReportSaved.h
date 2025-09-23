#ifndef REPORTSAVED_H
#define REPORTSAVED_H

#include <QWidget>

namespace Ui {
class ReportSaved;
}

class ReportSaved : public QWidget
{
    Q_OBJECT

public:
    explicit ReportSaved(QWidget *parent = nullptr);
    ~ReportSaved();

    void refreshUI();

private:
    Ui::ReportSaved *ui;
};

#endif // REPORTSAVED_H
