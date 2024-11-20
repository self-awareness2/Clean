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
	Controller( );

	bool initalize(short deviceNo);
	~Controller();
private:
	void printError(const std::string& functionName, short errorCode) {
		std::cerr << functionName << " failed with error code: " << errorCode << "\n";
	}

};

