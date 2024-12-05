#include "mainWidget.h"

MainWidget::MainWidget(QWidget* parent)
{
	log().init("CleanLog"); // ��ʼ����־ϵͳ
	log().Debug("test");
	controller = new Controller();
	setMinimumSize(1200, 900);
	QPushButton *a =new  QPushButton(QString::fromLocal8Bit("̧��"),this);
	QPushButton *b =new QPushButton(QString::fromLocal8Bit("�ؼ�"),this);
	QPushButton *c =new  QPushButton(QString::fromLocal8Bit("�ϸ�"),this);
	QPushButton *stop =new QPushButton(QString::fromLocal8Bit("ֹͣ	"),this);
	a->setGeometry(100,100,100,50); // ���ù̶���С
	c->setGeometry(200,100,100,50); // ���ù̶���С
	b->setGeometry(100,200,100,50); // ���ù̶���С
	stop->setGeometry(200,200,100,50); // ���ù̶���С
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

