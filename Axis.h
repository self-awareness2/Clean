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
    HAND devHandle;//���������
    short axisID;  //��id
    bool isInitialized;
public:
    Axis(HAND devHandle,short id) :devHandle(devHandle), axisHandle(id+241), axisID(id), isInitialized(false) {}

    // ��ʼ����
    bool initialize( );

    // �ر���
    void close();

    /// <summary>
    /// ����
    /// </summary>
    /// <param name="homeMethod">��ԭ�㷽ʽ</param>
    /// <param name="velSwitch">�ٶ�</param>
    /// <param name="zeroVelocity"></param>
    /// <returns></returns>
    bool home(int homeMethod,double velSwitch);
    

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