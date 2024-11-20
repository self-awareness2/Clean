///******************************************************************
//
// Moudle Name  :   mtn_lib20_oem.h
// Abstract     :   GaoChuan Motion 2.0 oem user header 
// Note :			1.结构体定义中所有的‘reservedxxx’的成员都是保留参数,为保持兼容性,请设置为0
//					2.无特别说明,所有API返回RTN_CMD_SUCCESS（即0值）表示执行成功,其他则表示错误代码
//					3.所有的API参数中,无特别说明,axisHandle表示操作轴的句柄,devHandle表示目标控制器的句柄,crdHandle表示目标坐标系组句柄
//                  4.mtn_lib20中所有的结构体都是以四字节对齐方式编译，为了避免结构体对齐引起的问题，请将编译环境设置为四字节对齐
// Modification History :
///******************************************************************
#ifndef _H_MTN_LIB20_OEM_H_
#define _H_MTN_LIB20_OEM_H_
#include "mtn_lib20.h"

#ifdef __cplusplus
extern "C" {
#endif

// 设置PTP的高级参数
// minEvenTime:最小匀速时间
// param1:保留
MTN_API short  __stdcall OEM_MtSetMinEventTime(HAND axisHandle,short minEvenTime,short param1,short param2,short param3);

// 读取PTP的高级参数
MTN_API short  __stdcall OEM_MtGetMinEventTime(HAND axisHandle,short *minEvenTime,short *param1,short *param2,short *param3);

// 多轴同步运动
// mask:轴掩码
// pPosArray:位置数组
MTN_API short  __stdcall OEM_PtpSync(HAND devHandle,short mask,long *pPosArray);


typedef struct
{
	long xStart;			// X起点
	long yStart;			// Y起点
	long xIntv;				// X间距
	long yIntv;				// Y间距
	long cnt;				// 数量
	long reserved;
} TComp2DimensDataGroup;

// 功能：设置二维比较数据
// pArrayGroup:比较数组地址
// count:位置点数,count=0表示清除已经缓存的数据。一次性最多压入128组数据
// group:组号,0 或者1
// chn:保留,设为0
MTN_API short __stdcall OEM_Comp2DimensSetDataGroup(HAND devHandle,short group,TComp2DimensDataGroup *pArrayGroup,short count,short chn);


// 功能：设置双头运动中的第二个头相对第一个头的参数
// 参数：offsetX:双头回原点后，在X方向，第2个头的原点相对第1个头的原点的偏置量
//			 offsetY:双头回原点后，在Y方向，第2个头的原点相对第1个头的原点的偏置量
//			 pAxisNo:[0]第二个头的X轴对应的轴号  [1]第二个头的Y轴对应的轴号
MTN_API short __stdcall NMC_CrdSetDoubleHeadPara(HAND crdHandle,long offsetX,long offsetY,short *pAxisNo);

// 功能：读取双头运动中的第二个头相对第一个头的参数
// 参数：pOffsetX:双头回原点后，在X方向，第2个头的原点相对第1个头的原点的偏置量
//			 pOffsetY:双头回原点后，在Y方向，第2个头的原点相对第1个头的原点的偏置量
//			 pAxisNo:[0]第二个头的X轴对应的轴号  [1]第二个头的Y轴对应的轴号
MTN_API short __stdcall NMC_CrdGetDoubleHeadPara(HAND crdHandle,long *pOffsetX,long *pOffsetY,short *pAxisNo);

// 功能：实现第二个点胶头的图元切换动作,在没加工完一个图元后，切换到另外一个图元需要配合调用该指令
// 参数：	rotX,rotY:下一个图元的旋转中心（一般为相机拍照的位置）
//			tgtPosX,tgtPosY:是下一个图元的起始点位置XY的坐标 
//			deltaX、deltaY和theta:是下一个图元的中心相对第一个图元中心的偏移和旋转量。
//			deltaX、deltaY单位为脉冲，theta单位为度
//			vel,acc:第二个点胶头移动到起点的速度和加速度
// 注：没有对deltaX deltaY以及theta进行判断，后续根据第二号头的XY行程增加判断。
MTN_API short __stdcall NMC_CrdBufObjectSwitch(HAND crdHandle, long segNo,long rotX,long rotY, 
	long tgtPosX,long tgtPosY, long deltaX,long deltaY,double theta,double vel,double acc);

// 功能：建立2号头的与1号头的同步运动关系
MTN_API short __stdcall NMC_CrdBufSecondHeadSyncMoveOn(HAND crdHandle, long segNo);

// 功能：结束2号头的与1号头的同步运动关系
MTN_API short __stdcall NMC_CrdBufSecondHeadSyncMoveOff(HAND crdHandle, long segNo);

#define LASER_PARAM_TAB_UNIT_MAX	64		// 最大的激光参数表数量
typedef struct
{
	// SHIO模式下的参数
	double gateTime; 		// 设置gate 打开时间,单位：s（内部最小值：1/36us ）,取值范围(0,0.0009)
	long minFrq;			// 最低频率，单位HZ
	short gateDistance; 	// 固定模式下的位置间隔 单位：pulse
    short k;				// 低频过渡系数          
	short startDot; 	    // 启动时出光打点
	short lowFrqRange; 		// 低频范围：0：100k，1：1M,2:9M
	short accLowFrqOnVel;	// 加速段低频功能的启用速度值
	short decLowFrqOffVel;	// 减速段低频功能的关闭速度值
	short yCoe;				// Y向补偿，取值范围[0,255],实际比例为0~2的比例，coe*256后设到这个变量
	short yAng;				// 光斑的旋转角度
	
	// 普通模式下的参数
	long onDelay;		//开光延时,单位us,取值范围[0,65535]
	long offDelay;		//关光延时,单位us,取值范围[0,65535]
	long minValue;		//最小输出值，DA输出时，范围[0,32767],占空比输出时，范围[0,100],频率输出时，范围[0,2000000]
	long maxValue;		//最大输出值，DA输出时，范围[0,32767],占空比输出时，范围[0,100],频率输出时，范围[0,2000000]
	long standbyPower;	//待机能量,为0表示取消待机能量输出功能
	double overRide;	//跟随倍率,为0表示取消激光能量跟随
	short followType;	//跟随类型,0：跟随规划速度,1：跟随实际速度
	short reserved[7];	// 保留

}TLaserParamTableUnit;


MTN_API short  __stdcall OEM_CrdBufLaserSetParamTableIdx( HAND crdHandle,long segNo,short tableIdx,short laserCh);
MTN_API short  __stdcall OEM_LaserSetParamTableIdx( HAND devHandle,short tableIdx,short laserCh);
MTN_API short  __stdcall OEM_LaserSetParamTableUnit( HAND devHandle,short tableIdx,TLaserParamTableUnit *pParamUnit);
MTN_API short  __stdcall OEM_LaserGetParamTableUnit( HAND devHandle,short tableIdx,TLaserParamTableUnit *pParamUnit);

//------------------------------------------------------------------------------------------------------------
//
//         多段速运动
//
//------------------------------------------------------------------------------------------------------------
// 高速变低速
typedef struct
{
	double startVel;	// 第一段起跳速度
	double highVel;		// 高速段最大速度
	double highAcc;		// 高速段加速度
	double highDec;		// 高速段减速度
	double lowVel;		// 低速段最大速度
	double lowDec;		// 低速段减速度
	long highDist;		// 高速段目标位置
	long lowDist;		// 低速段目标位置
	short smooth;		// 平滑系数，取值[0,50]
	short reseved[3];	// 保留字段
}TPvtMoveHighToLow;

// 多段速：高速变低速
MTN_API short  __stdcall OEM_MtPvtMoveHighToLow(HAND axisHandle,TPvtMoveHighToLow *pPrm);

// 低速变高速
typedef struct
{
	double startVel;	// 第一段起跳速度
	double highVel;		// 高速段最大速度
	double highAcc;		// 高速段加速度
	double highDec;		// 高速段减速度
	double lowVel;		// 低速段最大速度
	double lowAcc;		// 低速段加速度
	long highDist;		// 高速段目标位置
	long lowDist;		// 低速段目标位置
	short smooth;		// 平滑系数，取值[0,50]
	short reseved[3];	// 保留字段
}TPvtMoveLowToHigh;

// 多段速：低速变高速
MTN_API short  __stdcall OEM_MtPvtMoveLowToHigh(HAND axisHandle,TPvtMoveLowToHigh *pPrm);

// 三段速运动（高低高）
typedef struct
{
 	double startVel;	//起跳速度
 	double vel1;		//第1段匀速运动的速度（单位：脉冲/毫秒）
 	double acc1;		//第1段加速度（单位：脉冲/毫秒^2）
 	double dec1;		//第1段减速度（单位：脉冲/毫秒^2）
 	double vel2;		//第2段匀速运动的速度（单位：脉冲/毫秒）
	double vel3;		//第3段匀速运动速度
 	double acc3;		//第3段加速到第3段的加速度
 	double dec3;		//第3段减速度

	long dist1;			//第1段行程（单位：脉冲）
 	long dist2;			//第2段行程（单位：脉冲）
 	long dist3;			//第3段行程
 	long reserved2;		// 保留
	short smooth;		// 平滑系数，取值[0,50]
	short reseved[3];	// 保留字段
} TPvtMove3Stage;

// 多段速：三段速运动（高低高）
MTN_API short  __stdcall OEM_MtPvt3Stage(HAND axisHandle,TPvtMove3Stage *pPrm);


//------------------------------------------------------------------------------------------------------------
//
//         坐标系的速度，补偿激光
//
//------------------------------------------------------------------------------------------------------------
// 根据坐标系的速度，补偿激光输出的相关控制量
#define LASER_CRDVELCOMP_PT_MAX			64
#define LASER_CRDVELCOMP_GROUP_MAX		4
typedef struct
{
	short count;								// 实际点数
	short mode;									// 补偿对象，0：补偿option值，1：补偿输出能量 2:更新能量跟随倍率
	short src;									// 跟随类型,0:编码器速度，1：规划速度
	short reserved[5];							// 保留
	float vel[LASER_CRDVELCOMP_PT_MAX];			// 速度表
	float comp[LASER_CRDVELCOMP_PT_MAX];		// 补偿值
}TLaserCrdVelCompTable;

// 配置坐标系速度补偿表
// pCompTable：补偿表
// group:补偿表格的序号，取值范围[0,LASER_CRDVELCOMP_GROUP_MAX)
MTN_API short  __stdcall OEM_LaserSetCrdVelCompTable(HAND devHandle, TLaserCrdVelCompTable *pCompTable,short group);
MTN_API short  __stdcall OEM_LaserGetCrdVelCompTable(HAND devHandle, TLaserCrdVelCompTable *pCompTable,short group);

// 启用或关闭速度补偿功能
// crdNo: 坐标系编号，[0,1]
// onOff：启用或关闭，0：关闭补偿功能，1：启用补偿功能
// group:补偿表格的序号，取值范围[0,LASER_CRDVELCOMP_GROUP_MAX)
// laserCh:激光通道号
MTN_API short  __stdcall OEM_LaserCrdVelCompOnOff(HAND devHandle, short crdNo,short onOff,short group,short laserCh);

// 启用或关闭速度补偿功能,缓冲区指令
// onOff：启用或关闭，0：关闭补偿功能，1：启用补偿功能
// group:补偿表格的序号，取值范围[0,LASER_CRDVELCOMP_GROUP_MAX)
// laserCh:激光通道号
MTN_API short  __stdcall OEM_CrdBufLaserCrdVelCompOnOff( HAND crdHandle,long segNo,short onOff,short group,short laserCh);

// 读取单轴急停DI的触发状态
// pTrigSts:是否触发，1表示已经触发。NMC_MtSetEstopDIMask/NMC_MtSetEstopDI指令会复位触发状态。
// pTrigIndex:本次触发的di序号。NMC_MtSetEstopDIMask/NMC_MtSetEstopDI指令会复位触发状态。
MTN_API short  __stdcall OEM_MtGetEstopDITrigSts(HAND axisHandle, short *pTrigSts ,short *pTrigIndex);

// 缓冲区启动单轴PTP二段速运动
// segNo:段号
// axisNo：轴号，取值[0,n),非坐标系内轴
// tgtPos：目标位置
// blockEn:0:非阻塞非同步，1：阻塞
// 二段速的参数参考TPtpTwoStagePrm定义
MTN_API short __stdcall OEM_CrdBufSetPtpTwoStage(HAND crdHandle, long segNo,short axisNo,long tgtPos,short inType,
			short inIndex,short inTrigLevel,short action,double prm1,double prm2,double prm3,double prm4,short blockEn);

// 缓冲区单轴移动参数设置
// segNo:段号
// axisNo：轴号,[0,n]
// vel:运动速度
// acc:运动加速度
// dec:运动减加速度
// velS:运动启动速度
// velE:运动终点速度
// smoothCoef:平滑系数
MTN_API short __stdcall OEM_CrdBufSetPtpMoveParaEx(HAND crdHandle, long segNo,short axisNo,double vel,double acc,double dec,double velS,double velE,short soomthCoef);


// 缓冲区补偿激光偏移值
// segNo:段号
// compType:bias类型，0:能量 1:跟随系数 2:option值
// bias:偏移值
// ch:激光通道
MTN_API short __stdcall OEM_CrdBufSetLaserBias(HAND crdHandle, long segNo,short biasType,double bias,short ch);

MTN_API short __stdcall OEM_LaserSetBias(HAND devHandle, short biasType,double bias,short ch);

///////////////////////////////////////////// UART
//奇偶校验位选项
#define UART_PARITY_N                       0		// 无校验
#define UART_PARITY_O                       1		// 奇校验
#define UART_PARITY_E                       2		// 偶校验

//停止位
#define UART_STOP_BITS_10                   0		// 停止位为1
#define UART_STOP_BITS_15                   1		// 停止位为1.5
#define UART_STOP_BITS_20                   2		// 停止位为2

typedef struct
{
	long baudrate;			// 波特率
	short mode;				// 端口的工作模式:0:默认，扩展模块工作模式，1:自由协议模式
	short dataBits;			// 数据位,取值范围[7,8]
	short stopBits;			// 停止位,取值范围[0,2]，参考宏定义，如UART_STOP_BITS_10等
	short parity;			// 校验方式，如UART_PARITY_N等
	short rxBufLen;			// 接收缓存长度，默认128
	short txBufLen;			// 发送缓存长度，默认128
	short reserved[4];		// 保留
}TUartPara;		

// 配置Uart端口在自由模式下的通讯参数
// pParam:参数
// ch:保留，请写0
MTN_API short __stdcall OEM_DevUartSetPara( HAND devHandle, TUartPara  *pParam,short ch);

// 获取Uart端口的参数
MTN_API short __stdcall OEM_DevUartGetPara( HAND devHandle, TUartPara  *pParam,short ch);

// 打开或关闭UART
// onOff:0：关闭，1：打开
// ch:保留，请写0
MTN_API short __stdcall OEM_DevUartOnOff( HAND devHandle, short onOff,short ch );

// 读Uart端口
// onOff:0：关闭，1：打开
// pBuf:读数据接收缓存区
// readLen:需要读取的数据长度，byte,一次最多读256字节
// retLen:实际读到的数据长度，byte
// ch:保留，请写0
MTN_API short __stdcall OEM_DevUartRead( HAND devHandle, void *pBuf,short readLen,short *retLen ,short ch);

// 写Uart端口
// onOff:0：关闭，1：打开
// pBuf:写数据
// writeLen:写的数据长度，byte,一次最多写256字节
// writedLen:实际写出的数据长度，byte
// ch:保留，请写0
MTN_API short __stdcall OEM_DevUartWrite( HAND devHandle, void *pBuf,short writeLen,short *writedLen ,short ch);

// 清除接收缓存
MTN_API short __stdcall OEM_DevUartClrRx( HAND devHandle,short ch);

// 获取当前串口收到的数据长度
// pOnOff:打开状态
// pLen:缓存的数据长度
// ch:保留，请写0
MTN_API short __stdcall OEM_DevUartGetRxLen( HAND devHandle,short *pOnOff,long *pLen,short ch);

// 带减速度的单轴停止功能,
// dec:减速度,单位：pulse/ms^2
// 注意：1.仅对PTP及Jog运动有效，对于其他运动模式，等同于NMC_MtStop
//       2.如果指定的减速度太小，则自动按照合适的减速度减速为0
MTN_API short __stdcall OEM_MtStopEx( HAND axisHandle,double dec);

// 周期同步
MTN_API short __stdcall OEM_Sync( HAND devHandle);


typedef struct 
{  
	short axMask;		// 捕获的轴掩码，最多8轴
	short captMode;		// 捕获模式，参考NMC_MtSetCaptSns的参数定义
	short captIoSrc;	// 捕获源，参考NMC_MtSetCaptSns的参数定义
    short captLev;		// 捕获电平，参考NMC_MtSetCaptSns的参数定义
	long captMaxCnt;	// 最多捕获多少个数据
	short reserved[2];
}TRepeatCaptParamEx;

// 设置重复捕获Ex的参数
// pParam:重复捕获cans
// ch:通道号，保留，请填0
MTN_API short __stdcall OEM_CaptRepeatSetParamEx( HAND devHandle,TRepeatCaptParamEx *pParam,short ch);
MTN_API short __stdcall OEM_CaptRepeatGetParamEx( HAND devHandle,TRepeatCaptParamEx *pParam,short ch);

// 启动或关闭重复捕获
// onOff:1:开，0:关
// ch:通道号，保留，请填0
MTN_API short __stdcall OEM_CaptRepeatOnOffEx( HAND devHandle,short onOff,short ch);

// 读取重复捕获计数
// pOnOff:onOff状态
// pLeftCount:剩余的捕获次数
// pSumCnt:累计捕获次数
// pGetCount:已经获取的次数
// ch:通道号，保留，请填0
MTN_API short  __stdcall OEM_CaptRepeatGetStatusEx(HAND devHandle,short *pOnOff,long *pLeftCount,long *pGetCount,long *pSumCnt,short ch);


// 读取重复捕获位置值
// pPosArray:返回的位置值数组
// count:要读取的触发位置组数，取值范围[1,32]
//       注意：捕获每触发一次，会产生n个位置数据（多轴），比如同时捕获四个轴，则count=1表示拿回四个位置值
// pGetCount:实际返回的数目
// ch:通道号，保留，请填0
MTN_API short  __stdcall OEM_CaptRepeatGetPosEx(HAND devHandle,long *pPosArray,short count,short *pGetCount,short ch);


//------------------------------------------------------------------------------------------------------------
//
//	Modbus
//
//------------------------------------------------------------------------------------------------------------
typedef struct 
{  
	short mode;			// 模式 -1:扩展模块,0:RTU,1:ASCII,16:RTU_Master
	short slaveAddr;	// 从站地址,仅在为从站时有效
	short port;			// 硬件端口，仅2有效
	short parity;		// 校验类型，0：无校验，1：奇校验，2：偶校验
	short dataBit;		// 数据位
	short stopBit;		// 停止位
	long bautrate;		// 波特率
	short masterTimeout;// 主站的最大响应时间,单位：毫秒
	short reserved[7];	// 保留
}TModbusParam;

// Modbus初始化
// pParam:参数
MTN_API short  __stdcall OEM_ModbusInit(HAND devHandle,TModbusParam *pParam);

// Modbus寄存器参数读取
// regType:寄存器类型,0:din,bit;1:coil,bit;2:input word,4:holding,word
// pRegCnt:寄存器个数
// pStartAddr:寄存器起始地址
MTN_API short  __stdcall OEM_ModbusGetRegParam(HAND devHandle,short regType,short *pRegCnt,long *pStartAddr);

// Modbus寄存器参数设置
// regType:寄存器类型,0:din,bit;1:coil,bit;2:input word,4:holding,word
// regCnt:寄存器个数
// startAddr:寄存器起始地址
MTN_API short  __stdcall OEM_ModbusSetRegParam(HAND devHandle,short regType,short regCnt,long startAddr);

// Modbus参数读取
// pParam:参数
MTN_API short  __stdcall OEM_ModbusGetParam(HAND devHandle,TModbusParam *pParam);


// 获取当前的modbus参数
// pSts: 
	//0:unset
	//1:slave mode, unconnected
	//2:slave mode, connected
	//3:master mode, unconnected
	//4:master mode, connected
MTN_API short  __stdcall OEM_ModbusGetSts(HAND devHandle,short  *pSts);

// Modbus关闭
// flag:1表示切换回扩展模块模式，其他标志只关闭Modbus
MTN_API short  __stdcall OEM_ModbusClose(HAND devHandle,short flag);

// Modebus:读取开关输入
// offset:地址偏移
// count:数据数量
// pBuff:返回的数据
// slaveAddr:对于控制器作为从站，该参数可选或无效，控制器作为主站，表示从站地址[1~127]
MTN_API short  __stdcall OEM_ModbusGetDin(HAND devHandle,short offset,short count,unsigned char *pBuff,short slaveAddr);

// Modebus:读取线圈输入
// offset:地址偏移
// count:数据数量
// pBuff:返回的数据
// slaveAddr:对于控制器作为从站，该参数可选或无效，控制器作为主站，表示从站地址[1~127]
MTN_API short  __stdcall OEM_ModbusGetCoil(HAND devHandle,short offset,short count,unsigned char *pBuff,short slaveAddr);

// Modebus:读取保持寄存器
// offset:地址偏移
// count:数据数量
// pBuff:返回的数据
// slaveAddr:对于控制器作为从站，该参数可选或无效，控制器作为主站，表示从站地址[1~127]
MTN_API short  __stdcall OEM_ModbusGetHolding(HAND devHandle,short offset,short count,unsigned short *pBuff,short slaveAddr);

// Modebus:读取16位输入寄存器
// offset:地址偏移
// count:数据数量
// pBuff:返回的数据
// slaveAddr:对于控制器作为从站，该参数可选或无效，控制器作为主站，表示从站地址[1~127]
MTN_API short  __stdcall OEM_ModbusGetInput(HAND devHandle,short offset,short count,unsigned short *pBuff,short slaveAddr);

// Modebus:写开关输入
// offset:地址偏移
// count:数据数量
// pBuff:数据
// slaveAddr:对于控制器作为从站，该参数可选或无效，控制器作为主站，表示从站地址[1~127]
MTN_API short  __stdcall OEM_ModbusSetDin(HAND devHandle,short offset,short count,unsigned char *pBuff,short slaveAddr);

// Modebus:写线圈输入
// offset:地址偏移
// count:数据数量
// pBuff:数据
// slaveAddr:对于控制器作为从站，该参数可选或无效，控制器作为主站，表示从站地址[1~127]
MTN_API short  __stdcall OEM_ModbusSetCoil(HAND devHandle,short offset,short count,unsigned char *pBuff,short slaveAddr);

// Modebus:写保持寄存器
// offset:地址偏移
// count:数据数量
// pBuff:数据
// slaveAddr:对于控制器作为从站，该参数可选或无效，控制器作为主站，表示从站地址[1~127]
MTN_API short  __stdcall OEM_ModbusSetHolding(HAND devHandle,short offset,short count,unsigned short *pBuff,short slaveAddr);

// Modebus:写16位输入寄存器
// offset:地址偏移
// count:数据数量
// pBuff:数据
// slaveAddr:对于控制器作为从站，该参数可选或无效，控制器作为主站，表示从站地址[1~127]
MTN_API short  __stdcall OEM_ModbusSetInput(HAND devHandle,short offset,short count,unsigned short *pBuff,short slaveAddr);




// 对称运动参数
// 描述：两个平行平面，次平面XY自动跟随主平面XY的运动，运动规律为基于O点对称
// 过程：1.设置参数
//		 2.主轴从轴运动到对称点，然后启动跟随
//       3.主轴运动过程中，从轴自动跟随
//       4.关闭跟随，解除关联
typedef struct 
{  

	long masterCent[2];			// 主平面的圆心坐标
	long slaveCent[2];			// 次平面的圆心坐标
	long masterStart[2];		// 主平面的起点坐标
	long slaveStart[2];			// 次平面的起点坐标

	short slaveAxMask;			// 从轴掩码，两个轴，非坐标系内
	short reserved[3];			// 保留参数

}TCrdSymmParam;

// 设置对称运动参数
MTN_API short __stdcall OEM_CrdSetSymmParam(  HAND crdHandle, TCrdSymmParam *pParam);

// 启动或关闭对称跟随运动
MTN_API short __stdcall OEM_CrdBufSymmOnOff(  HAND crdHandle, long segNo,short onOff);


// 圆形限位
typedef struct 
{  
	short axMask;		// 关联的轴掩码
	short mode;			// 0:触发后停止关联轴运动，1：停止并置起急停标志位
	long centPosX;		// 圆形限位的圆心X，单位：pulse
	long centPosY;		// 圆形限位的圆心Y，单位：pulse
	long radius;		// 半径，半径为0表示取消该通道的圆形区域限位检查，单位：pulse
	float yProp;		// 系数，Y方向的当量除以X方向的当量
	float reserved2;	// 保留
}TCircleLimitPara;

// 设置圆形限位区域 
// pPara:参数
// chn:通道号，可以设置多组
MTN_API short __stdcall OEM_SetCircleLimit(HAND devHandle,TCircleLimitPara *pPara,short chn);
MTN_API short __stdcall OEM_GetCircleLimit(HAND devHandle,TCircleLimitPara *pPara,short chn);


//------------------------------------------------------------------------------------------------------------
//
//	Scan
//
//------------------------------------------------------------------------------------------------------------
 
// 振镜通道数量
#define OEM_SCAN_MAX_CHN		1

// 振镜控制数据清除
MTN_API short __stdcall OEM_ScanBufClr(HAND devHandle,short chn);

// 振镜控制的启动及停止，0：停止，1:启动
MTN_API short __stdcall OEM_ScanOnOff(HAND devHandle,short onOff,short chn);

// 所有数据压完
MTN_API short __stdcall OEM_ScanEndList(HAND devHandle,short chn);

// 振镜控制指令，运动指令,绝对运动
// pXPosArray:x方向的位置数据
// pYPosArray:y方向的位置数据
// cnt:数组包含的数据个数
MTN_API short __stdcall OEM_ScanBufMoveAbs(HAND devHandle,short *pXPosArray,short *pYPosArray,short cnt,short chn);

// 振镜控制指令，运动指令,相对运动
// pXPosArray:x方向的位置数据
// pYPosArray:y方向的位置数据
// cnt:数组包含的数据个数
MTN_API short __stdcall OEM_ScanBufMoveRel(HAND devHandle,short *pXPosArray,short *pYPosArray,short cnt,short chn);

// 振镜控制指令，设置位置模式
// posMode:位置模式，0：绝对，默认，1：相对
MTN_API short __stdcall OEM_ScanBufSetPosMode(HAND devHandle,short posMode,short chn);

// 振镜控制指令，更新段号
// segNo:段号
MTN_API short __stdcall OEM_ScanBufSetSegNo(HAND devHandle,long segNo,short chn);

// 振镜控制指令，延时指令
// delayUs:延时时间，单位us
MTN_API short __stdcall OEM_ScanBufDelay(HAND devHandle,long delayUs,short chn);

// 振镜控制指令，激光开关指令
// laserOnOff:开关
MTN_API short __stdcall OEM_ScanBufLaserOnOff(HAND devHandle,short laserOnOff,short chn);

// 振镜控制指令，激光开关光延时
// onDelay:开光延时，单位us,取值范围[0,65535]
// offDelay:关光延时，单位us,取值范围[0,65535]
MTN_API short __stdcall OEM_ScanBufLaserSetOnOffDelay(HAND devHandle,double onDelay,double offDelay,short chn);

// 振镜控制指令，激光能量PWM设置
// pulseWid:PWM宽度，单位us,取值范围[0.25,16000]
// onTime:on时间，单位us,,取值范围[0.25,16000]
MTN_API short __stdcall OEM_ScanBufLaserSetPowerPwm(HAND devHandle,double pulseWid,double onTime,short chn);

// 振镜控制指令，激光能量DAC设置
// dac:电压输出值
MTN_API short __stdcall OEM_ScanBufLaserSetPowerDac(HAND devHandle,short dac,short chn);


//状态位定义
#define BIT_SCAN_EN					(0x00000001)    // 使能标志位 
#define BIT_SCAN_RUN				(0x00000002)    // 运动:1 ,静止 0   
#define BIT_SCAN_END				(0x00000004)    // 是否End标志位
#define BIT_SCAN_BUF_FULL			(0x00000008)    // 数据满    
#define BIT_SCAN_BUF_EMPTY			(0x00000010)    // 数据空    
#define BIT_SCAN_ERR_PUSH	        (0x00001000)    // 压数据错误    
#define BIT_SCAN_ERR_POP	        (0x00002000)    // 取数据错误
#define BIT_SCAN_ERR_OTHER	        (0x00004000)    // 其他错误，参考errCode

typedef struct 
{  
	long sts;				// 运行状态，按位表示，如上
	long userSeg;			// 用户段号
	long leftSpace;			// 剩余空间
	long usedSpace;			// 使用空间
	unsigned long cmdAllCnt;// 全部指令的计数
	short xPos;				// x方向当前位置
	short yPos;				// y方向当前位置
	short errCode;			// 错误码
	short reserved[3];		// 保留

}TOemScanSts;

// 获取振镜的运行状态
MTN_API short __stdcall OEM_ScanGetSts(HAND devHandle,TOemScanSts *pSts,short chn);


// 手动：运动到指定点
MTN_API short __stdcall OEM_ScanMoveAbs(HAND devHandle,short x,short y,short chn);

// 手动：开光
MTN_API short __stdcall OEM_ScanLaserOnOff(HAND devHandle,short onOff,short chn);

// 手动：输出PWM
// pulseWid:PWM宽度，单位us,取值范围[0.5,16000]
// onTime:on时间，单位us
MTN_API short __stdcall OEM_ScanLaserPowerPwm(HAND devHandle,double pulseWid,double onTime,short chn);

// 手动：输出DAC
MTN_API short __stdcall OEM_ScanLaserPowerDac(HAND devHandle,short dac,short chn);

//------------------------------------------------------------------------------------------------------------
//
//         事件
//
//------------------------------------------------------------------------------------------------------------
#define EVENT_MAX_CHN		8

// event src
#define EVENT_SRC_PRFPOS	0				// 规划位置
#define EVENT_SRC_ENCPOS	1				// 实际位置

// event dir
#define EVENT_DIR_BIGGER		0			// 大于
#define EVENT_DIR_SMALLER		1			// 小于
#define EVENT_DIR_EQUAL			2			// 等于
#define EVENT_DIR_NOT_BIGGER	3			// 不大于
#define EVENT_DIR_NOT_SMALLER	4			// 不小于
#define EVENT_DIR_NOT_EQUAL		5			// 不等于

// action ID
#define EVENT_ACTION_NONE		0			// 不执行任何的动作
#define EVENT_ACTION_SETDO		1			// 设置DO（idx:组号，param1:输出位掩码，param2:输出值掩码
#define EVENT_ACTION_PTP_VEL	2			// 更新PTP的速度（idx:轴号，param1:速度，param2:保留
 
typedef struct
{
 	short eventSrc;							// 事件的源，如EVENT_SRC_PRFPOS
 	short eventIdx;							// 事件的序号
	short dir;								// 方向
	short errZone;							// 误差
	long trigCnt;							// 触发次数
	long eventReserved[3];					// 保留
	double compVal1;						// 比较值
	
	short actionType;						// 事件触发后的动作类型
	short actionIdx;						// 动作序号
	float actionParam1;						// 动作参数
	float actionParam2;						// 动作参数2
	short actionReserved[6];				// 保留
} TEventConfig;

// 事件配置
// pEventCfg:配置参数，参见结构体定义
// chn:通道号，取值范围[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_DevEventSetConfig(HAND devHandle, TEventConfig *pEventCfg,short chn);

// 获取事件配置
// pEventCfg:配置参数，参见结构体定义
// chn:通道号，取值范围[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_DevEventGetConfig(HAND devHandle,TEventConfig *pEventCfg,short chn);

// 获取事件开关
// onOff:开关，0:关 1:开
// chn:通道号，取值范围[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_DevEventSetOnOff(HAND devHandle,short onOff,short chn);

// 获取状态
// pOnOff:开关状态，0:关 1:开
// pTrigCnt:触发计数
// chn:通道号，取值范围[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_DevEventGetSts(HAND devHandle,short *pTrigCnt,short *pOnOff,short chn);

// 缓冲区配置事件及开关
// pEventCfg:配置信息
// onOff:是否立即开启关闭
// chn:通道号，取值范围[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_CrdBufEventSetConfig(HAND crdHandle,long segNo,TEventConfig *pEventCfg,short onOff,short chn);

// 缓冲区事件开关
// onOff:是否立即开启关闭
// chn:通道号，取值范围[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_CrdBufEventSetOnOff(HAND crdHandle,long segNo,short onOff,short chn);

// 缓冲区等待事件触发
// trigCnt:触发的事件计数
// timeOut:超时 单位:ms
// chn:通道号，取值范围[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_CrdBufEventWait(HAND crdHandle,long segNo,short trigCnt,long timeOut,short chn);

// 机构示教开始
// startPos:起始位置，单位:脉冲
// interval:间隔，单位:脉冲
// sectCount:示教的段数
// pFileNameToSaveTechData:示教数据的存储文件
MTN_API short  __stdcall OEM_MtLeadScrewTechRun(HAND axisHandle,long startPos,long interval,long sectCount,char *pFileNameToSaveTechData);

// 机构示教过程状态查询
// pRun:运行状态，0：停止中，1：正在运行，其他：错误代码
// pPercent:运行的进度百分比
MTN_API short  __stdcall OEM_MtLeadScrewTechSts(HAND axisHandle,short *pRun,short *pPercent);

// 机构示教强制终止
MTN_API short  __stdcall OEM_MtLeadScrewTechBreak(HAND axisHandle);

// 加载机构示教数据
// pFileNameTechData:数据文件名
MTN_API short  __stdcall OEM_MtLeadScrewTechLoad(HAND axisHandle,char *pFileNameTechData);



// 单轴编码器的配置
typedef struct
{
	short encoderIdx;		//编码器编号，取值范围[0,n],256表示辅助编码器
	short encoderMode;		//编码器模式，请参考NMC_SetEncMode说明
	short reserved[6];		// 保留
}TEncoderCfg;

//设置单轴编码器的配置
MTN_API short  __stdcall OEM_MtSetEncCfg (HAND axisHandle,TEncoderCfg *pPara);

//获取单轴编码器的配置
MTN_API short  __stdcall OEM_MtGetEncCfg (HAND axisHandle,TEncoderCfg *pPara);


// 两段速PTP运动
// pPrfTime:对于规划位置触发，返回整个规划需要的时间
MTN_API short  __stdcall OEM_MtMovePtpAbsTwoStageEx(HAND axisHandle,TPtpTwoStagePrm *pPrm,double *pPrfTime);

// 功能：2维位置比较自动连续输出
// onOff： 0 停止,1输出 注意：NMC_Comp2DimensOnoff关闭也可以实现关闭连续输出
// group:组号,0 或者1
// outInteval:输出间隔，单位us
// outCnt:输出次数
// chn:保留,设为0
MTN_API short __stdcall OEM_Comp2DimensOutPulse(HAND devHandle,short group,short onOff,long outInteval,long outCnt,short chn);


// PT及PVT OEM
// 查询PT数据剩余空间大小
// pSpace:返回的剩余空间大小
// pUsed: 已使用的空间段数
// fifo:在数据贮存模式下，使用的FIFO编号，取值范围[0,1]
MTN_API short  __stdcall OEM_MtPtGetSpaceEx(HAND axisHandle,short *pSpace,short *pUsed,short fifo);

// 向Pt运动缓存区中压运动数据段
// count:压入的数据段数
// pPosArray:段运行距离
// pTimeArray:段运行时间
// pTypeArray:段类型,见宏定义
// fifo:在数据贮存模式下，使用的FIFO编号，取值范围[0,1]
MTN_API short  __stdcall OEM_MtPtPushEx(HAND axisHandle,short count,double *pPosArray,long *pTimeArray,short *pTypeArray,short fifo);

// 清空PT数据
// fifo:在数据贮存模式下，使用的FIFO编号，取值范围[0,1]
MTN_API short  __stdcall OEM_MtPtBufClrEx(HAND axisHandle,short fifo);

// 启动Pt运动
// otherSynAxCnts： 不包括axisHandle 的其他同步启动轴数量
// pOtherSynAxArray: 其他同步启动轴的序号：0~N	
// fifo:在数据贮存模式下，使用的FIFO编号，取值范围[0,1]
MTN_API short  __stdcall OEM_MtPtStartMtnEx(HAND axisHandle,short otherSynAxCnts,short *pOtherSynAxArray,short fifo);

// 向PVT运动缓存区中压运动数据段
// count:压入的数据段数：1~32
// pPosArray:段运行距离
// pTimeArray:段运行时间
// pVelArray:段运行速度
// fifo:在数据贮存模式下，使用的FIFO编号，取值范围[0,1]
MTN_API short  __stdcall OEM_MtPvtDataEx(HAND axisHandle,short count,double *pPosArray,double *pTimeArray,double *pVelArray,short fifo);

// 查询PVT数据剩余空间大小
// pFreeSpace:返回的剩余空间大小
// pUsedSpace: 已使用的空间段数
// fifo:在数据贮存模式下，使用的FIFO编号，取值范围[0,1]
MTN_API short  __stdcall OEM_MtPvtBufGetSpaceEx(HAND axisHandle,short *pFreeSpace,short *pUsedSpace,short fifo);

// 清空PVT数据
// fifo:在数据贮存模式下，使用的FIFO编号，取值范围[0,1]
MTN_API short  __stdcall OEM_MtPvtBufClrEx(HAND axisHandle,short fifo);

// 启动Pvt运动
// otherSynAxCnts： 不包括axisHandle 的其他同步启动轴数量
// pOtherSynAxArray: 其他同步启动轴的序号：0~N	
// fifo:在数据贮存模式下，使用的FIFO编号，取值范围[0,1]
// 注：同步的轴必须属于同一个控制器
MTN_API short  __stdcall OEM_MtPvtStartMtnEx(HAND axisHandle,short otherSynAxCnts,short *pOtherSynAxArray,short fifo);

// 获取编码器位置（补偿前）
// pEncPosEx:补偿前的编码器位置
MTN_API short  __stdcall OEM_MtGetEncPosEx(HAND axisHandle,long *pEncPosEx);

// PTPBufMv
#define PTPBUFMV_MAX_GROUP		2		// 最大的组数
#define PTPBUFMV_MAX_AX			4		// 最大的参与轴数量
#define PTPBUFMV_MAX_SEC		4		// 最大的段数

// Ptp运动单元
typedef struct
{
	float acc;
	float dec;
	float velS;
	float velE;
	float velMax;
	long tgtPos;
	short smooth;
	short setDelay;
	short reserved[4];
}TPtpBufMvUnit;

typedef struct
{
	short run;				// 0:Stop,1:running;2:error
	short errCode;			// 错误代码
	short curUnitIdx;		// 当前执行的单元序号
	short reserved[3];		// 其他
}TPtpBufMvSts;

// 压入Ptp多轴运动参数
// axisCnt:参与的轴数量，取值范围[1,4]
// pAxisList:参与的轴列表数组
// unitCnt:运动的段数量，取值范围[1,4]
// pMvUnitList:运动的段数组列表，数组长度为axisCnt*unitCnt
// group:组号，取值范围[0,1]
MTN_API short  __stdcall OEM_PtpBufMvPushData(HAND devHandle,short axisCnt,short *pAxisList,short unitCnt,TPtpBufMvUnit *pMvUnitList,short group);

// 启动Ptp多轴运动
// group:组号，取值范围[0,1]
MTN_API short  __stdcall OEM_PtpBufMvStart(HAND devHandle,short group);

// 停止Ptp多轴运动
// group:组号，取值范围[0,1]
MTN_API short  __stdcall OEM_PtpBufMvStop(HAND devHandle,short group);

// 查询Ptp多轴运动状态
// group:组号，取值范围[0,1]
// pSts:状态
MTN_API short  __stdcall OEM_PtpBufMvSts(HAND devHandle,TPtpBufMvSts *pSts,short group);




/*

//-------------------------------------------------------------------------------
//1.多轴运动
//-------------------------------------------------------------------------------
// 多轴运动配置
// mapNum:参与的轴数量; pMapNo:轴列表
NMC_API short __stdcall NMC_MultiLineSetsysPara(HAND multiHandle,short *pMapNo,short mapNum);
// 压入多轴运动数据
// pEndPos:终点位置; vel:速度 ;acc:速度 ;dec:速度 ;blendRatio:混合系数;userID:用户ID
NMC_API short __stdcall NMC_MultiLineAddMoveData(HAND multiHandle,double *pEndPos,double vel,double acc,double dec,double blendRatio,long userID);
// 清除多轴运动数据
NMC_API short __stdcall NMC_MultiLineClrData(HAND multiHandle,long *pSpace);
// 启动多轴运动
NMC_API short __stdcall NMC_MultiLineStart(HAND multiHandle);
// 停止多轴运动
NMC_API short __stdcall NMC_MultiLineStop(HAND multiHandle,short stopType);
// 获取多轴运动状态
NMC_API short __stdcall NMC_MultiLineGetSts(HAND multiHandle,short *pRunSts,short *pErr);
// 相关的其他指令
NMC_API short __stdcall NMC_MultiLineOpen(HAND devHandle, PHAND pMultiLinedHandle );
NMC_API short __stdcall NMC_MultiLineClose( PHAND pMultiLinedHandle );
NMC_API short __stdcall NMC_MultiLineGetsysPara(HAND multiHandle,short *pMapNo,short *pMapNum,short *pIsActive);
NMC_API short __stdcall NMC_MultiLineDelete(HAND multiHandle);
NMC_API short __stdcall NMC_MultiLineSetOverRide(HAND multiHandle,double ratio);
NMC_API short __stdcall NMC_MultiLineGetOverRide(HAND multiHandle,double *pRatio);
NMC_API short __stdcall NMC_MultiLineGetUserID(HAND multiHandle,long *pUserID);
NMC_API short __stdcall NMC_MultiLineGetDataSpace(HAND multiHandle,long *pSpace);
NMC_API short __stdcall NMC_MultiLineGetPrfVel(HAND multiHandle,double *pVel);
NMC_API short __stdcall NMC_MultiLineClrErr(HAND multiHandle);


//-------------------------------------------------------------------------------
//2.多维位置比较
//-------------------------------------------------------------------------------
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
	long out2Delay;								// 输出2的滞后时间，单位us
	long reserved[7];							// 保留，默认值 0（不使用）
} TComp2DimensParamEx;

typedef struct
{
	short axCnt;				// 参与的轴数量，取值[1,6]
	short axList[6];			// 参与的轴列表
	short outType;				// 输出方式0：脉冲1：电平
	short outChnType;			// 通道类型：0 GPO, 1  GATE通道
	short outChnIdx;			// 比较输出信号的通道号，取值[0,n]
	short posSrc;				// 轴位置类型 ：0规划1：编码器
	short stLevel;				// 电平模式下的起始电平（0或1）
	long gateTime;				// 脉冲方式脉冲时间,单位us
	long errZone;				// 进入比较点容差半径范围（pulse）
	long directOutZone;			// 近距离直接触发范围
	long reserved[7];			// 保留，默认值 0（不使用）
} TCompXDimensExParam;

// 设置多维位置比较
// pParam:参数  group:组号，取值[0,n]
NMC_API short __stdcall OEM_CompXDimensExSetParam(HAND hDev,TCompXDimensExParam *pParam,short group);
NMC_API short __stdcall OEM_CompXDimensExGetParam(HAND hDev,TCompXDimensExParam *pParam,short group);

// 功能：设置多维位置比较数据
// pArrayPos:比较数据位置值
// count:位置点数,count=0表示清除已经缓存的数据。一次性最多压入128组数据
// group:组号,0 或者1
MTN_API short __stdcall OEM_CompXDimensExSetData(HAND devHandle,long *pArrayPos,short count,short group);

// 功能：清除多维位置比较数据
MTN_API short __stdcall OEM_CompXDimensExClrData(HAND devHandle,short group);

// 功能：多维位置比较使能
// onOff： 0 停止,1输出  
MTN_API short __stdcall OEM_CompXDimensExOnoff(HAND devHandle,short onOff,short group);

// 功能：多维位置比较手动输出
MTN_API short __stdcall OEM_CompXDimensExManual(HAND devHandle,short outCnt,short group);

typedef struct
{
	short sts;				// 运行状态，0 空闲 1 忙
	short reserved1;		// 保留
	long freeSpace;			// 控制器剩余空间
	long usedSpace;			// 剩余位置比较点
	long outCount;			// 已经输出的个数
	long reserved2[4];		// 保留
} TCompXDimensExSts;

// 功能：多维位置比较的输出状态
// pStatus: 状态结构体
// group:组号,0 或者1
MTN_API short __stdcall OEM_CompXDimensExGetSts(HAND devHandle,TCompXDimensExSts *pStatus,short group);

*/





#ifdef __cplusplus
}
#endif






#endif	// _H_MTN_LIB20_OEM_H_
