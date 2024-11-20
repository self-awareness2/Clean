#include "Controller.h"

Controller::Controller( )
{
	myGml = const_cast<char*>("D:\\Test\\Clean\\singal_final.gml");
	initalize(0);
}

bool Controller::backHome()
{
	axes[0].home(17, 10);
	axes[1].home(18, 10);
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
	NMC_EcatGetSts(devHandle, &ecatSts);
	std::cout << ecatSts << std::endl;
	

	for (int  i = 0; i < 16; i++)
	{
		axes.push_back(Axis(devHandle,i+16));
	}
	for(int i = 0; i < 16; i++)
	{
		axes[i].initialize();//return false;
	}
	return true;
}

bool Controller::CaseUp()
{
	axes[4].side2side(1);
	axes[5].side2side(1);
	return false;
}

Controller::~Controller()
{
	//NMC_EcatStop(devHandle);
}
