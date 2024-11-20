#pragma once
#include "mtn_lib20.h"
#include "mtn_lib20_err.h"
#include "mtn_lib20_ecat.h"
#include "mtn_lib20_ext.h"
#include "mtn_lib20_oem.h"
#include <iostream>
class Axis {
private:
    HAND axisHandle;  // ����
    short axisID;  //��id

    bool isInitialized;



   

public:
    Axis(short id) : axisHandle(0), axisID(id), isInitialized(false) {}

    // ��ʼ����
    bool initialize(HAND devHandle, short axisNo);

    // �ر���
    void close();

    bool home(double switchVelocity, double zeroVelocity, double acceleration);

    // ��λ�˶�������λ�ã�
    bool moveTo(long targetPosition, double velocity, double acceleration, double deceleration);

    // ֹͣ�˶�
    void stop();

    // ������
    bool hasError();

    // �������
    void clearError();

    // ��������
    ~Axis();


private:
    bool handleResult(short result, const std::string& functionName) {
        if (result == RTN_CMD_SUCCESS) return true;
        printError(functionName, result);
        return false;
    }
    // �ڲ���������ӡ����
    void printError(const std::string& functionName, short errorCode) {
        std::cerr << functionName << " failed with error code: " << errorCode << "\n";
    }

    bool logError(const std::string& message)
    {
        std::cerr << "Error: " << message << std::endl;
        return true;
    }


};