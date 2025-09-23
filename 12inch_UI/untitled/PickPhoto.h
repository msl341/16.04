#ifndef PICKPHOTO_H
#define PICKPHOTO_H

#include <QDialog>
#include <QStandardItemModel>
#include <QScroller>

#include "mykey.h"

namespace Ui {
class PickPhoto;
}

class PickPhoto : public QDialog
{
    Q_OBJECT

public:
    explicit PickPhoto(QWidget *parent = nullptr, QString FolderPath = "default");
    ~PickPhoto();
    QString formatFileName(const QString &fileName, int maxLength);

    void refreshUI();

signals:
    void selected(QList<QString> selectedList);

private slots:

    void on_cancelBtn_clicked();

    void on_okBtn_clicked();

private:
    Ui::PickPhoto *ui;

    QString path = "", pathDefault = "";
};

#endif // PICKPHOTO_H
