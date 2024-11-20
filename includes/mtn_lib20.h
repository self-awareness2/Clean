////**********************************************************************************************************
//
//  Copyright(c) 2017, Shenzhen Gaochuan Industrial Automation Co.,Ltd
//
//  Moudle Name :   nmc_lib20.h
//
//  Abstract    :   GaoChuan Motion 2.0 User Header
//
//  Note        :   1.�ṹ�嶨�������е�'reservedxxx'�ĳ�Ա���Ǳ�������,Ϊ������������,������Ϊ0��
//                  2.���ر�˵��,����API����RTN_CMD_SUCCESS����0ֵ����ʾִ�гɹ�,�������ʾ�������,��mtn_lib20_err.h��
//                  3.���е�API������,���ر�˵��,axisHandle��ʾ������ľ��,devHandle��ʾĿ��������ľ��,
//                    crdHandle��ʾĿ������ϵ������
//                  4.�����ر�˵��,����API�Ĳ�����,ǣ�浽������0��ʼ,����NMC_MtOpen�е�itemNo����,0��ʾ��һ���ᡣ
//                  5.mtn_lib20�����еĽṹ�嶼�������ֽڶ��뷽ʽ���룬Ϊ�˱���ṹ�������������⣬�뽫���뻷������Ϊ���ֽڶ���
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
//              �궨��
//
//------------------------------------------------------------------------------------------------------------
// �������
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

// ������Ͷ���
typedef     unsigned short*     PHAND;
typedef     unsigned short      HAND;

//------------------------------------------------------------------------------------------------------------
//
//           ָ���������
//
//------------------------------------------------------------------------------------------------------------
//  1.���������ӡ��ر�
//  2.��������
//  3.�������
//  4.����״̬��ȡ
//  5.IO���Ƽ��ⲿ��Դ��д
//  6.����ϵ����
//  7.����ϵ����
//  8.����ϵ���˶�������״̬��ȡ
//  9.�������岹�˶���IO����
//  10.����
//  11.���ӳ���
//  12.����͹��
//------------------------------------------------------------------------------------------------------------
//
//          1.���������ӡ��ر�
//
//------------------------------------------------------------------------------------------------------------
// ͨѶģʽ����
typedef enum { USB=0, Ethernet, RS485 } TSearchMode;

//�豸��Ϣ�ṹ
typedef struct
{
    unsigned short address;     // ����λ��ϵͳ�е��豸���,
    char  idStr[16];            // ʶ���ַ���
    char  description[64];      // ������
    unsigned short ID;          // ���ϵ�ID(δ��)
}TDevInfo;

// �忨��Ѱ
// ����: mode:ͨѶģʽ
// pDevNo : �����豸����Ŀ
// pInfoList�������豸��Ϣ
MTN_API short __stdcall NMC_DevSearch( TSearchMode mode, unsigned short *pDevNo, TDevInfo *pInfoList );

// �忨�򿪣�������ţ�
// devNo: �豸���,ȡֵ��Χ[0,n]�� pDevHandle: �����豸�������
MTN_API short __stdcall NMC_DevOpen       ( short devNo, PHAND pDevHandle );

// �忨�ر�
// pDevHandle : �豸���ָ��
MTN_API short __stdcall NMC_DevClose(PHAND pDevHandle );

// �忨��λ
MTN_API short __stdcall NMC_DevReset(HAND devHandle );

// �򿪵���
// devHandle : �豸���
// itemNo�����,ȡֵ��Χ[0,n]
// pCrdHandle������ϵ����
MTN_API short  __stdcall NMC_MtOpen(HAND devHandle, short itemNo, PHAND pAxisHandle ); 

// �رյ���
// devHandle : �豸���ָ��
MTN_API short  __stdcall NMC_MtClose(PHAND pAxisHandle );

// ������ϵ��(֧�ֶ�����ϵ)
// itemNo������ϵ��,ȡֵ��Χ[0,1]
// pCrdHandle����������ϵ����
MTN_API short __stdcall NMC_CrdOpenEx( HAND devHandle,short itemNo, PHAND pCrdHandle );

// �ر�����ϵ��
// pCrdHandle������ϵ����
MTN_API short __stdcall NMC_CrdClose(PHAND pCrdHandle );

//------------------------------------------------------------------------------------------------------------
//
//          2.��������
//
//------------------------------------------------------------------------------------------------------------
// ϵͳ��չ��Դ����ʼID,������չ��������ģ�����������
#define EXT_RES_START_INDEX  256

// ������ģʽ�������ź�Դ,�ź�����,ȡ��,,��������Ƶ�� 
// Bit7:0 ��Ƶϵ��,��ֵΪ0~255����Ӧ��Ƶ��ֵ 1~256
// Bit9:8 �źź�Դѡ��
//   00���ⲿ�ź�����
//   01: ����������
//   10���Զ������źţ������壩
//   11���Զ������źţ������壩
// Bit11:10 �ź����ͣ��ⲿ��
//  00��AB��,90�Ȳ�
//  01������+����
//  10��������+������
//  11������
// Bit12 ����A��B�������ⲿ�� 0��������,1������
// Bit13 ����Aȡ�����ⲿ�� 0����ȡ��,1��ȡ��
// Bit14 ����Bȡ�����ⲿ�� 0����ȡ��,1��ȡ��
// Bti15 ����������,0�������Сֵ��ת,1������ת
// ���ñ�����ģʽ
// encId: ������ID,�����������ͨ��,ȡֵ��Χ[0,n],
//                ������չ������ͨ��,256��ʾ��һ����չ������ͨ��,257��ʾ�ڶ���,�Դ�����
// encMode:������ģʽ,�ο��궨��
MTN_API short  __stdcall NMC_SetEncMode( HAND devHandle, short encId,  short encMode );

// ���������λ�Ƿ�ֹͣ�˶�
// enable�������λ������������,1Ϊ����,0Ϊ��ֹ
MTN_API short  __stdcall NMC_MtSwLmtOnOff  ( HAND axisHandle, short swt );

// ���������λ��ֵ
// posLmt�����������λ����ֵ
// negLmt�����������λ����ֵ����λΪ������
MTN_API short  __stdcall NMC_MtSwLmtValue  ( HAND axisHandle, long posLmt,long negLmt );

//���˶���ȫ����
typedef struct
{
    double estpDec;     // ��ͣ���ٶ�
    double maxVel;      // ����ٶ�
    double maxAcc;      // �����ٶ�
}TSafePara;
// �����ᰲȫ����
// TSafePara��������ͣ���ٶȡ���������ٶȡ����������ٶ�
MTN_API short  __stdcall NMC_MtSetSafePara( HAND axisHandle, TSafePara *pPara );

// �����������ģʽ
// inv, 1��ȡ��,0����ȡ��
// mode 0�����巽�� 1����������
MTN_API short  __stdcall NMC_MtSetStepMode ( HAND axisHandle, short inv, short mode );

// �������ٶ��˲�����
// ע��filterCoefϵ����0~5֮��,ֵԽ��,�ٶ�Խƽ����Ĭ��ֵΪ0
MTN_API short __stdcall NMC_MtSetAxisVelFilter(HAND axisHandle,short filterCoef);

// Ӳ����λ����
// posLmtEnable: ������λ������������,1Ϊ����,0Ϊ��ֹ
// negLmtEnable: ������λ������������,1Ϊ����,0Ϊ��ֹ
// posLmtSns: ������λ������ƽ,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
// negLmtSns: ������λ������ƽ,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
MTN_API short __stdcall NMC_MtSetLmtCfg( HAND axisHandle, short posLmtEnable,short negLmtEnable,short posLmtSns,short negLmtSns );

// �ŷ���������
// alarmEnable: �ŷ�����������������,1Ϊ����,0Ϊ��ֹ
// alarmSns:     �ŷ�����������ƽ,1Ϊ�ߵ�ƽ����,0Ϊ�͵�ƽ����
MTN_API short __stdcall NMC_MtSetAlarmCfg( HAND axisHandle, short alarmEnable,short alarmSns );

// ������������˲�
// coeϵ���� ��Χ0~65535,0���˲�,��ֵԽ���˲�Ч��Խ���ԡ�
MTN_API short  __stdcall NMC_MtSetStepFilter ( HAND axisHandle, unsigned short  coe );

//------------------------------------------------------------------------------------------------------------
//
//          3.�������ָ��
//
//------------------------------------------------------------------------------------------------------------
// ����Ĺ滮ģʽ
#define MT_NONE_PRF_MODE        (-1)            // ��Ч
#define MT_PTP_PRF_MODE         (0)             // ���ι滮
#define MT_JOG_PRF_MODE         (1)             // �����ٶ�ģʽ
#define MT_CRD_PRF_MODE         (3)             // ����ϵ
#define MT_GANTRY_MODE          (4)             // ���Ÿ���ģʽ
#define MT_PT_PRF_MODE			(5)				// PTģʽ
#define MT_MULTI_LINE_MODE		(6)				// ����ֱ�߲岹
#define MT_GEAR_PRF_MODE		(7)				// ���ӳ���ģʽ
#define MT_FOLLOW_PRF_MODE		(8)				// Follow����ģʽ
#define MT_PVT_PRF_MODE			(9)				// PVT

// ���õ���滮ģʽ
// mode�������˶�ģʽ
MTN_API short __stdcall NMC_MtSetPrfMode(HAND axisHandle,short mode);

// ����PTP�˶������ṹ
typedef struct
{
    double acc;         // ���ٶ�
    double dec;         // ���ٶ�
    double startVel;    // �����ٶ�
    double endVel;      // ��ֹ�ٶ�
    short smoothCoef;   // ƽ��ϵ��,ȡֵ��Χ[0,199]
    short reserved[3];      // ����
}TPtpPara;
// ���ö������, �����¡�
// pAxPara������,�ο��ṹ���塣
MTN_API short __stdcall NMC_MtSetPtpPara( HAND axisHandle, TPtpPara *pAxPara );

typedef struct
{
   double totalTime;	// ��ǰ��λ�˶�����ʱ�䣬��λ:ms
   double leftTime;		// ��ǰ��λ�˶���ʣ��ʱ�䣬��λ:ms
   double reseved[2];	// ����
}TTrapTime;

// ��ȡ��ǰ��λ�˶�ִ��ʱ�����
MTN_API short  __stdcall  NMC_MtGetTrapTime(HAND axisHandle,TTrapTime *pTrapTime);

// ����JOG�˶������ṹ
typedef struct
{
    double acc;         // ���ٶ�
    double dec;         // ���ٶ�
    double smoothCoef;  // ƽ��ϵ��,ȡֵ��Χ[0,199],��ֵԽ�����ٶȱ仯Խƽ��
}TJogPara;
// ����Jog�˶�����
// pAxPara������,�ο��ṹ���塣
MTN_API short __stdcall NMC_MtSetJogPara   ( HAND axisHandle, TJogPara *pAxPara );

// ����Ŀ���˶��ٶ�,ֻ���PTP��Jog��PTPģʽ��ֻ��������,Jogģʽ�������ű�ʶ�˶�����
// vel: Ŀ���ٶȣ�����ٶȣ�,��λ�� ����/ms
MTN_API short __stdcall NMC_MtSetVel( HAND axisHandle, double vel );

// ����Ŀ���˶�λ��,ֻ���PTP
// pos: Ŀ��λ��,��λ�� ����
MTN_API short __stdcall NMC_MtSetPtpTgtPos( HAND axisHandle, long pos );

// ��������, ֻ���PTP��Jog
MTN_API short __stdcall NMC_MtUpdate( HAND axisHandle );

// �����˶�ֹͣ
// ע���˶��ᰴ�趨�ļ��ٶ�ֹͣ��
MTN_API short __stdcall NMC_MtStop( HAND axisHandle );

// ���ἱͣ����������ͣ��־λ
// ע���˶��ᰴ�趨�ļ�ͣ���ٶ�ֹͣ�����û������,�������ֹͣ��
MTN_API short __stdcall NMC_MtAbruptStop( HAND axisHandle );

// ����λ��ϵͳ����,�滮�Լ�������
MTN_API short __stdcall NMC_MtZeroPos( HAND axisHandle);

// �����ŷ�������������״̬
// swt: ���ÿ�����Ч״̬��0, ��Ч������͵�ƽ��,1,��Ч������ߵ�ƽ��
MTN_API short  __stdcall NMC_MtSetSvClr( HAND axisHandle, short swt );

// �����ŷ�ON, �ᾲֹʱִ��,���������updateָ��,��Ҫ��ʱһ������
MTN_API short  __stdcall NMC_MtSetSvOn( HAND axisHandle );

// �����ŷ�OFF, �ᾲֹʱִ��,���������updateָ��,��Ҫ��ʱһ������
MTN_API short  __stdcall NMC_MtSetSvOff( HAND axisHandle );

// ��������״̬
MTN_API short  __stdcall NMC_MtClrError ( HAND axisHandle );

// ��������״̬,��λ���
// stsMask:��ӦλΪ1������Ҫ�����Ӧλ�Ĵ���״̬
MTN_API short  __stdcall NMC_MtClrStsByBits(HAND axisHandle , short stsMask);

// �����λ�˶�,����NMC_MtSetPrfMode,NMC_MtSetPtpPara,NMC_MtSetVel,NMC_MtSetPtpTgtPos,NMC_MtUpdate
// acc:���ٶ�,dec�����ٶ�,startVel:�����ٶ�,endVel:��ֹ�ٶ�,smoothCoef:ƽ��ϵ��
// maxVel������ٶ�
// tgtPos:Ŀ��λ��,��λ������
MTN_API short  __stdcall NMC_MtMovePtpAbs(HAND axisHandle,double acc,double dec,double startVel,double endVel,double maxVel,short smoothCoef,long tgtPos);

// ���������ٶ��˶�
// acc:���ٶ�,dec�����ٶ�,smoothCoef:ƽ��ϵ��
// maxVel������ٶ�
// clrStsFlag:�Ƿ��˶�ǰ�������״̬��0���������1�����
MTN_API short  __stdcall NMC_MtMoveJog(HAND axisHandle,double acc,double dec,double maxVel,
                                        short smoothCoef,short clrStsFlag);
typedef struct
{
	short axisMask;			// �����룬��ӦbitΪ1��ʾ��������˶�
	short clrStsFlag;		// �Ƿ��˶�ǰ�������״̬��0���������1�����
	short reserved[2];		// ����
    double acc[8];			// ���ٶ�
    double dec[8];			// �����ٶ�
    double startVel[8];		// �����ٶ�
    double endVel[8];		// ��ֹ�ٶ�
	double maxVel[8];		// ����ٶ�
	short  smoothCoef[8];	// ƽ��ϵ��
	long tgtPos[8];			// λ�ã���λ:����
}TMovePtpPack8;
// �����λ�˶����(�����˶�)
// axisFirstHandle:����ĵ�һ������
// pPackData:�������
// ע�⣺1.���ĳ������޷��˶��Ĵ���״̬���������᲻�������˶�
MTN_API short  __stdcall NMC_MtMovePtpAbsPack8(HAND axisFirstHandle,TMovePtpPack8 * pPackData);

// �����λ�˶����(����˶�)
// axisFirstHandle:����ĵ�һ������
// pPackData:�������
// ע�⣺1.���ĳ������޷��˶��Ĵ���״̬���������᲻�������˶�
MTN_API short  __stdcall NMC_MtMovePtpRelPack8(HAND axisFirstHandle,TMovePtpPack8 * pPackData);

// �����λ�˶�,����˶�
// acc:���ٶ�,dec�����ٶ�,startVel:�����ٶ�,endVel:��ֹ�ٶ�,smoothCoef:ƽ��ϵ��
// maxVel������ٶ�
// relPos:��Ե�ǰλ�õ��ƶ���,��λ������
MTN_API short  __stdcall NMC_MtMovePtpRel(HAND axisHandle,double acc,double dec,double startVel,double endVel,double maxVel,short smoothCoef,long relPos);

// ����ͬ���˶���ͨ��PTPʵ�֣�
// axisMask:�����������
// acc,dev:���ٶ�,���ٶ�
// sVel,eVel��maxVel:�����ٶ�,�յ��ٶȣ�����ٶ�
// smooth:ƽ��ϵ��
// pPosArray:Ŀ��λ������
MTN_API short __stdcall NMC_MtMultiMoveAbs(HAND devHandle,short axisMask,double acc,double dec,double sVel,
	double eVel,double maxVel,short smooth,long *pPosArray);

// PTP�������˶�����
typedef struct
{ 
    double acc;         // ���ٶ�
    double dec;         // ���ٶ�
    double startVel;    // �����ٶ�
    double endVel;      // �յ��ٶ�
    double maxVel;      // ����ٶ�
    long tgtPos;        // Ŀ��λ��
    short reserved;      // ��������
    short smoothCoef;   // ƽ��ϵ��
    short inType;       // �������ͣ�0��ͨ��DI��1��Home�ź�; 
    short inIdx;       //  �����ź�ͨ����
    short inTrigLevel; // ������ƽ��0���͵�ƽ��1���ߵ�ƽ
    short action;       // ������Ķ�����0����������1������Ŀ���ٶ�,
                                                // 2.����Ŀ��λ��
                                                // 3:����Ŀ��λ�ã�λ��Ϊ��Դ���������λ�ã�
                                                // 4:��ͣ
    double prm1;        // action=1ʱ��ʾ���µ�Ŀ���ٶ�
    double prm2;        // action=2��3ʱ��ʾ���µ�Ŀ��λ��
    double prm3;        // ����
    double prm4;        // ����
} TPtpTwoStagePrm;

// ������PTP�˶�
MTN_API short  __stdcall NMC_MtMovePtpAbsTwoStage(HAND axisHandle,TPtpTwoStagePrm *pPrm);

//------------------------------------------------------------------------------------------------------------
//
//         4.����״̬��ȡ
//
//------------------------------------------------------------------------------------------------------------
// ��ȡ�滮����ϵ��λ��
// pPos : ����λ��,��λ�� ����
MTN_API short __stdcall NMC_MtGetPrfPos   ( HAND axisHandle, long *pPos );

// ����ǰ��滮�ٶ�
// pVel: �����ٶ�,��λ�� ����/ms
MTN_API short __stdcall NMC_MtGetPrfVel   ( HAND axisHandle, double *pVel );

// ��ȡ�����״̬��4�ᣩ
#define PACK_AXIS_NUM   4
typedef struct
{
    long prfPos[PACK_AXIS_NUM];     // �滮λ��
    long encPos[PACK_AXIS_NUM];     // ʵ��λ��
    float prfVel[PACK_AXIS_NUM];    // �滮�ٶ�
    long motionIO[PACK_AXIS_NUM];   // ��ר��IO
    short sts[PACK_AXIS_NUM];       // ��״̬
    long gpo;                       // ͨ�����
    long gpi;                       // ͨ������
}TAxisStsPack;
// �����ȡ������״̬,�ӵ�һ���Ὺʼ��ȡ�����ĸ����״̬
// axisFirstHandle : ��һ������
// count:��ȡ״̬��������,ȡֵ��Χ��[1,4]
// pPackSts: �����״̬����,�ο��ṹ�嶨��
MTN_API short  __stdcall NMC_MtGetStsPack  ( HAND axisFirstHandle, short count,TAxisStsPack *pPackSts );

// ��ȡ�����״̬��12�ᣩ
typedef struct
{
    short          mtSts[12];          // ����״̬��λ����ο�NMC_MtGetSts
    short          mtMio[12];          // ����ר��IO,λ����ο�NMC_MtGetMotionIO
    short          mtMioLog[12];       // ����ר��IO:�߼���ƽ,λ����ο�NMC_MtGetMotionIOLogical
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
    long           crdLeftLen[2];      // ����ϵ������ʣ��γ�����λ:����
    long           crdAllCmdCnt[2];    // ����ϵ�������ܹ�ѹ���ָ����Ŀ
    long           extDi[6];           // ��չģ�����룬2��վ~8��վ
    long           extDo[6];           // ��չģ�������2��վ~8��վ
	short		   adc[4];			   // ģ��������ֵ 0~4ͨ��
	short		   adcAux[2];		   // ��չģ��������ֵ 0~1ͨ��
	short		   dac[4];			   // ģ�������ֵ 0~4ͨ��
	short		   dacAux[2];		   // ��չģ�������ֵ 0~1ͨ��
    long           reserved[10];       // Ԥ��

}TAxisStsPack12Ex;
// �����ȡ12�����״̬
// axisFirstHandle : ��һ������
// pPackSts: �����״̬����,�ο��ṹ�嶨��
MTN_API short  __stdcall NMC_MtGetStsPack12Ex  ( HAND axisFirstHandle, TAxisStsPack12Ex *pPackSts );

// ���ٶ�ȡ���״̬ 
typedef struct
{
    short sts[8];					// ��״̬
	short crdSts[2];				// ����ϵ״̬
}TMcStsPackEx;
// �����ȡ������״̬
// devHandle : ���������
// pPackSts: �����״̬����,�ο��ṹ�嶨��
MTN_API short  __stdcall NMC_MtGetStsPackEx  ( HAND devHandle, TMcStsPackEx *pPackSts );

// ���ٶ�ȡ��״̬
MTN_API short  __stdcall NMC_MtGetStsEx( HAND axisHandle, short *pStsWord );

// ���ٶ�ȡ����ϵ״̬
MTN_API short __stdcall NMC_CrdGetStsEx2( HAND crdHandle, short  *pStsWord );

// ������չ��״̬��ȡָ���
// enFlag:�Ƿ����ã�1-���ã�0-�رգ�Ĭ��Ϊ�ر�״̬
MTN_API short __stdcall NMC_DevSetStsExCmdEn( HAND devHandle, short  enFlag );


// ����ǰ�������ͨ��
// pPos:���ر�������ֵ
MTN_API short  __stdcall NMC_MtGetEncPos   ( HAND axisHandle, long *pPos );

// ����������ٶ�(��λ�ǣ�����/ms)
MTN_API short  __stdcall NMC_GetEncVel( HAND devHandle, short encId, double *pVel);

// ��״̬��λ���� 
#define BIT_AXIS_BUSY           (0x00000001)    // bit 0  , �˶�:1 ,��ֹ 0       
#define BIT_AXIS_POSREC         (0x00000002)    // bit 1 , �ŷ�λ�õ���,����ģʽʱλ�õ���,�ŷ�ģʽʱʵ��λ�õ�������� 
#define BIT_AXIS_MVERR          (0x00000004)    // bit 2 , �ϴ��˶�����,��ǰ�޷������˶�,��Ҫ����NMC_MtClrError���
#define BIT_AXIS_SVON           (0x00000008)    // bit 3  , �ŷ�����        
#define BIT_AXIS_CRD            (0x00000010)    // bit 4 , ����ϵģʽ      
#define BIT_AXIS_STEP           (0x00000020)    // bit 5  , ����/�ŷ�       
#define BIT_AXIS_LMTP           (0x00000040)    // bit 6  , ������λ�������뿪���Զ����        
#define BIT_AXIS_LMTN           (0x00000080)    // bit 7  , ������λ�������뿪���Զ����
#define BIT_AXIS_SOFTPOSLMT     (0x00000100)    // bit 8  , ��������λ����  
#define BIT_AXIS_SOFTNEGLMT     (0x00000200)    // bit 9  , ��������λ����  
#define BIT_AXIS_ALM            (0x00000400)    // bit 10  , �ŷ�����,��Ҫ����NMC_MtClrError���
#define BIT_AXIS_POSERR         (0x00000800)    // bit 11  , λ�ó���,��Ҫ����NMC_MtClrError��� 
#define BIT_AXIS_ESTP           (0x00001000)    // bit 12 , ��ͣ,��Ҫ����NMC_MtClrError���
#define BIT_AXIS_HWERR          (0x00002000)    // bit 13 , Ӳ������ 
#define BIT_AXIS_CAPTSET        (0x00004000)    // bit 14  , ���񴥷�       
// ����ǰ��״̬
// pStsWord: ������״̬�֡��ο�λ����
MTN_API short  __stdcall NMC_MtGetSts( HAND axisHandle, short *pStsWord );

// ר��IO����,arrive,alm : home : limit+ , limit- servoClr
#define BIT_AXMTIO_LMTN     (0x00000001)    // bit 0  ,������λ  
#define BIT_AXMTIO_LMTP     (0x00000002)    // bit 1  ,������λ  
#define BIT_AXMTIO_HOME     (0x00000004)    // bit 2  ,ԭ��  
#define BIT_AXMTIO_ALARM    (0x00000008)    // bit 3  ,�������� 
#define BIT_AXMTIO_ARRIVE   (0x00000010)    // bit 4  ,�����λ 
#define BIT_AXMTIO_CAPT     (0x00000020)    // bit 5  ,����Դ�ź�
#define BIT_AXMTIO_SVRCLR   (0x00000100)    // bit 8  ,�ŷ�����ź�
// ���˶�����ר��IO
// pIoValue : ����ר��IO��״̬,ԭ��,��λ,�������ŷ��������ȡ��ο�λ���塣��ӦλΪ0Ϊ�͵�ƽ,1Ϊ�ߵ�ƽ��
MTN_API short __stdcall NMC_MtGetMotionIO ( HAND axisHandle, long *pIoValue );

// ���˶�����ר��IO,�߼���ƽ
// pIoValue : ����ר��IO��״̬,ԭ��,��λ,�������ο�λ���塣��ӦλΪ0Ϊ�͵�ƽ,1Ϊ�ߵ�ƽ��
MTN_API short __stdcall NMC_MtGetMotionIOLogical ( HAND axisHandle, long *pIoValue );




//------------------------------------------------------------------------------------------------------------
//
//        5.IO���Ƽ��ⲿ��Դ��д
//
//------------------------------------------------------------------------------------------------------------
// ����ͨ�����(��ͨ��,֧�ֳ���32λ),��Ĭ��group
// value: ����ͨ�������������1, ����ߵ�ƽ,0,����͵�ƽ
// groupID:DO��,ȡֵ��Χ[0,n],������Ҫ���������Ƿ���ڶ������������
MTN_API short  __stdcall NMC_SetDOGroup( HAND devHandle, long value, short groupID) ;

// ��ͨ������(��ͨ��,֧�ֳ���32λ) ,��Ĭ��group
// pInValue: ͨ������������ֵ��1, �ߵ�ƽ,0,�͵�ƽ
// groupID:DI��,ȡֵ��Χ[0,n],0: ����DI31~DI0, 1: ����DI63~DI32,����ָ��չIOģ��
MTN_API short __stdcall NMC_GetDIGroup( HAND devHandle, long *pInValue, short groupID);

// ��ȡͨ�����(��ͨ��,֧�ֳ���32λ),��Ĭ��group
// pDoValue: ����ͨ�������������1, �ߵ�ƽ,0,�͵�ƽ
// groupID:DO��,ȡֵ��Χ[0,n],,0: ����DO31~DO0, 1: ����DO63~DO32,����ָ��չIOģ��
MTN_API short  __stdcall NMC_GetDOGroup( HAND devHandle, long *pDoValue, short groupID);

// ��λ����ͨ�����
// bitIndex:ȡֵ��Χ[0,n],λ���,ǰ64λΪ���ص�ͨ�����,����64Ϊ��չDO
// value: ����ͨ�������������1, ����ߵ�ƽ,0,����͵�ƽ
MTN_API short  __stdcall NMC_SetDOBit( HAND devHandle, short bitIndex, short value );

// ��λ����� 
MTN_API short  __stdcall NMC_GetDOBit( HAND devHandle,short bitIndex, short *bitValue);

// ��λ��ͨ������ 
// ��ͨ������(��ͨ��,֧�ֳ���32λ) 
// bitIndex:ȡֵ��Χ[0,n],λ���
// pBitValue: ͨ������������ֵ��1, �ߵ�ƽ,0,�͵�ƽ
MTN_API short  __stdcall NMC_GetDIBit( HAND devHandle,short bitIndex, short *pBitValue );

// ��ȡ��չIOģ���״̬
// sts:ioģ��״̬
MTN_API short  __stdcall NMC_GetIOModuleSts(HAND devHandle, unsigned long *sts);

// ������չIOģ����Ч��Ĭ��ΪIO64ģ�飩
// chDevId:�豸ID
MTN_API short  __stdcall NMC_SetIOModuleEn( HAND devHandle, unsigned char chDevId);

// ��չģ�����Ͷ���
#define IOMODULE_TYPE_IO64		1		// 32DI32DOģ�飨����16DI16DOģ�飩
#define IOMODULE_TYPE_IO32_DA	2		// 4AD4DAģ��

// ������չIOģ����Ч(��ģ������)
// chDevId:�豸ID
// chDevType:ģ�����ͣ����궨��
MTN_API short  __stdcall NMC_IOModuleSetEn( HAND devHandle, unsigned char chDevId,short chDevType);

// ��ȡ��չIOģ������
// chDevId:�豸ID
// pChDevType:���ص�ģ�����ͣ����궨��
MTN_API short  __stdcall NMC_IOModuleGetType( HAND devHandle, unsigned char chDevId,short *pChDevType);

// ��չIOģ��ͨ��д��8λ����
// chDevId���豸վ��
// offset:����ƫ��
MTN_API short  __stdcall NMC_IOModuleWr8Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned char data);

// ��չIOģ��ͨ��д��16λ����
MTN_API short  __stdcall NMC_IOModuleWr16Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned short data);

// ��չIOģ��ͨ��д��32λ����
MTN_API short  __stdcall NMC_IOModuleWr32Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned long data);

// ��չIOģ��ͨ���������8λ����
// chDevId���豸վ��
// offset:����ƫ��
MTN_API short  __stdcall NMC_IOModuleRdOut8Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned char *pData);

// ��չIOģ��ͨ���������16λ����
MTN_API short  __stdcall NMC_IOModuleRdOut16Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned short *pData);

// ��չIOģ��ͨ���������32λ����
MTN_API short  __stdcall NMC_IOModuleRdOut32Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned long *pData);

// ��չIOģ��ͨ������8λ����
// chDevId���豸վ��
// offset:����ƫ��
MTN_API short  __stdcall NMC_IOModuleRd8Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned char *pData);

// ��չIOģ��ͨ������16λ����
MTN_API short  __stdcall NMC_IOModuleRd16Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned short *pData);

// ��չIOģ��ͨ������32λ����
MTN_API short  __stdcall NMC_IOModuleRd32Bit( HAND devHandle, unsigned char chDevId,unsigned char offset,unsigned long *pData);


//------------------------------------------------------------------------------------------------------------
//
//        6.����ϵ����
//
//------------------------------------------------------------------------------------------------------------
#define CRD_MAX_DIMENSION 4

// ����ϵ����
typedef struct
{
    short axCnts;       // �����������
    short reserved[3];  // ����
    short pAxArray[4];  // ����ϵ��ӳ���,�����ȡֵ��Χ[0,n]
    short port[4];      // ����ϵ�˿�ӳ���,ͳһ��Ϊ0
}TCrdConfig;
// �����岹����ϵϵͳ(����)
// pConfig:����ϵ����,�ο��ṹ�嶨��
MTN_API short __stdcall NMC_CrdConfig( HAND crdHandle, TCrdConfig *pConfig );

//�������˶���ȫ����
typedef struct
{
    double estpDec;     // ��ͣ���ٶ�
    double maxVel;      // ����ٶ�
    double maxAcc;      // �����ٶ�
}TCrdSafePara;
// �����Ỻ�����˶���ȫ����
// pPara��������ͣ���ٶȡ���������ٶȡ����������ٶ�
MTN_API short  __stdcall NMC_CrdSetSafePara( HAND crdHandle, TCrdSafePara *pPara );

// �����Ỻ�����˶�ƫ��
// count:����ƫ�Ƶ�����
// pOffsetArray���������˶�ƫ��,long����
// ע����ͬʱ�޸�����ϵ���������˶�ƫ�ƣ�
MTN_API short  __stdcall NMC_CrdSetOffset( HAND crdHandle,short count, long *pOffsetArray );

// ɾ������ϵ
MTN_API short __stdcall NMC_CrdDelete(  HAND crdHandle );


//------------------------------------------------------------------------------------------------------------
//
//        7.����ϵ���п���
//
//------------------------------------------------------------------------------------------------------------
// ����ϵ�����˶�����  
MTN_API short __stdcall NMC_CrdStartMtn( HAND crdHandle );

// ����ƽ��ֹͣ�˶�
// ע������ֹͣ�˶����������ָ���������Ҫ�ٴ��������ܼ������л�����ָ�
MTN_API short __stdcall NMC_CrdStopMtn( HAND crdHandle );

// ��ͣ
// �������ָ�����
MTN_API short __stdcall NMC_CrdEstopMtn( HAND crdHandle );

// �����������˶����ȴ��˶����Ž������˶�,���ÿ��б�־��
// ע���������˶�������������ֹͣ�˶�����ָ�����ȫ��ִ�����,�����������˶�״̬��
MTN_API short __stdcall NMC_CrdEndMtn   ( HAND crdHandle );

// ���ػ������˶��Ķϵ�
// vel:����ʱʹ�õ��ٶ�
// acc:����ʱʹ�õļ��ٶ�
MTN_API short __stdcall NMC_CrdGotoBreak( HAND crdHandle,double acc,double vel);


//------------------------------------------------------------------------------------------------------------
//
//        8.����ϵ���˶�������״̬��ȡ
//
//------------------------------------------------------------------------------------------------------------
// ����ϵ״̬��λ���� 
#define BIT_CORD_BUSY           (0x00000001)    // bit 0 , �˶�:1 ,��ֹ 0,�����˶����˶�ֹͣ,��� 
#define BIT_CORD_MVERR          (0x00000002)    // bit 1 , �˶�����,��ǰ�˶�ָ���޷�����,��Ҫ�����λ    
#define BIT_CORD_EMPTY          (0x00000004)    // bit 2 , �������ա�       
#define BIT_CORD_FULL           (0x00000008)    // bit 3 , ����������               
#define BIT_CORD_NODATASTOP     (0x00000010)    // bit 4 , ���������쳣ֹͣ���߼�ͣ��    
#define BIT_CORD_SDRAM_HWERR    (0x00000020)    // bit 5, �岹������Ӳ��������������  
// ��ȡ����ϵ״̬
// pStsWord������״̬��,�ο��궨��
MTN_API short __stdcall NMC_CrdGetSts( HAND crdHandle, short  *pStsWord );

typedef struct
{
    short crdSts;          // ����ϵ״̬
    short axSts[4];        // ����ϵ�����״̬
    long  prfPos[4];       // �û�����ϵ�µĹ滮λ��
    long  axisPos[4];      // ��е����ϵ�µĹ滮λ��
    long  encPos[4];        // ������λ��
    long  userSeg;         // ���еĻ������κ�
    double  prfVel;         // �˶��ٶ�
    long  gpDi;             // ͨ������0~31
    long  gpDo;             // ͨ�����0~31
    short  motDi[4];        // ��λ��ԭ�㡢��������ο�ר��IOλ����( ���� BIT_AXMTIO_LMTN )
    short  reserved;        // ����
    long crdFreeSpace;      // ������ʣ��ռ�
    long crdUsedSpace;
}TPackedCrdSts4;
// ����ϵ�˶�ģʽ��,�����ȡ������״̬
MTN_API short __stdcall NMC_CrdGetStsPack4( HAND crdHandle, TPackedCrdSts4 *pPackSts );

// ������ϵ�˶�����״̬,ͬʱ�����������Ĵ���״̬
MTN_API short __stdcall NMC_CrdClrError   ( HAND crdHandle );

// ��ȡָ��������г���
// pRes�����ؿ��еĳ���
MTN_API short __stdcall NMC_CrdBufGetFree ( HAND crdHandle, long *pRes );

// ��ȡָ��������ó���
// pLen: ���ȡ��������л�δִ�е�ָ�������
MTN_API short __stdcall NMC_CrdBufGetUsed  ( HAND crdHandle, long *pLen );

// ��ȡ�岹����������δ��ɵ���λ����
// pLen: ����
MTN_API short __stdcall NMC_CrdGetBufLeftLength(HAND crdHandle, double *pLen);

// ָ��������
MTN_API short __stdcall NMC_CrdBufClr( HAND crdHandle );

// ��������ϵʣ��λ���������ڿ��Ƽ������������Ĺرղ������
// group:�����������
// ch:����ͨ����
MTN_API short  __stdcall NMC_CrdSetLeftLenForLaserWaveOff ( HAND crdHandle,double length ,short group,short ch);

// ������������ϵʣ��λ���������ڿ��Ƽ������������Ĺرղ������
MTN_API short  __stdcall NMC_CrdBufSetLeftLenForLaserWaveOff( HAND crdHandle,long segNo,double length,short group,short ch);

// ���κ�
// pSegNo�����صĵ�ǰ�κ�
MTN_API short __stdcall NMC_CrdGetUserSegNo  ( HAND crdHandle, long *pSegNo);

//  ��ȡ�ܹ�ѹ�˶�����ָ��
//  pCnt:���ص�ָ����
MTN_API short __stdcall NMC_CrdGetBufAllCmdCnt ( HAND crdHandle, long *pCnt);

// ��ʼ���㻺����ִ��ʱ��
// ע��:1.�����Ҫ����ִ��ʱ�䣬��Ҫʹ����λ��ǰհ
//     2.��ʼ�����еĻ�����ָ�������ѹ�������
MTN_API short __stdcall NMC_CrdStartExeTimeCalc(void);

// ��ȡ������ָ���ִ��ʱ�䣬��ֹͣ���㣬��λ:ms
MTN_API short __stdcall NMC_CrdGetExeTime(double *pTime);

//------------------------------------------------------------------------------------------------------------
//
//        9.�������岹�˶���IO����
//
//------------------------------------------------------------------------------------------------------------

// ����ֱ�߲岹
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// crdAxMask:�������,��λ��ʾ
// endVel,vel,synAcc:�յ��ٶȣ�����ٶȣ��岹���ٶ�
// pTgPosArray��Ŀ��λ������
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdLineXYZA(  HAND crdHandle,  long segNo, short crdAxMask,
	long *pTgPosArray, double endVel, double vel,double synAcc ,short lookaheadDis);

// ����4ά�岹�£�A����������ת���ٶȣ������ڸ��ٶȣ�����Ҫ���н��ٴ���
MTN_API short  __stdcall NMC_CrdSetFourthAxisTolTurnVel(HAND crdHandle,double tolVel);

// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// crdAxMask:�������,��λ��ʾ
// pTgPosArray��Ŀ��λ������,����Ϊ3
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdLineXYZEx(  HAND crdHandle,  long segNo, short crdAxMask,long *pTgPosArray,
	double endVel, double vel,double synAcc,short lookaheadDis );

// ����ֱ�߲岹�����֧��8�ᣩ
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// crdAxmask:����ϵ�в������,��λ��ʾ
// extAxMask:����������,��λ��ʾ,���ܰ�������ϵ��
// pTgPosArray��Ŀ��λ������,����Ϊ���в����˶����������,
//              ����С��������ϵ�ڵ�������꣨��crdAxMaskλ���У��������������������������꣨��extAxMaskλ���У�
// lookaheadDis:�Ƿ�ʹ��ǰհ(��������������ϵ�е�����˶�),0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdLineXYZD8(  HAND crdHandle, long segNo, 
	long crdAxmask, long extAxMask, long *pTgPosArray,
	double endVel, double vel,double synAcc,short lookaheadDis );

// 8��岹�����Ԫ�ṹ��
typedef struct
{
    long segNo;         // �û��Զ���κ�
	short crdAxMask;
	short extAxMask;
    long  tgPos[8];     // Ŀ��λ��
	float vel;         // ����ٶ�
	float endVel;      // �յ��ٶ�
    float acc;			// �岹���ٶ�
	short lookaheadDis;	// �Ƿ�ʹ��ǰհ
	short reserved;		// ����
}TCrdLineXYZD8Unit;

// ����Ķ���ֱ�߲岹
// count:���ָ����,ȡֵ��Χ[1,18]
// pCmdArray:ָ���б�
MTN_API short __stdcall NMC_CrdLineXYZD8Pack(  HAND crdHandle, short count,  TCrdLineXYZD8Unit *pCmdArray);


// 4��岹�����Ԫ�ṹ��
typedef struct
{
    long segNo;         // �û��Զ���κ�
	short crdAxMask;
	short extAxMask;
    long  tgPos[4];     // Ŀ��λ��
	float vel;         // ����ٶ�
	float endVel;      // �յ��ٶ�
    float acc;      // �岹���ٶ�
	short lookaheadDis;	// �Ƿ�ʹ��ǰհ
	short reserved;		// ����
}TCrdLineXYZD4Unit;

// �����4��ֱ�߲岹
// count:���ָ����,ȡֵ��Χ[1,25]
// pCmdArray:ָ���б�
MTN_API short __stdcall NMC_CrdLineXYZD4Pack(  HAND crdHandle, short count,  TCrdLineXYZD4Unit *pCmdArray);

typedef struct
{
    long segNo;         // �û��Զ���κ�
    long  tgPos[3];     // Ŀ��λ��
    double endVel;      // �յ��ٶ�
    double vel;         // ����ٶ�
    double synAcc;      // �岹���ٶ�
    short mask;         // �������,��λ��ʾ
	short lookaheadDis;	// �Ƿ�ʹ��ǰհ
    short reserved[2];  // ����
}TCrdLineXYZUnit;
// �����ֱ�߲岹
// count:���ָ����,ȡֵ��Χ[1,20]
// pCmdArray:ָ���б�
MTN_API short __stdcall NMC_CrdLineXYZPack(  HAND crdHandle, short count,  TCrdLineXYZUnit *pCmdArray);

// XYƽ��Բ���岹���յ�λ�á��뾶������
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// radius:Բ���뾶,����0��ʾ�ӻ�,С��0��ʾ�Ż�
// pTgPosArray��Ŀ��λ�����飨��ά����,�ֱ��ʾXY��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
MTN_API short __stdcall NMC_CrdArcRadius(  HAND crdHandle, long segNo,long *pTgPosArray, double radius, short circleDir,double endVel, double vel,double synAcc );

// YZƽ��Բ���岹���յ�λ�á��뾶������
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// radius:Բ���뾶,����0��ʾ�ӻ�,С��0��ʾ�Ż�
// pTgPosArray��Ŀ��λ�����飨��ά����,�ֱ��ʾYZ��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
MTN_API short __stdcall NMC_CrdArcRadiusYZ(  HAND crdHandle, long segNo,
	long *pTgPos, double radius, short circleDir,double velEnd, double vel,double synAcc );

// ZXƽ��Բ���岹���յ�λ�á��뾶������
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// radius:Բ���뾶,����0��ʾ�ӻ�,С��0��ʾ�Ż�
// pTgPosArray��Ŀ��λ�����飨��ά����,�ֱ��ʾZX��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
MTN_API short __stdcall NMC_CrdArcRadiusZX(  HAND crdHandle, long segNo,
	long *pTgPos, double radius, short circleDir,double velEnd, double vel,double synAcc );

// XYƽ��Բ���岹���յ�λ�á��뾶������
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// radius:Բ���뾶,����0��ʾ�ӻ�,С��0��ʾ�Ż�
// pTgPosArray��Ŀ��λ�����飨��ά����,�ֱ��ʾXY��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdArcRadiusEx(  HAND crdHandle, long segNo,long *pTgPosArray, double radius, 
								short circleDir,double endVel, double vel,double synAcc ,short lookaheadDis);

// YZƽ��Բ���岹���յ�λ�á��뾶������
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// radius:Բ���뾶,����0��ʾ�ӻ�,С��0��ʾ�Ż�
// pTgPosArray��Ŀ��λ�����飨��ά����,�ֱ��ʾYZ��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdArcRadiusYZEx(  HAND crdHandle, long segNo,long *pTgPos, double radius, 
	short circleDir,double velEnd, double vel,double synAcc ,short lookaheadDis);

// ZXƽ��Բ���岹���յ�λ�á��뾶������
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// radius:Բ���뾶,����0��ʾ�ӻ�,С��0��ʾ�Ż�
// pTgPosArray��Ŀ��λ�����飨��ά����,�ֱ��ʾZX��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdArcRadiusZXEx(  HAND crdHandle, long segNo,long *pTgPos, double radius, 
	short circleDir,double velEnd, double vel,double synAcc ,short lookaheadDis);

// XYƽ��Բ���岹���յ�λ�á�Բ�ġ�����
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pCenterPosArray:Բ�����꣨��ά����,�ֱ��ʾXY�����������Բ��λ�ã�,ע�⣺Բ������Ϊ������������λ��
// pTgPosArray��Ŀ��λ�ã���ά����,�ֱ��ʾXY���Ŀ��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
MTN_API short __stdcall NMC_CrdArcCenter(  HAND crdHandle, long segNo,long *pTgPosArray, long *pCenterPosArray,short circleDir,double endVel, double vel,double synAcc );

// YZƽ��Բ���岹���յ�λ�á�Բ�ġ�����
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pCenterPosArray:Բ�����꣨��ά����,�ֱ��ʾYZ�����������Բ��λ�ã�,ע�⣺Բ������Ϊ������������λ��
// pTgPosArray��Ŀ��λ�ã���ά����,�ֱ��ʾYZ���Ŀ��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
MTN_API short __stdcall NMC_CrdArcCenterYZ(  HAND crdHandle, long segNo,long *pTgPos, 
	long *pCenterPos,short circleDir,double velEnd, double vel,double synAcc );

// ZXƽ��Բ���岹���յ�λ�á�Բ�ġ�����
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pCenterPosArray:Բ�����꣨��ά����,�ֱ��ʾZX�����������Բ��λ�ã�,ע�⣺Բ������Ϊ������������λ��
// pTgPosArray��Ŀ��λ�ã���ά����,�ֱ��ʾZX���Ŀ��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
MTN_API short __stdcall NMC_CrdArcCenterZX(  HAND crdHandle, long segNo,long *pTgPos, 
	long *pCenterPos,short circleDir,double velEnd, double vel,double synAcc );

// XYƽ��Բ���岹���յ�λ�á�Բ�ġ�����
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pCenterPosArray:Բ�����꣨��ά����,�ֱ��ʾXY�����������Բ��λ�ã�,ע�⣺Բ������Ϊ������������λ��
// pTgPosArray��Ŀ��λ�ã���ά����,�ֱ��ʾXY���Ŀ��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdArcCenterEx(  HAND crdHandle, long segNo,long *pTgPosArray, long *pCenterPosArray,
										short circleDir,double endVel, double vel,double synAcc ,short lookaheadDis);

// YZƽ��Բ���岹���յ�λ�á�Բ�ġ�����
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pCenterPosArray:Բ�����꣨��ά����,�ֱ��ʾZX�����������Բ��λ�ã�,ע�⣺Բ������Ϊ������������λ��
// pTgPosArray��Ŀ��λ�ã���ά����,�ֱ��ʾYZ���Ŀ��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdArcCenterYZEx(  HAND crdHandle, long segNo,long *pTgPos, long *pCenterPos,
    short circleDir,double velEnd, double vel,double synAcc ,short lookaheadDis);

// ZXƽ��Բ���岹���յ�λ�á�Բ�ġ�����
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pCenterPosArray:Բ�����꣨��ά����,�ֱ��ʾZX�����������Բ��λ�ã�,ע�⣺Բ������Ϊ������������λ��
// pTgPosArray��Ŀ��λ�ã���ά����,�ֱ��ʾZX���Ŀ��λ�ã�
// circleDir:Բ������,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdArcCenterZXEx(  HAND crdHandle, long segNo,long *pTgPos, long *pCenterPos,
    short circleDir,double velEnd, double vel,double synAcc ,short lookaheadDis);

// XYƽ��Բ���岹����㣨��ǰ�㣩���е㡢�յ�
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pMidPosArray:�м�λ�õ����꣨��ά����,�ֱ��ʾ�м���XY���λ�ã�
// pTgPosArray���յ�λ�����꣨��ά����,�ֱ��ʾ�յ��XY���λ�ã�
MTN_API short __stdcall NMC_CrdArcPPP(  HAND crdHandle,long segNo, long *pMidPosArray, long *pTgPosArray, double endVel, double vel,double synAcc );

// XYƽ��Բ���岹����㣨��ǰ�㣩���е㡢�յ�
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pMidPosArray:�м�λ�õ����꣨��ά����,�ֱ��ʾ�м���XY���λ�ã�
// pTgPosArray���յ�λ�����꣨��ά����,�ֱ��ʾ�յ��XY���λ�ã�
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdArcPPPEx(  HAND crdHandle,long segNo, long *pMidPosArray, long *pTgPosArray, 
												double endVel, double vel,double synAcc ,short lookaheadDis);
// ��Բ�岹��Ĭ�ϲ������ٶ�ǰհ����ʼ����ֹ�ٶ�Ϊ0��ע�⣡��ԲΪ��Բ��
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pCenterPos����ԲԲ�ĵ�λ�ã���ά����,�ֱ��ʾ�е��XY���λ�ã���ע�⣡���λ�õ�Բ��λ��Ϊ�����
// abRatio:��ʾ��ԲAB��ĳ��ȱ���ֵ ֵ��Χ��[0.05,1]
// ellipseDir:��Բ�滭����,0��ʾ˳ʱ�뷽��,1��ʾ��ʱ�뷽��
MTN_API short __stdcall NMC_CrdEllipse(  HAND crdHandle, long segNo,double abRatio, long *pCenterPos,short ellipseDir, double vel,double synAcc);

// �����߲岹
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pTgPosArray��Ŀ��λ�ã���ά����,�ֱ��ʾ�յ��XYZ���λ�ã�
// pCenterPosArray:Բ��λ�ã���ά����,�ֱ��ʾXY�����������Բ��λ�ã�,ע�⣺Բ������Ϊ������������λ��
// rounds: Z����Ȧ��
MTN_API short __stdcall NMC_CrdHelixCenter(  HAND crdHandle, long segNo, long *pTgPosArray, long *pCenterPosArray,short circleDir,double rounds, double endVel, double vel,double synAcc );

// �����߲岹
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pTgPosArray��Ŀ��λ�ã���ά����,�ֱ��ʾ�յ��XYZ���λ�ã�
// pCenterPosArray:Բ��λ�ã���ά����,�ֱ��ʾXY�����������Բ��λ�ã�,ע�⣺Բ������Ϊ������������λ��
// rounds: Z����Ȧ��
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdHelixCenterEx(  HAND crdHandle, long segNo, long *pTgPosArray, long *pCenterPosArray,short circleDir,
														double rounds, double endVel, double vel,double synAcc ,short lookaheadDis);

// 3DԲ���岹
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pMidPos���е�λ�ã���ά����,�ֱ��ʾ�е��XYZ���λ�ã�
// pTgPos:�յ�λ�ã���ά����,�ֱ��ʾ�յ��XYZ���λ�ã�
MTN_API short __stdcall NMC_CrdArc3D(  HAND crdHandle,long segNo, long *pMidPos, long *pTgPos,
									double velEnd, double vel,double synAcc );

// 3DԲ���岹
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pMidPos���е�λ�ã���ά����,�ֱ��ʾ�е��XYZ���λ�ã�
// pTgPos:�յ�λ�ã���ά����,�ֱ��ʾ�յ��XYZ���λ�ã�
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdArc3DEx(  HAND crdHandle,long segNo, long *pMidPos, long *pTgPos,
									double velEnd, double vel,double synAcc ,short lookaheadDis);

// 3DԲ���岹(��Բ)
// segNo:�κţ�endVel:�յ��ٶ�;vel:����ٶ�;synAcc:�ϳɼ��ٶ�
// pMidPos���е�λ�ã���ά����,�ֱ��ʾ�е��XYZ���λ�ã�
// pTgPos:�յ�λ�ã���ά����,�ֱ��ʾ�յ��XYZ���λ�ã�
// lookaheadDis:�Ƿ�ʹ��ǰհ,0��ʹ��ǰհ,��������Զ������յ��ٶ�,1������ǰհ,ʹ���趨���յ��ٶȣ�endVel��
MTN_API short __stdcall NMC_CrdCircle3DEx(  HAND crdHandle,long segNo, long *pMidPos, long *pTgPos,
									double velEnd, double vel,double synAcc ,short lookaheadDis);

// ���������DO�鶨��
#define CRD_BUFF_DO_MOTOR_ENABLE            1   // ���ʹ��
#define CRD_BUFF_DO_MOTOR_CLEAR             2   // ����������
#define CRD_BUFF_DO_GPDO1                   3   // ͨ�����1
#define CRD_BUFF_DO_GPDO2                   4   // ͨ�����2
#define CRD_BUFF_DO_EXTDO1					5	// ��չģ��1
#define CRD_BUFF_DO_EXTDO2					6	// ��չģ��2
#define CRD_BUFF_DO_EXTDO3					7	// ��չģ��3
#define CRD_BUFF_DO_EXTDO4					8	// ��չģ��4
#define CRD_BUFF_DO_EXTDO5					9	// ��չģ��5
#define CRD_BUFF_DO_EXTDO6					10	// ��չģ��6

// ������DO
// segNo:�κ�
// doType:Do����,���궨��
// ch��λ���,ȡֵ��Χ[0,31]
// value�����ֵ,ȡֵ��Χ[0,1]
MTN_API short __stdcall NMC_CrdBufDo( HAND crdHandle, long segNo, short doType,   long  ch,  long  value);

// ������DO
// segNo:�κ�
// gourp:Do���,���궨��
// doMask��λ����
// doValue�����ֵ
MTN_API short  __stdcall NMC_CrdBufDoEx(HAND crdHandle,long segNo,short group,long doMask,long doValue);

// ͨ�����������
#define BUF_OUT_GROUP_DA        (0)             // ģ�������
#define BUF_OUT_GROUP_PWM       (1)             // PWM���
// ���������
// segNo:�κ�
// gourp:���,���궨��
// ch��ͨ����,ȡֵ��Χ[0,n]
// value�����ֵ
MTN_API short __stdcall NMC_CrdBufOut( HAND crdHandle,  long segNo, short group, short ch, long  value);

// ������DI�ȴ�
// index:ͨ����,ȡֵ��Χ[0,127],ǰ64ͨ������ͨ��DI����64ͨ��������չIO
// diValue���ȴ�ֵ
// waitLastTime����ʱ,��λ������
MTN_API short __stdcall NMC_CrdBufWaitDI(HAND crdHandle, long segNo,short index,short diValue,long waitLastTime);

// �������ȴ�
// waitType:�ȴ����ͣ�0���ڲ�������1��DO״̬
// index:ͨ���ţ������ڲ�������ȡֵ��Χ[0,1],����DO��ȡֵ��Χ[0,63]
// waitValue���ȴ�ֵ
// waitTimeInMs����ʱ,��λ������
MTN_API short __stdcall NMC_CrdBufWait(HAND crdHandle, long segNo,short waitType,short index,long waitValue,long waitTimeInMs);

// ����:�������ȴ�����˶���λ
// segNo:�κ�
// axisMask:��Ҫ�ȴ���λ�������루��λ��Ӧ���,���ܳ��������������������
// overTime:�ȴ���λ��ʱ��ʱ�䣬��λ��ms
MTN_API short  __stdcall NMC_CrdBufWaitEncInPosition(HAND crdHandle,long segNo,long axisMask,long overTime);

// ����:�������ȴ��ض�λ�ã�����������ִ����һ��ָ��
// segNo:�κ�
// axisNo:��Ҫ�ȴ���λ�����
// condition:��λ������0��С�ڵ����趨λ��  1�����ڵ����趨λ��
// pos:�趨λ��
// posSrc:�ȴ��滮���Ǳ�������0�������� 1���ڲ��滮
// overTime:�ȴ���λ��ʱ��ʱ�䣬��λ��ms
MTN_API short  __stdcall NMC_CrdBufWaitPos(HAND crdHandle,long segNo,short axisNo,
    short condition,long pos,short posSrc,long overTime);

// ��������ʱ��λ
#define CRD_BUFF_DELAY_SCALE_MS             0   // ����
#define CRD_BUFF_DELAY_SCALE_SECAND         1   // ��
// ��������ʱ
// segNo:�κ�
// scale:��ʱ��λ,0��ʾ��λΪ����,1��ʾ��λΪ��
// count����ʱʱ��
MTN_API short __stdcall NMC_CrdBufDelay( HAND crdHandle, long segNo, short scale, long  count);

// �����������ƶ�(����λ���ƶ�)
// segNo:�κ�
// axisMask:�������
// pTgPos��Ŀ��λ��
// blockEn:�Ƿ�Ϊ����ģʽ
// synEn���Ƿ�Ϊͬ��ģʽ,���synEn��blockEnͬʱΪ1,��ͬ������
MTN_API short __stdcall NMC_CrdBufAxMove( HAND crdHandle,  long segNo, short axisMask,long *pTgPos,short blockEn ,short synEn);

// �����������ƶ�(������)
// segNo:�κ�
// axisMask:�������
// pTgPos��Ŀ��λ��
// vel:�ٶ�
// acc:���ٶ�
// blockEn:�Ƿ�Ϊ����ģʽ
// synEn���Ƿ�Ϊͬ��ģʽ,���synEn��blockEnͬʱΪ1,��ͬ������
MTN_API short  __stdcall NMC_CrdBufAxMoveEx(HAND crdHandle,long segNo,short axisMask,long *pTgPos,
	double vel,double acc,short blockEn ,short synEn);

// �����������ƶ�(���λ���ƶ�)
// segNo:�κ�
// axisMask:�������
// pRelPos������ƶ�λ��
// blockEn:�Ƿ�Ϊ����ģʽ
// synEn���Ƿ�Ϊͬ��ģʽ,���synEn��blockEnͬʱΪ1,��ͬ������
MTN_API short __stdcall NMC_CrdBufAxMoveRel( HAND crdHandle,  long segNo, short axisMask,long *pRelPos,short blockEn ,short synEn);

// �����������ƶ���������
// segNo:�κ�
// axisNo�����,[0,n]
// vel:�˶��ٶ�
// acc:�˶����ٶ�
// smoothCoef:ƽ��ϵ��
MTN_API short __stdcall NMC_CrdBufSetPtpMovePara(HAND crdHandle, long segNo,short axisNo,double vel,double acc,short soomthCoef);

// ����������
// segNo:�κ�
// onOff:����
MTN_API short __stdcall NMC_CrdBufValueFollow ( HAND crdHandle ,  long segNo, short onOff );

// ���������üӹ����淶Χ��������Χ��ֹͣ�˶�
// crdAxMask:�Ƿ񼤻��������	��λ�����ж� ��bit0~2���ֱ��ӦXYZ�� 1��������0 �ر�
// pXMax: pXMax[0]ΪX����С�г̱߽�	pXMax[1]ΪX������г̱߽�  pXMax[2]ΪX��������ʱ�ȴ��Ĳο�λ��
// pYMax��pZMax ͬpXMax˵��
MTN_API short __stdcall NMC_CrdBufSetScaleLimit ( HAND crdHandle,long segNo,
    short crdAxMask,long *pXMax,long *pYMax,long *pZMax);

// ���ø����˶�ǰ���˶�������
// axis:���  0~N
//relDistance����Բ���λ����
//vel�������ٶ�
MTN_API short  __stdcall NMC_CrdBufBeforeAxSyncMove(HAND crdHandle, long segNo,short axis,long relDistance,double vel);

// ��������ϵ�ٶȱ���
// overRide������ϵ�ٶȱ���,ȡֵ��Χ(0,10)
MTN_API short __stdcall NMC_CrdSetOverRide( HAND crdHandle, double overRide );

//------------------------------------------------------------------------------------------------------------
//
//        10.����
//
//------------------------------------------------------------------------------------------------------------
// �������Ͷ���                                                 
// ����ģʽ    ��ԭ��      ����λ     ��Z��    ԭ��+Z�� ԭ��+ -Z��  ��λ+ -Z��
typedef enum { HM_MODE1=0, HM_MODE2, HM_MODE3, HM_MODE4, HM_MODE5, HM_MODE6 } THomeMode;

// �����������
typedef struct
{
    short  mode;                    // ģʽ,HM_MODE1 ~ HM_MODE6 �����룩
    short  dir;                     // ��Ѱ��㷽�򣨱��룩, 0:����,1������,����ֵ������
    long    offset;                 // ԭ��ƫ�ƣ����룩
    double  scan1stVel;             // ������Ѱ�ٶȣ����룩
    double  scan2ndVel;             // ���٣�������Ѱʱ��Ҫ��
    // ��usePreSetPtpPara=0ʱ,�����˶��ļ����ٶ�Ĭ�ϵ���acc,�����ٶȡ��յ��ٶȡ�ƽ��ϵ��Ĭ��Ϊ0
    double  acc;                    // ���ٶ�
    
    unsigned char reScanEn;         // �Ƿ�������Ѱ��㣨��ѡ,����ʱ��Ϊ0��
    unsigned char homeEdge;         // ԭ��,�����أ�Ĭ���½��أ�
    unsigned char lmtEdge;          // ��λ,�����أ�Ĭ���½��أ�
    unsigned char zEdge;            // ��λ,�����أ�Ĭ���½��أ�
    unsigned long iniRetPos;        // ��ʼ�����˶����루��ѡ,����ʱ��Ϊ0��
    unsigned long retSwOffset;      // �����˶�ʱ�뿪���ؾ��루��ѡ,����ʱ��Ϊ0��
    unsigned long safeLen;          // ��ȫ����,����ʱ��Զ��Ѱ���루��ѡ,����ʱ��Ϊ0,�����ƾ��룩
    unsigned char usePreSetPtpPara; // Ϊ1��ʾ�û���Ҫ����������ǰ,�Լ����û����˶����㵽�㣩�Ĳ���
    unsigned char reserved[3];      // ����
    long reserved2;                 // ����
} THomeSetting;
// ���û������
// pHomePara: ��������ṹ,�ο��ṹ����
MTN_API short __stdcall NMC_MtSetHomePara( HAND axisHandle, THomeSetting *pHomePara );

// ����״̬��λ���� 
#define BIT_AXHOME_BUSY         (0x00000001)    // bit 0  , æ    
#define BIT_AXHOME_OK           (0x00000002)    // bit 1  , �ɹ�  
#define BIT_AXHOME_FAIL         (0x00000004)    // bit 2  , ʧ��  
#define BIT_AXHOME_ERR_MV       (0x00000008)    // bit 3  , �����˶����������²��� 
#define BIT_AXHOME_ERR_SWT      (0x00000010)    // bit 4  , ������Ѱ�����п���û���� 
// ������״̬
// pStsWord: ����״̬�֡������궨��,��8λΪ�������
MTN_API short __stdcall NMC_MtGetHomeSts(HAND axisHandle, short *pStsWord );

// ��������
MTN_API short __stdcall NMC_MtHome(HAND axisHandle );

// �����Ի��㣨���Ի������,����λ�ã�
MTN_API short __stdcall NMC_MtTryHome( HAND axisHandle );

// ��ֹ����
MTN_API short __stdcall NMC_MtHomeStop(HAND axisHandle );

// ���»���λ�ú���ʷ����λ�õĲ�ֵ
// pErrPos: ����λ��ƫ��
// ע������ɹ�ʱ��������
MTN_API short __stdcall NMC_MtGetHomeError( HAND axisHandle, long *pErrPos );





//------------------------------------------------------------------------------------------------------------
//
//        11.���ӳ���
//
//------------------------------------------------------------------------------------------------------------
// ����Gear���淽��
// dir��  0:˫����棬<0������棬 >0�������
MTN_API short  __stdcall NMC_MtGearSetDir(HAND axisHandle,short dir);

// ��ȡGear���淽��
// pDir��  0:˫����棬<0������棬 >0�������
MTN_API short  __stdcall NMC_MtGearGetDir(HAND axisHandle,short *pDir);

// ����Gear�������
// axisHandle������������
// masterNo��  �������кţ�0~N��
// masterType��  ��������  1:AXIS�滮ֵ  2��AXIS����ֵ 3��������ֵ
MTN_API short  __stdcall NMC_MtGearSetMaster(HAND axisHandle,short masterNo,short masterType);

// ��ȡGear�������
// pMasterNo��  �������кţ�0~N��
// pMasterType��  ��������
MTN_API short  __stdcall NMC_MtGearGetMaster(HAND axisHandle,short *pMasterNo,short *pMasterType);

// ����Gear���汶��
// axisHandle������������
// masterEven�� ������ϵ��������λ��
// slaveEven��  ������ϵ��������λ��
// masterSlope�����������λ��,�������0��ͬʱ���ܵ���1
MTN_API short  __stdcall NMC_MtGearSetRatio(HAND axisHandle,long masterEven,long slaveEven,long masterSlope);

// ��ȡGear���汶��
// axisHandle������������
// pMasterEven�� ������ϵ��������λ��
// pSlaveEven��  ������ϵ��������λ��
// pMasterSlope�����������λ��,�������0��ͬʱ���ܵ���1
MTN_API short  __stdcall NMC_MtGearGetRatio(HAND axisHandle,long *pMasterEven,long *pSlaveEven,long *pMasterSlope);

// ����Gear�˶�
// syncCount�� ������axisHandle ������ͬ������������
// pSyncAxisArray: ����ͬ�����������ţ�0~N	
// ע��ͬ�������������ͬһ��������
MTN_API short  __stdcall NMC_MtGearStartMtn(HAND axisHandle,short syncAxCnts,short *pSyncAxArray);

//------------------------------------------------------------------------------------------------------------
//
//        12.����͹��
//
//------------------------------------------------------------------------------------------------------------
// ����FOLLOW���淽��
// dir��  0:˫����棬<0������棬 >0�������
MTN_API short  __stdcall NMC_MtFollowSetDir(HAND axisHandle,short dir);

// ��ȡFOLLOW���淽��
// pDir��  0:˫����棬<0������棬 >0�������
MTN_API short  __stdcall NMC_MtFollowGetDir(HAND axisHandle,short *pDir);

// FOLLOW�������������
#define PROFILE_FOLLOW_MASTER_NONE		   (0)	// 0:��Ч
#define PROFILE_FOLLOW_MASTER_AXIS_PRF     (1)	// 1:AXIS�滮ֵ
#define PROFILE_FOLLOW_MASTER_AXIS_ENC     (2)	// 2��AXIS����ֵ
#define PROFILE_FOLLOW_MASTER_ENC          (3)	// 3��������ֵ

// ����FOLLOW�������
// axisHandle������������
// masterNo��  �������кţ�0~N��
// masterType��  ��������  ������궨��
MTN_API short  __stdcall NMC_MtFollowSetMaster(HAND axisHandle,short masterNo,short masterType);

// ��ȡFOLLOW�������
// axisHandle������������
// pMasterNo��  �������кţ�0~N��
// pMasterType��  ��������  ������궨��
MTN_API short  __stdcall NMC_MtFollowGetMaster(HAND axisHandle,short *pMasterNo,short *pMasterType);

// ����FOLLOW��ѭ��ִ�д���
// loopCnt��ѭ��
MTN_API short  __stdcall NMC_MtFollowSetLoopCount(HAND axisHandle,long loopCnt);

// ��ȡFOLLOW��ѭ��ִ�д���
// pLoopCnt��ѭ��
MTN_API short  __stdcall NMC_MtFollowGetLoopCount(HAND axisHandle,long *pLoopCnt);

// FOLLOW�����¼�
#define PROFILE_FOLLOW_EVENT_START        (1)	// ��������
#define PROFILE_FOLLOW_EVENT_PASS         (2)	// ���ᴩԽ�趨λ���Ժ���������

// ����FOLLOW�ĵ������¼�
// eventType��1 ��ʾ��������ָ���Ժ�	����������2��ʾ	���ᴩԽ�趨λ���Ժ���������
// masterDir:��Խ����ʱ��������˶�����1 ���������˶���-1 ���Ḻ���˶�
// pos:��Խλ��
MTN_API short  __stdcall NMC_MtFollowSetEvent(HAND axisHandle,short eventType,short masterDir,long pos);

// ��ȡFOLLOW�������¼�
// pEvent��1 ��ʾ��������ָ���Ժ�����������2��ʾ���ᴩԽ�趨λ���Ժ���������
// pMasterDir:��Խ����ʱ��������˶�����1 ���������˶���-1 ���Ḻ���˶�
// pPos:��Խλ��
MTN_API short  __stdcall NMC_MtFollowGetEvent(HAND axisHandle,short *pEvent,short *pMasterDir,long *pPos);

// ��ȡFOLLOW��fifoʣ��ռ�
// pSpace���ռ��С
// fifoNo:fifo�ţ�0��1
MTN_API short  __stdcall NMC_MtFollowGetSpace(HAND axisHandle,short *pSpace,short fifoNo);

// FOLLOW�Ķ�����
#define PROFILE_FOLLOW_SEGMENT_NORMAL   	 (0)	// 0��ͨ��
#define PROFILE_FOLLOW_SEGMENT_EVEN     	 (1)	// 1���ٶ�
#define PROFILE_FOLLOW_SEGMENT_STOP     	 (2)	// 2ֹͣ��
#define PROFILE_FOLLOW_SEGMENT_CONTINUE 	 (3)	// 3������

// ����FOLLOW������
// masterPos������λ��
// slavePos:����λ��
// type:���ݶ����ͣ�0��ͨ�Σ�Ĭ�ϣ�1���ٶΣ�2 ���ٵ� 0 �Σ�3���� FIFO ֮���ٶ�����
// fifoNo:fifo�ţ�0��1
MTN_API short  __stdcall NMC_MtFollowPushData(HAND axisHandle,long masterPos,double slavePos,short type,short fifoNo);

// ���FOLLOW��Ӧfifo�ŵ�����
// fifoNo:fifo�ţ�0��1
MTN_API short  __stdcall NMC_MtFollowClear(HAND axisHandle,short fifoNo);

// ����Follow�˶�
// syncCount�� ������axisHandle ������ͬ������������
// pSyncAxisArray: ����ͬ�����������ţ�0~N	
MTN_API short  __stdcall NMC_MtFollowStart(HAND axisHandle,short syncAxCnts,short *pSyncAxArray);

// �л�Follow�˶���fifo��
// syncCount�� ������axisHandle ������ͬ������fifo�л���������
// pSyncAxisArray: ����ͬ������fifo�л��������ţ�0~N	
MTN_API short  __stdcall NMC_MtFollowSwitch(HAND axisHandle,short syncAxCnts,short *pSyncAxArray);


#ifdef __cplusplus
}
#endif


#endif  // _H_NMC_LIB20_H_
