#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>

namespace Ui {
class KeyBoard;
}

class KeyBoard : public QWidget
{
    Q_OBJECT

public:
    explicit KeyBoard(QWidget *parent = nullptr);
    ~KeyBoard();

    void moveKeyBoard();
    void showFullKeyBoard();
    bool btnVisible();

signals:
    void showStackTwo();
    void hideKeyBoard();
    void clickPos(QPoint pos);

private slots:
    void setMoveBtnVisible(bool status);

protected:
    void mousePressEvent(QMouseEvent *event) override ;

private:
    Ui::KeyBoard *ui;
};

#endif // KEYBOARD_H
