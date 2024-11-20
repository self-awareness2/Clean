///******************************************************************
//
// Moudle Name  :   mtn_lib20_ext.h
// Abstract     :   GaoChuan Motion 2.0 external user header 
// Note :			1.�ṹ�嶨�������еġ�reservedxxx���ĳ�Ա���Ǳ�������,Ϊ���ּ�����,������Ϊ0
//					2.���ر�˵��,����API����RTN_CMD_SUCCESS����0ֵ����ʾִ�гɹ�,�������ʾ�������
//					3.���е�API������,���ر�˵��,axisHandle��ʾ������ľ��,devHandle��ʾĿ��������ľ��,crdHandle��ʾĿ������ϵ����
//                  4.mtn_lib20�����еĽṹ�嶼�������ֽڶ��뷽ʽ���룬Ϊ�˱���ṹ�������������⣬�뽫���뻷������Ϊ���ֽڶ���
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
//           ָ���������
//
//------------------------------------------------------------------------------------------------------------
//	1.�豸�߼����õ�
//	2.�������ö�ȡ
//	3.����߼�ָ��
//	4.�������߼�ָ��
//	5.Ӳ�����񼰲�����ָ��
//	6.ƽ̨���ָ��
//	7.���ݲɼ�ģ��(�߼�ָ��)
//	8.����
//	9.����
//  10.ͨѶ��չ������
//  11.����
//  12.PT
//  13.���Ծ���λ�ñȽ�
//  14.��άλ�õ�Ƚ�
//  15.��άλ�ñȽ����
//  16.����ϵ���ת��
//  17.�ṹ���ʼ������������ϰ��ָ��
//  18.�ջ�
//  19.�߼�BufIo������ü�����
//  20.ģ��������
//  21.scara
//  22.����ϵ���汣��ָ��
//  23.������ָ��
//  24.�Զ�״̬����
//  25 : ��λ�Զ��շ�
//  26 : ����һάλ�ñȽ�
//  27 ����count��clock
//  28.PVT
///////////////////////////////////////////////////////////////////ָ��
//------------------------------------------------------------------------------------------------------------
//
//	1.�豸�߼����õ�
//
//------------------------------------------------------------------------------------------------------------

// ����ͨѶ����
// devHandle : �豸���
// waitTimeInUs���ȴ�ʱ��,΢��
// retryTimes�� ͨѶ���Դ���
MTN_API short __stdcall NMC_SetCommPara( HAND devHandle, unsigned long waitTimeInUs, unsigned long retryTimes );

// �忨�򿪣��������ƣ�
// idStr: �忨ID�ַ���, ��ͨ��ָ��д�롣pDevHandle: �����豸�������
// ע��ID���û���д��,���粻��ʧ,���������ְ忨�������忨��ID��Ϊ0
MTN_API short __stdcall NMC_DevOpenByID   ( char *idStr, PHAND pDevHandle );

// �忨�򿪣�����IP��ַ��
// pIPv4Array: �忨IP��ַ,�ĸ��ֽ�,���磺unsinged char ipv4[4] = {192,168,1,110};
// pDevHandle: �����豸�������
MTN_API short __stdcall NMC_DevOpenByIP   (unsigned char *pIPv4Array, PHAND pDevHandle );

// �޸İ忨ID��
// pIdStr: Ҫд��İ忨ID�ַ���,�16�ֽ�,��\0��β
// ע���޸�ID����ɺ�,�忨Ҫ��������,�µ�ID����Ч��
MTN_API short __stdcall NMC_DevWriteID   ( HAND devHandle, char *pIdStr );

// ��ȡ�忨ID��
// pIdStr: �洢�ַ���������,���鳤�ȴ���16�ֽ�
MTN_API short __stdcall NMC_DevReadID(HAND devHandle, char *pIdStr );

// ��ȡ��İ汾
// pVersion�����հ汾��Ϣ
// example(c):
//          char dllVersion[128];
//          NMC_GetDllVersion(dllVersion);
MTN_API short  __stdcall NMC_GetDllVersion(char *pVersion);

// ��ǰ�˶��������̼��İ汾����Ϣ
typedef struct
{
	char strVer[16];
	char strOemVer[16];
	char strBuild[32];
}TMtLibVersion;
// ��ȡ��ǰ�˶��������̼��İ汾����Ϣ
// devHandle : �豸���
// pVersion���汾��Ϣ
MTN_API short __stdcall NMC_GetMtLibVersion ( HAND devHandle, TMtLibVersion *pVersion );

typedef struct
{
	char strVer[16];           // �������汾��
	char strOemVer[16];        // OEM�汾��(���ƿ���������),Ĭ��Ϊ0
	short time[6];          // ʱ��,������,ʱ����
	short axisNum;          // ֧�ֵ�����
	short encNum;           // ֧�ֵı�������
	short diNum;            // ������������
	short doNum;            // �����������
	short daNum;            // ģ����ͨ��
	short adNum;            // ģ��������ͨ��
	short shioNum;          // ͬ������IOͨ��
    short reserved;         // ����
	char ipv4[4];           // IP��ַ
	char idStr[16];         // �忨����,�࿨ʱ�������ƴ򿪲ο�NMC_DevOpenByID
	unsigned long uid[4];   // Ψһ���к�
}TCardInfo;
// ��ȡ��ǰ�˶���������Ϣ
MTN_API short __stdcall NMC_GetCardInfo ( HAND devHandle, TCardInfo *pInfo );

typedef struct
{
	char strVer[16];           // �������汾��
	char strOemVer[16];        // OEM�汾��(���ƿ���������),Ĭ��Ϊ0
	short time[6];          // ʱ��,������,ʱ����
	short axisNum;          // ֧�ֵ�����
	short encNum;           // ֧�ֵı�������
	short diNum;            // ������������
	short doNum;            // �����������
	short daNum;            // ģ����ͨ��
	short adNum;            // ģ��������ͨ��
	short shioNum;          // ͬ������IOͨ��
	short reserved;         // ����
	unsigned char ipv4[4];  // IP��ַ
	char idStr[16];         // �忨����,�࿨ʱ�������ƴ򿪲ο�NMC_DevOpenByID
	unsigned long uid[4];   // Ψһ���к�
	char macAddr[6];		// ����mac��ַ
	char resv[256];
}TCardInfoEx;

// ��ȡ��ǰ�˶���������Ϣ
MTN_API short __stdcall NMC_GetCardInfoEx ( HAND devHandle, TCardInfoEx *pInfo );

// ����ָ�����
// enable:0�رյ�����Ϣ,Ĭ�Ϲر�,1:��ͨѶ��debug�����2:��ӡ���ļ���3����ӡ�����GCS
// debugOutputFile:��������ļ�������enable=2ʱ��Ҫ
MTN_API short  __stdcall NMC_SetCmdDebug( short enable,char *debugOutputFile);

// ��ȡ���������Ϣ
// errCode:�������
// errDesc:���صĴ����������
MTN_API short  __stdcall NMC_GetErrDesc( short errCode,char *errDesc);

// ���������ļ�
MTN_API short __stdcall NMC_LoadConfigFromFile(HAND devHandle, char *pFilePath);

// ����Ϊ�����ļ�
MTN_API short __stdcall NMC_SaveConfigToFile(HAND devHandle, char *pFilePath);

// ���������������Ϣ,����Щ��Ϣ���浽ϵͳ������,��������������NMC_DevReset��,ϵͳ��ʹ����Щ����
// ����Ĳ���������������λ�����巽ʽ����������ʽ����ȫ�������˲�����
// enable:1��ʾ���浱ǰ����,��ʹ���Զ����ز�������,0����ʾ�ر��Զ����ز�������
MTN_API short __stdcall NMC_SaveMotionConfig(HAND devHandle,short enable);

// ��ȡƽ̨�汾��
MTN_API short  __stdcall NMC_GetVersion( HAND devHandle, unsigned char *verArray );

// ��ȡ������������Ϣ example : char flags[1024];NMC_DevGetMcInfoFlag(g_hDev,flags);
MTN_API short __stdcall NMC_DevGetMcInfoFlag(HAND devHandle,char *flags);

// ������״̬
#define BIT_DEV_TERMINALBOARD_ONLINE			(0x00000001)		// bit 0  , ���Ӱ�ͨѶ״̬��PCIe������1������:,0������    
#define BIT_DEV_TERMINALBOARD_POWER				(0x00000002)		// bit 1  , ���Ӱ幩���Ƿ�������PCIe������1������:,0������    

// ��ȡ������״̬����λ��ʾ
MTN_API short  __stdcall NMC_DevGetSts(HAND devHandle,  long *sts);

//------------------------------------------------------------------------------------------------------------
//
//	2.�������ö�д
//
//------------------------------------------------------------------------------------------------------------
// ��ȡ��滮ģʽ
// pMode���������˶�ģʽ
MTN_API short __stdcall NMC_MtGetPrfMode(HAND axisHandle,short *pMode);

// ��ȡPtp����
// pAxPara������
MTN_API short __stdcall NMC_MtGetPtpPara( HAND axisHandle, TPtpPara *pAxPara );

// ��ȡJog����
// pAxPara������
MTN_API short __stdcall NMC_MtGetJogPara   ( HAND axisHandle, TJogPara *pAxPara );

// ��ȡĿ���˶��ٶ�
// pVel: Ŀ���ٶȣ�����ٶȣ�,��λ�� ����/ms
MTN_API short __stdcall NMC_MtGetVel( HAND axisHandle, double *pVel );

// ��ȡĿ���˶�λ��,ֻ���PTP
// pPos: Ŀ��λ��,��λ�� ����
MTN_API short __stdcall NMC_MtGetPtpTgtPos( HAND axisHandle, long *pPos );

// ��������ͨ��λ��
// devHandle : ���������
// encId: ������ID,ȡֵ��Χ[0,n]
// pPos:���ر�������ֵ
MTN_API short  __stdcall NMC_GetEncPos( HAND devHandle, short encId, long *pPos );

// д������ͨ��λ��
// devHandle : ���������
// encId: ������ID,�����������ͨ��,ȡֵ��Χ[0,n]
//				  ������չ������ͨ��,256��ʾ��һ����չ������ͨ��,257��ʾ�ڶ���,�Դ�����
// encPos:��������ֵ
MTN_API short  __stdcall NMC_SetEncPos( HAND devHandle, short encId, long encPos );

// ���������λ�����,��λ�������趨ֵʱ,���ֹͣ�˶�,��ʾλ������
// posErrΪ0��ʾ�����
MTN_API short  __stdcall NMC_MtSetPosErrLmt( HAND axisHandle, long posErr );

// ��ȡ�����λ������趨ֵ
MTN_API short  __stdcall NMC_MtGetPosErrLmt( HAND axisHandle, long *pPosErr );

// ��ȡ������ģʽ
// encId: ������ID,�����������ͨ��,ȡֵ��Χ[0,n]
//				  ������չ������ͨ��,256��ʾ��һ����չ������ͨ��,257��ʾ�ڶ���,�Դ�����
// encMode:���ر�����ģʽ,�ο��궨��
MTN_API short  __stdcall NMC_GetEncMode (HAND devHandle, short encId,  short *encMode );

// ��ȡ��λ���������Ƿ�ֹͣ�˶�
// posEn��������λ������������,1Ϊ����,0Ϊ��ֹ
// negEn: ������λ������������
MTN_API short  __stdcall NMC_MtGetLmtOnOff    ( HAND axisHandle, short *pPosSwt, short *pNegSwt );

// ��ȡ��λ���ش�����ƽ
// posSwt��������λ������ƽ����,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
// negSwt: ������λ������ƽ����
MTN_API short  __stdcall NMC_MtGetLmtSns      ( HAND axisHandle, short *pPosSwt, short *pNegSwt );

// ��ȡ�ŷ����������Ƿ�ֹͣ�˶�
// swt���ŷ���������������������,1Ϊ����,0Ϊ��ֹ����Ĭ��Ϊ�ߵ�ƽ������
MTN_API short  __stdcall NMC_MtGetAlarmOnOff  ( HAND axisHandle, short *pSwt );

// ��ȡ�ŷ��������ص�ƽ
// swt���ŷ�����������ƽ����,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
MTN_API short  __stdcall NMC_MtGetAlarmSns    ( HAND axisHandle, short *pSwt );

// ��ȡ�����λ�Ƿ�ֹͣ�˶�
// enable�������λ������������,1Ϊ����,0Ϊ��ֹ
MTN_API short  __stdcall NMC_MtGetSwLmtOnOff  ( HAND axisHandle, short *pSwt );

// ��ȡ�����λ��ֵ
// posLmt�����������λ����ֵ
// negLmt�����������λ����ֵ����λΪ������
MTN_API short  __stdcall NMC_MtGetSwLmtValue  ( HAND axisHandle, long *pPosLmt,long *pNegLmt );

//  ��ȡ�ᰲȫ����
MTN_API short  __stdcall NMC_MtGetSafePara( HAND axisHandle, TSafePara *pPara );

// ��ȡ�������ģʽ
// pInv, 1��ȡ��,0����ȡ��
// pMode 0�����巽�� 1����������
MTN_API short  __stdcall NMC_MtGetStepMode ( HAND axisHandle, short *pInv, short *pMode );

// ��ȡ���ٶ��˲�����
MTN_API short __stdcall NMC_MtGetAxisVelFilter(HAND axisHandle,short *pFilterCoef);

// ��ȡ�������
// pHomePara: ��������ṹ,�ο��ṹ����
MTN_API short __stdcall NMC_MtGetHomePara( HAND axisHandle, THomeSetting *pHomePara );

//------------------------------------------------------------------------------------------------------------
//
//	3.����߼�ָ��
//
//------------------------------------------------------------------------------------------------------------

// ��ȡ��е�����λ��
// pPos : ����λ��,��λ�� ����
MTN_API short __stdcall NMC_MtGetAxisPos   ( HAND axisHandle, long *pPos );

// �����͵�ִ������λ��
// pPos : ����λ��,��λ�� ����
MTN_API short __stdcall NMC_MtGetCmdPos   ( HAND axisHandle, long *pPos );

// �趨��еλ��, �ᾲֹʱִ��,���������updateָ��,��Ҫ��ʱһ������
// axisPos: �趨��еλ��ֵ
// ע��ֻ�����ᾲֹʱʹ��
MTN_API short  __stdcall NMC_MtSetAxisPos( HAND axisHandle, long axisPos);

// �趨������λ��, �ᾲֹʱִ��,���������updateָ��,��Ҫ��ʱһ������
// encPos: �趨������λ��ֵ
// ע��ֻ�����ᾲֹʱʹ��
MTN_API short  __stdcall NMC_MtSetEncPos( HAND axisHandle, long encPos);

// ���õ���滮�߼�����
// axisHandle : ����
// mapAxisNo�����,ȡֵ��Χ[0,n]
// port���˿ں�,ȡֵ��Χ[0,1],Ĭ��Ϊ0
// startPos��ƫ��,Ĭ��Ϊ0
// pCrdHandle������ϵ����
MTN_API short __stdcall NMC_MtPrfConfig(HAND axisHandle,short mapAxisNo,short port,long startPos);

// ��ȡ����滮�߼�����
MTN_API short __stdcall NMC_MtGetPrfConfig(HAND axisHandle,short *mapAxisNo,short *port,long *startPos);

// ���õ������ϵ��
// axisHandle : ����
// inCoe���������ϵ��,ȡֵ��Χ(0,1]
MTN_API short __stdcall NMC_MtSetPrfCoe(HAND axisHandle,double inCoe);

// ��ȡ�������ϵ��
// axisHandle : ����
// pInCoe���������ϵ��,ȡֵ��Χ(0,1]
MTN_API short __stdcall NMC_MtGetPrfCoe(HAND axisHandle,double *pInCoe);

// ������ͨ����������ϵ��,Ĭ��Ϊ1
// axisHandle : ����
// encCoe������ͨ������������ϵ��,ȡֵ��Χ(0,1]
MTN_API short __stdcall NMC_MtSetEncCoe(HAND axisHandle,double encCoe);

// ��ȡ��ͨ����������ϵ��
// axisHandle : ����
// pEncCoe������ϵ��,ȡֵ��Χ(0,1]
MTN_API short __stdcall NMC_MtGetEncCoe(HAND axisHandle,double *pEncCoe);

// ������ĵ�λ������
// axisHandle : ����
// arrivalBand: ��λ���,��λPulse ȡֵ����0
// stableTime: ��λ����ʱ��,��λ ms ȡֵ����0
MTN_API short __stdcall NMC_MtSetAxisArrivalPara(HAND axisHandle,long arrivalBand,long stableTime);

// ��ȡ��ĵ�λ������
// axisHandle : ����
// pArrivalBand:��λ���,��λPulse 
// pStableTime����λ����ʱ��,��λ ms
MTN_API short __stdcall NMC_MtGetAxisArrivalPara(HAND axisHandle,long *pArrivalBand,long *pStableTime);

// �����ݾ���������
// num�������Ķ���,ȡֵ��Χ[2,128]
// startPos��������ʼλ�ã���ֹλ��Ϊ startPos + cmpLen
// cmpLen:��������
// pCompPos:���򲹳�ֵ
// pCompNeg:���򲹳�ֵ
MTN_API short  __stdcall NMC_MtSetLeadScrewCompPara(HAND axisHandle,short num,
						long startPos,long cmpLen,short *pCompPos,short *pCompNeg);

// ʹ�ܻ��ֹ�ݾ�λ�ò���
MTN_API short __stdcall NMC_MtEnableLeadScrew(HAND axisHandle, short enable);

// ���÷����϶����
// compValue�� ������
// compDelta�� ���ڲ����������粹����Ϊ100�����ڲ�����Ϊ10�����򲹳�����10���滮�������100������Ĳ���
// compDir��	 ��������,0:���򲹳����������˶�ʱ���Ӳ�������1�����򲹳����������˶�ʱ���Ӳ�����
MTN_API short  __stdcall NMC_MtSetBacklash(HAND axisHandle, long compValue,double compDelta,long compDir);

// ��ȡ�����϶����
MTN_API short  __stdcall NMC_MtGetBacklash(HAND axisHandle,long *pCompValue,double *pCompDelta,long *pCompDir);

// ���õ��ἱͣDI
// gpiIndex��ͨ���������,[0,]������Ϊ-1�����ʾȡ����ͣDI
// sense :������ƽ,0���͵�ƽ,1���ߵ�ƽ
MTN_API short __stdcall NMC_MtSetEstopDI( HAND axisHandle, short gpiIndex,short sense);

// ��ȡ���ἱͣDI
// gpiIndex��ͨ���������,[0,]
// sense :������ƽ,0���͵�ƽ,1���ߵ�ƽ
MTN_API short __stdcall NMC_MtGetEstopDI( HAND axisHandle, short *gpiIndex,short *sense);

// ���õ��ἱͣDI Mask,�������ö����ͣDI
// gpiMask��ͨ�������λ����
// senseMask :������ƽ��λ���룬��Ӧλ,0���͵�ƽ,1���ߵ�ƽ
MTN_API short __stdcall NMC_MtSetEstopDIMask( HAND axisHandle, long gpiMask,long senseMask);

// ���õ��ἱͣDI Mask,�������ö����ͣDI
// gpiMask��ͨ�������λ����
// senseMask :������ƽ��λ���룬��Ӧλ,0���͵�ƽ,1���ߵ�ƽ
MTN_API short __stdcall NMC_MtGetEstopDIMask( HAND axisHandle, long *pGpiMask,long *pSenseMask);

// �߼���ͣ
#define ESTOP_DI_EX_CH_NUM				2   // �߼���ͣ���ͨ������

typedef struct
{
	short axMask;			// ������
	short diType;			// DI���ͣ�0-ͨ�����룬1-����λ��2-����λ��3-ԭ�㣬4-Z��
	short diIndex;			// ͨ�����,[0,]
	short filter;			// �˲�ϵ��,ȡֵ��Χ[0,255]
	long diSense;			// ������ƽ,0���͵�ƽ,1���ߵ�ƽ
	long reserved[3];		// ����
}TEstopExParam;

// ���õ��ἱͣDI,�����������BIT_AXIS_ESTP��־λ
// ע��:����߼���ͣ�����󣬹滮λ����ʵ��λ�ÿ��ܴ��ڲ�ֵ
// pParam:�߼���ͣ����
// group:ͨ���ţ�ȡֵ[0,ESTOP_DI_EX_CH_NUM-1]
MTN_API short __stdcall NMC_SetEstopDIEx( HAND devHandle, TEstopExParam *pParam,short group);

// ��ȡ���ἱͣDI
MTN_API short __stdcall NMC_GetEstopDIEx( HAND devHandle, TEstopExParam *pParam,short group);

// �������߼���ͣIO�����ر�
// onOff:1-���ø߼���ͣIO��0-�رո߼���ͣIO
// group:ͨ���ţ�ȡֵ[0,ESTOP_DI_EX_CH_NUM-1]
MTN_API short __stdcall NMC_CrdBufEstopDIExOnOff( HAND crdHandle, long segNo,short onOff,short group);

// ����߼����ἱͣDI
MTN_API short __stdcall NMC_ClrEstopDIEx( HAND devHandle,short group);

// �߼�����ͨ����Ŀ
#define CAPT_EX_CH_NUM				6   // 

// ����Դ
#define CAPT_EX_SRC_GPI				0   // ͨ������
#define CAPT_EX_SRC_NEGLMT          1   // ������λ
#define CAPT_EX_SRC_POSLMT          2   // ������λ
#define CAPT_EX_SRC_HOME			3   // ԭ��
#define CAPT_EX_SRC_Z				4   // Z���ź�
#define CAPT_EX_SRC_PRFPOS          5   // �滮λ�ã����滮λ�ôﵽ�趨ֵʱ������
#define CAPT_EX_SRC_ENCPOS          6   // ������λ��

typedef struct
{
	short capPosIndex;	// �����λ��Դ���,0~N����1~N+1����Ĭ��0��ע������ı�����λ�ø����û����õı�����ģʽ���� 
	
	short trigSrc;		// ����Դ,������Ķ��塣��Ĭ�ϣ�CAPT_EX_SRC_GPI��
	short trigIndex;	// ����Դ��š���Ĭ��0��
	short filter;		// �˲�ʱ�䳣��,��λ0.1����,ȡֵ��Χ[0,255]
	long  trigValue;	// ����ֵ,���ڴ���ԴΪIO,��ʾ�źŴ�������Ч��ƽ�����ڴ���ԴΪλ��,���ʾ���������λ�á���Ĭ��0��
}TAdvCaptureParam;

// ���ø߼��������,����������
// pParam:����
// ch���߼�����ͨ����,[0~3]
MTN_API short __stdcall NMC_MtSetAdvCaptParam( HAND devHandle, TAdvCaptureParam *pParam,short ch);

// ����߼�����״̬,��ȡ����ͨ���Ĳ���
// ch���߼�����ͨ����,[0~3]
MTN_API short __stdcall NMC_MtClrAdvCaptSts( HAND devHandle,short ch);

// ��ȡ�߼�����״̬
// captSts:����״̬,bit0��ʾ���õ��ź�ǰ�ش�����,bit1��ʾ�źŵĺ��ش�������
// pPosArray : ����λ��,�ڴ�����ʱ,λ��Ϊ���񵽵�λ��ֵ��
//				pPosArray[0]:�ź�ǰ�ش���λ��,pPosArray[1]:�źź��ش���λ��,��λ:����
MTN_API short  __stdcall NMC_MtGetAdvCaptPos( HAND devHandle, short *captSts,long *pPosArray ,short ch);

// �����Ჹ������
// enable: 0:ȡ�� 1��ʹ��
// para1: ����1����ֵ��Χ�ڣ�10~500��,�����ȴӴ�С�������ò���
// para2: ����2����ֵΪ����Ƶ��HZ
MTN_API short  __stdcall  NMC_MtSetAxisDampCompParam(HAND axisHandle,short enable,short param1,short param2);

// ����Խ�ޱ����Ķ���
// actionsBits:��Խ�ޱ�����Ĵ���������λ��ʾ��Ĭ��Ϊ0����ֻ�����ᳬ�ޱ�־λ
//		bit0:�ر�ʹ��
//		bit1:ֹͣ���˶�
//		��������
MTN_API short  __stdcall NMC_MtSetPosErrAction( HAND axisHandle,short actionsBits);

// ��ȡԽ�ޱ����Ķ���
MTN_API short  __stdcall NMC_MtGetPosErrAction( HAND axisHandle,short *pActionsBits);

//------------------------------------------------------------------------------------------------------------
//
//	4.�������߼�ָ��
//
//------------------------------------------------------------------------------------------------------------

// ����ϵ�˶�����չ����
typedef struct
{
	double startVel;					//�����ٶȣ�Ĭ��0��
	double T;							//ǰհʱ�䳣��,Խ�����ٶȱ仯ԽС (Ĭ��1)
	double smoothDec;					//ֹͣ���ٶȣ�Ĭ��accMax��
	double abruptDec;					//��ͣ���ٶȣ�Ĭ�������
	short  lookAheadSwitch;				//ǰհ��������( Ĭ��Ϊ1����ʾǰհ��)
	short eventTime;					// ��С�����ٶ�ʱ��,��λms,(Ĭ��Ϊ10)
	short reserved[2];
}TExtCrdPara;

// ��������ϵ��չ���� 
// extCrdPara:����ϵ��չ����,�ο�����ϵ�˶�����չ������TExtCrdPara�ṹ�嶨��
MTN_API short __stdcall NMC_CrdSetExtPara( HAND crdHandle, TExtCrdPara *extCrdPara);

typedef struct
{
	short lookAheadSwitch;			// ǰհ���ܿ��ƣ�0:����Ҫǰհ��1:ʹ����λ��ǰհ��[2,n]��ʹ����λ��ǰհ����ֵΪǰհ�����������
	short centAccEn;				// �Ƿ�ʹ��ָ�������ļ��ٶȣ�Ĭ��Ϊ0������ʹ��
	short crossEn;					// ���߶κϲ�����,0:�رպϲ���1�����úϲ�
	short eventTime;				// ��С�����ٶ�ʱ��,��λms,(Ĭ��Ϊ10)

	double accMax;					// ��̨����������ٶ�,Ĭ��1000
	double T;						// ǰհʱ�䳣��,Խ�����ٶȱ仯ԽС (Ĭ��1)
	double slowAng;					// ���ٽǶ�,С���趨�Ƕȣ��򲻼���
	double stopAng;					// ֹͣ�Ƕȣ������趨�Ƕȣ������Ϊ0
	double crossProp;				// ���߶κϲ����ȣ�ȡֵ��Χ(0,n],��ֵԽ����ϲ�Խ����	
	double centAcc;					// ���ļ��ٶ�
	double dvMax[CRD_MAX_DIMENSION];// ����������ٶȱ仯��

	short preHandleEn;				// �켣Ԥ�����ܿ���
	short reserved;					// ��������
	float preHandleDisAngMin;		// �켣Ԥ������С�Ƕȣ��������
	float preHandleDisAngMax;		// �켣Ԥ�������Ƕ�
	float preHandleTol;				// Ԥ��������λ:����

}TLookaheadPara;

// ����ǰհ����
// lkhPara:ǰհ��صĲ���
MTN_API short __stdcall NMC_CrdSetLookaheadPara( HAND crdHandle, TLookaheadPara *lkhPara);

// ��ȡǰհ����
// lkhPara:ǰհ��صĲ���
// defaultFlag:1��ʾ��ȡĬ��ֵ��0��ʾ��ȡ��ǰֵ
MTN_API short __stdcall NMC_CrdGetLookaheadPara( HAND crdHandle, TLookaheadPara *lkhPara,short defaultFlag);

// ��������ϵ�˶��������Ƿ�����,NMC_CrdConfig��Ĭ��Ϊ����״̬
// enFlag:����,1������,0��������
// ע�⣺�������ʹ������ϵ�˶�������,����NMC_CrdConfig֮����ø�ָ��
MTN_API short __stdcall NMC_EnableCrdSdram( HAND crdHandle, short enFlag);

// ��ȡ����ϵ��չ����
// extCrdPara:����ϵ��չ����
MTN_API short __stdcall NMC_CrdGetExtPara( HAND crdHandle, TExtCrdPara *extCrdPara);
 
// ����ϵ�˶���Բ���岹����
#define MAX_ERR_TABLE_SECTION	2
typedef struct
{
	double minSectionLen;				// �ֽ����С�γ�,Ĭ��1����,��Χ[1,10000]
	double maxArcDiff;					// ����Բ����Ч�����,��λ������
		
	// Բ���岹������ñ�
	// ע�⣺MTNͨ������Բ���岹�ٶ�,�Ӷ���֤�岹��rȫ��Ϊ0,���ʾ�ر��������
	double r[MAX_ERR_TABLE_SECTION];	// �뾶
	double err[MAX_ERR_TABLE_SECTION+1];	// �뾶��Ӧ�Ĳ岹���,�뾶 [0,r0],��Ӧerr0;�뾶[r0,r1],��Ӧerr1;�뾶[r1,+max],��Ӧerr2

}TArcSecSetting;
// ����Բ���岹�������߼�ָ�
// pSetting : ����
MTN_API short __stdcall NMC_CrdSetArcSecPara( HAND crdHandle,  TArcSecSetting *pSetting);
                                          
// ��Բ���岹�������߼�ָ�
MTN_API short __stdcall NMC_CrdGetArcSecPara( HAND crdHandle,  TArcSecSetting *pSetting);

// ����ϵ�˶�����
typedef struct
{
	short orgFlag;		// �Ƿ��Զ�������ϵԭ��
	short reserved[3];		// ����
	long offset[4];		// �Զ�������ϵԭ��ƫ�ã����ڻ�еԭ�㣩
	double synAccMax;	// ���ϳɼ��ٶ�
	double synVelMax;	// ���ϳ��ٶ�
}TCrdPara;
// ��������ϵ����(����)
// pCrdPara:����ϵ����
MTN_API short __stdcall NMC_CrdSetPara( HAND crdHandle, TCrdPara *pCrdPara );

// ��ȡ�岹����ϵϵͳ������Ϣ
// pConfig:��������ϵ����,�ο��ṹ�嶨��
MTN_API short __stdcall NMC_CrdGetConfig( HAND crdHandle, TCrdConfig *pConfig );

// ��ȡ����ϵ����
// pCrdPara:����ϵ����
MTN_API short __stdcall NMC_CrdGetPara( HAND crdHandle, TCrdPara *pCrdPara );

// ��ȡ����ϵ�ٶȱ���
// overRide������ϵ�ٶȱ���
MTN_API short __stdcall NMC_CrdGetOverRide( HAND crdHandle, double *pOverRide );

// ����ϵ״̬��λ����:�ڲ���չ 
#define BIT_CORD_POSREC         (0x00000040)    // bit 6 , �ŷ�λ�õ���,����ģʽʱλ�õ���,�ŷ�ģʽʱʵ��λ�õ��������    
#define BIT_CORD_AUXAXIS_BUSY   (0x00000080)    // bit 7 , ����ϵ�˶��еĹ���������ǰ�����˶�״̬����
#define BIT_CORD_AUXAXIS_ERR    (0x00000100)    // bit 8 , �岹���������             
#define BIT_CORD_AXIS_ERR       (0x00000200)    // bit 9 , �岹����ڱ�����������λ������������   
#define BIT_CORD_SDRAM_CALC_ERR (0x00000400)    // bit 10 , SDRAM�������������  
#define BIT_CORD_SCARA_CALC_ERR (0x00000800)    // bit 11 , SCARA�������ݴ���
// ��ȡ�ڲ�����ϵ״̬
// pStsWord������״̬��,����64bits(��ά��long����),���ں�����չ״̬λ
MTN_API short __stdcall NMC_CrdGetInnerSts     ( HAND crdHandle, long *pStsWord );

// ֱ���޸�����ϵƫ��
// pOffsetArray:����ϵƫ��
// cnt:���鳤��
MTN_API short __stdcall NMC_CrdModifyOffset( HAND crdHandle, long *pOffsetArray, short cnt);

// ���������ü�ͣDI
// axis:���,ȡֵ��Χ[0,n)
// gpiIndex:ͨ���������
// sense:������ƽ
MTN_API short  __stdcall NMC_CrdBufSetEstopDI ( HAND crdHandle,long segNo,short axis,short gpiIndex,short sense);

// ���������ݴ��
#define BUF_LINE	0 //������ֱ�߲岹
#define BUF_DO		1 //������DO���
#define BUF_OUT		2 //������OUT���
#define BUF_DELAY   3 //��������ʱ
#define BUF_AXMOVE	4 //�����������˶�
#define BUF_DOEX    5 //������DO������������������
#define BUF_ARC_R   6 //ƽ��Բ���岹���յ�λ�á��뾶������
#define BUF_ARC_C   7 //ƽ��Բ���岹���յ�λ�á�Բ�ġ�����
#define BUF_LASER_SETPOWER		8	// ���⣺��������
#define BUF_LASER_ONOFF			9	// ���⣺���������ع�
#define BUF_LASER_SETFOLLOW		10	// ���⣺���ø���
#define BUF_LASER_SETPARAM		11	// ���⣺���ò���
#define BUF_LINEXYZA			12	// ����������ֱ�߲岹
#define BUF_SHIO_GATEPULSE		13	// ���������Gate����
#define BUF_DOBITPULSE			14	// DoBitPulse����
#define BUF_XYZD8          		15	// LineXYZD8,���ݽṹ��Ϊ��TCrdLineXYZD8Unit
#define BUF_SHIOMINFRQ     		16	// ���û����SHIO��СƵ��
#define BUF_SHIOSETPARAM        17	// ����SHIO����
#define BUF_SHIOGATEONOFF       18	// ����Gate����
#define BUF_WAITENCINPOS        19	// �ȴ������λ
#define BUF_WAITDI              20	// �ȴ�DI

#pragma pack(push)
#pragma pack(4)
typedef struct
{  
	long segNo;        // �û��Զ���κ�
	long tgPos[3];     // Ŀ��λ��
	double endVel;     // �յ��ٶ�
	double vel;        // ����ٶ�
	double synAcc;     // �岹���ٶ�
	short mask;        // crdAxMask,����Ĳ岹��,��λ��ʾ
	short lookaheadDis;//�Ƿ�ʹ��ǰհ
    long  reserved;     // ����
}TCrdBufLine;

typedef struct
{  
	long tgPos[4];     // Ŀ��λ��
	double endVel;     // �յ��ٶ�
	double vel;        // ����ٶ�
	double synAcc;     // �岹���ٶ�
	long segNo;        // �û��Զ���κ�
	short mask;        // crdAxMask,����Ĳ岹��,��λ��ʾ
	short lookaheadDis;//�Ƿ�ʹ��ǰհ
}TCrdBufLineXYZA;

typedef struct
{
	long segNo;     // �û��Զ���κ�
	short group;    // Out������� 
	short ch;       // ͨ����,ȡֵ��Χ[0,n]
	long outValue;	// ���
}TCrdBufOut;

typedef struct
{
	long segNo;     // �û��Զ���κ�
	short group;    // ���������DO�� 
	short ch;       // λ���,ȡֵ��Χ[0,31]
	long value;     // ���ֵ,ȡֵ��Χ[0,1]
}TCrdBufDO;

typedef struct
{
	long segNo;     // �û��Զ���κ�
	long scale;     // ��ʱ��λ,0��ʾ��λΪ����,1��ʾ��λΪ��
	long count;     // ��ʱʱ��
}TCrdBufDelay;

typedef struct
{
	long segNo;     // �û��Զ���κ�
	long group;    // ���������DO��
	long doMask;    // �������λ,bitλΪ1��ʾҪ���
	long value;     // ���ֵ,bitλָʾ���ֵ
}TCrdBufDOEx;

typedef struct
{
	long segNo;         // �û��Զ���κ�
	short axis;		    // �����ƶ������ [0,n],������ϵ����	
	short soomthCoef;   // smoothCoef:ƽ��ϵ��
	short blockEn;      // �Ƿ�Ϊ����ģʽ 0 ������ ,1 ����
	short synEn;        // �Ƿ�Ϊͬ��ģʽ 0 �첽 ,1 ͬ��
    long  tgPos;	    // Ŀ��λ��
	double vel;         // �˶��ٶ�
	double acc;         // �˶����ٶ�
}TCrdBufAxMove;

typedef struct
{
	long segNo;         // �û��Զ���κ�
	long tgPos[2];		// Ŀ��λ��
	short circleDir;    // �Ƿ�Ϊͬ��ģʽ 0 �첽 ,1 ͬ��
	char lookaheadDis;	// �Ƿ�ʹ��ǰհ
	char panelIndex;	// Բ���岹ƽ�棺0��XYƽ�棬1��YZƽ�棬������ZXƽ��
	double radius;		// �뾶
	double endVel;      // �յ��ٶ�
	double vel;         // �˶��ٶ�
	double acc;         // �˶����ٶ�
}TCrdBufArcR;

typedef struct
{
	long segNo;         // �û��Զ���κ�
	long tgPos[2];		// Ŀ��λ��
	long centerPos[2];	// Ŀ��λ��
	short circleDir;    // �Ƿ�Ϊͬ��ģʽ 0 �첽 ,1 ͬ��
	char lookaheadDis;	// �Ƿ�ʹ��ǰհ
	char panelIndex;	// Բ���岹ƽ�棺0��XYƽ�棬1��YZƽ�棬������ZXƽ��
	double endVel;      // �յ��ٶ�
	double vel;         // �˶��ٶ�
	double acc;         // �˶����ٶ�
}TCrdBufArcC;
 
typedef struct
{  
	long segNo;        // �û��Զ���κ�
	long onDelay;     // ������ʱ
	long offDelay;     // �ع���ʱ
	long minValue;     // ��С���ֵ
	long maxValue;     // ������ֵ
	long standbyPower;	// ��������
	short ch;			// �������ͨ��
	short reserved;		// ����
}TCrdBufLaserSetParam;

typedef struct
{  
	long segNo;        // �û��Զ���κ�
	short followType;    // ��������
	short ch;			// ����ͨ����
	double overRide;     // ���汶��
}TCrdBufLaserSetFollow;

typedef struct
{  
	long segNo;        // �û��Զ���κ�
	short onOff;		// ����,0���ع�,1������
	short ch;			// ����ͨ����
}TCrdBufLaserOnOff;

typedef struct
{  
	long segNo;        // �û��Զ���κ�
	short ch;			// ����ͨ����
	short reserved;		// ����
	double power;		// ����
}TCrdBufLaserSetPower;

typedef struct
{  
	long segNo;        // �û��Զ���κ�
	long outCount;		// �������
	double gateTime;	// gate�����������λ��΢��
	double gateFrq;		// gate�����Ƶ�ʣ���λ��HZ
	short ch;			// ch:ͨ��
    short reserved[3];  // ����
}TCrdBufSHIOGatePulse;


typedef struct
{  
	long segNo;			// �û��Զ���κ�
	long highLevelTime;	// �ߵ�ƽ��ȣ���λ:us
	long lowLevelTime;	// �͵�ƽ��ȣ���λ:us
	long outCount;		// ����������
	long initialLevel;	// 0��������͵�ƽ��1��������ߵ�ƽ
	short ch;			// ch:ͨ��
	short enable;		// 1:ʹ��,0:�ر�
	short doType;		// DO����,Ĭ��CRD_BUFF_DO_GPDO1
	short doIndex;		// DO��ţ�ȡֵ��Χ[0,n]
}TCrdBufDoBitPulse;

typedef struct
{  
	long segNo;			// �û��Զ���κ�
    long minFrq;        // ��СƵ�ʣ�����enable=1ʱ��Ч
	short ch;			// ͨ��
	short setOrClr;		// 1:����,0:���
}TCrdBufSHIOMinFrq;

typedef struct
{  
	long segNo;			// �û��Զ���κ�
	short ch;			// ͨ��
	short reserved;		// ����
    double delay;       // ��ʱ���ع�ʱ��
    double gateTime;    // gate��ʱ�䣬��λ:��
    double gateDistance;// �̶�ģʽ�µ�λ�ü������λpulse
}TCrdBufSHIOSetParam;

typedef struct
{  
	long segNo;			// �û��Զ���κ�
	short ch;			// ͨ��
	short onOff;		// 1:�򿪣�0���ر�
}TCrdBufSHIOGateOnOff;

typedef struct
{  
	long segNo;			// �û��Զ���κ�
	long axisMask;		// ������
	long overTime;		// �ȴ���ʱʱ�䣬��λ������
}TCrdBufWaitEncInPosition;

typedef struct
{  
	long segNo;			// �û��Զ���κ�
	short index;		// ͨ����,ȡֵ��Χ[0,127],ǰ64ͨ������ͨ��DI����64ͨ��������չIO
	short level;		// �ȴ�ֵ
    long waitLastTime;  //��ʱ,��λ������
}TCrdBufWaitDI;

#pragma pack(pop)

// ����岹����
// pBufData �岹���ݽṹ�洢����
// dataLen ���ݳ���
// ѹ������ʱ����ѹ��ָ���֣�Ȼ����ѹ��ָ���ֶ�Ӧ�Ĺ������ݣ��ܵ����ݳ��Ȳ�����1000���ֽ�
MTN_API short __stdcall NMC_CrdBufDataPack(HAND crdHandle,  unsigned char *pBufData, short dataLen);

//���ܣ�������̽λ��ֹͣ��������λ��ƫ��
// useCaptPos���Ƿ�ʹ�ò���λ��  1ʹ��,0��ʹ��
// axis:�����
// sense:������ƽ,0���͵�ƽ,1���ߵ�ƽ
// gpiIndex:ͨ���������
MTN_API short  __stdcall NMC_CrdBufSetStopOffset ( HAND crdHandle, long segNo,
	short axis,short gpiIndex,short sense,short useCaptPos);

//���ܣ����������̽λ��ֹͣ��������λ��ƫ��
MTN_API short  __stdcall NMC_CrdBufClrStopOffset ( HAND crdHandle, long segNo,short axis);

// �����Ƿ���������߶γ���
MTN_API short __stdcall NMC_CrdSetBufLengthFlag(HAND crdHandle, short flag);

// ��ȡ�岹�߶γ���
MTN_API short __stdcall NMC_CrdGetBufLength(HAND crdHandle, double *pLen);

MTN_API short  __stdcall NMC_CrdSetIsShortLine(HAND crdHandle,short isShortLine);

MTN_API short  __stdcall NMC_CrdSetLookAheadCentriAcc(HAND crdHandle,short isUsingSetAcc,double centriAcc);

//------------------------------------------------------------------------------------------------------------
//
//	5.Ӳ�����񼰲�����ָ��
//
//------------------------------------------------------------------------------------------------------------

// ������Ӳ������ģʽѡ�� 
#define CAPT_MODE_Z          0   // ������Z�ಶ�� 
#define CAPT_MODE_IO         1   // IO ���� 
#define CAPT_MODE_Z_AND_IO   2   // IO+Z�� ���� 
#define CAPT_MODE_Z_AFT_IO   3   // ��IO������Z�ഥ�� ���� 

// ������Ӳ������IOԴѡ�� 
#define CAPT_IO_SRC_HOME    0   // ԭ��������Ϊ����IO 
#define CAPT_IO_SRC_LMTN    1   // ������λ������Ϊ����IO 
#define CAPT_IO_SRC_LMTP    2   // ������λ������Ϊ����IO 
#define CAPT_IO_SRC_DI0     3   // ͨ����������0��Ϊ����IO 
#define CAPT_IO_SRC_DI1     4   // ͨ����������1��Ϊ����IO 
#define CAPT_IO_SRC_DI2     5   // ͨ����������2��Ϊ����IO 
#define CAPT_IO_SRC_DI3     6   // ͨ����������3��Ϊ����IO 
#define CAPT_IO_SRC_DI4     7   // ͨ����������4��Ϊ����IO 
#define CAPT_IO_SRC_DI5     8   // ͨ����������5��Ϊ����IO 
#define CAPT_IO_SRC_DI6     9   // ͨ����������6��Ϊ����IO 
#define CAPT_IO_SRC_DI7     10  // ͨ����������7��Ϊ����IO 
#define CAPT_IO_SRC_DI8     11  // ͨ����������8��Ϊ����IO 
#define CAPT_IO_SRC_DI9     12  // ͨ����������9��Ϊ����IO 
#define CAPT_IO_SRC_DI10    13  // ͨ����������10��Ϊ����IO 
#define CAPT_IO_SRC_DI11    14  // ͨ����������11��Ϊ����IO 
#define CAPT_IO_SRC_DI12    15  // ͨ����������12��Ϊ����IO 
// ���ò�����Ч��ƽ
// mode : ģʽѡ��,�ο��궨��
// ioSrc��IO����Դѡ��,�ο��궨��
// level: �����ء�bit0:index��ƽ��0Ϊ�½���,1Ϊ�����أ�,bit1:IO��ƽ
MTN_API short  __stdcall NMC_MtSetCaptSns( HAND axisHandle, short mode, short ioSrc, short level );

// ��ȡ������Ч��ƽ
// mode : ģʽѡ��,�ο��궨��
// ioSrc��IO����Դѡ��,�ο��궨��
// level: �����ء�0Ϊ�½���,1Ϊ������
MTN_API short  __stdcall NMC_MtGetCaptSns( HAND axisHandle, short *pMode, short *pIoSrc, short *pLevel );

// ������������
// ע�����񴥷���־����״̬���
MTN_API short  __stdcall NMC_MtSetCapt( HAND axisHandle );

// �����Ĳ���״̬
MTN_API short __stdcall NMC_MtClrCaptSts   ( HAND axisHandle);

// ������λ��
// pPos : ����λ��,��λ:����
MTN_API short  __stdcall NMC_MtGetCaptPos( HAND axisHandle, long *pPos );

// ��ȡ��������˲�
// pCoeϵ���� ��Χ0~65535,0���˲�,��ֵԽ���˲�Ч��Խ���ԡ�Ĭ��ֵΪ0
MTN_API short  __stdcall NMC_MtGetStepFilter ( HAND axisHandle, unsigned short  *pCoe );

// ����ͬʱ����
// axisHandle:������
// axisMask����bit��Ӧ��Ӧ���,bitΪ1��ʾ����,bitΪ0��ʾ������
MTN_API short __stdcall NMC_MtUpdateMulti( HAND axisHandle,long axisMask );

// ����ͬʱֹͣ
// axisHandle:������
// axisMask����bit��Ӧ��Ӧ���,bitΪ1��ʾ����,bitΪ0��ʾ������
MTN_API short __stdcall NMC_MtStopMulti( HAND axisHandle,long axisMask  );

// ��λ����ͨ�������ź�ȡ��
// bitIndex:ȡֵ��Χ[0,n],λ���,ǰ64λΪ���ص�ͨ������,����64Ϊ��չDi
// revs:�Ƿ�ȡ��,1��ȡ��,0����ȡ��
MTN_API short  __stdcall NMC_SetDIBitRevs ( HAND devHandle,short bitIndex,short revs);

// ��λ��ȡͨ�������ź�ȡ��
// bitIndex:ȡֵ��Χ[0,n],λ���,ǰ64λΪ���ص�ͨ������,����64Ϊ��չDi
// pRevs:�Ƿ�ȡ��,1��ȡ��,0����ȡ��
MTN_API short  __stdcall NMC_GetDIBitRevs ( HAND devHandle,short bitIndex,short *pRevs);

// ��λ����ͨ������ź�ȡ��
// bitIndex:ȡֵ��Χ[0,n],λ���,ǰ64λΪ���ص�ͨ�����,����64Ϊ��չDo
// revs:�Ƿ�ȡ��,1��ȡ��,0����ȡ��
MTN_API short  __stdcall NMC_SetDOBitRevs ( HAND devHandle,short bitIndex,short revs);

// ��λ��ȡͨ������ź�ȡ��
// bitIndex:ȡֵ��Χ[0,n],λ���,ǰ64λΪ���ص�ͨ�����,����64Ϊ��չDo
// pRevs:�Ƿ�ȡ��,1��ȡ��,0����ȡ��
MTN_API short  __stdcall NMC_GetDOBitRevs ( HAND devHandle,short bitIndex,short *pRevs);

// DO��������趨ʱ���ת
// bitIndex:ȡֵ��Χ[0,n],λ���,ǰ64λΪ���ص�ͨ�����,����64Ϊ��չDo
// value:����ͨ�������������1, ����ߵ�ƽ,0,����͵�ƽ
// reverseTime:�����ĵ�ƽ,��λ:����
MTN_API short  __stdcall NMC_SetDOBitAutoReverse(HAND devHandle,short bitIndex,short value,short reverseTime);

// DIOӳ��
#define DIO_MAP_MAX_NUM		8	// ��������ӳ���ϵ

// �ź����Ͷ���
#define DIO_TYPE_GPI		1	// ͨ������
#define DIO_TYPE_HOME		2	// ��Home�ź�
#define DIO_TYPE_ALM		3	// �����������ź�
#define DIO_TYPE_LMTN		4	// �Ḻ����λ�ź�
#define DIO_TYPE_LMTP		5	// ��������λ�ź�
#define DIO_TYPE_GPO		6	// ͨ������ź�
#define DIO_TYPE_SVON		7	// �ŷ�ʹ���ź�
#define DIO_TYPE_SVCLR		8	// ��������ź�


// DIoӳ���������
typedef struct 
{
	unsigned char  enable;		// 1�����ã�0������
	unsigned char  pinGrp;      // ӳ����ź�����
	unsigned char  pinIndex;    // ӳ����ź����
	unsigned char  outEnable;	// �������       
	unsigned char  newGrp;      // ӳ�䵽���ź�����
	unsigned char  newIndex;	// ӳ�䵽���ź����
}TDioMappingCfg;

// ����һ��ӳ�䣬ӳ���ϵĿǰ������DIO_MAP_MAX_NUM��
MTN_API short  __stdcall NMC_SetDioMapping(HAND devHandle,TDioMappingCfg *pDioCfg);

// ��ȡ���е�DIOӳ������
// pDioCfg��ӳ����������,ĿǰΪDIO_MAP_MAX_NUM��
MTN_API short  __stdcall NMC_GetAllDioMapping(HAND devHandle,TDioMappingCfg *pDioCfg);

// ������е�DIOӳ���ϵ
MTN_API short  __stdcall NMC_ClrAllDioMapping(HAND devHandle);

//------------------------------------------------------------------------------------------------------------
//
//	6.ƽ̨���ָ��
//
//------------------------------------------------------------------------------------------------------------
// 
#define     VAR_PWM0_CTL    256		// pwmͨ��0�򿪹ر�,1��ʾ��,0��ʾ�ر�
#define     VAR_PWM0_VALUE  257		// pwmͨ��0���ֵ
#define     VAR_PWM1_CTL    258		// pwmͨ��1�򿪹ر�,1��ʾ��,0��ʾ�ر�
#define     VAR_PWM1_VALUE  259		// pwmͨ��1���ֵ
#define     VAR_EXT_DAC0    260		// ��չ��DACͨ��0
#define     VAR_EXT_DAC1    261		// ��չ��DACͨ��1
#define     VAR_OUT_OPTION	262		// PWM���ͨ��ѡ��
#define     VAR_DAC0		263		// DACͨ��0~7
#define     VAR_DAC1		264
#define     VAR_DAC2		265
#define     VAR_DAC3		266
#define     VAR_DAC4		267
#define     VAR_DAC5		268
#define     VAR_DAC6		269
#define     VAR_DAC7		270
#define     VAR_ADC0		271		// ADCͨ��0~7
#define     VAR_ADC1		272
#define     VAR_ADC2		273
#define     VAR_ADC3		274
#define     VAR_ADC4		275
#define     VAR_ADC5		276
#define     VAR_ADC6		277
#define     VAR_ADC7		278
#define     VAR_INNNER_VAR1	1000
#define     VAR_INNNER_VAR2	1001
// ����ͨ�ÿ�Ѱַ���� 8�ֽ��������ͣ��ɺ��ǳ��õ�����,�磺char/short/long/double �ȣ�
MTN_API short __stdcall NMC_SetVar8B( HAND devHandle, long varID, long long value );

// ��ȡͨ�ÿ�Ѱַ���� 8�ֽ��������ͣ��ɺ��ǳ��õ�����,�磺char/short/long/double �ȣ�
MTN_API short __stdcall NMC_GetVar8B( HAND devHandle, long varID, long long *pValue );

// ϵͳ�����궨��
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

// ����ͨ�ÿ�Ѱַϵͳ���� 8�ֽ��������ͣ��ɺ��ǳ��õ�����,�磺char/short/long/double �ȣ�
MTN_API short __stdcall NMC_SysSetVar8B( HAND devHandle, long varID, __int64 value );

// ��ȡͨ�ÿ�Ѱַϵͳ���� 8�ֽ��������ͣ��ɺ��ǳ��õ�����,�磺char/short/long/double �ȣ�
MTN_API short __stdcall NMC_SysGetVar8B( HAND devHandle, long varID, __int64 *pValue );

//�򱸷��ڴ�д����(�ܳ���Լ1500byte)
//src: Ҫд�������
//len: Ҫд��ĳ���,��λ��byte
//off: Ҫд��ĵ�ַ(ƫ����)
// ע��1)д������ݵ��粻��ʧ��
//     2)һ�����д1440�ֽڡ��ܳ���Լ1500byte
MTN_API short __stdcall NMC_BackSramWrite(HAND devHandle,const void *src, long len, long off);

//�ӱ����ڴ������
//dst: �����������ݴ���
//len: Ҫ�����ĳ���,��λ��byte,һ������1440�ֽڡ��ܳ���Լ1500byte
//off: �����ݵĵ�ַ(ƫ����)
MTN_API short __stdcall NMC_BackSramRead(HAND devHandle,void *dst, long len, long off);

// ƽ̨��������ʱ��ṹ
typedef    struct
{
    short   year;           // ��,��ʵ��ݡ�ȡֵ��Χ[2000,2099]
    short   mon;            // ��,ȡֵ��Χ[1,12]
    short   day;            // ��,ȡֵ��Χ[1,31]
    short   hour;           // ʱ,ȡֵ��Χ[0,23]
    short   min;            // ��,ȡֵ��Χ[0,59]
    short   second;         // ��,ȡֵ��Χ[0,59]
} TNMCTime;
// ��ʱ��
// pTime ������ʱ��ṹ,�ο� TNMCTime �ṹ����
// ע��ʱ���ڳ���ʱ����ʵ��ʱ���趨,�û�����ͨ��ָ���޸�
MTN_API short  __stdcall NMC_GetTime( HAND devHandle, TNMCTime *pTime );


// дʱ��
// pTime ��ʱ��ṹ,�ο� TNMCTime �ṹ����
// pPassword : ������ϵͳ����,�������Ϊ16���ֽ�
MTN_API short  __stdcall NMC_SetTime( HAND devHandle, TNMCTime *pTime,char *pPassword);

// �޸Ŀ�����ϵͳ����,���������޸�ϵͳʱ�ӵ�
// pPasswordOld : ������ϵͳ��ǰ����,�������Ϊ15���ַ�
// pPasswordNew : �µĿ�����ϵͳ����,�������Ϊ15���ַ�
// ע�⣺1.��ʼ����������
//            2.�޸������,����ؼ�ס�µ����롣��������ֻ�ܷ�����λ��
//            3.�����Сд����
MTN_API short  __stdcall NMC_ChangePassword( HAND devHandle, char *pPasswordOld,char *pPasswordNew);

// ��֤ϵͳ����
// pPassword : ������ϵͳ��ǰ����,�������Ϊ15���ַ�
// ����0��ʾ��֤ͨ��,������ʾ����
MTN_API short  __stdcall NMC_VerifyPassword( HAND devHandle, char *pPassword);

// ���ϵͳ���뼰�û�����
// pData:�������ݣ�����Ϊ8
MTN_API short  __stdcall NMC_ClrPassword( HAND devHandle, short *pData);

// ���豸Ψһ���к�
// pUID �������豸Ψһ���к�,Ϊ�ĸ�Int32������
// example:unsigned long devID[4];
//         NMC_GetUID(g_hDev,devID);
MTN_API short  __stdcall NMC_GetUID( HAND devHandle, unsigned long *pUID );

// д�û�����
// add ����������ƫ�Ƶ�ַ(�ֽڵ�ַ)
// len : д�볤��,��λ��byte
// pWrData ��Ҫд������ݣ�
// ע��1)д������ݵ��粻��ʧ��
//     2)һ�����д256�ֽڡ��������ܳ���Ϊ2048�ֽڡ�
//     3)��ָ�������ָ�����ʱ��᳤,�������ͨѶ���󣨷���-1��,����Ҫ��ͨ��NMC_SetCommPara�ӳ�ָ��ͨѶʱ��
MTN_API short  __stdcall NMC_UserParaWr( HAND devHandle, unsigned long add, unsigned long len, unsigned char *pWrData );

// ���û�����
// add ����������ƫ�Ƶ�ַ(�ֽڵ�ַ)
// len : д�볤��,��λ��byte
// pRdData ��Ҫ��ȡ�����ݴ洢
// ע��һ������256�ֽڡ��������ܳ���Ϊ2048�ֽڡ����ο����� �� NMC_UserParaWr��
MTN_API short  __stdcall NMC_UserParaRd( HAND devHandle, unsigned long add, unsigned long len, unsigned char *pRdData );

// д��չ�û�����
// add ����������ƫ�Ƶ�ַ(�ֽڵ�ַ)
// len : д�볤��,��λ��byte
// pWrData ��Ҫд������ݣ�
// ע��1)д������ݵ��粻��ʧ��
//     2)һ�����д1000�ֽڡ��������ܳ���Ϊ32K�ֽڡ�
//     3)��ָ�������ָ�����ʱ��᳤,�������ͨѶ���󣨷���-1��,����Ҫ��ͨ��NMC_SetCommPara�ӳ�ָ��ͨѶʱ��
MTN_API short  __stdcall NMC_UserParaWrEx( HAND devHandle, unsigned long add, unsigned long len, unsigned char *pWrData );

// ����չ�û�����
// add ����������ƫ�Ƶ�ַ(�ֽڵ�ַ)
// len : д�볤��,��λ��byte
// pRdData ��Ҫ��ȡ�����ݴ洢
// ע��һ������1000�ֽڡ��������ܳ���Ϊ32K�ֽڡ����ο����� �� NMC_UserParaWr��
MTN_API short  __stdcall NMC_UserParaRdEx( HAND devHandle, unsigned long add, unsigned long len, unsigned char *pRdData );

// ���籣�棺�������ݶ���
typedef struct
{
	long crdSegNo;		// ����ϵ�˶��Ķκ�
	long crdPrfPos[3];	// ����ϵ�˶��Ĺ滮λ��
	long axPrfPos[8];	// �滮λ��
	long axisPos[8];	// ��еλ��
	long encPos[8];		// ������λ��
}TBackGroup1;
// ��ȡ��ǰ���ݵı�����ֵ���ϵ��Զ����棩
// pBackVar : ���ݵı���ֵ,�ο��ṹ�嶨��
MTN_API short __stdcall NMC_GetBackedVarGroup1( HAND devHandle, TBackGroup1 *pBackVar);

// ���籣�棺�������ݶ��壨12�ᣩ
typedef struct
{
	long crdSegNo[2];		// ����ϵ�˶��Ķκ�
	long crdPrfPos[2][3];	// ����ϵ�˶��Ĺ滮λ��
	long axPrfPos[12];		// �滮λ��
	long axisPos[12];		// ��еλ��
	long encPos[12];		// ������λ��
}TBackGroup2;
// ��ȡ��ǰ���ݵı�����ֵ���ϵ��Զ����棩
// pBackVar : ���ݵı���ֵ,�ο��ṹ�嶨��
MTN_API short __stdcall NMC_GetBackedVarGroup2( HAND devHandle, TBackGroup2 *pBackVar);

// ��ʼ���߹رձ������Զ����ݣ��ϵ��Զ�����,Ĭ��Ϊ�ر�״̬��
// en:�Ƿ���,1�������������Զ�����,0��ֹͣ�������Զ�����
MTN_API short __stdcall NMC_SetBackedVarOnOff( HAND devHandle, short en);

// ��ȡ��ǰ�Զ����ݵĿ���״̬
// pEn:��ǰ�Ŀ���״̬
MTN_API short __stdcall NMC_GetBackedVarOnOff( HAND devHandle, short *pEn);

// paraID
#define     PARA_IP_ADDR   	100		// IP��ַ,�ĸ��ֽڷֱ��ʾ�Ķ�
#define     PARA_IP_MSK    	101		// IP mask
#define     PARA_IP_GW   	102		// Gateway
#define     PARA_IP_DHCP   	103		// DHCP
#define     PARA_WRITE_EN	999		// ��������
// ��ȡϵͳ������long �ͣ�
// paraID :��ϵͳ����ID,�μ����涨�塣pValue : ����ֵ
// ע���˺������������ð忨�ϵ���չ��Դ
MTN_API short  __stdcall NMC_DevGetPara( HAND devHandle, unsigned long paraID, long *pValue );

// ����ϵͳ������long �ͣ�
// paraID :��ϵͳ����ID,�μ����涨�塣value : ����ֵ
// ע���˺��������ڶ�ȡ�忨�ϵ���չ��Դ
// ע��IP��ַ�Ȳ���д�ɹ���,��Ҫ����NMC_DevSetPara(devHandle,PARA_WRITE_EN,1)����ʹ��д��ȥ�Ĳ�������
// ע��IP��ַ�Ȳ���д�ɹ���,���ڿ�����������������Ч
MTN_API short  __stdcall NMC_DevSetPara( HAND devHandle, unsigned long paraID, long value );

// �����û�����
// pUserName    : ָ�����û���,Ŀǰֻ֧��"USER1"
// pPasswordOld : ���û��ĵ�ǰ����,�������Ϊ15���ַ�
// pPasswordNew : �µĸ��û�������,�������Ϊ15���ַ�
// ע�⣺1.��ʼ����������,һ����������,�����Ҫ��½��,������ĳЩָ������������������������˶�ָ��,����DO���ָ�
//      2.�޸������,����ؼ�ס�µ����롣��������ֻ�ܷ�����λ��
//      3.�����Сд����
MTN_API short  __stdcall NMC_UserSetPassword( HAND devHandle, char *pUserName,char *pPasswordOld,char *pPasswordNew);

// �û���½
// pUserName    : ָ�����û���,Ŀǰֻ֧��"USER1"
// pPassword    : ���û�������
MTN_API short  __stdcall NMC_UserLogin( HAND devHandle, char *pUserName,char *pPassword);

// �û��˳���½
// pUserName    : ָ�����û���,Ŀǰֻ֧��"USER1"
MTN_API short  __stdcall NMC_UserLogout( HAND devHandle, char *pUserName);

// ���ÿ������Ĺ滮���ڣ�Ĭ��1000
// period����λus	ֻ��Ϊ250 500 1000
// ע�⣺1.�滮�������ú�������Ч��ֻ���ڿ���������ʱ����
//       2.NMC_DevReset�Ḵλ�滮����ΪĬ��ֵ
MTN_API short __stdcall NMC_SetProfilePeriod(HAND devHandle,short period);

// ��ȡ�������Ĺ滮����
// period����λus	ֻ��Ϊ250 500 1000
MTN_API short __stdcall NMC_GetProfilePeriod(HAND devHandle,short *pPeriod);

// ��ӡ��Ϣ
MTN_API short __stdcall NMC_UserPrint(char *msg);

// ��ȡ�����Ϣ
MTN_API short __stdcall NMC_DevGetOutputMsg(HAND devHandle,char *szBuf,short maxLen,short *pGetLen);

//------------------------------------------------------------------------------------------------------------
//
//	7.���ݲɼ�ģ��(�߼�ָ��)
//
//------------------------------------------------------------------------------------------------------------

// Collectģ�飺��������
#define COLLECT_ADDRESS_PRF_POS				(0)	// �滮λ��
#define COLLECT_ADDRESS_AXIS_POS			(1)	// ��еλ��
#define COLLECT_ADDRESS_ENC_POS				(2)	// ������λ��
#define COLLECT_ADDRESS_CMD_POS				(3)	// ����λ��
#define COLLECT_ADDRESS_AXIS_VEL			(4)	// ����ٶ�
#define COLLECT_ADDRESS_CRD_POS				(5)	// ����ϵ0λ��
#define COLLECT_ADDRESS_CRD_VEL				(6)	// ����ϵ0�ٶ�
#define COLLECT_ADDRESS_CRD_POS0			(5)	// ����ϵ0λ��
#define COLLECT_ADDRESS_CRD_VEL0			(6)// ����ϵ0�ٶ�
#define COLLECT_ADDRESS_CRD_POS1			(9)// ����ϵ1λ��		
#define COLLECT_ADDRESS_CRD_VEL1			(10)// ����ϵ1�ٶ�
#define COLLECT_ADDRESS_ENC_VEL				(7)	// �������ٶ�
#define COLLECT_ADDRESS_CMD_VEL				(8)	// �����ٶ�
#define	COLLECT_ADDRESS_LASER_OUTPUT		(11)// �������������ǰ��
#define COLLECT_ADDRESS_LASER_GATE			(12)// ����gate�ź�״̬
#define COLLECT_ADDRESS_LASER_POWER			(13)// ����������ǰ���ֵ
#define COLLECT_ADDRESS_DI      			(14)// ����������״̬
#define COLLECT_ADDRESS_DO      			(15)// ���������״̬
#define COLLECT_ADDRESS_CRD_USERSEG			(16)// ����ϵ�û��κ�
#define COLLECT_ADDRESS_DAC					(17)// ģ�������
#define COLLECT_ADDRESS_ADC					(18)// ģ��������

// ��ȡ��Ҫ�ɼ����ݱ����ĵ�ַ
//  index:���������(��0��ʼ)
//  type: ����������,������Collectģ�飺�������͡��궨��
//  pAddr: ���ص����ݵ�ַ
// pDataLen: ���صĸ����ݳ���
MTN_API short  __stdcall NMC_GetCollectDataAddr( HAND devHandle, short index,short dataType,unsigned long *pAddr, short *pDataLen);

// �ɼ�ģ�飺�ɼ�����
#define COLLECT_LIST_MAX		(8) 			//ÿ�����ɼ�8������
typedef struct
{
	short  count;								// ��Ҫ�ɼ��ı�������
	short  interval;							// �ɼ��ļ��ʱ��,0��ʾÿ��1���ײɼ�һ������,1��ʾÿ��2ms...
	unsigned long  address[COLLECT_LIST_MAX];	// �����ĵ�ַ
	short  length[COLLECT_LIST_MAX];			// ÿ�������ĳ��ȣ���λ��char��
}TCollectCfg;

// �ɼ�ģ�飺����ģʽ
#define COLLECT_MODE_NONE	0	// ������
#define COLLECT_MODE_G_SRC1	1	// �ɼ�Դ1��ֵ���ڱȽ�ֵ
#define COLLECT_MODE_L_SRC1	2	// �ɼ�Դ1��ֵС�ڱȽ�ֵ
#define COLLECT_MODE_DIFF	3	// �ɼ�Դ1��ɼ�Դ2�����ֵ���ڱȽ�ֵ
typedef struct
{
	short  mode;								// ����ģʽ,
	short  source1;								// ����Դ1
	short  source2;								// ����Դ2
	short  startDelay;							// ������������ʱ
	double  value;								// �����Ƚ�ֵ
}TCollectTrig;
// ���òɼ�����ͨ��,��Ҫ���ö�Ӧ�ṹ�����
// pCollect:�ɼ�ģ������
// pTrig:�ɼ�ģ�鴥����ʽ����
MTN_API short  __stdcall NMC_ConfigCollect( HAND devHandle, TCollectCfg *pCollect,TCollectTrig *pTrig );

// ������ֹͣ���ݲɼ�
// en��1���� 0ֹͣ
MTN_API short  __stdcall NMC_CollectOnOff ( HAND devHandle, short en);

// Collectģ�飺�ɼ�״̬
#define COLLECT_BUSY						(0x0001)
#define COLLECT_OVERRIDE_DATA				(0x0002)	
#define COLLECT_PUSH_DATA_ERR				(0x0004)
// ��ȡ�ɼ�״̬:
// pSts���ɼ�״̬,��λ��ʾ����״̬,�ο���Collectģ�飺�ɼ�״̬���궨��
// pDataLen: �ɼ���������
MTN_API short  __stdcall NMC_GetCollectSts ( HAND devHandle, short *pSts, long *pDataLen );

// ��ȡ������:
// len���ɼ����ݳ��ȣ���λ��char,һ������1440�ֽڣ�
// pData: �ɼ������ݣ�����charΪ��Ԫ�洢��
MTN_API short  __stdcall NMC_GetCollectData ( HAND devHandle, short len, unsigned char *pData );

// ����ɼ�״̬
MTN_API short  __stdcall NMC_ClearCollectSts ( HAND devHandle);

//------------------------------------------------------------------------------------------------------------
//
//	8.����
//
//------------------------------------------------------------------------------------------------------------
#define MAX_LASER_NUMS			    (4)	    // ��󼤹�ͨ��

// �������ģʽ
#define LASER_DISABLE_MODE			    (0)	    // ���ü��⹦��
#define BASIC_OUTPUT_MODE			    (1)		// ��������ģʽ
#define TIME_ARRAY_OUTPUT_MODE			(2)    	// ���ο���ģʽ
#define SHIO_OUTPUT_MODE				(3)     // λ�ñȽϿ���ģʽ

//���ü�����Ƶ�ģʽ����ģʽ���趨,Լ����Ӧָ��Ĺ��ܺͲ���
//mode: �������ģʽ,�ο������궨��
MTN_API short  __stdcall NMC_LaserSetMode  (HAND devHandle, short mode, short ch );

 // ���������ź�����
#define LASER_NONE 			(0)			// �رռ������ģʽ
#define LASER_DA  			(1)			// DA���
#define LASER_PWM_DUTY		(2)			// ռ�ձ����
#define LASER_PWM_FRQ		(3)			// Ƶ�����
#define LASER_PWM_FRQ_EXT	(4)			// Ƶ�����,����̶�

// ���������ź������������
// outputType�����������
// index :���ͨ�����,ȡֵ��Χ[0,n]
// optionVal: ����Ϊռ�ձ����ʱ,��ֵΪPWM��Ƶ��,��λHZ��
//            ��ΪLASER_PWM_FRQʱ,��ֵ��Ϊռ�ձ�ֵ,��0~100����
//            ��ΪLASER_PWM_FRQ_EXTʱ,��ֵΪ����,��λΪ0.5΢��,ȡֵ��Χ(0,~)
// ch :����ͨ��,ȡֵ��Χ[0,n]
MTN_API short  __stdcall NMC_LaserSetOutputType ( HAND devHandle,short outputType,short index,long optionVal,short ch);

// ���������ź������������(�߾���)
// outputType�����������
// index :���ͨ�����,ȡֵ��Χ[0,n]
// optionVal: ����Ϊռ�ձ����ʱ,��ֵΪPWM��Ƶ��,��λHZ��
//            ��ΪLASER_PWM_FRQʱ,��ֵ��Ϊռ�ձ�ֵ,��λΪ�ٷֱȣ�
//            ��ΪLASER_PWM_FRQ_EXTʱ,��ֵΪ����,��λΪ΢��,ȡֵ��Χ(0,~)
// ch :����ͨ��,ȡֵ��Χ[0,n]
MTN_API short  __stdcall NMC_LaserSetOutputTypeEx ( HAND devHandle,short outputType,short index,double optionVal,short ch);

// ���ܣ���������������������,
// outVal: �����������趨ֵ������NMC_LaserSetOutputType���õ�������Ͷ�Ӧ��
// ch�����ͨ�� (��Ҫ���ݲ�ͬ�����źŶ˿����������趨)
MTN_API short  __stdcall NMC_LaserSetPower ( HAND devHandle,long outVal,short ch);

// ���ܣ���ȡ��ǰ��������� 
// pVal: ��������ֵ
// ch��ͨ����
MTN_API short  __stdcall NMC_LaserGetPower ( HAND devHandle,double *pVal,short ch);

// ���ܣ���ȡ��ǰ���⿪��״̬ 
// pOnOffState: ���⿪��״̬��1�����⴦�ڴ�״̬��0:���⴦�ڹر�״̬
// ch��ͨ����
MTN_API short  __stdcall NMC_LaserGetOnOff ( HAND devHandle,short *pOnOffState,short ch);

// ���ܣ���������������������(�߾���)
// chn�����ͨ�� (��Ҫ���ݲ�ͬ�����źŶ˿����������趨)
// outVal: �����������趨ֵ������NMC_LaserSetOutputTypeEx���õ�������Ͷ�Ӧ��
MTN_API short  __stdcall NMC_LaserSetPowerEx ( HAND devHandle,double outVal,short ch);

// ���ܣ���������������� 
// onOffl: 0����1��ʾ�򿪻�رռ������
// ch�����ͨ�� (��Ҫ���ݲ�ͬ�����źŶ˿����������趨)
MTN_API short  __stdcall NMC_LaserOnOff ( HAND devHandle,short onOff,short ch);

// ���ü������
// onDelay:������ʱ,��λus,ȡֵ��Χ[0,65535]
// offDelay:�ع���ʱ,��λus,ȡֵ��Χ[0,65535]
// minValue:��С���ֵ,ȡֵ��Χ[0,32767]
// maxValue:������ֵ,ȡֵ��Χ[0,32767]
// standbyPower:��������,Ϊ0��ʾȡ�����������������
// ch:�������ͨ��
MTN_API short  __stdcall NMC_LaserSetParam ( HAND devHandle, long onDelay ,
				long offDelay, long minValue ,long maxValue,long standbyPower,short ch);

// ���������ü������
// onDelay:������ʱ,��λus,ȡֵ��Χ[0,65535]
// offDelay:�ع���ʱ,��λus,ȡֵ��Χ[0,65535]
// minValue:��С���ֵ��DA���ʱ����Χ[0,32767],ռ�ձ����ʱ����Χ[0,100],Ƶ�����ʱ����Χ[0,2000000]
// maxValue:������ֵ��DA���ʱ����Χ[0,32767],ռ�ձ����ʱ����Χ[0,100],Ƶ�����ʱ����Χ[0,2000000]
// standbyPower:��������,Ϊ0��ʾȡ�����������������
// ch:�������ͨ��
MTN_API short  __stdcall NMC_CrdBufLaserSetParam ( HAND crdHandle, long segment,long onDelay ,
				long offDelay, long minValue ,long maxValue,long standbyPower,short ch);

// ��ȡ�������
MTN_API short  __stdcall NMC_LaserGetParam ( HAND devHandle, long *pOnDelay,
			long *pOffDelay, long *pMinValue ,long *pMaxValue,long *pStandbyPower,short ch);

// ���û�����������������
// segNo:�κ�
// overRide:���汶��,Ϊ0��ʾȡ��������������
// followType:��������,0������滮�ٶ�,1������ʵ���ٶ�
// ch:����ͨ����,ȡֵ��Χ[0,n]
MTN_API short __stdcall NMC_CrdBufLaserSetFollow(HAND crdHandle,long segNo,double overRide,short followType,short ch);

// ���û�����������������
// powerFilter:��������˲�ϵ����ȡֵ��Χ[0,32]��0����������Ĭ�ϣ�
// followAdvMode:����������㷽��
// ch:����ͨ����,ȡֵ��Χ[0,n]
MTN_API short __stdcall NMC_LaserSetFollowParam(HAND devHandle,short powerFilter,short followAdvMode,short ch);

// ���������⿪��
// segNo:�κ�
// onOff:����,0���ع�,1������
// ch:�������ͨ��
MTN_API short  __stdcall NMC_CrdBufLaserOnOff ( HAND crdHandle,long segNo,short onOff,short ch);

// ���������ü�������,������������ģʽ��,��������ָ����Ч
// segNo:�κ�
// power:����
// ch:�������ͨ��
MTN_API short  __stdcall NMC_CrdBufLaserPower ( HAND crdHandle,long segNo,long power,short ch);

// ���������������ݱ����򳤶����ֵ
#define LASER_CMP_DATA_LEN_MAX				(10)

// ���ü�������������
// tableNo�� ������� ��֧��20�ű�
// pXCmpPos��X������ıȽ�λ��,����ΪxCount  
// pYCmpPos: Y������ıȽ�λ��,����ΪyCount  
// xCount�� ��X����ĳ���,ȡֵ��Χ[2,10]
// yCount�� ��Y����ĳ���,ȡֵ��Χ[2,10]
// powerMin:	���ڸ���С�����Ų���
// powerMax:	С�ڸ���������Ų���
// pLaserCmpPower���������ֵ���ò���Ϊ2ά������׵�ַ
// chn:��Ӧ�ļ���ͨ����
MTN_API short  __stdcall NMC_SetLaserPowerCmpTable ( HAND devHandle,short tableNo,long *pXCmpPos,long *pYCmpPos,
	short xCount,short yCount, unsigned long powerMin,unsigned long powerMax,unsigned long *pLaserCmpPower,short chn);

// ����������������
// pAxisNo�� pAxisNo[0]��X�����λ�ñȽ���� pAxisNo[1]��Y�����λ�ñȽ����
// chn�������������·����ͨ��
MTN_API short  __stdcall NMC_StartLaserPowerComp ( HAND devHandle,short *pAxisNo,short chn);

// ֹͣ������������
MTN_API short  __stdcall NMC_StopLaserPowerComp ( HAND devHandle,short chn);

// 
#define LASER_GROUP		(12)			// ��󼤹���������
#define LASET_POINT		(40)			// ÿ��������

typedef struct
{
	short pwmEnable;		// �Ƿ���Ҫ���PWM,0:�������һ�����Σ�1������λ���������
	short outputType;		// �����ź�������ͣ�0��gate,1��GPO
	short outputCh;			// �����ź����ͨ��
	short stLevelRevs;	    // SHIO�����ƽȡ��,Ĭ��Ϊ0����ȡ��
	long pwmPeriod;			// ����,PWM����,��λus,����С��ʱ�������������
	long pwmWidth;			// ����,PWM����,��λus,�˲�������,�������ʱ�������������
    long gateDistance; 	    // �̶�ģʽ�µ�λ�ü�� ��λ��pulse��
						    // Ĭ��0,ģʽ2~4 �»������Ч�Լ��
    long minFrqFrq; 	    // ����,SHIO������Ƶ�ʣ���λHZ
    short posSrc; 		    // �Ƚ�ģʽ,�ⲿ�����������ڲ��滮ֵ��
					        // 0���ⲿ���������Ƽ���,1���ڲ��滮ֵ��
					        // Ĭ��0��
    short axisMask; 	    // ���,��bit λ��Ӧ����һ�������ᣩ��
						    // Ĭ�� 0��
    short minFrqEn;		    // ����,�Ƿ�����SHIO������Ƶ�ʣ�Ĭ��0��������
	short reserved2;	    // ����
}TTimeArrayPara;

// ����ʱ�������������
// ch : ����ͨ��
// pPara �� ����
// ע��1.��ʱ�����������ʽ����Ч
MTN_API short  __stdcall NMC_LaserSetTimeArrayPara  ( HAND devHandle,TTimeArrayPara *pPara,short ch);

typedef struct
{
	unsigned short time[LASET_POINT];// ÿ����֮��ļ��ʱ��,��λ:100΢��
	short power[LASET_POINT];		// �����������С
	short count;					// ʵ��ѹ�����
}TLaserPower;

// ���ü��������,�����������ģʽ,group��Ч,pLaserPowerΪָ���ĵ���������Ϣ
// group : ������һ�鼤������
// pLaserPower �� ���õ�����
// ע��1.���������� 
//     2.�ýӿڶ���SHIOģʽ��Ч
MTN_API short  __stdcall NMC_LaserSetTimeArrayPower  ( HAND devHandle,short group,TLaserPower *pLaserPower );
	
// ִ��ʱ�����м���,ֻ��ʱ���������ģʽ����Ч
// group : ������һ�鼤������
// ch:����ͨ��
// ע��1.����ʱ�����������,ֱ�����һ����,������һ����������Ϊ0,��ά�����һ���������
//    2.������һ��������Ϊ0,��û��PWM������,���Զ��رռ��⡣��PWM�������Ҫ����NMC_LaserOnOff����NMC_CrdBufLaserOnOff�رռ���
MTN_API short  __stdcall NMC_LaserTimeArrayExe  (HAND devHandle, short group,short ch );

// ������ִ��ʱ�����м���,ֻ��ʱ���������ģʽ����Ч
// segNo:�κ�
// group:������һ�鼤������
// ch:�������ͨ��
// ע��1.����ʱ�����������,ֱ�����һ����,������һ����������Ϊ0,��ά�����һ���������
//    2.������һ��������Ϊ0,��û��PWM������,���Զ��رռ��⡣��PWM�������Ҫ����NMC_LaserOnOff����NMC_CrdBufLaserOnOff�رռ���
MTN_API short  __stdcall NMC_CrdBufLaserTimeArrayExe ( HAND crdHandle,long segNo,short group,short ch);

typedef struct
{
	short isArray; 		// �Ƿ�̶���໹�����顣0���̶���ࣨ��֧�֣�,Ĭ��0
	short outMode; 		// ���ģʽ��Ĭ��1
						// 1��ֻ���gate ���������,
						// 2: ����λ�����gate
						// 3: ����λ�����gate,gate ��ͬ��trigger �ź�ͬ��
						// 4: ����λ�����gate,gate ���ź�����ͬ��
	short posSrc; 		// �Ƚ�ģʽ,�ⲿ�����������ڲ��滮ֵ��
						// 0���ⲿ���������Ƽ���,1���ڲ��滮ֵ��
						// Ĭ��0��
	short axisMask; 	// ���,��bit λ��Ӧ����һ�������ᣩ��
						// Ĭ�� 0��
	double delay; 		// ��ʱ���ع�ʱ��( �ݲ��� ),��λ��s��Ĭ�� 0��
	double gateTime; 	// ����gate ��ʱ��,��λ��s���ڲ���Сֵ��1/36us ��,ȡֵ��Χ(0,0.0009)
						// Ĭ��0��
	long gateDistance; 	// �̶�ģʽ�µ�λ�ü�� ��λ��pulse��
						// Ĭ��0,ģʽ2~4 �»������Ч�Լ�顣
    long k;				// ��Ƶ����ϵ��          
	long startDot; 	    // ����ʱ������
	long lowFrqRange; 	// ��Ƶ��Χ��0:100K,1:1M
	short outType;		// ������ͣ�0-Gate��1-GPO
	short outIndex;		// ���ͨ����ȡֵ[0,19]
	long reserved5; 	// ��������,Ӧ��Ϊ0��
}TSHIOPara;

// ����SHIO���ܵĲ���
MTN_API short  __stdcall NMC_SHIOConfigPara  (HAND devHandle, TSHIOPara *pSHIOPara,short ch);

// SHIO�������СƵ�ʹ��ܿ�
// minFrq:���Ƶ�ʣ���λHZ
MTN_API short  __stdcall NMC_SHIOEnableMinFrq  (HAND devHandle,long minFrq,short ch);

// SHIO�������СƵ�ʹ��ܹر�
MTN_API short  __stdcall NMC_SHIODisableMinFrq  (HAND devHandle,short ch);

// ����������SHIO���ܵĲ���
MTN_API short  __stdcall NMC_CrdBufSHIOConfigPara  (HAND crdHandle, long segment, TSHIOPara *pSHIOPara,short ch);

// ������SHIO�������СƵ�ʹ��ܿ�
// minFrq:���Ƶ�ʣ���λHZ
MTN_API short  __stdcall NMC_CrdBufSHIOSetMinFrq(HAND crdHandle, long segment, long minFrq,short ch);

// ������SHIO�������СƵ�ʹ��ܹر�
MTN_API short  __stdcall NMC_CrdBufSHIOClrMinFrq (HAND crdHandle, long segment,short ch);

// ����������SHIO���ܵĲ���
// delay:��ʱ���ع�ʱ��( �ݲ��� ),��λ��s��Ĭ�� 0��
// gateTime:����gate ��ʱ��,��λ��s���ڲ���Сֵ��1/36us ��,ȡֵ��Χ(0,0.0009),Ĭ��0��
// gateDistance:�̶�ģʽ�µ�λ�ü�� ��λ��pulse��
MTN_API short  __stdcall NMC_CrdBufSHIOSetParam  (HAND crdHandle, long segment,double delay,
	double gateTime,double gateDistance,short ch);

// �л��ᣨ���������ϵ����ȫһ�£�
MTN_API short  __stdcall NMC_SHIOChangeAxisMask( HAND devHandle, short axisMask,short ch );

// �л��ᣨ���������ϵ����ȫһ�£�,������ָ��
MTN_API short  __stdcall NMC_CrdBufSHIOChangeAxisMask( HAND crdHandle, long segment, short axisMask,short ch );

// ����GATE���
// ע�����ú����ģʽ���
MTN_API short  __stdcall NMC_SHIOGateOn ( HAND devHandle ,short ch);

// ��ֹGATE���
// ע�����ú�������ֹ���
MTN_API short  __stdcall NMC_SHIOGateOff ( HAND devHandle ,short ch);

// ����Trigger ���,
// triggerFreq : ����triger ����Ƶ�ʵ�λ��HZ��
// triggerWidth : ����triger ������,��λ��s���ڲ���Сֵ��1/36us ����Ĭ��0��
// ע�����ú��������
MTN_API short __stdcall NMC_SHIOTriggerOn ( HAND devHandle,double freq,double width ,short ch);

// ��ֹGATE���
// ע�����ú��������
MTN_API short  __stdcall NMC_SHIOTriggerOff ( HAND devHandle ,short ch);

// ����GATE���
// ע�����ú����ģʽ���
MTN_API short  __stdcall NMC_BufSHIOGateOn ( HAND crdHandle, long segNo,short ch);

//��ֹGATE���
//ע��������ִ�е���ָ���������ֹ���
MTN_API short  __stdcall NMC_BufSHIOGateOff ( HAND crdHandle, long segNo,short ch);

// PWMӳ�䵽GATE�������
// pwmCh:pwm ͨ����
// gateCh:gate�ź�ͨ����
// onOff: 0 -- ��ӳ�䣬1 -- ӳ�� ��Ĭ��Ϊ0��
MTN_API short  __stdcall NMC_SetPwmToGate (HAND devHandle, short pwmCh,short gateCh,short onOff);

// ������SHIO�㶯���⣬���һ��gate����,ע�⣺�����ڼ���SHIO����ģʽ��ʹ��
// gateTime:gate�����������λ��΢��
// gateFrq:gate�����Ƶ�ʣ���λ��HZ
// outCount:�������
// ch:ͨ��
MTN_API short  __stdcall NMC_CrdBufSHIOGatePulse ( HAND crdHandle,long segNo,double gateTime, 
	double gateFrq,long outCount,short ch);

// SHIO�㶯���⣬���һ��gate����,ע�⣺�����ڼ���SHIO����ģʽ��ʹ��
// gateTime:gate�����������λ��΢��
// gateFrq:gate�����Ƶ�ʣ���λ��HZ
// outCount:�������
// ch:ͨ��
MTN_API short  __stdcall NMC_SHIOGatePulse ( HAND devHandle,double gateTime, double gateFrq,long outCount,short ch);

// ���һ��PWM����,ע�⣺�����ڼ���SHIO����ģʽ��ʹ��
// onTime:PWM�����������λ��΢��
// pwmFrq:PWM�����Ƶ�ʣ���λ��HZ
// outCount:�������
// ch:ͨ��
MTN_API short  __stdcall NMC_PwmPulseOut ( HAND devHandle,double onTime, double pwmFrq,long outCount,short ch);

//------------------------------------------------------------------------------------------------------------
//
//	9.����
//
//------------------------------------------------------------------------------------------------------------
// ��������������
// axisHandle: ������������
// group     : �������,ȡֵ��Χ[0,n]
MTN_API short __stdcall NMC_SetGantryMaster( HAND axisHandle, short group );

// �������ŴӶ���
// axisHandle  : ���ŴӶ�����;
// group       : �������,ȡֵ��Χ[0,n]
// gantryErrLmt: ���ű������,ȡֵ��Χ(0,...)
MTN_API short __stdcall NMC_SetGantrySlave( HAND axisHandle , short group, long gantryErrLmt );

// ���Ź��ܹر�
// group :       �������,ȡֵ��Χ[0,n]
MTN_API short __stdcall NMC_DelGantryGroup( HAND axisHandle, short group );

//------------------------------------------------------------------------------------------------------------
//
//	10.ͨѶ��չ������
//
//------------------------------------------------------------------------------------------------------------
// ͨѶ��չ
// �û�ָ���,ֻд
MTN_API short  __stdcall NMC_UserCmdWrite( HAND devHandle, unsigned char *sendBuffer, unsigned long sendLen );

// �û�ָ���,ֻ��
MTN_API short  __stdcall NMC_UserCmdRead( HAND devHandle, unsigned char *sendBuffer, 
	unsigned long sendLen, unsigned char *recBuffer, unsigned long waitLen );

// �������ݴ���,ֻд
MTN_API short  __stdcall NMC_DataTransfer( HAND devHandle, unsigned char *sendBuffer, unsigned long sendLen );		

// ��ֹ�û���������
MTN_API short __stdcall NMC_SysSetUserApp   ( HAND devHandle, unsigned char mode );

// ����
MTN_API short __stdcall NMC_SysUpgrade   ( HAND devHandle );

// �����̼�
MTN_API short __stdcall NMC_SysUpgradeEx( HAND devHandle, unsigned char cmd, 
	unsigned char *sendBuffer, unsigned long sendLen, unsigned char *recBuffer, unsigned long recvedLen );

// ���õ�����Ϣ
MTN_API short __stdcall NMC_SetDebugErrorEn(  HAND devHandle, short debugErrEn );

// ��ȡ���һ�εĴ������
// ����ֵ���������
MTN_API short __stdcall NMC_GetLastErr(void);

// ����ָ����󷵻�ֵģʽ
// mode:0-��׼ģʽ,��������ϸ�Ĵ������(Ĭ��)��1--���ģʽ,ֻ���ش���������
MTN_API short __stdcall NMC_SetErrCodeMode(short mode);

// ����ָ��ͨѶ���Ź�
// timeout:���Ź���ʱʱ��,��λ����,С�ڵ���0����رտ��Ź�����
// stopMode:��ʱֹͣģʽ,1:����ֹͣ,0:������ִ����Ϻ�ֹͣ
// groupID:��ʱ���do�����
// doValue:��ʱ���do״̬
MTN_API short __stdcall NMC_SetWatchDog(HAND devHandle,long timeout,short stopMode,short groupID,long doValue);

//------------------------------------------------------------------------------------------------------------
//
//	11.����
//
//------------------------------------------------------------------------------------------------------------
// �˳�����
MTN_API short __stdcall NMC_ClrHandWheel(HAND devHandle);

// ��������
// axis:���,ȡֵ��Χ[0,n]
// ratio:���汶��,ȡֵ��Χ(0,..],��ֵԽ��,��ͬ��������,�������˶�����Խ��
// acc:����ļ��ٶ�
// vel:������ٶ�
// ע���������ź�ԴΪ�������������˿�
MTN_API short __stdcall NMC_SetHandWheel(HAND devHandle,short axis,double ratio,double acc,double vel);


// ѡ�����ָ���ı�����ͨ��
// index:������ͨ�����,�������ͨ��,ȡֵ��Χ[0,n]
//                    �������չ������ͨ��,��256��ʾ��һ����չ������ͨ��,257��ʾ�ڶ���,�Դ�����
MTN_API short __stdcall NMC_SetHandWheelInput(HAND devHandle,short index);

// �������ָ���ı���
// ratio:���汶��,ȡֵ��Χ(0,..]
MTN_API short __stdcall NMC_SetHandWheelRatio(HAND devHandle,double ratio);


//------------------------------------------------------------------------------------------------------------
//
//	12.PT
//
//------------------------------------------------------------------------------------------------------------
// ����PT�˶������ṹ
typedef struct
{
    double smoothDec;		// ֹͣ���ٶ�
    double abruptDec;		// ��ͣ���ٶȣ���ʱ����
    double reserved1[2];	// ����
    long reserved2[4];      // ����
}TPtPara;
// ����PT�˶�����ز��� 
// pPara������,�ο��ṹ����
MTN_API short __stdcall NMC_MtPtSetPara( HAND axisHandle, TPtPara *pPara );

// onOff:		1������פ��ģʽ   0������ˢ��ģʽ(Ĭ��ģʽ)
// loopCount:	ѭ������ ��������פ��ģʽ����Ч
MTN_API short  __stdcall NMC_MtPtSetStatic(HAND axisHandle,short onOff,long loopCount);

// onOff:		1������פ��ģʽ   0������ˢ��ģʽ(Ĭ��ģʽ)
// loopCount:	ѭ������ ��������פ��ģʽ����Ч
MTN_API short  __stdcall NMC_MtPtGetStatic(HAND axisHandle,short *pOnOff,long *pLoopCount);

// ��ѯPT����ʣ��ռ��С
// pSpace:���ص�ʣ��ռ��С
// pUsed: ��ʹ�õĿռ����
MTN_API short  __stdcall NMC_MtPtGetSpace(HAND axisHandle,short *pSpace,short *pUsed);


// PT���ݶ�����
#define MT_PT_NORMAL	(0)
#define MT_PT_STOP		(1)
#define MT_PT_EVEN		(2)

// ��Pt�˶���������ѹ�˶����ݶ�
// count:ѹ������ݶ���
// pPosArray:�����о���
// pTimeArray:������ʱ��
// pTypeArray:������,���궨��
MTN_API short  __stdcall NMC_MtPtPush(HAND axisHandle,short count,double *pPosArray,long *pTimeArray,short *pTypeArray);

// ���PT����
MTN_API short  __stdcall NMC_MtPtBufClr(HAND axisHandle);

// ����Pt�˶�
// otherSynAxCnts�� ������axisHandle ������ͬ������������
// pOtherSynAxArray: ����ͬ�����������ţ�0~N	
// ע��ͬ�������������ͬһ��������
MTN_API short  __stdcall NMC_MtPtStartMtn(HAND axisHandle,short otherSynAxCnts,short *pOtherSynAxArray);


//-------------------------------------------------------------------------------
// 13.���Ծ���λ�ñȽ�
//-------------------------------------------------------------------------------

// ��ȷ����ṹ��
typedef struct
{
	short dimens;
	short compMode;
	short axMask;       
	short src;
	double gateTime;
}TLinearCmpPara;


// ���ܣ����þ�ȷλ�ñȽϵĲ��������������λ�ñȽ�λ������
// dimens:�Ƚϵ�ά�� 1����2
// axisMask��ѡ�Ƚϵ����,��bitѡ��:���ܳ���2��bitͬʱΪ1
// src���Ƚ�Դ��1:������λ��  0���滮λ��
// cmpMode���Ƚϵ�ģʽ��0 ���������λ�ñȽ�,1 ���ԱȽ�,��interval���Ƚ�
// gateTime:�����������
// chn�����ͨ�� Ŀǰֻ֧��0
MTN_API short __stdcall NMC_LinearCompSetParam(HAND devHandle,short dimens, short axisMask,short src,short cmpMode,double gateTime,short chn);


// ��ȡ���ò���
MTN_API short __stdcall NMC_LinearCompGetParam(HAND devHandle,TLinearCmpPara *pLinearCmpPara,short chn);


// ���ܣ����þ�ȷ�Ƚ�λ������
// pStartPos����ʼ�Ƚ�λ�ã�ע�⣺��ʱû��
// pPos :�Ƚϵ�λ�������ַ��
//		 ע�⣺����Ϊ��Ծ��룬��һ��Ϊ�����NMC_LinearCompOnOff����ʱ��λ�õľ��룬�ڶ���Ϊ��Ե�һ��ľ���
// count���Ƚϵ�λ�ø���������ܳ���250������Ƚ����ݹ��࣬����ͨ����ε��õķ�ʽ��ѹ���ݣ�����������
// chn�����ͨ�� Ŀǰֻ֧��0
MTN_API short __stdcall NMC_LinearCompSetData(HAND devHandle,long *pStartPos,long *pPos,long count, short chn);


// ���ܣ����ԱȽ����
// pStartPos����ʼ�Ƚ�λ��
// interval:���ԱȽϼ�ࣨС��32767��
// count: ���ԱȽϴ���
MTN_API short __stdcall NMC_LinearCompInterval(HAND devHandle,long *pStartPos,long interval,long count, short chn);


// ���ܣ���ȷλ�ñȽ�ʹ��
// onOff�� 0 ֹͣ,1���
// chn�����ͨ�� Ŀǰֻ֧��0
MTN_API short __stdcall NMC_LinearCompOnOff(HAND devHandle,short onOff, short chn);


// ���ܣ��Ƚϵ����״̬
// pStatus: 0 δ�����Ƚ� 1 �Ƚ������
// pOutCount������ĸ���,�����������ģʽ�����������������ѯ����
// chn�����ͨ�� Ŀǰֻ֧��0
MTN_API short __stdcall NMC_LinearCompStatus(HAND devHandle,short *pStatus, short *pOutCount,short chn);

//-------------------------------------------------------------------------------
//14.��άλ�õ�Ƚ�
//-------------------------------------------------------------------------------
#define CMP_OUTPUT_CHN_MAX	(3)

// ��άλ�õ�ȽϽṹ��
typedef struct
{
	short outputchn[CMP_OUTPUT_CHN_MAX];		// �Ƚ������ͨ��:-1��ʾ���������
	short outputType[CMP_OUTPUT_CHN_MAX]; 		// �����ʽ0������1����ƽ
	short chnType[CMP_OUTPUT_CHN_MAX];      	// ͨ�����ͣ�0 GPO, 1  GATEͨ��
	short dir1No; 								// ����1 ��λ��Դ��ţ�0~11��
	short dir2No; 								// ����2 ��λ��Դ��ţ�0~11��
	short posSrc; 								// ��λ������ ��0�滮1��������
	short stLevel[CMP_OUTPUT_CHN_MAX];			// ��ƽģʽ�µ���ʼ��ƽ��0��1��
	short gateTime[CMP_OUTPUT_CHN_MAX]; 		// ���巽ʽ����ʱ��:��λms
	short errZone; 								// ����Ƚϵ��ݲ�뾶��Χ��pulse��
} TComp2DimensParam;

// ���ܣ�����2άλ�ñȽϵĲ���
// param: ��ά�Ƚϲ���
// group:���,0 ����1
// chn:����,��Ϊ0
MTN_API short __stdcall NMC_Comp2DimensSetParam(HAND devHandle,short group,TComp2DimensParam *param,short chn);

// ���ܣ���ȡ2άλ�ñȽϵĲ���
// param: ��ά�Ƚϲ���
// group:���,0 ����1
// chn:����,��Ϊ0
MTN_API short __stdcall NMC_Comp2DimensGetParam(HAND devHandle,short group,TComp2DimensParam *param,short chn);

// ���ٶ�άλ�õ�ȽϽṹ��
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
	long reserved[8];							// ������Ĭ��ֵ 0����ʹ�ã�
} TComp2DimensParamEx;

// ���ܣ�����2άλ�ñȽϵĲ���
// param: ��ά�Ƚϲ���
// group:���,0 ����1
// chn:����,��Ϊ0
MTN_API short __stdcall NMC_Comp2DimensSetParamEx(HAND devHandle,short group,TComp2DimensParamEx *param,short chn);

// ���ܣ���ȡ2άλ�ñȽϵĲ���
MTN_API short __stdcall NMC_Comp2DimensGetParamEx(HAND devHandle,short group,TComp2DimensParamEx *param,short chn);


// ���ܣ����ö�ά�Ƚ�����
// pArrayPos:�Ƚ������ַ
// count:λ�õ���,count=0��ʾ����Ѿ���������ݡ�һ�������ѹ��128������
// group:���,0 ����1
// chn:����,��Ϊ0
MTN_API short __stdcall NMC_Comp2DimensSetData(HAND devHandle,short group,long *pArrayPos,short count,short chn);

// ���ܣ�2άλ�ñȽ�ʹ��
// onOff�� 0 ֹͣ,1��� 2�ֶ�
// group:���,0 ����1
// chn:����,��Ϊ0
MTN_API short __stdcall NMC_Comp2DimensOnoff(HAND devHandle,short group,short onOff,short chn);


// ���ܣ�2άλ�ñȽϵ����״̬
// pStatus: 0 δ�����Ƚ� 1 �Ƚ������
// pOutCount������ĸ���
// group:���,0 ����1
// chn:����,��Ϊ0
MTN_API short __stdcall NMC_Comp2DimensStatus(HAND devHandle,short group,short *pStatus, short *pOutCount,short chn);

typedef struct
{
	short sts;				// ����״̬��0 ���� 1 æ
	short reserved1;		// ����
	long freeSpace;			// ������ʣ��ռ�
	long usedSpace;			// ʣ��λ�ñȽϵ�
	long outCount;			// �Ѿ�����ĸ���
	long reserved2[4];		// ����
} TComp2DimensSts;

// ���ܣ�2άλ�ñȽϵ����״̬
// pStatus: ״̬�ṹ��
// group:���,0 ����1
// chn:����,��Ϊ0
MTN_API short __stdcall NMC_Comp2DimensStatusEx(HAND devHandle,short group,TComp2DimensSts *pStatus,short chn);


//-------------------------------------------------------------------------------
//15.��άλ�ñȽ����ͨ�ýӿ�
//-------------------------------------------------------------------------------
// Xάλ�õ�ȽϽṹ��
typedef struct
{
	short dimens; 		                    // ά��
	short axMask;                           // ʹ�õ���,��λ
	short src; 		                        // ��λ������ ��0�滮1��������

	short outCnts; 							// �������
	short outType[CMP_OUTPUT_CHN_MAX]; 		// �����ʽ0������1����ƽ
	short outChnType[CMP_OUTPUT_CHN_MAX];	// ͨ�����ͣ�0 GPO, 1  GATEͨ��
	short outIndex[CMP_OUTPUT_CHN_MAX];     // GPO��0~63  GATE��0
	short outStLevel[CMP_OUTPUT_CHN_MAX];   // ��ƽģʽ�µ���ʼ��ƽ��0��1��
	short outGateTime[CMP_OUTPUT_CHN_MAX]; 	// ����ģʽ�µ�����ʱ��:��λms
	short errZone; 							// ����Ƚϵ��ݲ�뾶��Χ��pulse��
} TCompXDimensParam;

// ���ܣ�����Xάλ�ñȽϵĲ���
// param: Xά�Ƚϲ���
// ch:���,0~2
MTN_API short __stdcall NMC_CompXDimensSetParam(HAND devHandle,TCompXDimensParam *param,short chn);

// ���ܣ���ȡXάλ�ñȽϵĲ���
// param: ��ά�Ƚϲ���
// chn:���
MTN_API short __stdcall NMC_CompXDimensGetParam(HAND devHandle,TCompXDimensParam *param,short chn);

// ���ܣ�����Xάλ�ñȽϵ����ģʽ
// outMode: ���ģʽ 0��ͬʱ���ģʽ 1�� ��ѭ���ģʽ
// ch:���,0~N
MTN_API short __stdcall NMC_CompXDimensSetCmpOutMode(HAND devHandle,short outMode ,short chn);

// ���ܣ�����Xά�Ƚ�����
// pArrayPos:�Ƚ������ַ,ע������1ά�Ƚ�,��pPosArray����һά�����ַ,����2ά�Ƚ�,��pPosArrayӦ����2ά�����ַ
// outValue
// count:λ�õ���,ע����Ϊ2ά����Ƚ�ʱ,ÿ��������Ϊһ������
// ch:���,0~N
// ע�����ṹ�嶨���IO,ͬʱ���
MTN_API short __stdcall NMC_CompXDimensSetData(HAND devHandle, long *pPosArray, short count, short chn);

// ���ܣ�Xάλ�ñȽ�ʹ��
// onOff�� 0 ֹͣ,1���
// chn�� ���
MTN_API short __stdcall NMC_CompXDimensOnoff(HAND devHandle,short onOff, short chn);

// ���ܣ�Xάλ�ñȽϵ����״̬
// pStatus: 0 δ�����Ƚ� 1 �Ƚ������
// pOutCount������ĸ���
// chn�����
MTN_API short __stdcall NMC_CompXDimensStatus(HAND devHandle,short *pStatus, short *pOutCount,short chn);

//-------------------------------------------------------------------------------
//16.����ϵ���ת�������ݻ�е�ṹ����ת����
//-------------------------------------------------------------------------------
// ���ܣ�ʹ����תת������
//       �û������ǰ���ֱ����������,ʵ�ʼӹ���һ����ת���ϼӹ�,�����ô˹���
// rotAxisNo����ת�����
// angleRadEqual����ת������ת����ϵ��
// firstAxisInitPos����ת����,X���λ��
// secAxisInitPos����ת����,Y���λ��
MTN_API short  __stdcall NMC_CrdSetTransRotate(HAND crdHandle,short rotAxisNo,
								double angleRadEqual,long firstAxisInitPos,long secAxisInitPos);

// ���ܣ��ر���תת������
MTN_API short  __stdcall NMC_CrdDelTransRotate(HAND crdHandle);

// ���ܣ�ʹ�ܼ�����ת������
//       �û������ǰ���ֱ����������,ʵ�ʻ�е������һ����ת���һ��������
//������	rotAxNo����ת�����
//		transAxNo��ƽ�������
//		rotEquiv����ת�ᵱ��,2PI/���һȦ������
MTN_API short  __stdcall NMC_CrdSetTransPolar(HAND crdHandle, short rotAxNo,short transAxNo, double rotEquiv);

// ���ܣ��������趨�ļ�����λ�ò��ҽ���Ȧ�����㴦�����õ���PTP���е�ָ��λ�ã�
//������	xPos:������ϵ��X����λ��
//		yPos:������ϵ��Y����λ��,�����˶�����5000,5000����λ��,���൱����ת��ת��45�Ƚ�,�������˶�������2*5000��λ��
//		rotVel:��ת�ٶ�
//		transVel:�����ٶ�
MTN_API short  __stdcall NMC_CrdRunToPolarPos(HAND crdHandle,double xPos,double yPos,double rotVel,double transVel);

// ���ܣ��������趨�ļ�����Ƕ�λ�ã����õ���PTP���е�ָ��λ�ã�
//������	theta:��ת��Ŀ��Ƕ�
//				vel:��ת�ٶ�
//				clrRoundFlag:�Ƿ����Ȧ��
MTN_API short  __stdcall NMC_CrdRunToPolarTheta(HAND crdHandle,double theta,double vel,short clrRoundFlag);

// ���ܣ����ټ�������ͣ�ֻ�ָ�ֱ������ϵ��
MTN_API short  __stdcall NMC_CrdDelTransPolar(HAND crdHandle);

// XYZA�������ýӿ�
// ����XYZA��ӳ�����
// pAxisMapArray[0]~[3]�ֱ��ӦX��Y��Z��A
MTN_API short  __stdcall NMC_CrdSetTransXYZA(HAND crdHandle, short *pAxisMapArray );

// ����XYZA���ͣ��ع�XYZ�ṹ
MTN_API short  __stdcall  NMC_CrdDelTransXYZA(HAND crdHandle);

// �󹤾߲���
// deltaTheta����0������������ת���ĽǶ�ֵ
// deltaX����תdeltaTheta�ǶȺ�����У����ͬһ��λ�ú�X�������ƶ���
// deltaY����תdeltaTheta�ǶȺ�����У����ͬһ��λ�ú�Y�������ƶ���
// pToolX: ���ߵ�Xֵ
// pToolY: ���ߵ�Yֵ
MTN_API short  __stdcall NMC_CrdSetXYZAToolCalc(HAND crdHandle, double 	deltaTheta,long deltaX,long deltaY,long *pToolX,long *pToolY );


// ����XYZA���Ͳ���
// pulse2Rad: A���ÿ�������Ӧ�Ļ���ֵ
// toolX�����ߵ�Xֵ
// toolY: ���ߵ�Yֵ
MTN_API short  __stdcall NMC_CrdSetXYZAPara(HAND crdHandle, double	pulse2Rad,long toolX,long toolY );

// ����XYZA���Ͳ���
// pPulse2Rad:A���ÿ�������Ӧ�Ļ���ֵ
// pToolX:���ߵ�Xֵ
// pToolY:���ߵ�Yֵ
MTN_API short  __stdcall NMC_CrdGetXYZAPara(HAND crdHandle, double	*pPulse2Rad,long *pToolX,long *pToolY );

// ����ѹ��岹���ݵ�λ���Ƿ���Ҫ�ؽڵ��ѿ���������ת��
MTN_API short __stdcall NMC_CrdSetXYZAJointTransCrdPos( HAND crdHandle, short isTrans );

//-------------------------------------------------------------------------------
//17.�ṹ���ʼ������
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

// ��������״̬,ͬʱ���
MTN_API short  __stdcall NMC_MtClrErrorEx(HAND axisHandle,short count);

// ���DO,16λ
// bitsFlag,0:��16λ,1����16λ
MTN_API short  __stdcall NMC_SetDOGroupEx( HAND devHandle, long value, short groupID,short bitsFlag) ;

//-------------------------------------------------------------------------------
//18.�ջ�
//-------------------------------------------------------------------------------

// PID����
typedef struct
{
    float kp;											// ����ϵ��
    float ki;											// ����ϵ��
    float kd;											// ΢��ϵ��
    float kvff;											// �ٶ�ǰ��ϵ��
    long integralLimit;                                 // ���ֱ��ͼ���
    long derivativeLimit;                               // ΢�ֱ��ͼ���
    short outLimit;                                     // ������ͼ���
} TPidPara;

// Dac����
typedef struct
{
	short inverse;			// ��ѹ�Ƿ�ȡ��
	short bias;				// Dac��Ư
	short dacLmt;			// Dac�������ֵ
}TDacMotor;

// ���õ���ջ����Ƶ�DA����,����DAͨ���Ķ�Ӧ
MTN_API short  __stdcall NMC_MtSetCloseLoopDac (HAND axisHandle,TDacMotor *pDacPara);

// ��ȡ����ջ����Ƶ�DA����
MTN_API short  __stdcall NMC_MtGetCloseLoopDac (HAND axisHandle,TDacMotor *pDacPara);

// ���õ���Ŀ���ģʽ��Ĭ��ʹ�ö�Ӧ��ı�������Ϊ���뷴��,��Ӧ��ŵ�DAC��Ϊ���
// �ջ�ģʽ��,�ȵ���NMC_SetCloseLoopDacָ��
//mode: 0 �������  1 DA�ջ����ƣ�Ĭ��Ϊ�������
MTN_API short  __stdcall NMC_MtSetCtrlMode(HAND axisHandle,short mode);

// ��ȡ����Ŀ���ģʽ
MTN_API short  __stdcall NMC_MtGetCtrlMode(HAND axisHandle,short *pMode);


//���ö�Ӧ��ŵ�PID����
MTN_API short  __stdcall NMC_MtSetPIDPara(HAND axisHandle,short index, TPidPara *pidPara);

// ��ȡ��Ӧ��ŵ�PID����
MTN_API short  __stdcall NMC_MtGetPIDPara(HAND axisHandle,short index, TPidPara *pPidPara);

// ����ʹ������PID
MTN_API short  __stdcall NMC_MtSetPIDIndex(HAND axisHandle,short index);

// ��ȡ��ʹ�õ�PID���
MTN_API short  __stdcall NMC_MtGetPIDIndex(HAND axisHandle,short *pIndex);

//-------------------------------------------------------------------------------
//19.�߼�BufIo������ü�����
//-------------------------------------------------------------------------------
// BufIo����������
#define MAX_ADV_BUFIO_GROUP	2

// �߼�BufIo�������
typedef struct
{
	// �����
	short outType;				// ������ͣ�0��ͨ�������1��Gate�źţ���������
	short outGroup;				// ����飬ȡֵ��Χ[0,n]
	short outIndex;				// �����ţ�ȡֵ��Χ[0,n]
	short outSns;				// ��Ч��ƽ,0:�͵�ƽ��Ч��1���ߵ�ƽ
	
	// �ź�
	short pulseMode;		// 0����ƽ�����1���������
	short reserved1;		// ����
	long  pulseOnTime;		// ��Ч��ƽʱ�䣨���������ʽ����Ч������λ��΢��
	long  pulseOffTime;		// ��Ч��ƽʱ�䣨���������ʽ����Ч������λ��΢��
	
	unsigned char reserved[32];	// ����
}TAdvBufIoParam;

// ����BufIo�������
MTN_API short  __stdcall NMC_AdvBufIoSetParam(HAND devHandle,TAdvBufIoParam *pPrm,short ch);

// ��ȡBufIo�������
MTN_API short  __stdcall NMC_AdvBufIoGetParam(HAND devHandle,TAdvBufIoParam *pPrm,short ch);

// ���������ø߼�BufIo�����Ч���˶�һ�ξ��������ض�״̬��
// outLength:���룬��λ������
// value: ����ģʽ����������������ƽ��ʽ�������塣
// ch:����飬ȡֵ��Χ��[0,MAX_ADV_BUFIO_GROUP)
MTN_API short  __stdcall NMC_CrdAdvBufIoOnAfterLen(HAND crdHandle,long segNo,
	long outLength,long value,short ch);

// ���������ø߼�BufIo�ر������������ȫ���˶�����ǰ��ǰһ�ξ�������ض�״̬��
// outLength:���룬��λ������
// ch:����飬ȡֵ��Χ��[0,MAX_ADV_BUFIO_GROUP)
MTN_API short  __stdcall NMC_CrdAdvBufIoOffBeforeLen(HAND crdHandle,long segNo,long outLength,short ch );
	
// �������ø߼�BufIo���
// value: ����ģʽ����������������ƽ��ʽ��0:�رգ�1:�򿪡�
// ch:����飬ȡֵ��Χ��[0,MAX_ADV_BUFIO_GROUP)
MTN_API short  __stdcall NMC_AdvBufIoOut(HAND devHandle,long value,short ch);

// ��ȡBufIo���������
// pOutCout:����������
// ch:����飬ȡֵ��Χ��[0,MAX_ADV_BUFIO_GROUP)
MTN_API short  __stdcall NMC_AdvBufIoGetPulseCnt(HAND devHandle,long *pOutCout,short ch);

// DO����������ͨ����
#define MAX_NUM_DOBIT_PULSE		4

// DO�������
// doType:DO����,0��ͨ���������������
// doIndex:DO��ţ�ȡֵ��Χ[0,n]
// highLevelTime:�ߵ�ƽ��ȣ���λ:us
// lowLevelTime:�͵�ƽ��ȣ���λ:us
// outCount:����������
// firstLevel:0��������͵�ƽ��1��������ߵ�ƽ
// ch:�������ͨ����,ȡֵ��Χ:[0,MAX_NUM_DOBIT_PULSE-1]
MTN_API short  __stdcall NMC_DoBitPulseEnable(HAND devHandle,short doType,short doIndex,
	long highLevelTime,long lowLevelTime,long outCount,short initialLevel,short ch);

// �ر�DO�������
MTN_API short  __stdcall NMC_DoBitPulseDisable(HAND devHandle,short ch);

// DO������� ����������
MTN_API short  __stdcall NMC_CrdBufDoBitPulseEnable(HAND crdHandle, long segNo,short doType,short doIndex,
	long highLevelTime,long lowLevelTime,long outCount,short initialLevel,short ch);

// �ر�DO�����������������
MTN_API short  __stdcall NMC_CrdBufDoBitPulseDisable(HAND crdHandle, long segNo,short ch);

//-------------------------------------------------------------------------------
//20.ģ��������
//-------------------------------------------------------------------------------

// ����DAC��ģ���������ͨ����ģʽ
// ch:ģ����ͨ����,ȡֵ��Χ[0,n]
// mode:ģ���������Χ,0:0~5V, 1:0~10V, 2: 0~10.8V, 3:+/-5V, 4:+/-10V, 5:+/-10.8V,������Ч��Ĭ��Ϊ4
MTN_API short __stdcall NMC_SetDacMode(HAND devHandle,short ch, short mode);

// ��ȡDAC��ģ���������ͨ����ģʽ
// ch:ģ����ͨ����,ȡֵ��Χ[0,n]
// pMode:���ص�ģ���������Χ�趨ֵ
MTN_API short __stdcall NMC_GetDacMode(HAND devHandle,short ch,short *pMode);

// ����Adc����
// ch:ģ����ͨ����,0~7��ʾ��ͨ���ϵ�AD��256����ʾ��չAD
// mode:ģ������Χ,0:0~5V, 1:0~10V, 2: 0~10.8V, 3:+/-5V, 4:+/-10V, 5:+/-10.8V,Ĭ��Ϊ4
// ע�⣺Ŀǰֻ֧��+/-10V
// filterCoe:�˲�ϵ����ȡֵ��Χ[0,64],0��ʾȡ��Adc�˲�����λ:ms��Ĭ��ֵΪ0
MTN_API short __stdcall NMC_SetAdcMode(HAND devHandle,short ch,short range,short filterCoe);

// ��ȡAdc����
// ch:ģ����ͨ����,0~7��ʾ��ͨ���ϵ�AD��256����ʾ��չAD
// pMode:ģ������Χ
// pFilterCoe:�˲�ϵ��
MTN_API short __stdcall NMC_GetAdcMode(HAND devHandle,short ch,short *pRange,short *pFilterCoe);

// ����DAC��ģ������������ֵ
// ch:ģ����ͨ����,ȡֵ��Χ[0,n]
// dacValue:ģ�������ֵ,ȡֵ��Χ[-32768,32767],��ӦDAC�����Χ
MTN_API short __stdcall NMC_SetDac(HAND devHandle,short ch,short dacValue);

// ��ȡDAC��ģ������������ֵ
// ch:ģ����ͨ����,ȡֵ��Χ[0,n]
// pDacValue:����ģ�������ֵ,ȡֵ��Χ[-32768,32767],��ӦDAC�����Χ
MTN_API short __stdcall NMC_GetDac(HAND devHandle,short ch,short *pDacValue);

// ��ȡADC��ģ�������룩ֵ
// ch:ģ����ͨ����,ȡֵ��Χ[0,n]
// pAdcValue:����ģ��������ֵ��ȡֵ��Χ[-32768,32767],��ӦAdc�����ѹ��Χ
MTN_API short __stdcall NMC_GetAdc(HAND devHandle,short ch,short *pAdcValue);

// ����ģ���������ƫ��ֵ
// ch:ģ����ͨ���ţ�[0,n]��ʾ����,[256,n]��ʾ��չģ����ͨ��
// bias:DAC���ƫ��ֵ
MTN_API short  __stdcall NMC_SetDacBias(HAND devHandle,short ch,short bias);

// ��ȡģ���������ƫ��ֵ
// ch:ģ����ͨ���ţ�[0,n]��ʾ����,[256,n]��ʾ��չģ����ͨ��
// pBias:DAC���ƫ��ֵ
MTN_API short  __stdcall NMC_GetDacBias(HAND devHandle,short ch,short *pBias);

// ����ģ��������ļ���ֵ
// ch:ģ����ͨ���ţ�[0,n]��ʾ����,[256,n]��ʾ��չģ����ͨ��
// maxVal:������ֵ
// minVal:�����Сֵ
MTN_API short  __stdcall NMC_SetDacLmt(HAND devHandle,short ch,short maxVal,short minVal);

// ��ȡģ��������ļ���ֵ
// ch:ģ����ͨ���ţ�[0,n]��ʾ����,[256,n]��ʾ��չģ����ͨ��
// pMaxVal:������ֵ
// pMinVal:�����Сֵ
MTN_API short  __stdcall NMC_GetDacLmt(HAND devHandle,short ch,short *pMaxVal,short *pMinVal);

//-------------------------------------------------------------------------------
//21.scara
//-------------------------------------------------------------------------------
// ��ؽṹ��
typedef struct
{
    double arm1Len;         // ��1������λ���û���λ
    double arm2Len;         // ��2������λ���û���λ
    double pitch;           // Z���˿�˽ھ࣬��λ���û���λ
    double reserved[16];    // ����������Ϊ0
}TScaraMechPara;

typedef struct
{
    long encBits;          // �ؽڵĵ��һȦ��������
    long zeroPulsePos;     // �ؽ����λ�õ�����λ��
    float posLmt;           // �ؽڵ�����λλ�ã���λ ��
    float negLmt;           // �ؽڵĸ���λλ�ã���λ ��
    float ratio;            // ���ٱ�
    float maxVel;           // ���ؽ��ٶ�  ����λ  ��/s
    float maxAcc;           // ���ؽڼ��ٶ�: ��λ ��/s^2
	float reserved1;		// ����������Ϊ0
    double reserved[8];	    // ����������Ϊ0
}TScaraJiontPara;

// ���û�е����
MTN_API short  __stdcall NMC_CrdSetScaraMechPara(HAND crdHandle,TScaraMechPara *pScaraMechPara);

// ��ȡ��е����
MTN_API short  __stdcall NMC_CrdGetScaraMechPara(HAND crdHandle,TScaraMechPara *pScaraMechPara);

// ���ùؽڲ���
MTN_API short  __stdcall NMC_CrdSetScaraJiontPara(HAND crdHandle,short jointNo,TScaraJiontPara *pScaraJiontPara);

// ��ȡ�ؽڲ���
MTN_API short  __stdcall NMC_CrdGetScaraJiontPara(HAND crdHandle,short jointNo,TScaraJiontPara *pScaraJiontPara);

// ����crd����Ϊscara
// jointNum: 2/3
// jointAxNoArray ���鳤��Ϊ4�����õ���������Ϊ0
MTN_API short  __stdcall NMC_CrdSetTransScara(HAND crdHandle, short jointNum, short *jointAxNoArray );

// ����scara����
MTN_API short  __stdcall NMC_CrdDelTransScara(HAND crdHandle);

typedef struct
{
   short masterAxNo;	// �������ţ�0~N
   short useEnc;	// ʹ�ñ�������0���滮��1��������
   short dirReverse;    // �����᷽��ȡ����0����ȡ����1��ȡ��

   short followedAxNo;   // �����ĸ��ᣬ0:X��1:Y
   double posCoe;	 // �����ᵱ���͸�����ĵ������������浱�� / �����ᵱ��
  
   long  reserved2[16];  // ����������Ϊ0
}TFlyFollowPara;

// ����crd���÷��и���ģʽ
// *pFlyFollowPara ģʽ����
MTN_API short  __stdcall NMC_CrdSetFlyFollow(HAND crdHandle, TFlyFollowPara *pFlyFollowPara);

// ���ٷ��и���
MTN_API short  __stdcall NMC_CrdDelFlyFollow(HAND crdHandle);

// ��ѯ�Ƿ�����ͣ���Ѿ�������״̬
// sts : 1��ʾ������  0��ʾû�и�����
MTN_API short  __stdcall  NMC_CrdGetFlyFollowUpSts(HAND crdHandle,short *pSts);

// ���������÷��и��湦�ܵ������͹ر�
// enable:0:�رո���
//        1:�������
//        2:��ͣ����
MTN_API short  __stdcall NMC_CrdBufEnableFlyFollow(HAND crdHandle, long segNo,short enable);

// �����������и�������£��ƶ�����еλ��
MTN_API short  __stdcall NMC_CrdBufFlyFollowLineXY(HAND crdHandle, long segNo,long *tgtPos,double acc,double vel);

// ���������ȴ�����������
// usedSpace:�ȴ����������ݶ��������ڵ���usedSpace��������ִ�У�
MTN_API short  __stdcall NMC_CrdBufWaitData(HAND crdHandle, long segNo,long usedSpace);

// ������������ϵ�������
// crdAxMaster:��������ᣬȡֵ��Χ[0,n],Ϊ����ϵ�ڵ��ᣬ0:X�ᣬ1:Y�ᣬ2:Z�ᣬ3:A��
// axFllowMask:����Ĵ�������
// onOff������������߹رո���,1:�������棬0:�رո��棬��ʱ��crdAxMaster��axFllowMask���ԣ�������ֵ
MTN_API short  __stdcall NMC_CrdBufAxFollowOnOff(HAND crdHandle, long segNo,short crdAxMaster,short axFllowMask,short onOff);

//-------------------------------------------------------------------------------
//22.����ϵ���汣��ָ��
//-------------------------------------------------------------------------------
#define CRD_INTERF_GROUP_MAX		(2)

// ��������ϵ�ĸ��汣��
// groupNo: ��������ϵ��ţ�Ŀǰֻ����������ϵ�����Ը�ֵΪ0��
// mode:	0:����ģʽ�����ָ��棬������ϵ��ֹͣ  1������ģʽ�����ָ��棬����һ��ֹͣ���뿪
MTN_API short  __stdcall NMC_SetMvProtect(HAND devHandle,short groupNo,short mode);

// ȡ������ϵ�ĸ��汣��
// groupNo: ��������ϵ��ţ�Ŀǰֻ����������ϵ�����Ը�ֵΪ0��
MTN_API short  __stdcall NMC_DelMvProtect(HAND devHandle,short groupNo);

// ��ȡ����ϵ�ĸ���״̬
// groupNo: ��������ϵ��ţ�Ŀǰֻ����������ϵ�����Ը�ֵΪ0��
// pSts:	0 û���������湦�� 1  û�г��ָ���  2 ���淢��
MTN_API short  __stdcall NMC_GetMvProtectSts(HAND devHandle,short groupNo,short *pSts);

typedef struct
{
   short crdNo[2];		// ��Ҫ���汣����������ϵ��
   short crdAxNo[2];	// ����ϵ�ĸ������,ָXYZ����һ����X:0  Y:1    Z:2��
   short moveDir[2];    // ��������ֱ��������Сʱ���˶�����1������ -1������

   long orgDis;			// ������ϵ��crdAxNo����ԭ��ʱ�ľ���
   long mvProtectDis;	 // ����ı�������   
   long safeWaitPos;	// modeΪ����ģʽʱ����������Ҫֹͣ���ĵȴ�λ�ã�modeΪ0ʱ��Ч��
   double mvToSafeAcc;  // �˶����ȴ�λ�õ��ƶ����ٶ�
   double mvToSafeVel;  // �˶����ȴ�λ�õ��ƶ��ٶ�
   short stopCrdNo;		// modeΪ����ģʽʱ����Ҫֹͣ������ϵ�ţ�modeΪ0ʱ��Ч��
   short reserved[3];      // ��������
   
}TMvProtectPara;

// ��������ϵ�ĸ��汣������
// groupNo:	��������ϵ��ţ�Ŀǰֻ����������ϵ�����Ը�ֵΪ0��
// pCrdInterfProtectPara�� �������
MTN_API short  __stdcall NMC_SetMvProtectMode01Para(HAND devHandle,short groupNo,TMvProtectPara *pMvProtectPara);

// ��ȡ����ϵ�ĸ��汣������
// groupNo:	��������ϵ��ţ�Ŀǰֻ����������ϵ�����Ը�ֵΪ0��
// pCrdInterfProtectPara�� �������
MTN_API short  __stdcall NMC_GetMvProtectMode01Para(HAND devHandle,short groupNo,TMvProtectPara *pMvProtectPara);


//-------------------------------------------------------------------------------
//23.������ָ��
//-------------------------------------------------------------------------------
typedef struct
{
    short crdSts;          // ����ϵ״̬
    short axSts[3];        // ����ϵ�����״̬
    long  prfPos[3];       // �û�����ϵ�µĹ滮λ��
    long  axisPos[3];      // ��е����ϵ�µĹ滮λ��
    long  encPos[3];        // ������λ��
    long  userSeg;         // ���еĻ������κ�
    double  prfVel;         // �˶��ٶ�
    long  gpDi;             // ͨ������0~31
    long  gpDo;             // ͨ�����0~31
    short  motDi[3];        // ��λ��ԭ�㡢��������ο�ר��IOλ����( ���� BIT_AXMTIO_LMTN )
    short  reserved;        // ����
    long crdFreeSpace;      // ������ʣ��ռ�
    long reserved2;
}TPackedCrdSts3;
// ����ϵ�˶�ģʽ��,�����ȡ������״̬
MTN_API short __stdcall NMC_CrdGetStsPack3( HAND crdHandle, TPackedCrdSts3 *pPackSts );

// ����ϵģʽ��,��ȡ�����Ļ�е����λ��
// cnts: ��ȡ����,1~N
// pPos��������������
MTN_API short __stdcall NMC_CrdGetAxisPos(HAND crdHandle,short cnts, long *pPosArray);

// ��ȡ�滮λ��XYZ
// cnts: ��ȡ����,1~N
// pPosArray��������������
MTN_API short __stdcall NMC_CrdGetPrfPos( HAND crdHandle, short cnts, long *pPosArray );

// ��ȡ������λ��
// cnts: ��ȡ����,1~N
// pPos�������������顣
MTN_API short __stdcall NMC_CrdGetEncPos  ( HAND crdHandle, short cnts, long *pPosArray );

// ��ȡ����ϵ�ϳ��ٶ�
// pVel������ϵ�ϳ��ٶ�
MTN_API short __stdcall NMC_CrdGetVel(HAND crdHandle,double *pVel);

// ������ϵ��
// pCrdHandle����������ϵ����
MTN_API short __stdcall NMC_CrdOpen(HAND devHandle, PHAND pCrdHandle );

// ���ἱͣ
// ע���˶��ᰴ�趨�ļ�ͣ���ٶ�ֹͣ�����û������,�������ֹͣ��
MTN_API short __stdcall NMC_MtEstp    ( HAND axisHandle );

// ��ȡ�����״̬��8�ᣩ
typedef struct
{
	long prfPos[8];     // �滮λ��
	long encPos[8];     // ʵ��λ��
	float prfVel[8];    // �滮�ٶ�
	long motionIO[8];   // ��ר��IO
	short sts[8];       // ��״̬
	long gpo;            // ͨ�����
	long gpi;            // ͨ������
}TAxisStsPack8;
// �����ȡ8�����״̬,�ӵ�һ���Ὺʼ��ȡ
// axisFirstHandle : ��һ������
// pPackSts: �����״̬����,�ο��ṹ�嶨��
MTN_API short  __stdcall NMC_MtGetStsPack8  ( HAND axisFirstHandle, TAxisStsPack8 *pPackSts );

// ֱ�߲岹
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// crdAxMask:�������,��λ��ʾ
// pTgPosArray��Ŀ��λ������,����Ϊ3
MTN_API short __stdcall NMC_CrdLineXYZ(  HAND crdHandle,  long segNo, short crdAxMask,long *pTgPosArray, double endVel, double vel,double synAcc );

// ��ȡͨ�����(��ͨ��,֧�ֳ���32λ)
// groupID:DO��,ȡֵ��Χ[0,n],,0: ����DO31~DO0, 1: ����DO63~DO32,����ָ��չIOģ��
// pDoValue: ����ͨ�������������1, �ߵ�ƽ,0,�͵�ƽ
MTN_API short  __stdcall NMC_GetDO( HAND devHandle, short groupID, long *pDoValue);

// ����ͨ�����(��ͨ��,֧�ֳ���32λ)
// groupID:DO��,ȡֵ��Χ[0,n],������Ҫ���������Ƿ���ڶ������������
// value: ����ͨ�������������1, ����ߵ�ƽ,0,����͵�ƽ
MTN_API short  __stdcall NMC_SetDO( HAND devHandle, short groupID, long value ) ;

// ��ͨ������(��ͨ��,֧�ֳ���32λ) 
// groupID:DI��,ȡֵ��Χ[0,n],0: ����DI31~DI0, 1: ����DI63~DI32,����ָ��չIOģ��
// pInValue: ͨ������������ֵ��1, �ߵ�ƽ,0,�͵�ƽ
MTN_API short __stdcall NMC_GetDI( HAND devHandle, short groupID, long *pInValue );

// ������λ���������Ƿ�ֹͣ�˶�
// posEn��������λ������������,1Ϊ����,0Ϊ��ֹ
// negEn: ������λ������������
MTN_API short  __stdcall NMC_MtLmtOnOff    ( HAND axisHandle, short posSwt, short negSwt );

// ������λ���ش�����ƽ
// posSwt��������λ������ƽ����,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
// negSwt: ������λ������ƽ����
MTN_API short  __stdcall NMC_MtLmtSns      ( HAND axisHandle, short posSwt, short negSwt );

// ����ԭ�㿪�ش�����ƽ��ע�⣺����ĵ�ƽ���ò���Ӱ�첶��ĵ�ƽ
// sns��ԭ���ƽ����,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
MTN_API short  __stdcall NMC_MtHomeSns( HAND axisHandle, short sns);

// ��ȡԭ�㿪�ش�����ƽ
// pSns����ǰ��ԭ���ƽ����,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
MTN_API short  __stdcall NMC_MtGetHomeSns( HAND axisHandle, short *pSns);

// �����ŷ����������Ƿ�ֹͣ�˶�
// swt���ŷ���������������������,1Ϊ����,0Ϊ��ֹ����Ĭ��Ϊ�ߵ�ƽ������
MTN_API short  __stdcall NMC_MtAlarmOnOff  ( HAND axisHandle, short swt );

// �����ŷ��������ص�ƽ
// swt���ŷ�����������ƽ����,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
MTN_API short  __stdcall NMC_MtAlarmSns    ( HAND axisHandle, short swt );

// ��ȡ�����״̬��12�ᣩ
typedef struct
{
	long prfPos[12];     // �滮λ��
	long encPos[12];     // ʵ��λ��
	float prfVel[12];    // �滮�ٶ�
	long motionIO[12];   // ��ר��IO
	short sts[12];       // ��״̬
	long gpo;            // ͨ�����
	long gpi;            // ͨ������
}TAxisStsPack12;
// �����ȡ12�����״̬,�ӵ�һ���Ὺʼ��ȡ
// axisFirstHandle : ��һ������
// pPackSts: �����״̬����,�ο��ṹ�嶨��
MTN_API short  __stdcall NMC_MtGetStsPack12  ( HAND axisFirstHandle, TAxisStsPack12 *pPackSts );

//------------------------------------------------------------------------
//                                                     
//  24.�Զ�״̬����
//                                                   
//------------------------------------------------------------------------
#define AUTO_RTN_MAX_AXIS  12
// �������״̬�ṹ
typedef struct
{
    short          mtSts[12];          // ����״̬
    short          mtMio[12];          // ����ר��IO
	long           mtPrfPos[12];       // ����滮λ��
    long           mtEncPos[12];       // ����ʵ��λ��
	float          mtPrfVel[12];       // ����滮�ٶ�

    short          crdSts[2];          // ����ϵ״̬
	float          crdPrfVel[2];	   // ����ϵ�˶��ٶ�
	long           crdUserSeg[2];      // ����ϵ���еĻ������κ�
	long           crdFreeSpace[2];    // ����ϵ������ʣ��ռ�
    long           crdUsedSpace[2];    // ����ϵ������ʹ�ÿռ�

    long           gpi;                // ͨ������
    long           gpo;                // ͨ�����
    short          reserved[32];       // Ԥ��

}TAutoRtnPackedSts;

// ���������Զ�״̬����
// mode1 : ������Щ״̬�������أ�0���̶�ʱ�����ڷ��أ�Ĭ�ϣ�; 1������+��״̬�仯������ϵ״̬�仯��
// mode2 : ����
// cycleInMs: ���ڣ���λms��ȡֵ5~10000������ֵ100ms��
// port: �˿ڣ�д0��������޸ģ�
// hostTag : ��λ����ǩ��д0��������޸ģ�
MTN_API short __stdcall NMC_DevAutoRtnSet( HAND devHandle, long mode1, long mode2, long cycleInMs, long port, long hostTag );

// ���ý����Զ�״̬����
MTN_API short __stdcall NMC_DevAutoRtnClr( HAND devHandle );

// ͬ����
// ��֮ǰ��״̬������������Ժ��������ͬ��ָ��ͺ��״̬
// hostTag : ��λ����ǩ��д0
MTN_API short __stdcall NMC_DevAutoRtnSyn( HAND devHandle, long hostTag );

// ��״̬
// packedSts : ���״̬
MTN_API short __stdcall NMC_DevAutoRtnGet( HAND devHandle, TAutoRtnPackedSts * packedSts, short *pReady );

// ����PTPλ�ñȽ����
// comparaPos�� Ŀ��λ�ã���λ�� ����
// upDateVel���ȽϺ�ĸ����ٶ� pulse/ms
MTN_API short __stdcall NMC_MtSetPtpComparePara( HAND axisHandle,short dir, long comparaPos, double upDateVel);

// ��ȡPTP�Ƚ����״̬
MTN_API short __stdcall NMC_MtGetPtpCompareSts( HAND axisHandle,short *pIsCompareActive,short *pIsCompareOut);

//------------------------------------------------------------------------
//                                                     
//  Group 25 : ��λ�Զ��շ�
//                                                   
//------------------------------------------------------------------------

// �������õ�λ�Զ��շ�
MTN_API short __stdcall NMC_DevAsynCommSet( HAND devHandle, unsigned long delayInMs );

// ���ùرյ�λ�Զ��շ�
MTN_API short __stdcall NMC_DevAsynCommClr( HAND devHandle );

// ���������Զ�״̬����
MTN_API short __stdcall NMC_DevAsynGetSts( HAND devHandle, TAutoRtnPackedSts * packedSts, short *pReady );

// �����λ�˶�     
MTN_API short __stdcall NMC_DevAsynAbsMoveType1( HAND axisHandle, float acc,float dec,float vel,
    short smooth,long arrivalBand,long stableTime,long tgtPos);

// ����Do
MTN_API short __stdcall NMC_DevAsynSetDoBit( HAND devHandle, short bitIdx,short setValue);

//------------------------------------------------------------------------
//                                                     
//  Group 26 : ����һάλ�ñȽ�
//                                                   
//------------------------------------------------------------------------

#define CMP_HS1DIMENS_CHN_MAX	(4)         // ���֧���ĸ�ͨ��
#define CMP_HS1DIMENS_POS_MAX	(128)         // ÿ��ͨ�����֧��8��λ�õ�

// һά����λ�ñȽϲ����ṹ
typedef struct
{
short dirNo;            // ������Դ��0~7������Ӧ��0~7�ı�������
short out1StLevel;      // out1��ʼ��ƽ��0��1��
short out2StLevel;      // out2��ʼ��ƽ��0��1��
short reserved;         // ����
long out1Width;         // out1�����ȣ�0~65535,��λus
long out2Width;         // out2�����ȣ�0~65535,��λus
long out2Delay;         // out2��ʱ��0~65535,��λus
} TCompHs1DimensParam;

// ���ܣ����ø���1άλ�ñȽϵĲ������Ƚϱ�������
// param: һά�Ƚϲ���
// chn��ͨ����,��Χ0~3
// ע��1)��Ҫ�����ñ�����ģʽ���������ⲿ���������ڲ�������
//???? 2)�Ƚ��������λ����ο�Ӳ���ֲᡣ
//???? 3)out1�Ƚ�λ�õ����������, out2��λ����ʱ�����
MTN_API short __stdcall  NMC_CompHs1DimensSetParam(HAND devHandle, TCompHs1DimensParam *param,short chn );

// ���ܣ���ȡ����1άλ�ñȽϵĲ���
// param, chn��ͬ��
MTN_API short __stdcall NMC_CompHs1DimensGetParam(HAND devHandle, TCompHs1DimensParam *param,short chn);

// ���ܣ����ø���1ά�Ƚ�����
// pArrayPos:�Ƚ������ַ
// count:λ�õ���
// chn: ͬ��
MTN_API short __stdcall NMC_CompHs1DimensSetData(HAND devHandle,long *pArrayPos,short count,short chn);

// ���ܣ�����1άλ�ñȽ�ʹ��
// onOff�� 0:ֹͣ,1:���,2:�ֶ�����������ڿ���״̬��,Ҳ��Ҫ��ǰ���ò�����
// chn: ͬ��
MTN_API short __stdcall NMC_CompHs1DimensOnOff(HAND devHandle, short onOff,short chn);

// ���ܣ�����1άλ�ñȽϵ�״̬
// pBusy: 0 δ�����Ƚ� 1 �Ƚ������
// pOutCount������ĸ���
// pWaitCnts���ȴ��Ƚϵĸ���
// pFreeCnts�����������еĸ���
// chn: ͬ��
MTN_API short __stdcall NMC_CompHs1DimensStatus(HAND devHandle, short * pBusy, short *pOutCount, short *pWaitCnts, short *pFreeCnts, short chn);

//------------------------------------------------------------------------
//                                                     
//  Group 27 : ��ȡ������Ϣ
//                                                   
//------------------------------------------------------------------------
// ��ȡ��ʱʱ�ӣ��������ϵ翪ʼ
// pClock:����ֵ����λ:125us
// pLoop: ѭ�����ڼ���
MTN_API short  __stdcall NMC_GetClock(HAND devHandle,unsigned long *pClock,unsigned long *pLoop);

// ��ȡ����״̬
// firstAxisHandle:��һ������
// pSts:���ص�״̬����
// count:������
// pClock:���ص�ǰ������ʱ�ӣ���λ125us
MTN_API short  __stdcall NMC_MtGetStsMulti(HAND firstAxisHandle,short *pStsArray,short count,unsigned long *pClock);

// ��ȡ����滮ģʽ
// firstAxisHandle:��һ������
// pModes:���ص�����
// count:������
// pClock:���ص�ǰ������ʱ��
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
#define DI_TYPE_LIMIT_POSITIVE               0		// ������λ
#define DI_TYPE_LIMIT_NEGATIVE               1		// ������λ
#define DI_TYPE_ALARM                        2		// ��������
#define DI_TYPE_HOME                         3		// ԭ��
#define DI_TYPE_GPI                          4		// ͨ������
#define DI_TYPE_LIMIT_POSITIVE_LOG           10		// ������λ:�߼���ƽ
#define DI_TYPE_LIMIT_NEGATIVE_LOG           11		// ������λ:�߼���ƽ
#define DI_TYPE_ALARM_LOG                    12		// ��������:�߼���ƽ
#define DI_TYPE_HOME_LOG                     13		// ԭ��:�߼���ƽ


// ����DI���˲�ϵ��
// diType:DI����,��DI type�궨��
// groupID:DI��,ȡֵ��Χ[0,n],����DI_TYPE_GPI����0: ����DI31~DI0, 1: ����DI63~DI32,����ָ��չIOģ�飻��������DI���ͣ���ʱ����
// diIndex:DIͨ���ţ�ȡֵ��Χ[0,n]
// filtTime:�˲�ʱ�䣬��λms��Ĭ��Ϊ3,ȡֵ��Χ[0,32]
MTN_API short  __stdcall NMC_SetDIFilter( HAND devHandle,short diType,short diGroup,short diIndex,short filtTime);

// ��ȡDI���˲�ϵ��
MTN_API short  __stdcall NMC_GetDIFilter( HAND devHandle,short diType,short diGroup,short diIndex,short *pFiltTime);

// ��ȡ�����������ź�ֵ
// diType:DI����,��DI type�궨��
// groupID:DI��,ȡֵ��Χ[0,n],����DI_TYPE_GPI����0: ����DI31~DI0, 1: ����DI63~DI32,����ָ��չIOģ�飻��������DI���ͣ���ʱ����
// pDiValue:���ص�����ֵ
MTN_API short  __stdcall NMC_GetDIEx( HAND devHandle,short diType,short groupID,long *pDiValue);

// ��ȡ�����������ź�ֵ(ԭʼֵ)
// diType:DI����,��DI type�궨��
// groupID:DI��,ȡֵ��Χ[0,n],����DI_TYPE_GPI����0: ����DI31~DI0, 1: ����DI63~DI32,����ָ��չIOģ�飻��������DI���ͣ���ʱ����
// pDiValue:���ص�����ֵ
MTN_API short  __stdcall NMC_GetDIRaw( HAND devHandle,short diType,short groupID,long *pDiValue);

// ���������������źŵķ�ת����
// diType:DI����,��DI type�궨��
// diIndex:DI��ţ�ȡֵ��Χ[0,n]������ͨ�����룬ֻ֧��0~15����������ֻ֧��0~7
// pReverseCountArray:���صķ�ת��������
// count:ͬʱ��ȡ��������ȡֵ��Χ[1,16]
MTN_API short  __stdcall  NMC_SetDiReverseCount(HAND devHandle,short diType,short diIndex,unsigned long *pReverseCountArray,short count);

// ��ȡ�����������źŵķ�ת����
// diType:DI����
// diIndex:DI��ţ�ȡֵ��Χ[0,n]
// pReverseCountArray:��ת��������
// count:ͬʱ��ȡ��������ȡֵ��Χ[1,16]
MTN_API short  __stdcall  NMC_GetDiReverseCount(HAND devHandle,short diType,short diIndex,unsigned long *pReverseCountArray,short count);

// DO type
#define DO_TYPE_MOTOR_ENABLE            1   // ���ʹ��
#define DO_TYPE_MOTOR_CLEAR             2   // ����������
#define DO_TYPE_GPDO                    3   // ͨ�����1

// ���DO,��������
// doType:do����
// groupID:���
// outMask:��λ�������
// outValue:��λ�����ֵ
MTN_API short  __stdcall NMC_SetDOMask( HAND devHandle,long outMask,long outValue ,short doType,short groupID) ;

// ��ȡģ���������ѹֵ
// ch:ͨ���ţ�[0,n]��ʾ���أ�256��ʾ��չģ����ͨ��
// count:��ȡ��ͨ������,ȡֵ��Χ[1,8]
// pAdcVolArray:��ȡ�ĵ�ѹֵ����
MTN_API short  __stdcall NMC_GetAdcVoltageMulti( HAND devHandle,short ch,short count,double *pAdcVolArray);

// ����ģ���������ѹֵ
// ch:ͨ���ţ�[0,n]��ʾ���أ�256��ʾ��չģ����ͨ��
// count:��ȡ��ͨ������,ȡֵ��Χ[1,8]
// pDacVolArray:��ȡ�ĵ�ѹֵ����
MTN_API short  __stdcall NMC_SetDacVoltageMulti( HAND devHandle,short ch,short count,double *pDacVolArray);

// ��ȡģ���������ѹֵ
// ch:ͨ���ţ�[0,n]��ʾ���أ�256��ʾ��չģ����ͨ��
// count:��ȡ��ͨ������,ȡֵ��Χ[1,8]
// pDacVolArray:��ȡ�ĵ�ѹֵ����
MTN_API short  __stdcall NMC_GetDacVoltageMulti( HAND devHandle,short ch,short count,double *pDacVolArray);

#define REPEAT_CAPT_MAX_NUM		64      // ����ظ��������

// �����ظ��������
// count:�ظ����������ȡֵ��Χ[0,REPEAT_CAPT_MAX_NUM],0��ʾȡ���ظ�����
// ע��:���ú������������
MTN_API short  __stdcall NMC_MtSetCaptRepeat(HAND axisHandle,short count);

// ��ȡ�ظ��������
// pCount:�Ѿ��������
MTN_API short  __stdcall NMC_MtGetCaptRepeatStatus(HAND axisHandle,short *pCount);

// ��ȡ�ظ�����λ��ֵ
// pPosArray:���ص�λ��ֵ����
// startNum:��ʼ����
// count:�ظ����������ȡֵ��Χ[1,32],һ������32��
MTN_API short  __stdcall NMC_MtGetCaptRepeatPosMulti(HAND axisHandle,long *pPosArray,short startNum,short count);

// ��ȡ�жϵ�ִ��ʱ��
// pServoRunTime:�ŷ����ڵ�ǰֵ
// pProfileRunTime:�滮���ڵ�ǰֵ
MTN_API short  __stdcall NMC_GetInterruptTime(HAND devHandle,double *pServoRunTime,double *pProfileRunTime);

// ��ȡ�жϵ����ִ��ʱ��
// pServoRunTimeMax:�ŷ��������ֵ
// pProfileRunTimeMax:�滮�������ֵ
MTN_API short  __stdcall NMC_GetInterruptTimeMax(HAND devHandle,double *pServoRunTimeMax,double *pProfileRunTimeMax);

// ������ֹͣ����ϵ�˶�
// crdIdx:ֹͣ����ϵ��ţ�-1��ʾֹͣ����
MTN_API short  __stdcall NMC_CrdBufStopMtn(HAND crdHandle,long segNo,short crdIdx);

// ʹ�ܻ�ر��������ι���
// enable: 0:ȡ�� 1��ʹ��
// bufCount: ���εĿ��
// kCoef: ���ε�ϵ��
MTN_API short  __stdcall  NMC_MtSetAxisInputShaping(HAND axisHandle,short enable,short bufCount,double kCoef);

// ��ȡ���DO
// doType:do����
// groupID:���
// pOutValue:��ȡ����ֵ
MTN_API short  __stdcall NMC_GetDOEx( HAND devHandle,short doType,short groupID,long *pOutValue );

// ��λ����ͨ������ź�ȡ��
// doType:DO����,���磺DO_TYPE_GPDO
// group:��ţ���ʱֻ��GPO��Ч��ָDO�����
// bitIndex:ȡֵ��Χ[0,n],λ���,ǰ64λΪ���ص�ͨ�����,����64Ϊ��չDo
// revs:�Ƿ�ȡ��,1��ȡ��,0����ȡ��
MTN_API short  __stdcall NMC_SetDOBitRevsEx ( HAND devHandle,short doType,short group,short bitIndex,short revs);

// ��λ��ȡͨ������ź�ȡ��
MTN_API short  __stdcall NMC_GetDOBitRevsEx( HAND devHandle,short doType,short group,short bitIndex,short *pRevs);

// ��ȡ����ϵ״̬
// pSts��crd״̬����λ��ʾ
// pUserSeg����ǰ���û��κ�
MTN_API short __stdcall NMC_CrdGetStsEx( HAND crdHandle, short *pSts,long *pUserSeg );

// �����ش���
// diIndex:ͨ��������ţ�ֻ֧��ͨ�������źţ�ȡֵ��Χ[0,32]
// diSns:�����أ�0Ϊ�½���,1Ϊ������
MTN_API short  __stdcall  NMC_MtPtStartMtnEx(HAND axisHandle,short diIndex,short diSns);

///xyƽ�油��
#define XY2DCOMP_MAX_TABLE_NUM	(4)	// ƽ�油�������������
typedef struct
{
	short count[2];				// Count[0]��Count[1]�ֱ�ΪX��Y��������ݵ�����ÿ��������С2��
	short reserved[2];			// ����
	long posBegin[2];			// posBegin[0]��posBegin[1]�ֱ�ΪX,Y�������ʼ����λ��
	long step[2];				// step[0]��step[1]�ֱ�ΪXY����Ĳ�������
	double angle;				// �궨����ϵ���е����ϵ�ļнǣ���λ����
}T2DCompensationTable;

typedef struct
{
	long xDirComp;
	long yDirComp;
	long zDirComp;
}TCompData;						// ÿ�������������ϵĲ�����

// ���ò�������XYΪ��׼�ο����궨XYZ�����ƫ�����ݣ�����������
// tableIndex: ȡֵ0��Ϊ������չ׼����
// pData:���ݰ���X*Y���㣬�������ܳ���X*Y*3<= 3000,ÿ�������XYZ3������Ĳ���ֵ,���鰴��x��������
MTN_API short  __stdcall  NMC_Set2DCompensationTable(HAND devHandle,short tableIndex,T2DCompensationTable *pTable,TCompData *pData);

// ��ȡ������
MTN_API short  __stdcall  NMC_Get2DCompensationTable(HAND devHandle,short tableIndex,T2DCompensationTable *pTable,TCompData *pData);

typedef struct
{
	short enable;			// ������ֹͣ����
	short tableIndex;		// ʹ�õ�Ŀ¼��ȡֵ0
	short axisType[2];		// ��ά��������ʹ�õ�������:0��ʾ�滮��1��ʾʹ�ñ������a
							//  axisType[0]��ӦX�������ͣ�axisType[1]��ӦY��������
	short axisIndex[3];		// axisIndex[0]��ʾX����ʹ�õ���ţ� axisIndex[1]��ʾY����ʹ�õ����
												// ע��axisIndex[2]��ʾZ������Ҫ���������
}T2DCompensation;

// ���ò�����XYƽ������
MTN_API short  __stdcall  NMC_Set2DCompensation(HAND devHandle,T2DCompensation *pComp);

// ��ȡXYƽ�����������
MTN_API short  __stdcall  NMC_Get2DCompensation(HAND devHandle,T2DCompensation *pComp);

//------------------------------------------------------------------------------------------------------------
//
//	28.PVT
//
//------------------------------------------------------------------------------------------------------------
// ����PVT�˶������ṹ
typedef struct
{
    double smoothDec;		// ֹͣ���ٶ�
    double abruptDec;		// ��ͣ���ٶȣ���ʱ����
    double reserved1[2];	// ����
	long dataMode;			// ����ģʽ��1������פ��ģʽ   0������ˢ��ģʽ(Ĭ��ģʽ)
	long loopCount;			// ѭ������ ��������פ��ģʽ����Ч
    long reserved2[4];      // ����
}TPvtPara;
// ����PVT�˶�����ز��� 
// pPara������,�ο��ṹ����
MTN_API short __stdcall NMC_MtPvtSetPara( HAND axisHandle, TPvtPara *pPara );
// ��ȡPVT�˶�����ز��� 
MTN_API short __stdcall NMC_MtPvtGetPara( HAND axisHandle, TPvtPara *pPara );
 
// ��PVT�˶���������ѹ�˶����ݶ�
// count:ѹ������ݶ�����1~32
// pPosArray:�����о���
// pTimeArray:������ʱ��
// pVelArray:�������ٶ�
MTN_API short  __stdcall NMC_MtPvtData(HAND axisHandle,short count,double *pPosArray,double *pTimeArray,double *pVelArray);

// ��ѯPVT����ʣ��ռ��С
// pFreeSpace:���ص�ʣ��ռ��С
// pUsedSpace: ��ʹ�õĿռ����
MTN_API short  __stdcall NMC_MtPvtBufGetSpace(HAND axisHandle,short *pFreeSpace,short *pUsedSpace);

// ���PVT����
MTN_API short  __stdcall NMC_MtPvtBufClr(HAND axisHandle);

// ����Pvt�˶�
// otherSynAxCnts�� ������axisHandle ������ͬ������������
// pOtherSynAxArray: ����ͬ�����������ţ�0~N	
// ע��ͬ�������������ͬһ��������
MTN_API short  __stdcall NMC_MtPvtStartMtn(HAND axisHandle,short otherSynAxCnts,short *pOtherSynAxArray);

#ifdef __cplusplus
}
#endif

#endif	// _H_MTN_LIB20_EXT_H_
