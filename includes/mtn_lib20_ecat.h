///******************************************************************
//
// Moudle Name  :   mtn_lib20_ecat.h
// Abstract     :   GaoChuan Motion 2.0 ethercat user header 
// Note :			1.结构体定义中所有的‘reservedxxx’的成员都是保留参数,为保持兼容性,请设置为0
//					  2.无特别说明,所有API返回RTN_CMD_SUCCESS（即0值）表示执行成功,其他则表示错误代码
//					  3.所有的API参数中,无特别说明,axisHandle表示操作轴的句柄,devHandle表示目标控制器的句柄,crdHandle表示目标坐标系组句柄
//            4.mtn_lib20中所有的结构体都是以四字节对齐方式编译，为了避免结构体对齐引起的问题，请将编译环境设置为四字节对齐
// Modification History :
///******************************************************************
#ifndef _H_MTN_LIB20_ECAT_H_
#define _H_MTN_LIB20_ECAT_H_
#include "mtn_lib20.h"

#ifdef __cplusplus
extern "C" {
#endif
 

// 启动Ethercat主站
MTN_API short  __stdcall NMC_EcatStart(HAND devHandle);

// 停止Ethercat主站
MTN_API short  __stdcall NMC_EcatStop(HAND devHandle);

// 获取当前在线的从站数量
// pSlaveCnt:从站的总数
// pDriverCnt:驱动器数量
// pIoCnt:IO类型从站数量
MTN_API short  __stdcall NMC_EcatGetResource(HAND devHandle,short *pSlaveCnt,short *pDriverCnt,short *pIoCnt);

// 获取主站状态
// pSts:返回状态码
//        bit0-bit7:主站状态（取值：0x01,0x02,0x03,0x04,0x08）
//                  0x01: INIT
//                  0x02: PREOP
//                  0x03: BOOT
//                  0x04: SAFEOP
//                  0x0: OP
//        bit8-bit11:状态机步骤
MTN_API short  __stdcall NMC_EcatGetSts(HAND devHandle,unsigned short *pSts);

// 设置从站驱动器的工作模式，用户一般不需要调用
// mode: Control Mode : CSP:8 CSV:9  CST:10
// axisHandle:轴句柄，通过NMC_MtOpen获取，ethercat从站轴的编号从16开始
MTN_API short  __stdcall NMC_EcatAxisSetMode(HAND axisHandle,unsigned char mode);

// 获取从站驱动器的工作模式
// axisHandle:轴句柄，通过NMC_MtOpen获取，ethercat从站轴的编号从16开始
MTN_API short  __stdcall NMC_EcatAxisGetMode(HAND axisHandle,unsigned char *pMode);

// 获取从站驱动器的错误代码
// axisHandle:轴句柄，通过NMC_MtOpen获取，ethercat从站轴的编号从16开始
MTN_API short  __stdcall NMC_EcatAxisGetErrorCode(HAND axisHandle,unsigned short *pError);

// 获取从站驱动器的数字量输入状态
// axisHandle:轴句柄，通过NMC_MtOpen获取，ethercat从站轴的编号从16开始
MTN_API short  __stdcall NMC_EcatAxisGetDi(HAND axisHandle,long *pDiVal);

// 启动回零，回零状态可以通过NMC_MtGetHomeSts查询
// method:回零方式，根据标准，只支持402要求必须实现的，具体请参考驱动器相关的说明
// velSwitch:找原点速度command/s
// velZero:找index脉冲速度command/s
// acc:加速度command/s^2
// prmEx:保留
// axisHandle:轴句柄，通过NMC_MtOpen获取，ethercat从站轴的编号从16开始
MTN_API short  __stdcall NMC_EcatStartHome(HAND axisHandle,long method,double velSwitch,double velZero,double acc,double prmEx);

// 获取驱动器的回零状态
MTN_API short  __stdcall NMC_EcatGetHomeSts(HAND axisHandle,unsigned char *pStatus);

// 终止回零 
// axisHandle:轴句柄，通过NMC_MtOpen获取，ethercat从站轴的编号从16开始
MTN_API short  __stdcall NMC_EcatStopHome(HAND axisHandle);

// Ethercat SDO 读
// devId:从站号
// idx:SDO的Index
// sub_idx:SDO的SubIndex
// len:数据长度
// val:数据内容
// abort_code:错误码
MTN_API short  __stdcall NMC_EcatSdoRead(HAND devHandle,short devId,unsigned short idx, unsigned char sub_idx, unsigned int len, unsigned char *val, unsigned int *abort_code);

// Ethercat SDO 写
// devId:从站号
// idx:SDO的Index
// sub_idx:SDO的SubIndex
// len:数据长度
// val:数据内容
// abort_code:错误码
MTN_API short  __stdcall NMC_EcatSdoWrite(HAND devHandle,short devId,unsigned short idx, unsigned char sub_idx, unsigned int len, unsigned char *val, unsigned int *abort_code);

// 下载Ethercat配置文件（配置文件通过配置工具生成）
// gmlFileName:配置工具路径
// masterIdx:主站序号，保留，写0
MTN_API short  __stdcall NMC_EcatLoadConfigFromFile(HAND devHandle,char *gmlFileName,short masterIdx);
 
#ifdef __cplusplus
}
#endif

#endif	// _H_MTN_LIB20_ECAT_H_
