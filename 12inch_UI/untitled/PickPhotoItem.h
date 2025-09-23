#ifndef PICKPHOTOITEM_H
#define PICKPHOTOITEM_H

#include <QWidget>

namespace Ui {
class PickPhotoItem;
}

class PickPhotoItem : public QWidget
{
    Q_OBJECT

public:
    explicit PickPhotoItem(bool enableClick = true, QWidget *parent = nullptr);
    ~PickPhotoItem();

    void itemSetIconVisible(bool status);
    bool itemGetIconVisible();
    void itemSetPhoto(QString path);
    void itemSetPhotoPath(QString path);
    QString itemGetPhotoPath();
    void itemSetIndex(int idx);
    void itemResize(int width, int height);

signals:
    void clicked(int idx, bool status);

private slots:
    void on_pickPhoto_clicked();

private:
    Ui::PickPhotoItem *ui;

    QString photoPath;
    int index = 0;
    bool clickable = true;
};

#endif // PICKPHOTOITEM_H
