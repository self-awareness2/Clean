#include "Axis.h"

bool Axis::initialize(HAND devHandle, short axisNo)
{
	short ret = NMC_MtOpen(devHandle, axisID, &axisHandle);
	if (ret == RTN_CMD_SUCCESS)
	{
		isInitialized = true;
		std::cout << "Axis" << axisID << "initialized successfully. \n";
		return true;
	}
	else {
		printError("NMC_MTOpen", ret);
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

bool Axis::home(double switchVelocity, double zeroVelocity, double acceleration)
{
	if (!isInitialized) return logError("Axis not initialized!");
	short ret = NMC_EcatStartHome(axisHandle, 1, switchVelocity, zeroVelocity, acceleration, 0);
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
