#include "Axis.h"

bool Axis::initialize()
{
	short ret = NMC_MtOpen(devHandle, axisID, &axisHandle);
	if (ret == RTN_CMD_SUCCESS)
	{
		isInitialized = true;
		std::cout << "Axis" << axisID << "initialized successfully. \n";
	}
	else {
		printError("NMC_MTOpen", ret);
		return false;
	}
	ret = NMC_MtZeroPos(axisHandle);
	if (ret == RTN_CMD_SUCCESS) {

	}
	else {
		printError("NMC_MtZeroPos", ret);
		return false;
	}
	ret = NMC_MtClrError(axisHandle);
	if (ret == RTN_CMD_SUCCESS) {

	}
	else {
		printError("NMC_MtClrError", ret);
		return false;
	}
	ret = NMC_MtSetStepMode(axisHandle, 0, 1);
	if (ret == RTN_CMD_SUCCESS) {

	}
	else {
		printError("NMC_MtSetStepMode", ret);
		return false;
	}
	ret = NMC_MtSetSvOn(axisHandle);
	if (ret == RTN_CMD_SUCCESS)
	{
		std::cout << "Axis " << axisID << "SvOn successfully. \n";
		return true;
	}
	else
	{
		printError("NMC_MtSetSvOn", ret);
		return false;
	}
}

void Axis::close()
{
	if (isInitialized) {
		NMC_MtClose(&axisHandle);
		isInitialized = false;
		std::cout << "Axis" << axisID << "closed. \n";
	}
}

bool Axis::home(int homeMethod,double velSwitch)
{
	if (!isInitialized) return logError("Axis not initialized!");
	short ret = NMC_EcatStartHome(axisHandle, homeMethod, velSwitch, 1, 0.1, 0);
	return handleResult(ret, "NMC_EcatStartHome");
}

bool Axis::moveTo(long targetPosition, double velocity, double acceleration, double deceleration)
{
	if(!isInitialized) return logError("Axis not initialized!");
	short ret = NMC_MtMovePtpAbs(axisHandle, acceleration, deceleration, 0, 0, velocity, 0,targetPosition);
	return handleResult(ret, "NMC_MtMovePtpAbs");
}



void Axis::stop()
{
	if (isInitialized) {
		NMC_MtStop(axisHandle);
		std::cout << "Axis " << axisID << " stopped.\n";
	}
}

bool Axis::hasError()
{
	return false;
}

void Axis::clearError()
{
}


Axis::~Axis()
{
}