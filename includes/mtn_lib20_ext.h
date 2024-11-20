///******************************************************************
//
// Moudle Name  :   mtn_lib20_ext.h
// Abstract     :   GaoChuan Motion 2.0 external user header 
// Note :			1.结构体定义中所有的‘reservedxxx’的成员都是保留参数,为保持兼容性,请设置为0
//					2.无特别说明,所有API返回RTN_CMD_SUCCESS（即0值）表示执行成功,其他则表示错误代码
//					3.所有的API参数中,无特别说明,axisHandle表示操作轴的句柄,devHandle表示目标控制器的句柄,crdHandle表示目标坐标系组句柄
//                  4.mtn_lib20中所有的结构体都是以四字节对齐方式编译，为了避免结构体对齐引起的问题，请将编译环境设置为四字节对齐
// Modification History :
///******************************************************************
#ifndef _H_MTN_LIB20_EXT_H_
#define _H_MTN_LIB20_EXT_H_
#include "mtn_lib20.h"

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------------------------------------
//
//           指令分组索引
//
//------------------------------------------------------------------------------------------------------------
//	1.设备高级配置等
//	2.单轴配置读取
//	3.单轴高级指令
//	4.缓冲区高级指令
//	5.硬件捕获及不常用指令
//	6.平台相关指令
//	7.数据采集模块(高级指令)
//	8.激光
//	9.龙门
//  10.通讯扩展等其他
//  11.手轮
//  12.PT
//  13.线性距离位置比较
//  14.二维位置点比较
//  15.多维位置比较输出
//  16.坐标系输出转换
//  17.结构体初始化函数及常见习惯指令
//  18.闭环
//  19.高级BufIo输出配置及控制
//  20.模拟量控制
//  21.scara
//  22.坐标系干涉保护指令
//  23.不常用指令
//  24.自动状态返回
//  25 : 点位自动收发
//  26 : 高速一维位置比较
//  27 ：带count及clock
//  28.PVT
///////////////////////////////////////////////////////////////////指令
//------------------------------------------------------------------------------------------------------------
//
//	1.设备高级配置等
//
//------------------------------------------------------------------------------------------------------------

// 设置通讯参数
// devHandle : 设备句柄
// waitTimeInUs：等待时间,微秒
// retryTimes： 通讯重试次数
MTN_API short __stdcall NMC_SetCommPara( HAND devHandle, unsigned long waitTimeInUs, unsigned long retryTimes );

// 板卡打开（根据名称）
// idStr: 板卡ID字符串, 可通过指令写入。pDevHandle: 返回设备操作句柄
// 注：ID号用户可写入,掉电不丢失,可用于区分板卡。出厂板卡号ID号为0
MTN_API short __stdcall NMC_DevOpenByID   ( char *idStr, PHAND pDevHandle );

// 板卡打开（根据IP地址）
// pIPv4Array: 板卡IP地址,四个字节,例如：unsinged char ipv4[4] = {192,168,1,110};
// pDevHandle: 返回设备操作句柄
MTN_API short __stdcall NMC_DevOpenByIP   (unsigned char *pIPv4Array, PHAND pDevHandle );

// 修改板卡ID号
// pIdStr: 要写入的板卡ID字符串,最长16字节,以\0结尾
// 注：修改ID号完成后,板卡要掉电重启,新的ID才有效。
MTN_API short __stdcall NMC_DevWriteID   ( HAND devHandle, char *pIdStr );

// 读取板卡ID号
// pIdStr: 存储字符串的数组,数组长度大于16字节
MTN_API short __stdcall NMC_DevReadID(HAND devHandle, char *pIdStr );

// 读取库的版本
// pVersion：接收版本信息
// example(c):
//          char dllVersion[128];
//          NMC_GetDllVersion(dllVersion);
MTN_API short  __stdcall NMC_GetDllVersion(char *pVersion);

// 当前运动控制器固件的版本等信息
typedef struct
{
	char strVer[16];
	char strOemVer[16];
	char strBuild[32];
}TMtLibVersion;
// 读取当前运动控制器固件的版本等信息
// devHandle : 设备句柄
// pVersion：版本信息
MTN_API short __stdcall NMC_GetMtLibVersion ( HAND devHandle, TMtLibVersion *pVersion );

typedef struct
{
	char strVer[16];           // 控制器版本号
	char strOemVer[16];        // OEM版本号(定制控制器才有),默认为0
	short time[6];          // 时间,年月日,时分秒
	short axisNum;          // 支持的轴数
	short encNum;           // 支持的编码器数
	short diNum;            // 数字输入数量
	short doNum;            // 数字输出数量
	short daNum;            // 模拟量通道
	short adNum;            // 模拟量输入通道
	short shioNum;          // 同步高速IO通道
    short reserved;         // 保留
	char ipv4[4];           // IP地址
	char idStr[16];         // 板卡名称,多卡时可用名称打开参考NMC_DevOpenByID
	unsigned long uid[4];   // 唯一序列号
}TCardInfo;
// 读取当前运动控制器信息
MTN_API short __stdcall NMC_GetCardInfo ( HAND devHandle, TCardInfo *pInfo );

typedef struct
{
	char strVer[16];           // 控制器版本号
	char strOemVer[16];        // OEM版本号(定制控制器才有),默认为0
	short time[6];          // 时间,年月日,时分秒
	short axisNum;          // 支持的轴数
	short encNum;           // 支持的编码器数
	short diNum;            // 数字输入数量
	short doNum;            // 数字输出数量
	short daNum;            // 模拟量通道
	short adNum;            // 模拟量输入通道
	short shioNum;          // 同步高速IO通道
	short reserved;         // 保留
	unsigned char ipv4[4];  // IP地址
	char idStr[16];         // 板卡名称,多卡时可用名称打开参考NMC_DevOpenByID
	unsigned long uid[4];   // 唯一序列号
	char macAddr[6];		// 网口mac地址
	char resv[256];
}TCardInfoEx;

// 读取当前运动控制器信息
MTN_API short __stdcall NMC_GetCardInfoEx ( HAND devHandle, TCardInfoEx *pInfo );

// 启动指令调试
// enable:0关闭调试信息,默认关闭,1:打开通讯的debug输出；2:打印到文件；3：打印输出到GCS
// debugOutputFile:调试输出文件，仅在enable=2时需要
MTN_API short  __stdcall NMC_SetCmdDebug( short enable,char *debugOutputFile);

// 获取错误代码信息
// errCode:错误代码
// errDesc:返回的错误代码描述
MTN_API short  __stdcall NMC_GetErrDesc( short errCode,char *errDesc);

// 加载配置文件
MTN_API short __stdcall NMC_LoadConfigFromFile(HAND devHandle, char *pFilePath);

// 保存为配置文件
MTN_API short __stdcall NMC_SaveConfigToFile(HAND devHandle, char *pFilePath);

// 保存基本的配置信息,将这些信息保存到系统参数区,控制器重启或者NMC_DevReset后,系统将使用这些参数
// 保存的参数包括报警、限位、脉冲方式、编码器方式、安全参数、滤波参数
// enable:1表示保存当前配置,并使能自动加载参数功能,0：表示关闭自动加载参数功能
MTN_API short __stdcall NMC_SaveMotionConfig(HAND devHandle,short enable);

// 获取平台版本号
MTN_API short  __stdcall NMC_GetVersion( HAND devHandle, unsigned char *verArray );

// 获取控制器功能信息 example : char flags[1024];NMC_DevGetMcInfoFlag(g_hDev,flags);
MTN_API short __stdcall NMC_DevGetMcInfoFlag(HAND devHandle,char *flags);

// 控制器状态
#define BIT_DEV_TERMINALBOARD_ONLINE			(0x00000001)		// bit 0  , 端子板通讯状态（PCIe卡），1：正常:,0：错误    
#define BIT_DEV_TERMINALBOARD_POWER				(0x00000002)		// bit 1  , 端子板供电是否正常（PCIe卡），1：正常:,0：错误    

// 获取控制器状态，按位表示
MTN_API short  __stdcall NMC_DevGetSts(HAND devHandle,  long *sts);

//------------------------------------------------------------------------------------------------------------
//
//	2.单轴配置读写
//
//------------------------------------------------------------------------------------------------------------
// 获取轴规划模式
// pMode：返回轴运动模式
MTN_API short __stdcall NMC_MtGetPrfMode(HAND axisHandle,short *pMode);

// 获取Ptp参数
// pAxPara：参数
MTN_API short __stdcall NMC_MtGetPtpPara( HAND axisHandle, TPtpPara *pAxPara );

// 获取Jog参数
// pAxPara：参数
MTN_API short __stdcall NMC_MtGetJogPara   ( HAND axisHandle, TJogPara *pAxPara );

// 获取目标运动速度
// pVel: 目标速度（最大速度）,单位是 脉冲/ms
MTN_API short __stdcall NMC_MtGetVel( HAND axisHandle, double *pVel );

// 获取目标运动位置,只针对PTP
// pPos: 目标位置,单位是 脉冲
MTN_API short __stdcall NMC_MtGetPtpTgtPos( HAND axisHandle, long *pPos );

// 读编码器通道位置
// devHandle : 控制器句柄
// encId: 编码器ID,取值范围[0,n]
// pPos:返回编码器数值
MTN_API short  __stdcall NMC_GetEncPos( HAND devHandle, short encId, long *pPos );

// 写编码器通道位置
// devHandle : 控制器句柄
// encId: 编码器ID,对于轴编码器通道,取值范围[0,n]
//				  对于扩展编码器通道,256表示第一个扩展编码器通道,257表示第二个,以此类推
// encPos:编码器数值
MTN_API short  __stdcall NMC_SetEncPos( HAND devHandle, short encId, long encPos );

// 设置允许的位置误差,当位置误差超过设定值时,电机停止运动,提示位置误差超限
// posErr为0表示不检查
MTN_API short  __stdcall NMC_MtSetPosErrLmt( HAND axisHandle, long posErr );

// 读取允许的位置误差设定值
MTN_API short  __stdcall NMC_MtGetPosErrLmt( HAND axisHandle, long *pPosErr );

// 读取编码器模式
// encId: 编码器ID,对于轴编码器通道,取值范围[0,n]
//				  对于扩展编码器通道,256表示第一个扩展编码器通道,257表示第二个,以此类推
// encMode:返回编码器模式,参考宏定义
MTN_API short  __stdcall NMC_GetEncMode (HAND devHandle, short encId,  short *encMode );

// 读取限位开关输入是否停止运动
// posEn：正向限位触发允许设置,1为允许,0为禁止
// negEn: 负向限位触发允许设置
MTN_API short  __stdcall NMC_MtGetLmtOnOff    ( HAND axisHandle, short *pPosSwt, short *pNegSwt );

// 读取限位开关触发电平
// posSwt：正向限位触发电平设置,1为高电平触发,0为低电平触发
// negSwt: 负向限位触发电平设置
MTN_API short  __stdcall NMC_MtGetLmtSns      ( HAND axisHandle, short *pPosSwt, short *pNegSwt );

// 读取伺服报警开关是否停止运动
// swt：伺服报警开关输入允许设置,1为允许,0为禁止。（默认为高电平触发）
MTN_API short  __stdcall NMC_MtGetAlarmOnOff  ( HAND axisHandle, short *pSwt );

// 读取伺服报警开关电平
// swt：伺服报警触发电平设置,1为高电平触发,0为低电平触发
MTN_API short  __stdcall NMC_MtGetAlarmSns    ( HAND axisHandle, short *pSwt );

// 读取软件限位是否停止运动
// enable：软件限位触发允许设置,1为允许,0为禁止
MTN_API short  __stdcall NMC_MtGetSwLmtOnOff  ( HAND axisHandle, short *pSwt );

// 读取软件限位数值
// posLmt：正向软件限位设置值
// negLmt：负向软件限位设置值。单位为脉冲数
MTN_API short  __stdcall NMC_MtGetSwLmtValue  ( HAND axisHandle, long *pPosLmt,long *pNegLmt );

//  读取轴安全参数
MTN_API short  __stdcall NMC_MtGetSafePara( HAND axisHandle, TSafePara *pPara );

// 读取脉冲输出模式
// pInv, 1：取反,0：不取反
// pMode 0：脉冲方向 1：正负脉冲
MTN_API short  __stdcall NMC_MtGetStepMode ( HAND axisHandle, short *pInv, short *pMode );

// 读取轴速度滤波参数
MTN_API short __stdcall NMC_MtGetAxisVelFilter(HAND axisHandle,short *pFilterCoef);

// 读取回零参数
// pHomePara: 回零参数结构,参考结构定义
MTN_API short __stdcall NMC_MtGetHomePara( HAND axisHandle, THomeSetting *pHomePara );

//------------------------------------------------------------------------------------------------------------
//
//	3.单轴高级指令
//
//------------------------------------------------------------------------------------------------------------

// 读取机械坐标的位置
// pPos : 返回位置,单位是 脉冲
MTN_API short __stdcall NMC_MtGetAxisPos   ( HAND axisHandle, long *pPos );

// 读发送到执行器的位置
// pPos : 返回位置,单位是 脉冲
MTN_API short __stdcall NMC_MtGetCmdPos   ( HAND axisHandle, long *pPos );

// 设定机械位置, 轴静止时执行,如果后面是update指令,需要延时一个周期
// axisPos: 设定机械位置值
// 注：只能在轴静止时使用
MTN_API short  __stdcall NMC_MtSetAxisPos( HAND axisHandle, long axisPos);

// 设定编码器位置, 轴静止时执行,如果后面是update指令,需要延时一个周期
// encPos: 设定编码器位置值
// 注：只能在轴静止时使用
MTN_API short  __stdcall NMC_MtSetEncPos( HAND axisHandle, long encPos);

// 设置单轴规划高级参数
// axisHandle : 轴句柄
// mapAxisNo：轴号,取值范围[0,n]
// port：端口号,取值范围[0,1],默认为0
// startPos：偏置,默认为0
// pCrdHandle：坐标系组句柄
MTN_API short __stdcall NMC_MtPrfConfig(HAND axisHandle,short mapAxisNo,short port,long startPos);

// 读取单轴规划高级参数
MTN_API short __stdcall NMC_MtGetPrfConfig(HAND axisHandle,short *mapAxisNo,short *port,long *startPos);

// 设置单轴比例系数
// axisHandle : 轴句柄
// inCoe：单轴比例系数,取值范围(0,1]
MTN_API short __stdcall NMC_MtSetPrfCoe(HAND axisHandle,double inCoe);

// 读取单轴比例系数
// axisHandle : 轴句柄
// pInCoe：单轴比例系数,取值范围(0,1]
MTN_API short __stdcall NMC_MtGetPrfCoe(HAND axisHandle,double *pInCoe);

// 设置轴通道编码器的系数,默认为1
// axisHandle : 轴句柄
// encCoe：单轴通道编码器比例系数,取值范围(0,1]
MTN_API short __stdcall NMC_MtSetEncCoe(HAND axisHandle,double encCoe);

// 读取轴通道编码器的系数
// axisHandle : 轴句柄
// pEncCoe：比例系数,取值范围(0,1]
MTN_API short __stdcall NMC_MtGetEncCoe(HAND axisHandle,double *pEncCoe);

// 设置轴的到位误差参数
// axisHandle : 轴句柄
// arrivalBand: 到位误差,单位Pulse 取值大于0
// stableTime: 到位保持时间,单位 ms 取值大于0
MTN_API short __stdcall NMC_MtSetAxisArrivalPara(HAND axisHandle,long arrivalBand,long stableTime);

// 获取轴的到位误差参数
// axisHandle : 轴句柄
// pArrivalBand:到位误差,单位Pulse 
// pStableTime：到位保持时间,单位 ms
MTN_API short __stdcall NMC_MtGetAxisArrivalPara(HAND axisHandle,long *pArrivalBand,long *pStableTime);

// 设置螺距误差补偿参数
// num：补偿的段数,取值范围[2,128]
// startPos：补偿起始位置，终止位置为 startPos + cmpLen
// cmpLen:补偿长度
// pCompPos:正向补偿值
// pCompNeg:负向补偿值
MTN_API short  __stdcall NMC_MtSetLeadScrewCompPara(HAND axisHandle,short num,
						long startPos,long cmpLen,short *pCompPos,short *pCompNeg);

// 使能或禁止螺距位置补偿
MTN_API short __stdcall NMC_MtEnableLeadScrew(HAND axisHandle, short enable);

// 设置反向间隙补偿
// compValue： 补偿量
// compDelta： 周期补偿量，比如补偿量为100，周期补偿量为10，则反向补偿会在10个规划周期完成100个脉冲的补偿
// compDir：	 补偿方向,0:负向补偿，往负向运动时叠加补偿量，1：正向补偿，往正向运动时叠加补偿量
MTN_API short  __stdcall NMC_MtSetBacklash(HAND axisHandle, long compValue,double compDelta,long compDir);

// 获取反向间隙补偿
MTN_API short  __stdcall NMC_MtGetBacklash(HAND axisHandle,long *pCompValue,double *pCompDelta,long *pCompDir);

// 设置单轴急停DI
// gpiIndex：通用输入序号,[0,]，设置为-1，则表示取消急停DI
// sense :触发电平,0：低电平,1：高电平
MTN_API short __stdcall NMC_MtSetEstopDI( HAND axisHandle, short gpiIndex,short sense);

// 读取单轴急停DI
// gpiIndex：通用输入序号,[0,]
// sense :触发电平,0：低电平,1：高电平
MTN_API short __stdcall NMC_MtGetEstopDI( HAND axisHandle, short *gpiIndex,short *sense);

// 设置单轴急停DI Mask,可以配置多个急停DI
// gpiMask：通用输出的位掩码
// senseMask :触发电平的位掩码，对应位,0：低电平,1：高电平
MTN_API short __stdcall NMC_MtSetEstopDIMask( HAND axisHandle, long gpiMask,long senseMask);

// 设置单轴急停DI Mask,可以配置多个急停DI
// gpiMask：通用输出的位掩码
// senseMask :触发电平的位掩码，对应位,0：低电平,1：高电平
MTN_API short __stdcall NMC_MtGetEstopDIMask( HAND axisHandle, long *pGpiMask,long *pSenseMask);

// 高级急停
#define ESTOP_DI_EX_CH_NUM				2   // 高级急停最大通道数量

typedef struct
{
	short axMask;			// 轴掩码
	short diType;			// DI类型，0-通用输入，1-负限位，2-正限位，3-原点，4-Z相
	short diIndex;			// 通道序号,[0,]
	short filter;			// 滤波系数,取值范围[0,255]
	long diSense;			// 触发电平,0：低电平,1：高电平
	long reserved[3];		// 保留
}TEstopExParam;

// 设置单轴急停DI,触发后会置起BIT_AXIS_ESTP标志位
// 注意:单轴高级急停触发后，规划位置与实际位置可能存在差值
// pParam:高级急停参数
// group:通道号，取值[0,ESTOP_DI_EX_CH_NUM-1]
MTN_API short __stdcall NMC_SetEstopDIEx( HAND devHandle, TEstopExParam *pParam,short group);

// 读取单轴急停DI
MTN_API short __stdcall NMC_GetEstopDIEx( HAND devHandle, TEstopExParam *pParam,short group);

// 缓冲区高级急停IO启动关闭
// onOff:1-启用高级急停IO，0-关闭高级急停IO
// group:通道号，取值[0,ESTOP_DI_EX_CH_NUM-1]
MTN_API short __stdcall NMC_CrdBufEstopDIExOnOff( HAND crdHandle, long segNo,short onOff,short group);

// 清除高级单轴急停DI
MTN_API short __stdcall NMC_ClrEstopDIEx( HAND devHandle,short group);

// 高级捕获通道数目
#define CAPT_EX_CH_NUM				6   // 

// 捕获源
#define CAPT_EX_SRC_GPI				0   // 通用输入
#define CAPT_EX_SRC_NEGLMT          1   // 负向限位
#define CAPT_EX_SRC_POSLMT          2   // 正向限位
#define CAPT_EX_SRC_HOME			3   // 原点
#define CAPT_EX_SRC_Z				4   // Z向信号
#define CAPT_EX_SRC_PRFPOS          5   // 规划位置（当规划位置达到设定值时触发）
#define CAPT_EX_SRC_ENCPOS          6   // 编码器位置

typedef struct
{
	short capPosIndex;	// 捕获的位置源序号,0~N：轴1~N+1。（默认0）注：捕获的编码器位置根据用户设置的编码器模式决定 
	
	short trigSrc;		// 触发源,见上面的定义。（默认：CAPT_EX_SRC_GPI）
	short trigIndex;	// 触发源序号。（默认0）
	short filter;		// 滤波时间常数,单位0.1毫秒,取值范围[0,255]
	long  trigValue;	// 触发值,对于触发源为IO,表示信号触发的有效电平；对于触发源为位置,则表示触发捕获的位置。（默认0）
}TAdvCaptureParam;

// 设置高级捕获参数,并启动捕获
// pParam:参数
// ch：高级捕获通道号,[0~3]
MTN_API short __stdcall NMC_MtSetAdvCaptParam( HAND devHandle, TAdvCaptureParam *pParam,short ch);

// 清除高级捕获状态,并取消该通道的捕获
// ch：高级捕获通道号,[0~3]
MTN_API short __stdcall NMC_MtClrAdvCaptSts( HAND devHandle,short ch);

// 读取高级捕获状态
// captSts:捕获状态,bit0表示设置的信号前沿触发到,bit1表示信号的后沿触发到。
// pPosArray : 返回位置,在触发到时,位置为捕获到的位置值。
//				pPosArray[0]:信号前沿触发位置,pPosArray[1]:信号后沿触发位置,单位:脉冲
MTN_API short  __stdcall NMC_MtGetAdvCaptPos( HAND devHandle, short *captSts,long *pPosArray ,short ch);

// 设置轴补偿参数
// enable: 0:取消 1：使能
// para1: 参数1，数值范围在（10~500）,建议先从大到小进行设置测试
// para2: 参数2，数值为控制频率HZ
MTN_API short  __stdcall  NMC_MtSetAxisDampCompParam(HAND axisHandle,short enable,short param1,short param2);

// 设置越限报警的动作
// actionsBits:轴越限报警后的处理方法，按位表示，默认为0，即只置起轴超限标志位
//		bit0:关闭使能
//		bit1:停止轴运动
//		其他保留
MTN_API short  __stdcall NMC_MtSetPosErrAction( HAND axisHandle,short actionsBits);

// 读取越限报警的动作
MTN_API short  __stdcall NMC_MtGetPosErrAction( HAND axisHandle,short *pActionsBits);

//------------------------------------------------------------------------------------------------------------
//
//	4.缓冲区高级指令
//
//------------------------------------------------------------------------------------------------------------

// 坐标系运动：扩展参数
typedef struct
{
	double startVel;					//起跳速度（默认0）
	double T;							//前瞻时间常数,越大则速度变化越小 (默认1)
	double smoothDec;					//停止减速度（默认accMax）
	double abruptDec;					//急停减速度（默认无穷大）
	short  lookAheadSwitch;				//前瞻启动开关( 默认为1，表示前瞻开)
	short eventTime;					// 最小的匀速段时间,单位ms,(默认为10)
	short reserved[2];
}TExtCrdPara;

// 设置坐标系扩展参数 
// extCrdPara:坐标系扩展参数,参考坐标系运动：扩展参数’TExtCrdPara结构体定义
MTN_API short __stdcall NMC_CrdSetExtPara( HAND crdHandle, TExtCrdPara *extCrdPara);

typedef struct
{
	short lookAheadSwitch;			// 前瞻功能控制，0:不需要前瞻，1:使用下位机前瞻，[2,n]：使用上位机前瞻，数值为前瞻段数缓存段数
	short centAccEn;				// 是否使用指定的向心加速度，默认为0，即不使用
	short crossEn;					// 短线段合并开关,0:关闭合并；1：启用合并
	short eventTime;				// 最小的匀速段时间,单位ms,(默认为10)

	double accMax;					// 机台允许的最大加速度,默认1000
	double T;						// 前瞻时间常数,越大则速度变化越小 (默认1)
	double slowAng;					// 减速角度,小于设定角度，则不减速
	double stopAng;					// 停止角度，大于设定角度，则减速为0
	double crossProp;				// 短线段合并粒度，取值范围(0,n],数值越大，则合并越夸张	
	double centAcc;					// 向心加速度
	double dvMax[CRD_MAX_DIMENSION];// 单轴允许的速度变化量

	short preHandleEn;				// 轨迹预处理功能开关
	short reserved;					// 保留参数
	float preHandleDisAngMin;		// 轨迹预处理最小角度，保留尖角
	float preHandleDisAngMax;		// 轨迹预处理最大角度
	float preHandleTol;				// 预处理误差，单位:脉冲

}TLookaheadPara;

// 设置前瞻参数
// lkhPara:前瞻相关的参数
MTN_API short __stdcall NMC_CrdSetLookaheadPara( HAND crdHandle, TLookaheadPara *lkhPara);

// 获取前瞻参数
// lkhPara:前瞻相关的参数
// defaultFlag:1表示获取默认值，0表示获取当前值
MTN_API short __stdcall NMC_CrdGetLookaheadPara( HAND crdHandle, TLookaheadPara *lkhPara,short defaultFlag);

// 设置坐标系运动缓冲区是否启用,NMC_CrdConfig后默认为启用状态
// enFlag:启用,1：启动,0：不启用
// 注意：如果不想使用坐标系运动缓冲区,请在NMC_CrdConfig之后调用该指令
MTN_API short __stdcall NMC_EnableCrdSdram( HAND crdHandle, short enFlag);

// 读取坐标系扩展参数
// extCrdPara:坐标系扩展参数
MTN_API short __stdcall NMC_CrdGetExtPara( HAND crdHandle, TExtCrdPara *extCrdPara);
 
// 坐标系运动：圆弧插补配置
#define MAX_ERR_TABLE_SECTION	2
typedef struct
{
	double minSectionLen;				// 分解的最小段长,默认1脉冲,范围[1,10000]
	double maxArcDiff;					// 最大的圆弧有效性误差,单位：脉冲
		
	// 圆弧插补误差配置表
	// 注意：MTN通过限制圆弧插补速度,从而保证插补误差。r全部为0,则表示关闭这个功能
	double r[MAX_ERR_TABLE_SECTION];	// 半径
	double err[MAX_ERR_TABLE_SECTION+1];	// 半径对应的插补误差,半径 [0,r0],对应err0;半径[r0,r1],对应err1;半径[r1,+max],对应err2

}TArcSecSetting;
// 设置圆弧插补参数（高级指令）
// pSetting : 设置
MTN_API short __stdcall NMC_CrdSetArcSecPara( HAND crdHandle,  TArcSecSetting *pSetting);
                                          
// 读圆弧插补参数（高级指令）
MTN_API short __stdcall NMC_CrdGetArcSecPara( HAND crdHandle,  TArcSecSetting *pSetting);

// 坐标系运动参数
typedef struct
{
	short orgFlag;		// 是否自定义坐标系原点
	short reserved[3];		// 保留
	long offset[4];		// 自定义坐标系原点偏置（基于机械原点）
	double synAccMax;	// 最大合成加速度
	double synVelMax;	// 最大合成速度
}TCrdPara;
// 设置坐标系参数(必须)
// pCrdPara:坐标系参数
MTN_API short __stdcall NMC_CrdSetPara( HAND crdHandle, TCrdPara *pCrdPara );

// 读取插补坐标系系统配置信息
// pConfig:返回坐标系配置,参考结构体定义
MTN_API short __stdcall NMC_CrdGetConfig( HAND crdHandle, TCrdConfig *pConfig );

// 获取坐标系参数
// pCrdPara:坐标系参数
MTN_API short __stdcall NMC_CrdGetPara( HAND crdHandle, TCrdPara *pCrdPara );

// 获取坐标系速度倍率
// overRide：坐标系速度倍率
MTN_API short __stdcall NMC_CrdGetOverRide( HAND crdHandle, double *pOverRide );

// 坐标系状态字位定义:内部扩展 
#define BIT_CORD_POSREC         (0x00000040)    // bit 6 , 伺服位置到达,步进模式时位置到达,伺服模式时实际位置到达误差限    
#define BIT_CORD_AUXAXIS_BUSY   (0x00000080)    // bit 7 , 坐标系运动中的关联轴启动前处于运动状态错误
#define BIT_CORD_AUXAXIS_ERR    (0x00000100)    // bit 8 , 插补辅助轴错误             
#define BIT_CORD_AXIS_ERR       (0x00000200)    // bit 9 , 插补轴存在报警错误（如限位、驱动报警）   
#define BIT_CORD_SDRAM_CALC_ERR (0x00000400)    // bit 10 , SDRAM缓冲区计算错误  
#define BIT_CORD_SCARA_CALC_ERR (0x00000800)    // bit 11 , SCARA计算数据错误
// 读取内部坐标系状态
// pStsWord：返回状态字,定义64bits(二维的long数组),便于后续扩展状态位
MTN_API short __stdcall NMC_CrdGetInnerSts     ( HAND crdHandle, long *pStsWord );

// 直接修改坐标系偏移
// pOffsetArray:坐标系偏移
// cnt:数组长度
MTN_API short __stdcall NMC_CrdModifyOffset( HAND crdHandle, long *pOffsetArray, short cnt);

// 缓冲区设置急停DI
// axis:轴号,取值范围[0,n)
// gpiIndex:通用输入序号
// sense:触发电平
MTN_API short  __stdcall NMC_CrdBufSetEstopDI ( HAND crdHandle,long segNo,short axis,short gpiIndex,short sense);

// 缓冲区数据打包
#define BUF_LINE	0 //缓冲区直线插补
#define BUF_DO		1 //缓冲区DO输出
#define BUF_OUT		2 //缓冲区OUT输出
#define BUF_DELAY   3 //缓冲区延时
#define BUF_AXMOVE	4 //缓冲区单轴运动
#define BUF_DOEX    5 //缓冲区DO输出（根据掩码输出）
#define BUF_ARC_R   6 //平面圆弧插补：终点位置、半径、方向
#define BUF_ARC_C   7 //平面圆弧插补：终点位置、圆心、方向
#define BUF_LASER_SETPOWER		8	// 激光：设置能量
#define BUF_LASER_ONOFF			9	// 激光：缓冲区开关光
#define BUF_LASER_SETFOLLOW		10	// 激光：设置跟随
#define BUF_LASER_SETPARAM		11	// 激光：设置参数
#define BUF_LINEXYZA			12	// 缓冲区四轴直线插补
#define BUF_SHIO_GATEPULSE		13	// 缓冲区输出Gate脉冲
#define BUF_DOBITPULSE			14	// DoBitPulse功能
#define BUF_XYZD8          		15	// LineXYZD8,数据结构体为：TCrdLineXYZD8Unit
#define BUF_SHIOMINFRQ     		16	// 设置或清除SHIO最小频率
#define BUF_SHIOSETPARAM        17	// 设置SHIO参数
#define BUF_SHIOGATEONOFF       18	// 设置Gate开关
#define BUF_WAITENCINPOS        19	// 等待电机到位
#define BUF_WAITDI              20	// 等待DI

#pragma pack(push)
#pragma pack(4)
typedef struct
{  
	long segNo;        // 用户自定义段号
	long tgPos[3];     // 目标位置
	double endVel;     // 终点速度
	double vel;        // 最大速度
	double synAcc;     // 插补加速度
	short mask;        // crdAxMask,参与的插补轴,按位表示
	short lookaheadDis;//是否使用前瞻
    long  reserved;     // 保留
}TCrdBufLine;

typedef struct
{  
	long tgPos[4];     // 目标位置
	double endVel;     // 终点速度
	double vel;        // 最大速度
	double synAcc;     // 插补加速度
	long segNo;        // 用户自定义段号
	short mask;        // crdAxMask,参与的插补轴,按位表示
	short lookaheadDis;//是否使用前瞻
}TCrdBufLineXYZA;

typedef struct
{
	long segNo;     // 用户自定义段号
	short group;    // Out输出类型 
	short ch;       // 通道号,取值范围[0,n]
	long outValue;	// 输出
}TCrdBufOut;

typedef struct
{
	long segNo;     // 用户自定义段号
	short group;    // 缓冲区输出DO组 
	short ch;       // 位序号,取值范围[0,31]
	long value;     // 输出值,取值范围[0,1]
}TCrdBufDO;

typedef struct
{
	long segNo;     // 用户自定义段号
	long scale;     // 延时单位,0表示单位为毫秒,1表示单位为秒
	long count;     // 延时时长
}TCrdBufDelay;

typedef struct
{
	long segNo;     // 用户自定义段号
	long group;    // 缓冲区输出DO组
	long doMask;    // 输出操作位,bit位为1表示要输出
	long value;     // 输出值,bit位指示输出值
}TCrdBufDOEx;

typedef struct
{
	long segNo;         // 用户自定义段号
	short axis;		    // 单轴移动的轴号 [0,n],非坐标系内轴	
	short soomthCoef;   // smoothCoef:平滑系数
	short blockEn;      // 是否为阻塞模式 0 不阻塞 ,1 阻塞
	short synEn;        // 是否为同步模式 0 异步 ,1 同步
    long  tgPos;	    // 目标位置
	double vel;         // 运动速度
	double acc;         // 运动加速度
}TCrdBufAxMove;

typedef struct
{
	long segNo;         // 用户自定义段号
	long tgPos[2];		// 目标位置
	short circleDir;    // 是否为同步模式 0 异步 ,1 同步
	char lookaheadDis;	// 是否使用前瞻
	char panelIndex;	// 圆弧插补平面：0：XY平面，1：YZ平面，其他：ZX平面
	double radius;		// 半径
	double endVel;      // 终点速度
	double vel;         // 运动速度
	double acc;         // 运动加速度
}TCrdBufArcR;

typedef struct
{
	long segNo;         // 用户自定义段号
	long tgPos[2];		// 目标位置
	long centerPos[2];	// 目标位置
	short circleDir;    // 是否为同步模式 0 异步 ,1 同步
	char lookaheadDis;	// 是否使用前瞻
	char panelIndex;	// 圆弧插补平面：0：XY平面，1：YZ平面，其他：ZX平面
	double endVel;      // 终点速度
	double vel;         // 运动速度
	double acc;         // 运动加速度
}TCrdBufArcC;
 
typedef struct
{  
	long segNo;        // 用户自定义段号
	long onDelay;     // 开光延时
	long offDelay;     // 关光延时
	long minValue;     // 最小输出值
	long maxValue;     // 最大输出值
	long standbyPower;	// 待机能量
	short ch;			// 激光控制通道
	short reserved;		// 保留
}TCrdBufLaserSetParam;

typedef struct
{  
	long segNo;        // 用户自定义段号
	short followType;    // 跟随类型
	short ch;			// 激光通道号
	double overRide;     // 跟随倍率
}TCrdBufLaserSetFollow;

typedef struct
{  
	long segNo;        // 用户自定义段号
	short onOff;		// 开关,0：关光,1：开光
	short ch;			// 激光通道号
}TCrdBufLaserOnOff;

typedef struct
{  
	long segNo;        // 用户自定义段号
	short ch;			// 激光通道号
	short reserved;		// 保留
	double power;		// 能量
}TCrdBufLaserSetPower;

typedef struct
{  
	long segNo;        // 用户自定义段号
	long outCount;		// 输出个数
	double gateTime;	// gate输出的脉宽，单位：微秒
	double gateFrq;		// gate输出的频率，单位：HZ
	short ch;			// ch:通道
    short reserved[3];  // 保留
}TCrdBufSHIOGatePulse;


typedef struct
{  
	long segNo;			// 用户自定义段号
	long highLevelTime;	// 高电平宽度，单位:us
	long lowLevelTime;	// 低电平宽度，单位:us
	long outCount;		// 输出脉冲个数
	long initialLevel;	// 0：先输出低电平，1：先输出高电平
	short ch;			// ch:通道
	short enable;		// 1:使能,0:关闭
	short doType;		// DO类型,默认CRD_BUFF_DO_GPDO1
	short doIndex;		// DO序号，取值范围[0,n]
}TCrdBufDoBitPulse;

typedef struct
{  
	long segNo;			// 用户自定义段号
    long minFrq;        // 最小频率，仅当enable=1时有效
	short ch;			// 通道
	short setOrClr;		// 1:设置,0:清除
}TCrdBufSHIOMinFrq;

typedef struct
{  
	long segNo;			// 用户自定义段号
	short ch;			// 通道
	short reserved;		// 保留
    double delay;       // 延时开关光时间
    double gateTime;    // gate打开时间，单位:秒
    double gateDistance;// 固定模式下的位置间隔，单位pulse
}TCrdBufSHIOSetParam;

typedef struct
{  
	long segNo;			// 用户自定义段号
	short ch;			// 通道
	short onOff;		// 1:打开，0：关闭
}TCrdBufSHIOGateOnOff;

typedef struct
{  
	long segNo;			// 用户自定义段号
	long axisMask;		// 轴掩码
	long overTime;		// 等待超时时间，单位：毫秒
}TCrdBufWaitEncInPosition;

typedef struct
{  
	long segNo;			// 用户自定义段号
	short index;		// 通道号,取值范围[0,127],前64通道代表通用DI，后64通道代表扩展IO
	short level;		// 等待值
    long waitLastTime;  //超时,单位：毫秒
}TCrdBufWaitDI;

#pragma pack(pop)

// 打包插补数据
// pBufData 插补数据结构存储数组
// dataLen 数据长度
// 压入数据时，先压入指令字，然后再压入指令字对应的工作数据，总的数据长度不超过1000个字节
MTN_API short __stdcall NMC_CrdBufDataPack(HAND crdHandle,  unsigned char *pBufData, short dataLen);

//功能：缓冲区探位置停止并后续加位置偏置
// useCaptPos：是否使用捕获位置  1使用,0不使用
// axis:轴序号
// sense:触发电平,0：低电平,1：高电平
// gpiIndex:通用输入序号
MTN_API short  __stdcall NMC_CrdBufSetStopOffset ( HAND crdHandle, long segNo,
	short axis,short gpiIndex,short sense,short useCaptPos);

//功能：解除缓冲区探位置停止并后续加位置偏置
MTN_API short  __stdcall NMC_CrdBufClrStopOffset ( HAND crdHandle, long segNo,short axis);

// 设置是否计算所有线段长度
MTN_API short __stdcall NMC_CrdSetBufLengthFlag(HAND crdHandle, short flag);

// 读取插补线段长度
MTN_API short __stdcall NMC_CrdGetBufLength(HAND crdHandle, double *pLen);

MTN_API short  __stdcall NMC_CrdSetIsShortLine(HAND crdHandle,short isShortLine);

MTN_API short  __stdcall NMC_CrdSetLookAheadCentriAcc(HAND crdHandle,short isUsingSetAcc,double centriAcc);

//------------------------------------------------------------------------------------------------------------
//
//	5.硬件捕获及不常用指令
//
//------------------------------------------------------------------------------------------------------------

// 编码器硬件捕获模式选择 
#define CAPT_MODE_Z          0   // 编码器Z相捕获 
#define CAPT_MODE_IO         1   // IO 捕获 
#define CAPT_MODE_Z_AND_IO   2   // IO+Z相 捕获 
#define CAPT_MODE_Z_AFT_IO   3   // 先IO触发再Z相触发 捕获 

// 编码器硬件捕获IO源选择 
#define CAPT_IO_SRC_HOME    0   // 原点输入作为捕获IO 
#define CAPT_IO_SRC_LMTN    1   // 负向限位输入作为捕获IO 
#define CAPT_IO_SRC_LMTP    2   // 正向限位输入作为捕获IO 
#define CAPT_IO_SRC_DI0     3   // 通用数字输入0作为捕获IO 
#define CAPT_IO_SRC_DI1     4   // 通用数字输入1作为捕获IO 
#define CAPT_IO_SRC_DI2     5   // 通用数字输入2作为捕获IO 
#define CAPT_IO_SRC_DI3     6   // 通用数字输入3作为捕获IO 
#define CAPT_IO_SRC_DI4     7   // 通用数字输入4作为捕获IO 
#define CAPT_IO_SRC_DI5     8   // 通用数字输入5作为捕获IO 
#define CAPT_IO_SRC_DI6     9   // 通用数字输入6作为捕获IO 
#define CAPT_IO_SRC_DI7     10  // 通用数字输入7作为捕获IO 
#define CAPT_IO_SRC_DI8     11  // 通用数字输入8作为捕获IO 
#define CAPT_IO_SRC_DI9     12  // 通用数字输入9作为捕获IO 
#define CAPT_IO_SRC_DI10    13  // 通用数字输入10作为捕获IO 
#define CAPT_IO_SRC_DI11    14  // 通用数字输入11作为捕获IO 
#define CAPT_IO_SRC_DI12    15  // 通用数字输入12作为捕获IO 
// 设置捕获有效电平
// mode : 模式选择,参考宏定义
// ioSrc：IO输入源选择,参考宏定义
// level: 触发沿。bit0:index电平（0为下降沿,1为上升沿）,bit1:IO电平
MTN_API short  __stdcall NMC_MtSetCaptSns( HAND axisHandle, short mode, short ioSrc, short level );

// 读取捕获有效电平
// mode : 模式选择,参考宏定义
// ioSrc：IO输入源选择,参考宏定义
// level: 触发沿。0为下降沿,1为上升沿
MTN_API short  __stdcall NMC_MtGetCaptSns( HAND axisHandle, short *pMode, short *pIoSrc, short *pLevel );

// 设置启动捕获
// 注：捕获触发标志在轴状态字里。
MTN_API short  __stdcall NMC_MtSetCapt( HAND axisHandle );

// 清除轴的捕获状态
MTN_API short __stdcall NMC_MtClrCaptSts   ( HAND axisHandle);

// 读捕获位置
// pPos : 返回位置,单位:脉冲
MTN_API short  __stdcall NMC_MtGetCaptPos( HAND axisHandle, long *pPos );

// 读取脉冲输出滤波
// pCoe系数： 范围0~65535,0不滤波,数值越大滤波效果越明显。默认值为0
MTN_API short  __stdcall NMC_MtGetStepFilter ( HAND axisHandle, unsigned short  *pCoe );

// 多轴同时启动
// axisHandle:任意轴
// axisMask：按bit对应相应轴号,bit为1表示启动,bit为0表示不启动
MTN_API short __stdcall NMC_MtUpdateMulti( HAND axisHandle,long axisMask );

// 多轴同时停止
// axisHandle:任意轴
// axisMask：按bit对应相应轴号,bit为1表示启动,bit为0表示不启动
MTN_API short __stdcall NMC_MtStopMulti( HAND axisHandle,long axisMask  );

// 按位设置通用输入信号取反
// bitIndex:取值范围[0,n],位序号,前64位为本地的通用输入,大于64为扩展Di
// revs:是否取反,1：取反,0：不取反
MTN_API short  __stdcall NMC_SetDIBitRevs ( HAND devHandle,short bitIndex,short revs);

// 按位读取通用输入信号取反
// bitIndex:取值范围[0,n],位序号,前64位为本地的通用输入,大于64为扩展Di
// pRevs:是否取反,1：取反,0：不取反
MTN_API short  __stdcall NMC_GetDIBitRevs ( HAND devHandle,short bitIndex,short *pRevs);

// 按位设置通用输出信号取反
// bitIndex:取值范围[0,n],位序号,前64位为本地的通用输出,大于64为扩展Do
// revs:是否取反,1：取反,0：不取反
MTN_API short  __stdcall NMC_SetDOBitRevs ( HAND devHandle,short bitIndex,short revs);

// 按位读取通用输出信号取反
// bitIndex:取值范围[0,n],位序号,前64位为本地的通用输出,大于64为扩展Do
// pRevs:是否取反,1：取反,0：不取反
MTN_API short  __stdcall NMC_GetDOBitRevs ( HAND devHandle,short bitIndex,short *pRevs);

// DO输出持续设定时间后翻转
// bitIndex:取值范围[0,n],位序号,前64位为本地的通用输出,大于64为扩展Do
// value:设置通用数字量输出。1, 输出高电平,0,输出低电平
// reverseTime:持续的电平,单位:毫秒
MTN_API short  __stdcall NMC_SetDOBitAutoReverse(HAND devHandle,short bitIndex,short value,short reverseTime);

// DIO映射
#define DIO_MAP_MAX_NUM		8	// 最多允许的映射关系

// 信号类型定义
#define DIO_TYPE_GPI		1	// 通用输入
#define DIO_TYPE_HOME		2	// 轴Home信号
#define DIO_TYPE_ALM		3	// 驱动器报警信号
#define DIO_TYPE_LMTN		4	// 轴负向限位信号
#define DIO_TYPE_LMTP		5	// 轴正向限位信号
#define DIO_TYPE_GPO		6	// 通用输出信号
#define DIO_TYPE_SVON		7	// 伺服使能信号
#define DIO_TYPE_SVCLR		8	// 报警清除信号


// DIo映射参数配置
typedef struct 
{
	unsigned char  enable;		// 1：启用，0：禁用
	unsigned char  pinGrp;      // 映射的信号类型
	unsigned char  pinIndex;    // 映射的信号序号
	unsigned char  outEnable;	// 输出允许       
	unsigned char  newGrp;      // 映射到的信号类型
	unsigned char  newIndex;	// 映射到的信号序号
}TDioMappingCfg;

// 增加一组映射，映射关系目前最多存在DIO_MAP_MAX_NUM组
MTN_API short  __stdcall NMC_SetDioMapping(HAND devHandle,TDioMappingCfg *pDioCfg);

// 获取所有的DIO映射数据
// pDioCfg：映射数据数组,目前为DIO_MAP_MAX_NUM组
MTN_API short  __stdcall NMC_GetAllDioMapping(HAND devHandle,TDioMappingCfg *pDioCfg);

// 清除所有的DIO映射关系
MTN_API short  __stdcall NMC_ClrAllDioMapping(HAND devHandle);

//------------------------------------------------------------------------------------------------------------
//
//	6.平台相关指令
//
//------------------------------------------------------------------------------------------------------------
// 
#define     VAR_PWM0_CTL    256		// pwm通道0打开关闭,1表示打开,0表示关闭
#define     VAR_PWM0_VALUE  257		// pwm通道0输出值
#define     VAR_PWM1_CTL    258		// pwm通道1打开关闭,1表示打开,0表示关闭
#define     VAR_PWM1_VALUE  259		// pwm通道1输出值
#define     VAR_EXT_DAC0    260		// 扩展的DAC通道0
#define     VAR_EXT_DAC1    261		// 扩展的DAC通道1
#define     VAR_OUT_OPTION	262		// PWM输出通道选项
#define     VAR_DAC0		263		// DAC通道0~7
#define     VAR_DAC1		264
#define     VAR_DAC2		265
#define     VAR_DAC3		266
#define     VAR_DAC4		267
#define     VAR_DAC5		268
#define     VAR_DAC6		269
#define     VAR_DAC7		270
#define     VAR_ADC0		271		// ADC通道0~7
#define     VAR_ADC1		272
#define     VAR_ADC2		273
#define     VAR_ADC3		274
#define     VAR_ADC4		275
#define     VAR_ADC5		276
#define     VAR_ADC6		277
#define     VAR_ADC7		278
#define     VAR_INNNER_VAR1	1000
#define     VAR_INNNER_VAR2	1001
// 设置通用可寻址变量 8字节数据类型（可涵盖常用的类似,如：char/short/long/double 等）
MTN_API short __stdcall NMC_SetVar8B( HAND devHandle, long varID, long long value );

// 读取通用可寻址变量 8字节数据类型（可涵盖常用的类似,如：char/short/long/double 等）
MTN_API short __stdcall NMC_GetVar8B( HAND devHandle, long varID, long long *pValue );

// 系统变量宏定义
#define SYS_VAR_SET_STAT_ENABLE		100
#define SYS_VAR_GET_CLOCK			101
#define SYS_VAR_GET_USERAPP_COUNT	107
#define SYS_VAR_GET_USERAPP_MIN		108
#define SYS_VAR_GET_USERAPP_MAX		109
#define SYS_VAR_GET_USERAPP_AVG		110
#define SYS_VAR_GET_USERAPP_CURT	111
#define SYS_VAR_GET_PRFINT_COUNT	112
#define SYS_VAR_GET_PRFINT_MIN		113
#define SYS_VAR_GET_PRFINT_MAX		114
#define SYS_VAR_GET_PRFINT_AVG		115
#define SYS_VAR_GET_PRFINT_CURT		116
#define SYS_VAR_GET_MAINLP_COUNT	117
#define SYS_VAR_GET_MAINLP_MIN		118
#define SYS_VAR_GET_MAINLP_MAX		119
#define SYS_VAR_GET_MAINLP_AVG		120
#define SYS_VAR_GET_MAINLP_CURT		121

// 设置通用可寻址系统变量 8字节数据类型（可涵盖常用的类似,如：char/short/long/double 等）
MTN_API short __stdcall NMC_SysSetVar8B( HAND devHandle, long varID, __int64 value );

// 读取通用可寻址系统变量 8字节数据类型（可涵盖常用的类似,如：char/short/long/double 等）
MTN_API short __stdcall NMC_SysGetVar8B( HAND devHandle, long varID, __int64 *pValue );

//向备份内存写数据(总长度约1500byte)
//src: 要写入的数据
//len: 要写入的长度,单位：byte
//off: 要写入的地址(偏移量)
// 注：1)写入的数据掉电不丢失。
//     2)一次最多写1440字节。总长度约1500byte
MTN_API short __stdcall NMC_BackSramWrite(HAND devHandle,const void *src, long len, long off);

//从备份内存读数据
//dst: 读出的数据暂存区
//len: 要读出的长度,单位：byte,一次最多读1440字节。总长度约1500byte
//off: 读数据的地址(偏移量)
MTN_API short __stdcall NMC_BackSramRead(HAND devHandle,void *dst, long len, long off);

// 平台：控制器时间结构
typedef    struct
{
    short   year;           // 年,真实年份。取值范围[2000,2099]
    short   mon;            // 月,取值范围[1,12]
    short   day;            // 日,取值范围[1,31]
    short   hour;           // 时,取值范围[0,23]
    short   min;            // 分,取值范围[0,59]
    short   second;         // 秒,取值范围[0,59]
} TNMCTime;
// 读时间
// pTime ：返回时间结构,参考 TNMCTime 结构定义
// 注：时间在出厂时根据实际时间设定,用户不可通过指令修改
MTN_API short  __stdcall NMC_GetTime( HAND devHandle, TNMCTime *pTime );


// 写时间
// pTime ：时间结构,参考 TNMCTime 结构定义
// pPassword : 控制器系统密码,长度最多为16个字节
MTN_API short  __stdcall NMC_SetTime( HAND devHandle, TNMCTime *pTime,char *pPassword);

// 修改控制器系统密码,密码用于修改系统时钟等
// pPasswordOld : 控制器系统当前密码,长度最多为15个字符
// pPasswordNew : 新的控制器系统密码,长度最多为15个字符
// 注意：1.初始出厂无密码
//            2.修改密码后,请务必记住新的密码。忘记密码只能返厂复位。
//            3.密码大小写敏感
MTN_API short  __stdcall NMC_ChangePassword( HAND devHandle, char *pPasswordOld,char *pPasswordNew);

// 验证系统密码
// pPassword : 控制器系统当前密码,长度最多为15个字符
// 返回0表示验证通过,其他表示错误
MTN_API short  __stdcall NMC_VerifyPassword( HAND devHandle, char *pPassword);

// 清除系统密码及用户密码
// pData:解密数据，长度为8
MTN_API short  __stdcall NMC_ClrPassword( HAND devHandle, short *pData);

// 读设备唯一序列号
// pUID ：返回设备唯一序列号,为四个Int32的数据
// example:unsigned long devID[4];
//         NMC_GetUID(g_hDev,devID);
MTN_API short  __stdcall NMC_GetUID( HAND devHandle, unsigned long *pUID );

// 写用户参数
// add ：参数区的偏移地址(字节地址)
// len : 写入长度,单位：byte
// pWrData ：要写入的数据；
// 注：1)写入的数据掉电不丢失。
//     2)一次最多写256字节。参数区总长度为2048字节。
//     3)此指令比其它指令操作时间会长,如果出现通讯错误（返回-1）,则需要将通过NMC_SetCommPara延长指令通讯时间
MTN_API short  __stdcall NMC_UserParaWr( HAND devHandle, unsigned long add, unsigned long len, unsigned char *pWrData );

// 读用户参数
// add ：参数区的偏移地址(字节地址)
// len : 写入长度,单位：byte
// pRdData ：要读取的数据存储
// 注：一次最多读256字节。参数区总长度为2048字节。（参考函数 ： NMC_UserParaWr）
MTN_API short  __stdcall NMC_UserParaRd( HAND devHandle, unsigned long add, unsigned long len, unsigned char *pRdData );

// 写扩展用户参数
// add ：参数区的偏移地址(字节地址)
// len : 写入长度,单位：byte
// pWrData ：要写入的数据；
// 注：1)写入的数据掉电不丢失。
//     2)一次最多写1000字节。参数区总长度为32K字节。
//     3)此指令比其它指令操作时间会长,如果出现通讯错误（返回-1）,则需要将通过NMC_SetCommPara延长指令通讯时间
MTN_API short  __stdcall NMC_UserParaWrEx( HAND devHandle, unsigned long add, unsigned long len, unsigned char *pWrData );

// 读扩展用户参数
// add ：参数区的偏移地址(字节地址)
// len : 写入长度,单位：byte
// pRdData ：要读取的数据存储
// 注：一次最多读1000字节。参数区总长度为32K字节。（参考函数 ： NMC_UserParaWr）
MTN_API short  __stdcall NMC_UserParaRdEx( HAND devHandle, unsigned long add, unsigned long len, unsigned char *pRdData );

// 掉电保存：备份数据定义
typedef struct
{
	long crdSegNo;		// 坐标系运动的段号
	long crdPrfPos[3];	// 坐标系运动的规划位置
	long axPrfPos[8];	// 规划位置
	long axisPos[8];	// 机械位置
	long encPos[8];		// 编码器位置
}TBackGroup1;
// 读取当前备份的变量数值（断电自动保存）
// pBackVar : 备份的变量值,参考结构体定义
MTN_API short __stdcall NMC_GetBackedVarGroup1( HAND devHandle, TBackGroup1 *pBackVar);

// 掉电保存：备份数据定义（12轴）
typedef struct
{
	long crdSegNo[2];		// 坐标系运动的段号
	long crdPrfPos[2][3];	// 坐标系运动的规划位置
	long axPrfPos[12];		// 规划位置
	long axisPos[12];		// 机械位置
	long encPos[12];		// 编码器位置
}TBackGroup2;
// 读取当前备份的变量数值（断电自动保存）
// pBackVar : 备份的变量值,参考结构体定义
MTN_API short __stdcall NMC_GetBackedVarGroup2( HAND devHandle, TBackGroup2 *pBackVar);

// 开始或者关闭变量的自动备份（断电自动保存,默认为关闭状态）
// en:是否开启,1：开启变量的自动备份,0：停止变量的自动备份
MTN_API short __stdcall NMC_SetBackedVarOnOff( HAND devHandle, short en);

// 读取当前自动备份的开启状态
// pEn:当前的开启状态
MTN_API short __stdcall NMC_GetBackedVarOnOff( HAND devHandle, short *pEn);

// paraID
#define     PARA_IP_ADDR   	100		// IP地址,四个字节分别表示四段
#define     PARA_IP_MSK    	101		// IP mask
#define     PARA_IP_GW   	102		// Gateway
#define     PARA_IP_DHCP   	103		// DHCP
#define     PARA_WRITE_EN	999		// 参数保存
// 读取系统参数（long 型）
// paraID :　系统参数ID,参见后面定义。pValue : 返回值
// 注：此函数可用于设置板卡上的扩展资源
MTN_API short  __stdcall NMC_DevGetPara( HAND devHandle, unsigned long paraID, long *pValue );

// 设置系统参数（long 型）
// paraID :　系统参数ID,参见后面定义。value : 设置值
// 注：此函数可用于读取板卡上的扩展资源
// 注：IP地址等参数写成功后,需要调用NMC_DevSetPara(devHandle,PARA_WRITE_EN,1)才能使得写下去的参数保存
// 注：IP地址等参数写成功后,将在控制器重新启动后生效
MTN_API short  __stdcall NMC_DevSetPara( HAND devHandle, unsigned long paraID, long value );

// 设置用户密码
// pUserName    : 指定的用户名,目前只支持"USER1"
// pPasswordOld : 该用户的当前密码,长度最多为15个字符
// pPasswordNew : 新的该用户的密码,长度最多为15个字符
// 注意：1.初始出厂无密码,一旦设置密码,则必须要登陆后,控制器某些指令才能正常工作（包括启动运动指令,设置DO输出指令）
//      2.修改密码后,请务必记住新的密码。忘记密码只能返厂复位。
//      3.密码大小写敏感
MTN_API short  __stdcall NMC_UserSetPassword( HAND devHandle, char *pUserName,char *pPasswordOld,char *pPasswordNew);

// 用户登陆
// pUserName    : 指定的用户名,目前只支持"USER1"
// pPassword    : 该用户的密码
MTN_API short  __stdcall NMC_UserLogin( HAND devHandle, char *pUserName,char *pPassword);

// 用户退出登陆
// pUserName    : 指定的用户名,目前只支持"USER1"
MTN_API short  __stdcall NMC_UserLogout( HAND devHandle, char *pUserName);

// 设置控制器的规划周期，默认1000
// period：单位us	只能为250 500 1000
// 注意：1.规划周期设置后立即生效，只能在控制器启动时配置
//       2.NMC_DevReset会复位规划周期为默认值
MTN_API short __stdcall NMC_SetProfilePeriod(HAND devHandle,short period);

// 获取控制器的规划周期
// period：单位us	只能为250 500 1000
MTN_API short __stdcall NMC_GetProfilePeriod(HAND devHandle,short *pPeriod);

// 打印信息
MTN_API short __stdcall NMC_UserPrint(char *msg);

// 获取输出信息
MTN_API short __stdcall NMC_DevGetOutputMsg(HAND devHandle,char *szBuf,short maxLen,short *pGetLen);

//------------------------------------------------------------------------------------------------------------
//
//	7.数据采集模块(高级指令)
//
//------------------------------------------------------------------------------------------------------------

// Collect模块：变量类型
#define COLLECT_ADDRESS_PRF_POS				(0)	// 规划位置
#define COLLECT_ADDRESS_AXIS_POS			(1)	// 机械位置
#define COLLECT_ADDRESS_ENC_POS				(2)	// 编码器位置
#define COLLECT_ADDRESS_CMD_POS				(3)	// 命令位置
#define COLLECT_ADDRESS_AXIS_VEL			(4)	// 电机速度
#define COLLECT_ADDRESS_CRD_POS				(5)	// 坐标系0位置
#define COLLECT_ADDRESS_CRD_VEL				(6)	// 坐标系0速度
#define COLLECT_ADDRESS_CRD_POS0			(5)	// 坐标系0位置
#define COLLECT_ADDRESS_CRD_VEL0			(6)// 坐标系0速度
#define COLLECT_ADDRESS_CRD_POS1			(9)// 坐标系1位置		
#define COLLECT_ADDRESS_CRD_VEL1			(10)// 坐标系1速度
#define COLLECT_ADDRESS_ENC_VEL				(7)	// 编码器速度
#define COLLECT_ADDRESS_CMD_VEL				(8)	// 命令速度
#define	COLLECT_ADDRESS_LASER_OUTPUT		(11)// 激光输出（补偿前）
#define COLLECT_ADDRESS_LASER_GATE			(12)// 激光gate信号状态
#define COLLECT_ADDRESS_LASER_POWER			(13)// 激光能量当前输出值
#define COLLECT_ADDRESS_DI      			(14)// 数字量输入状态
#define COLLECT_ADDRESS_DO      			(15)// 数字量输出状态
#define COLLECT_ADDRESS_CRD_USERSEG			(16)// 坐标系用户段号
#define COLLECT_ADDRESS_DAC					(17)// 模拟量输出
#define COLLECT_ADDRESS_ADC					(18)// 模拟量输入

// 获取需要采集数据变量的地址
//  index:变量的序号(从0开始)
//  type: 变量的类型,参数‘Collect模块：变量类型’宏定义
//  pAddr: 返回的数据地址
// pDataLen: 返回的该数据长度
MTN_API short  __stdcall NMC_GetCollectDataAddr( HAND devHandle, short index,short dataType,unsigned long *pAddr, short *pDataLen);

// 采集模块：采集配置
#define COLLECT_LIST_MAX		(8) 			//每组最多采集8个数据
typedef struct
{
	short  count;								// 需要采集的变量个数
	short  interval;							// 采集的间隔时间,0表示每隔1毫米采集一次数据,1表示每隔2ms...
	unsigned long  address[COLLECT_LIST_MAX];	// 变量的地址
	short  length[COLLECT_LIST_MAX];			// 每个变量的长度（单位：char）
}TCollectCfg;

// 采集模块：触发模式
#define COLLECT_MODE_NONE	0	// 无条件
#define COLLECT_MODE_G_SRC1	1	// 采集源1数值大于比较值
#define COLLECT_MODE_L_SRC1	2	// 采集源1数值小于比较值
#define COLLECT_MODE_DIFF	3	// 采集源1与采集源2两项差值大于比较值
typedef struct
{
	short  mode;								// 触发模式,
	short  source1;								// 触发源1
	short  source2;								// 触发源2
	short  startDelay;							// 触发启动的延时
	double  value;								// 触发比较值
}TCollectTrig;
// 配置采集数据通道,需要配置对应结构体参数
// pCollect:采集模块配置
// pTrig:采集模块触发方式配置
MTN_API short  __stdcall NMC_ConfigCollect( HAND devHandle, TCollectCfg *pCollect,TCollectTrig *pTrig );

// 启动或停止数据采集
// en：1启动 0停止
MTN_API short  __stdcall NMC_CollectOnOff ( HAND devHandle, short en);

// Collect模块：采集状态
#define COLLECT_BUSY						(0x0001)
#define COLLECT_OVERRIDE_DATA				(0x0002)	
#define COLLECT_PUSH_DATA_ERR				(0x0004)
// 获取采集状态:
// pSts：采集状态,按位表示各自状态,参考‘Collect模块：采集状态’宏定义
// pDataLen: 采集的数据量
MTN_API short  __stdcall NMC_GetCollectSts ( HAND devHandle, short *pSts, long *pDataLen );

// 获取采数据:
// len：采集数据长度（单位：char,一次最多读1440字节）
// pData: 采集的数据（均以char为单元存储）
MTN_API short  __stdcall NMC_GetCollectData ( HAND devHandle, short len, unsigned char *pData );

// 清除采集状态
MTN_API short  __stdcall NMC_ClearCollectSts ( HAND devHandle);

//------------------------------------------------------------------------------------------------------------
//
//	8.激光
//
//------------------------------------------------------------------------------------------------------------
#define MAX_LASER_NUMS			    (4)	    // 最大激光通道

// 激光控制模式
#define LASER_DISABLE_MODE			    (0)	    // 禁用激光功能
#define BASIC_OUTPUT_MODE			    (1)		// 基本控制模式
#define TIME_ARRAY_OUTPUT_MODE			(2)    	// 波形控制模式
#define SHIO_OUTPUT_MODE				(3)     // 位置比较控制模式

//设置激光控制的模式。该模式的设定,约束相应指令的功能和操作
//mode: 激光控制模式,参考上述宏定义
MTN_API short  __stdcall NMC_LaserSetMode  (HAND devHandle, short mode, short ch );

 // 激光物理信号类型
#define LASER_NONE 			(0)			// 关闭激光输出模式
#define LASER_DA  			(1)			// DA输出
#define LASER_PWM_DUTY		(2)			// 占空比输出
#define LASER_PWM_FRQ		(3)			// 频率输出
#define LASER_PWM_FRQ_EXT	(4)			// 频率输出,脉宽固定

// 激光物理信号输出类型配置
// outputType：输出的类型
// index :输出通道序号,取值范围[0,n]
// optionVal: 当作为占空比输出时,该值为PWM的频率,单位HZ；
//            当为LASER_PWM_FRQ时,该值作为占空比值,（0~100）；
//            当为LASER_PWM_FRQ_EXT时,该值为脉宽,单位为0.5微秒,取值范围(0,~)
// ch :激光通道,取值范围[0,n]
MTN_API short  __stdcall NMC_LaserSetOutputType ( HAND devHandle,short outputType,short index,long optionVal,short ch);

// 激光物理信号输出类型配置(高精度)
// outputType：输出的类型
// index :输出通道序号,取值范围[0,n]
// optionVal: 当作为占空比输出时,该值为PWM的频率,单位HZ；
//            当为LASER_PWM_FRQ时,该值作为占空比值,单位为百分比；
//            当为LASER_PWM_FRQ_EXT时,该值为脉宽,单位为微秒,取值范围(0,~)
// ch :激光通道,取值范围[0,n]
MTN_API short  __stdcall NMC_LaserSetOutputTypeEx ( HAND devHandle,short outputType,short index,double optionVal,short ch);

// 功能：设置立即输出激光的能量,
// outVal: 激光能量（设定值意义与NMC_LaserSetOutputType设置的输出类型对应）
// ch：输出通道 (需要根据不同物理信号端口数量进行设定)
MTN_API short  __stdcall NMC_LaserSetPower ( HAND devHandle,long outVal,short ch);

// 功能：读取当前激光的能量 
// pVal: 激光能量值
// ch：通道号
MTN_API short  __stdcall NMC_LaserGetPower ( HAND devHandle,double *pVal,short ch);

// 功能：读取当前激光开关状态 
// pOnOffState: 激光开关状态，1：激光处于打开状态，0:激光处于关闭状态
// ch：通道号
MTN_API short  __stdcall NMC_LaserGetOnOff ( HAND devHandle,short *pOnOffState,short ch);

// 功能：设置立即输出激光的能量(高精度)
// chn：输出通道 (需要根据不同物理信号端口数量进行设定)
// outVal: 激光能量（设定值意义与NMC_LaserSetOutputTypeEx设置的输出类型对应）
MTN_API short  __stdcall NMC_LaserSetPowerEx ( HAND devHandle,double outVal,short ch);

// 功能：激光立即输出开关 
// onOffl: 0或者1表示打开或关闭激光输出
// ch：输出通道 (需要根据不同物理信号端口数量进行设定)
MTN_API short  __stdcall NMC_LaserOnOff ( HAND devHandle,short onOff,short ch);

// 设置激光参数
// onDelay:开光延时,单位us,取值范围[0,65535]
// offDelay:关光延时,单位us,取值范围[0,65535]
// minValue:最小输出值,取值范围[0,32767]
// maxValue:最大输出值,取值范围[0,32767]
// standbyPower:待机能量,为0表示取消待机能量输出功能
// ch:激光控制通道
MTN_API short  __stdcall NMC_LaserSetParam ( HAND devHandle, long onDelay ,
				long offDelay, long minValue ,long maxValue,long standbyPower,short ch);

// 缓冲区设置激光参数
// onDelay:开光延时,单位us,取值范围[0,65535]
// offDelay:关光延时,单位us,取值范围[0,65535]
// minValue:最小输出值，DA输出时，范围[0,32767],占空比输出时，范围[0,100],频率输出时，范围[0,2000000]
// maxValue:最大输出值，DA输出时，范围[0,32767],占空比输出时，范围[0,100],频率输出时，范围[0,2000000]
// standbyPower:待机能量,为0表示取消待机能量输出功能
// ch:激光控制通道
MTN_API short  __stdcall NMC_CrdBufLaserSetParam ( HAND crdHandle, long segment,long onDelay ,
				long offDelay, long minValue ,long maxValue,long standbyPower,short ch);

// 读取激光参数
MTN_API short  __stdcall NMC_LaserGetParam ( HAND devHandle, long *pOnDelay,
			long *pOffDelay, long *pMinValue ,long *pMaxValue,long *pStandbyPower,short ch);

// 设置缓冲区激光能量跟随
// segNo:段号
// overRide:跟随倍率,为0表示取消激光能量跟随
// followType:跟随类型,0：跟随规划速度,1：跟随实际速度
// ch:激光通道号,取值范围[0,n]
MTN_API short __stdcall NMC_CrdBufLaserSetFollow(HAND crdHandle,long segNo,double overRide,short followType,short ch);

// 设置缓冲区激光能量跟随
// powerFilter:能量输出滤波系数，取值范围[0,32]，0：不开启（默认）
// followAdvMode:能量输出计算方法
// ch:激光通道号,取值范围[0,n]
MTN_API short __stdcall NMC_LaserSetFollowParam(HAND devHandle,short powerFilter,short followAdvMode,short ch);

// 缓冲区激光开关
// segNo:段号
// onOff:开关,0：关光,1：开光
// ch:激光控制通道
MTN_API short  __stdcall NMC_CrdBufLaserOnOff ( HAND crdHandle,long segNo,short onOff,short ch);

// 缓冲区设置激光能量,激光能量跟随模式下,调用这条指令无效
// segNo:段号
// power:能量
// ch:激光控制通道
MTN_API short  __stdcall NMC_CrdBufLaserPower ( HAND crdHandle,long segNo,long power,short ch);

// 激光能量补偿数据表单方向长度最大值
#define LASER_CMP_DATA_LEN_MAX				(10)

// 设置激光能量补偿表
// tableNo： 补偿表号 ：支持20张表
// pXCmpPos：X方向轴的比较位置,长度为xCount  
// pYCmpPos: Y方向轴的比较位置,长度为yCount  
// xCount： 表X方向的长度,取值范围[2,10]
// yCount： 表Y方向的长度,取值范围[2,10]
// powerMin:	大于该最小能量才补偿
// powerMax:	小于该最大能量才补偿
// pLaserCmpPower：补偿表的值，该参数为2维数组的首地址
// chn:对应的激光通道号
MTN_API short  __stdcall NMC_SetLaserPowerCmpTable ( HAND devHandle,short tableNo,long *pXCmpPos,long *pYCmpPos,
	short xCount,short yCount, unsigned long powerMin,unsigned long powerMax,unsigned long *pLaserCmpPower,short chn);

// 启动激光能量补偿
// pAxisNo： pAxisNo[0]表X方向的位置比较轴号 pAxisNo[1]表Y方向的位置比较轴号
// chn：补偿输出给哪路激光通道
MTN_API short  __stdcall NMC_StartLaserPowerComp ( HAND devHandle,short *pAxisNo,short chn);

// 停止激光能量补偿
MTN_API short  __stdcall NMC_StopLaserPowerComp ( HAND devHandle,short chn);

// 
#define LASER_GROUP		(12)			// 最大激光能量组数
#define LASET_POINT		(40)			// 每组最大点数

typedef struct
{
	short pwmEnable;		// 是否需要输出PWM,0:立即输出一个波形，1：根据位移周期输出
	short outputType;		// 开关信号输出类型：0：gate,1：GPO
	short outputCh;			// 开关信号输出通道
	short stLevelRevs;	    // SHIO输出电平取反,默认为0，不取反
	long pwmPeriod;			// 保留,PWM周期,单位us,不能小于时间数组的总周期
	long pwmWidth;			// 保留,PWM脉宽,单位us,此参数保留,脉宽等于时间数组的总周期
    long gateDistance; 	    // 固定模式下的位置间隔 单位：pulse。
						    // 默认0,模式2~4 下会进行有效性检查
    long minFrqFrq; 	    // 保留,SHIO输出最低频率，单位HZ
    short posSrc; 		    // 比较模式,外部编码器还是内部规划值。
					        // 0：外部编码器（推荐）,1：内部规划值。
					        // 默认0。
    short axisMask; 	    // 轴号,按bit 位对应。（一般两个轴）。
						    // 默认 0。
    short minFrqEn;		    // 保留,是否启用SHIO输出最低频率，默认0，不启用
	short reserved2;	    // 保留
}TTimeArrayPara;

// 设置时间数组输出参数
// ch : 激光通道
// pPara ： 参数
// 注：1.仅时间数组输出方式下有效
MTN_API short  __stdcall NMC_LaserSetTimeArrayPara  ( HAND devHandle,TTimeArrayPara *pPara,short ch);

typedef struct
{
	unsigned short time[LASET_POINT];// 每个点之间的间隔时间,单位:100微秒
	short power[LASET_POINT];		// 各点的能量大小
	short count;					// 实际压入点数
}TLaserPower;

// 设置激光的能量,对于立即输出模式,group无效,pLaserPower为指定的单个能量信息
// group : 设置哪一组激光能量
// pLaserPower ： 设置的数据
// 注：1.即波形设置 
//     2.该接口对于SHIO模式无效
MTN_API short  __stdcall NMC_LaserSetTimeArrayPower  ( HAND devHandle,short group,TLaserPower *pLaserPower );
	
// 执行时间序列激光,只在时间序列输出模式下有效
// group : 设置哪一组激光能量
// ch:激光通道
// 注：1.启用时间数组输出后,直到最后一个点,如果最后一个点能量不为0,则维持最后一个能量输出
//    2.如果最后一个点能量为0,且没有PWM输出配合,则自动关闭激光。有PWM配合则需要调用NMC_LaserOnOff或者NMC_CrdBufLaserOnOff关闭激光
MTN_API short  __stdcall NMC_LaserTimeArrayExe  (HAND devHandle, short group,short ch );

// 缓冲区执行时间序列激光,只在时间序列输出模式下有效
// segNo:段号
// group:设置哪一组激光能量
// ch:激光控制通道
// 注：1.启用时间数组输出后,直到最后一个点,如果最后一个点能量不为0,则维持最后一个能量输出
//    2.如果最后一个点能量为0,且没有PWM输出配合,则自动关闭激光。有PWM配合则需要调用NMC_LaserOnOff或者NMC_CrdBufLaserOnOff关闭激光
MTN_API short  __stdcall NMC_CrdBufLaserTimeArrayExe ( HAND crdHandle,long segNo,short group,short ch);

typedef struct
{
	short isArray; 		// 是否固定间距还是数组。0：固定间距（仅支持）,默认0
	short outMode; 		// 输出模式。默认1
						// 1：只输出gate 立即开或关,
						// 2: 根据位移输出gate
						// 3: 根据位移输出gate,gate 和同部trigger 信号同步
						// 4: 根据位移输出gate,gate 和信号输入同步
	short posSrc; 		// 比较模式,外部编码器还是内部规划值。
						// 0：外部编码器（推荐）,1：内部规划值。
						// 默认0。
	short axisMask; 	// 轴号,按bit 位对应。（一般两个轴）。
						// 默认 0。
	double delay; 		// 延时开关光时间( 暂不用 ),单位：s。默认 0。
	double gateTime; 	// 设置gate 打开时间,单位：s（内部最小值：1/36us ）,取值范围(0,0.0009)
						// 默认0。
	long gateDistance; 	// 固定模式下的位置间隔 单位：pulse。
						// 默认0,模式2~4 下会进行有效性检查。
    long k;				// 低频过渡系数          
	long startDot; 	    // 启动时出光打点
	long lowFrqRange; 	// 低频范围：0:100K,1:1M
	short outType;		// 输出类型：0-Gate，1-GPO
	short outIndex;		// 输出通道，取值[0,19]
	long reserved5; 	// 保留参数,应设为0。
}TSHIOPara;

// 配置SHIO功能的参数
MTN_API short  __stdcall NMC_SHIOConfigPara  (HAND devHandle, TSHIOPara *pSHIOPara,short ch);

// SHIO输出的最小频率功能开
// minFrq:最低频率，单位HZ
MTN_API short  __stdcall NMC_SHIOEnableMinFrq  (HAND devHandle,long minFrq,short ch);

// SHIO输出的最小频率功能关闭
MTN_API short  __stdcall NMC_SHIODisableMinFrq  (HAND devHandle,short ch);

// 缓冲区配置SHIO功能的参数
MTN_API short  __stdcall NMC_CrdBufSHIOConfigPara  (HAND crdHandle, long segment, TSHIOPara *pSHIOPara,short ch);

// 缓冲区SHIO输出的最小频率功能开
// minFrq:最低频率，单位HZ
MTN_API short  __stdcall NMC_CrdBufSHIOSetMinFrq(HAND crdHandle, long segment, long minFrq,short ch);

// 缓冲区SHIO输出的最小频率功能关闭
MTN_API short  __stdcall NMC_CrdBufSHIOClrMinFrq (HAND crdHandle, long segment,short ch);

// 缓冲区配置SHIO功能的参数
// delay:延时开关光时间( 暂不用 ),单位：s。默认 0。
// gateTime:设置gate 打开时间,单位：s（内部最小值：1/36us ）,取值范围(0,0.0009),默认0。
// gateDistance:固定模式下的位置间隔 单位：pulse。
MTN_API short  __stdcall NMC_CrdBufSHIOSetParam  (HAND crdHandle, long segment,double delay,
	double gateTime,double gateDistance,short ch);

// 切换轴（允许和坐标系不完全一致）
MTN_API short  __stdcall NMC_SHIOChangeAxisMask( HAND devHandle, short axisMask,short ch );

// 切换轴（允许和坐标系不完全一致）,缓冲区指令
MTN_API short  __stdcall NMC_CrdBufSHIOChangeAxisMask( HAND crdHandle, long segment, short axisMask,short ch );

// 允许GATE输出
// 注：设置后根据模式输出
MTN_API short  __stdcall NMC_SHIOGateOn ( HAND devHandle ,short ch);

// 禁止GATE输出
// 注：设置后立即禁止输出
MTN_API short  __stdcall NMC_SHIOGateOff ( HAND devHandle ,short ch);

// 设置Trigger 输出,
// triggerFreq : 设置triger 脉冲频率单位：HZ。
// triggerWidth : 设置triger 脉冲宽度,单位：s（内部最小值：1/36us ）。默认0。
// 注：设置后立即输出
MTN_API short __stdcall NMC_SHIOTriggerOn ( HAND devHandle,double freq,double width ,short ch);

// 禁止GATE输出
// 注：设置后马上输出
MTN_API short  __stdcall NMC_SHIOTriggerOff ( HAND devHandle ,short ch);

// 允许GATE输出
// 注：设置后根据模式输出
MTN_API short  __stdcall NMC_BufSHIOGateOn ( HAND crdHandle, long segNo,short ch);

//禁止GATE输出
//注：缓冲区执行到该指令后立即禁止输出
MTN_API short  __stdcall NMC_BufSHIOGateOff ( HAND crdHandle, long segNo,short ch);

// PWM映射到GATE引脚输出
// pwmCh:pwm 通道号
// gateCh:gate信号通道号
// onOff: 0 -- 不映射，1 -- 映射 （默认为0）
MTN_API short  __stdcall NMC_SetPwmToGate (HAND devHandle, short pwmCh,short gateCh,short onOff);

// 缓冲区SHIO点动出光，输出一段gate脉冲,注意：必须在激光SHIO控制模式下使用
// gateTime:gate输出的脉宽，单位：微秒
// gateFrq:gate输出的频率，单位：HZ
// outCount:输出个数
// ch:通道
MTN_API short  __stdcall NMC_CrdBufSHIOGatePulse ( HAND crdHandle,long segNo,double gateTime, 
	double gateFrq,long outCount,short ch);

// SHIO点动出光，输出一段gate脉冲,注意：必须在激光SHIO控制模式下使用
// gateTime:gate输出的脉宽，单位：微秒
// gateFrq:gate输出的频率，单位：HZ
// outCount:输出个数
// ch:通道
MTN_API short  __stdcall NMC_SHIOGatePulse ( HAND devHandle,double gateTime, double gateFrq,long outCount,short ch);

// 输出一段PWM脉冲,注意：必须在激光SHIO控制模式下使用
// onTime:PWM输出的脉宽，单位：微秒
// pwmFrq:PWM输出的频率，单位：HZ
// outCount:输出个数
// ch:通道
MTN_API short  __stdcall NMC_PwmPulseOut ( HAND devHandle,double onTime, double pwmFrq,long outCount,short ch);

//------------------------------------------------------------------------------------------------------------
//
//	9.龙门
//
//------------------------------------------------------------------------------------------------------------
// 设置龙门主动轴
// axisHandle: 龙门主动轴句柄
// group     : 龙门组号,取值范围[0,n]
MTN_API short __stdcall NMC_SetGantryMaster( HAND axisHandle, short group );

// 设置龙门从动轴
// axisHandle  : 龙门从动轴句柄;
// group       : 龙门组号,取值范围[0,n]
// gantryErrLmt: 龙门保护误差,取值范围(0,...)
MTN_API short __stdcall NMC_SetGantrySlave( HAND axisHandle , short group, long gantryErrLmt );

// 龙门功能关闭
// group :       龙门组号,取值范围[0,n]
MTN_API short __stdcall NMC_DelGantryGroup( HAND axisHandle, short group );

//------------------------------------------------------------------------------------------------------------
//
//	10.通讯扩展等其他
//
//------------------------------------------------------------------------------------------------------------
// 通讯扩展
// 用户指令传输,只写
MTN_API short  __stdcall NMC_UserCmdWrite( HAND devHandle, unsigned char *sendBuffer, unsigned long sendLen );

// 用户指令传输,只读
MTN_API short  __stdcall NMC_UserCmdRead( HAND devHandle, unsigned char *sendBuffer, 
	unsigned long sendLen, unsigned char *recBuffer, unsigned long waitLen );

// 批量数据传输,只写
MTN_API short  __stdcall NMC_DataTransfer( HAND devHandle, unsigned char *sendBuffer, unsigned long sendLen );		

// 禁止用户程序运行
MTN_API short __stdcall NMC_SysSetUserApp   ( HAND devHandle, unsigned char mode );

// 升级
MTN_API short __stdcall NMC_SysUpgrade   ( HAND devHandle );

// 升级固件
MTN_API short __stdcall NMC_SysUpgradeEx( HAND devHandle, unsigned char cmd, 
	unsigned char *sendBuffer, unsigned long sendLen, unsigned char *recBuffer, unsigned long recvedLen );

// 设置调试信息
MTN_API short __stdcall NMC_SetDebugErrorEn(  HAND devHandle, short debugErrEn );

// 读取最后一次的错误代码
// 返回值：错误代码
MTN_API short __stdcall NMC_GetLastErr(void);

// 设置指令错误返回值模式
// mode:0-标准模式,将返回详细的错误代码(默认)；1--简洁模式,只返回错误代码类别
MTN_API short __stdcall NMC_SetErrCodeMode(short mode);

// 设置指令通讯看门狗
// timeout:看门狗超时时间,单位毫秒,小于等于0代表关闭看门狗功能
// stopMode:超时停止模式,1:马上停止,0:缓冲区执行完毕后停止
// groupID:超时输出do的组号
// doValue:超时输出do状态
MTN_API short __stdcall NMC_SetWatchDog(HAND devHandle,long timeout,short stopMode,short groupID,long doValue);

//------------------------------------------------------------------------------------------------------------
//
//	11.手轮
//
//------------------------------------------------------------------------------------------------------------
// 退出手轮
MTN_API short __stdcall NMC_ClrHandWheel(HAND devHandle);

// 启动手轮
// axis:轴号,取值范围[0,n]
// ratio:跟随倍率,取值范围(0,..],数值越大,则同样的输入,跟随轴运动距离越长
// acc:跟随的加速度
// vel:跟随的速度
// 注：编码器信号源为控制器上手脉端口
MTN_API short __stdcall NMC_SetHandWheel(HAND devHandle,short axis,double ratio,double acc,double vel);


// 选择手轮跟随的编码器通道
// index:编码器通道编号,如果是轴通道,取值范围[0,n]
//                    如果是扩展编码器通道,则256表示第一个扩展编码器通道,257表示第二个,以此类推
MTN_API short __stdcall NMC_SetHandWheelInput(HAND devHandle,short index);

// 设置手轮跟随的倍率
// ratio:跟随倍率,取值范围(0,..]
MTN_API short __stdcall NMC_SetHandWheelRatio(HAND devHandle,double ratio);


//------------------------------------------------------------------------------------------------------------
//
//	12.PT
//
//------------------------------------------------------------------------------------------------------------
// 单轴PT运动参数结构
typedef struct
{
    double smoothDec;		// 停止减速度
    double abruptDec;		// 急停减速度，暂时保留
    double reserved1[2];	// 保留
    long reserved2[4];      // 保留
}TPtPara;
// 设置PT运动的相关参数 
// pPara：参数,参考结构定义
MTN_API short __stdcall NMC_MtPtSetPara( HAND axisHandle, TPtPara *pPara );

// onOff:		1：数据驻存模式   0：数据刷新模式(默认模式)
// loopCount:	循环次数 ：仅数据驻存模式下有效
MTN_API short  __stdcall NMC_MtPtSetStatic(HAND axisHandle,short onOff,long loopCount);

// onOff:		1：数据驻存模式   0：数据刷新模式(默认模式)
// loopCount:	循环次数 ：仅数据驻存模式下有效
MTN_API short  __stdcall NMC_MtPtGetStatic(HAND axisHandle,short *pOnOff,long *pLoopCount);

// 查询PT数据剩余空间大小
// pSpace:返回的剩余空间大小
// pUsed: 已使用的空间段数
MTN_API short  __stdcall NMC_MtPtGetSpace(HAND axisHandle,short *pSpace,short *pUsed);


// PT数据段类型
#define MT_PT_NORMAL	(0)
#define MT_PT_STOP		(1)
#define MT_PT_EVEN		(2)

// 向Pt运动缓存区中压运动数据段
// count:压入的数据段数
// pPosArray:段运行距离
// pTimeArray:段运行时间
// pTypeArray:段类型,见宏定义
MTN_API short  __stdcall NMC_MtPtPush(HAND axisHandle,short count,double *pPosArray,long *pTimeArray,short *pTypeArray);

// 清空PT数据
MTN_API short  __stdcall NMC_MtPtBufClr(HAND axisHandle);

// 启动Pt运动
// otherSynAxCnts： 不包括axisHandle 的其他同步启动轴数量
// pOtherSynAxArray: 其他同步启动轴的序号：0~N	
// 注：同步的轴必须属于同一个控制器
MTN_API short  __stdcall NMC_MtPtStartMtn(HAND axisHandle,short otherSynAxCnts,short *pOtherSynAxArray);


//-------------------------------------------------------------------------------
// 13.线性距离位置比较
//-------------------------------------------------------------------------------

// 精确输出结构体
typedef struct
{
	short dimens;
	short compMode;
	short axMask;       
	short src;
	double gateTime;
}TLinearCmpPara;


// 功能：设置精确位置比较的参数，并清除线性位置比较位置数据
// dimens:比较的维数 1或者2
// axisMask：选比较的轴号,按bit选择:不能超过2个bit同时为1
// src：比较源：1:编码器位置  0：规划位置
// cmpMode：比较的模式：0 按输出数组位置比较,1 线性比较,按interval间距比较
// gateTime:输出的脉冲宽度
// chn：输出通道 目前只支持0
MTN_API short __stdcall NMC_LinearCompSetParam(HAND devHandle,short dimens, short axisMask,short src,short cmpMode,double gateTime,short chn);


// 获取配置参数
MTN_API short __stdcall NMC_LinearCompGetParam(HAND devHandle,TLinearCmpPara *pLinearCmpPara,short chn);


// 功能：设置精确比较位置数据
// pStartPos：起始比较位置，注意：暂时没用
// pPos :比较的位置数组地址。
//		 注意：这里为相对距离，第一点为相对于NMC_LinearCompOnOff调用时的位置的距离，第二点为相对第一点的距离
// count：比较的位置个数，最大不能超过250，如果比较数据过多，可以通过多次调用的方式下压数据，缓冲区长度
// chn：输出通道 目前只支持0
MTN_API short __stdcall NMC_LinearCompSetData(HAND devHandle,long *pStartPos,long *pPos,long count, short chn);


// 功能：线性比较输出
// pStartPos：起始比较位置
// interval:线性比较间距（小于32767）
// count: 线性比较次数
MTN_API short __stdcall NMC_LinearCompInterval(HAND devHandle,long *pStartPos,long interval,long count, short chn);


// 功能：精确位置比较使能
// onOff： 0 停止,1输出
// chn：输出通道 目前只支持0
MTN_API short __stdcall NMC_LinearCompOnOff(HAND devHandle,short onOff, short chn);


// 功能：比较的输出状态
// pStatus: 0 未启动比较 1 比较输出中
// pOutCount：输出的个数,对于数组输出模式，输出计数计算请咨询我们
// chn：输出通道 目前只支持0
MTN_API short __stdcall NMC_LinearCompStatus(HAND devHandle,short *pStatus, short *pOutCount,short chn);

//-------------------------------------------------------------------------------
//14.二维位置点比较
//-------------------------------------------------------------------------------
#define CMP_OUTPUT_CHN_MAX	(3)

// 二维位置点比较结构体
typedef struct
{
	short outputchn[CMP_OUTPUT_CHN_MAX];		// 比较输出的通道:-1表示不输出处理
	short outputType[CMP_OUTPUT_CHN_MAX]; 		// 输出方式0：脉冲1：电平
	short chnType[CMP_OUTPUT_CHN_MAX];      	// 通道类型：0 GPO, 1  GATE通道
	short dir1No; 								// 方向1 的位置源轴号（0~11）
	short dir2No; 								// 方向2 的位置源轴号（0~11）
	short posSrc; 								// 轴位置类型 ：0规划1：编码器
	short stLevel[CMP_OUTPUT_CHN_MAX];			// 电平模式下的起始电平（0或1）
	short gateTime[CMP_OUTPUT_CHN_MAX]; 		// 脉冲方式脉冲时间:单位ms
	short errZone; 								// 进入比较点容差半径范围（pulse）
} TComp2DimensParam;

// 功能：设置2维位置比较的参数
// param: 二维比较参数
// group:组号,0 或者1
// chn:保留,设为0
MTN_API short __stdcall NMC_Comp2DimensSetParam(HAND devHandle,short group,TComp2DimensParam *param,short chn);

// 功能：获取2维位置比较的参数
// param: 二维比较参数
// group:组号,0 或者1
// chn:保留,设为0
MTN_API short __stdcall NMC_Comp2DimensGetParam(HAND devHandle,short group,TComp2DimensParam *param,short chn);

// 高速二维位置点比较结构体
typedef struct
{
	short outputChn;							// 比较输出的通道号，取值[0,n]
	short outputType; 							// 输出方式0：脉冲1：电平
	short chnType;      						// 通道类型：0 GPO, 1  GATE通道
	short dir1No; 								// 方向1 的位置源轴号（0~11）
	short dir2No; 								// 方向2 的位置源轴号（0~11）
	short posSrc; 								// 轴位置类型 ：0规划1：编码器
	short stLevel;								// 电平模式下的起始电平（0或1）
	short errZone; 								// 进入比较点容差半径范围（pulse）
	short  directOutZone;						// 近距离直接触发范围
	short  vibrateRange;						// 抖动滤波范围	
	long gateTime; 								// 脉冲方式脉冲时间,单位us
	long minIntervalTime;						// 最小触发时间间隔,单位us
	long reserved[8];							// 保留，默认值 0（不使用）
} TComp2DimensParamEx;

// 功能：设置2维位置比较的参数
// param: 二维比较参数
// group:组号,0 或者1
// chn:保留,设为0
MTN_API short __stdcall NMC_Comp2DimensSetParamEx(HAND devHandle,short group,TComp2DimensParamEx *param,short chn);

// 功能：读取2维位置比较的参数
MTN_API short __stdcall NMC_Comp2DimensGetParamEx(HAND devHandle,short group,TComp2DimensParamEx *param,short chn);


// 功能：设置二维比较数据
// pArrayPos:比较数组地址
// count:位置点数,count=0表示清除已经缓存的数据。一次性最多压入128组数据
// group:组号,0 或者1
// chn:保留,设为0
MTN_API short __stdcall NMC_Comp2DimensSetData(HAND devHandle,short group,long *pArrayPos,short count,short chn);

// 功能：2维位置比较使能
// onOff： 0 停止,1输出 2手动
// group:组号,0 或者1
// chn:保留,设为0
MTN_API short __stdcall NMC_Comp2DimensOnoff(HAND devHandle,short group,short onOff,short chn);


// 功能：2维位置比较的输出状态
// pStatus: 0 未启动比较 1 比较输出中
// pOutCount：输出的个数
// group:组号,0 或者1
// chn:保留,设为0
MTN_API short __stdcall NMC_Comp2DimensStatus(HAND devHandle,short group,short *pStatus, short *pOutCount,short chn);

typedef struct
{
	short sts;				// 运行状态，0 空闲 1 忙
	short reserved1;		// 保留
	long freeSpace;			// 控制器剩余空间
	long usedSpace;			// 剩余位置比较点
	long outCount;			// 已经输出的个数
	long reserved2[4];		// 保留
} TComp2DimensSts;

// 功能：2维位置比较的输出状态
// pStatus: 状态结构体
// group:组号,0 或者1
// chn:保留,设为0
MTN_API short __stdcall NMC_Comp2DimensStatusEx(HAND devHandle,short group,TComp2DimensSts *pStatus,short chn);


//-------------------------------------------------------------------------------
//15.多维位置比较输出通用接口
//-------------------------------------------------------------------------------
// X维位置点比较结构体
typedef struct
{
	short dimens; 		                    // 维度
	short axMask;                           // 使用的轴,按位
	short src; 		                        // 轴位置类型 ：0规划1：编码器

	short outCnts; 							// 输出数量
	short outType[CMP_OUTPUT_CHN_MAX]; 		// 输出方式0：脉冲1：电平
	short outChnType[CMP_OUTPUT_CHN_MAX];	// 通道类型：0 GPO, 1  GATE通道
	short outIndex[CMP_OUTPUT_CHN_MAX];     // GPO：0~63  GATE：0
	short outStLevel[CMP_OUTPUT_CHN_MAX];   // 电平模式下的起始电平（0或1）
	short outGateTime[CMP_OUTPUT_CHN_MAX]; 	// 脉冲模式下的脉冲时间:单位ms
	short errZone; 							// 进入比较点容差半径范围（pulse）
} TCompXDimensParam;

// 功能：设置X维位置比较的参数
// param: X维比较参数
// ch:组号,0~2
MTN_API short __stdcall NMC_CompXDimensSetParam(HAND devHandle,TCompXDimensParam *param,short chn);

// 功能：获取X维位置比较的参数
// param: 二维比较参数
// chn:组号
MTN_API short __stdcall NMC_CompXDimensGetParam(HAND devHandle,TCompXDimensParam *param,short chn);

// 功能：设置X维位置比较的输出模式
// outMode: 输出模式 0：同时输出模式 1： 轮循输出模式
// ch:组号,0~N
MTN_API short __stdcall NMC_CompXDimensSetCmpOutMode(HAND devHandle,short outMode ,short chn);

// 功能：设置X维比较数据
// pArrayPos:比较数组地址,注：若是1维比较,则pPosArray传入一维数组地址,若是2维比较,则pPosArray应传入2维数组地址
// outValue
// count:位置点数,注：若为2维数组比较时,每两个数据为一个点数
// ch:组号,0~N
// 注：按结构体定义的IO,同时输出
MTN_API short __stdcall NMC_CompXDimensSetData(HAND devHandle, long *pPosArray, short count, short chn);

// 功能：X维位置比较使能
// onOff： 0 停止,1输出
// chn： 组号
MTN_API short __stdcall NMC_CompXDimensOnoff(HAND devHandle,short onOff, short chn);

// 功能：X维位置比较的输出状态
// pStatus: 0 未启动比较 1 比较输出中
// pOutCount：输出的个数
// chn：组号
MTN_API short __stdcall NMC_CompXDimensStatus(HAND devHandle,short *pStatus, short *pOutCount,short chn);

//-------------------------------------------------------------------------------
//16.坐标系输出转换（根据机械结构进行转换）
//-------------------------------------------------------------------------------
// 功能：使能旋转转换处理
//       用户数据是按照直角坐标描述,实际加工在一个旋转面上加工,可以用此功能
// rotAxisNo：旋转轴轴号
// angleRadEqual：旋转轴脉冲转弧度系数
// firstAxisInitPos：旋转中心,X轴的位置
// secAxisInitPos：旋转中心,Y轴的位置
MTN_API short  __stdcall NMC_CrdSetTransRotate(HAND crdHandle,short rotAxisNo,
								double angleRadEqual,long firstAxisInitPos,long secAxisInitPos);

// 功能：关闭旋转转换处理
MTN_API short  __stdcall NMC_CrdDelTransRotate(HAND crdHandle);

// 功能：使能极坐标转换处理
//       用户数据是按照直角坐标描述,实际机械机构是一个旋转轴和一个进给轴
//参数：	rotAxNo：旋转轴轴号
//		transAxNo：平移轴轴号
//		rotEquiv：旋转轴当量,2PI/电机一圈脉冲数
MTN_API short  __stdcall NMC_CrdSetTransPolar(HAND crdHandle, short rotAxNo,short transAxNo, double rotEquiv);

// 功能：运行至设定的极坐标位置并且进行圈数清零处理（利用单轴PTP运行到指定位置）
//参数：	xPos:极坐标系下X方向位置
//		yPos:极坐标系下Y方向位置,比如运动到（5000,5000）的位置,则相当于旋转轴转到45度角,进给轴运动到根号2*5000的位置
//		rotVel:旋转速度
//		transVel:进给速度
MTN_API short  __stdcall NMC_CrdRunToPolarPos(HAND crdHandle,double xPos,double yPos,double rotVel,double transVel);

// 功能：运行至设定的极坐标角度位置（利用单轴PTP运行到指定位置）
//参数：	theta:旋转轴目标角度
//				vel:旋转速度
//				clrRoundFlag:是否清除圈数
MTN_API short  __stdcall NMC_CrdRunToPolarTheta(HAND crdHandle,double theta,double vel,short clrRoundFlag);

// 功能：销毁极坐标机型（只恢复直角坐标系）
MTN_API short  __stdcall NMC_CrdDelTransPolar(HAND crdHandle);

// XYZA机型设置接口
// 设置XYZA的映射轴号
// pAxisMapArray[0]~[3]分别对应X、Y、Z和A
MTN_API short  __stdcall NMC_CrdSetTransXYZA(HAND crdHandle, short *pAxisMapArray );

// 销毁XYZA机型，回归XYZ结构
MTN_API short  __stdcall  NMC_CrdDelTransXYZA(HAND crdHandle);

// 求工具参数
// deltaTheta：从0°往正方向旋转过的角度值
// deltaX：旋转deltaTheta角度后，重新校正到同一点位置后，X轴的相对移动量
// deltaY：旋转deltaTheta角度后，重新校正到同一点位置后，Y轴的相对移动量
// pToolX: 工具的X值
// pToolY: 工具的Y值
MTN_API short  __stdcall NMC_CrdSetXYZAToolCalc(HAND crdHandle, double 	deltaTheta,long deltaX,long deltaY,long *pToolX,long *pToolY );


// 设置XYZA机型参数
// pulse2Rad: A轴的每个脉冲对应的弧度值
// toolX：工具的X值
// toolY: 工具的Y值
MTN_API short  __stdcall NMC_CrdSetXYZAPara(HAND crdHandle, double	pulse2Rad,long toolX,long toolY );

// 设置XYZA机型参数
// pPulse2Rad:A轴的每个脉冲对应的弧度值
// pToolX:工具的X值
// pToolY:工具的Y值
MTN_API short  __stdcall NMC_CrdGetXYZAPara(HAND crdHandle, double	*pPulse2Rad,long *pToolX,long *pToolY );

// 设置压入插补数据的位置是否需要关节到笛卡尔的坐标转换
MTN_API short __stdcall NMC_CrdSetXYZAJointTransCrdPos( HAND crdHandle, short isTrans );

//-------------------------------------------------------------------------------
//17.结构体初始化函数
//-------------------------------------------------------------------------------
MTN_API short  __stdcall NMC_TSafeParaStructInit(HAND devHandle,TSafePara *pPara);
MTN_API short  __stdcall NMC_TCrdConfigStructInit(HAND devHandle,TCrdConfig *pPara);
MTN_API short  __stdcall NMC_TCrdSafeParaStructInit(HAND devHandle,TCrdSafePara *pPara);
MTN_API short  __stdcall NMC_THomeSettingStructInit(HAND devHandle,THomeSetting *pPara);
MTN_API short  __stdcall NMC_TArcSecSettingStructInit(HAND devHandle,TArcSecSetting *pPara);
MTN_API short  __stdcall NMC_TCrdParaStructInit(HAND devHandle,TCrdPara *pPara);
MTN_API short  __stdcall NMC_TCollectCfgStructInit(HAND devHandle,TCollectCfg *pPara);
MTN_API short  __stdcall NMC_TCollectTrigStructInit(HAND devHandle,TCollectTrig *pPara);
MTN_API short  __stdcall NMC_TTimeArrayParaStructInit(HAND devHandle,TTimeArrayPara *pPara);
MTN_API short  __stdcall NMC_TLaserPowerStructInit(HAND devHandle,TLaserPower *pPara);
MTN_API short  __stdcall NMC_TSHIOParaStructInit(HAND devHandle,TSHIOPara *pPara);
MTN_API short  __stdcall NMC_TLinearCmpParaStructInit(HAND devHandle,TLinearCmpPara *pPara);
MTN_API short  __stdcall NMC_TComp2DimensParamStructInit(HAND devHandle,TComp2DimensParam *pPara);
MTN_API short  __stdcall NMC_TPtpParaStructInit(HAND devHandle,TPtpPara *pPara);
MTN_API short  __stdcall NMC_TJogParaStructInit(HAND devHandle,TJogPara *pPara);
MTN_API short  __stdcall NMC_TNMCTimeStructInit(HAND devHandle,TNMCTime *pPara);

// 清除轴错误状态,同时多个
MTN_API short  __stdcall NMC_MtClrErrorEx(HAND axisHandle,short count);

// 输出DO,16位
// bitsFlag,0:低16位,1：高16位
MTN_API short  __stdcall NMC_SetDOGroupEx( HAND devHandle, long value, short groupID,short bitsFlag) ;

//-------------------------------------------------------------------------------
//18.闭环
//-------------------------------------------------------------------------------

// PID参数
typedef struct
{
    float kp;											// 增益系数
    float ki;											// 积分系数
    float kd;											// 微分系数
    float kvff;											// 速度前馈系数
    long integralLimit;                                 // 积分饱和极限
    long derivativeLimit;                               // 微分饱和极限
    short outLimit;                                     // 输出饱和极限
} TPidPara;

// Dac参数
typedef struct
{
	short inverse;			// 电压是否取反
	short bias;				// Dac零漂
	short dacLmt;			// Dac输出极限值
}TDacMotor;

// 设置单轴闭环控制的DA参数,轴与DA通道的对应
MTN_API short  __stdcall NMC_MtSetCloseLoopDac (HAND axisHandle,TDacMotor *pDacPara);

// 获取单轴闭环控制的DA参数
MTN_API short  __stdcall NMC_MtGetCloseLoopDac (HAND axisHandle,TDacMotor *pDacPara);

// 设置单轴的控制模式：默认使用对应轴的编码器作为输入反馈,对应序号的DAC作为输出
// 闭环模式下,先调用NMC_SetCloseLoopDac指令
//mode: 0 脉冲控制  1 DA闭环控制，默认为脉冲控制
MTN_API short  __stdcall NMC_MtSetCtrlMode(HAND axisHandle,short mode);

// 读取单轴的控制模式
MTN_API short  __stdcall NMC_MtGetCtrlMode(HAND axisHandle,short *pMode);


//设置对应组号的PID参数
MTN_API short  __stdcall NMC_MtSetPIDPara(HAND axisHandle,short index, TPidPara *pidPara);

// 获取对应组号的PID参数
MTN_API short  __stdcall NMC_MtGetPIDPara(HAND axisHandle,short index, TPidPara *pPidPara);

// 设置使用哪组PID
MTN_API short  __stdcall NMC_MtSetPIDIndex(HAND axisHandle,short index);

// 获取正使用的PID组号
MTN_API short  __stdcall NMC_MtGetPIDIndex(HAND axisHandle,short *pIndex);

//-------------------------------------------------------------------------------
//19.高级BufIo输出配置及控制
//-------------------------------------------------------------------------------
// BufIo输出最大组数
#define MAX_ADV_BUFIO_GROUP	2

// 高级BufIo输出参数
typedef struct
{
	// 输出点
	short outType;				// 输出类型，0：通用输出；1：Gate信号；其他保留
	short outGroup;				// 输出组，取值范围[0,n]
	short outIndex;				// 输出序号，取值范围[0,n]
	short outSns;				// 有效电平,0:低电平有效，1：高电平
	
	// 信号
	short pulseMode;		// 0：电平输出，1：脉冲输出
	short reserved1;		// 保留
	long  pulseOnTime;		// 有效电平时间（脉冲输出方式下有效），单位：微秒
	long  pulseOffTime;		// 无效电平时间（脉冲输出方式下有效），单位：微秒
	
	unsigned char reserved[32];	// 保留
}TAdvBufIoParam;

// 设置BufIo输出参数
MTN_API short  __stdcall NMC_AdvBufIoSetParam(HAND devHandle,TAdvBufIoParam *pPrm,short ch);

// 读取BufIo输出参数
MTN_API short  __stdcall NMC_AdvBufIoGetParam(HAND devHandle,TAdvBufIoParam *pPrm,short ch);

// 缓冲区设置高级BufIo输出有效（运动一段距离后输出特定状态）
// outLength:距离，单位：脉冲
// value: 脉冲模式下输出脉冲个数，电平方式下无意义。
// ch:输出组，取值范围：[0,MAX_ADV_BUFIO_GROUP)
MTN_API short  __stdcall NMC_CrdAdvBufIoOnAfterLen(HAND crdHandle,long segNo,
	long outLength,long value,short ch);

// 缓冲区设置高级BufIo关闭输出（缓冲区全部运动结束前提前一段距离输出特定状态）
// outLength:距离，单位：脉冲
// ch:输出组，取值范围：[0,MAX_ADV_BUFIO_GROUP)
MTN_API short  __stdcall NMC_CrdAdvBufIoOffBeforeLen(HAND crdHandle,long segNo,long outLength,short ch );
	
// 立即设置高级BufIo输出
// value: 脉冲模式下输出脉冲个数，电平方式下0:关闭，1:打开。
// ch:输出组，取值范围：[0,MAX_ADV_BUFIO_GROUP)
MTN_API short  __stdcall NMC_AdvBufIoOut(HAND devHandle,long value,short ch);

// 读取BufIo的输出数量
// pOutCout:输出脉冲个数
// ch:输出组，取值范围：[0,MAX_ADV_BUFIO_GROUP)
MTN_API short  __stdcall NMC_AdvBufIoGetPulseCnt(HAND devHandle,long *pOutCout,short ch);

// DO脉冲输出最大通道数
#define MAX_NUM_DOBIT_PULSE		4

// DO脉冲输出
// doType:DO类型,0：通用输出；其他保留
// doIndex:DO序号，取值范围[0,n]
// highLevelTime:高电平宽度，单位:us
// lowLevelTime:低电平宽度，单位:us
// outCount:输出脉冲个数
// firstLevel:0：先输出低电平，1：先输出高电平
// ch:输出脉冲通道号,取值范围:[0,MAX_NUM_DOBIT_PULSE-1]
MTN_API short  __stdcall NMC_DoBitPulseEnable(HAND devHandle,short doType,short doIndex,
	long highLevelTime,long lowLevelTime,long outCount,short initialLevel,short ch);

// 关闭DO脉冲输出
MTN_API short  __stdcall NMC_DoBitPulseDisable(HAND devHandle,short ch);

// DO脉冲输出 （缓冲区）
MTN_API short  __stdcall NMC_CrdBufDoBitPulseEnable(HAND crdHandle, long segNo,short doType,short doIndex,
	long highLevelTime,long lowLevelTime,long outCount,short initialLevel,short ch);

// 关闭DO脉冲输出（缓冲区）
MTN_API short  __stdcall NMC_CrdBufDoBitPulseDisable(HAND crdHandle, long segNo,short ch);

//-------------------------------------------------------------------------------
//20.模拟量控制
//-------------------------------------------------------------------------------

// 设置DAC（模拟量输出）通道的模式
// ch:模拟量通道号,取值范围[0,n]
// mode:模拟量输出范围,0:0~5V, 1:0~10V, 2: 0~10.8V, 3:+/-5V, 4:+/-10V, 5:+/-10.8V,其他无效，默认为4
MTN_API short __stdcall NMC_SetDacMode(HAND devHandle,short ch, short mode);

// 读取DAC（模拟量输出）通道的模式
// ch:模拟量通道号,取值范围[0,n]
// pMode:返回的模拟量输出范围设定值
MTN_API short __stdcall NMC_GetDacMode(HAND devHandle,short ch,short *pMode);

// 设置Adc参数
// ch:模拟量通道号,0~7表示轴通道上的AD，256：表示扩展AD
// mode:模拟量范围,0:0~5V, 1:0~10V, 2: 0~10.8V, 3:+/-5V, 4:+/-10V, 5:+/-10.8V,默认为4
// 注意：目前只支持+/-10V
// filterCoe:滤波系数，取值范围[0,64],0表示取消Adc滤波，单位:ms，默认值为0
MTN_API short __stdcall NMC_SetAdcMode(HAND devHandle,short ch,short range,short filterCoe);

// 读取Adc参数
// ch:模拟量通道号,0~7表示轴通道上的AD，256：表示扩展AD
// pMode:模拟量范围
// pFilterCoe:滤波系数
MTN_API short __stdcall NMC_GetAdcMode(HAND devHandle,short ch,short *pRange,short *pFilterCoe);

// 设置DAC（模拟量输出）输出值
// ch:模拟量通道号,取值范围[0,n]
// dacValue:模拟量输出值,取值范围[-32768,32767],对应DAC输出范围
MTN_API short __stdcall NMC_SetDac(HAND devHandle,short ch,short dacValue);

// 读取DAC（模拟量输出）输出值
// ch:模拟量通道号,取值范围[0,n]
// pDacValue:返回模拟量输出值,取值范围[-32768,32767],对应DAC输出范围
MTN_API short __stdcall NMC_GetDac(HAND devHandle,short ch,short *pDacValue);

// 读取ADC（模拟量输入）值
// ch:模拟量通道号,取值范围[0,n]
// pAdcValue:返回模拟量输入值，取值范围[-32768,32767],对应Adc输入电压范围
MTN_API short __stdcall NMC_GetAdc(HAND devHandle,short ch,short *pAdcValue);

// 设置模拟量输出的偏移值
// ch:模拟量通道号，[0,n]表示本地,[256,n]表示扩展模拟量通道
// bias:DAC输出偏移值
MTN_API short  __stdcall NMC_SetDacBias(HAND devHandle,short ch,short bias);

// 读取模拟量输出的偏移值
// ch:模拟量通道号，[0,n]表示本地,[256,n]表示扩展模拟量通道
// pBias:DAC输出偏移值
MTN_API short  __stdcall NMC_GetDacBias(HAND devHandle,short ch,short *pBias);

// 设置模拟量输出的极限值
// ch:模拟量通道号，[0,n]表示本地,[256,n]表示扩展模拟量通道
// maxVal:输出最大值
// minVal:输出最小值
MTN_API short  __stdcall NMC_SetDacLmt(HAND devHandle,short ch,short maxVal,short minVal);

// 读取模拟量输出的极限值
// ch:模拟量通道号，[0,n]表示本地,[256,n]表示扩展模拟量通道
// pMaxVal:输出最大值
// pMinVal:输出最小值
MTN_API short  __stdcall NMC_GetDacLmt(HAND devHandle,short ch,short *pMaxVal,short *pMinVal);

//-------------------------------------------------------------------------------
//21.scara
//-------------------------------------------------------------------------------
// 相关结构体
typedef struct
{
    double arm1Len;         // 杆1长，单位是用户单位
    double arm2Len;         // 杆2长，单位是用户单位
    double pitch;           // Z轴的丝杆节距，单位是用户单位
    double reserved[16];    // 保留，设置为0
}TScaraMechPara;

typedef struct
{
    long encBits;          // 关节的电机一圈的脉冲数
    long zeroPulsePos;     // 关节零点位置的脉冲位置
    float posLmt;           // 关节的正限位位置：单位 度
    float negLmt;           // 关节的负限位位置：单位 度
    float ratio;            // 减速比
    float maxVel;           // 最大关节速度  ：单位  °/s
    float maxAcc;           // 最大关节加速度: 单位 °/s^2
	float reserved1;		// 保留，设置为0
    double reserved[8];	    // 保留，设置为0
}TScaraJiontPara;

// 设置机械参数
MTN_API short  __stdcall NMC_CrdSetScaraMechPara(HAND crdHandle,TScaraMechPara *pScaraMechPara);

// 读取机械参数
MTN_API short  __stdcall NMC_CrdGetScaraMechPara(HAND crdHandle,TScaraMechPara *pScaraMechPara);

// 设置关节参数
MTN_API short  __stdcall NMC_CrdSetScaraJiontPara(HAND crdHandle,short jointNo,TScaraJiontPara *pScaraJiontPara);

// 读取关节参数
MTN_API short  __stdcall NMC_CrdGetScaraJiontPara(HAND crdHandle,short jointNo,TScaraJiontPara *pScaraJiontPara);

// 设置crd类型为scara
// jointNum: 2/3
// jointAxNoArray 数组长度为4，不用的数据设置为0
MTN_API short  __stdcall NMC_CrdSetTransScara(HAND crdHandle, short jointNum, short *jointAxNoArray );

// 销毁scara机型
MTN_API short  __stdcall NMC_CrdDelTransScara(HAND crdHandle);

typedef struct
{
   short masterAxNo;	// 传输带轴号，0~N
   short useEnc;	// 使用编码器，0：规划，1：编码器
   short dirReverse;    // 传输轴方向取反。0：不取反，1：取反

   short followedAxNo;   // 跟随哪个轴，0:X，1:Y
   double posCoe;	 // 传输轴当量和跟随轴的当量比例，跟随当量 / 传输轴当量
  
   long  reserved2[16];  // 保留，设置为0
}TFlyFollowPara;

// 设置crd启用飞行跟随模式
// *pFlyFollowPara 模式参数
MTN_API short  __stdcall NMC_CrdSetFlyFollow(HAND crdHandle, TFlyFollowPara *pFlyFollowPara);

// 销毁飞行跟随
MTN_API short  __stdcall NMC_CrdDelFlyFollow(HAND crdHandle);

// 查询是否在暂停后已经跟随上状态
// sts : 1表示跟随上  0表示没有跟随上
MTN_API short  __stdcall  NMC_CrdGetFlyFollowUpSts(HAND crdHandle,short *pSts);

// 缓冲区设置飞行跟随功能的启动和关闭
// enable:0:关闭跟随
//        1:激活跟随
//        2:暂停跟随
MTN_API short  __stdcall NMC_CrdBufEnableFlyFollow(HAND crdHandle, long segNo,short enable);

// 缓冲区：飞行跟随情况下，移动到机械位置
MTN_API short  __stdcall NMC_CrdBufFlyFollowLineXY(HAND crdHandle, long segNo,long *tgtPos,double acc,double vel);

// 缓冲区：等待缓冲区数据
// usedSpace:等待缓冲区数据段数（大于等于usedSpace继续往下执行）
MTN_API short  __stdcall NMC_CrdBufWaitData(HAND crdHandle, long segNo,long usedSpace);

// 缓冲区：坐标系内轴跟随
// crdAxMaster:跟随的主轴，取值范围[0,n],为坐标系内的轴，0:X轴，1:Y轴，2:Z轴，3:A轴
// axFllowMask:跟随的从轴掩码
// onOff：启动跟随或者关闭跟随,1:启动跟随，0:关闭跟随，此时，crdAxMaster和axFllowMask忽略，可任意值
MTN_API short  __stdcall NMC_CrdBufAxFollowOnOff(HAND crdHandle, long segNo,short crdAxMaster,short axFllowMask,short onOff);

//-------------------------------------------------------------------------------
//22.坐标系干涉保护指令
//-------------------------------------------------------------------------------
#define CRD_INTERF_GROUP_MAX		(2)

// 启动坐标系的干涉保护
// groupNo: 干涉坐标系组号（目前只有两个坐标系，所以该值为0）
// mode:	0:基本模式，出现干涉，两坐标系均停止  1：激光模式，出现干涉，其中一个停止并离开
MTN_API short  __stdcall NMC_SetMvProtect(HAND devHandle,short groupNo,short mode);

// 取消坐标系的干涉保护
// groupNo: 干涉坐标系组号（目前只有两个坐标系，所以该值为0）
MTN_API short  __stdcall NMC_DelMvProtect(HAND devHandle,short groupNo);

// 获取坐标系的干涉状态
// groupNo: 干涉坐标系组号（目前只有两个坐标系，所以该值为0）
// pSts:	0 没有启动干涉功能 1  没有出现干涉  2 干涉发生
MTN_API short  __stdcall NMC_GetMvProtectSts(HAND devHandle,short groupNo,short *pSts);

typedef struct
{
   short crdNo[2];		// 需要干涉保护的两坐标系号
   short crdAxNo[2];	// 坐标系的干涉轴号,指XYZ中哪一个（X:0  Y:1    Z:2）
   short moveDir[2];    // 两干涉轴分别往距离减小时的运动方向，1：正向 -1：负向

   long orgDis;			// 两坐标系的crdAxNo轴在原点时的距离
   long mvProtectDis;	 // 干涉的保护距离   
   long safeWaitPos;	// mode为激光模式时，干涉轴需要停止到的等待位置（mode为0时无效）
   double mvToSafeAcc;  // 运动到等待位置的移动加速度
   double mvToSafeVel;  // 运动到等待位置的移动速度
   short stopCrdNo;		// mode为激光模式时，需要停止的坐标系号（mode为0时无效）
   short reserved[3];      // 保留参数
   
}TMvProtectPara;

// 设置坐标系的干涉保护参数
// groupNo:	干涉坐标系组号（目前只有两个坐标系，所以该值为0）
// pCrdInterfProtectPara： 干涉参数
MTN_API short  __stdcall NMC_SetMvProtectMode01Para(HAND devHandle,short groupNo,TMvProtectPara *pMvProtectPara);

// 获取坐标系的干涉保护参数
// groupNo:	干涉坐标系组号（目前只有两个坐标系，所以该值为0）
// pCrdInterfProtectPara： 干涉参数
MTN_API short  __stdcall NMC_GetMvProtectMode01Para(HAND devHandle,short groupNo,TMvProtectPara *pMvProtectPara);


//-------------------------------------------------------------------------------
//23.不常用指令
//-------------------------------------------------------------------------------
typedef struct
{
    short crdSts;          // 坐标系状态
    short axSts[3];        // 坐标系里各轴状态
    long  prfPos[3];       // 用户坐标系下的规划位置
    long  axisPos[3];      // 机械坐标系下的规划位置
    long  encPos[3];        // 编码器位置
    long  userSeg;         // 运行的缓冲区段号
    double  prfVel;         // 运动速度
    long  gpDi;             // 通用输入0~31
    long  gpDo;             // 通用输出0~31
    short  motDi[3];        // 限位、原点、报警。请参考专用IO位定义( 搜索 BIT_AXMTIO_LMTN )
    short  reserved;        // 保留
    long crdFreeSpace;      // 缓冲区剩余空间
    long reserved2;
}TPackedCrdSts3;
// 坐标系运动模式下,打包读取控制器状态
MTN_API short __stdcall NMC_CrdGetStsPack3( HAND crdHandle, TPackedCrdSts3 *pPackSts );

// 坐标系模式下,读取多个轴的机械坐标位置
// cnts: 读取个数,1~N
// pPos：返回坐标数组
MTN_API short __stdcall NMC_CrdGetAxisPos(HAND crdHandle,short cnts, long *pPosArray);

// 读取规划位置XYZ
// cnts: 读取个数,1~N
// pPosArray：返回坐标数组
MTN_API short __stdcall NMC_CrdGetPrfPos( HAND crdHandle, short cnts, long *pPosArray );

// 读取编码器位置
// cnts: 读取个数,1~N
// pPos：返回坐标数组。
MTN_API short __stdcall NMC_CrdGetEncPos  ( HAND crdHandle, short cnts, long *pPosArray );

// 获取坐标系合成速度
// pVel：坐标系合成速度
MTN_API short __stdcall NMC_CrdGetVel(HAND crdHandle,double *pVel);

// 打开坐标系组
// pCrdHandle：返回坐标系组句柄
MTN_API short __stdcall NMC_CrdOpen(HAND devHandle, PHAND pCrdHandle );

// 单轴急停
// 注：运动会按设定的急停加速度停止。如果没有设置,则会立即停止。
MTN_API short __stdcall NMC_MtEstp    ( HAND axisHandle );

// 读取打包轴状态（8轴）
typedef struct
{
	long prfPos[8];     // 规划位置
	long encPos[8];     // 实际位置
	float prfVel[8];    // 规划速度
	long motionIO[8];   // 轴专用IO
	short sts[8];       // 轴状态
	long gpo;            // 通用输出
	long gpi;            // 通用输入
}TAxisStsPack8;
// 打包读取8个轴的状态,从第一个轴开始读取
// axisFirstHandle : 第一个轴句柄
// pPackSts: 打包的状态数据,参考结构体定义
MTN_API short  __stdcall NMC_MtGetStsPack8  ( HAND axisFirstHandle, TAxisStsPack8 *pPackSts );

// 直线插补
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// crdAxMask:参与的轴,按位表示
// pTgPosArray：目标位置数组,长度为3
MTN_API short __stdcall NMC_CrdLineXYZ(  HAND crdHandle,  long segNo, short crdAxMask,long *pTgPosArray, double endVel, double vel,double synAcc );

// 读取通用输出(按通道,支持超过32位)
// groupID:DO组,取值范围[0,n],,0: 本地DO31~DO0, 1: 本地DO63~DO32,其他指扩展IO模块
// pDoValue: 设置通用数字量输出。1, 高电平,0,低电平
MTN_API short  __stdcall NMC_GetDO( HAND devHandle, short groupID, long *pDoValue);

// 设置通用输出(按通道,支持超过32位)
// groupID:DO组,取值范围[0,n],具体需要看控制器是否存在多组数字量输出
// value: 设置通用数字量输出。1, 输出高电平,0,输出低电平
MTN_API short  __stdcall NMC_SetDO( HAND devHandle, short groupID, long value ) ;

// 读通用输入(按通道,支持超过32位) 
// groupID:DI组,取值范围[0,n],0: 本地DI31~DI0, 1: 本地DI63~DI32,其他指扩展IO模块
// pInValue: 通用数字量输入值。1, 高电平,0,低电平
MTN_API short __stdcall NMC_GetDI( HAND devHandle, short groupID, long *pInValue );

// 设置限位开关输入是否停止运动
// posEn：正向限位触发允许设置,1为允许,0为禁止
// negEn: 负向限位触发允许设置
MTN_API short  __stdcall NMC_MtLmtOnOff    ( HAND axisHandle, short posSwt, short negSwt );

// 设置限位开关触发电平
// posSwt：正向限位触发电平设置,1为高电平触发,0为低电平触发
// negSwt: 负向限位触发电平设置
MTN_API short  __stdcall NMC_MtLmtSns      ( HAND axisHandle, short posSwt, short negSwt );

// 设置原点开关触发电平，注意：这里的电平设置不会影响捕获的电平
// sns：原点电平设置,1为高电平触发,0为低电平触发
MTN_API short  __stdcall NMC_MtHomeSns( HAND axisHandle, short sns);

// 读取原点开关触发电平
// pSns：当前的原点电平设置,1为高电平触发,0为低电平触发
MTN_API short  __stdcall NMC_MtGetHomeSns( HAND axisHandle, short *pSns);

// 设置伺服报警开关是否停止运动
// swt：伺服报警开关输入允许设置,1为允许,0为禁止。（默认为高电平触发）
MTN_API short  __stdcall NMC_MtAlarmOnOff  ( HAND axisHandle, short swt );

// 设置伺服报警开关电平
// swt：伺服报警触发电平设置,1为高电平触发,0为低电平触发
MTN_API short  __stdcall NMC_MtAlarmSns    ( HAND axisHandle, short swt );

// 读取打包轴状态（12轴）
typedef struct
{
	long prfPos[12];     // 规划位置
	long encPos[12];     // 实际位置
	float prfVel[12];    // 规划速度
	long motionIO[12];   // 轴专用IO
	short sts[12];       // 轴状态
	long gpo;            // 通用输出
	long gpi;            // 通用输入
}TAxisStsPack12;
// 打包读取12个轴的状态,从第一个轴开始读取
// axisFirstHandle : 第一个轴句柄
// pPackSts: 打包的状态数据,参考结构体定义
MTN_API short  __stdcall NMC_MtGetStsPack12  ( HAND axisFirstHandle, TAxisStsPack12 *pPackSts );

//------------------------------------------------------------------------
//                                                     
//  24.自动状态返回
//                                                   
//------------------------------------------------------------------------
#define AUTO_RTN_MAX_AXIS  12
// 打包返回状态结构
typedef struct
{
    short          mtSts[12];          // 单轴状态
    short          mtMio[12];          // 单轴专用IO
	long           mtPrfPos[12];       // 单轴规划位置
    long           mtEncPos[12];       // 单轴实际位置
	float          mtPrfVel[12];       // 单轴规划速度

    short          crdSts[2];          // 坐标系状态
	float          crdPrfVel[2];	   // 坐标系运动速度
	long           crdUserSeg[2];      // 坐标系运行的缓冲区段号
	long           crdFreeSpace[2];    // 坐标系缓冲区剩余空间
    long           crdUsedSpace[2];    // 坐标系缓冲区使用空间

    long           gpi;                // 通用输入
    long           gpo;                // 通用输出
    short          reserved[32];       // 预留

}TAutoRtnPackedSts;

// 设置启用自动状态返回
// mode1 : 设置哪些状态主动返回，0：固定时间周期返回（默认）; 1：周期+轴状态变化，坐标系状态变化；
// mode2 : 备用
// cycleInMs: 周期，单位ms。取值5~10000。建议值100ms。
// port: 端口，写0（库里会修改）
// hostTag : 上位机标签，写0（库里会修改）
MTN_API short __stdcall NMC_DevAutoRtnSet( HAND devHandle, long mode1, long mode2, long cycleInMs, long port, long hostTag );

// 设置禁用自动状态返回
MTN_API short __stdcall NMC_DevAutoRtnClr( HAND devHandle );

// 同步，
// 把之前的状态缓冲清除掉。以后读到的是同步指令发送后的状态
// hostTag : 上位机标签，写0
MTN_API short __stdcall NMC_DevAutoRtnSyn( HAND devHandle, long hostTag );

// 读状态
// packedSts : 打包状态
MTN_API short __stdcall NMC_DevAutoRtnGet( HAND devHandle, TAutoRtnPackedSts * packedSts, short *pReady );

// 设置PTP位置比较输出
// comparaPos： 目标位置，单位是 脉冲
// upDateVel：比较后的更新速度 pulse/ms
MTN_API short __stdcall NMC_MtSetPtpComparePara( HAND axisHandle,short dir, long comparaPos, double upDateVel);

// 获取PTP比较输出状态
MTN_API short __stdcall NMC_MtGetPtpCompareSts( HAND axisHandle,short *pIsCompareActive,short *pIsCompareOut);

//------------------------------------------------------------------------
//                                                     
//  Group 25 : 点位自动收发
//                                                   
//------------------------------------------------------------------------

// 设置启用点位自动收发
MTN_API short __stdcall NMC_DevAsynCommSet( HAND devHandle, unsigned long delayInMs );

// 设置关闭点位自动收发
MTN_API short __stdcall NMC_DevAsynCommClr( HAND devHandle );

// 设置启用自动状态返回
MTN_API short __stdcall NMC_DevAsynGetSts( HAND devHandle, TAutoRtnPackedSts * packedSts, short *pReady );

// 多轴点位运动     
MTN_API short __stdcall NMC_DevAsynAbsMoveType1( HAND axisHandle, float acc,float dec,float vel,
    short smooth,long arrivalBand,long stableTime,long tgtPos);

// 设置Do
MTN_API short __stdcall NMC_DevAsynSetDoBit( HAND devHandle, short bitIdx,short setValue);

//------------------------------------------------------------------------
//                                                     
//  Group 26 : 高速一维位置比较
//                                                   
//------------------------------------------------------------------------

#define CMP_HS1DIMENS_CHN_MAX	(4)         // 最大支持四个通道
#define CMP_HS1DIMENS_POS_MAX	(128)         // 每个通道最多支持8个位置点

// 一维高速位置比较参数结构
typedef struct
{
short dirNo;            // 编码器源（0~7），对应轴0~7的编码器。
short out1StLevel;      // out1起始电平（0或1）
short out2StLevel;      // out2起始电平（0或1）
short reserved;         // 保留
long out1Width;         // out1脉冲宽度，0~65535,单位us
long out2Width;         // out2脉冲宽度，0~65535,单位us
long out2Delay;         // out2延时，0~65535,单位us
} TCompHs1DimensParam;

// 功能：设置高速1维位置比较的参数（比较编码器）
// param: 一维比较参数
// chn：通道号,范围0~3
// 注：1)需要先设置编码器模式，可设置外部编码器或内部计数。
//???? 2)比较输出引脚位置请参考硬件手册。
//???? 3)out1比较位置到后马上输出, out2到位后延时输出。
MTN_API short __stdcall  NMC_CompHs1DimensSetParam(HAND devHandle, TCompHs1DimensParam *param,short chn );

// 功能：读取高速1维位置比较的参数
// param, chn：同上
MTN_API short __stdcall NMC_CompHs1DimensGetParam(HAND devHandle, TCompHs1DimensParam *param,short chn);

// 功能：设置高速1维比较数据
// pArrayPos:比较数组地址
// count:位置点数
// chn: 同上
MTN_API short __stdcall NMC_CompHs1DimensSetData(HAND devHandle,long *pArrayPos,short count,short chn);

// 功能：高速1维位置比较使能
// onOff： 0:停止,1:输出,2:手动输出（必须在空闲状态下,也需要提前设置参数）
// chn: 同上
MTN_API short __stdcall NMC_CompHs1DimensOnOff(HAND devHandle, short onOff,short chn);

// 功能：高速1维位置比较的状态
// pBusy: 0 未启动比较 1 比较输出中
// pOutCount：输出的个数
// pWaitCnts：等待比较的个数
// pFreeCnts：缓冲区空闲的个数
// chn: 同上
MTN_API short __stdcall NMC_CompHs1DimensStatus(HAND devHandle, short * pBusy, short *pOutCount, short *pWaitCnts, short *pFreeCnts, short chn);

//------------------------------------------------------------------------
//                                                     
//  Group 27 : 获取多轴信息
//                                                   
//------------------------------------------------------------------------
// 读取计时时钟，控制器上电开始
// pClock:计数值，单位:125us
// pLoop: 循环周期计数
MTN_API short  __stdcall NMC_GetClock(HAND devHandle,unsigned long *pClock,unsigned long *pLoop);

// 获取多轴状态
// firstAxisHandle:第一个轴句柄
// pSts:返回的状态数组
// count:轴数量
// pClock:返回当前控制器时钟，单位125us
MTN_API short  __stdcall NMC_MtGetStsMulti(HAND firstAxisHandle,short *pStsArray,short count,unsigned long *pClock);

// 获取多轴规划模式
// firstAxisHandle:第一个轴句柄
// pModes:返回的数组
// count:轴数量
// pClock:返回当前控制器时钟
MTN_API short  __stdcall NMC_MtGetPrfModeMulti(HAND firstAxisHandle,short *pModeArray,short count,unsigned long *pClock);
MTN_API short  __stdcall NMC_MtGetAxisPrfPosMulti(HAND firstAxisHandle,long *pPosArray,short count,unsigned long *pClock);
MTN_API short  __stdcall NMC_MtGetAxisPrfVelMulti(HAND firstAxisHandle,double *pVelArray,short count,unsigned long *pClock);
MTN_API short  __stdcall NMC_MtGetAxisPrfAccMulti(HAND firstAxisHandle,double *pAccArray,short count,unsigned long *pClock);
MTN_API short  __stdcall NMC_MtGetAxisEncPosMulti(HAND firstAxisHandle,long *pPosArray,short count,unsigned long *pClock);
MTN_API short  __stdcall NMC_MtGetAxisEncVelMulti(HAND firstAxisHandle,double *pVelArray,short count,unsigned long *pClock);
MTN_API short  __stdcall NMC_MtGetAxisEncAccMulti(HAND firstAxisHandle,double *pAccArray,short count,unsigned long *pClock);
MTN_API short  __stdcall NMC_MtGetAxisErrorMulti(HAND firstAxisHandle,long *pErrArray,short count,unsigned long *pClock);
MTN_API short  __stdcall NMC_GetEncPosMulti(HAND devHandle,short encoder,long *pEncPosArray,short count,unsigned long *pClock);

// DI type
#define DI_TYPE_LIMIT_POSITIVE               0		// 正向限位
#define DI_TYPE_LIMIT_NEGATIVE               1		// 负向限位
#define DI_TYPE_ALARM                        2		// 驱动报警
#define DI_TYPE_HOME                         3		// 原点
#define DI_TYPE_GPI                          4		// 通用输入
#define DI_TYPE_LIMIT_POSITIVE_LOG           10		// 正向限位:逻辑电平
#define DI_TYPE_LIMIT_NEGATIVE_LOG           11		// 负向限位:逻辑电平
#define DI_TYPE_ALARM_LOG                    12		// 驱动报警:逻辑电平
#define DI_TYPE_HOME_LOG                     13		// 原点:逻辑电平


// 设置DI的滤波系数
// diType:DI类型,见DI type宏定义
// groupID:DI组,取值范围[0,n],对于DI_TYPE_GPI，则0: 本地DI31~DI0, 1: 本地DI63~DI32,其他指扩展IO模块；对于其他DI类型，暂时保留
// diIndex:DI通道号，取值范围[0,n]
// filtTime:滤波时间，单位ms，默认为3,取值范围[0,32]
MTN_API short  __stdcall NMC_SetDIFilter( HAND devHandle,short diType,short diGroup,short diIndex,short filtTime);

// 获取DI的滤波系数
MTN_API short  __stdcall NMC_GetDIFilter( HAND devHandle,short diType,short diGroup,short diIndex,short *pFiltTime);

// 读取数字量输入信号值
// diType:DI类型,见DI type宏定义
// groupID:DI组,取值范围[0,n],对于DI_TYPE_GPI，则0: 本地DI31~DI0, 1: 本地DI63~DI32,其他指扩展IO模块；对于其他DI类型，暂时保留
// pDiValue:返回的输入值
MTN_API short  __stdcall NMC_GetDIEx( HAND devHandle,short diType,short groupID,long *pDiValue);

// 读取数字量输入信号值(原始值)
// diType:DI类型,见DI type宏定义
// groupID:DI组,取值范围[0,n],对于DI_TYPE_GPI，则0: 本地DI31~DI0, 1: 本地DI63~DI32,其他指扩展IO模块；对于其他DI类型，暂时保留
// pDiValue:返回的输入值
MTN_API short  __stdcall NMC_GetDIRaw( HAND devHandle,short diType,short groupID,long *pDiValue);

// 设置数字量输入信号的翻转计数
// diType:DI类型,见DI type宏定义
// diIndex:DI序号，取值范围[0,n]，对于通用输入，只支持0~15，对于其他只支持0~7
// pReverseCountArray:返回的翻转计数数组
// count:同时获取的数量，取值范围[1,16]
MTN_API short  __stdcall  NMC_SetDiReverseCount(HAND devHandle,short diType,short diIndex,unsigned long *pReverseCountArray,short count);

// 获取数字量输入信号的翻转计数
// diType:DI类型
// diIndex:DI序号，取值范围[0,n]
// pReverseCountArray:翻转计数数组
// count:同时获取的数量，取值范围[1,16]
MTN_API short  __stdcall  NMC_GetDiReverseCount(HAND devHandle,short diType,short diIndex,unsigned long *pReverseCountArray,short count);

// DO type
#define DO_TYPE_MOTOR_ENABLE            1   // 电机使能
#define DO_TYPE_MOTOR_CLEAR             2   // 电机报警清除
#define DO_TYPE_GPDO                    3   // 通用输出1

// 输出DO,按照掩码
// doType:do类型
// groupID:组号
// outMask:按位输出掩码
// outValue:按位输出数值
MTN_API short  __stdcall NMC_SetDOMask( HAND devHandle,long outMask,long outValue ,short doType,short groupID) ;

// 读取模拟量输入电压值
// ch:通道号，[0,n]表示本地，256表示扩展模拟量通道
// count:获取的通道数量,取值范围[1,8]
// pAdcVolArray:获取的电压值数组
MTN_API short  __stdcall NMC_GetAdcVoltageMulti( HAND devHandle,short ch,short count,double *pAdcVolArray);

// 设置模拟量输出电压值
// ch:通道号，[0,n]表示本地，256表示扩展模拟量通道
// count:获取的通道数量,取值范围[1,8]
// pDacVolArray:获取的电压值数组
MTN_API short  __stdcall NMC_SetDacVoltageMulti( HAND devHandle,short ch,short count,double *pDacVolArray);

// 读取模拟量输出电压值
// ch:通道号，[0,n]表示本地，256表示扩展模拟量通道
// count:获取的通道数量,取值范围[1,8]
// pDacVolArray:获取的电压值数组
MTN_API short  __stdcall NMC_GetDacVoltageMulti( HAND devHandle,short ch,short count,double *pDacVolArray);

#define REPEAT_CAPT_MAX_NUM		64      // 最大重复捕获次数

// 设置重复捕获次数
// count:重复捕获次数，取值范围[0,REPEAT_CAPT_MAX_NUM],0表示取消重复捕获
// 注意:设置后将清除捕获数据
MTN_API short  __stdcall NMC_MtSetCaptRepeat(HAND axisHandle,short count);

// 读取重复捕获计数
// pCount:已经捕获次数
MTN_API short  __stdcall NMC_MtGetCaptRepeatStatus(HAND axisHandle,short *pCount);

// 读取重复捕获位置值
// pPosArray:返回的位置值数组
// startNum:起始计数
// count:重复捕获次数，取值范围[1,32],一次最多读32个
MTN_API short  __stdcall NMC_MtGetCaptRepeatPosMulti(HAND axisHandle,long *pPosArray,short startNum,short count);

// 获取中断的执行时间
// pServoRunTime:伺服周期当前值
// pProfileRunTime:规划周期当前值
MTN_API short  __stdcall NMC_GetInterruptTime(HAND devHandle,double *pServoRunTime,double *pProfileRunTime);

// 获取中断的最大执行时间
// pServoRunTimeMax:伺服周期最大值
// pProfileRunTimeMax:规划周期最大值
MTN_API short  __stdcall NMC_GetInterruptTimeMax(HAND devHandle,double *pServoRunTimeMax,double *pProfileRunTimeMax);

// 缓冲区停止坐标系运动
// crdIdx:停止坐标系序号，-1表示停止自身
MTN_API short  __stdcall NMC_CrdBufStopMtn(HAND crdHandle,long segNo,short crdIdx);

// 使能或关闭输入整形功能
// enable: 0:取消 1：使能
// bufCount: 整形的宽度
// kCoef: 整形的系数
MTN_API short  __stdcall  NMC_MtSetAxisInputShaping(HAND axisHandle,short enable,short bufCount,double kCoef);

// 获取输出DO
// doType:do类型
// groupID:组号
// pOutValue:获取的数值
MTN_API short  __stdcall NMC_GetDOEx( HAND devHandle,short doType,short groupID,long *pOutValue );

// 按位设置通用输出信号取反
// doType:DO类型,例如：DO_TYPE_GPDO
// group:组号，暂时只对GPO有效，指DO的组号
// bitIndex:取值范围[0,n],位序号,前64位为本地的通用输出,大于64为扩展Do
// revs:是否取反,1：取反,0：不取反
MTN_API short  __stdcall NMC_SetDOBitRevsEx ( HAND devHandle,short doType,short group,short bitIndex,short revs);

// 按位读取通用输出信号取反
MTN_API short  __stdcall NMC_GetDOBitRevsEx( HAND devHandle,short doType,short group,short bitIndex,short *pRevs);

// 获取坐标系状态
// pSts：crd状态，按位表示
// pUserSeg：当前的用户段号
MTN_API short __stdcall NMC_CrdGetStsEx( HAND crdHandle, short *pSts,long *pUserSeg );

// 输入沿触发
// diIndex:通用输入序号，只支持通用输入信号，取值范围[0,32]
// diSns:触发沿，0为下降沿,1为上升沿
MTN_API short  __stdcall  NMC_MtPtStartMtnEx(HAND axisHandle,short diIndex,short diSns);

///xy平面补偿
#define XY2DCOMP_MAX_TABLE_NUM	(4)	// 平面补偿的最大表格数量
typedef struct
{
	short count[2];				// Count[0]和Count[1]分别为X，Y方向的数据点数，每个方向最小2个
	short reserved[2];			// 保留
	long posBegin[2];			// posBegin[0]和posBegin[1]分别为X,Y方向的起始补偿位置
	long step[2];				// step[0]和step[1]分别为XY方向的补偿步长
	double angle;				// 标定坐标系与机械坐标系的夹角，单位：度
}T2DCompensationTable;

typedef struct
{
	long xDirComp;
	long yDirComp;
	long zDirComp;
}TCompData;						// 每个点三个方向上的补偿量

// 设置补偿表：以XY为基准参考，标定XYZ方向的偏差数据，并进行设置
// tableIndex: 取值0（为后续扩展准备）
// pData:数据包含X*Y个点，点数组总长度X*Y*3<= 3000,每个点包含XYZ3个方向的补偿值,数组按照x方向排列
MTN_API short  __stdcall  NMC_Set2DCompensationTable(HAND devHandle,short tableIndex,T2DCompensationTable *pTable,TCompData *pData);

// 获取补偿表
MTN_API short  __stdcall  NMC_Get2DCompensationTable(HAND devHandle,short tableIndex,T2DCompensationTable *pTable,TCompData *pData);

typedef struct
{
	short enable;			// 启动或停止补偿
	short tableIndex;		// 使用的目录表：取值0
	short axisType[2];		// 二维补偿表所使用的轴类型:0表示规划，1表示使用编码器
							//  axisType[0]对应X方向类型，axisType[1]对应Y方向类型
	short axisIndex[3];		// axisIndex[0]表示X方向使用的轴号， axisIndex[1]表示Y方向使用的轴号
												// 注：axisIndex[2]表示Z方向需要补偿的轴号
}T2DCompensation;

// 设置并启动XY平面误差补偿
MTN_API short  __stdcall  NMC_Set2DCompensation(HAND devHandle,T2DCompensation *pComp);

// 获取XY平面的误差补偿参数
MTN_API short  __stdcall  NMC_Get2DCompensation(HAND devHandle,T2DCompensation *pComp);

//------------------------------------------------------------------------------------------------------------
//
//	28.PVT
//
//------------------------------------------------------------------------------------------------------------
// 单轴PVT运动参数结构
typedef struct
{
    double smoothDec;		// 停止减速度
    double abruptDec;		// 急停减速度，暂时保留
    double reserved1[2];	// 保留
	long dataMode;			// 工作模式，1：数据驻存模式   0：数据刷新模式(默认模式)
	long loopCount;			// 循环次数 ：仅数据驻存模式下有效
    long reserved2[4];      // 保留
}TPvtPara;
// 设置PVT运动的相关参数 
// pPara：参数,参考结构定义
MTN_API short __stdcall NMC_MtPvtSetPara( HAND axisHandle, TPvtPara *pPara );
// 读取PVT运动的相关参数 
MTN_API short __stdcall NMC_MtPvtGetPara( HAND axisHandle, TPvtPara *pPara );
 
// 向PVT运动缓存区中压运动数据段
// count:压入的数据段数：1~32
// pPosArray:段运行距离
// pTimeArray:段运行时间
// pVelArray:段运行速度
MTN_API short  __stdcall NMC_MtPvtData(HAND axisHandle,short count,double *pPosArray,double *pTimeArray,double *pVelArray);

// 查询PVT数据剩余空间大小
// pFreeSpace:返回的剩余空间大小
// pUsedSpace: 已使用的空间段数
MTN_API short  __stdcall NMC_MtPvtBufGetSpace(HAND axisHandle,short *pFreeSpace,short *pUsedSpace);

// 清空PVT数据
MTN_API short  __stdcall NMC_MtPvtBufClr(HAND axisHandle);

// 启动Pvt运动
// otherSynAxCnts： 不包括axisHandle 的其他同步启动轴数量
// pOtherSynAxArray: 其他同步启动轴的序号：0~N	
// 注：同步的轴必须属于同一个控制器
MTN_API short  __stdcall NMC_MtPvtStartMtn(HAND axisHandle,short otherSynAxCnts,short *pOtherSynAxArray);

#ifdef __cplusplus
}
#endif

#endif	// _H_MTN_LIB20_EXT_H_
