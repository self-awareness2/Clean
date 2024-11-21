#include "Controller.h"

Controller::Controller( )
{
	myGml = const_cast<char*>("D:\\Test\\Clean\\singal_final.gml");
	initalize(0);
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

bool Controller::initalize(short deviceNo)
{
	short ret = NMC_DevOpen(deviceNo, &devHandle);
	if (ret != RTN_CMD_SUCCESS)
	{
		printError("NMC_DevOpen", ret);
	}
	ret = NMC_EcatLoadConfigFromFile(devHandle, myGml, 0);
	if (ret != RTN_CMD_SUCCESS)
	{
		printError("NMC_EcatLoadConfigFromFile", ret);
	}
	ret = NMC_EcatStart(devHandle);
	if (ret != RTN_CMD_SUCCESS)
	{
		printError("NMC_EcatStart", ret);
	}
	unsigned short ecatSts;
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		NMC_EcatGetSts(devHandle, &ecatSts);
		if (ecatSts == 0x0) break;
	}
	axes.push_back(Axis(devHandle,16,245000,20));
	axes.push_back(Axis(devHandle,17,295000,20));
	axes.push_back(Axis(devHandle,18,1450000,40));
	axes.push_back(Axis(devHandle,19,1450000,40));
	axes.push_back(Axis(devHandle,20,4270000,100));
	axes.push_back(Axis(devHandle,21,4270000,100));
	axes.push_back(Axis(devHandle,22,1080000,100));
	axes.push_back(Axis(devHandle,23,1080000,100));
	axes.push_back(Axis(devHandle,24,410000,100));
	axes.push_back(Axis(devHandle,25,430000,100));
	axes.push_back(Axis(devHandle,26,5000000,100));
	axes.push_back(Axis(devHandle,27,5000000,100));
	axes.push_back(Axis(devHandle,28,2750000,100));
	axes.push_back(Axis(devHandle,29,2750000,100));
	axes.push_back(Axis(devHandle,30,1780000,100));
	axes.push_back(Axis(devHandle,31,1780000,100));

	for(int i = 0; i < 16; i++)
	{
		axes[i].initialize();//return false;
	}

	for (int i = 0; i < 16; i++)
		axesSts.push_back(0);
	std::thread t(&Controller::flashStas, this);
	t.detach();
	return true;
}

bool Controller::caseUp()
{
	axes[4].side2side(0);
	axes[5].side2side(0);
	while (!(axesSts[4]>>7&1))
	{
	}
	while (!(axesSts[5] >> 7 & 1))
	{

	}
	axes[6].side2side(1);
	axes[7].side2side(1);
	axes[8].side2side(1);
	axes[9].side2side(1);

	while (!(axesSts[6] >> 6 & 1)) 
	{

	}
	while (!(axesSts[7] >> 6 & 1))
	{

	}while (!(axesSts[8] >> 6 & 1))
	{

	}while (!(axesSts[9] >> 6 & 1))
	{

	}
	axes[4].side2side(1);
	axes[5].side2side(1);
	return true;
}


bool Controller::caseDown()
{
	axes[4].side2side(0);
	axes[5].side2side(0);
	while (!(axesSts[4] >> 7 & 1))
	{
	}
	while (!(axesSts[5] >> 7 & 1))
	{

	}
	axes[6].side2side(0);
	axes[7].side2side(0);
	axes[8].side2side(0);
	axes[9].side2side(0);

	while (!(axesSts[6] >> 7 & 1))
	{

	}
	while (!(axesSts[7] >> 7 & 1))
	{

	}while (!(axesSts[8] >> 7 & 1))
	{

	}while (!(axesSts[9] >> 7 & 1))
	{

	}
	axes[4].side2side(1);
	axes[5].side2side(1);
	return true;
}


void Controller::stop()
{
		for (int i = 0; i < axes.size(); i++)
		{
			axes[i].stop();
		}
}

bool Controller::svOff()
{
	for (auto axis : axes)
	{
		axis.svOff();
	}
	return true;
}


Controller::~Controller()
{
	stop();
}

void Controller::flashStas()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		for (int i = 0 ; i < 16 ;i++)
		{
			NMC_MtGetSts(axes[i].getHandle(), &axesSts[i]);
		}
	}
}
