#include "PushButton.h"

PushButton::PushButton(QWidget* parent)
	:QPushButton(parent)
{
	status = NORMAL;
	mousePress = false;
}

PushButton::~PushButton()
{

}

void PushButton::setPicName(QString picName)
{
	this->picName = picName;
	setFixedSize(QPixmap(picName).size());
}

void PushButton::enterEvent(QEvent*)
{
	status = ENTER;
	update(); //ÖØÐÂ»æÖÆ
}

void PushButton::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		mousePress = true;
		status = PRESS;
		update();
	}
}

void PushButton::mouseReleaseEvent(QMouseEvent* event)
{
	if (mousePress && this->rect().contains(event->pos()))
	{
		mousePress = false;
		status = ENTER;
		update();
		emit clicked();
	}
}

void PushButton::leaveEvent(QEvent*)
{
	status = NORMAL;
	update();
}

void PushButton::paintEvent(QPaintEvent*)
{
	QPainter painter(this);
	QPixmap pixmap;
	switch (status)
	{
	case PushButton::NORMAL:
	{
		pixmap.load(picName);
		break;
	}
	case PushButton::ENTER:
	{
		pixmap.load(picName+QString("_hover"));
		break;
	}
	case PushButton::PRESS:
	{
		pixmap.load(picName + QString("_pressed"));

		break;
	}
	case PushButton::NOSTATUS:
	{
		pixmap.load(picName);
		break;
	}
	default:
		pixmap.load(picName);
		break;
	}
	painter.drawPixmap(rect(), pixmap);
}

