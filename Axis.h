#pragma once
#include "mtn_lib20.h"
#include "mtn_lib20_err.h"
#include "mtn_lib20_ecat.h"
#include "mtn_lib20_ext.h"
#include "mtn_lib20_oem.h"
#include <iostream>

struct AxisStatus
{
    bool isBusy;
    bool isNeg;
};

class Axis {
private:
    HAND axisHandle;  // ����
    HAND devHandle;//���������
    short axisID;  //��id
    bool isInitialized;
    double maxV;
public:
    long distance;

    /// <summary>
    /// ��ʼ��
    /// </summary>
    /// <param name="devHandle">�豸���</param>
    /// <param name="id">��id</param>
    /// <param name="distance">�Ḻ��λ������λ����</param>
    Axis(HAND devHandle,short id,long distance,double v) :devHandle(devHandle), axisHandle(id+241), axisID(id), isInitialized(false),distance(distance), maxV(v){}
    HAND getHandle() { return axisHandle; }
    // ��ʼ����
    bool initialize( );

    /// <summary>
    /// ����
    /// </summary>
    /// <param name="homeMethod">��ԭ�㷽ʽ</param>
    /// <param name="velSwitch">�ٶ�</param>
    /// <returns></returns>
    bool home(int homeMethod,double velSwitch);

    /// <summary>
    /// ������λ������λ,�ɸ���λ������λ,1�������壬0��������
    /// </summary>
    /// <returns></returns>
    bool side2side(bool direction);

    // ��λ�˶�������λ�ã�
    bool moveTo(long targetPosition, double velocity, double acceleration, double deceleration);

    // ֹͣ�˶�
    void stop();

    void svOff();

    // ������
    bool hasError();

    // ���
    void clear();

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