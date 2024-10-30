#pragma once
#include <qapplication.h>
#include <QDialog>
#include <QWidget>
#include <QPainter>		
#include <QMouseEvent>
#include <qmath.h>	

class DropShadowWidget : public QDialog
{
	Q_OBJECT

public:

	explicit DropShadowWidget(QWidget* parent = 0);
	~DropShadowWidget();

protected:

	void mousePressEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	void mouseMoveEvent(QMouseEvent* event);
	virtual void paintEvent(QPaintEvent* event);

private:

	QPoint move_point; //�ƶ��ľ���
	bool mouse_press; //����������

};

