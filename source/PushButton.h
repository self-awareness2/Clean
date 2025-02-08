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
    void enterEvent(QEvent*) override;
    void leaveEvent(QEvent*) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent*) override;

private:
    enum ButtonStatus{NORMAL, ENTER, PRESS, NOSTATUS};
    ButtonStatus status;
    QString picName;

    int btnWidth; 
    int btnHeight;
    bool mousePress;
};

