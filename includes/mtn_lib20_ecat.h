///******************************************************************
//
// Moudle Name  :   mtn_lib20_ecat.h
// Abstract     :   GaoChuan Motion 2.0 ethercat user header 
// Note :			1.�ṹ�嶨�������еġ�reservedxxx���ĳ�Ա���Ǳ�������,Ϊ���ּ�����,������Ϊ0
//					  2.���ر�˵��,����API����RTN_CMD_SUCCESS����0ֵ����ʾִ�гɹ�,�������ʾ�������
//					  3.���е�API������,���ر�˵��,axisHandle��ʾ������ľ��,devHandle��ʾĿ��������ľ��,crdHandle��ʾĿ������ϵ����
//            4.mtn_lib20�����еĽṹ�嶼�������ֽڶ��뷽ʽ���룬Ϊ�˱���ṹ�������������⣬�뽫���뻷������Ϊ���ֽڶ���
// Modification History :
///******************************************************************
#ifndef _H_MTN_LIB20_ECAT_H_
#define _H_MTN_LIB20_ECAT_H_
#include "mtn_lib20.h"

#ifdef __cplusplus
extern "C" {
#endif
 

// ����Ethercat��վ
MTN_API short  __stdcall NMC_EcatStart(HAND devHandle);

// ֹͣEthercat��վ
MTN_API short  __stdcall NMC_EcatStop(HAND devHandle);

// ��ȡ��ǰ���ߵĴ�վ����
// pSlaveCnt:��վ������
// pDriverCnt:����������
// pIoCnt:IO���ʹ�վ����
MTN_API short  __stdcall NMC_EcatGetResource(HAND devHandle,short *pSlaveCnt,short *pDriverCnt,short *pIoCnt);

// ��ȡ��վ״̬
// pSts:����״̬��
//        bit0-bit7:��վ״̬��ȡֵ��0x01,0x02,0x03,0x04,0x08��
//                  0x01: INIT
//                  0x02: PREOP
//                  0x03: BOOT
//                  0x04: SAFEOP
//                  0x0: OP
//        bit8-bit11:״̬������
MTN_API short  __stdcall NMC_EcatGetSts(HAND devHandle,unsigned short *pSts);

// ���ô�վ�������Ĺ���ģʽ���û�һ�㲻��Ҫ����
// mode: Control Mode : CSP:8 CSV:9  CST:10
// axisHandle:������ͨ��NMC_MtOpen��ȡ��ethercat��վ��ı�Ŵ�16��ʼ
MTN_API short  __stdcall NMC_EcatAxisSetMode(HAND axisHandle,unsigned char mode);

// ��ȡ��վ�������Ĺ���ģʽ
// axisHandle:������ͨ��NMC_MtOpen��ȡ��ethercat��վ��ı�Ŵ�16��ʼ
MTN_API short  __stdcall NMC_EcatAxisGetMode(HAND axisHandle,unsigned char *pMode);

// ��ȡ��վ�������Ĵ������
// axisHandle:������ͨ��NMC_MtOpen��ȡ��ethercat��վ��ı�Ŵ�16��ʼ
MTN_API short  __stdcall NMC_EcatAxisGetErrorCode(HAND axisHandle,unsigned short *pError);

// ��ȡ��վ������������������״̬
// axisHandle:������ͨ��NMC_MtOpen��ȡ��ethercat��վ��ı�Ŵ�16��ʼ
MTN_API short  __stdcall NMC_EcatAxisGetDi(HAND axisHandle,long *pDiVal);

// �������㣬����״̬����ͨ��NMC_MtGetHomeSts��ѯ
// method:���㷽ʽ�����ݱ�׼��ֻ֧��402Ҫ�����ʵ�ֵģ�������ο���������ص�˵��
// velSwitch:��ԭ���ٶ�command/s
// velZero:��index�����ٶ�command/s
// acc:���ٶ�command/s^2
// prmEx:����
// axisHandle:������ͨ��NMC_MtOpen��ȡ��ethercat��վ��ı�Ŵ�16��ʼ
MTN_API short  __stdcall NMC_EcatStartHome(HAND axisHandle,long method,double velSwitch,double velZero,double acc,double prmEx);

// ��ȡ�������Ļ���״̬
MTN_API short  __stdcall NMC_EcatGetHomeSts(HAND axisHandle,unsigned char *pStatus);

// ��ֹ���� 
// axisHandle:������ͨ��NMC_MtOpen��ȡ��ethercat��վ��ı�Ŵ�16��ʼ
MTN_API short  __stdcall NMC_EcatStopHome(HAND axisHandle);

// Ethercat SDO ��
// devId:��վ��
// idx:SDO��Index
// sub_idx:SDO��SubIndex
// len:���ݳ���
// val:��������
// abort_code:������
MTN_API short  __stdcall NMC_EcatSdoRead(HAND devHandle,short devId,unsigned short idx, unsigned char sub_idx, unsigned int len, unsigned char *val, unsigned int *abort_code);

// Ethercat SDO д
// devId:��վ��
// idx:SDO��Index
// sub_idx:SDO��SubIndex
// len:���ݳ���
// val:��������
// abort_code:������
MTN_API short  __stdcall NMC_EcatSdoWrite(HAND devHandle,short devId,unsigned short idx, unsigned char sub_idx, unsigned int len, unsigned char *val, unsigned int *abort_code);

// ����Ethercat�����ļ��������ļ�ͨ�����ù������ɣ�
// gmlFileName:���ù���·��
// masterIdx:��վ��ţ�������д0
MTN_API short  __stdcall NMC_EcatLoadConfigFromFile(HAND devHandle,char *gmlFileName,short masterIdx);
 
#ifdef __cplusplus
}
#endif

#endif	// _H_MTN_LIB20_ECAT_H_
