#include "mainWidget.h"
#include <QScrollArea>
#include <opencv2/opencv.hpp>
#include <cstdio>
#include <iostream>


MainWidget::MainWidget(QWidget* parent)
    : QMainWindow(parent)
{
    lg::Logger::instance().init("CleanLog"); // 初始化日志系统
    lg::Logger::instance().Info("App Start!");
	qRegisterMetaType<Controller::ProcessState>("Controller::ProcessState");

    setMinimumSize(1200, 900);
    a = new QPushButton(QString::fromLocal8Bit("抬盖"), this);
	b = new QPushButton(QString::fromLocal8Bit("回家"), this);
    c = new QPushButton(QString::fromLocal8Bit("合盖"), this);
    stop = new QPushButton(QString::fromLocal8Bit("停止"), this);
    test = new QPushButton(QString::fromLocal8Bit("运行测试"), this);
    a->setGeometry(100,100,100,50); // 设置固定大小
    c->setGeometry(200,100,100,50); // 设置固定大小
    stop->setGeometry(200,200,100,50); // 设置固定大小
    test->setGeometry(300,200,100,50); // 设置固定大小


	stateLabel = new QLabel(this);
	stateLabel->setGeometry(100, 250, 100, 50);
	stateLabel->setStyleSheet("font-size: 20px;");
	stateLabel->setText(QString::fromLocal8Bit("当前状态:"));

	stepLabel = new QLabel(this);
	stepLabel->setGeometry(100,300,100,50);
	stepLabel->setStyleSheet("font-size: 20px;");
	stepLabel->setText(QString::fromLocal8Bit("当前步骤:"));
	

	QThread* controllerThread = new QThread(this);
	controller = new Controller();
	connect(a, &QPushButton::clicked, controller, [&]() {QtConcurrent::run(controller, &Controller::caseUp);});
	connect(b, &QPushButton::clicked, controller, [&]() {QtConcurrent::run(controller, &Controller::backHome);});
	connect(c, &QPushButton::clicked, controller, [&]() {QtConcurrent::run(controller, &Controller::caseDown);});
	connect(test, &QPushButton::clicked, controller, [&]() {QtConcurrent::run(controller, &Controller::autoRun);});
	connect(stop, &QPushButton::clicked, controller, &Controller::stop);
	connect(controller, &Controller::stateChanged, this, &MainWidget::stateChanged);
	connect(controller, &Controller::stepChanged, this, &MainWidget::stepChanged);
}


void MainWidget::stateChanged(Controller::ProcessState state)
{
	switch(state)
	{
		case Controller::ST_IDLE:
			stateLabel->setText(QString::fromLocal8Bit("请选择"));
			break;
		case Controller::ST_RUNNING:
			stateLabel->setText(QString::fromLocal8Bit("运行中"));
			break;

		case Controller::ST_PAUSED:
			stateLabel->setText(QString::fromLocal8Bit("暂停"));
			break;
		case Controller::ST_ERROR:
			stateLabel->setText(QString::fromLocal8Bit("错误"));
			break;
	}
}
void MainWidget::stepChanged(short step)

{
	switch(step)
	{
		case 0:
			stepLabel->setText(QString::fromLocal8Bit("当前步骤: CaseUp!"));
			break;
		case 1:
			stepLabel->setText(QString::fromLocal8Bit("当前步骤: MaskUp!"));
			break;
		case 2:
			stepLabel->setText(QString::fromLocal8Bit("当前步骤: MaskDetect!"));
			break;
		case 3:
			stepLabel->setText(QString::fromLocal8Bit("当前步骤: MaskDown!"));
			break;
		case 4:
			stepLabel->setText(QString::fromLocal8Bit("当前步骤: CaseDown!"));
			break;
	}
}

MainWidget::~MainWidget()
{
	delete controller;
	lg::Logger::instance().Info("App End!");
}
