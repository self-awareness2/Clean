#pragma once
#include <qmainwindow.h>
#include <QtConcurrent/qtconcurrentrun.h>
#include "TitleWidget.h"
#include "Controller.h"
class MainWidget :public QMainWindow
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = nullptr);
	~MainWidget();
	Controller *controller;
protected:

public slots:
private:
	TitleWidget* titleWidget;
};

