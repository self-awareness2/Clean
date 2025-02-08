#include "Controller.h"

Controller::Controller( QObject * parent ):QObject(parent)
{
	if (!initalize(0)) {
		logError("Controller initialization failed");
	}
}


bool Controller::backHome() 
{
	axes[0].home(1, 10);
	axes[1].home(2, 10);
	axes[2].home(17, 10);
	axes[3].home(17, 10);
	axes[4].home(18, 100);
	axes[5].home(18, 100);
	axes[6].home(17, 80);
	axes[7].home(17, 80);
	axes[8].home(17, 80);
	axes[9].home(17, 80);
	axes[10].home(18, 80);
	axes[11].home(18, 80);
	axes[12].home(17, 80);
	axes[13].home(17, 80);	
	axes[14].home(17, 80);
	axes[15].home(17, 80);
	return true;
}
void Controller::setupStateMachine() {
	// 创建状态
	//m_states[ST_IDLE] = new QState();
	//m_states[ST_STEP1_LIFT_DOWN] = new QState();
	//m_states[ST_STEP1_GRIP_OPEN] = new QState();
	//m_states[ST_STEP1_LIFT_UP] = new QState();
	//m_states[ST_STEP2_MASK_MOVE] = new QState();
	//m_states[ST_STEP2_MASK_DOWN] = new QState();
	//m_states[ST_STEP2_MASK_GRIP] = new QState();
	//m_states[ST_STEP2_MASK_UP] = new QState();
	//m_states[ST_STEP3_SCAN] = new QState();
	//m_states[ST_STEP4_MASK_DOWN] = new QState();
	//m_states[ST_STEP4_MASK_GRIP] = new QState();
	//m_states[ST_STEP4_MASK_UP] = new QState();
	//m_states[ST_STEP5_LIFT_DOWN] = new QState();
	//m_states[ST_STEP5_GRIP_CLOSE] = new QState();
	//m_states[ST_STEP5_LIFT_UP] = new QState();
	//m_states[ST_COMPLETED] = new QFinalState();
	//m_states[ST_PAUSED] = new QState();
	//m_states[ST_ERROR] = new QState();

	//// 设置初始状态
	//m_machine.setInitialState(m_states[ST_IDLE]);

	//// 添加状态到状态机
	//for (auto state : m_states) {
	//	m_machine.addState(state);
	//}

	//// 设置状态转换
	//setupTransitions();

	//// 启动状态机
	//m_machine.start();
}

bool Controller::initalize(short deviceNo)
{
	short ret = NMC_DevOpen(deviceNo, &devHandle);
	if (ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_DevOpen ", ret);
	}
	ret = NMC_EcatLoadConfigFromFile(devHandle, const_cast<char*> (myGml), 0);
	if (ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_EcatLoadConfigFromFile ", ret);
	}
	ret = NMC_EcatStart(devHandle);
	if (ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_EcatStart ", ret);
	}
	unsigned short ecatSts;
	while (0) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		NMC_EcatGetSts(devHandle, &ecatSts);
		if (ecatSts == 0x0) break;
	}
	axes.push_back(Axis(devHandle, 16, 245000,20));//0  上相机
	axes.push_back(Axis(devHandle, 17, 295000, 20));//1  下相机
	axes.push_back(Axis(devHandle,18,1450000,40));//2  搬运
	axes.push_back(Axis(devHandle,19,1450000,40));//3 搬运
	axes.push_back(Axis(devHandle,20,4270000,100));//4 抬盖升降
	axes.push_back(Axis(devHandle,21,4270000,100));//5 抬盖升降
	axes.push_back(Axis(devHandle,22,1080000,100));//6 抬盖夹爪1
	axes.push_back(Axis(devHandle, 23, 1080000, 100));//7 抬盖夹爪2
	axes.push_back(Axis(devHandle, 24, 500000, 100));//8 抬盖夹爪3
	axes.push_back(Axis(devHandle, 25, 500000, 100));//9 抬盖夹爪4
	axes.push_back(Axis(devHandle, 26, 5000000, 100));//10 mask升降1
	axes.push_back(Axis(devHandle, 27, 5000000, 100));//11 mask升降2
	axes.push_back(Axis(devHandle,28,2750000,100));//12 mask夹爪1
	axes.push_back(Axis(devHandle, 29, 2750000, 100));//13 mask夹爪2
	axes.push_back(Axis(devHandle, 30, 1780000, 100));//14	mask夹爪3
	axes.push_back(Axis(devHandle, 31, 1780000, 100));//15 mask夹爪4

	for(int i = 0; i < 16; i++)
	{
		axes[i].initialize();//return false;
	}
	axesSts.resize(16);
	std::thread t(&Controller::flashAxisStaus, this);
	t.detach();
	logInfo("controller init sucess!");
	return true;
}

void Controller::caseUp()
{
	logInfo("start caseUP!");
	if(!axesSts[2].negativeLimit || !axesSts[3].negativeLimit) // 判断搬运轴是否在负限位
	{
		logError("caseUp failed, axis 2 or 3 not at negative limit");
		return;
	}
	axes[4].side2side(0);
	while (!(axesSts[4].negativeLimit) || !(axesSts[5].negativeLimit))

	{
		if (stopRequested)	return;
		QThread::msleep(200);
	}
	axes[6].side2side(1);
	axes[7].side2side(1);
	axes[8].side2side(1);
	axes[9].side2side(1);

	while (!(axesSts[6].positiveLimit) || !(axesSts[7].positiveLimit) || !(axesSts[8] .positiveLimit) || !(axesSts[9].positiveLimit))
	{
		if (stopRequested) return;
		QThread::msleep(200);
	}
	axes[4].side2side(1);
	axes[5].side2side(1);
	while (!(axesSts[4].positiveLimit) || !(axesSts[5] .positiveLimit))
	{
		if (stopRequested)	return;
		QThread::msleep(200);
	}
}

void Controller::maskUp()
{
	if (!axesSts[4].positiveLimit || !axesSts[5].positiveLimit)
	{
		logError("start maskUp failed, axis 4 or 5 not at positive limit");
		return;
	}
	logInfo("The operation of step 'maskclawMove' has commenced execution.");
	axes[2].side2side(1);
	axes[3].side2side(1);
	while (!(axesSts[2].positiveLimit) || !(axesSts[3].positiveLimit))
	{
		if (stopRequested)	return;
		QThread::msleep(200);
	}	
	axes[10].side2side(0);
	axes[11].side2side(0);
	
	while (!(axesSts[10].negativeLimit) || !(axesSts[11].negativeLimit))
	{
		if (stopRequested)	return;
		QThread::msleep(200);
	}

	axes[12].side2side(1);
	axes[13].side2side(1);
	axes[14].side2side(1);
	axes[15].side2side(1);
	while (!(axesSts[12].positiveLimit) || !(axesSts[13].positiveLimit) || !(axesSts[14].positiveLimit) || !(axesSts[15].positiveLimit))
	{
		if (stopRequested)	return;
		QThread::msleep(200);
	}
}

void Controller::maskDetect()
{
	// 抬升未到位
	if (!axesSts[10].positiveLimit && !axesSts[11].positiveLimit) {
		logError("maskDetect failed, axis 10 or 11 not at positive limit");
		return;
	}
	logInfo("start maskDetect!");
	if(maskSize)
	{
		circleCount = 11;
		axes[2].move(-210000);
	}
	else
	{
		circleCount = 12;
		axes[2].move(-154033);
	}

	if(detectMode == MODE_DETECT_ClEAN_DETECT || detectMode == MODE_DETECT)
	{
		camera();
	}


}

void Controller::camera()

{
	for(int i = 0; i < circleCount; i++)
	{
		axes[2].move(-49850);
		while (axesSts[2].isMoving)
		{
			QThread::msleep(200);
		}
		//打开灯光相机拍摄
		axes[0].side2side(1);
		while (!axesSts[0].positiveLimit)
		{
			QThread::msleep(200);
		}
		axes[0].side2side(0);
		while (!axesSts[0].negativeLimit)
		{
			QThread::msleep(200);
		}
	}
	
}


void Controller::caseDown()

{
	logInfo("start caseDown!");
	if(!axesSts[2].negativeLimit && !axesSts[3].negativeLimit) // 判断搬运轴是否在负限位
	{
		logError("caseDown failed, axis 2 or 3 not at negative limit");
		return;
	}
	stopRequested = false;
	axes[4].side2side(0);
	axes[5].side2side(0);
	while (!(axesSts[4].negativeLimit) &&!(axesSts[5].negativeLimit))
	{
		if (stopRequested)	return;
		QThread::msleep(200);
	}
	//收夹爪
	axes[6].side2side(0);
	axes[7].side2side(0);
	axes[8].side2side(0);
	axes[9].side2side(0);
	while (!(axesSts[6].negativeLimit)|| !(axesSts[7] .negativeLimit)|| !(axesSts[8] .negativeLimit)|| !(axesSts[9].negativeLimit))
	{
		if (stopRequested) return;
		QThread::msleep(200);
	}
	axes[4].side2side(1);
	axes[5].side2side(1);
	while (!(axesSts[4] .positiveLimit) || !(axesSts[5].positiveLimit))
	{
		if (stopRequested)	return;
		QThread::msleep(200);
	}
}


void Controller::stop()
{
	stopRequested = true;
	for (int i = 0; i < axes.size(); i++)
	{
		axes[i].stop();
	}	
	logError("clicked stop button , all axes stoped \n");
}

void Controller::svOff()
{
	for (auto axis : axes)
	{
		axis.svOff();
	}
}


Controller::~Controller()
{
	stopTogether();
	stop();
	svOff();
	delete timer;
}

/// @brief 自动运行
void  Controller::autoRun()
{
	if(!areAllAxesInInitialState())
	{
		logError("autoRun failed, axes not in initial state");
		return;
	}
	caseUp();
	maskUp();
	maskDetect();
	caseDown();
}

/// @brief 刷新轴状态
void Controller::flashAxisStaus()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		for (int i = 0; i < 16; i++)
		{
			short axsiSts = 0;
			NMC_MtGetSts(axes[i].getHandle(), &axsiSts);
			axesSts[i].isMoving = (axsiSts & (1 << 0)) == 0 ? false : true; //取bit0,0静止,1运动bool IsRuning = (axsiSts & (1 << 0)) == 0 ? false : true; //取bit0,0静止,1运动
			axesSts[i].positiveLimit = (axsiSts & (1 << 6)) == 0 ? false : true;//取bit6,正限位
			axesSts[i].negativeLimit = (axsiSts & (1 << 7)) == 0 ? false : true;	//取bit7,负限位
			axesSts[i].hasError = (axsiSts & (1 << 10)) == 0 ? false : true;//取bit10,驱动器是否报警
		}
	}
}

/// @brief 判断所有轴是否在初始状态
/// @return 
bool Controller::areAllAxesInInitialState() {
    for (int i = 0; i < axesSts.size(); ++i) {
        if ((i == 4 || i == 5 || i == 10 || i == 11)) {

            // 轴 4, 5, 10, 11 应该在正限位
            if (!axesSts[i].positiveLimit) {
                return false;
            }
        } else {
            // 其他轴应该在负限位
            if (!axesSts[i].negativeLimit) {
                return false;
            }
        }
    }
    return true; // 所有轴都在期望的限位，返回 true
}

/// @brief 设置龙门组
/// @return 
bool Controller::together()
{
	short ret = NMC_SetGantryMaster(axes[2].getHandle(),1);
	if(ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_SetGantryMaster 0-1", ret);
		return false;
	}
	ret = NMC_SetGantrySlave(axes[3].getHandle(),1,2000);
	if(ret != RTN_CMD_SUCCESS)

	{
		logError("NMC_SetGantrySlave 2-3", ret);
		return false;
	}

	ret = NMC_SetGantryMaster(axes[4].getHandle(),2);
	if(ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_SetGantryMaster 4-5", ret);
		return false;
	}
	ret = NMC_SetGantrySlave(axes[5].getHandle(),2,2000);
	if(ret != RTN_CMD_SUCCESS)

	{
		logError("NMC_SetGantrySlave 4-5", ret);
		return false;
	}

	ret = NMC_SetGantryMaster(axes[10].getHandle(),3);
	if(ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_SetGantryMaster 10-11", ret);
		return false;
	}
	ret = NMC_SetGantrySlave(axes[11].getHandle(),3,2000);
	if(ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_SetGantrySlave 10-11", ret);
		return false;
	}
	return true;
}

/// @brief 停止龙门组
void Controller::stopTogether()
{
	NMC_DelGantryGroup(axes[2].getHandle(),1);
	NMC_DelGantryGroup(axes[4].getHandle(),2);
	NMC_DelGantryGroup(axes[10].getHandle(),3);
}