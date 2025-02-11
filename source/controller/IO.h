#pragma once
#include "mtn_lib20.h"
#include "mtn_lib20_err.h"
#include <iostream>

class IOController {
private:
    HAND devHandle;

public:
    IOController(HAND handle);
    bool setOutputBit(short bitIndex, bool value);
    bool getInputBit(short bitIndex, bool& value);
    bool setOutputGroup(short groupID, long value);
    bool getInputGroup(short groupID, long& value);
    bool checkIOModuleStatus(unsigned long& status);
    bool enableIOModule(unsigned char moduleID);
};
