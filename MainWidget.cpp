#include "mainWidget.h"

MainWidget::MainWidget(QWidget* parent)
	:DropShadowWidget(parent)
{
	controller = new Controller();
	
	setMinimumSize(1200, 900);
	QPushButton *a =new  QPushButton(QString::fromLocal8Bit("Ì§¸Ç"),this);
	QPushButton *c =new  QPushButton(QString::fromLocal8Bit("ºÏ¸Ç"),this);
	QPushButton *b =new QPushButton(QString::fromLocal8Bit("»Ø¼Ò"),this);
	QPushButton *stop =new QPushButton(QString::fromLocal8Bit("Í£Ö¹"),this);
	
	
	a->setGeometry(500, 400, 100, 40);
	b->setGeometry(500, 500, 100, 40);
	c->setGeometry(500, 700, 100, 40);
	stop->setGeometry(500, 600, 100, 40);	
	connect(a, &QPushButton::clicked, this, [&]() {controller->caseUp(); });
	connect(c, &QPushButton::clicked, this, [&]() {controller->caseDown(); });
	connect(b,&QPushButton::clicked, this, [&]() {controller->backHome(); });
	connect(stop,&QPushButton::clicked, this, [&]() {controller->stop(); });

	titleWidget = new TitleWidget(this);
	titleWidget->hide();
}




void MainWidget::paintEvent(QPaintEvent* event)
{
    DropShadowWidget::paintEvent(event);
}

MainWidget::~MainWidget()
{
	delete controller;
}

