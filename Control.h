#pragma once
#include <vector>
#include "Axis.h"
class Controller
{
private:
	HAND devHandle;
	std::vector<Axis> axes;

	char* myGml;
public:
	Controller(short numAxes, short numIo);

	bool initalize(short deviceNo);

private:
	void printError(const std::string& functionName, short errorCode) {
		std::cerr << functionName << " failed with error code: " << errorCode << "\n";
	}



};

