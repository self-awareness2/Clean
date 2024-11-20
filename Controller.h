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
	bool  backHome();
	bool initalize(short deviceNo);
	bool CaseUp();
	~Controller();
private:
	enum Status
	{
		BEGIN,RUN,ERROR,BACK
	};
	void printError(const std::string& functionName, short errorCode) {
		std::cerr << functionName << " failed with error code: " << errorCode << "\n";
	}

};

