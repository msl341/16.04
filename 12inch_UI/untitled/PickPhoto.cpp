#include "PickPhoto.h"
#include "ui_PickPhoto.h"

PickPhoto::PickPhoto(QWidget *parent, QString FolderPath) :
    QDialog(parent),
    ui(new Ui::PickPhoto)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_DeleteOnClose);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::Dialog);
    QScroller::grabGesture(ui->listView->viewport(), QScroller::LeftMouseButtonGesture);

    if(flag_USB == 1){
        path = "/mnt/USB_FLASH/Picture/" + FolderPath;
    }
    else if(flag_USB == 0 && flag_SD == 1){
        path = "/mnt/SD_CARD/Picture/" + FolderPath;
    }

    QDir Directory(path);
    if(!Directory.exists()){
        QString command = "mkdir -p " + path;
        qDebug() << command;
        int result = system(command.toStdString().c_str());
        if (result == 0) {
            qDebug() << "Command executed successfully!";
        } else {
            qDebug() << "Command failed with return code:" << result;
        }
    }
    system("sync");
    QStandardItemModel *model = new QStandardItemModel(this);
    QStringList filters;
    filters << "*.png" << "*.jpg";  // 可以根據需要添加更多的檔名
    QStringList LoadFileList = Directory.entryList(filters, QDir::Files);
    filters.clear();//jason
    if(LoadFileList.size() > 0){
        ui->label->setVisible(false);
        for (QString filePath : LoadFileList){
            QFileInfo info(Directory, filePath);
            QString shortName = formatFileName(info.fileName(), 10);
            QStandardItem *item = new QStandardItem(QIcon(info.filePath()), shortName);
            item->setData(info.fileName(), Qt::UserRole + 1);
            model->appendRow(item);
            QPixmapCache::clear();
        }
    }
    else{
        ui->label->setVisible(true);
    }


    ui->listView->setModel(model);
}

PickPhoto::~PickPhoto()
{
    delete ui;
}

QString PickPhoto::formatFileName(const QString &fileName, int maxLength)
{
    if (fileName.length() <= maxLength) {
        return fileName;  // 如果文件名小於或等於最大長度，則直接返回
    }

    QString extension = fileName.section('.', -1);  // 取得文件的副檔名
    QString baseName = fileName.left(fileName.lastIndexOf("."));  // 取得不包括副檔名的部分

    int partLength = (maxLength - 3 - extension.length()) / 2;  // 保留開頭和結尾的長度
    QString shortName = baseName.left(partLength) + "..." + baseName.right(partLength);

    return shortName + "." + extension;
}

void PickPhoto::refreshUI()
{
    ui->retranslateUi(this);
}

void PickPhoto::on_cancelBtn_clicked()
{
    close();
}

void PickPhoto::on_okBtn_clicked()
{
    QModelIndexList selectedList = ui->listView->selectionModel()->selectedIndexes();

    QList<QString> selectedPhotoPaths;
    for(const QModelIndex &item : selectedList){
        selectedPhotoPaths.append(item.data(Qt::UserRole + 1).toString());
        qDebug() << item.data(Qt::UserRole + 1).toString();
    }
    emit selected(selectedPhotoPaths);
    close();
}
