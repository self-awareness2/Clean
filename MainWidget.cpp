#include "mainWidget.h"

MainWidget::MainWidget(QWidget* parent)
	:DropShadowWidget(parent)
{
	setMinimumSize(1200, 800);

	titleWidget = new TitleWidget(this);
}
