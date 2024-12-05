#pragma once
#include <qmainwindow.h>
#include <QtConcurrent/qtconcurrentrun.h>

#include "Logger.h"
#define log() lg::Logger::instance()
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

