#pragma once
#include "DropShadowWidget.h"
#include "TitleWidget.h"
class MainWidget :public DropShadowWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = nullptr);
protected:
public slots:
private:
	TitleWidget* titleWidget;
};

