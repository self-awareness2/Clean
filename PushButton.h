#pragma once
#include <qpushbutton.h>
#include <QMouseEvent>
#include <QPainter>
class PushButton :
    public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget* parent = nullptr);
    ~PushButton();
    void setPicName(QString picName);
protected:
    void enterEvent(QEvent*);
    void leaveEvent(QEvent*);
    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void paintEvent(QPaintEvent*);

private:
    enum ButtonStatus{NORMAL, ENTER, PRESS, NOSTATUS};
    ButtonStatus status;
    QString picName;

    int btnWidth; 
    int btnHeight;
    bool mousePress;
};

