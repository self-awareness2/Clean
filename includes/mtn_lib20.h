////**********************************************************************************************************
//
//  Copyright(c) 2017, Shenzhen Gaochuan Industrial Automation Co.,Ltd
//
//  Moudle Name :   nmc_lib20.h
//
//  Abstract    :   GaoChuan Motion 2.0 User Header
//
//  Note        :   1.结构体定义中所有的'reservedxxx'的成员都是保留参数,为保持向后兼容性,请设置为0。
//                  2.无特别说明,所有API返回RTN_CMD_SUCCESS（即0值）表示执行成功,其他则表示错误代码,见mtn_lib20_err.h。
//                  3.所有的API参数中,无特别说明,axisHandle表示操作轴的句柄,devHandle表示目标控制器的句柄,
//                    crdHandle表示目标坐标系组句柄。
//                  4.若无特别说明,所有API的参数中,牵涉到序号则从0开始,比如NMC_MtOpen中的itemNo参数,0表示第一个轴。
//                  5.mtn_lib20中所有的结构体都是以四字节对齐方式编译，为了避免结构体对齐引起的问题，请将编译环境设置为四字节对齐
// Modification History :
//
////**********************************************************************************************************
#ifndef _H_NMC_LIB20_H_
#define _H_NMC_LIB20_H_

#ifdef __cplusplus
extern "C" {
#endif

//------------------------------------------------------------------------------------------------------------
//
//              宏定义
//
//------------------------------------------------------------------------------------------------------------
// 编译控制
#ifndef MTN_API
    #ifdef WIN32 
        #ifdef NMC_LIB_EXPORTS
            #define MTN_API __declspec(dllexport)
        #else
            #define MTN_API __declspec(dllimport)
        #endif
    #else
        #define MTN_API 
        #define __stdcall 
    #endif    
#endif

// 句柄类型定义
typedef     unsigned short*     PHAND;
typedef     unsigned short      HAND;

//------------------------------------------------------------------------------------------------------------
//
//           指令分组索引
//
//------------------------------------------------------------------------------------------------------------
//  1.控制器连接、关闭
//  2.单轴配置
//  3.单轴控制
//  4.单轴状态读取
//  5.IO控制及外部资源读写
//  6.坐标系配置
//  7.坐标系控制
//  8.坐标系及运动缓冲区状态读取
//  9.缓冲区插补运动和IO控制
//  10.回零
//  11.电子齿轮
//  12.电子凸轮
//------------------------------------------------------------------------------------------------------------
//
//          1.控制器连接、关闭
//
//------------------------------------------------------------------------------------------------------------
// 通讯模式设置
typedef enum { USB=0, Ethernet, RS485 } TSearchMode;

//设备信息结构
typedef struct
{
    unsigned short address;     // 在上位机系统中的设备序号,
    char  idStr[16];            // 识别字符串
    char  description[64];      // 描述符
    unsigned short ID;          // 板上的ID(未用)
}TDevInfo;

// 板卡搜寻
// 参数: mode:通讯模式
// pDevNo : 返回设备的数目
// pInfoList：返回设备信息
MTN_API short __stdcall NMC_DevSearch( TSearchMode mode, unsigned short *pDevNo, TDevInfo *pInfoList );

// 板卡打开（根据序号）
// devNo: 设备序号,取值范围[0,n]； pDevHandle: 返回设备操作句柄
MTN_API short __stdcall NMC_DevOpen       ( short devNo, PHAND pDevHandle );

// 板卡关闭
// pDevHandle : 设备句柄指针
MTN_API short __stdcall NMC_DevClose(PHAND pDevHandle );

// 板卡复位
MTN_API short __stdcall NMC_DevReset(HAND devHandle );

// 打开单轴
// devHandle : 设备句柄
// itemNo：轴号,取值范围[0,n]
// pCrdHandle：坐标系组句柄
MTN_API short  __stdcall NMC_MtOpen(HAND devHandle, short itemNo, PHAND pAxisHandle ); 

// 关闭单轴
// devHandle : 设备句柄指针
MTN_API short  __stdcall NMC_MtClose(PHAND pAxisHandle );

// 打开坐标系组(支持多坐标系)
// itemNo：坐标系号,取值范围[0,1]
// pCrdHandle：返回坐标系组句柄
MTN_API short __stdcall NMC_CrdOpenEx( HAND devHandle,short itemNo, PHAND pCrdHandle );

// 关闭坐标系组
// pCrdHandle：坐标系组句柄
MTN_API short __stdcall NMC_CrdClose(PHAND pCrdHandle );

//------------------------------------------------------------------------------------------------------------
//
//          2.单轴配置
//
//------------------------------------------------------------------------------------------------------------
// 系统扩展资源的起始ID,包括扩展编码器／模拟量输入输出
#define EXT_RES_START_INDEX  256

// 编码器模式：定义信号源,信号类型,取反,,编码器分频等 
// Bit7:0 分频系数,数值为0~255。对应分频数值 1~256
// Bit9:8 信号号源选择
//   00：外部信号输入
//   01: 轴脉冲输入
//   10：自动产生信号（正脉冲）
//   11：自动产生信号（负脉冲）
// Bit11:10 信号类型（外部）
//  00：AB相,90度差
//  01：脉冲+方向
//  10：正脉冲+负脉冲
//  11：保留
// Bit12 输入A、B交换（外部） 0：不交换,1：交换
// Bit13 输入A取反（外部） 0：不取反,1：取反
// Bit14 输入B取反（外部） 0：不取反,1：取反
// Bti15 编码器饱和,0：最大最小值翻转,1：不翻转
// 设置编码器模式
// encId: 编码器ID,对于轴编码器通道,取值范围[0,n],
//                对于扩展编码器通道,256表示第一个扩展编码器通道,257表示第二个,以此类推
// encMode:编码器模式,参考宏定义
MTN_API short  __stdcall NMC_SetEncMode( HAND devHandle, short encId,  short encMode );

// 设置软件限位是否停止运动
// enable：软件限位触发允许设置,1为允许,0为禁止
MTN_API short  __stdcall NMC_MtSwLmtOnOff  ( HAND axisHandle, short swt );

// 设置软件限位数值
// posLmt：正向软件限位设置值
// negLmt：负向软件限位设置值。单位为脉冲数
MTN_API short  __stdcall NMC_MtSwLmtValue  ( HAND axisHandle, long posLmt,long negLmt );

//轴运动安全参数
typedef struct
{
    double estpDec;     // 急停加速度
    double maxVel;      // 最大速度
    double maxAcc;      // 最大加速度
}TSafePara;
// 设置轴安全参数
// TSafePara：包含急停减速度、最大允许速度、最大允许加速度
MTN_API short  __stdcall NMC_MtSetSafePara( HAND axisHandle, TSafePara *pPara );

// 设置脉冲输出模式
// inv, 1：取反,0：不取反
// mode 0：脉冲方向 1：正负脉冲
MTN_API short  __stdcall NMC_MtSetStepMode ( HAND axisHandle, short inv, short mode );

// 设置轴速度滤波参数
// 注：filterCoef系数在0~5之间,值越大,速度越平滑，默认值为0
MTN_API short __stdcall NMC_MtSetAxisVelFilter(HAND axisHandle,short filterCoef);

// 硬件限位配置
// posLmtEnable: 正向限位触发允许设置,1为允许,0为禁止
// negLmtEnable: 负向限位触发允许设置,1为允许,0为禁止
// posLmtSns: 正向限位触发电平,1为高电平触发,0为低电平触发
// negLmtSns: 正向限位触发电平,1为高电平触发,0为低电平触发
MTN_API short __stdcall NMC_MtSetLmtCfg( HAND axisHandle, short posLmtEnable,short negLmtEnable,short posLmtSns,short negLmtSns );

// 伺服报警配置
// alarmEnable: 伺服报警触发允许设置,1为允许,0为禁止
// alarmSns:     伺服报警触发电平,1为高电平触发,0为低电平触发
MTN_API short __stdcall NMC_MtSetAlarmCfg( HAND axisHandle, short alarmEnable,short alarmSns );

// 设置脉冲输出滤波
// coe系数： 范围0~65535,0不滤波,数值越大滤波效果越明显。
MTN_API short  __stdcall NMC_MtSetStepFilter ( HAND axisHandle, unsigned short  coe );

//------------------------------------------------------------------------------------------------------------
//
//          3.单轴控制指令
//
//------------------------------------------------------------------------------------------------------------
// 各轴的规划模式
#define MT_NONE_PRF_MODE        (-1)            // 无效
#define MT_PTP_PRF_MODE         (0)             // 梯形规划
#define MT_JOG_PRF_MODE         (1)             // 连续速度模式
#define MT_CRD_PRF_MODE         (3)             // 坐标系
#define MT_GANTRY_MODE          (4)             // 龙门跟随模式
#define MT_PT_PRF_MODE			(5)				// PT模式
#define MT_MULTI_LINE_MODE		(6)				// 多轴直线插补
#define MT_GEAR_PRF_MODE		(7)				// 电子齿轮模式
#define MT_FOLLOW_PRF_MODE		(8)				// Follow跟随模式
#define MT_PVT_PRF_MODE			(9)				// PVT

// 设置单轴规划模式
// mode：单轴运动模式
MTN_API short __stdcall NMC_MtSetPrfMode(HAND axisHandle,short mode);

// 单轴PTP运动参数结构
typedef struct
{
    double acc;         // 加速度
    double dec;         // 减速度
    double startVel;    // 起跳速度
    double endVel;      // 终止速度
    short smoothCoef;   // 平滑系数,取值范围[0,199]
    short reserved[3];      // 保留
}TPtpPara;
// 设置多个参数, 并更新。
// pAxPara：参数,参考结构定义。
MTN_API short __stdcall NMC_MtSetPtpPara( HAND axisHandle, TPtpPara *pAxPara );

typedef struct
{
   double totalTime;	// 当前点位运动的总时间，单位:ms
   double leftTime;		// 当前点位运动的剩余时间，单位:ms
   double reseved[2];	// 保留
}TTrapTime;

// 获取当前点位运动执行时间参数
MTN_API short  __stdcall  NMC_MtGetTrapTime(HAND axisHandle,TTrapTime *pTrapTime);

// 单轴JOG运动参数结构
typedef struct
{
    double acc;         // 加速度
    double dec;         // 减速度
    double smoothCoef;  // 平滑系数,取值范围[0,199],数值越大则速度变化越平滑
}TJogPara;
// 设置Jog运动参数
// pAxPara：参数,参考结构定义。
MTN_API short __stdcall NMC_MtSetJogPara   ( HAND axisHandle, TJogPara *pAxPara );

// 设置目标运动速度,只针对PTP和Jog：PTP模式下只接受正数,Jog模式下正负号标识运动方向
// vel: 目标速度（最大速度）,单位是 脉冲/ms
MTN_API short __stdcall NMC_MtSetVel( HAND axisHandle, double vel );

// 设置目标运动位置,只针对PTP
// pos: 目标位置,单位是 脉冲
MTN_API short __stdcall NMC_MtSetPtpTgtPos( HAND axisHandle, long pos );

// 参数更新, 只针对PTP和Jog
MTN_API short __stdcall NMC_MtUpdate( HAND axisHandle );

// 单轴运动停止
// 注：运动会按设定的减速度停止。
MTN_API short __stdcall NMC_MtStop( HAND axisHandle );

// 单轴急停，不会置起急停标志位
// 注：运动会按设定的急停加速度停止。如果没有设置,则会立即停止。
MTN_API short __stdcall NMC_MtAbruptStop( HAND axisHandle );

// 单轴位置系统清零,规划以及编码器
MTN_API short __stdcall NMC_MtZeroPos( HAND axisHandle);

// 设置伺服报警清除输出的状态
// swt: 设置开关有效状态。0, 有效（输出低电平）,1,无效（输出高电平）
MTN_API short  __stdcall NMC_MtSetSvClr( HAND axisHandle, short swt );

// 设置伺服ON, 轴静止时执行,如果后面是update指令,需要延时一个周期
MTN_API short  __stdcall NMC_MtSetSvOn( HAND axisHandle );

// 设置伺服OFF, 轴静止时执行,如果后面是update指令,需要延时一个周期
MTN_API short  __stdcall NMC_MtSetSvOff( HAND axisHandle );

// 清除轴错误状态
MTN_API short  __stdcall NMC_MtClrError ( HAND axisHandle );

// 清除轴错误状态,按位清除
// stsMask:对应位为1表明需要清除对应位的错误状态
MTN_API short  __stdcall NMC_MtClrStsByBits(HAND axisHandle , short stsMask);

// 单轴点位运动,包含NMC_MtSetPrfMode,NMC_MtSetPtpPara,NMC_MtSetVel,NMC_MtSetPtpTgtPos,NMC_MtUpdate
// acc:加速度,dec：减速度,startVel:起跳速度,endVel:终止速度,smoothCoef:平滑系数
// maxVel：最大速度
// tgtPos:目标位置,单位：脉冲
MTN_API short  __stdcall NMC_MtMovePtpAbs(HAND axisHandle,double acc,double dec,double startVel,double endVel,double maxVel,short smoothCoef,long tgtPos);

// 单轴连续速度运动
// acc:加速度,dec：减速度,smoothCoef:平滑系数
// maxVel：最大速度
// clrStsFlag:是否运动前先清除轴状态，0：不清除，1：清除
MTN_API short  __stdcall NMC_MtMoveJog(HAND axisHandle,double acc,double dec,double maxVel,
                                        short smoothCoef,short clrStsFlag);
typedef struct
{
	short axisMask;			// 轴掩码，对应bit为1表示该轴参与运动
	short clrStsFlag;		// 是否运动前先清除轴状态，0：不清除，1：清除
	short reserved[2];		// 保留
    double acc[8];			// 加速度
    double dec[8];			// 减加速度
    double startVel[8];		// 起跳速度
    double endVel[8];		// 终止速度
	double maxVel[8];		// 最大速度
	short  smoothCoef[8];	// 平滑系数
	long tgtPos[8];			// 位置，单位:脉冲
}TMovePtpPack8;
// 单轴点位运动打包(绝对运动)
// axisFirstHandle:数组的第一个轴句柄
// pPackData:打包参数
// 注意：1.如果某轴存在无法运动的错误状态，则所有轴不会启动运动
MTN_API short  __stdcall NMC_MtMovePtpAbsPack8(HAND axisFirstHandle,TMovePtpPack8 * pPackData);

// 单轴点位运动打包(相对运动)
// axisFirstHandle:数组的第一个轴句柄
// pPackData:打包参数
// 注意：1.如果某轴存在无法运动的错误状态，则所有轴不会启动运动
MTN_API short  __stdcall NMC_MtMovePtpRelPack8(HAND axisFirstHandle,TMovePtpPack8 * pPackData);

// 单轴点位运动,相对运动
// acc:加速度,dec：减速度,startVel:起跳速度,endVel:终止速度,smoothCoef:平滑系数
// maxVel：最大速度
// relPos:相对当前位置的移动量,单位：脉冲
MTN_API short  __stdcall NMC_MtMovePtpRel(HAND axisHandle,double acc,double dec,double startVel,double endVel,double maxVel,short smoothCoef,long relPos);

// 多轴同步运动（通过PTP实现）
// axisMask:参与轴的掩码
// acc,dev:加速度,减速度
// sVel,eVel，maxVel:启动速度,终点速度，最大速度
// smooth:平滑系数
// pPosArray:目标位置数组
MTN_API short __stdcall NMC_MtMultiMoveAbs(HAND devHandle,short axisMask,double acc,double dec,double sVel,
	double eVel,double maxVel,short smooth,long *pPosArray);

// PTP两段速运动参数
typedef struct
{ 
    double acc;         // 加速度
    double dec;         // 减速度
    double startVel;    // 启动速度
    double endVel;      // 终点速度
    double maxVel;      // 最大速度
    long tgtPos;        // 目标位置
    short reserved;      // 保留参数
    short smoothCoef;   // 平滑系数
    short inType;       // 输入类型：0：通用DI，1：Home信号; 
    short inIdx;       //  输入信号通道号
    short inTrigLevel; // 触发电平，0：低电平，1：高电平
    short action;       // 触发后的动作，0：不动作，1：更新目标速度,
                                                // 2.更新目标位置
                                                // 3:更新目标位置（位置为相对触发点的相对位置）
                                                // 4:急停
    double prm1;        // action=1时表示更新的目标速度
    double prm2;        // action=2，3时表示更新的目标位置
    double prm3;        // 保留
    double prm4;        // 保留
} TPtpTwoStagePrm;

// 两段速PTP运动
MTN_API short  __stdcall NMC_MtMovePtpAbsTwoStage(HAND axisHandle,TPtpTwoStagePrm *pPrm);

//------------------------------------------------------------------------------------------------------------
//
//         4.单轴状态读取
//
//------------------------------------------------------------------------------------------------------------
// 读取规划坐标系的位置
// pPos : 返回位置,单位是 脉冲
MTN_API short __stdcall NMC_MtGetPrfPos   ( HAND axisHandle, long *pPos );

// 读当前轴规划速度
// pVel: 返回速度,单位是 脉冲/ms
MTN_API short __stdcall NMC_MtGetPrfVel   ( HAND axisHandle, double *pVel );

// 读取打包轴状态（4轴）
#define PACK_AXIS_NUM   4
typedef struct
{
    long prfPos[PACK_AXIS_NUM];     // 规划位置
    long encPos[PACK_AXIS_NUM];     // 实际位置
    float prfVel[PACK_AXIS_NUM];    // 规划速度
    long motionIO[PACK_AXIS_NUM];   // 轴专用IO
    short sts[PACK_AXIS_NUM];       // 轴状态
    long gpo;                       // 通用输出
    long gpi;                       // 通用输入
}TAxisStsPack;
// 打包读取多个轴的状态,从第一个轴开始读取后续四个轴的状态
// axisFirstHandle : 第一个轴句柄
// count:读取状态的轴数量,取值范围：[1,4]
// pPackSts: 打包的状态数据,参考结构体定义
MTN_API short  __stdcall NMC_MtGetStsPack  ( HAND axisFirstHandle, short count,TAxisStsPack *pPackSts );

// 读取打包轴状态（12轴）
typedef struct
{
    short          mtSts[12];          // 单轴状态，位定义参考NMC_MtGetSts
    short          mtMio[12];          // 单轴专用IO,位定义参考NMC_MtGetMotionIO
    short          mtMioLog[12];       // 单轴专用IO:逻辑电平,位定义参考NMC_MtGetMotionIOLogical
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
    long           crdLeftLen[2];      // 坐标系缓冲区剩余段长，单位:脉冲
    long           crdAllCmdCnt[2];    // 坐标系缓冲区总共压入的指令数目
    long           extDi[6];           // 扩展模块输入，2号站~8号站
    long           extDo[6];           // 扩展模块输出，2号站~8号站
	short		   adc[4];			   // 模拟量输入值 0~4通道
	short		   adcAux[2];		   // 扩展模拟量输入值 0~1通道
	short		   dac[4];			   // 模拟量输出值 0~4通道
	short		   dacAux[2];		   // 扩展模拟量输出值 0~1通道
    long           reserved[10];       // 预留

}TAxisStsPack12Ex;
// 打包读取12个轴的状态
// axisFirstHandle : 第一个轴句柄
// pPackSts: 打包的状态数据,参考结构体定义
MTN_API short  __stdcall NMC_MtGetStsPack12Ex  ( HAND axisFirstHandle, TAxisStsPack12Ex *pPackSts );

// 快速读取打包状态 
typedef struct
{
    short sts[8];					// 轴状态
	short crdSts[2];				// 坐标系状态
}TMcStsPackEx;
// 打包读取控制器状态
// devHandle : 控制器句柄
// pPackSts: 打包的状态数据,参考结构体定义
MTN_API short  __stdcall NMC_MtGetStsPackEx  ( HAND devHandle, TMcStsPackEx *pPackSts );

// 快速读取轴状态
MTN_API short  __stdcall NMC_MtGetStsEx( HAND axisHandle, short *pStsWord );

// 快速读取坐标系状态
MTN_API short __stdcall NMC_CrdGetStsEx2( HAND crdHandle, short  *pStsWord );

// 启用扩展的状态读取指令功能
// enFlag:是否启用，1-启用，0-关闭，默认为关闭状态
MTN_API short __stdcall NMC_DevSetStsExCmdEn( HAND devHandle, short  enFlag );


// 读当前轴编码器通道
// pPos:返回编码器数值
MTN_API short  __stdcall NMC_MtGetEncPos   ( HAND axisHandle, long *pPos );

// 读轴编码器速度(单位是：脉冲/ms)
MTN_API short  __stdcall NMC_GetEncVel( HAND devHandle, short encId, double *pVel);

// 轴状态字位定义 
#define BIT_AXIS_BUSY           (0x00000001)    // bit 0  , 运动:1 ,静止 0       
#define BIT_AXIS_POSREC         (0x00000002)    // bit 1 , 伺服位置到达,步进模式时位置到达,伺服模式时实际位置到达误差限 
#define BIT_AXIS_MVERR          (0x00000004)    // bit 2 , 上次运动出错,或当前无法启动运动,需要调用NMC_MtClrError清除
#define BIT_AXIS_SVON           (0x00000008)    // bit 3  , 伺服允许        
#define BIT_AXIS_CRD            (0x00000010)    // bit 4 , 坐标系模式      
#define BIT_AXIS_STEP           (0x00000020)    // bit 5  , 步进/伺服       
#define BIT_AXIS_LMTP           (0x00000040)    // bit 6  , 正向限位，反向离开会自动清除        
#define BIT_AXIS_LMTN           (0x00000080)    // bit 7  , 负面限位，反向离开会自动清除
#define BIT_AXIS_SOFTPOSLMT     (0x00000100)    // bit 8  , 正向软限位触发  
#define BIT_AXIS_SOFTNEGLMT     (0x00000200)    // bit 9  , 负向软限位触发  
#define BIT_AXIS_ALM            (0x00000400)    // bit 10  , 伺服报警,需要调用NMC_MtClrError清除
#define BIT_AXIS_POSERR         (0x00000800)    // bit 11  , 位置超限,需要调用NMC_MtClrError清除 
#define BIT_AXIS_ESTP           (0x00001000)    // bit 12 , 急停,需要调用NMC_MtClrError清除
#define BIT_AXIS_HWERR          (0x00002000)    // bit 13 , 硬件错误 
#define BIT_AXIS_CAPTSET        (0x00004000)    // bit 14  , 捕获触发       
// 读当前轴状态
// pStsWord: 返回轴状态字。参考位定义
MTN_API short  __stdcall NMC_MtGetSts( HAND axisHandle, short *pStsWord );

// 专用IO定义,arrive,alm : home : limit+ , limit- servoClr
#define BIT_AXMTIO_LMTN     (0x00000001)    // bit 0  ,负向限位  
#define BIT_AXMTIO_LMTP     (0x00000002)    // bit 1  ,正向限位  
#define BIT_AXMTIO_HOME     (0x00000004)    // bit 2  ,原点  
#define BIT_AXMTIO_ALARM    (0x00000008)    // bit 3  ,驱动报警 
#define BIT_AXMTIO_ARRIVE   (0x00000010)    // bit 4  ,电机到位 
#define BIT_AXMTIO_CAPT     (0x00000020)    // bit 5  ,捕获源信号
#define BIT_AXMTIO_SVRCLR   (0x00000100)    // bit 8  ,伺服清除信号
// 读运动控制专用IO
// pIoValue : 返回专用IO的状态,原点,限位,报警，伺服清除输出等。参考位定义。对应位为0为低电平,1为高电平。
MTN_API short __stdcall NMC_MtGetMotionIO ( HAND axisHandle, long *pIoValue );

// 读运动控制专用IO,逻辑电平
// pIoValue : 返回专用IO的状态,原点,限位,报警。参考位定义。对应位为0为低电平,1为高电平。
MTN_API short __stdcall NMC_MtGetMotionIOLogical ( HAND axisHandle, long *pIoValue );




//------------------------------------------------------------------------------------------------------------
//
//        5.IO控制及外部资源读写
//
//------------------------------------------------------------------------------------------------------------
// 设置通用输出(按通道,支持超过32位),带默认group
// value: 设置通用数字量输出。1, 输出高电平,0,输出低电平
// groupID:DO组,取值范围[0,n],具体需要看控制器是否存在多组数字量输出
MTN_API short  __stdcall NMC_SetDOGroup( HAND devHandle, long value, short groupID) ;

// 读通用输入(按通道,支持超过32位) ,带默认group
// pInValue: 通用数字量输入值。1, 高电平,0,低电平
// groupID:DI组,取值范围[0,n],0: 本地DI31~DI0, 1: 本地DI63~DI32,其他指扩展IO模块
MTN_API short __stdcall NMC_GetDIGroup( HAND devHandle, long *pInValue, short groupID);

// 读取通用输出(按通道,支持超过32位),带默认group
// pDoValue: 设置通用数字量输出。1, 高电平,0,低电平
// groupID:DO组,取值范围[0,n],,0: 本地DO31~DO0, 1: 本地DO63~DO32,其他指扩展IO模块
MTN_API short  __stdcall NMC_GetDOGroup( HAND devHandle, long *pDoValue, short groupID);

// 按位设置通用输出
// bitIndex:取值范围[0,n],位序号,前64位为本地的通用输出,大于64为扩展DO
// value: 设置通用数字量输出。1, 输出高电平,0,输出低电平
MTN_API short  __stdcall NMC_SetDOBit( HAND devHandle, short bitIndex, short value );

// 按位读输出 
MTN_API short  __stdcall NMC_GetDOBit( HAND devHandle,short bitIndex, short *bitValue);

// 按位读通用输入 
// 读通用输入(按通道,支持超过32位) 
// bitIndex:取值范围[0,n],位序号
// pBitValue: 通用数字量输入值。1, 高电平,0,低电平
MTN_API short  __stdcall NMC_GetDIBit( HAND devHandle,short bitIndex, short *pBitValue );

// 读取扩展IO模块的状态
// sts:io模块状态
MTN_API short  __stdcall NMC_GetIOModuleSts(HAND devHandle, unsigned long *sts);

// 设置扩展IO模块有效（默认为IO64模块）
// chDevId:设备ID
MTN_API short  __stdcall NMC_SetIOModuleEn( HAND devHandle, unsigned char chDevId);

// 扩展模块类型定义
#define IOMODULE_TYPE_IO64		1		// 32DI32DO模块（包括16DI16DO模块）
#define IOMODULE_TYPE_IO32_DA	2		// 4AD4DA模块

// 设置扩展IO模块有效(带模块类型)
// chDevId:设备ID
// chDevType:模块类型，见宏定义
MTN_API short  __stdcall NMC_IOModuleSetEn( HAND devHandle, unsigned char chDevId,short chDevType);

// 读取扩展IO模块类型
// chDevId:设备ID
// pChDevType:返回的模块类型，见宏定义
MTN_API short  __stdcall NMC_IOModuleGetType( HAND devHandle, unsigned char chDevId,short *pChDevType);

// 扩展IO模块通道写，8位长度
// chDevId：设备站号
// offset:数据偏移
MTN_API short  __stdcall NMC_IOModuleWr8Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned char data);

// 扩展IO模块通道写，16位长度
MTN_API short  __stdcall NMC_IOModuleWr16Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned short data);

// 扩展IO模块通道写，32位长度
MTN_API short  __stdcall NMC_IOModuleWr32Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned long data);

// 扩展IO模块通道读输出，8位长度
// chDevId：设备站号
// offset:数据偏移
MTN_API short  __stdcall NMC_IOModuleRdOut8Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned char *pData);

// 扩展IO模块通道读输出，16位长度
MTN_API short  __stdcall NMC_IOModuleRdOut16Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned short *pData);

// 扩展IO模块通道读输出，32位长度
MTN_API short  __stdcall NMC_IOModuleRdOut32Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned long *pData);

// 扩展IO模块通道读，8位长度
// chDevId：设备站号
// offset:数据偏移
MTN_API short  __stdcall NMC_IOModuleRd8Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned char *pData);

// 扩展IO模块通道读，16位长度
MTN_API short  __stdcall NMC_IOModuleRd16Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned short *pData);

// 扩展IO模块通道读，32位长度
MTN_API short  __stdcall NMC_IOModuleRd32Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned long *pData);


//------------------------------------------------------------------------------------------------------------
//
//        6.坐标系配置
//
//------------------------------------------------------------------------------------------------------------
#define CRD_MAX_DIMENSION 4

// 坐标系配置
typedef struct
{
    short axCnts;       // 参与的轴数量
    short reserved[3];  // 保留
    short pAxArray[4];  // 坐标系轴映射表,轴序号取值范围[0,n]
    short port[4];      // 坐标系端口映射表,统一设为0
}TCrdConfig;
// 建立插补坐标系系统(必须)
// pConfig:坐标系配置,参考结构体定义
MTN_API short __stdcall NMC_CrdConfig( HAND crdHandle, TCrdConfig *pConfig );

//缓冲区运动安全参数
typedef struct
{
    double estpDec;     // 急停加速度
    double maxVel;      // 最大速度
    double maxAcc;      // 最大加速度
}TCrdSafePara;
// 设置轴缓冲区运动安全参数
// pPara：包含急停减速度、最大允许速度、最大允许加速度
MTN_API short  __stdcall NMC_CrdSetSafePara( HAND crdHandle, TCrdSafePara *pPara );

// 设置轴缓冲区运动偏移
// count:设置偏移的轴数
// pOffsetArray：缓冲区运动偏移,long数组
// 注：会同时修改坐标系内相关轴的运动偏移！
MTN_API short  __stdcall NMC_CrdSetOffset( HAND crdHandle,short count, long *pOffsetArray );

// 删除坐标系
MTN_API short __stdcall NMC_CrdDelete(  HAND crdHandle );


//------------------------------------------------------------------------------------------------------------
//
//        7.坐标系运行控制
//
//------------------------------------------------------------------------------------------------------------
// 坐标系缓冲运动启动  
MTN_API short __stdcall NMC_CrdStartMtn( HAND crdHandle );

// 立即平滑停止运动
// 注：立即停止运动。并不清空指令缓冲区。需要再次启动才能继续运行缓冲区指令。
MTN_API short __stdcall NMC_CrdStopMtn( HAND crdHandle );

// 急停
// 并不清空指令缓冲区
MTN_API short __stdcall NMC_CrdEstopMtn( HAND crdHandle );

// 结束缓冲区运动（等待运动完后才结束区运动,并置空闲标志）
// 注：缓冲区运动结束并不立即停止运动。把指令缓冲区全部执行完后,结束缓冲区运动状态。
MTN_API short __stdcall NMC_CrdEndMtn   ( HAND crdHandle );

// 返回缓冲区运动的断点
// vel:返回时使用的速度
// acc:返回时使用的加速度
MTN_API short __stdcall NMC_CrdGotoBreak( HAND crdHandle,double acc,double vel);


//------------------------------------------------------------------------------------------------------------
//
//        8.坐标系及运动缓冲区状态读取
//
//------------------------------------------------------------------------------------------------------------
// 坐标系状态字位定义 
#define BIT_CORD_BUSY           (0x00000001)    // bit 0 , 运动:1 ,静止 0,立即运动下运动停止,完成 
#define BIT_CORD_MVERR          (0x00000002)    // bit 1 , 运动出错,或当前运动指令无法启动,需要软件复位    
#define BIT_CORD_EMPTY          (0x00000004)    // bit 2 , 缓冲区空　       
#define BIT_CORD_FULL           (0x00000008)    // bit 3 , 缓冲区满　               
#define BIT_CORD_NODATASTOP     (0x00000010)    // bit 4 , 缓冲区空异常停止或者急停　    
#define BIT_CORD_SDRAM_HWERR    (0x00000020)    // bit 5, 插补缓冲区硬件或者其他错误  
// 读取坐标系状态
// pStsWord：返回状态字,参考宏定义
MTN_API short __stdcall NMC_CrdGetSts( HAND crdHandle, short  *pStsWord );

typedef struct
{
    short crdSts;          // 坐标系状态
    short axSts[4];        // 坐标系里各轴状态
    long  prfPos[4];       // 用户坐标系下的规划位置
    long  axisPos[4];      // 机械坐标系下的规划位置
    long  encPos[4];        // 编码器位置
    long  userSeg;         // 运行的缓冲区段号
    double  prfVel;         // 运动速度
    long  gpDi;             // 通用输入0~31
    long  gpDo;             // 通用输出0~31
    short  motDi[4];        // 限位、原点、报警。请参考专用IO位定义( 搜索 BIT_AXMTIO_LMTN )
    short  reserved;        // 保留
    long crdFreeSpace;      // 缓冲区剩余空间
    long crdUsedSpace;
}TPackedCrdSts4;
// 坐标系运动模式下,打包读取控制器状态
MTN_API short __stdcall NMC_CrdGetStsPack4( HAND crdHandle, TPackedCrdSts4 *pPackSts );

// 清坐标系运动错误状态,同时清除所包含轴的错误状态
MTN_API short __stdcall NMC_CrdClrError   ( HAND crdHandle );

// 读取指令缓冲区空闲长度
// pRes：返回空闲的长度
MTN_API short __stdcall NMC_CrdBufGetFree ( HAND crdHandle, long *pRes );

// 读取指令缓冲区已用长度
// pLen: 长度。缓冲区中还未执行的指令个数。
MTN_API short __stdcall NMC_CrdBufGetUsed  ( HAND crdHandle, long *pLen );

// 获取插补缓冲区中尚未完成的总位移量
// pLen: 长度
MTN_API short __stdcall NMC_CrdGetBufLeftLength(HAND crdHandle, double *pLen);

// 指令缓冲区清空
MTN_API short __stdcall NMC_CrdBufClr( HAND crdHandle );

// 设置坐标系剩余位移量，用于控制激光能量跟随后的关闭波形输出
// group:波形数组组号
// ch:激光通道号
MTN_API short  __stdcall NMC_CrdSetLeftLenForLaserWaveOff ( HAND crdHandle,double length ,short group,short ch);

// 缓冲设置坐标系剩余位移量，用于控制激光能量跟随后的关闭波形输出
MTN_API short  __stdcall NMC_CrdBufSetLeftLenForLaserWaveOff( HAND crdHandle,long segNo,double length,short group,short ch);

// 读段号
// pSegNo：返回的当前段号
MTN_API short __stdcall NMC_CrdGetUserSegNo  ( HAND crdHandle, long *pSegNo);

//  读取总共压了多少条指令
//  pCnt:返回的指令数
MTN_API short __stdcall NMC_CrdGetBufAllCmdCnt ( HAND crdHandle, long *pCnt);

// 开始计算缓冲区执行时间
// 注意:1.如果需要计算执行时间，需要使用上位机前瞻
//     2.开始后，所有的缓冲区指令，都不会压入控制器
MTN_API short __stdcall NMC_CrdStartExeTimeCalc(void);

// 读取缓冲区指令的执行时间，并停止计算，单位:ms
MTN_API short __stdcall NMC_CrdGetExeTime(double *pTime);

//------------------------------------------------------------------------------------------------------------
//
//        9.缓冲区插补运动和IO控制
//
//------------------------------------------------------------------------------------------------------------

// 四轴直线插补
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// crdAxMask:参与的轴,按位表示
// endVel,vel,synAcc:终点速度，最大速度，插补加速度
// pTgPosArray：目标位置数组
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdLineXYZA(  HAND crdHandle,  long segNo, short crdAxMask,
	long *pTgPosArray, double endVel, double vel,double synAcc ,short lookaheadDis);

// 设置4维插补下，A轴的最大容忍转弯速度，若大于该速度，则需要进行降速处理
MTN_API short  __stdcall NMC_CrdSetFourthAxisTolTurnVel(HAND crdHandle,double tolVel);

// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// crdAxMask:参与的轴,按位表示
// pTgPosArray：目标位置数组,长度为3
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdLineXYZEx(  HAND crdHandle,  long segNo, short crdAxMask,long *pTgPosArray,
	double endVel, double vel,double synAcc,short lookaheadDis );

// 多轴直线插补（最多支持8轴）
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// crdAxmask:坐标系中参与的轴,按位表示
// extAxMask:其他参与轴,按位表示,不能包括坐标系中
// pTgPosArray：目标位置数组,长度为所有参与运动的轴的数量,
//              索引小的是坐标系内的轴的坐标（按crdAxMask位排列）。索引大的是其它联动轴的坐标（按extAxMask位排列）
// lookaheadDis:是否使用前瞻(仅仅适用与坐标系中的轴的运动),0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdLineXYZD8(  HAND crdHandle, long segNo, 
	long crdAxmask, long extAxMask, long *pTgPosArray,
	double endVel, double vel,double synAcc,short lookaheadDis );

// 8轴插补打包单元结构体
typedef struct
{
    long segNo;         // 用户自定义段号
	short crdAxMask;
	short extAxMask;
    long  tgPos[8];     // 目标位置
	float vel;         // 最大速度
	float endVel;      // 终点速度
    float acc;			// 插补加速度
	short lookaheadDis;	// 是否使用前瞻
	short reserved;		// 保留
}TCrdLineXYZD8Unit;

// 打包的多轴直线插补
// count:打包指令数,取值范围[1,18]
// pCmdArray:指令列表
MTN_API short __stdcall NMC_CrdLineXYZD8Pack(  HAND crdHandle, short count,  TCrdLineXYZD8Unit *pCmdArray);


// 4轴插补打包单元结构体
typedef struct
{
    long segNo;         // 用户自定义段号
	short crdAxMask;
	short extAxMask;
    long  tgPos[4];     // 目标位置
	float vel;         // 最大速度
	float endVel;      // 终点速度
    float acc;      // 插补加速度
	short lookaheadDis;	// 是否使用前瞻
	short reserved;		// 保留
}TCrdLineXYZD4Unit;

// 打包的4轴直线插补
// count:打包指令数,取值范围[1,25]
// pCmdArray:指令列表
MTN_API short __stdcall NMC_CrdLineXYZD4Pack(  HAND crdHandle, short count,  TCrdLineXYZD4Unit *pCmdArray);

typedef struct
{
    long segNo;         // 用户自定义段号
    long  tgPos[3];     // 目标位置
    double endVel;      // 终点速度
    double vel;         // 最大速度
    double synAcc;      // 插补加速度
    short mask;         // 参与的轴,按位表示
	short lookaheadDis;	// 是否使用前瞻
    short reserved[2];  // 保留
}TCrdLineXYZUnit;
// 打包的直线插补
// count:打包指令数,取值范围[1,20]
// pCmdArray:指令列表
MTN_API short __stdcall NMC_CrdLineXYZPack(  HAND crdHandle, short count,  TCrdLineXYZUnit *pCmdArray);

// XY平面圆弧插补：终点位置、半径、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// radius:圆弧半径,大于0表示劣弧,小于0表示优弧
// pTgPosArray：目标位置数组（二维数组,分别表示XY的位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
MTN_API short __stdcall NMC_CrdArcRadius(  HAND crdHandle, long segNo,long *pTgPosArray, double radius, short circleDir,double endVel, double vel,double synAcc );

// YZ平面圆弧插补：终点位置、半径、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// radius:圆弧半径,大于0表示劣弧,小于0表示优弧
// pTgPosArray：目标位置数组（二维数组,分别表示YZ的位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
MTN_API short __stdcall NMC_CrdArcRadiusYZ(  HAND crdHandle, long segNo,
	long *pTgPos, double radius, short circleDir,double velEnd, double vel,double synAcc );

// ZX平面圆弧插补：终点位置、半径、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// radius:圆弧半径,大于0表示劣弧,小于0表示优弧
// pTgPosArray：目标位置数组（二维数组,分别表示ZX的位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
MTN_API short __stdcall NMC_CrdArcRadiusZX(  HAND crdHandle, long segNo,
	long *pTgPos, double radius, short circleDir,double velEnd, double vel,double synAcc );

// XY平面圆弧插补：终点位置、半径、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// radius:圆弧半径,大于0表示劣弧,小于0表示优弧
// pTgPosArray：目标位置数组（二维数组,分别表示XY的位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdArcRadiusEx(  HAND crdHandle, long segNo,long *pTgPosArray, double radius, 
								short circleDir,double endVel, double vel,double synAcc ,short lookaheadDis);

// YZ平面圆弧插补：终点位置、半径、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// radius:圆弧半径,大于0表示劣弧,小于0表示优弧
// pTgPosArray：目标位置数组（二维数组,分别表示YZ的位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdArcRadiusYZEx(  HAND crdHandle, long segNo,long *pTgPos, double radius, 
	short circleDir,double velEnd, double vel,double synAcc ,short lookaheadDis);

// ZX平面圆弧插补：终点位置、半径、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// radius:圆弧半径,大于0表示劣弧,小于0表示优弧
// pTgPosArray：目标位置数组（二维数组,分别表示ZX的位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdArcRadiusZXEx(  HAND crdHandle, long segNo,long *pTgPos, double radius, 
	short circleDir,double velEnd, double vel,double synAcc ,short lookaheadDis);

// XY平面圆弧插补：终点位置、圆心、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pCenterPosArray:圆心坐标（二维数组,分别表示XY轴相对于起点的圆心位置）,注意：圆心坐标为相对于起点的相对位置
// pTgPosArray：目标位置（二维数组,分别表示XY轴的目标位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
MTN_API short __stdcall NMC_CrdArcCenter(  HAND crdHandle, long segNo,long *pTgPosArray, long *pCenterPosArray,short circleDir,double endVel, double vel,double synAcc );

// YZ平面圆弧插补：终点位置、圆心、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pCenterPosArray:圆心坐标（二维数组,分别表示YZ轴相对于起点的圆心位置）,注意：圆心坐标为相对于起点的相对位置
// pTgPosArray：目标位置（二维数组,分别表示YZ轴的目标位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
MTN_API short __stdcall NMC_CrdArcCenterYZ(  HAND crdHandle, long segNo,long *pTgPos, 
	long *pCenterPos,short circleDir,double velEnd, double vel,double synAcc );

// ZX平面圆弧插补：终点位置、圆心、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pCenterPosArray:圆心坐标（二维数组,分别表示ZX轴相对于起点的圆心位置）,注意：圆心坐标为相对于起点的相对位置
// pTgPosArray：目标位置（二维数组,分别表示ZX轴的目标位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
MTN_API short __stdcall NMC_CrdArcCenterZX(  HAND crdHandle, long segNo,long *pTgPos, 
	long *pCenterPos,short circleDir,double velEnd, double vel,double synAcc );

// XY平面圆弧插补：终点位置、圆心、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pCenterPosArray:圆心坐标（二维数组,分别表示XY轴相对于起点的圆心位置）,注意：圆心坐标为相对于起点的相对位置
// pTgPosArray：目标位置（二维数组,分别表示XY轴的目标位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdArcCenterEx(  HAND crdHandle, long segNo,long *pTgPosArray, long *pCenterPosArray,
										short circleDir,double endVel, double vel,double synAcc ,short lookaheadDis);

// YZ平面圆弧插补：终点位置、圆心、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pCenterPosArray:圆心坐标（二维数组,分别表示ZX轴相对于起点的圆心位置）,注意：圆心坐标为相对于起点的相对位置
// pTgPosArray：目标位置（二维数组,分别表示YZ轴的目标位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdArcCenterYZEx(  HAND crdHandle, long segNo,long *pTgPos, long *pCenterPos,
    short circleDir,double velEnd, double vel,double synAcc ,short lookaheadDis);

// ZX平面圆弧插补：终点位置、圆心、方向
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pCenterPosArray:圆心坐标（二维数组,分别表示ZX轴相对于起点的圆心位置）,注意：圆心坐标为相对于起点的相对位置
// pTgPosArray：目标位置（二维数组,分别表示ZX轴的目标位置）
// circleDir:圆弧方向,0表示顺时针方向,1表示逆时针方向
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdArcCenterZXEx(  HAND crdHandle, long segNo,long *pTgPos, long *pCenterPos,
    short circleDir,double velEnd, double vel,double synAcc ,short lookaheadDis);

// XY平面圆弧插补：起点（当前点）、中点、终点
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pMidPosArray:中间位置点坐标（二维数组,分别表示中间点的XY轴的位置）
// pTgPosArray：终点位置坐标（二维数组,分别表示终点的XY轴的位置）
MTN_API short __stdcall NMC_CrdArcPPP(  HAND crdHandle,long segNo, long *pMidPosArray, long *pTgPosArray, double endVel, double vel,double synAcc );

// XY平面圆弧插补：起点（当前点）、中点、终点
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pMidPosArray:中间位置点坐标（二维数组,分别表示中间点的XY轴的位置）
// pTgPosArray：终点位置坐标（二维数组,分别表示终点的XY轴的位置）
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdArcPPPEx(  HAND crdHandle,long segNo, long *pMidPosArray, long *pTgPosArray, 
												double endVel, double vel,double synAcc ,short lookaheadDis);
// 椭圆插补，默认不参与速度前瞻，起始和终止速度为0（注意！椭圆为整圆）
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pCenterPos：椭圆圆心点位置（二维数组,分别表示中点的XY轴的位置）。注意！起点位置到圆心位置为长轴的
// abRatio:表示椭圆AB轴的长度比例值 值范围：[0.05,1]
// ellipseDir:椭圆绘画方向,0表示顺时针方向,1表示逆时针方向
MTN_API short __stdcall NMC_CrdEllipse(  HAND crdHandle, long segNo,double abRatio, long *pCenterPos,short ellipseDir, double vel,double synAcc);

// 螺旋线插补
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pTgPosArray：目标位置（三维数组,分别表示终点的XYZ轴的位置）
// pCenterPosArray:圆心位置（二维数组,分别表示XY轴相对于起点的圆心位置）,注意：圆心坐标为相对于起点的相对位置
// rounds: Z方向圈数
MTN_API short __stdcall NMC_CrdHelixCenter(  HAND crdHandle, long segNo, long *pTgPosArray, long *pCenterPosArray,short circleDir,double rounds, double endVel, double vel,double synAcc );

// 螺旋线插补
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pTgPosArray：目标位置（三维数组,分别表示终点的XYZ轴的位置）
// pCenterPosArray:圆心位置（二维数组,分别表示XY轴相对于起点的圆心位置）,注意：圆心坐标为相对于起点的相对位置
// rounds: Z方向圈数
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdHelixCenterEx(  HAND crdHandle, long segNo, long *pTgPosArray, long *pCenterPosArray,short circleDir,
														double rounds, double endVel, double vel,double synAcc ,short lookaheadDis);

// 3D圆弧插补
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pMidPos：中点位置（三维数组,分别表示中点的XYZ轴的位置）
// pTgPos:终点位置（三维数组,分别表示终点的XYZ轴的位置）
MTN_API short __stdcall NMC_CrdArc3D(  HAND crdHandle,long segNo, long *pMidPos, long *pTgPos,
									double velEnd, double vel,double synAcc );

// 3D圆弧插补
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pMidPos：中点位置（三维数组,分别表示中点的XYZ轴的位置）
// pTgPos:终点位置（三维数组,分别表示终点的XYZ轴的位置）
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdArc3DEx(  HAND crdHandle,long segNo, long *pMidPos, long *pTgPos,
									double velEnd, double vel,double synAcc ,short lookaheadDis);

// 3D圆弧插补(整圆)
// segNo:段号；endVel:终点速度;vel:最大速度;synAcc:合成加速度
// pMidPos：中点位置（三维数组,分别表示中点的XYZ轴的位置）
// pTgPos:终点位置（三维数组,分别表示终点的XYZ轴的位置）
// lookaheadDis:是否使用前瞻,0：使用前瞻,则控制器自动计算终点速度,1：禁用前瞻,使用设定的终点速度（endVel）
MTN_API short __stdcall NMC_CrdCircle3DEx(  HAND crdHandle,long segNo, long *pMidPos, long *pTgPos,
									double velEnd, double vel,double synAcc ,short lookaheadDis);

// 缓冲区输出DO组定义
#define CRD_BUFF_DO_MOTOR_ENABLE            1   // 电机使能
#define CRD_BUFF_DO_MOTOR_CLEAR             2   // 电机报警清除
#define CRD_BUFF_DO_GPDO1                   3   // 通用输出1
#define CRD_BUFF_DO_GPDO2                   4   // 通用输出2
#define CRD_BUFF_DO_EXTDO1					5	// 扩展模块1
#define CRD_BUFF_DO_EXTDO2					6	// 扩展模块2
#define CRD_BUFF_DO_EXTDO3					7	// 扩展模块3
#define CRD_BUFF_DO_EXTDO4					8	// 扩展模块4
#define CRD_BUFF_DO_EXTDO5					9	// 扩展模块5
#define CRD_BUFF_DO_EXTDO6					10	// 扩展模块6

// 缓冲区DO
// segNo:段号
// doType:Do类型,见宏定义
// ch：位序号,取值范围[0,31]
// value：输出值,取值范围[0,1]
MTN_API short __stdcall NMC_CrdBufDo( HAND crdHandle, long segNo, short doType,   long  ch,  long  value);

// 缓冲区DO
// segNo:段号
// gourp:Do组别,见宏定义
// doMask：位掩码
// doValue：输出值
MTN_API short  __stdcall NMC_CrdBufDoEx(HAND crdHandle,long segNo,short group,long doMask,long doValue);

// 通用输出宏类型
#define BUF_OUT_GROUP_DA        (0)             // 模拟量输出
#define BUF_OUT_GROUP_PWM       (1)             // PWM输出
// 缓冲区输出
// segNo:段号
// gourp:组别,见宏定义
// ch：通道号,取值范围[0,n]
// value：输出值
MTN_API short __stdcall NMC_CrdBufOut( HAND crdHandle,  long segNo, short group, short ch, long  value);

// 缓冲区DI等待
// index:通道号,取值范围[0,127],前64通道代表通用DI，后64通道代表扩展IO
// diValue：等待值
// waitLastTime：超时,单位：毫秒
MTN_API short __stdcall NMC_CrdBufWaitDI(HAND crdHandle, long segNo,short index,short diValue,long waitLastTime);

// 缓冲区等待
// waitType:等待类型，0：内部变量，1：DO状态
// index:通道号，对于内部变量，取值范围[0,1],对于DO，取值范围[0,63]
// waitValue：等待值
// waitTimeInMs：超时,单位：毫秒
MTN_API short __stdcall NMC_CrdBufWait(HAND crdHandle, long segNo,short waitType,short index,long waitValue,long waitTimeInMs);

// 功能:缓冲区等待电机运动到位
// segNo:段号
// axisMask:需要等待到位的轴掩码（按位对应轴号,不能超出控制器的最大轴数）
// overTime:等待到位超时的时间，单位：ms
MTN_API short  __stdcall NMC_CrdBufWaitEncInPosition(HAND crdHandle,long segNo,long axisMask,long overTime);

// 功能:缓冲区等待特定位置，满足条件才执行下一条指令
// segNo:段号
// axisNo:需要等待到位的轴号
// condition:到位条件，0：小于等于设定位置  1：大于等于设定位置
// pos:设定位置
// posSrc:等待规划还是编码器，0：编码器 1：内部规划
// overTime:等待到位超时的时间，单位：ms
MTN_API short  __stdcall NMC_CrdBufWaitPos(HAND crdHandle,long segNo,short axisNo,
    short condition,long pos,short posSrc,long overTime);

// 缓冲区延时单位
#define CRD_BUFF_DELAY_SCALE_MS             0   // 毫秒
#define CRD_BUFF_DELAY_SCALE_SECAND         1   // 秒
// 缓冲区延时
// segNo:段号
// scale:延时单位,0表示单位为毫秒,1表示单位为秒
// count：延时时长
MTN_API short __stdcall NMC_CrdBufDelay( HAND crdHandle, long segNo, short scale, long  count);

// 缓冲区单轴移动(绝对位移移动)
// segNo:段号
// axisMask:参与的轴
// pTgPos：目标位置
// blockEn:是否为阻塞模式
// synEn：是否为同步模式,如果synEn和blockEn同时为1,则同步优先
MTN_API short __stdcall NMC_CrdBufAxMove( HAND crdHandle,  long segNo, short axisMask,long *pTgPos,short blockEn ,short synEn);

// 缓冲区单轴移动(带参数)
// segNo:段号
// axisMask:参与的轴
// pTgPos：目标位置
// vel:速度
// acc:加速度
// blockEn:是否为阻塞模式
// synEn：是否为同步模式,如果synEn和blockEn同时为1,则同步优先
MTN_API short  __stdcall NMC_CrdBufAxMoveEx(HAND crdHandle,long segNo,short axisMask,long *pTgPos,
	double vel,double acc,short blockEn ,short synEn);

// 缓冲区单轴移动(相对位移移动)
// segNo:段号
// axisMask:参与的轴
// pRelPos：相对移动位置
// blockEn:是否为阻塞模式
// synEn：是否为同步模式,如果synEn和blockEn同时为1,则同步优先
MTN_API short __stdcall NMC_CrdBufAxMoveRel( HAND crdHandle,  long segNo, short axisMask,long *pRelPos,short blockEn ,short synEn);

// 缓冲区单轴移动参数设置
// segNo:段号
// axisNo：轴号,[0,n]
// vel:运动速度
// acc:运动加速度
// smoothCoef:平滑系数
MTN_API short __stdcall NMC_CrdBufSetPtpMovePara(HAND crdHandle, long segNo,short axisNo,double vel,double acc,short soomthCoef);

// 缓冲区跟随
// segNo:段号
// onOff:开关
MTN_API short __stdcall NMC_CrdBufValueFollow ( HAND crdHandle ,  long segNo, short onOff );

// 缓冲区设置加工幅面范围，超出范围则停止运动
// crdAxMask:是否激活幅面限制	按位进行判断 ，bit0~2，分别对应XYZ轴 1：开启，0 关闭
// pXMax: pXMax[0]为X的最小行程边界	pXMax[1]为X的最大行程边界  pXMax[2]为X发生干涉时等待的参考位置
// pYMax和pZMax 同pXMax说明
MTN_API short __stdcall NMC_CrdBufSetScaleLimit ( HAND crdHandle,long segNo,
    short crdAxMask,long *pXMax,long *pYMax,long *pZMax);

// 设置跟随运动前的运动补偿量
// axis:轴号  0~N
//relDistance：相对补偿位移量
//vel：补偿速度
MTN_API short  __stdcall NMC_CrdBufBeforeAxSyncMove(HAND crdHandle, long segNo,short axis,long relDistance,double vel);

// 设置坐标系速度倍率
// overRide：坐标系速度倍率,取值范围(0,10)
MTN_API short __stdcall NMC_CrdSetOverRide( HAND crdHandle, double overRide );

//------------------------------------------------------------------------------------------------------------
//
//        10.回零
//
//------------------------------------------------------------------------------------------------------------
// 回零类型定义                                                 
// 回零模式    单原点      单限位     单Z相    原点+Z相 原点+ -Z相  限位+ -Z相
typedef enum { HM_MODE1=0, HM_MODE2, HM_MODE3, HM_MODE4, HM_MODE5, HM_MODE6 } THomeMode;

// 回零参数设置
typedef struct
{
    short  mode;                    // 模式,HM_MODE1 ~ HM_MODE6 （必须）
    short  dir;                     // 搜寻零点方向（必须）, 0:负向,1：正向,其它值无意义
    long    offset;                 // 原点偏移（必须）
    double  scan1stVel;             // 基本搜寻速度（必须）
    double  scan2ndVel;             // 低速（两次搜寻时需要）
    // 当usePreSetPtpPara=0时,回零运动的减加速度默认等于acc,起跳速度、终点速度、平滑系数默认为0
    double  acc;                    // 加速度
    
    unsigned char reScanEn;         // 是否两次搜寻零点（可选,不用时设为0）
    unsigned char homeEdge;         // 原点,触发沿（默认下降沿）
    unsigned char lmtEdge;          // 限位,触发沿（默认下降沿）
    unsigned char zEdge;            // 限位,触发沿（默认下降沿）
    unsigned long iniRetPos;        // 起始反向运动距离（可选,不用时设为0）
    unsigned long retSwOffset;      // 反向运动时离开开关距离（可选,不用时设为0）
    unsigned long safeLen;          // 安全距离,回零时最远搜寻距离（可选,不用时设为0,不限制距离）
    unsigned char usePreSetPtpPara; // 为1表示用户需要在启动回零前,自己设置回零运动（点到点）的参数
    unsigned char reserved[3];      // 保留
    long reserved2;                 // 保留
} THomeSetting;
// 设置回零参数
// pHomePara: 回零参数结构,参考结构定义
MTN_API short __stdcall NMC_MtSetHomePara( HAND axisHandle, THomeSetting *pHomePara );

// 回零状态字位定义 
#define BIT_AXHOME_BUSY         (0x00000001)    // bit 0  , 忙    
#define BIT_AXHOME_OK           (0x00000002)    // bit 1  , 成功  
#define BIT_AXHOME_FAIL         (0x00000004)    // bit 2  , 失败  
#define BIT_AXHOME_ERR_MV       (0x00000008)    // bit 3  , 错误：运动参数出错导致不动 
#define BIT_AXHOME_ERR_SWT      (0x00000010)    // bit 4  , 错误：搜寻过程中开关没触发 
// 读回零状态
// pStsWord: 返回状态字。参数宏定义,高8位为错误代码
MTN_API short __stdcall NMC_MtGetHomeSts(HAND axisHandle, short *pStsWord );

// 启动回零
MTN_API short __stdcall NMC_MtHome(HAND axisHandle );

// 尝试性回零（测试回零误差,不清位置）
MTN_API short __stdcall NMC_MtTryHome( HAND axisHandle );

// 终止回零
MTN_API short __stdcall NMC_MtHomeStop(HAND axisHandle );

// 读新回零位置和历史回零位置的差值
// pErrPos: 回零位置偏差
// 注：回零成功时才有意义
MTN_API short __stdcall NMC_MtGetHomeError( HAND axisHandle, long *pErrPos );





//------------------------------------------------------------------------------------------------------------
//
//        11.电子齿轮
//
//------------------------------------------------------------------------------------------------------------
// 设置Gear跟随方向
// dir：  0:双向跟随，<0负向跟随， >0正向跟随
MTN_API short  __stdcall NMC_MtGearSetDir(HAND axisHandle,short dir);

// 获取Gear跟随方向
// pDir：  0:双向跟随，<0负向跟随， >0正向跟随
MTN_API short  __stdcall NMC_MtGearGetDir(HAND axisHandle,short *pDir);

// 设置Gear主轴参数
// axisHandle：从轴跟随轴号
// masterNo：  主轴序列号（0~N）
// masterType：  主轴类型  1:AXIS规划值  2：AXIS反馈值 3：编码器值
MTN_API short  __stdcall NMC_MtGearSetMaster(HAND axisHandle,short masterNo,short masterType);

// 获取Gear主轴参数
// pMasterNo：  主轴序列号（0~N）
// pMasterType：  主轴类型
MTN_API short  __stdcall NMC_MtGearGetMaster(HAND axisHandle,short *pMasterNo,short *pMasterType);

// 设置Gear跟随倍率
// axisHandle：从轴跟随轴号
// masterEven： 传动比系数，主轴位移
// slaveEven：  传动比系数，从轴位移
// masterSlope：主轴离合区位移,必须大于0，同时不能等于1
MTN_API short  __stdcall NMC_MtGearSetRatio(HAND axisHandle,long masterEven,long slaveEven,long masterSlope);

// 获取Gear跟随倍率
// axisHandle：从轴跟随轴号
// pMasterEven： 传动比系数，主轴位移
// pSlaveEven：  传动比系数，从轴位移
// pMasterSlope：主轴离合区位移,必须大于0，同时不能等于1
MTN_API short  __stdcall NMC_MtGearGetRatio(HAND axisHandle,long *pMasterEven,long *pSlaveEven,long *pMasterSlope);

// 启动Gear运动
// syncCount： 不包括axisHandle 的其他同步启动轴数量
// pSyncAxisArray: 其他同步启动轴的序号：0~N	
// 注：同步的轴必须属于同一个控制器
MTN_API short  __stdcall NMC_MtGearStartMtn(HAND axisHandle,short syncAxCnts,short *pSyncAxArray);

//------------------------------------------------------------------------------------------------------------
//
//        12.电子凸轮
//
//------------------------------------------------------------------------------------------------------------
// 设置FOLLOW跟随方向
// dir：  0:双向跟随，<0负向跟随， >0正向跟随
MTN_API short  __stdcall NMC_MtFollowSetDir(HAND axisHandle,short dir);

// 获取FOLLOW跟随方向
// pDir：  0:双向跟随，<0负向跟随， >0正向跟随
MTN_API short  __stdcall NMC_MtFollowGetDir(HAND axisHandle,short *pDir);

// FOLLOW跟随的主轴类型
#define PROFILE_FOLLOW_MASTER_NONE		   (0)	// 0:无效
#define PROFILE_FOLLOW_MASTER_AXIS_PRF     (1)	// 1:AXIS规划值
#define PROFILE_FOLLOW_MASTER_AXIS_ENC     (2)	// 2：AXIS反馈值
#define PROFILE_FOLLOW_MASTER_ENC          (3)	// 3：编码器值

// 设置FOLLOW主轴参数
// axisHandle：从轴跟随轴号
// masterNo：  主轴序列号（0~N）
// masterType：  主轴类型  见上面宏定义
MTN_API short  __stdcall NMC_MtFollowSetMaster(HAND axisHandle,short masterNo,short masterType);

// 获取FOLLOW主轴参数
// axisHandle：从轴跟随轴号
// pMasterNo：  主轴序列号（0~N）
// pMasterType：  主轴类型  见上面宏定义
MTN_API short  __stdcall NMC_MtFollowGetMaster(HAND axisHandle,short *pMasterNo,short *pMasterType);

// 设置FOLLOW的循环执行次数
// loopCnt：循环
MTN_API short  __stdcall NMC_MtFollowSetLoopCount(HAND axisHandle,long loopCnt);

// 获取FOLLOW的循环执行次数
// pLoopCnt：循环
MTN_API short  __stdcall NMC_MtFollowGetLoopCount(HAND axisHandle,long *pLoopCnt);

// FOLLOW跟随事件
#define PROFILE_FOLLOW_EVENT_START        (1)	// 立即启动
#define PROFILE_FOLLOW_EVENT_PASS         (2)	// 主轴穿越设定位置以后启动跟随

// 设置FOLLOW的的启动事件
// eventType：1 表示调用启动指令以后	立即启动，2表示	主轴穿越设定位置以后启动跟随
// masterDir:穿越启动时，主轴的运动方向，1 主轴正向运动，-1 主轴负向运动
// pos:穿越位置
MTN_API short  __stdcall NMC_MtFollowSetEvent(HAND axisHandle,short eventType,short masterDir,long pos);

// 获取FOLLOW的启动事件
// pEvent：1 表示调用启动指令以后立即启动，2表示主轴穿越设定位置以后启动跟随
// pMasterDir:穿越启动时，主轴的运动方向，1 主轴正向运动，-1 主轴负向运动
// pPos:穿越位置
MTN_API short  __stdcall NMC_MtFollowGetEvent(HAND axisHandle,short *pEvent,short *pMasterDir,long *pPos);

// 获取FOLLOW的fifo剩余空间
// pSpace：空间大小
// fifoNo:fifo号，0或1
MTN_API short  __stdcall NMC_MtFollowGetSpace(HAND axisHandle,short *pSpace,short fifoNo);

// FOLLOW的段类型
#define PROFILE_FOLLOW_SEGMENT_NORMAL   	 (0)	// 0普通段
#define PROFILE_FOLLOW_SEGMENT_EVEN     	 (1)	// 1匀速段
#define PROFILE_FOLLOW_SEGMENT_STOP     	 (2)	// 2停止段
#define PROFILE_FOLLOW_SEGMENT_CONTINUE 	 (3)	// 3连续段

// 设置FOLLOW的数据
// masterPos：主轴位移
// slavePos:从轴位移
// type:数据段类型：0普通段，默认；1匀速段；2 减速到 0 段；3保持 FIFO 之间速度连续
// fifoNo:fifo号，0或1
MTN_API short  __stdcall NMC_MtFollowPushData(HAND axisHandle,long masterPos,double slavePos,short type,short fifoNo);

// 清除FOLLOW对应fifo号的数据
// fifoNo:fifo号，0或1
MTN_API short  __stdcall NMC_MtFollowClear(HAND axisHandle,short fifoNo);

// 启动Follow运动
// syncCount： 不包括axisHandle 的其他同步启动轴数量
// pSyncAxisArray: 其他同步启动轴的序号：0~N	
MTN_API short  __stdcall NMC_MtFollowStart(HAND axisHandle,short syncAxCnts,short *pSyncAxArray);

// 切换Follow运动的fifo号
// syncCount： 不包括axisHandle 的其他同步进行fifo切换的轴数量
// pSyncAxisArray: 其他同步进行fifo切换的轴的序号：0~N	
MTN_API short  __stdcall NMC_MtFollowSwitch(HAND axisHandle,short syncAxCnts,short *pSyncAxArray);


#ifdef __cplusplus
}
#endif


#endif  // _H_NMC_LIB20_H_
