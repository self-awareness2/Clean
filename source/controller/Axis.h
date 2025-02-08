﻿#pragma once
#include "mtn_lib20.h"
#include "mtn_lib20_err.h"
#include "mtn_lib20_ecat.h"
#include "mtn_lib20_ext.h"
#include "mtn_lib20_oem.h"
#include <iostream>
#include "../log/Logger.h"

struct AxisStatus {
    bool positiveLimit;  // 正限位
    bool negativeLimit;  // 负限位
    bool isMoving;       // 是否运动
    bool hasError;       // 是否报错
};

class Axis {
private:
    HAND axisHandle;  // 轴句柄
    HAND devHandle;//控制器句柄
    short axisID;  //轴id
    bool isInitialized;
    double maxV;
public:
    long distance;

    /// <summary>
    /// 初始化
    /// </summary>
    /// <param name="devHandle">设备句柄</param>
    /// <param name="id">轴id</param>
    /// <param name="distance">轴负限位到正限位距离</param>
    Axis(HAND devHandle,short id,long distance,double v) :devHandle(devHandle), axisHandle(id+241), axisID(id), isInitialized(false),distance(distance), maxV(v){}
    HAND getHandle() { return axisHandle; }
    // 初始化轴
    bool initialize( );

    /// <summary>
    /// 回零
    /// </summary>
    /// <param name="homeMethod">找原点方式</param>
    /// <param name="velSwitch">速度</param>
    /// <returns></returns>
    bool home(int homeMethod,double velSwitch);

    /// <summary>
    /// 由正限位到负限位,由负限位到正限位,1正向脉冲，0负向脉冲
    /// </summary>
    /// <returns></returns>
    bool side2side(bool direction);

    // 点位运动（绝对位置）
    bool moveTo(long targetPosition, double velocity, double acceleration, double deceleration);

    // 点位运动（相对位置）
    bool move(long targetDistance);

    // 停止运动
    void stop();


    void svOff();

    // 检查错误
    bool hasError();

    // 清除
    void clear();

    // 析构函数
    ~Axis();


private:
    bool handleResult(short result, const std::string& functionName) {
        if (result == RTN_CMD_SUCCESS) return true;
        logError(functionName, result);
        return false;
    }
    // 内部函数：打印错误
    void logError(const std::string& functionName, short errorCode) {
        std::string errmsg =functionName + "failed with error code " + std::to_string(errorCode);
        lg::Logger::instance().Error(errmsg.c_str());
    }
};