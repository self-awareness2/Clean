#pragma once
#include <qobject.h>
#include <qthread.h>
#include <qcoreapplication.h>
#include <vector>
#include <thread>
#include "Axis.h"
#include "Logger.h"
#define log() lg::Logger::instance()
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
	LOG4QT_DECLARE_STATIC_LOGGER(logger, "mystaticlog");
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
		//char* errstr = functionName + "failed with error code:";// errorCode + '\n';
		log().Error("controll funcerro");
	}

};
