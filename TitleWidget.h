#pragma once
#include <QWidget>
#include <QLabel>
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
	QLabel* logo; // astiLogo
	


};

