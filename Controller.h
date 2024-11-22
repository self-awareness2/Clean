#pragma once
#include <qobject.h>
#include <qthread.h>
#include <qcoreapplication.h>
#include <vector>
#include <thread>
#include "Axis.h"
class Controller : public QObject
{
	Q_OBJECT
private:
	HAND devHandle;
	std::vector<Axis> axes;
	std::vector<short> axesSts;
	std::atomic<bool> stopRequested;
	char* myGml;
public:
	explicit Controller(QObject * parent = nullptr );
	bool initalize(short deviceNo);
	~Controller();


public slots:	
	void  backHome();
	void caseUp();
	void caseDown();
	void stop();
	void svOff();

private:
	void flashStas();
	void printError(const std::string& functionName, short errorCode) {
		std::cerr << functionName << " failed with error code: " << errorCode << "\n";
	}

};
