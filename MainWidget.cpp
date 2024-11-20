#include "mainWidget.h"

MainWidget::MainWidget(QWidget* parent)
	:DropShadowWidget(parent)
{
	
	setMinimumSize(1200, 900);
	titleWidget = new TitleWidget(this);
	titleWidget->show();
	controller = new Controller();

}




void MainWidget::paintEvent(QPaintEvent* event)
{
    DropShadowWidget::paintEvent(event);
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
     painter.drawPixmap(10, 0, width()-20, 150, QPixmap("img/skin/12_big.png"));
}

MainWidget::~MainWidget()
{
	delete controller;
}

