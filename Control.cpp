#include "Control.h"

bool Controller::initalize(short deviceNo)
{
	short ret = NMC_DevOpen(deviceNo, &devHandle);
	myGml = const_cast<char*>("final.gml");
	if (ret != RTN_CMD_SUCCESS)
	{
		printError("NMC_DevOpen", ret);
	}
	for(int i = 0; i < 16; i++)
	{
		if (!axes[i].initialize(devHandle, i)) return false;
	}




	return true;

}
