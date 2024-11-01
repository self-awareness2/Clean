#pragma once
#include "DropShadowWidget.h"
#include "TitleWidget.h"
class MainWidget :public DropShadowWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = nullptr);
	void paintEvent(QPaintEvent* event);
protected:
public slots:
private:
	TitleWidget* titleWidget;
};

