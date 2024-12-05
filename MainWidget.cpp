#include "mainWidget.h"

MainWidget::MainWidget(QWidget* parent)
{
	log().init("CleanLog"); // 初始化日志系统
	log().Debug("test");
	controller = new Controller();
	setMinimumSize(1200, 900);
	QPushButton *a =new  QPushButton(QString::fromLocal8Bit("抬盖"),this);
	QPushButton *b =new QPushButton(QString::fromLocal8Bit("回家"),this);
	QPushButton *c =new  QPushButton(QString::fromLocal8Bit("合盖"),this);
	QPushButton *stop =new QPushButton(QString::fromLocal8Bit("停止	"),this);
	a->setGeometry(100,100,100,50); // 设置固定大小
	c->setGeometry(200,100,100,50); // 设置固定大小
	b->setGeometry(100,200,100,50); // 设置固定大小
	stop->setGeometry(200,200,100,50); // 设置固定大小
	connect(a, &QPushButton::clicked, controller, [&]() {	QtConcurrent::run(controller, &Controller::caseUp);});
	connect(b, &QPushButton::clicked, controller, &Controller::backHome);
	connect(c, &QPushButton::clicked, controller, [&](){	QtConcurrent::run(controller, &Controller::caseDown);	});
	connect(stop, &QPushButton::clicked, controller, &Controller::stop);
	titleWidget = new TitleWidget(this);
	titleWidget->hide();
}


MainWidget::~MainWidget()
{
}

