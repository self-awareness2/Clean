#include "mainWidget.h"

MainWidget::MainWidget(QWidget* parent)
{
	controller = new Controller();
	
	
	setMinimumSize(1200, 900);
	QPushButton *a =new  QPushButton(QString::fromLocal8Bit("Ì§¸Ç"),this);
	QPushButton *b =new QPushButton(QString::fromLocal8Bit("»Ø¼Ò"),this);
	QPushButton *c =new  QPushButton(QString::fromLocal8Bit("ºÏ¸Ç"),this);
	QPushButton *stop =new QPushButton(QString::fromLocal8Bit("Í£Ö¹"),this);
	
	connect(a, &QPushButton::clicked, this, [&]() {controller->caseUp(); });
	connect(b,&QPushButton::clicked, this, [&]() {controller->backHome(); });
	connect(c, &QPushButton::clicked, this, [&]() {controller->caseDown(); });
	connect(stop,&QPushButton::clicked, this, [&]() {controller->stop(); });

	titleWidget = new TitleWidget(this);
	//titleWidget->hide();
}


MainWidget::~MainWidget()
{
	delete controller;
}

