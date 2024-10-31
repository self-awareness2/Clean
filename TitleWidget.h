#pragma once
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include "PushButton.h"
class TitleWidget : public QWidget
{
	Q_OBJECT
public:
	explicit TitleWidget(QWidget* parent = nullptr);

public slots:


signals:
	void showMin();
	void showMainMenu();
	void closeWidget();
	void changePage();

private:
	QPoint pressPoint;
	QLabel* title;
	QLabel* logo; // astiLogo
	bool isMove;
	PushButton* controlButton;
	PushButton* imageButton;
	PushButton* minButton;
	PushButton* closeButton;
};

