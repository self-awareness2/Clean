// LTSController.h : LTSController DLL 的主头文件

#pragma once

/*************************************************
Copyright (C), 2005 OPT MACHINE VISION TECH CO.,LTD. All rights reserved.
Version: 1.0.1          
Date: 2019.09.01         
Description: the set of functions that exported for the controller to control light source, such as turn on/off the light source, 
             adjust the intensity.
History: 
Fei Wang 2014/10/17 1.0.0 build this moudle
*************************************************/

#ifndef __LTSCONTROLER_H__
#define __LTSCONTROLER_H__

#ifdef CREATDLL_EXPORTS
#define DLL_API __declspec(dllexport)  
#else
#define DLL_API __declspec(dllimport)  
#endif

#include "atlstr.h"

typedef struct LTSController_IntensityItem
{
	int channelIndex;
	int intensity;
}IntensityItem;

typedef struct LTSController_ServerInf
{
	char IP[20];
	SOCKET server_socket;
	HANDLE server_hThread;
}ServerInf;

typedef struct LTSController_ReturnData
{
    int nType; //1 通道开，2 通道关，3 设置亮度
    int nChannel;
    int nValue;
}ReturnDataInfo;

typedef int(__stdcall*StreamSearchCB)(CString Controller_IP, long long nUserVal);

extern "C" 
{

	/*******************************************************************
	函数: LTSController_InitSerialPort
	描述: 初始化串口链接
	输入:  
	    comName - 串口名称，如：COM1...
		nBaudRate - 波特率
	输出: 
	    无
	返回值: 
	    0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API  LTSController_InitSerialPort(char *comName,int nBaudRate);

	/*******************************************************************
	函数: LTSController_ReleaseSerialPort
	描述: 释放串口链接
	输入:  
	    无
	输出: 
	    无
	返回值: 
	    0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API  LTSController_ReleaseSerialPort();

	/*******************************************************************
	函数: LTSController_ConnectNetwork
	描述: 初始化网口链接
	输入:
		IP_Array - IP地址数组，如：192.168.0.185
		num - IP数组数量
		nPort - 端口号，如：8899
		cb – 回调函数，当某个IP已连上后，将调用回调函数
		user – this指针

	输出:
		无
	返回值:
		0 - 成功
		-1 - 失败
	*******************************************************************/
	//long DLL_API LTSController_ConnectNetwork(CString *IP_Array, int num, int nPort, StreamSearchCB cb, long long user);

	/*******************************************************************
	函数: LTSController_InitNetwork
	描述: 初始化网口链接
	输入:  
	    ip - IP地址，如：192.168.0.185
		nPort - 端口号，如：8899
		cb – 回调函数，当连上后，将调用回调函数
		user – this指针
	输出: 
	    无
	返回值: 
	    0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API LTSController_InitNetwork(CString ip,int nPort, StreamSearchCB cb, long long user);

	/*******************************************************************
	函数: LTSController_ReleaseSerialPort
	描述: 释放网口链接
	输入:  
	    无
	输出: 
	    无
	返回值: 
	    0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API LTSController_ReleaseNetwork();

		/*******************************************************************
	函数: LTSController_ReleaseSerialPort
	描述: 释放网口链接
	输入:  
	    无
	输出: 
	    无
	返回值: 
	    0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API LTSController_ReleaseAllNetwork();

	/*******************************************************************
	函数: LTSController_SearchIP
	描述: 搜索局域网内的IP
	输入:
		cb - 回调函数，接收IP地址
		User - this指针

	输出:
		无
	返回值:
		0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API LTSController_SearchIP(StreamSearchCB cb, long long user);

	/*******************************************************************
	函数: LTSController_TurnOnChannelLength
	描述: 打开单通道
	输入: 
		channelIdx - 通道
		intensity - 当前通道亮度（0-999）
	输出: 
	    无
	返回值: 
		发送指令
	*******************************************************************/
	DLL_API char*  LTSController_TurnOnChannelLength(int channelIdx,int intensity);

	
	/*******************************************************************
	函数: LTSController_TurnOnChannelLength
	描述: 打开所有控制器单通道
	输入: 
		channelIdx - 通道
		intensity - 当前通道亮度（0-999）
	输出: 
	    无
	返回值: 
		发送指令
	*******************************************************************/
	DLL_API char*  LTSController_TurnOnAllChannelLength(int channelIdx,int intensity);

	/*******************************************************************
	函数: LTSController_TurnOffChannelLength
	描述: 关闭单通道
	输入: 
		channelIdx - 通道
		intensity - 当前通道亮度（0-999）
	输出: 
	    无
	返回值: 
		发送指令
	*******************************************************************/
	DLL_API char*  LTSController_TurnOffChannelLength(int channelIdx,int intensity);

	/*******************************************************************
	函数: LTSController_TurnOffChannelLength
	描述: 关闭所有控制器单通道
	输入: 
		channelIdx - 通道
		intensity - 当前通道亮度（0-999）
	输出: 
	    无
	返回值: 
		发送指令
	*******************************************************************/
	DLL_API char*  LTSController_TurnOffAllChannelLength(int channelIdx,int intensity);

	/*******************************************************************
	函数: LTSController_ReadIntensityLength
	描述: 读取单通道电源值
	输入:	
		channelIdx - 通道
	输出: 
	    无
	返回值: 
		电源值
		NULL - 失败
	*******************************************************************/
	long DLL_API  LTSController_ReadIntensityLength(int channelIdx);

	/*******************************************************************
	函数: LTSController_SetIntensityLength
	描述: 设置单通道电源值
	输入:	
		channelIdx - 通道
		intensity - 电源值
	输出: 
	    无
	返回值: 
		发送指令
	*******************************************************************/
	DLL_API char*  LTSController_SetIntensityLength(int channelIdx, int intensity);

	/*******************************************************************
	函数: LTSController_SetALLIntensityLength
	描述: 设置单通道电源值
	输入:
		channelIdx - 通道
		intensity - 电源值
	输出:
		无
	返回值:
		发送指令
	*******************************************************************/
	DLL_API char*  LTSController_SetALLIntensityLength(int channelIdx, int intensity);

	/*******************************************************************
	函数: LTSController_SetInitial
	描述: 设置单通道电源值
	输入:	
		c - 首指令之母，默认#， 可以设置$、&等等
	输出: 
	    无
	返回值: 
		发送指令
	*******************************************************************/
	void DLL_API LTSController_SetInitial(char c);

	/*******************************************************************
	函数: LTSController_SetIntensity
	描述: 设置多通道亮度
	输入:
		intensityArray - 通道信息（包含：通道和亮度）
		length - 设置通道总数
	输出:
		无
	返回值:
		0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API  LTSController_SetIntensity(IntensityItem* intensityArray, int length);

	/*******************************************************************
	函数: LTSController_SetMultiIntensity
	描述: 设置多通道亮度
	输入:
		intensityArray - 通道信息（包含：通道和亮度）
		length - 设置通道总数
	输出:
		无
	返回值:
		0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API  LTSController_SetMultiIntensity(IntensityItem* intensityArray, int length);

	/*******************************************************************
	函数: LTSController_SetMultiIntensityAll
	描述: 设置全部连接的控制器多通道亮度
	输入:
		intensityArray - 通道信息（包含：通道和亮度）
		length - 设置通道总数
	输出:
		无
	返回值:
		0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API LTSController_SetMultiIntensityAll(IntensityItem* intensityArray, int length);

	
	/*******************************************************************
	函数: LTSController_WriteCommand
	描述: 设置指令发送
	输入:
		command - 指令
		ReturnData - 返回
	输出:
		无
	返回值:
		0 - 成功
		-1 - 失败
	*******************************************************************/
	long DLL_API LTSController_WriteCommand(char* command, LTSController_ReturnData* ReturnData);

	/*******************************************************************
	函数: LTSController_WriteCommand
	描述: 读取报警
	输入:
		nAlarmType - 设置通道总数
	输出:
		无
	返回值:
		发送指令
	*******************************************************************/
	DLL_API char* LTSController_ReadAlarm(int nAlarmType);

			/*******************************************************************
	函数: LTSController_WriteCommand
	描述: 重启设备
	输入:
		无
	输出:
		无
	返回值:
		0 - 成功
		-1 - 失败
	*******************************************************************/
	 long DLL_API LTSController_RebootDevice();
}; 

#endif