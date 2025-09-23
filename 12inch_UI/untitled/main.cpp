#include "widget.h"

#include <QApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    printf("==============1749=================\n");
//    qputenv("QT_IM_MODULE", QByteArray("Qt5Input"));

    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QApplication a(argc, argv);
    Widget w;

    QFile styleFile(":/sanping.qss");
    styleFile.open(QFile::ReadOnly);
    QString style = QLatin1String(styleFile.readAll());
    a.setStyleSheet(style);
    styleFile.close();

    w.show();
    return a.exec();
}
