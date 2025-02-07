#include "Controller.h"

Controller::Controller( QObject * parent ):QObject(parent)
{
	if (!initalize(0)) {
		logError("Controller initialization failed");
	}
}

void  Controller::checkStatus()
{

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
}
void Controller::setupStateMachine() {
	// 创建状态
	m_states[ST_IDLE] = new QState();
	m_states[ST_STEP1_LIFT_DOWN] = new QState();
	m_states[ST_STEP1_GRIP_OPEN] = new QState();
	m_states[ST_STEP1_LIFT_UP] = new QState();
	m_states[ST_STEP2_MASK_MOVE] = new QState();
	m_states[ST_STEP2_MASK_DOWN] = new QState();
	m_states[ST_STEP2_MASK_GRIP] = new QState();
	m_states[ST_STEP2_MASK_UP] = new QState();
	m_states[ST_STEP3_SCAN] = new QState();
	m_states[ST_STEP4_MASK_DOWN] = new QState();
	m_states[ST_STEP4_MASK_GRIP] = new QState();
	m_states[ST_STEP4_MASK_UP] = new QState();
	m_states[ST_STEP5_LIFT_DOWN] = new QState();
	m_states[ST_STEP5_GRIP_CLOSE] = new QState();
	m_states[ST_STEP5_LIFT_UP] = new QState();
	m_states[ST_COMPLETED] = new QFinalState();
	m_states[ST_PAUSED] = new QState();
	m_states[ST_ERROR] = new QState();

	// 设置初始状态
	m_machine.setInitialState(m_states[ST_IDLE]);

	// 添加状态到状态机
	for (auto state : m_states) {
		m_machine.addState(state);
	}

	// 设置状态转换
	setupTransitions();

	// 启动状态机
	m_machine.start();
}

bool Controller::initalize(short deviceNo)
{
	short ret = NMC_DevOpen(deviceNo, &devHandle);
	if (ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_DevOpen", ret);
	}
	ret = NMC_EcatLoadConfigFromFile(devHandle, const_cast<char*> (myGml), 0);
	if (ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_EcatLoadConfigFromFile", ret);
	}
	ret = NMC_EcatStart(devHandle);
	if (ret != RTN_CMD_SUCCESS)
	{
		logError("NMC_EcatStart", ret);
	}
	unsigned short ecatSts;
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		NMC_EcatGetSts(devHandle, &ecatSts);
		if (ecatSts == 0x0) break;
	}
	axes.push_back(Axis(devHandle,16,245000,20));//0  上相机
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
	logInfo("clicked caseUp button");
	axes[4].side2side(0);
	axes[5].side2side(0);
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


void Controller::caseDown()
{
	stopRequested = false;
	axes[4].side2side(0);
	axes[5].side2side(0);
	while (!(axesSts[4].negativeLimit)|| !(axesSts[5].negativeLimit))
	{
		if (stopRequested)	return;
		QThread::msleep(200);
	}
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
	stop();
	svOff();
	delete timer;
}

void  Controller::autoRun()
{
	caseUp();
	maskUp();
}
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
