#include "TitleWidget.h"

TitleWidget::TitleWidget(QWidget* parent)
	:QWidget(parent)
{
	title = new QLabel;
	logo = new QLabel; // astiLogo
	controlButton = new PushButton();
	imageButton = new PushButton();
	minButton = new PushButton();
	closeButton = new PushButton();

	title->setObjectName("whiteLabel");

	controlButton->setPicName(QString(":/"));
	imageButton->setPicName(QString(":/"));
	minButton->setPicName(QString(""));
	closeButton->setPicName(QString());

	//connect


	//上半部分 
	QHBoxLayout* titleLayout = new QHBoxLayout();
	titleLayout->addWidget(title, 0, Qt::AlignVCenter);
	titleLayout->addStretch();
	titleLayout->addWidget(minButton, 0, Qt::AlignTop);
	titleLayout->addWidget(closeButton, 0, Qt::AlignTop);
	titleLayout->setSpacing(0);
	titleLayout->setContentsMargins(0, 0, 5, 0);
	title->setContentsMargins(15, 0, 0, 0);

	//下半部分
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	buttonLayout->addWidget(controlButton, 0, Qt::AlignBottom);
	buttonLayout->addWidget(imageButton, 0, Qt::AlignBottom);

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addLayout(titleLayout);
	mainLayout->addLayout(buttonLayout);

	setLayout(mainLayout);

}
