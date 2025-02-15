﻿#include "Axis.h"

bool Axis::initialize()
{
	short ret = NMC_MtOpen(devHandle, axisID, &axisHandle);
	if (ret == RTN_CMD_SUCCESS)
	{
		isInitialized = true;
	}
	else {
		logError("NMC_MTOpen", ret);
		return false;
	}
	ret = NMC_MtZeroPos(axisHandle);
	if (ret == RTN_CMD_SUCCESS) {

	}
	else {
		logError("NMC_MtZeroPos", ret);
		return false;
	}
	ret = NMC_MtClrError(axisHandle);
	if (ret == RTN_CMD_SUCCESS) {

	}
	else {
		logError("NMC_MtClrError", ret);
		return false;
	}
	ret = NMC_MtSetStepMode(axisHandle, 0, 1);
	if (ret == RTN_CMD_SUCCESS) {

	}
	else {
		logError("NMC_MtSetStepMode", ret);
		return false;
	}
	ret = NMC_MtSetSvOn(axisHandle);
	if (ret == RTN_CMD_SUCCESS)
	{
		return true;
	}
	else
	{
		logError("NMC_MtSetSvOn", ret);
		return false;
	}
}

//void Axis::close()
//{
//	if (isInitialized) {
//		NMC_MtClose(&axisHandle);
//		isInitialized = false;
//		std::cout << "Axis" << axisID << "closed. \n";
//	}
//}

bool Axis::home(int homeMethod,double velSwitch)
{
	if (!isInitialized)
	{
	lg::Logger::instance().Error("Axis not initialized!");
		return 0;
	}
	short ret = NMC_EcatStartHome(axisHandle, homeMethod, velSwitch, 1, 0.1, 0);
	return handleResult(ret, "NMC_EcatStartHome");
}

bool Axis::side2side(bool direction)
{	
	moveTo(direction?distance:-distance, maxV, 0.1, 0.05);
	return false;
}
/// @brief  绝对运动
/// @param targetPosition 目标位置
/// @param velocity 速度
/// @param acceleration 加速度
/// @param deceleration 减速度
/// @return 
bool Axis::moveTo(long targetPosition, double velocity, double acceleration, double deceleration)
{
	short ret = NMC_MtMovePtpAbs(axisHandle, acceleration, deceleration, 0, 0, velocity, 0,targetPosition);
	return handleResult(ret, "NMC_MtMovePtpAbs");
}


/// @brief  相对运动
/// @param targetDistance 距离
/// @return 
bool Axis::move(long targetDistance)
{
	short ret = NMC_MtMovePtpRel(axisHandle, 0.1, 0.1, 0, 0, maxV, 0, targetDistance);
	return handleResult(ret, "NMC_MtMovePtpRel");
}





void Axis::stop()

{
		NMC_MtStop(axisHandle);
}

void Axis::svOff()
{
	NMC_MtSetSvOff(axisHandle);
}

bool Axis::hasError()
{
	return false;
}

void Axis::clear()
{
	NMC_MtClrError(axisHandle);
	NMC_MtZeroPos(axisHandle);
}


Axis::~Axis()
{
}
