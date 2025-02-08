#pragma once
#include <qmainwindow.h>
#include <QtConcurrent/qtconcurrentrun.h>
#include <qgroupbox.h>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <qpushbutton.h>

#include "../log/Logger.h"
#include "../controller/Controller.h"
class MainWidget :public QMainWindow
{
	Q_OBJECT
public:
	MainWidget(QWidget *parent = nullptr);
	~MainWidget();
	Controller *controller;

public slots:
	void stateChanged(Controller::ProcessState state);
	void stepChanged(short step);
private:
	QPushButton *a;
    QPushButton *c;
    QPushButton *stop;
    QPushButton *test;
	QLabel* stateLabel;
	QLabel* stepLabel;
	//TitleWidget* titleWidget;

};

