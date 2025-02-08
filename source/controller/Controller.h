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
	explicit Controller(QObject* parent = nullptr);
	void setupStateMachine();
	bool initalize(short deviceNo);
	~Controller();

signals:
	void errorOccured(const std::string& msg);

public slots:
	bool  backHome();   //回原点
	void caseUp();		//抬盖
	void maskUp(); //移动口罩夹
	void caseDown(); //降下盖子
	void stop(); //停止
	void svOff(); //断所有使能
	void autoRun();  //自动流程
	void maskDetect(); //检测
private:
	enum ProcessState {
		ST_IDLE,            // 空闲状态
		ST_STEP1_LIFT_DOWN, // 步骤1：抬盖升降下降
		ST_STEP1_GRIP_OPEN, // 步骤1：夹爪伸出
		ST_STEP1_LIFT_UP,   // 步骤1：抬盖升降上升
		ST_STEP2_MASK_MOVE, // 步骤2：mask搬运移动
		ST_STEP2_MASK_DOWN, // 步骤2：mask升降下降
		ST_STEP2_MASK_GRIP, // 步骤2：mask夹爪伸出
		ST_STEP2_MASK_UP,   // 步骤2：mask升降上升
		ST_STEP3_SCAN,      // 步骤3：mask搬运移动并拍摄
		ST_STEP4_MASK_DOWN, // 步骤4：mask升降下降
		ST_STEP4_MASK_GRIP, // 步骤4：mask夹爪收回
		ST_STEP4_MASK_UP,   // 步骤4：mask升降上升
		ST_STEP5_LIFT_DOWN, // 步骤5：抬盖升降下降
		ST_STEP5_GRIP_CLOSE,// 步骤5：夹爪收回
		ST_STEP5_LIFT_UP,   // 步骤5：抬盖升降上升
		ST_COMPLETED,       // 完成状态
		ST_PAUSED,          // 暂停状态
		ST_ERROR            // 错误状态
	};
	ProcessState currentState;

	bool maskSize; //0 小 1 大
	enum detectMode{
		MODE_DETECT,
		MODE_DETECT_ClEAN_DETECT,
		MODE_CLEAN_DETECT
	};
	detectMode detectMode;
	int circleCount;
	QTimer* timer;


	void checkStatus();
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
