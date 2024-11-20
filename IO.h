#pragma once
#include "mtn_lib20.h"
#include "mtn_lib20_err.h"
#include <iostream>

class IOController {
private:
    HAND devHandle; // �豸���

public:
    // ���캯��
    IOController(HAND handle) : devHandle(handle) {}

    // ���õ���λ���
    bool setOutputBit(short bitIndex, bool value) {
        short ret = NMC_SetDOBit(devHandle, bitIndex, value ? 1 : 0);
        if (ret == RTN_CMD_SUCCESS) {
            std::cout << "Set output bit " << bitIndex << " to " << value << ".\n";
            return true;
        }
        else {
            std::cerr << "Failed to set output bit " << bitIndex << ", error: " << ret << ".\n";
            return false;
        }
    }

    // ��ȡ����λ����
    bool getInputBit(short bitIndex, bool& value) {
        short bitValue = 0;
        short ret = NMC_GetDIBit(devHandle, bitIndex, &bitValue);
        if (ret == RTN_CMD_SUCCESS) {
            value = (bitValue != 0);
            std::cout << "Input bit " << bitIndex << " value: " << value << ".\n";
            return true;
        }
        else {
            std::cerr << "Failed to get input bit " << bitIndex << ", error: " << ret << ".\n";
            return false;
        }
    }

    // �����������
    bool setOutputGroup(short groupID, long value) {
        short ret = NMC_SetDOGroup(devHandle, value, groupID);
        if (ret == RTN_CMD_SUCCESS) {
            std::cout << "Set output group " << groupID << " to " << value << ".\n";
            return true;
        }
        else {
            std::cerr << "Failed to set output group " << groupID << ", error: " << ret << ".\n";
            return false;
        }
    }

    // ��ȡ��������
    bool getInputGroup(short groupID, long& value) {
        short ret = NMC_GetDIGroup(devHandle, &value, groupID);
        if (ret == RTN_CMD_SUCCESS) {
            std::cout << "Input group " << groupID << " value: " << value << ".\n";
            return true;
        }
        else {
            std::cerr << "Failed to get input group " << groupID << ", error: " << ret << ".\n";
            return false;
        }
    }

    // �����չIOģ��״̬
    bool checkIOModuleStatus(unsigned long& status) {
        short ret = NMC_GetIOModuleSts(devHandle, &status);
        if (ret == RTN_CMD_SUCCESS) {
            std::cout << "IO module status: " << status << ".\n";
            return true;
        }
        else {
            std::cerr << "Failed to get IO module status, error: " << ret << ".\n";
            return false;
        }
    }

    // ������չIOģ��
    bool enableIOModule(unsigned char moduleID) {
        short ret = NMC_SetIOModuleEn(devHandle, moduleID);
        if (ret == RTN_CMD_SUCCESS) {
            std::cout << "Enabled IO module with ID: " << (int)moduleID << ".\n";
            return true;
        }
        else {
            std::cerr << "Failed to enable IO module ID: " << (int)moduleID << ", error: " << ret << ".\n";
            return false;
        }
    }
};
