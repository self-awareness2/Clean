#include "mainWidget.h"

MainWidget::MainWidget(QWidget* parent)
{
	controller = new Controller();
	
	
	setMinimumSize(1200, 900);
	QPushButton *a =new  QPushButton(QString::fromLocal8Bit("̧��"),this);
	QPushButton *b =new QPushButton(QString::fromLocal8Bit("�ؼ�"),this);
	QPushButton *c =new  QPushButton(QString::fromLocal8Bit("�ϸ�"),this);
	QPushButton *stop =new QPushButton(QString::fromLocal8Bit("ֹͣ"),this);
	
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

