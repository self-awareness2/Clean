///******************************************************************
//
// Moudle Name  :   mtn_lib20_oem.h
// Abstract     :   GaoChuan Motion 2.0 oem user header 
// Note :			1.�ṹ�嶨�������еġ�reservedxxx���ĳ�Ա���Ǳ�������,Ϊ���ּ�����,������Ϊ0
//					2.���ر�˵��,����API����RTN_CMD_SUCCESS����0ֵ����ʾִ�гɹ�,�������ʾ�������
//					3.���е�API������,���ر�˵��,axisHandle��ʾ������ľ��,devHandle��ʾĿ��������ľ��,crdHandle��ʾĿ������ϵ����
//                  4.mtn_lib20�����еĽṹ�嶼�������ֽڶ��뷽ʽ���룬Ϊ�˱���ṹ�������������⣬�뽫���뻷������Ϊ���ֽڶ���
// Modification History :
///******************************************************************
#ifndef _H_MTN_LIB20_OEM_H_
#define _H_MTN_LIB20_OEM_H_
#include "mtn_lib20.h"

#ifdef __cplusplus
extern "C" {
#endif

// ����PTP�ĸ߼�����
// minEvenTime:��С����ʱ��
// param1:����
MTN_API short  __stdcall OEM_MtSetMinEventTime(HAND axisHandle,short minEvenTime,short param1,short param2,short param3);

// ��ȡPTP�ĸ߼�����
MTN_API short  __stdcall OEM_MtGetMinEventTime(HAND axisHandle,short *minEvenTime,short *param1,short *param2,short *param3);

// ����ͬ���˶�
// mask:������
// pPosArray:λ������
MTN_API short  __stdcall OEM_PtpSync(HAND devHandle,short mask,long *pPosArray);


typedef struct
{
	long xStart;			// X���
	long yStart;			// Y���
	long xIntv;				// X���
	long yIntv;				// Y���
	long cnt;				// ����
	long reserved;
} TComp2DimensDataGroup;

// ���ܣ����ö�ά�Ƚ�����
// pArrayGroup:�Ƚ������ַ
// count:λ�õ���,count=0��ʾ����Ѿ���������ݡ�һ�������ѹ��128������
// group:���,0 ����1
// chn:����,��Ϊ0
MTN_API short __stdcall OEM_Comp2DimensSetDataGroup(HAND devHandle,short group,TComp2DimensDataGroup *pArrayGroup,short count,short chn);


// ���ܣ�����˫ͷ�˶��еĵڶ���ͷ��Ե�һ��ͷ�Ĳ���
// ������offsetX:˫ͷ��ԭ�����X���򣬵�2��ͷ��ԭ����Ե�1��ͷ��ԭ���ƫ����
//			 offsetY:˫ͷ��ԭ�����Y���򣬵�2��ͷ��ԭ����Ե�1��ͷ��ԭ���ƫ����
//			 pAxisNo:[0]�ڶ���ͷ��X���Ӧ�����  [1]�ڶ���ͷ��Y���Ӧ�����
MTN_API short __stdcall NMC_CrdSetDoubleHeadPara(HAND crdHandle,long offsetX,long offsetY,short *pAxisNo);

// ���ܣ���ȡ˫ͷ�˶��еĵڶ���ͷ��Ե�һ��ͷ�Ĳ���
// ������pOffsetX:˫ͷ��ԭ�����X���򣬵�2��ͷ��ԭ����Ե�1��ͷ��ԭ���ƫ����
//			 pOffsetY:˫ͷ��ԭ�����Y���򣬵�2��ͷ��ԭ����Ե�1��ͷ��ԭ���ƫ����
//			 pAxisNo:[0]�ڶ���ͷ��X���Ӧ�����  [1]�ڶ���ͷ��Y���Ӧ�����
MTN_API short __stdcall NMC_CrdGetDoubleHeadPara(HAND crdHandle,long *pOffsetX,long *pOffsetY,short *pAxisNo);

// ���ܣ�ʵ�ֵڶ����㽺ͷ��ͼԪ�л�����,��û�ӹ���һ��ͼԪ���л�������һ��ͼԪ��Ҫ��ϵ��ø�ָ��
// ������	rotX,rotY:��һ��ͼԪ����ת���ģ�һ��Ϊ������յ�λ�ã�
//			tgtPosX,tgtPosY:����һ��ͼԪ����ʼ��λ��XY������ 
//			deltaX��deltaY��theta:����һ��ͼԪ��������Ե�һ��ͼԪ���ĵ�ƫ�ƺ���ת����
//			deltaX��deltaY��λΪ���壬theta��λΪ��
//			vel,acc:�ڶ����㽺ͷ�ƶ��������ٶȺͼ��ٶ�
// ע��û�ж�deltaX deltaY�Լ�theta�����жϣ��������ݵڶ���ͷ��XY�г������жϡ�
MTN_API short __stdcall NMC_CrdBufObjectSwitch(HAND crdHandle, long segNo,long rotX,long rotY, 
	long tgtPosX,long tgtPosY, long deltaX,long deltaY,double theta,double vel,double acc);

// ���ܣ�����2��ͷ����1��ͷ��ͬ���˶���ϵ
MTN_API short __stdcall NMC_CrdBufSecondHeadSyncMoveOn(HAND crdHandle, long segNo);

// ���ܣ�����2��ͷ����1��ͷ��ͬ���˶���ϵ
MTN_API short __stdcall NMC_CrdBufSecondHeadSyncMoveOff(HAND crdHandle, long segNo);

#define LASER_PARAM_TAB_UNIT_MAX	64		// ���ļ������������
typedef struct
{
	// SHIOģʽ�µĲ���
	double gateTime; 		// ����gate ��ʱ��,��λ��s���ڲ���Сֵ��1/36us ��,ȡֵ��Χ(0,0.0009)
	long minFrq;			// ���Ƶ�ʣ���λHZ
	short gateDistance; 	// �̶�ģʽ�µ�λ�ü�� ��λ��pulse
    short k;				// ��Ƶ����ϵ��          
	short startDot; 	    // ����ʱ������
	short lowFrqRange; 		// ��Ƶ��Χ��0��100k��1��1M,2:9M
	short accLowFrqOnVel;	// ���ٶε�Ƶ���ܵ������ٶ�ֵ
	short decLowFrqOffVel;	// ���ٶε�Ƶ���ܵĹر��ٶ�ֵ
	short yCoe;				// Y�򲹳���ȡֵ��Χ[0,255],ʵ�ʱ���Ϊ0~2�ı�����coe*256���赽�������
	short yAng;				// ��ߵ���ת�Ƕ�
	
	// ��ͨģʽ�µĲ���
	long onDelay;		//������ʱ,��λus,ȡֵ��Χ[0,65535]
	long offDelay;		//�ع���ʱ,��λus,ȡֵ��Χ[0,65535]
	long minValue;		//��С���ֵ��DA���ʱ����Χ[0,32767],ռ�ձ����ʱ����Χ[0,100],Ƶ�����ʱ����Χ[0,2000000]
	long maxValue;		//������ֵ��DA���ʱ����Χ[0,32767],ռ�ձ����ʱ����Χ[0,100],Ƶ�����ʱ����Χ[0,2000000]
	long standbyPower;	//��������,Ϊ0��ʾȡ�����������������
	double overRide;	//���汶��,Ϊ0��ʾȡ��������������
	short followType;	//��������,0������滮�ٶ�,1������ʵ���ٶ�
	short reserved[7];	// ����

}TLaserParamTableUnit;


MTN_API short  __stdcall OEM_CrdBufLaserSetParamTableIdx( HAND crdHandle,long segNo,short tableIdx,short laserCh);
MTN_API short  __stdcall OEM_LaserSetParamTableIdx( HAND devHandle,short tableIdx,short laserCh);
MTN_API short  __stdcall OEM_LaserSetParamTableUnit( HAND devHandle,short tableIdx,TLaserParamTableUnit *pParamUnit);
MTN_API short  __stdcall OEM_LaserGetParamTableUnit( HAND devHandle,short tableIdx,TLaserParamTableUnit *pParamUnit);

//------------------------------------------------------------------------------------------------------------
//
//         ������˶�
//
//------------------------------------------------------------------------------------------------------------
// ���ٱ����
typedef struct
{
	double startVel;	// ��һ�������ٶ�
	double highVel;		// ���ٶ�����ٶ�
	double highAcc;		// ���ٶμ��ٶ�
	double highDec;		// ���ٶμ��ٶ�
	double lowVel;		// ���ٶ�����ٶ�
	double lowDec;		// ���ٶμ��ٶ�
	long highDist;		// ���ٶ�Ŀ��λ��
	long lowDist;		// ���ٶ�Ŀ��λ��
	short smooth;		// ƽ��ϵ����ȡֵ[0,50]
	short reseved[3];	// �����ֶ�
}TPvtMoveHighToLow;

// ����٣����ٱ����
MTN_API short  __stdcall OEM_MtPvtMoveHighToLow(HAND axisHandle,TPvtMoveHighToLow *pPrm);

// ���ٱ����
typedef struct
{
	double startVel;	// ��һ�������ٶ�
	double highVel;		// ���ٶ�����ٶ�
	double highAcc;		// ���ٶμ��ٶ�
	double highDec;		// ���ٶμ��ٶ�
	double lowVel;		// ���ٶ�����ٶ�
	double lowAcc;		// ���ٶμ��ٶ�
	long highDist;		// ���ٶ�Ŀ��λ��
	long lowDist;		// ���ٶ�Ŀ��λ��
	short smooth;		// ƽ��ϵ����ȡֵ[0,50]
	short reseved[3];	// �����ֶ�
}TPvtMoveLowToHigh;

// ����٣����ٱ����
MTN_API short  __stdcall OEM_MtPvtMoveLowToHigh(HAND axisHandle,TPvtMoveLowToHigh *pPrm);

// �������˶����ߵ͸ߣ�
typedef struct
{
 	double startVel;	//�����ٶ�
 	double vel1;		//��1�������˶����ٶȣ���λ������/���룩
 	double acc1;		//��1�μ��ٶȣ���λ������/����^2��
 	double dec1;		//��1�μ��ٶȣ���λ������/����^2��
 	double vel2;		//��2�������˶����ٶȣ���λ������/���룩
	double vel3;		//��3�������˶��ٶ�
 	double acc3;		//��3�μ��ٵ���3�εļ��ٶ�
 	double dec3;		//��3�μ��ٶ�

	long dist1;			//��1���г̣���λ�����壩
 	long dist2;			//��2���г̣���λ�����壩
 	long dist3;			//��3���г�
 	long reserved2;		// ����
	short smooth;		// ƽ��ϵ����ȡֵ[0,50]
	short reseved[3];	// �����ֶ�
} TPvtMove3Stage;

// ����٣��������˶����ߵ͸ߣ�
MTN_API short  __stdcall OEM_MtPvt3Stage(HAND axisHandle,TPvtMove3Stage *pPrm);


//------------------------------------------------------------------------------------------------------------
//
//         ����ϵ���ٶȣ���������
//
//------------------------------------------------------------------------------------------------------------
// ��������ϵ���ٶȣ����������������ؿ�����
#define LASER_CRDVELCOMP_PT_MAX			64
#define LASER_CRDVELCOMP_GROUP_MAX		4
typedef struct
{
	short count;								// ʵ�ʵ���
	short mode;									// ��������0������optionֵ��1������������� 2:�����������汶��
	short src;									// ��������,0:�������ٶȣ�1���滮�ٶ�
	short reserved[5];							// ����
	float vel[LASER_CRDVELCOMP_PT_MAX];			// �ٶȱ�
	float comp[LASER_CRDVELCOMP_PT_MAX];		// ����ֵ
}TLaserCrdVelCompTable;

// ��������ϵ�ٶȲ�����
// pCompTable��������
// group:����������ţ�ȡֵ��Χ[0,LASER_CRDVELCOMP_GROUP_MAX)
MTN_API short  __stdcall OEM_LaserSetCrdVelCompTable(HAND devHandle, TLaserCrdVelCompTable *pCompTable,short group);
MTN_API short  __stdcall OEM_LaserGetCrdVelCompTable(HAND devHandle, TLaserCrdVelCompTable *pCompTable,short group);

// ���û�ر��ٶȲ�������
// crdNo: ����ϵ��ţ�[0,1]
// onOff�����û�رգ�0���رղ������ܣ�1�����ò�������
// group:����������ţ�ȡֵ��Χ[0,LASER_CRDVELCOMP_GROUP_MAX)
// laserCh:����ͨ����
MTN_API short  __stdcall OEM_LaserCrdVelCompOnOff(HAND devHandle, short crdNo,short onOff,short group,short laserCh);

// ���û�ر��ٶȲ�������,������ָ��
// onOff�����û�رգ�0���رղ������ܣ�1�����ò�������
// group:����������ţ�ȡֵ��Χ[0,LASER_CRDVELCOMP_GROUP_MAX)
// laserCh:����ͨ����
MTN_API short  __stdcall OEM_CrdBufLaserCrdVelCompOnOff( HAND crdHandle,long segNo,short onOff,short group,short laserCh);

// ��ȡ���ἱͣDI�Ĵ���״̬
// pTrigSts:�Ƿ񴥷���1��ʾ�Ѿ�������NMC_MtSetEstopDIMask/NMC_MtSetEstopDIָ��Ḵλ����״̬��
// pTrigIndex:���δ�����di��š�NMC_MtSetEstopDIMask/NMC_MtSetEstopDIָ��Ḵλ����״̬��
MTN_API short  __stdcall OEM_MtGetEstopDITrigSts(HAND axisHandle, short *pTrigSts ,short *pTrigIndex);

// ��������������PTP�������˶�
// segNo:�κ�
// axisNo����ţ�ȡֵ[0,n),������ϵ����
// tgtPos��Ŀ��λ��
// blockEn:0:��������ͬ����1������
// �����ٵĲ����ο�TPtpTwoStagePrm����
MTN_API short __stdcall OEM_CrdBufSetPtpTwoStage(HAND crdHandle, long segNo,short axisNo,long tgtPos,short inType,
			short inIndex,short inTrigLevel,short action,double prm1,double prm2,double prm3,double prm4,short blockEn);

// �����������ƶ���������
// segNo:�κ�
// axisNo�����,[0,n]
// vel:�˶��ٶ�
// acc:�˶����ٶ�
// dec:�˶������ٶ�
// velS:�˶������ٶ�
// velE:�˶��յ��ٶ�
// smoothCoef:ƽ��ϵ��
MTN_API short __stdcall OEM_CrdBufSetPtpMoveParaEx(HAND crdHandle, long segNo,short axisNo,double vel,double acc,double dec,double velS,double velE,short soomthCoef);


// ��������������ƫ��ֵ
// segNo:�κ�
// compType:bias���ͣ�0:���� 1:����ϵ�� 2:optionֵ
// bias:ƫ��ֵ
// ch:����ͨ��
MTN_API short __stdcall OEM_CrdBufSetLaserBias(HAND crdHandle, long segNo,short biasType,double bias,short ch);

MTN_API short __stdcall OEM_LaserSetBias(HAND devHandle, short biasType,double bias,short ch);

///////////////////////////////////////////// UART
//��żУ��λѡ��
#define UART_PARITY_N                       0		// ��У��
#define UART_PARITY_O                       1		// ��У��
#define UART_PARITY_E                       2		// żУ��

//ֹͣλ
#define UART_STOP_BITS_10                   0		// ֹͣλΪ1
#define UART_STOP_BITS_15                   1		// ֹͣλΪ1.5
#define UART_STOP_BITS_20                   2		// ֹͣλΪ2

typedef struct
{
	long baudrate;			// ������
	short mode;				// �˿ڵĹ���ģʽ:0:Ĭ�ϣ���չģ�鹤��ģʽ��1:����Э��ģʽ
	short dataBits;			// ����λ,ȡֵ��Χ[7,8]
	short stopBits;			// ֹͣλ,ȡֵ��Χ[0,2]���ο��궨�壬��UART_STOP_BITS_10��
	short parity;			// У�鷽ʽ����UART_PARITY_N��
	short rxBufLen;			// ���ջ��泤�ȣ�Ĭ��128
	short txBufLen;			// ���ͻ��泤�ȣ�Ĭ��128
	short reserved[4];		// ����
}TUartPara;		

// ����Uart�˿�������ģʽ�µ�ͨѶ����
// pParam:����
// ch:��������д0
MTN_API short __stdcall OEM_DevUartSetPara( HAND devHandle, TUartPara  *pParam,short ch);

// ��ȡUart�˿ڵĲ���
MTN_API short __stdcall OEM_DevUartGetPara( HAND devHandle, TUartPara  *pParam,short ch);

// �򿪻�ر�UART
// onOff:0���رգ�1����
// ch:��������д0
MTN_API short __stdcall OEM_DevUartOnOff( HAND devHandle, short onOff,short ch );

// ��Uart�˿�
// onOff:0���رգ�1����
// pBuf:�����ݽ��ջ�����
// readLen:��Ҫ��ȡ�����ݳ��ȣ�byte,һ������256�ֽ�
// retLen:ʵ�ʶ��������ݳ��ȣ�byte
// ch:��������д0
MTN_API short __stdcall OEM_DevUartRead( HAND devHandle, void *pBuf,short readLen,short *retLen ,short ch);

// дUart�˿�
// onOff:0���رգ�1����
// pBuf:д����
// writeLen:д�����ݳ��ȣ�byte,һ�����д256�ֽ�
// writedLen:ʵ��д�������ݳ��ȣ�byte
// ch:��������д0
MTN_API short __stdcall OEM_DevUartWrite( HAND devHandle, void *pBuf,short writeLen,short *writedLen ,short ch);

// ������ջ���
MTN_API short __stdcall OEM_DevUartClrRx( HAND devHandle,short ch);

// ��ȡ��ǰ�����յ������ݳ���
// pOnOff:��״̬
// pLen:��������ݳ���
// ch:��������д0
MTN_API short __stdcall OEM_DevUartGetRxLen( HAND devHandle,short *pOnOff,long *pLen,short ch);

// �����ٶȵĵ���ֹͣ����,
// dec:���ٶ�,��λ��pulse/ms^2
// ע�⣺1.����PTP��Jog�˶���Ч�����������˶�ģʽ����ͬ��NMC_MtStop
//       2.���ָ���ļ��ٶ�̫С�����Զ����պ��ʵļ��ٶȼ���Ϊ0
MTN_API short __stdcall OEM_MtStopEx( HAND axisHandle,double dec);

// ����ͬ��
MTN_API short __stdcall OEM_Sync( HAND devHandle);


typedef struct 
{  
	short axMask;		// ����������룬���8��
	short captMode;		// ����ģʽ���ο�NMC_MtSetCaptSns�Ĳ�������
	short captIoSrc;	// ����Դ���ο�NMC_MtSetCaptSns�Ĳ�������
    short captLev;		// �����ƽ���ο�NMC_MtSetCaptSns�Ĳ�������
	long captMaxCnt;	// ��ಶ����ٸ�����
	short reserved[2];
}TRepeatCaptParamEx;

// �����ظ�����Ex�Ĳ���
// pParam:�ظ�����cans
// ch:ͨ���ţ�����������0
MTN_API short __stdcall OEM_CaptRepeatSetParamEx( HAND devHandle,TRepeatCaptParamEx *pParam,short ch);
MTN_API short __stdcall OEM_CaptRepeatGetParamEx( HAND devHandle,TRepeatCaptParamEx *pParam,short ch);

// ������ر��ظ�����
// onOff:1:����0:��
// ch:ͨ���ţ�����������0
MTN_API short __stdcall OEM_CaptRepeatOnOffEx( HAND devHandle,short onOff,short ch);

// ��ȡ�ظ��������
// pOnOff:onOff״̬
// pLeftCount:ʣ��Ĳ������
// pSumCnt:�ۼƲ������
// pGetCount:�Ѿ���ȡ�Ĵ���
// ch:ͨ���ţ�����������0
MTN_API short  __stdcall OEM_CaptRepeatGetStatusEx(HAND devHandle,short *pOnOff,long *pLeftCount,long *pGetCount,long *pSumCnt,short ch);


// ��ȡ�ظ�����λ��ֵ
// pPosArray:���ص�λ��ֵ����
// count:Ҫ��ȡ�Ĵ���λ��������ȡֵ��Χ[1,32]
//       ע�⣺����ÿ����һ�Σ������n��λ�����ݣ����ᣩ������ͬʱ�����ĸ��ᣬ��count=1��ʾ�û��ĸ�λ��ֵ
// pGetCount:ʵ�ʷ��ص���Ŀ
// ch:ͨ���ţ�����������0
MTN_API short  __stdcall OEM_CaptRepeatGetPosEx(HAND devHandle,long *pPosArray,short count,short *pGetCount,short ch);


//------------------------------------------------------------------------------------------------------------
//
//	Modbus
//
//------------------------------------------------------------------------------------------------------------
typedef struct 
{  
	short mode;			// ģʽ -1:��չģ��,0:RTU,1:ASCII,16:RTU_Master
	short slaveAddr;	// ��վ��ַ,����Ϊ��վʱ��Ч
	short port;			// Ӳ���˿ڣ���2��Ч
	short parity;		// У�����ͣ�0����У�飬1����У�飬2��żУ��
	short dataBit;		// ����λ
	short stopBit;		// ֹͣλ
	long bautrate;		// ������
	short masterTimeout;// ��վ�������Ӧʱ��,��λ������
	short reserved[7];	// ����
}TModbusParam;

// Modbus��ʼ��
// pParam:����
MTN_API short  __stdcall OEM_ModbusInit(HAND devHandle,TModbusParam *pParam);

// Modbus�Ĵ���������ȡ
// regType:�Ĵ�������,0:din,bit;1:coil,bit;2:input word,4:holding,word
// pRegCnt:�Ĵ�������
// pStartAddr:�Ĵ�����ʼ��ַ
MTN_API short  __stdcall OEM_ModbusGetRegParam(HAND devHandle,short regType,short *pRegCnt,long *pStartAddr);

// Modbus�Ĵ�����������
// regType:�Ĵ�������,0:din,bit;1:coil,bit;2:input word,4:holding,word
// regCnt:�Ĵ�������
// startAddr:�Ĵ�����ʼ��ַ
MTN_API short  __stdcall OEM_ModbusSetRegParam(HAND devHandle,short regType,short regCnt,long startAddr);

// Modbus������ȡ
// pParam:����
MTN_API short  __stdcall OEM_ModbusGetParam(HAND devHandle,TModbusParam *pParam);


// ��ȡ��ǰ��modbus����
// pSts: 
	//0:unset
	//1:slave mode, unconnected
	//2:slave mode, connected
	//3:master mode, unconnected
	//4:master mode, connected
MTN_API short  __stdcall OEM_ModbusGetSts(HAND devHandle,short  *pSts);

// Modbus�ر�
// flag:1��ʾ�л�����չģ��ģʽ��������־ֻ�ر�Modbus
MTN_API short  __stdcall OEM_ModbusClose(HAND devHandle,short flag);

// Modebus:��ȡ��������
// offset:��ַƫ��
// count:��������
// pBuff:���ص�����
// slaveAddr:���ڿ�������Ϊ��վ���ò�����ѡ����Ч����������Ϊ��վ����ʾ��վ��ַ[1~127]
MTN_API short  __stdcall OEM_ModbusGetDin(HAND devHandle,short offset,short count,unsigned char *pBuff,short slaveAddr);

// Modebus:��ȡ��Ȧ����
// offset:��ַƫ��
// count:��������
// pBuff:���ص�����
// slaveAddr:���ڿ�������Ϊ��վ���ò�����ѡ����Ч����������Ϊ��վ����ʾ��վ��ַ[1~127]
MTN_API short  __stdcall OEM_ModbusGetCoil(HAND devHandle,short offset,short count,unsigned char *pBuff,short slaveAddr);

// Modebus:��ȡ���ּĴ���
// offset:��ַƫ��
// count:��������
// pBuff:���ص�����
// slaveAddr:���ڿ�������Ϊ��վ���ò�����ѡ����Ч����������Ϊ��վ����ʾ��վ��ַ[1~127]
MTN_API short  __stdcall OEM_ModbusGetHolding(HAND devHandle,short offset,short count,unsigned short *pBuff,short slaveAddr);

// Modebus:��ȡ16λ����Ĵ���
// offset:��ַƫ��
// count:��������
// pBuff:���ص�����
// slaveAddr:���ڿ�������Ϊ��վ���ò�����ѡ����Ч����������Ϊ��վ����ʾ��վ��ַ[1~127]
MTN_API short  __stdcall OEM_ModbusGetInput(HAND devHandle,short offset,short count,unsigned short *pBuff,short slaveAddr);

// Modebus:д��������
// offset:��ַƫ��
// count:��������
// pBuff:����
// slaveAddr:���ڿ�������Ϊ��վ���ò�����ѡ����Ч����������Ϊ��վ����ʾ��վ��ַ[1~127]
MTN_API short  __stdcall OEM_ModbusSetDin(HAND devHandle,short offset,short count,unsigned char *pBuff,short slaveAddr);

// Modebus:д��Ȧ����
// offset:��ַƫ��
// count:��������
// pBuff:����
// slaveAddr:���ڿ�������Ϊ��վ���ò�����ѡ����Ч����������Ϊ��վ����ʾ��վ��ַ[1~127]
MTN_API short  __stdcall OEM_ModbusSetCoil(HAND devHandle,short offset,short count,unsigned char *pBuff,short slaveAddr);

// Modebus:д���ּĴ���
// offset:��ַƫ��
// count:��������
// pBuff:����
// slaveAddr:���ڿ�������Ϊ��վ���ò�����ѡ����Ч����������Ϊ��վ����ʾ��վ��ַ[1~127]
MTN_API short  __stdcall OEM_ModbusSetHolding(HAND devHandle,short offset,short count,unsigned short *pBuff,short slaveAddr);

// Modebus:д16λ����Ĵ���
// offset:��ַƫ��
// count:��������
// pBuff:����
// slaveAddr:���ڿ�������Ϊ��վ���ò�����ѡ����Ч����������Ϊ��վ����ʾ��վ��ַ[1~127]
MTN_API short  __stdcall OEM_ModbusSetInput(HAND devHandle,short offset,short count,unsigned short *pBuff,short slaveAddr);




// �Գ��˶�����
// ����������ƽ��ƽ�棬��ƽ��XY�Զ�������ƽ��XY���˶����˶�����Ϊ����O��Գ�
// ���̣�1.���ò���
//		 2.��������˶����ԳƵ㣬Ȼ����������
//       3.�����˶������У������Զ�����
//       4.�رո��棬�������
typedef struct 
{  

	long masterCent[2];			// ��ƽ���Բ������
	long slaveCent[2];			// ��ƽ���Բ������
	long masterStart[2];		// ��ƽ����������
	long slaveStart[2];			// ��ƽ����������

	short slaveAxMask;			// �������룬�����ᣬ������ϵ��
	short reserved[3];			// ��������

}TCrdSymmParam;

// ���öԳ��˶�����
MTN_API short __stdcall OEM_CrdSetSymmParam(  HAND crdHandle, TCrdSymmParam *pParam);

// ������رնԳƸ����˶�
MTN_API short __stdcall OEM_CrdBufSymmOnOff(  HAND crdHandle, long segNo,short onOff);


// Բ����λ
typedef struct 
{  
	short axMask;		// ������������
	short mode;			// 0:������ֹͣ�������˶���1��ֹͣ������ͣ��־λ
	long centPosX;		// Բ����λ��Բ��X����λ��pulse
	long centPosY;		// Բ����λ��Բ��Y����λ��pulse
	long radius;		// �뾶���뾶Ϊ0��ʾȡ����ͨ����Բ��������λ��飬��λ��pulse
	float yProp;		// ϵ����Y����ĵ�������X����ĵ���
	float reserved2;	// ����
}TCircleLimitPara;

// ����Բ����λ���� 
// pPara:����
// chn:ͨ���ţ��������ö���
MTN_API short __stdcall OEM_SetCircleLimit(HAND devHandle,TCircleLimitPara *pPara,short chn);
MTN_API short __stdcall OEM_GetCircleLimit(HAND devHandle,TCircleLimitPara *pPara,short chn);


//------------------------------------------------------------------------------------------------------------
//
//	Scan
//
//------------------------------------------------------------------------------------------------------------
 
// ��ͨ������
#define OEM_SCAN_MAX_CHN		1

// �񾵿����������
MTN_API short __stdcall OEM_ScanBufClr(HAND devHandle,short chn);

// �񾵿��Ƶ�������ֹͣ��0��ֹͣ��1:����
MTN_API short __stdcall OEM_ScanOnOff(HAND devHandle,short onOff,short chn);

// ��������ѹ��
MTN_API short __stdcall OEM_ScanEndList(HAND devHandle,short chn);

// �񾵿���ָ��˶�ָ��,�����˶�
// pXPosArray:x�����λ������
// pYPosArray:y�����λ������
// cnt:������������ݸ���
MTN_API short __stdcall OEM_ScanBufMoveAbs(HAND devHandle,short *pXPosArray,short *pYPosArray,short cnt,short chn);

// �񾵿���ָ��˶�ָ��,����˶�
// pXPosArray:x�����λ������
// pYPosArray:y�����λ������
// cnt:������������ݸ���
MTN_API short __stdcall OEM_ScanBufMoveRel(HAND devHandle,short *pXPosArray,short *pYPosArray,short cnt,short chn);

// �񾵿���ָ�����λ��ģʽ
// posMode:λ��ģʽ��0�����ԣ�Ĭ�ϣ�1�����
MTN_API short __stdcall OEM_ScanBufSetPosMode(HAND devHandle,short posMode,short chn);

// �񾵿���ָ����¶κ�
// segNo:�κ�
MTN_API short __stdcall OEM_ScanBufSetSegNo(HAND devHandle,long segNo,short chn);

// �񾵿���ָ���ʱָ��
// delayUs:��ʱʱ�䣬��λus
MTN_API short __stdcall OEM_ScanBufDelay(HAND devHandle,long delayUs,short chn);

// �񾵿���ָ����⿪��ָ��
// laserOnOff:����
MTN_API short __stdcall OEM_ScanBufLaserOnOff(HAND devHandle,short laserOnOff,short chn);

// �񾵿���ָ����⿪�ع���ʱ
// onDelay:������ʱ����λus,ȡֵ��Χ[0,65535]
// offDelay:�ع���ʱ����λus,ȡֵ��Χ[0,65535]
MTN_API short __stdcall OEM_ScanBufLaserSetOnOffDelay(HAND devHandle,double onDelay,double offDelay,short chn);

// �񾵿���ָ���������PWM����
// pulseWid:PWM��ȣ���λus,ȡֵ��Χ[0.25,16000]
// onTime:onʱ�䣬��λus,,ȡֵ��Χ[0.25,16000]
MTN_API short __stdcall OEM_ScanBufLaserSetPowerPwm(HAND devHandle,double pulseWid,double onTime,short chn);

// �񾵿���ָ���������DAC����
// dac:��ѹ���ֵ
MTN_API short __stdcall OEM_ScanBufLaserSetPowerDac(HAND devHandle,short dac,short chn);


//״̬λ����
#define BIT_SCAN_EN					(0x00000001)    // ʹ�ܱ�־λ 
#define BIT_SCAN_RUN				(0x00000002)    // �˶�:1 ,��ֹ 0   
#define BIT_SCAN_END				(0x00000004)    // �Ƿ�End��־λ
#define BIT_SCAN_BUF_FULL			(0x00000008)    // ������    
#define BIT_SCAN_BUF_EMPTY			(0x00000010)    // ���ݿ�    
#define BIT_SCAN_ERR_PUSH	        (0x00001000)    // ѹ���ݴ���    
#define BIT_SCAN_ERR_POP	        (0x00002000)    // ȡ���ݴ���
#define BIT_SCAN_ERR_OTHER	        (0x00004000)    // �������󣬲ο�errCode

typedef struct 
{  
	long sts;				// ����״̬����λ��ʾ������
	long userSeg;			// �û��κ�
	long leftSpace;			// ʣ��ռ�
	long usedSpace;			// ʹ�ÿռ�
	unsigned long cmdAllCnt;// ȫ��ָ��ļ���
	short xPos;				// x����ǰλ��
	short yPos;				// y����ǰλ��
	short errCode;			// ������
	short reserved[3];		// ����

}TOemScanSts;

// ��ȡ�񾵵�����״̬
MTN_API short __stdcall OEM_ScanGetSts(HAND devHandle,TOemScanSts *pSts,short chn);


// �ֶ����˶���ָ����
MTN_API short __stdcall OEM_ScanMoveAbs(HAND devHandle,short x,short y,short chn);

// �ֶ�������
MTN_API short __stdcall OEM_ScanLaserOnOff(HAND devHandle,short onOff,short chn);

// �ֶ������PWM
// pulseWid:PWM��ȣ���λus,ȡֵ��Χ[0.5,16000]
// onTime:onʱ�䣬��λus
MTN_API short __stdcall OEM_ScanLaserPowerPwm(HAND devHandle,double pulseWid,double onTime,short chn);

// �ֶ������DAC
MTN_API short __stdcall OEM_ScanLaserPowerDac(HAND devHandle,short dac,short chn);

//------------------------------------------------------------------------------------------------------------
//
//         �¼�
//
//------------------------------------------------------------------------------------------------------------
#define EVENT_MAX_CHN		8

// event src
#define EVENT_SRC_PRFPOS	0				// �滮λ��
#define EVENT_SRC_ENCPOS	1				// ʵ��λ��

// event dir
#define EVENT_DIR_BIGGER		0			// ����
#define EVENT_DIR_SMALLER		1			// С��
#define EVENT_DIR_EQUAL			2			// ����
#define EVENT_DIR_NOT_BIGGER	3			// ������
#define EVENT_DIR_NOT_SMALLER	4			// ��С��
#define EVENT_DIR_NOT_EQUAL		5			// ������

// action ID
#define EVENT_ACTION_NONE		0			// ��ִ���κεĶ���
#define EVENT_ACTION_SETDO		1			// ����DO��idx:��ţ�param1:���λ���룬param2:���ֵ����
#define EVENT_ACTION_PTP_VEL	2			// ����PTP���ٶȣ�idx:��ţ�param1:�ٶȣ�param2:����
 
typedef struct
{
 	short eventSrc;							// �¼���Դ����EVENT_SRC_PRFPOS
 	short eventIdx;							// �¼������
	short dir;								// ����
	short errZone;							// ���
	long trigCnt;							// ��������
	long eventReserved[3];					// ����
	double compVal1;						// �Ƚ�ֵ
	
	short actionType;						// �¼�������Ķ�������
	short actionIdx;						// �������
	float actionParam1;						// ��������
	float actionParam2;						// ��������2
	short actionReserved[6];				// ����
} TEventConfig;

// �¼�����
// pEventCfg:���ò������μ��ṹ�嶨��
// chn:ͨ���ţ�ȡֵ��Χ[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_DevEventSetConfig(HAND devHandle, TEventConfig *pEventCfg,short chn);

// ��ȡ�¼�����
// pEventCfg:���ò������μ��ṹ�嶨��
// chn:ͨ���ţ�ȡֵ��Χ[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_DevEventGetConfig(HAND devHandle,TEventConfig *pEventCfg,short chn);

// ��ȡ�¼�����
// onOff:���أ�0:�� 1:��
// chn:ͨ���ţ�ȡֵ��Χ[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_DevEventSetOnOff(HAND devHandle,short onOff,short chn);

// ��ȡ״̬
// pOnOff:����״̬��0:�� 1:��
// pTrigCnt:��������
// chn:ͨ���ţ�ȡֵ��Χ[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_DevEventGetSts(HAND devHandle,short *pTrigCnt,short *pOnOff,short chn);

// �����������¼�������
// pEventCfg:������Ϣ
// onOff:�Ƿ����������ر�
// chn:ͨ���ţ�ȡֵ��Χ[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_CrdBufEventSetConfig(HAND crdHandle,long segNo,TEventConfig *pEventCfg,short onOff,short chn);

// �������¼�����
// onOff:�Ƿ����������ر�
// chn:ͨ���ţ�ȡֵ��Χ[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_CrdBufEventSetOnOff(HAND crdHandle,long segNo,short onOff,short chn);

// �������ȴ��¼�����
// trigCnt:�������¼�����
// timeOut:��ʱ ��λ:ms
// chn:ͨ���ţ�ȡֵ��Χ[0,EVENT_MAX_CHN)
MTN_API short  __stdcall OEM_CrdBufEventWait(HAND crdHandle,long segNo,short trigCnt,long timeOut,short chn);

// ����ʾ�̿�ʼ
// startPos:��ʼλ�ã���λ:����
// interval:�������λ:����
// sectCount:ʾ�̵Ķ���
// pFileNameToSaveTechData:ʾ�����ݵĴ洢�ļ�
MTN_API short  __stdcall OEM_MtLeadScrewTechRun(HAND axisHandle,long startPos,long interval,long sectCount,char *pFileNameToSaveTechData);

// ����ʾ�̹���״̬��ѯ
// pRun:����״̬��0��ֹͣ�У�1���������У��������������
// pPercent:���еĽ��Ȱٷֱ�
MTN_API short  __stdcall OEM_MtLeadScrewTechSts(HAND axisHandle,short *pRun,short *pPercent);

// ����ʾ��ǿ����ֹ
MTN_API short  __stdcall OEM_MtLeadScrewTechBreak(HAND axisHandle);

// ���ػ���ʾ������
// pFileNameTechData:�����ļ���
MTN_API short  __stdcall OEM_MtLeadScrewTechLoad(HAND axisHandle,char *pFileNameTechData);



// ���������������
typedef struct
{
	short encoderIdx;		//��������ţ�ȡֵ��Χ[0,n],256��ʾ����������
	short encoderMode;		//������ģʽ����ο�NMC_SetEncMode˵��
	short reserved[6];		// ����
}TEncoderCfg;

//���õ��������������
MTN_API short  __stdcall OEM_MtSetEncCfg (HAND axisHandle,TEncoderCfg *pPara);

//��ȡ���������������
MTN_API short  __stdcall OEM_MtGetEncCfg (HAND axisHandle,TEncoderCfg *pPara);


// ������PTP�˶�
// pPrfTime:���ڹ滮λ�ô��������������滮��Ҫ��ʱ��
MTN_API short  __stdcall OEM_MtMovePtpAbsTwoStageEx(HAND axisHandle,TPtpTwoStagePrm *pPrm,double *pPrfTime);

// ���ܣ�2άλ�ñȽ��Զ��������
// onOff�� 0 ֹͣ,1��� ע�⣺NMC_Comp2DimensOnoff�ر�Ҳ����ʵ�ֹر��������
// group:���,0 ����1
// outInteval:����������λus
// outCnt:�������
// chn:����,��Ϊ0
MTN_API short __stdcall OEM_Comp2DimensOutPulse(HAND devHandle,short group,short onOff,long outInteval,long outCnt,short chn);


// PT��PVT OEM
// ��ѯPT����ʣ��ռ��С
// pSpace:���ص�ʣ��ռ��С
// pUsed: ��ʹ�õĿռ����
// fifo:����������ģʽ�£�ʹ�õ�FIFO��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_MtPtGetSpaceEx(HAND axisHandle,short *pSpace,short *pUsed,short fifo);

// ��Pt�˶���������ѹ�˶����ݶ�
// count:ѹ������ݶ���
// pPosArray:�����о���
// pTimeArray:������ʱ��
// pTypeArray:������,���궨��
// fifo:����������ģʽ�£�ʹ�õ�FIFO��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_MtPtPushEx(HAND axisHandle,short count,double *pPosArray,long *pTimeArray,short *pTypeArray,short fifo);

// ���PT����
// fifo:����������ģʽ�£�ʹ�õ�FIFO��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_MtPtBufClrEx(HAND axisHandle,short fifo);

// ����Pt�˶�
// otherSynAxCnts�� ������axisHandle ������ͬ������������
// pOtherSynAxArray: ����ͬ�����������ţ�0~N	
// fifo:����������ģʽ�£�ʹ�õ�FIFO��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_MtPtStartMtnEx(HAND axisHandle,short otherSynAxCnts,short *pOtherSynAxArray,short fifo);

// ��PVT�˶���������ѹ�˶����ݶ�
// count:ѹ������ݶ�����1~32
// pPosArray:�����о���
// pTimeArray:������ʱ��
// pVelArray:�������ٶ�
// fifo:����������ģʽ�£�ʹ�õ�FIFO��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_MtPvtDataEx(HAND axisHandle,short count,double *pPosArray,double *pTimeArray,double *pVelArray,short fifo);

// ��ѯPVT����ʣ��ռ��С
// pFreeSpace:���ص�ʣ��ռ��С
// pUsedSpace: ��ʹ�õĿռ����
// fifo:����������ģʽ�£�ʹ�õ�FIFO��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_MtPvtBufGetSpaceEx(HAND axisHandle,short *pFreeSpace,short *pUsedSpace,short fifo);

// ���PVT����
// fifo:����������ģʽ�£�ʹ�õ�FIFO��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_MtPvtBufClrEx(HAND axisHandle,short fifo);

// ����Pvt�˶�
// otherSynAxCnts�� ������axisHandle ������ͬ������������
// pOtherSynAxArray: ����ͬ�����������ţ�0~N	
// fifo:����������ģʽ�£�ʹ�õ�FIFO��ţ�ȡֵ��Χ[0,1]
// ע��ͬ�������������ͬһ��������
MTN_API short  __stdcall OEM_MtPvtStartMtnEx(HAND axisHandle,short otherSynAxCnts,short *pOtherSynAxArray,short fifo);

// ��ȡ������λ�ã�����ǰ��
// pEncPosEx:����ǰ�ı�����λ��
MTN_API short  __stdcall OEM_MtGetEncPosEx(HAND axisHandle,long *pEncPosEx);

// PTPBufMv
#define PTPBUFMV_MAX_GROUP		2		// ��������
#define PTPBUFMV_MAX_AX			4		// ���Ĳ���������
#define PTPBUFMV_MAX_SEC		4		// ���Ķ���

// Ptp�˶���Ԫ
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
	short errCode;			// �������
	short curUnitIdx;		// ��ǰִ�еĵ�Ԫ���
	short reserved[3];		// ����
}TPtpBufMvSts;

// ѹ��Ptp�����˶�����
// axisCnt:�������������ȡֵ��Χ[1,4]
// pAxisList:��������б�����
// unitCnt:�˶��Ķ�������ȡֵ��Χ[1,4]
// pMvUnitList:�˶��Ķ������б����鳤��ΪaxisCnt*unitCnt
// group:��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_PtpBufMvPushData(HAND devHandle,short axisCnt,short *pAxisList,short unitCnt,TPtpBufMvUnit *pMvUnitList,short group);

// ����Ptp�����˶�
// group:��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_PtpBufMvStart(HAND devHandle,short group);

// ֹͣPtp�����˶�
// group:��ţ�ȡֵ��Χ[0,1]
MTN_API short  __stdcall OEM_PtpBufMvStop(HAND devHandle,short group);

// ��ѯPtp�����˶�״̬
// group:��ţ�ȡֵ��Χ[0,1]
// pSts:״̬
MTN_API short  __stdcall OEM_PtpBufMvSts(HAND devHandle,TPtpBufMvSts *pSts,short group);




/*

//-------------------------------------------------------------------------------
//1.�����˶�
//-------------------------------------------------------------------------------
// �����˶�����
// mapNum:�����������; pMapNo:���б�
NMC_API short __stdcall NMC_MultiLineSetsysPara(HAND multiHandle,short *pMapNo,short mapNum);
// ѹ������˶�����
// pEndPos:�յ�λ��; vel:�ٶ� ;acc:�ٶ� ;dec:�ٶ� ;blendRatio:���ϵ��;userID:�û�ID
NMC_API short __stdcall NMC_MultiLineAddMoveData(HAND multiHandle,double *pEndPos,double vel,double acc,double dec,double blendRatio,long userID);
// ��������˶�����
NMC_API short __stdcall NMC_MultiLineClrData(HAND multiHandle,long *pSpace);
// ���������˶�
NMC_API short __stdcall NMC_MultiLineStart(HAND multiHandle);
// ֹͣ�����˶�
NMC_API short __stdcall NMC_MultiLineStop(HAND multiHandle,short stopType);
// ��ȡ�����˶�״̬
NMC_API short __stdcall NMC_MultiLineGetSts(HAND multiHandle,short *pRunSts,short *pErr);
// ��ص�����ָ��
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
//2.��άλ�ñȽ�
//-------------------------------------------------------------------------------
typedef struct
{
	short outputChn;							// �Ƚ������ͨ���ţ�ȡֵ[0,n]
	short outputType; 							// �����ʽ0������1����ƽ
	short chnType;      						// ͨ�����ͣ�0 GPO, 1  GATEͨ��
	short dir1No; 								// ����1 ��λ��Դ��ţ�0~11��
	short dir2No; 								// ����2 ��λ��Դ��ţ�0~11��
	short posSrc; 								// ��λ������ ��0�滮1��������
	short stLevel;								// ��ƽģʽ�µ���ʼ��ƽ��0��1��
	short errZone; 								// ����Ƚϵ��ݲ�뾶��Χ��pulse��
	short  directOutZone;						// ������ֱ�Ӵ�����Χ
	short  vibrateRange;						// �����˲���Χ	
	long gateTime; 								// ���巽ʽ����ʱ��,��λus
	long minIntervalTime;						// ��С����ʱ����,��λus
	long out2Delay;								// ���2���ͺ�ʱ�䣬��λus
	long reserved[7];							// ������Ĭ��ֵ 0����ʹ�ã�
} TComp2DimensParamEx;

typedef struct
{
	short axCnt;				// �������������ȡֵ[1,6]
	short axList[6];			// ��������б�
	short outType;				// �����ʽ0������1����ƽ
	short outChnType;			// ͨ�����ͣ�0 GPO, 1  GATEͨ��
	short outChnIdx;			// �Ƚ�����źŵ�ͨ���ţ�ȡֵ[0,n]
	short posSrc;				// ��λ������ ��0�滮1��������
	short stLevel;				// ��ƽģʽ�µ���ʼ��ƽ��0��1��
	long gateTime;				// ���巽ʽ����ʱ��,��λus
	long errZone;				// ����Ƚϵ��ݲ�뾶��Χ��pulse��
	long directOutZone;			// ������ֱ�Ӵ�����Χ
	long reserved[7];			// ������Ĭ��ֵ 0����ʹ�ã�
} TCompXDimensExParam;

// ���ö�άλ�ñȽ�
// pParam:����  group:��ţ�ȡֵ[0,n]
NMC_API short __stdcall OEM_CompXDimensExSetParam(HAND hDev,TCompXDimensExParam *pParam,short group);
NMC_API short __stdcall OEM_CompXDimensExGetParam(HAND hDev,TCompXDimensExParam *pParam,short group);

// ���ܣ����ö�άλ�ñȽ�����
// pArrayPos:�Ƚ�����λ��ֵ
// count:λ�õ���,count=0��ʾ����Ѿ���������ݡ�һ�������ѹ��128������
// group:���,0 ����1
MTN_API short __stdcall OEM_CompXDimensExSetData(HAND devHandle,long *pArrayPos,short count,short group);

// ���ܣ������άλ�ñȽ�����
MTN_API short __stdcall OEM_CompXDimensExClrData(HAND devHandle,short group);

// ���ܣ���άλ�ñȽ�ʹ��
// onOff�� 0 ֹͣ,1���  
MTN_API short __stdcall OEM_CompXDimensExOnoff(HAND devHandle,short onOff,short group);

// ���ܣ���άλ�ñȽ��ֶ����
MTN_API short __stdcall OEM_CompXDimensExManual(HAND devHandle,short outCnt,short group);

typedef struct
{
	short sts;				// ����״̬��0 ���� 1 æ
	short reserved1;		// ����
	long freeSpace;			// ������ʣ��ռ�
	long usedSpace;			// ʣ��λ�ñȽϵ�
	long outCount;			// �Ѿ�����ĸ���
	long reserved2[4];		// ����
} TCompXDimensExSts;

// ���ܣ���άλ�ñȽϵ����״̬
// pStatus: ״̬�ṹ��
// group:���,0 ����1
MTN_API short __stdcall OEM_CompXDimensExGetSts(HAND devHandle,TCompXDimensExSts *pStatus,short group);

*/





#ifdef __cplusplus
}
#endif






#endif	// _H_MTN_LIB20_OEM_H_
