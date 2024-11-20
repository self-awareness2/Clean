#pragma once
#include "mtn_lib20.h"
#include "mtn_lib20_err.h"
#include "mtn_lib20_ecat.h"
#include "mtn_lib20_ext.h"
#include "mtn_lib20_oem.h"
#include <iostream>
class Axis {
private:
    HAND axisHandle;  // 轴句柄
    short axisID;  //轴id

    bool isInitialized;



   

public:
    Axis(short id) : axisHandle(0), axisID(id), isInitialized(false) {}

    // 初始化轴
    bool initialize(HAND devHandle, short axisNo);

    // 关闭轴
    void close();

    bool home(double switchVelocity, double zeroVelocity, double acceleration);

    // 点位运动（绝对位置）
    bool moveTo(long targetPosition, double velocity, double acceleration, double deceleration);

    // 停止运动
    void stop();

    // 检查错误
    bool hasError();

    // 清除错误
    void clearError();

    // 析构函数
    ~Axis();


private:
    bool handleResult(short result, const std::string& functionName) {
        if (result == RTN_CMD_SUCCESS) return true;
        printError(functionName, result);
        return false;
    }
    // 内部函数：打印错误
    void printError(const std::string& functionName, short errorCode) {
        std::cerr << functionName << " failed with error code: " << errorCode << "\n";
    }

    bool logError(const std::string& message)
    {
        std::cerr << "Error: " << message << std::endl;
        return true;
    }


};