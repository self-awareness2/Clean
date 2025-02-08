#pragma once
#include <qobject.h>
#include <qthread.h>
#include <qcoreapplication.h>
#include <QTimer>
#include <vector>
#include <thread>
#include <qstatemachine.h>
#include "Axis.h"
#include "../log/Logger.h"


class Controller : public QObject
{
	Q_OBJECT
private:
	HAND devHandle;
	std::vector<Axis> axes;
	std::vector<AxisStatus> axesSts;
	std::atomic<bool> stopRequested;
	const char* myGml = "../singal_final.gml";
public:
	enum ProcessState {
		ST_IDLE,            // 空闲状态
		ST_RUNNING,			//运行状态
		ST_PAUSED,          // 暂停状态
		ST_ERROR            // 错误状态
	};
	explicit Controller(QObject* parent = nullptr);
	bool initalize(short deviceNo);
	~Controller();

signals:
	void errorOccured(const std::string& msg);
	void stepChanged(short step);
	void stateChanged(ProcessState state);

public :
	ProcessState currentState;
	bool  backHome();   //回原点
	void caseUp();		//抬盖
	void maskUp(); //移动口罩夹
	void caseDown(); //降下盖子
	void stop(); //停止
	void svOff(); //断所有使能
	void autoRun();  //自动流程
	void maskDetect(); //检测
	void maskDown(); //口罩下降

private:
	bool maskSize; //0 小 1 大
	enum detectMode{
		MODE_DETECT,
		MODE_DETECT_ClEAN_DETECT,
		MODE_CLEAN_DETECT
	};
	detectMode detectMode;
	int circleCount;
	void flashAxisStaus();
	void camera();
	void logError(const std::string& functionName, short errorCode) {
		std::string errmsg = functionName + "failed with error code " + std::to_string(errorCode);
		lg::Logger::instance().Error(errmsg.c_str());
		emit errorOccured(errmsg);
	}
	void logError(const std::string msg)
	{
		lg::Logger::instance().Error(msg.c_str());
		emit errorOccured(msg);
	}	
	void logInfo(const std::string msg)
	{
		lg::Logger::instance().Info(msg.c_str());
	}
	bool together();
	void stopTogether();
	bool areAllAxesInInitialState();
};
