#pragma once
#include <vector>
#include <thread>
#include "Axis.h"
class Controller
{
private:
	HAND devHandle;
	std::vector<Axis> axes;
	std::vector<short> axesSts;
	enum Status
	{
		BEGIN, RUN, ERROR, BACK
	};
	char* myGml;
public:
	Controller( );
	bool  backHome();
	bool initalize(short deviceNo);
	bool caseUp();
	bool caseDown();
	void stop();
	bool svOff();
	~Controller();
private:
	void flashStas();
	void printError(const std::string& functionName, short errorCode) {
		std::cerr << functionName << " failed with error code: " << errorCode << "\n";
	}

};

