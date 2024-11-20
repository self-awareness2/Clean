#pragma once
#include "DropShadowWidget.h"
#include "TitleWidget.h"
#include "Controller.h"
class MainWidget :public DropShadowWidget
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = nullptr);
	~MainWidget();
	void paintEvent(QPaintEvent* event);
	Controller *controller;
protected:

public slots:
private:
	TitleWidget* titleWidget;
};

