#include "TitleWidget.h"

TitleWidget::TitleWidget(QWidget* parent)
	:QWidget(parent)
{
	setGeometry(30, 0, 1150, 150);
	//上半部分 
	title = new QLabel(QString::fromLocal8Bit("MASK检测吹扫-ASTI"));
	title->setObjectName("whiteLabel");


	minButton = new PushButton();
	closeButton = new PushButton();


	QHBoxLayout* titleLayout = new QHBoxLayout();
	titleLayout->addWidget(title, 0, Qt::AlignTop);
	titleLayout->addStretch();
	titleLayout->addWidget(minButton, 0, Qt::AlignTop);
	titleLayout->addWidget(closeButton, 0, Qt::AlignTop);
	titleLayout->setSpacing(0);
	titleLayout->setContentsMargins(0, 0, 5, 0);
	title->setContentsMargins(15, 0, 0, 0);

	//下半部分
	controlButton = new PushButton();
	imageButton = new PushButton();


	
	controlButton->setPicName(QString("../img/operation/control.png"));
	imageButton->setPicName(QString("../img/operation/view.png"));
	minButton->setPicName(QString("../img/min.png"));
	closeButton->setPicName(QString("../img/close.png"));

	logo = new QLabel(); 
	QPixmap pixmap = QPixmap("../img/logo.png");
	logo->setPixmap(pixmap);
	logo->setFixedSize(pixmap.size());
	logo->setAlignment(Qt::AlignRight);
	QHBoxLayout* buttonLayout = new QHBoxLayout();
	buttonLayout->addWidget(controlButton, 0, Qt::AlignBottom);
	buttonLayout->addWidget(imageButton, 0, Qt::AlignBottom);
	buttonLayout->addStretch();
	buttonLayout->addWidget(logo);
	buttonLayout->setSpacing(30);

	QVBoxLayout* mainLayout = new QVBoxLayout();
	mainLayout->addLayout(titleLayout);
	mainLayout->addLayout(buttonLayout);
	setLayout(mainLayout);

	//connect
	connect(minButton, &QPushButton::clicked, parent, &QWidget::hide);
}
