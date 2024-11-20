////*****************************************************************
// Moudle Name  :   nmc_lib20_err.h
// Abstract     :   错误代码定义
// Note :			‘//’之后为错误定义的说明，第二个'//'之后为错误的建议的处理方法
////*****************************************************************
#ifndef __H_MTN20_ERR_H__
#define __H_MTN20_ERR_H__

// 错误返回值类别:简洁模式
#define     RTN_LIB_UNSUPPORT           -1              // 库指令不支持 
#define     RTN_LIB_PARA_ERROR           -2              //库指令参数错不支持 
#define     RTN_DRV_ERROR                   -3              // 桢数据出错，指令桢长度超 
#define     RTN_FRAME_ERROR               -4              // 桢数据出错，指令桢长度超 
#define     RTN_FRAME_UNSUPPORT     -5              // 桢类型不支持错误         
#define     RTN_FRAME_TIMEOUT           -6              // 桢数据超时               
#define     RTN_FRAME_SUM_ERROR      -7              // 检验和错误               
#define     RTN_VEC_FHASE_ERROR        -8              // 矢量数据桢时序不支持     
#define     RTN_VEC_FIFO_FULL              -9              // 缓冲区满                                                           
#define     RTN_CMD_UNSUPPORT        -10              // 指令不支持               
#define     RTN_CMD_PARA_ERROR        -11              //参数1错，范围超出         
#define     RTN_CMD_EXE_ERROR           -12              // 执行失败                 
#define     RTN_CMD_PARA2_ERROR        -13             //参数2错，范围超出   
#define     RTN_CMD_PARA3_ERROR        -14             //参数3错，范围超出   
#define     RTN_CMD_PARA4_ERROR        -15             //参数4错，范围超出   
#define     RTN_CMD_PARA5_ERROR        -16             //参数5错，范围超出   
#define     RTN_CMD_PARA6_ERROR        -17             //参数6错，范围超出   
#define     RTN_CMD_PARA7_ERROR        -18             //参数7错，范围超出   
#define     RTN_CMD_PARA8_ERROR        -19             //参数8错，范围超出   
#define     RTN_CMD_PARA9_ERROR        -20             //参数9错，范围超出   
#define     RTN_CMD_PARA_OTHER         -21			   //其他错误     


// 错误代码
#define RTN_CMD_SUCCESS			0		        // 指令成功执行
#define RTN_CMD_TBD				999				// TBD

// return error code form Library,[1,99]
#define RTN_LIB_SEARCH_MODE						1	// NMC_DevSearch:不支持的搜索模式
#define RTN_LIB_OPEN_INDEX						2	// NMC_DevOpen:序号不能小于0
#define RTN_LIB_OPEN_COMM						3	// NMC_DevOpen:端口打开错误
#define RTN_LIB_OPEN_COMM2						4	// NMC_DevOpenByID:端口打开错误
#define RTN_LIB_ID_WRITE						5	// NMC_DevWriteID:写ID错误
#define RTN_LIB_ID_READ							6	// NMC_DevReadID:读ID错误
#define RTN_LIB_NOT_CONNECT						7	// NMC_CrdOpen:设备未打开
#define RTN_LIB_MT_INDEX						8	// NMC_MtOpen:序号小于0或者大于16
#define RTN_LIB_LINE_AXCNT						9	// NMC_CrdLineXYZ:轴数量范围不正确
#define RTN_LIB_LOCK							10	// 通讯锁错误
#define RTN_LIB_DEBUG_MODE						11	// NMC_SetCmdDebug:库Debug模式错误
#define RTN_LIB_DEBUG_FILE_CRT					12	// NMC_SetCmdDebug:debug文件创建
#define RTN_LIB_DEBUG_FILE_OPEN					13	// NMC_SetCmdDebug:debug文件打开
#define RTN_LIB_DEBUG_H_OPEN					14	// NMC_SetCmdDebug:通讯打开
#define RTN_LIB_CRDGetAxisPos_Cnt				15	// NMC_CrdGetAxisPos:cnts参数范围不正确[1,N]
#define RTN_LIB_CRDGetPos_Cnt					16	// NMC_CrdGetPrfPos的cnts参数范围不正确[1,N]
#define RTN_LIB_CRDGetEncPos_Cnt				17	// NMC_CrdGetEncPos的cnts参数范围不正确[1,N]
#define RTN_LIB_BackSramWrite_LEN				18	// NMC_BackSramWrite数据长度超出范围[1,240]
#define RTN_LIB_BackSramRead_LEN				19	// NMC_BackSramRead数据长度超出范围[1,240]
#define RTN_LIB_UserParaWr_LEN					20	// NMC_UserParaWr数据长度超出范围[1,240]
#define RTN_LIB_UserParaRd_LEN					21	// NMC_UserParaRd数据长度超出范围[1,240]
#define RTN_LIB_CRDLINEXYZPACK_Cnt				22	// NMC_CrdLineXYZPack:范围不正确，[1,5]
#define RTN_LIB_COLLECT_DATA_LEN				23	// NMC_GetCollectData:len
#define RTN_LIB_CONFIG_FILE						24	// NMC_SaveConfigToFile:配置文件错误
#define RTN_LIB_NOT_READY						25	// 自动返回没有准备好
#define RTN_LIB_AXIS_CNT						26	// 轴数量参数错误
#define RTN_LIB_DEV_COMM						27	// PCIE卡，实际通讯错误
#define RTN_LIB_CFG_FILE						28	// CFG文件错误：配置文件格式错误或者找不到某些轴的配置信息

// return error code form HostComm,[100,199]
#define RTN_COMM_PARA_LEN						100	// 参数长度不符合
#define RTN_COMM_CMD_UNSUPPORT					101	// 指令字不支持
#define RTN_COMM_TOP_UNSUPPORT					102	// 顶端指令字不支持
#define RTN_COMM_TOP_PARA						103	// 顶端参数错误
#define RTN_COMM_BACKSRAMREAD					104	// NMC_BackSramRead:参数错误//检查地址长度是否合理
#define RTN_COMM_BACKSRAMWRITE					105	// NMC_BackSramWrite:参数错误//检查地址长度是否合理
#define RTN_COMM_SYSUPGRADEEX					106	// NMC_SYSUPGRADEEX执行失败
#define RTN_COMM_DEVSETPARA						107	// NMC_DevSetPara执行失败
#define RTN_COMM_DEVGETPARA						108	// NMC_DevGetPara执行失败
#define RTN_COMM_GETTIME						109 // NMC_GetTime执行错误
#define RTN_COMM_USERPARAWR_PRM					110 // NMC_UserParaWr参数错误
#define RTN_COMM_USERPARAWR_EXE					111 // NMC_UserParaWr执行错误
#define RTN_COMM_USERPARARD_PRM					112 // NMC_UserParaRd参数错误

// return error code form Command
#define RTN_MC_MT_OPEN_INDEX						1000	// NMC_MtOpen:itemNo参数返回错误
#define RTN_MC_MT_LMT_POSSWT						1001	// NMC_MtLmtOnOff:posSwt参数范围不正确[0,1]
#define RTN_MC_MT_LMT_NEGSWT						1002	// NMC_MtLmtOnOff:negSwt参数范围不正确[0,1]
#define RTN_MC_MT_LMT_HANDLE						1003	// NMC_MtLmtOnOff:axisHandle错误
#define RTN_MC_MT_GETLMT_HANDLE						1004	// NMC_MtGetLmtOnOff:axisHandle错误
#define RTN_MC_MT_LMTSNS_POSSWT						1005	// NMC_MtLmtSns:posSwt参数范围不正确[0,1]
#define RTN_MC_MT_LMTSNS_NEGSWT						1006	// NMC_MtLmtSns:negSwt参数范围不正确[0,1]
#define RTN_MC_MT_LMTSNS_HANDLE						1007	// NMC_MtLmtSns:axisHandle错误
#define RTN_MC_MT_GETLMTSNS_HANDLE					1008	// NMC_MtGetLmtSns:axisHandle错误

#define RTN_MC_MT_ALMON_SWT							1010	// NMC_MtAlarmOnOff:swt参数范围不正确[0,1]
#define RTN_MC_MT_ALMON_HANDLE						1011	// NMC_MtAlarmOnOff:axisHandle错误
#define RTN_MC_MT_GETALMON_HANDLE					1012	// NMC_MtGetAlarmOnOff:axisHandle错误
#define RTN_MC_MT_ALMSns_SWT						1013	// NMC_MtAlarmSns:swt参数范围不正确[0,1]
#define RTN_MC_MT_ALMSns_HANDLE						1014	// NMC_MtAlarmSns:axisHandle错误
#define RTN_MC_MT_GETALSns_HANDLE					1015	// NMC_MtGetAlarmSns:axisHandle错误
#define RTN_MC_MT_SwLmtOn_SWT						1016	// NMC_MtSwLmtOnOff:swt参数范围不正确[0,1]
#define RTN_MC_MT_SwLmtOn_HANDLE					1017	// NMC_MtSwLmtOnOff:axisHandle错误
#define RTN_MC_MT_GetSwLmtOn_HANDLE					1018	// NMC_MtGetSwLmtOnOff:axisHandle错误
#define RTN_MC_MT_SwLmtV_POS						1019	// NMC_MtSwLmtValue:正向软限位值不应该小于等于负向
#define RTN_MC_MT_SwLmtV_HANDLE						1020	// NMC_MtSwLmtValue:axisHandle错误
#define RTN_MC_MT_GetSwLmtV_HANDLE					1021	// NMC_MtGetSwLmtValue:axisHandle错误
#define RTN_MC_MT_PosErr_VALUE						1022	// NMC_MtSetPosErrLmt:posErr位置误差不能小于0
#define RTN_MC_MT_PosErr_HANDLE						1023	// NMC_MtSetPosErrLmt:axisHandle错误
#define RTN_MC_MT_GetPosErr_HANDLE					1024	// NMC_MtGetPosErrLmt:axisHandle错误
#define RTN_MC_MT_SafePara_HANDLE					1025	// NMC_MtSetSafePara:axisHandle错误
#define RTN_MC_MT_SafeParaEdec						1026	// NMC_MtSetSafePara:estpDec必须大于0
#define RTN_MC_MT_SafeParaMaxV						1027	// NMC_MtSetSafePara:maxVel必须大于0
#define RTN_MC_MT_SafeParaMaxA						1028	// NMC_MtSetSafePara:maxAcc必须大于0
#define RTN_MC_MT_GetSafePara_HANDLE				1029	// NMC_MtGetSafePara:axisHandle错误
#define RTN_MC_SvrOn_HANDLE							1030	// NMC_MtSetSvOn:axisHandle错误
#define RTN_MC_SvrOff_HANDLE						1031	// NMC_MtSetSvOn:axisHandle错误
#define RTN_MC_SetPos_HANDLE						1032	// NMC_MtSetAxisPos:axisHandle错误
#define RTN_MC_SetEncPos_HANDLE						1033	// NMC_MtSetEncPos:axisHandle错误
#define RTN_MC_GetAPos_HANDLE						1034	// NMC_MtGetAxisPos:axisHandle错误
#define RTN_MC_GetPPos_HANDLE						1035	// NMC_MtGetPrfPos:axisHandle错误
#define RTN_MC_GetEPos_HANDLE						1036	// NMC_MtGetEncPos:axisHandle错误
#define RTN_MC_GetCPos_HANDLE						1037	// NMC_MtGetCmdPos:axisHandle错误
#define RTN_MC_SetCapSns_HANDLE						1038	// NMC_MtSetCaptSns:axisHandle错误
#define RTN_MC_GetCapSns_HANDLE						1039	// NMC_MtGetCaptSns:axisHandle错误
#define RTN_MC_SetCap_HANDLE						1040	// NMC_MtSetCapt:axisHandle错误
#define RTN_MC_GetCapPos_HANDLE						1041	// NMC_MtGetCaptPos:axisHandle错误
#define RTN_MC_GetSts_HANDLE						1042	// NMC_MtGetSts:axisHandle错误
#define RTN_MC_SetStepMode_HANDLE					1043	// NMC_MtSetStepMode:axisHandle错误
#define RTN_MC_SetStepMode_Mode						1044	// NMC_MtSetStepMode:mode参数范围错误[0,1]
#define RTN_MC_SetStepMode_Invert					1045	// NMC_MtSetStepMode:invert参数范围错误[0,1]
#define RTN_MC_GetStepMode_HANDLE					1046	// NMC_MtGetStepMode:axisHandle错误
#define RTN_MC_GetMIo_HANDLE						1047	// NMC_MtGetMotionIO:axisHandle错误
#define RTN_MC_GetStsP_Count						1048	// NMC_MtGetStsPack:axisHandle错误
#define RTN_MC_GetStsP_AxNum						1049	// NMC_MtGetStsPack:axisHandle错误
#define RTN_MC_SvClr_HANDLE							1050	// NMC_MtSetSvClr:axisHandle错误
#define RTN_IO_SetDo_GROUP							1051	// NMC_SetDO:groupID范围错误[0,n]
#define RTN_IO_GetDo_GROUP							1052	// NMC_GetDO:gourpID范围错误[0,n]
#define RTN_IO_SetDoBit_INDEX						1053	// NMC_SetDOBit:bitIndex错误
#define RTN_IO_SetDoBit_GROUP						1054	// NMC_SetDOBit:gourpID错误
#define RTN_IO_GetDi_GROUP							1055	// NMC_GetDI:gourpID错误
#define RTN_IO_GetDiBit_INDEX						1056	// NMC_GetDIBit:bitIndex错误
#define RTN_IO_GetDiBit_GROUP						1057	// NMC_GetDIBit:gourpID错误
#define RTN_IO_GetEncV_INDEX						1058	// NMC_GetEncVel:encId错误
#define RTN_IO_GetEncPos_INDEX						1059	// NMC_GetEncPos:axisHandle错误
#define RTN_MC_SetVar_ID							1060	// NMC_SetVar8B:varID错误
#define RTN_MC_GetVar_ID							1061	// NMC_GetVar8B:varID错误
#define RTN_MC_SysGetVar_ID							1062	// NMC_SysSetVar8B:varID错误
#define RTN_MC_SysSetVar_ID							1063	// NMC_SysGetVar8B:varID错误
#define RTN_MC_GetEncMode_ID						1064	// NMC_GetEncMode:encID错误
#define RTN_MC_SetEncMode_ID						1065	// NMC_SetEncMode:encID错误
#define RTN_MC_SetEncMode_MOVE						1066	// NMC_SetEncMode:正在运动，不能设置
#define RTN_MC_SetStepFilt_HANDLE					1067	// NMC_MtSetStepFilter:axisHandle错误
#define RTN_MC_PrfCfg_HANDLE						1068	// NMC_MtPrfConfig:axisHandle错误
#define RTN_MC_PrfCfg_PORT							1069	// NMC_MtPrfConfig:port范围错误[0,1]
#define RTN_MC_GetPrfCfg_HANDLE						1070	// NMC_MtGetPrfConfig:axisHandle错误
#define RTN_MC_SetPrfMode_HANDLE					1071	// NMC_MtSetPrfMode:axisHandle错误
#define RTN_MC_SetPrfMode_UNSUPPORT					1072	// NMC_MtSetPrfMode:模式不支持错误
#define RTN_MC_GetPrfMode_HANDLE					1073	// NMC_MtGetPrfMode:axisHandle错误
#define RTN_MC_SetPtpPrm_HANDLE						1074	// NMC_MtSetPtpPara:axisHandle错误
#define RTN_MC_SetPtpPrm_SVEL						1075	// NMC_MtSetPtpPara:startVel不能小于0
#define RTN_MC_SetPtpPrm_EVEL						1076	// NMC_MtSetPtpPara:endVel不能小于0
#define RTN_MC_SetPtpPrm_ACC						1077	// NMC_MtSetPtpPara:acc不能小于等于0
#define RTN_MC_SetPtpPrm_DEC						1078	// NMC_MtSetPtpPara:dec不能小于等于0
#define RTN_MC_SetPtpPrm_SMTH						1079	// NMC_MtSetPtpPara:smoothCoef不能小于0
#define RTN_MC_GetPtpPrm_HANDLE						1080	// NMC_MtGetPtpPara:axisHandle错误
#define RTN_MC_SetJogPrm_HANDLE						1081	// NMC_MtSetJogPara:axisHandle错误
#define RTN_MC_SetJogPrm_ACC						1082	// NMC_MtSetJogPara:acc不能小于等于0
#define RTN_MC_SetJogPrm_DEC						1083	// NMC_MtSetJogPara:dec不能小于等于0
#define RTN_MC_SetJogPrm_SMTH						1084	// NMC_MtSetJogPara:smoothCoef不能小于0
#define RTN_MC_GetJogPrm_HANDLE						1085	// NMC_MtGetJogPara:axisHandle错误
#define RTN_MC_SetVel_HANDLE						1086	// NMC_MtSetVel:axisHandle错误
#define RTN_MC_SetVel_VEL							1087	// NMC_MtSetVel:vel范围不正确,对于PTP（0,4500),对于JOG(-4500,4500)
#define RTN_MC_SetVel_VEL2							1088	// NMC_MtSetVel:vel范围不正确,对于PTP（0,4500),对于JOG(-4500,4500)
#define RTN_MC_GetVel_HANDLE						1089	// NMC_MtGetVel:axisHandle错误
#define RTN_MC_SetPtpTgtPos_HANDLE					1090	// NMC_MtSetPtpTgtPos:axisHandle错误
#define RTN_MC_SetPtpTgtPos_POS						1091	// NMC_MtSetPtpTgtPos:pos范围错误
#define RTN_MC_GetPtpTgtPos_HANDLE					1092	// NMC_MtGetPtpTgtPos:axisHandle错误
#define RTN_MC_UPDATE_HANDLE						1093	// NMC_MtUpdate:axisHandle错误
#define RTN_MC_STOP_HANDLE							1094	// NMC_MtStop:axisHandle错误
#define RTN_MC_ESTOP_HANDLE							1095	// NMC_MtEstp:axisHandle错误
#define RTN_MC_GetPrfVel_HANDLE						1096	// NMC_MtGetPrfVel:axisHandle错误
#define RTN_MC_ZeroPos_HANDLE						1097	// NMC_MtZeroPos:axisHandle错误
#define RTN_MC_ZeroPos_MOVE							1098	// NMC_MtZeroPos:正在运动，不能执行该操作

#define RTN_MC_CrdCfg_HANDLE						1099	// NMC_CrdConfig:crdHandle错误
#define RTN_MC_CrdCfg_DISABLE						1100	// NMC_CrdConfig:crd无法使用
#define RTN_MC_CrdCfg_AXIS							1101	// NMC_CrdConfig:参与轴数目错误
#define RTN_MC_CrdCfg_AXIS_INDEX					1102	// NMC_CrdConfig:参与轴序号错误
#define RTN_MC_CrdCfg_BUSY							1103	// NMC_CrdConfig:坐标系正在运动
#define RTN_MC_GetCrdCfg_HANDLE						1104	// NMC_CrdGetConfig:crdHandle错误
#define RTN_MC_CrdDel_HANDLE						1105	// NMC_CrdDelete:crdHandle错误
#define RTN_MC_CrdDel_BUSY							1106	// NMC_CrdDelete:坐标系正在运动,不能执行该操作
#define RTN_MC_CrdSetPrm_HANDLE						1107	// NMC_CrdSetPara:crdHandle错误
#define RTN_MC_CrdSetPrm_EN							1108	// NMC_CrdSetPara:坐标系未启用
#define RTN_MC_CrdSetPrm_ACC						1109	// NMC_CrdSetPara:synAccMax范围不正确，(0,max]
#define RTN_MC_CrdSetPrm_VEL						1110	// NMC_CrdSetPara:synVelMax范围不正确，(0,max]
#define RTN_MC_CrdGetPrm_HANDLE						1111	// NMC_CrdGetPara:crdHandle错误
#define RTN_MC_CrdGetPrm_EN							1112	// NMC_CrdGetPara:坐标系未启用
#define RTN_MC_CrdSetExtPrm_HANDLE					1113	// NMC_CrdSetExtPara:crdHandle错误
#define RTN_MC_CrdSetExtPrm_EN						1114	// NMC_CrdSetExtPara:坐标系未启用
#define RTN_MC_CrdSetExtPrm_T						1115	// NMC_CrdSetExtPara:T范围不正确，(0,max]
#define RTN_MC_CrdSetExtPrm_VEL						1116	// NMC_CrdSetExtPara:startVel范围不正确，[0,max]
#define RTN_MC_CrdSetExtPrm_EDEC					1117	// NMC_CrdSetExtPara:abruptDec范围不正确，(0,max]
#define RTN_MC_CrdSetExtPrm_SDEC					1118	// NMC_CrdSetExtPara:smoothDec范围不正确，(0,max]
#define RTN_MC_CrdGetExtPrm_HANDLE					1119	// NMC_CrdGetExtPara:crdHandle错误
#define RTN_MC_CrdGetExtPrm_EN						1120	// NMC_CrdGetExtPara:坐标系未启用
#define RTN_MC_StartMtn_HANDLE						1121	// NMC_CrdStartMtn:crdHandle错误
#define RTN_MC_StartMtn_EN							1122	// NMC_CrdStartMtn:坐标系未启用或者正在运动
#define RTN_MC_StopMtn_HANDLE						1123	// NMC_CrdStopMtn:crdHandle错误
#define RTN_MC_StopMtn_EN							1124	// NMC_CrdStopMtn:坐标系未启用
#define RTN_MC_EStopMtn_HANDLE						1125	// NMC_CrdEstopMtn:crdHandle错误
#define RTN_MC_EStopMtn_EN							1126	// NMC_CrdEstopMtn:坐标系未启用
#define RTN_MC_GetCrdSts_HANDLE						1127	// NMC_CrdGetSts:crdHandle错误
#define RTN_MC_GetCrdSts_EN							1128	// NMC_CrdGetSts:坐标系未启用
#define RTN_MC_GetCrdPos_HANDLE						1129	// NMC_CrdGetPrfPos:crdHandle错误
#define RTN_MC_GetCrdPos_EN							1130	// NMC_CrdGetPrfPos:坐标系未启用
#define RTN_MC_GetCrdPos_COUNT						1131	// NMC_CrdGetPrfPos:cnts范围不正确
#define RTN_MC_GetCrdVel_HANDLE						1132	// NMC_CrdGetVel:crdHandle错误
#define RTN_MC_GetCrdVel_EN							1133	// NMC_CrdGetVel:坐标系未启用
#define RTN_MC_SetOvrd_HANDLE						1134	// NMC_CrdSetOverRide:crdHandle错误
#define RTN_MC_SetOvrd_EN							1135	// NMC_CrdSetOverRide:坐标系未启用
#define RTN_MC_SetOvrd_OVERIDE						1136	// NMC_CrdSetOverRide:overRide范围错误
#define RTN_MC_GetOvrd_HANDLE						1137	// NMC_CrdGetOverRide:crdHandle错误
#define RTN_MC_GetOvrd_EN							1138	// NMC_CrdGetOverRide:坐标系未启用
#define RTN_MC_GetBufFree_HANDLE					1139	// NMC_CrdBufGetFree:crdHandle错误
#define RTN_MC_GetBufFree_EN						1140	// NMC_CrdBufGetFree:坐标系未启用
#define RTN_MC_GetBufUsed_HANDLE					1141	// NMC_CrdBufGetUsed:crdHandle错误
#define RTN_MC_GetBufUsed_EN						1142	// NMC_CrdBufGetUsed:坐标系未启用
#define RTN_MC_CrdBufClr_HANDLE						1143	// NMC_CrdBufClr:crdHandle错误
#define RTN_MC_CrdBufClr_EN							1144	// NMC_CrdBufClr:坐标系未启用
#define RTN_MC_GetSegNo_HANDLE						1145	// NMC_CrdGetUserSegNo:crdHandle错误
#define RTN_MC_GetSegNo_EN							1146	// NMC_CrdGetUserSegNo:坐标系未启用
#define RTN_MC_GetBufAllCnt_HANDLE					1147	// NMC_CrdGetBufAllCmdCnt:crdHandle错误
#define RTN_MC_GetBufAllCnt_EN						1148	// NMC_CrdGetBufAllCmdCnt:坐标系未启用
#define RTN_MC_EndMtn_HANDLE						1149	// NMC_CrdEndMtn:crdHandle错误
#define RTN_MC_EndMtn_EN							1150	// NMC_CrdEndMtn:坐标系未启用
#define RTN_MC_GetCrdEncPos_HANDLE					1151	// NMC_CrdGetEncPos:crdHandle错误
#define RTN_MC_GetCrdEncPos_EN						1152	// NMC_CrdGetEncPos:坐标系未启用
#define RTN_MC_GetCrdEncPos_COUNT					1153	// NMC_CrdGetEncPos:count范围错误
#define RTN_MC_CrdClrErr_HANDLE						1154	// NMC_CrdClrError:crdHandle错误
#define RTN_MC_CrdClrErr_EN							1155	// NMC_CrdClrError:坐标系未启用
#define RTN_MC_CrdSetVFolw_HANDLE					1156	// NMC_CrdSetValueFollow:crdHandle错误
#define RTN_MC_CrdSetVFolw_EN						1157	// NMC_CrdSetValueFollow:坐标系未启用
#define RTN_MC_CrdLineXYZ_HANDLE					1158	// NMC_CrdLineXYZ:crdHandle错误
#define RTN_MC_CrdLineXYZ_EN						1159	// NMC_CrdLineXYZ:坐标系未启用
#define RTN_MC_CrdLineXYZ_VEL						1160	// NMC_CrdLineXYZ:Vel范围不正确
#define RTN_MC_CrdLineXYZ_ACC						1161	// NMC_CrdLineXYZ:synAcc范围不正确
#define RTN_MC_CrdArcR_HANDLE						1162	// NMC_CrdArcRadius:crdHandle错误
#define RTN_MC_CrdArcR_EN							1163	// NMC_CrdArcRadius:坐标系未启用
#define RTN_MC_CrdArcR_VEL							1164	// NMC_CrdArcRadius:Vel范围不正确
#define RTN_MC_CrdArcR_ACC							1165	// NMC_CrdArcRadius:synAcc范围不正确
#define RTN_MC_CrdArcC_HANDLE						1166	// NMC_CrdArcCenter:crdHandle错误
#define RTN_MC_CrdArcC_EN							1167	// NMC_CrdArcCenter:坐标系未启用
#define RTN_MC_CrdArcC_VEL							1168	// NMC_CrdArcCenter:Vel范围不正确
#define RTN_MC_CrdArcC_ACC							1169	// NMC_CrdArcCenter:synAcc范围不正确
#define RTN_MC_CrdArcP_HANDLE						1170	// NMC_CrdArcPPP:crdHandle错误
#define RTN_MC_CrdArcP_EN							1171	// NMC_CrdArcPPP:坐标系未启用
#define RTN_MC_CrdArcP_VEL							1172	// NMC_CrdArcPPP:Vel范围不正确
#define RTN_MC_CrdArcP_ACC							1173	// NMC_CrdArcPPP:synAcc范围不正确
#define RTN_MC_CrdHelixC_HANDLE						1174	// NMC_CrdHelixCenter:crdHandle错误
#define RTN_MC_CrdHelixC_EN							1175	// NMC_CrdHelixCenter:坐标系未启用
#define RTN_MC_CrdHelixC_VEL						1176	// NMC_CrdHelixCenter:Vel范围不正确
#define RTN_MC_CrdHelixC_ACC						1177	// NMC_CrdHelixCenter:synAcc范围不正确
#define RTN_MC_CrdHelixC_ROUND						1178	// NMC_CrdHelixCenter:rounds范围不正确
#define RTN_MC_CrdBufDo_HANDLE						1179	// NMC_CrdBufDo:crdHandle错误
#define RTN_MC_CrdBufDo_EN							1180	// NMC_CrdBufDo:坐标系未启用
#define RTN_MC_CrdBufDo_GOURP						1181	// NMC_CrdBufDo:group范围不正确
#define RTN_MC_CrdBufDo_OPBITS						1182	// NMC_CrdBufDo:opbits范围不正确
#define RTN_MC_CrdBufOut_HANDLE						1183	// NMC_CrdBufOut:crdHandle错误
#define RTN_MC_CrdBufOut_EN							1184	// NMC_CrdBufOut:坐标系未启用
#define RTN_MC_CrdBufOut_CH							1185	// NMC_CrdBufOut:ch范围不正确
#define RTN_MC_CrdBufOut_GROUP						1186	// NMC_CrdBufOut:group范围不正确
#define RTN_MC_CrdBufDelay_HANDLE					1187	// NMC_CrdBufDelay:crdHandle错误
#define RTN_MC_CrdBufDelay_EN						1188	// NMC_CrdBufDelay:坐标系未启用
#define RTN_MC_CrdBufDelay_SCALE					1189	// NMC_CrdBufDelay:ch范围不正确
#define RTN_MC_CrdBufDelay_COUNT					1190	// NMC_CrdBufDelay:group范围不正确
#define RTN_MC_CrdBufDi_HANDLE						1191	// NMC_CrdBufWaitDI:crdHandle错误
#define RTN_MC_CrdBufDi_EN							1192	// NMC_CrdBufWaitDI:坐标系未启用
#define RTN_MC_CrdBufDi_INDEX						1193	// NMC_CrdBufWaitDI:index范围不正确
#define RTN_MC_CrdBufDi_COUNT						1194	// NMC_CrdBufWaitDI:waitTimeInMs范围不正确
#define RTN_MC_CrdBufAx_HANDLE						1195	// NMC_CrdBufAxMove:crdHandle错误
#define RTN_MC_CrdBufAx_EN							1196	// NMC_CrdBufAxMove:坐标系未启用
#define RTN_MC_CrdBufAx_AXIS						1197	// NMC_CrdBufAxMove:axisNum范围不正确
#define RTN_MC_BufSetPtpMovePara_HANDLE				1198	// NMC_CrdBufSetPtpMovePara:crdHandle错误
#define RTN_MC_BufSetPtpMovePara_EN					1199	// NMC_CrdBufSetPtpMovePara:坐标系未启用
#define RTN_MC_BufSetPtpMovePara_AXIS				1200	// NMC_CrdBufSetPtpMovePara:axis范围不正确
#define RTN_MC_BufSetPtpMovePara_VEL				1201	// NMC_CrdBufSetPtpMovePara:vel范围不正确
#define RTN_MC_BufSetPtpMovePara_ACC				1202	// NMC_CrdBufSetPtpMovePara:acc范围不正确
#define RTN_MC_BufSetPtpMovePara_SMTH				1203	// NMC_CrdBufSetPtpMovePara:smooth范围不正确
#define RTN_MC_CrdBufFollow_HANDLE					1204	// NMC_CrdBufWaitDI:crdHandle错误
#define RTN_MC_BufPushData_EN						1205	// NMC_CrdPushData:crdHandle错误
#define RTN_MC_BufPushData_HANDLE					1206	// NMC_CrdPushData:坐标系未启用

#define RTN_MC_INN_GetCenter_OVER					1207	// 插补指令圆弧参数错误//请检查圆弧参数是否符合
#define RTN_MC_INN_GetRad_OVER						1208	// 插补指令圆弧参数错误//请检查圆弧参数是否符合
#define RTN_MC_INN_GetCircDist_NULL					1209	// 插补指令圆弧参数错误//请检查圆弧参数是否符合
#define RTN_MC_INN_ARC_ONLYXY						1210	// 目前只支持XY平面的圆弧插补
#define RTN_MC_INN_ARC_ONLYXY2						1211	// 目前只支持XY平面的圆弧插补
#define RTN_MC_INN_ARC_ENDP							1212	// 圆弧终点不合理，过大或者过小
#define RTN_MC_INN_ARC_R_CIRCLE						1213	// 半径描述法，不支持描述整圆
#define RTN_MC_INN_ARC_R_CENTER						1214	// 圆心位置不合理
#define RTN_MC_INN_ARC_PPP_SAME						1215	// 3点重合
#define RTN_MC_INN_ARC_PPP_LINE						1216	// 3点共线
#define RTN_MC_INN_HELIX_NULL						1217	// 螺旋线数据为空
#define RTN_MC_INN_HELIX_ENDP						1218	// 螺旋线数据终点不合理，过大或者过小
#define RTN_MC_INN_HELIX_CIRCLE						1219	// 螺旋线不能描述整圆
#define RTN_MC_INN_HELIX_CENTER						1220	// 螺旋线圆心位置不合理
#define RTN_MC_INN_HELIX_POS						1221	// 螺旋线起点和终点不合理
#define RTN_MC_INN_HELIX_LEN						1222	// 螺旋线长度不合理
#define RTN_MC_INN_DOWNDATA_NULL					1223	// 下载数据为空
#define RTN_MC_INN_DA_CH							1224	// DAC通道范围不正确
#define RTN_MC_INN_DOWNLINE_NULL					1225	// 下载数据为空
#define RTN_MC_INN_DOWNLINE_POS						1226	// 下载数据位置不合理，过大或者过小
#define RTN_MC_INN_ENDVEL_ZERO						1227	// 计算的终点速度小于0
#define RTN_MC_INN_VEL_ZERO							1228	// 计算的目标速度小于0
#define RTN_MC_INN_ACC_ZERO							1229	// 计算的目标速度小于0
#define RTN_MC_INN_DOWNARC_NULL						1230	// 下载数据为空
#define RTN_MC_INN_ARC_Z							1231	// Z方向存在位移，目前支持XY平面
#define RTN_MC_INN_C_ENDPOS							1232	// 终点位置不合理，过大或者过小
#define RTN_MC_INN_CD_CIRCLE						1233	// 圆弧下载：半径描述法不能描述整圆
#define RTN_MC_INN_CD_CENTER						1234	// 圆弧下载：圆心坐标不合理
#define RTN_MC_INN_CD_PPP_S							1235	// 圆弧下载：三点重合
#define RTN_MC_INN_CD_PPP_L							1236	// 圆弧下载：三点共线
#define RTN_MC_INN_HELIX_D_NULL						1237	// 螺旋线数据为空
#define RTN_MC_INN_HELIX_D_ENDP						1238	// 螺旋线数据终点不合理，过大或者过小
#define RTN_MC_INN_HELIX_D_CIRCLE					1239	// 螺旋线不能描述整圆
#define RTN_MC_INN_HELIX_D_CENTER					1240	// 螺旋线圆心位置不合理
#define RTN_MC_INN_HELIX_D_POS						1241	// 螺旋线起点和终点不合理
#define RTN_MC_INN_HELIX_D_LEN						1242	// 螺旋线长度范围不正确
#define RTN_MC_INN_HELIX_D_VELEND					1243	// 螺旋线终点速度范围不正确
#define RTN_MC_INN_HELIX_D_VEL						1244	// 螺旋线速度范围不正确
#define RTN_MC_INN_HELIX_D_ACC						1245	// 螺旋线加速度范围不正确
#define RTN_MC_INN_CRV_TYPE							1246	// 指令类型异常
#define RTN_MC_INN_DS_NULL							1247	// 下层下发数据为空
#define RTN_MC_INN_DC_VEL							1248	// 圆弧计算速度超出范围
#define RTN_MC_INN_DC_ENDVEL						1249	// 圆弧计算速度超出范围
#define RTN_MC_INN_DC_ACC							1250	// 圆弧计算速度超出范围
#define RTN_MC_INN_DC_ENDPOS						1251	// 圆弧计算终点不合理，过大或者过小
#define RTN_MC_CRD_NO_SPACE							1252	// 插补缓冲区无数据
#define RTN_MC_MT_SetAxisFilter_Err					1253	// 设置轴速度滤波参数错误
#define RTN_MC_AX_ON_ALARM				1254	// axis on 条件不满足:伺服报警
#define RTN_MC_AX_ON_POSERR				1255	// axis on 条件不满足:位置越限
#define RTN_MC_EnableCrdSdram			1256	// 使能crd的sdram启用参数错误
#define RTN_MC_Sdram_no_Space			1257	// SDRAM无足够空间
#define RTN_MC_Push_Sdram_err			1258	// push数据到SDRAM错误
#define RTN_MC_AX_HOME_PARA				1259	// 回零临时，参数不正确
#define RTN_MC_CrdGetConfig_EN			1260	// NMC_CrdGetConfig获取参数时，未使能插补模块
#define RTN_MC_ClrCrdSts_HANDLE			1261	// NMC_ClrCrdSts句柄错误

#define RTN_MC_SetHomePara_HANDLE		1262	// NMC_MtSetHomePara句柄错误
#define RTN_MC_GetHomeSts_HANDLE		1263	// NMC_MtGetHomeSts句柄错误
#define RTN_MC_HomeStart_HANDLE			1264	// NMC_MtHome句柄错误
#define RTN_MC_HomeStop_HANDLE			1265	// NMC_MtHomeStop句柄错误
#define RTN_MC_GetHomeError_HANDLE		1266	// NMC_MtGetHomeError句柄错误
#define RTN_MC_GetHomePara_HANDLE		1267	// NMC_MtGetHomePara句柄错误
#define RTN_MC_TryHome_HANDLE			1268	// NMC_MtTryHome句柄错误
#define RTN_MC_HomeStartInNegLmt_HANDLE	1269	// NMC_MtHome或者NMC_MtTryHome调用时，电机负向限位触发，并且负向限位开关未输入句柄错误
#define RTN_MC_HomeStartInPosLmt_HANDLE	1270	// NMC_MtHome或者NMC_MtTryHome调用时，电机正向限位触发，并且正向限位开关未输入句柄错误
#define RTN_MC_HomeStartInAlarm_HANDLE	1271	// NMC_MtHome或者NMC_MtTryHome调用时，电机报警
#define RTN_MC_HomeStartInMoving_HANDLE	1272	// NMC_MtHome或者NMC_MtTryHome调用时，电机正在运动
#define RTN_MC_GetCrdAxisPos_HANDLE		1273	// NMC_CrdGetAxisPos句柄错误
#define RTN_MC_GetCrdAxisPos_EN			1274	// NMC_CrdGetAxisPos坐标系未初始化
#define RTN_MC_GetCrdAxisPos_COUNT		1275	// NMC_CrdGetAxisPos cnts参数错误
#define RTN_MC_CrdBufClr_CrdBusy		1276	// NMC_CrdBufClr Crd busy
#define RTN_MC_GetCrdStsPack3_HANDLE	1277	// NMC_CrdGetStsPack3句柄错误
#define RTN_MC_GetCrdStsPack3_EN		1278	// NMC_CrdGetStsPack3坐标系未初始化
#define RTN_MC_CrdSetExtPara_CrdBusy	1279	// NMC_CrdSetExtPara:当前坐标系正在运动
#define RTN_MC_CrdSetPara_CrdBusy		1280	// NMC_CrdSetPara:当前坐标系正在运动
#define RTN_MC_CrdConfig_CrdBusy		1281	// NMC_CrdConfig:当前坐标系正在运动
#define RTN_MC_CrdStartMtn_Mode			1282	// NMC_CrdStartMtn:启动时相关轴模式不对
#define RTN_MC_SetPrfMode_Busy			1283	// NMC_SetPrfMode:需要切换模式的轴处于busy状态
#define RTN_MC_MtUpdate_error			1284	// NMC_MtUpdate启动模式错误，当前轴模式不在该启动范围
#define RTN_MC_SetPrfCoe_HANDLE			1285	// NMC_MtSetPrfCoe:句柄错误
#define RTN_MC_GetPrfCoe_HANDLE			1286	// NMC_MtGetPrfCoe:句柄错误
#define RTN_MC_SetPrfCoe_Range			1287	// NMC_MtSetPrfCoe:系数范围不正确// inCoe有效范围：(0,1]
#define RTN_MC_SetPrfCoe_Busy			1288	// NMC_MtSetPrfCoe:轴忙，不能设置
#define RTN_MC_SetPrfCoe_PosNotZero		1289	// NMC_MtSetPrfCoe:当前位置不为0，不能设置// 先回原点，清除位置，然后再设置
#define RTN_MC_GetIOModuleSts_Unsupport	1290	// NMC_GetIOModuleSts:IO扩展模块不支持
#define RTN_MC_SetIOModuleEn_Param		1291	// NMC_SetIOModuleEn:参数错误，chDevId范围不正确
#define RTN_MC_SetIOModuleEn_Unsupport	1292	// NMC_SetIOModuleEn:IO扩展模块不支持
#define RTN_MC_GetDI_En					1293	// NMC_GetDI:对应IO模块未配置
#define RTN_MC_BackSramWrite_out_rang	1294	// NMC_BackSramWrite操作地址越界
#define RTN_MC_BackSramRead_out_rang	1295	// NMC_BackSramRead操作地址越界
#define RTN_MC_BackSramWrite_Len		1296	// NMC_BackSramWrite:写sram错误，写入长度不正确
#define RTN_MC_BackSramRead_Len			1297	// NMC_BackSramRead:读sram错误，读取长度不正确
#define RTN_MC_CrdLineXYZPack_Count		1298	// NMC_CrdLineXYZPack:count范围不正确[1,5]
#define RTN_MC_CrdLineXYZPack_Handle	1299	// NMC_CrdLineXYZPack:句柄错误
#define RTN_MC_CrdLineXYZPack_En		1300	// NMC_CrdLineXYZPack:坐标系未初始化
#define RTN_MC_CrdLineXYZPack_NoSpace	1301	// NMC_CrdLineXYZPack:没有足够的空间 // 检查空间是否足够
#define RTN_MC_CrdSetArcSecPara_Handle	1302	// NMC_CrdSetArcSecPara:句柄错误
#define RTN_MC_CrdSetArcSecPara_En		1303	// NMC_CrdSetArcSecPara:坐标系未初始化
#define RTN_MC_CrdSetArcSecPara_R_Rise	1304	// NMC_CrdSetArcSecPara:误差半径表的r值不符合，必须递增
#define RTN_MC_CrdSetArcSecPara_Err		1305	// NMC_CrdSetArcSecPara:误差半径表的err值不能小于等于0
#define RTN_MC_CrdSetArcSecPara_Diff	1306	// NMC_CrdSetArcSecPara:maxArcDiff范围不正确，不能小于1
#define RTN_MC_CrdSetArcSecPara_Sec		1307	// NMC_CrdSetArcSecPara:minSectionLen不能小于0
#define RTN_MC_CrdGetArcSecPara_Handle	1308	// NMC_CrdGetArcSecPara:句柄错误
#define RTN_MC_CrdGetArcSecPara_En		1309	// NMC_CrdGetArcSecPara:坐标系未初始化
#define RTN_IO_GetDIBit_En				1310	// NMC_GetDIBit:扩展模块未使能 //请先调用NMC_SetIOModuleEn使能响应模块
#define	RTN_IO_SetDoBit_En				1311	// NMC_SetDOBit:扩展模块未使能 //请先调用NMC_SetIOModuleEn使能响应模块
#define	RTN_IO_SetDo_En					1312	// NMC_SetDO:扩展模块未使能 //请先调用NMC_SetIOModuleEn使能响应模块
#define	RTN_IO_GetDo_En					1313	// NMC_GetDO:扩展模块未使能 //请先调用NMC_SetIOModuleEn使能响应模块
#define RTN_MC_GetCollectDataAddr_BUSY 	1314 	// NMC_GetCollectDataAddr:正在数据采集
#define RTN_MC_GetCollectDataAddr_index 1315 	// NMC_GetCollectDataAddr:index 超出范围
#define RTN_MC_ConfigCollect_BUSY 		1316 	// NMC_ConfigCollect:正在采集数据，不允许配置
#define RTN_MC_StartCollect_ErrFlag 	1317 	// NMC_StartCollect:正在采集数据
#define RTN_MC_GetCollectData_Err 		1318 	// NMC_GetCollectData:取数据失败
#define	RTN_MC_ConfigCollect_count		1319 	// MC_ConfigCollect:count 超出范围
#define	RTN_MC_SetJogPara_Busy			1320 	// NMC_MtSetJogPara:忙
#define	RTN_MC_SetJogPara_Mode			1321 	// NMC_MtSetJogPara:非jog模式下不允许配置
#define	RTN_MC_SetPtpPara_Busy			1322 	// NMC_MtSetPtpPara:忙
#define	RTN_MC_SetPtpPara_Mode			1323 	// NMC_MtSetPtpPara:非PTP模式下不允许配置
#define	RTN_MC_SetAxisPos_Busy			1324 	// NMC_MtSetAxisPos:非静止状态下禁止设置
#define RTN_IO_SetEncPos_INDEX			1325	// NMC_MtSetEncPos:encId范围不正确
#define RTN_MC_SetEncCoe_HANDLE			1326	// NMC_MtSetEncCoe:句柄错误
#define RTN_MC_GetEncCoe_HANDLE			1327	// NMC_MtGetEncCoe:句柄错误
#define RTN_MC_SetEncCoe_Range			1328	// NMC_MtSetEncCoe:系数范围不正确// inCoe有效范围：(0,1]
#define RTN_MC_SetEncCoe_Busy			1329	// NMC_MtSetEncCoe:轴忙，不能设置
#define RTN_MC_SetEncCoe_PosNotZero		1330	// NMC_MtSetEncCoe:当前位置不为0，不能设置// 先回原点，清除位置，然后再设置
#define	RTN_MC_ConfigCollect_Interval	1331    // MC_ConfigCollect:interval 超出范围

#define RTN_MC_SetLaserPower_group 		1332	// NMC_SetLaserPower设置激光能量的组号超范围
#define RTN_MC_SetLaserPower_points		1334	// NMC_SetLaserPower设置激光能量的组内点数超单位
#define RTN_MC_LaserOn_group					1335	//  NMC_LaserOn打开激光的组号超范围
#define RTN_MC_LaserOn_type						1336	// 	NMC_LaserOn打开激光的类型不对
#define RTN_MC_LaserOff_group					1337	//  NMC_LaserOff关闭激光的组号超范围
#define RTN_MC_LaserOff_type					1338 	//  NMC_LaserOff关闭激光的类型不对
#define RTN_MC_LaserConfig_laserType	1339	// NMC_LaserConfig配置激光的类型不对
#define RTN_MC_LaserConfig_val_err		1340	// NMC_LaserConfig配置激光的option值错误
#define RTN_MC_DelGantryGroup_exe_err	1341	// NMC_DelGantryGroup:执行错误
#define RTN_MC_DelGantryGroup_axisHandle_err	1342	//NMC_DelGantryGroup:句柄错误
#define RTN_MC_SetGantrySlave_have_Set	1343	// NMC_SetGantrySlave:设置错误
#define RTN_MC_SetGantryMaster_Busy		1344	// NMC_SetGantrySlave:正在运动
#define RTN_MC_SetGantrySlave_HANDLE	1345	// NMC_SetGantrySlave:句柄错误
#define RTN_MC_SetGantryMaster_HANDLE	1346	// NMC_SetGantryMaster:句柄错误
#define RTN_MC_SetGantryMaster_have_master	1347	// NMC_SetGantryMaster:master存在
#define RTN_MC_CrdLineXYZ_Len_Zero		1348	// NMC_CrdLineXYZ:直线插补长度为0
#define RTN_MC_CrdGotoBreak_VEL				1349	// CrdGotoBreak:速度设置错误
#define RTN_MC_CrdGotoBreak_ACC				1350	// CrdGotoBreak:加速度设置错误
#define RTN_MC_CrdGotoBreak_axis_busy  1351	// CrdGotoBreak:回断点轴正忙
#define RTN_MC_CrdSetOffset_count			1352	// CrdSetOffset 设置的偏移个数错误
#define RTN_MC_CrdStartMtn_stPos_err	1353	// CrdStartMtn 启动时的位置与计算起点不一致，或者需要回到断点处
#define RTN_MC_MtSetLmtCfg_Handle	1354	// NMC_MtSetLmtCfg:限位配置句柄错误
#define RTN_MC_MtSetAlarmCfg_Handle	1355	// NMC_MtSetAlarmCfg报警配置句柄错误
#define RTN_MC_CrdGotoBreak_En          1356            // NMC_CrdGotoBreak未启用
#define RTN_MC_CrdGotoBreak_Handle		1357            // NMC_CrdGotoBreak:crd句柄错误
#define RTN_MC_CrdSetOffset_En          1358            // NMC_CrdSetOffset未启用
#define RTN_MC_CrdSetOffset_Handle		1359            // NMC_CrdSetOffset:crd句柄错误
#define RTN_MC_CrdSetOffset_Axis_Busy	1360            // NMC_CrdSetOffset:电机正在运动
#define RTN_MC_CrdGotoBreak_NoData		1361			// NMC_CrdGotoBreak:无断点信息
#define RTN_MC_MtSetEncPos_Busy			1362			// NMC_MtSetEncPos:忙，正在运动
#define RTN_MC_SetGantrySlave_Busy		1363			// NMC_SetGantrySlave:忙
#define RTN_MC_SetGantrySlave_Pos		1364			// NMC_SetGantrySlave:主从轴当前位置超?
#define RTN_MC_GantryGroup_Range		1365			// gantry gourp参数范围不正确，有效范围[0,]
#define RTN_MC_SetGantrySlave_ErrLmt_Range 1367			// NMC_SetGantrySlave：gantryErrLmt必须大于0


#define RTN_MC_BufSHIOGateOn_HANDLE			500	// NMC_BufSHIOGateOn:句柄错误
#define RTN_MC_BufSHIOGateOn_EN			501		//  NMC_BufSHIOGateOn:调用该指令未启动插补坐标系
#define RTN_MC_BufSHIOGateOff_HANDLE			502	//  NMC_BufSHIOGateOff:句柄错误
#define RTN_MC_BufSHIOGateOff_EN			503		//  NMC_BufSHIOGateOff:调用该指令未启动插补坐标系
#define RTN_MC_LaserConfig_mode_err			504	//  NMC_LaserConfig:输入模式错误，没有该模式
#define RTN_MC_ConfigSHIOPara_isArray			505  //  NMC_ConfigHSIOPara:isArray参数错误
#define RTN_MC_ConfigSHIOPara_outMode			506	//  NMC_ConfigHSIOPara:outMode参数错误
#define RTN_MC_ConfigSHIOPara_posSrc			507	//  NMC_ConfigHSIOPara:posSrc参数错误
#define RTN_MC_ConfigSHIOPara_gateTime			508	//  NMC_ConfigHSIOPara:gateTime参数错误
#define RTN_MC_ConfigSHIOPara_delay			509	//  NMC_ConfigHSIOPara:delay参数小于0
#define RTN_MC_ConfigSHIOPara_gateDistance			510	//  NMC_ConfigHSIOPara:gateDistance参数错误
#define RTN_MC_SHIOTriggerOn_triggerFreq			511	//  NMC_SHIOTriggerOn:triggerFreq参数错误
#define RTN_MC_SHIOTriggerOn_triggerWidth			512	//  NMC_SHIOTriggerOn:triggerWidth参数错误
#define RTN_MC_SetLaserMode_mode			513	//  NMC_SetLaserMode:输入模式错误，没有该模式
#define RTN_MC_ConfigSHIOPara_axisMask			514	//  NMC_SetLaserMode:输入模式错误，没有该模式
#define RTN_MC_SHIOChangeAxisMask_axisMask			515	//  NMC_SetLaserMode:输入模式错误，没有该模式
#define RTN_MC_MtClrError_Handle				516	//  NMC_MtClrStsByBits或者NMC_MtClrError:句柄错误
#define RTN_MC_MtClrCaptSts_Handle				517	//  NMC_MtClrCaptSts:句柄错误
#define RTN_MC_ExitHandWheel_HANDLE				518	//  NMC_ExitHandWheel:句柄错
#define RTN_MC_SetHandWheel_HANDLE				519	//  NMC_SetHandWheel:句柄错
#define RTN_MC_SetHandWheel_Ratio				520	//  NMC_SetHandWheel:ratio 范围不正确
#define RTN_MC_SetHandWheel_Acc					521	//  NMC_SetHandWheel:acc 范围不正确
#define RTN_MC_SetHandWheel_Vel					522	//  NMC_SetHandWheel:vel 范围不正确
#define RTN_MC_SetHandWheel_Busy				523	//  NMC_SetHandWheel:busy
#define RTN_MC_ExitHandWheel_Busy				524	//  NMC_ExitHandWheel:busy
#define RTN_MC_SetHandWheel_isHandWheel_Mode 	525	//  NMC_SetHandWheel:已经是手轮模式
#define RTN_MC_SelectHandWheelInput_Index 		526	//  NMC_SelectHandWheelInput:通道范围不正确，[0,9]
#define RTN_MC_ExitHandWheel_Mode				527	//  NMC_ExitHandWheel:busy
#define RTN_MC_SetHandWheelRatio_Ratio			528	//  NMC_SetHandWheelRatio:ratio不能为0
#define RTN_MC_SetWatchDog_Mode	                529	//  NMC_SetWatchDog:stopMode参数不正确
#define RTN_MC_SetWatchDog_DoGroup              530	//  NMC_SetWatchDog:groupID参数不正确
#define RTN_MC_MtPtSetStatic_HANDLE				531	//  NMC_MtPtSetStatic:句柄
#define RTN_MC_MtPtGetStatic_HANDLE				532 //  NMC_MtPtGetStatic:句柄
#define RTN_NMC_MtPtSetStatic_no_pt_mode		533 //  NMC_MtPtSetStatic:非PT模式
#define RTN_NMC_MtPtSetStatic_onOff				534 //  NMC_MtPtSetStatic:onOff参数不正确[0,1]
#define RTN_MC_MtPtGetSpace_HANDLE				535 //  NMC_MtPtGetSpace:句柄 
#define RTN_NMC_MtPtGetSpace_no_pt_mode			536 //  NMC_MtPtGetSpace:非PT模式
#define RTN_MC_MtPtPush_HANDLE					537 //  NMC_MtPtPush:句柄 
#define RTN_NMC_MtPtPush_no_pt_mode				538 //  NMC_MtPtPush:非PT模式 
#define RTN_NMC_MtPtPush_count					539 //  NMC_MtPtPush:count参数不正确 
#define RTN_NMC_MtPtPush_pos					540 //  NMC_MtPtPush:位置参数不正确 
#define RTN_NMC_MtPtPush_time					541 //  NMC_MtPtPush:时间参数不正确  
#define RTN_NMC_MtPtPush_type					542 //  NMC_MtPtPush:类型参数不正确   
#define RTN_MC_MtPtBufClr_HANDLE				543 //  NMC_MtPtBufClr:句柄     
#define RTN_NMC_MtPtBufClr_no_pt_mode			544 //  NMC_MtPtBufClr:非PT模式
#define RTN_NMC_MtPtBufClr_busy					545 //  NMC_MtPtBufClr:忙        
#define RTN_MC_MtPtStartMtn_HANDLE				546 //  NMC_MtPtStartMtn:句柄         
#define RTN_NMC_MtPtStartMtn_syncAxCnts			547 //  NMC_MtPtStartMtn:axCnts参数不正确
#define RTN_NMC_MtPtStartMtn_no_pt_mode			548 //  NMC_MtPtStartMtn:非PT模式 
#define  RTN_NMC_MtPtStartMtn_one_axis_isBusy  	549 //  NMC_MtPtStartMtn:轴正在运动
#define  RTN_NMC_MtPtStartMtn_no_data			550 //  NMC_MtPtStartMtn:无PT数据
#define RTN_MC_Password_Paser                   551	//  系统密码解析错误
#define RTN_MC_Password_Format                  552	//  系统密码格式错误
#define RTN_MC_Password_Verify                  553	//   系统密码验证失败
#define RTN_MC_Password_Deny             	    554	//   系统密码验证过于频繁
#define RTN_MC_Password_Load             	    555	//   系统密码验证:加载
#define RTN_MC_Password_Save             	    556	//   系统密码验证:保存
#define RTN_MC_SetTime_TimeFormat               557	//  NMC_SetTime:时间格式不正确
#define RTN_MC_SetTime_Save			            558	//  NMC_SetTime:保存系统时间错误
#define RTN_MC_DacChanelInvalid			        559	//  dac通道无效
#define RTN_MC_SetDacMode_ModeInvalid	        560	//  dac模式无效
#define RTN_MC_SetDacMode_Set			        561	//  dac模式设置错误
#define RTN_MC_SetDac_Value						562 //  dac设定值范围不正确
#define RTN_MC_SetDac_Set						563 //  dac输出错误
#define RTN_MC_GetAdc_Get						564 //  adc读取错误
#define RTN_MC_CrdLaserFollow_Handle			565 //  CrdLaserFollow:CrdHandle
#define RTN_MC_CrdLaserFollow_not_set_laserType 566 // CrdLaserFollow:激光类型未设置
#define RTN_MC_CrdLaserFollow_followType_err		567 // CrdLaserFollow：坐标系激光跟随的速度类型参数错误
#define RTN_MC_CrdEnableLaserFollow_Handle			568 // CrdEnableLaserFollow:CrdHandle
#define RTN_MC_CrdEnableLaserFollow_onOff				569 // CrdEnableLaserFollow：onOff参数错误
#define RTN_MC_AdcChanelInvalid					570	// adc通道无效
#define RTN_MC_CrdBufOut_DacValue				571 // CrdBufOut:da设定值无效
#define RTN_MC_LaserSetParam_OnDelay				572 // NMC_LaserSetParam:onDelay范围错误
#define RTN_MC_LaserSetParam_OffDelay				573 // NMC_LaserSetParam:offDelay范围错误
#define RTN_MC_LaserSetParam_Ch					574 // NMC_LaserSetParam:ch范围错误
#define RTN_MC_LaserGetParam_Ch							575	// NMC_LaserGetParam:ch范围错误
#define RTN_MC_CrdBufLaserOnOff_Handle					576	// NMC_LaserGetOnOffDelay:ch范围错误
#define RTN_MC_CrdBufLaserOnOff_En					    577	// NMC_LaserGetOnOffDelay:坐标系未使能
#define RTN_MC_CrdBufLaserOnOff_OnOff					578	// NMC_LaserGetOnOffDelay:onOff范围错误
#define RTN_MC_CrdBufLaserOnOff_Ch					    579	// NMC_LaserGetOnOffDelay:ch范围错误
#define RTN_MC_CrdBufLaserPower_Handle					580	// NMC_CrdBufLaserPower:handle错误
#define RTN_MC_CrdBufLaserPower_En					    581	// NMC_CrdBufLaserPower:坐标系未使能
#define RTN_MC_CrdBufLaserPower_Power					582	// NMC_CrdBufLaserPower:power范围错误
#define RTN_MC_CrdBufLaserPower_Ch					    583	// NMC_CrdBufLaserPower:ch范围错误
#define RTN_MC_SetDac_CtrlMode						    584	// SetDac:DAC控制模式错误
#define RTN_MC_LaserSetParam_LaserType				585 // LaserSetParam: 设置时，激光类型未设置
#define RTN_MC_LaserSetMode_Ch				586 // NMC_LaserSetMode:ch参数不正确
#define RTN_MC_LaserSetMode_Set				587 // NMC_LaserSetMode:设置模式
#define RTN_MC_LaserSetParam_StandbyPower		588 // NMC_LaserSetStandbyPower:ch参数不正确
#define RTN_MC_LaserSetOutputType_Index		589 // NMC_LaserSetOutputType:index参数不正确
#define RTN_MC_LaserSetOutputType_Set		590 // NMC_LaserSetOutputType:设置错误
#define RTN_MC_LaserSetOutputType_Ch				591 // NMC_LaserSetOutputType:ch范围错误
#define RTN_MC_LaserTimeArrayOn_Ch				592 // NMC_LaserTimeArrayOn:ch范围错误
#define RTN_MC_LaserTimeArrayOff_Ch				593 // NMC_LaserTimeArrayOff:ch范围错误
#define RTN_MC_LaserSetPower_Ch	    594	// NMC_LaserSetPower:ch范围错误
#define RTN_MC_LaserOnOff_Mode		595	// NMC_LaserOnOff:当前模式下不支持
#define RTN_MC_LaserOnOff_OnOff     596	// NMC_LaserOnOff:onOff参数范围错误
#define RTN_MC_LaserOnOff_Ch		597 // NMC_LaserOnOff:ch参数范围错误
#define RTN_MC_SHIOGateOnOff_Mode		598 // NMC_SHIOGateOn:mode不正确
#define RTN_MC_LaserConfig_laserType_occupied		599 // NMC_LaserConfig:配置的laserType被占用了
#define RTN_MC_LaserConfig_conflict_laserType		600 // NMC_LaserConfig:配置的laserType类型有冲突
#define RTN_MC_SetLaserMode_conflict_mode				601 // NMC_SetLaserMode:配置的模式有冲突
#define RTN_MC_CrdBufMotion_LookaheadDis				602 // Crd:lookaheadDis参数范围错误
#define RTN_MC_SetLaserPower_Time					603 // NMC_LaserSetTimeArrayPower:时间设置错误

#define RTN_MC_LinearCompSetParam_dimens	  	604 // NMC_LinearCompSetParam：设置的维数参数不对
#define RTN_MC_LinearCompSetParam_axisMask		605 // NMC_LinearCompSetParam：设置的轴映射不对
#define RTN_MC_LinearCompSetParam_src			606 // NMC_LinearCompSetParam：设置的比较源参数不对
#define RTN_MC_LinearCompSetParam_cmpMode		607 // NMC_LinearCompSetParam：设置的比较源参数不对
#define RTN_MC_LinearCompSetParam_gateTime		608 // NMC_LinearCompSetParam：设置的比较输出的脉冲宽度参数不对
#define RTN_MC_LinearCompSetParam_chn			609 // NMC_LinearCompSetParam：设置的输出通道参数不对


#define RTN_MC_LinearCompInterval_count			610 // NMC_LinearCompInterval：设置的比较数量参数不对
#define RTN_MC_LinearCompInterval_section		611 // NMC_LinearCompInterval：设置的比较数据细分段数过大
#define RTN_MC_LinearCompInterval_cmpmode		612 // NMC_LinearCompInterval：设置的比较数据的比较模式不对

#define RTN_MC_LinearCompOnOff_onOff			613	// NMC_LinearCompOnOff: onOff参数错误

#define RTN_MC_Comp2DimensSetParam_chnType			614	// NMC_Comp2DimensSetParam: chnType参数错误	
#define RTN_MC_Comp2DimensSetParam_dirNo				615	// NMC_Comp2DimensSetParam: dirNo参数错误	
#define RTN_MC_Comp2DimensSetParam_errZone			616	// NMC_Comp2DimensSetParam: errZone参数错误	
#define RTN_MC_Comp2DimensSetParam_gateTime			617	// NMC_Comp2DimensSetParam: gateTime参数错误	
#define RTN_MC_Comp2DimensSetParam_outputType		618	// NMC_Comp2DimensSetParam: outputType参数错误	
#define RTN_MC_Comp2DimensSetParam_outputchn		619	// NMC_Comp2DimensSetParam: outputchn参数错误	
#define RTN_MC_Comp2DimensSetParam_posSrc				620	// NMC_Comp2DimensSetParam: posSrc参数错误	
#define RTN_MC_Comp2DimensSetParam_stLevel			621	// NMC_Comp2DimensSetParam: stLevel参数错误	
#define RTN_MC_Comp2DimensSetData_count					622	// NMC_Comp2DimensSetData: count参数错误	
#define RTN_MC_Comp2DimensOnoff_onOff						623	// NMC_Comp2DimensOnoff: onOff参数错误	
#define RTN_MC_Comp2DimensSetData_push_data_failed 624 //NMC_Comp2DimensSetData:压入数据失败 
#define RTN_MC_Comp2DimensSetParam_group				625	// NMC_Comp2DimensSetParam:group参数错误
#define RTN_MC_Comp2DimensGetParam_group				626 // NMC_Comp2DimensGetParam:group参数错误
#define RTN_MC_Comp2DimensSetData_group					627	// NMC_Comp2DimensSetData:group参数错误
#define RTN_MC_Comp2DimensOnoff_group						628	// NMC_Comp2DimensOnoff:group参数错误
#define RTN_MC_Comp2DimensStatus_group					629	// NMC_Comp2DimensStatus:group参数错误
#define RTN_MC_SetDiFilter_Range					630	// NMC_SetDIFilter:参数错误

#define RTN_MC_CrdEnableMatrixCalc_enable											630	// NMC_CrdEnableMatrixCalc:enable参数错误
#define RTN_MC_CrdEnableMatrixCalc_rotAxisNo									631	// NMC_CrdEnableMatrixCalc:rotAxisNo参数错误
#define RTN_MC_CrdEnableMatrixCalc_angleRadEqual							632	// NMC_CrdEnableMatrixCalc:angleRadEqual参数错误
#define RTN_MC_LinearCompSetData_count			633 // NMC_LinearCompSetData：设置的比较数量参数不对
#define RTN_MC_LinearCompSetData_section		634 // NMC_LinearCompSetData：设置的比较数据细分段数过大
#define RTN_MC_LinearCompSetData_cmpmode		635 // NMC_LinearCompSetData：设置的比较数据的比较模式不对
#define RTN_MC_LaserSetParam_Busy				636 // NMC_LaserSetParam:激光打开情况下不允许设置参数


#define RTN_MC_CrdEnableMatrixCalc_HANDLE 	637   // NMC_CrdEnableMatrixCalc:句柄错误
#define RTN_MC_CrdSetSafePara_HANDLE 				638   // NMC_CrdSetSafePara:句柄错误
#define RTN_MC_CrdEnableMatrixCalc_En 			639   // NMC_CrdEnableMatrixCalc:坐标系未使能

#define RTN_MC_CrdSetPolarType_En						640   // NMC_CrdSetPolarType:坐标系不允许使能
#define RTN_MC_CrdSetPolarType_HANDLE				641   // NMC_CrdSetPolarType:句柄错误
#define RTN_MC_CrdSetPolarType_rotAxNo			642   // NMC_CrdSetPolarType:极坐标的旋转轴号超范围
#define RTN_MC_CrdSetPolarType_transAxNo		643   // NMC_CrdSetPolarType:极坐标的平移轴号超范围
#define RTN_MC_CrdSetPolarType_rotAxNo_transAxNo_equal		644   // NMC_CrdSetPolarType:极坐标旋转轴和平移轴选定的轴号相同
#define RTN_MC_CrdSetPolarType_rotEquiv			645   // NMC_CrdSetPolarType:极坐标旋转轴当量错误

#define RTN_MC_CrdRunToPolarPos_HANDLE			646   // NMC_CrdRunToPolarPos:句柄错误

#define RTN_MC_CrdDeletePolar_HANDLE				647   // NMC_CrdDeletePolar:句柄错误
#define RTN_CrdDeletePolar_En								648   // NMC_CrdDeletePolar:坐标系未关闭
#define RTN_MC_CrdRunToPolarPos_En					649		// NMC_CrdRunToPolarPos:坐标系不允许使能
#define RTN_MC_CrdRunToPolarPos_not_polar		650		// NMC_CrdRunToPolarPos:坐标系未设置成极坐标

#define RTN_MC_CrdRunToPolarTheta_HANDLE		651
#define RTN_MC_CrdRunToPolarTheta_En				652
#define RTN_MC_CrdRunToPolarTheta_not_polar			653
#define RTN_MC_CrdRunToPolarTheta_clrRoundFlag 		654
#define RTN_MC_LaserSetTimeArrayPara_Ch 			655	//NMC_LaserSetTimeArrayPara参数错误：ch
#define RTN_MC_LaserSetTimeArrayPara_OutType 		656	//NMC_LaserSetTimeArrayPara参数错误：ouputType
#define RTN_MC_LaserSetTimeArrayPara_OutCh 		657	//NMC_LaserSetTimeArrayPara参数错误：outputCh
#define RTN_MC_LaserSetTimeArrayPara_PWMWidth 		658	//NMC_LaserSetTimeArrayPara参数错误：pwmWidth
#define RTN_MC_LaserSetTimeArrayPara_Period		659	//NMC_LaserSetTimeArrayPara参数错误：pwmPeriod
#define RTN_MC_LaserTimeArrayOn_group				660	//NMC_LaserTimeArrayExe参数错误：group
#define RTN_MC_CrdBufLaserTimeArrayExe_En			661 //NMC_CrdBufLaserTimeArrayExe:crd not enable
#define RTN_MC_CrdBufLaserTimeArrayExe_Ch			662	//NMC_CrdBufLaserTimeArrayExe参数错误：ch
#define RTN_MC_CrdBufLaserTimeArrayExe_Group		663	//NMC_CrdBufLaserTimeArrayExe参数错误：gourp
#define RTN_MC_CrdBufWaitEncInPosition_En		664	//NMC_CrdBufWaitEncInPosition坐标系未启用
#define RTN_MC_CrdBufWaitEncInPosition_AxisMask		665	//NMC_CrdBufWaitEncInPosition参数错误：axisMask
#define RTN_MC_CrdBufWaitEncInPosition_overTime		666	//NMC_CrdBufWaitEncInPosition参数错误：overTime

#define RTN_MC_MtSetAxisArrivalPara_HANDLE					667 //NMC_MtSetAxisArrivalParan参数错误：handle
#define RTN_MC_MC_MtSetAxisArrivalPara_arrivalBand	668 //NMC_MtSetAxisArrivalParan参数错误：arrivalBand
#define RTN_MC_MC_MtSetAxisArrivalPara_stableTime		669  //NMC_MtSetAxisArrivalParan参数错误：stableTime
#define RTN_MC_MtGetAxisArrivalPara_HANDLE					670  //NMC_MtGetAxisArrivalParan参数错误：Handle


#define RTN_MC_CrdArc3D_HANDLE						671  //NMC_CrdArc3D参数错误：Handle
#define RTN_MC_CrdArc3D_EN							672  //NMC_CrdArc3D参数错误：en
#define RTN_MC_CrdArc3D_VEL							673  //NMC_CrdArc3D参数错误：vel
#define RTN_MC_CrdArc3D_ACC							674  //NMC_CrdArc3D参数错误：acc
#define RTN_MC_CrdArc3D_Less_3D						675  //NMC_CrdArc3D 调用时，未建立3D坐标系

#define RTN_MC_INN_CD_3D_S							676	// 3D圆弧下载：三点重合
#define RTN_MC_INN_CD_3D_L							677	// 3D圆弧下载：三点共线
#define RTN_MC_INN_CD_3D_CIR_DEGRAD					678	// 3D圆弧计算参数退化
#define RTN_LIB_NOT_ACTIVE						    679	// 没有激活的功能

#define RTN_MC_LinearCompSetData_pos		 	680 // 线性位置比较的位置错误

#define RTN_MC_CompXDimensSetParam_chn					681				//NMC_CompXDimensSetParam参数错误：chn
#define RTN_MC_CompXDimensSetParam_outCnts			682				//NMC_CompXDimensSetParam参数错误：outCnts
#define RTN_MC_CompXDimensSetParam_outChnType		683				//NMC_CompXDimensSetParam参数错误：outChnType
#define RTN_MC_CompXDimensSetParam_gateTime			684				//NMC_CompXDimensSetParam参数错误：gateTime
#define RTN_MC_CompXDimensSetParam_stLevel			685				//NMC_CompXDimensSetParam参数错误：stLevel	
#define RTN_MC_CompXDimensSetParam_dimens				686				//NMC_CompXDimensSetParam参数错误：dimens
#define RTN_MC_CompXDimensSetParam_errZone			687				//NMC_CompXDimensSetParam参数错误：errZone
#define RTN_MC_CompXDimensSetParam_posSrc				688				//NMC_CompXDimensSetParam参数错误：posSrc
#define RTN_MC_CompXDimensSetParam_outType     	689				//NMC_CompXDimensSetParam参数错误：outType 
#define  RTN_MC_CompXDimensSetParam_outIndex   	690				//NMC_CompXDimensSetParam参数错误：outIndex

#define RTN_MC_CompXDimensGetParam_chn                	691				//NMC_CompXDimensGetParam参数错误：chn

#define RTN_MC_CompXDimensSetData_chn                 	692				//NMC_CompXDimensSetData参数错误：chn
#define RTN_MC_CompXDimensSetData_count               	693				//NMC_CompXDimensSetData参数错误：count
#define RTN_MC_CompXDimensSetData_push_data_failed    	694				//NMC_CompXDimensSetData数据压入SDARM错误

#define RTN_MC_NMC_CompXDimensOnoff_chn               	695				//NMC_CompXDimensOnoff参数错误：chn
#define RTN_MC_NMC_CompXDimensOnoff_onOff             	696				//NMC_CompXDimensOnoff参数错误：onOff 

#define RTN_MC_CompXDimensStatus_chn                  	697				//NMC_CompXDimensStatus参数错误：chn

#define RTN_MC_CrdBufMotion_Polar_err_start							698				// 极坐标运动不允许直线的起点从（0,0）位置出发


#define RTN_MC_AX_ON_BUSY                  							699	
#define RTN_MC_AX_ON_closeloop_no_encoder               700	
#define RTN_MC_AX_ON_closeloop_encoder_with_vel         701	
#define RTN_MC_AX_ON_closeloop_kp_less_zero            	702		
#define RTN_MC_AX_ON_closeloop_no_dac                  	703		

#define RTN_MC_SetCloseLoopDac_HANDLE                  	704		
#define RTN_MC_SetCloseLoopDac_axis_Busy                705	
#define RTN_MC_SetCloseLoopDac_bias                  		706	
#define RTN_MC_SetCloseLoopDac_dacLmt                  	707	
#define RTN_MC_SetCloseLoopDac_inverse                  708	

#define RTN_MC_GetCloseLoopDac_HANDLE                  	709	
#define RTN_MC_GetCloseLoopDac_no_closeloop_dac         710		

#define RTN_MC_MtSetCtrlMode_HANDLE                  		711		
#define RTN_MC_MtSetCtrlMode_axis_Busy                  712	
#define RTN_MC_MtSetCtrlMode_axis_svon                  713	
#define RTN_MC_MtSetCtrlMode_mode                  			714	
#define RTN_MC_MtSetCtrlMode_no_dac                  		715

	
#define RTN_MC_MtGetCtrlMode_HANDLE                  		716	
#define RTN_MC_SetPIDPara_HANDLE                  			717	
#define RTN_MC_SetPIDPara_index                  				718	
#define RTN_MC_SetPIDPara_ctrlMode                  		719	
#define RTN_MC_SetPIDPara_kp                  					720	
#define RTN_MC_SetPIDPara_ki                  					721	
#define RTN_MC_SetPIDPara_kd                  					722
#define RTN_MC_SetPIDPara_kvff                  				723	
#define RTN_MC_SetPIDPara_integralLimit                 724
#define RTN_MC_SetPIDPara_derivativeLimit               725
#define RTN_MC_SetPIDPara_outLimit                  		726

#define RTN_MC_GetPIDPara_HANDLE                  			727
#define RTN_MC_GetPIDPara_ctrlMode                  		728

#define RTN_MC_SelectPID_HANDLE                  				729		// NMC_MtSetPIDIndex:句柄错误
#define RTN_MC_GetUsingPIDIndex_HANDLE                  730		// NMC_MtGetPIDIndex：句柄错误
#define RTN_MC_GetUsingPIDIndex_ctrlMode                731		// NMC_MtGetPIDIndex：控制模式
#define RTN_CrdBufSetEstopDI_HANDLE 										732		// NMC_CrdBufSetEstopDI：句柄
#define RTN_CrdBufSetEstopDI_Axis 											733		// NMC_CrdBufSetEstopDI：轴号范围不正确
#define RTN_MC_UserPassword_UserNotSupport 							734		// 用户名不支持，当前只支持"USER1"

// 临时定义
#define RTN_MC_MtSetLeadScrewPara_HANDLE 				735	// NMC_MtSetLeadScrewPara:句柄错误
#define RTN_MC_MtSetLeadScrewPara_number 				736
#define RTN_MC_MtSetLeadScrewPara_lenPos 				737
#define RTN_MC_MtSetLeadScrewCompPos_HANDLE 		738
#define RTN_MC_MtSetLeadScrewCompPos_index 			739
#define RTN_MC_MtEnableLeadScrew_HANDLE 				740
#define RTN_MC_MtSetLeadScrewCompPos_not_config 741
#define RTN_MC_MtSetLeadScrewCompPos_enable 		742
#define RTN_MC_MtSetEstopDI_HANDLE							743
#define RTN_MC_MtGetEstopDI_HANDLE							744
#define RTN_MC_SetDIBitRevs_Index 							745 // NMC_SetDIBitRevs:bitIndex范围不正确

#define RTN_MC_MtSetAdvCaptParam_HANDLE					746
#define RTN_MC_MtSetAdvCaptParam_capPosType			747
#define RTN_MC_MtSetAdvCaptParam_capPosIndex		748
#define RTN_MC_MtSetAdvCaptParam_trigSrc				749
#define RTN_MC_MtSetAdvCaptParam_trigIndex			750
#define RTN_MC_MtSetAdvCaptParam_trigValue			751
#define RTN_MC_MtSetAdvCaptParam_singleTrigEn		752
#define RTN_MC_MtSetAdvCaptParam_ch							753
#define RTN_MtClrAdvCaptSts_HANDLE							754
#define RTN_MC_MtClrAdvCaptSts_ch								755
#define RTN_MC_MtGetAdvCaptPos_HANDLE						756
#define RTN_MC_MtGetAdvCaptPos_ch								757
#define RTN_MC_MtGetAdvCaptPos_no_active				758
#define RTN_MC_CrdBufDataPack_HANDLE						759	// NMC_CrdBufDataPack:句柄错误
#define RTN_MC_CrdBufDataPack_En								760	// NMC_CrdBufDataPack:坐标系未启用
#define RTN_MC_CrdBufDataPack_UnknowCmd					761	// NMC_CrdBufDataPack:未知的命令
#define RTN_MC_SetDOBitAutoReverse_Index				762	// NMC_SetDOBitAutoReverse:bitindex
#define RTN_MC_SetDOBitAutoReverse_RevsTime			763	// NMC_SetDOBitAutoReverse:reverseTime

#define RTN_MC_MtClrErrorEx_HANDLE							764
#define RTN_NMC_SetDOGroupEx_GetDOVal						765


#define RTN_MC_CrdBufSetStopOffset_HANDLE				766
#define RTN_MC_CrdBufSetStopOffset_EN						767
#define RTN_MC_CrdBufSetStopOffset_Sdram_no_use	768
#define RTN_MC_CrdBufClrStopOffset_HANDLE				769
#define RTN_MC_CrdBufClrStopOffset_EN						770
#define RTN_MC_CrdBufClrStopOffset_Sdram_no_use	771

#define RTN_MC_CompXDimensSetCmpOutMode_chn									772
#define RTN_MC_CompXDimensSetCmpOutMode_outMode							773
#define RTN_MC_CompXDimensSetCmpOutMode_outputchn_not_set		774
#define RTN_MC_MtSetAdvCaptParam_Filter		775								// NMC_MtSetAdvCaptParam:filter取值范围不正确


#define RTN_MC_CrdSetBufLengthFlag_Handle			776
#define RTN_MC_CrdSetBufLengthFlag_flag				777
#define RTN_MC_CrdGetBufLength_Handle					778

#define RTN_MC_CrdSetBufIOAfterLen_HANDLE   		779
#define RTN_MC_CrdSetBufIOAfterLen_EN						780
#define RTN_MC_CrdSetBufIOAfterLen_outLength		781
#define RTN_MC_CrdSetBufIOAfterLen_outType			782
#define RTN_MC_CrdSetBufIOAfterLen_outVal				783

#define RTN_MC_CrdSetBufIOBeforeLen_HANDLE   		784
#define RTN_MC_CrdSetBufIOBeforeLen_EN					785
#define RTN_MC_CrdSetBufIOBeforeLen_outLength		786
#define RTN_MC_CrdSetBufIOBeforeLen_outType			787
#define RTN_MC_CrdSetBufIOBeforeLen_outVal			788
#define RTN_MC_ClrPassword_Err									789			// ClrPassword:解密数据不正确

#define RTN_MC_CrdSetIsShortLine_HANDLE									790
#define RTN_MC_CrdSetIsShortLine_EN											791
#define RTN_MC_CrdSetIsShortLine_isShortLine						792

#define RTN_MC_CrdSetLookAheadCentriAcc_HANDLE					793
#define RTN_MC_CrdSetLookAheadCentriAcc_EN							794
#define RTN_MC_CrdSetLookAheadCentriAcc_isUsingSetAcc		795
#define RTN_MC_CrdSetLookAheadCentriAcc_centriAcc				796

#define RTN_NMC_SetDioMapping_PinGrp				797 // NMC_SetDioMapping:pinGrp/newGrp范围错误
#define RTN_NMC_SetDioMapping_PinIndex				798 // NMC_SetDioMapping:pinIndex/newIndex范围错误
#define RTN_NMC_SetDioMapping_Full				799 // NMC_SetDioMapping:最多只能配置16条映射数据

#define RTN_MC_INN_ARC_ONLYYZ											800
#define RTN_MC_INN_ARC_ONLYZX											801						
#define RTN_MC_INN_ARC_ONLYYZ2										802
#define RTN_MC_INN_ARC_ONLYZX2										803
#define RTN_MC_INN_ARC_X													804
#define RTN_MC_INN_ARC_Y													805
#define RTN_MC_CrdArcRYZ_HANDLE										806
#define RTN_MC_CrdArcRYZ_EN												807
#define RTN_MC_Crd_Less_Three_axes								808
#define RTN_MC_CrdArcRYZ_VEL											809
#define RTN_MC_CrdArcRYZ_ACC											810
#define RTN_MC_CrdArcRZX_HANDLE										811
#define RTN_MC_CrdArcRZX_EN												812
#define RTN_MC_CrdArcRZX_VEL											813
#define RTN_MC_CrdArcRZX_ACC											814
#define RTN_MC_CrdArcC_YZ_HANDLE									815
#define RTN_MC_CrdArcC_YZ_EN											816
#define RTN_MC_CrdArcC_YZ_VEL											817
#define RTN_MC_CrdArcC_YZ_ACC											818
#define RTN_MC_CrdArcC_ZX_HANDLE									819
#define RTN_MC_CrdArcC_ZX_EN											820
#define RTN_MC_CrdArcC_ZX_VEL											821
#define RTN_MC_CrdArcC_ZX_ACC											822
#define RTN_MC_LaserGetOnOff_Ch										823			// NMC_LaserGetOnOff:ch范围不正确
#define RTN_MC_LaserSetOutputType_DacMode					824			// MC_LaserSetOutputType:DAC被占用
#define RTN_MC_MtSetCtrlMode_dac_mode							825			// MC_MtSetCtrlMode:DAC被占用
#define RTN_MC_AdcFilterRange											826			// ADC滤波范围设置不正确
#define RTN_MC_MtXXX_HANDLE												827			// 轴句柄无效
#define RTN_MC_SetDacMode_Busy										828			// SetDacMode:DAC通道被占用（如配置为了激光输出等）
#define RTN_MC_LaserSetParam_MinValue							829 // NMC_LaserSetParam:onDelay范围错误
#define RTN_MC_LaserSetParam_MaxValue							830 // NMC_LaserSetParam:offDelay范围错误
#define RTN_MC_LinearCompSetParam_Busy						831 // NMC_LinearCompSetParam:激活中
#define RTN_MC_SHIOGatePulse_Ch										832 // NMC_SHIOGatePulse:通道号范围不正确
#define RTN_MC_SHIOGatePulse_Busy									833 // NMC_SHIOGatePulse:GateOn时不能输出
#define RTN_MC_PwmPulseOut_Ch											834 // NMC_PwmPulseOut:通道号范围不正确
#define RTN_MC_PwmPulseOut_Busy										835 // NMC_PwmPulseOut:LaserOn时不能输出
#define RTN_MC_ClrErrorEx_Count										836 // NMC_MtClrErrorEx:count范围错误

#define RTN_MC_MtSetBacklash_HANDLE											837
#define RTN_MC_MtSetBacklash_compValue									838
#define RTN_MC_MtSetBacklash_compDelta									839
#define RTN_MC_MtSetBacklash_compDir										840

#define RTN_MC_MtGetBacklash_HANDLE											841

#define RTN_MC_MtSetLeadScrewCompPara_HANDLE						842
#define RTN_MC_MtSetLeadScrewCompPara_num								843
#define RTN_MC_MtSetLeadScrewCompPara_cmpLen						844
#define RTN_MC_MtSetLeadScrewCompPara_pCompPos_NULL			845
#define RTN_MC_MtSetLeadScrewCompPara_pCompNeg_NULL			846

#define RTN_MC_MtGetLeadScrewCompPara_HANDLE						847

#define RTN_MC_MtEnableLeadScrewComp_HANDLE							848
#define RTN_MC_MtGetLeadScrewCompPara_no_setPara				849

#define RTN_MC_MtGetLeadScrewCompPara_enable						850
#define RTN_MC_MtGetLeadScrewCompPara_no_data						851


#define RTN_MC_SetLaserPowerCmpTable_tableNo											852
#define RTN_MC_SetLaserPowerCmpTable_pLaserCmpPower_NULL					855

#define RTN_MC_StartLaserPowerComp_tableNo												856
#define RTN_MC_StartLaserPowerComp_pAxisNo_NULL										857
#define RTN_MC_StartLaserPowerComp_pAxisNo_val										858
#define RTN_MC_SetLaserPowerCmpTable_pXCmpPos_NULL									859
#define RTN_MC_SetLaserPowerCmpTable_pYCmpPos_NULL									860
#define RTN_MC_StartLaserPowerComp_chn														861

#define RTN_MC_CrdBufSHIOGatePulse_HANDLE													862
#define RTN_MC_CrdBufSHIOGatePulse_EN															863														
#define RTN_MC_CrdBufSHIOGatePulse_gateTime												864										
#define RTN_MC_CrdBufSHIOGatePulse_gateFrq												865											
#define RTN_MC_CrdBufSHIOGatePulse_outCount												866												
#define RTN_MC_CrdBufSHIOGatePulse_ch															867
#define RTN_MC_CrdBufSHIOGatePulse_Gate_Busy											868
#define RTN_MC_StartLaserPowerComp_pSectionLen_less_zero					869
#define RTN_MC_UserParaEx_Add_Range					870 // 扩展用户参数区起始地址超出范围
#define RTN_MC_UserParaEx_Len_Range					871 // 扩展用户参数区读写长度超出范围

#define RTN_MC_SetLaserPowerCmpTable_xCount													872
#define RTN_MC_SetLaserPowerCmpTable_yCount													873
#define RTN_MC_SetLaserPowerCmpTable_pXCmpPos_not_linear_increasing 874
#define RTN_MC_SetLaserPowerCmpTable_pYCmpPos_not_linear_increasing 875
#define RTN_MC_StopLaserPowerComp_chn																876
#define RTN_MC_SetLaserPowerCmpTable_Chn														877		// NMC_SetLaserPowerCmpTable,激光通道范围错误
#define RTN_MC_IOModuleRw_Param																			878		// 扩展IO模块访问错误:参数错误//检查offset及读写位数
#define RTN_MC_IOModuleRw_Comm																			879		// 扩展IO模块访问错误:模块ID错误//检查通讯或者是否使能
#define RTN_MC_IOModuleRw_DevType																		880		// 扩展IO模块访问错误:模块读写//检查通讯或者是否使能或者参数
#define RTN_MC_IOModuleRw_Other																			881		// 扩展IO模块访问错误:其他错误
#define RTN_MC_IOModuleRw_En																				881		// 扩展IO模块访问错误:从站未使能

#define RTN_MC_INN_A_POS_DIFF																				890
#define RTN_MC_INN_ARC_A																						891
#define RTN_MC_CrdSetAxisATolVel_HANDLE															892
#define RTN_MC_CrdSetAxisATolVel_EN																	893
#define RTN_MC_CrdSetAxisATolVel_tolVel															894
#define RTN_MC_DoBitPulse_Ch																				895		// DoBitPulse通道范围不正确,[0,MAX_NUM_DOBIT_PULSE)
#define RTN_MC_DoBitPulse_DoIndex																		896		// DoBitPulse的doIndex参数不正确
#define RTN_MC_DoBitPulse_HighLevelTime															897		// DoBitPulse的highLevelTime参数不能小于等于0
#define RTN_MC_DoBitPulse_lowLevelTime															898		// DoBitPulse的lowLevelTime参数不能小于等于0
#define RTN_MC_DoBitPulse_OutCount																	899		// DoBitPulse的outCount参数不能小于等于0
#define RTN_MC_CrdSetScaraMechPara_Handle                           900
#define RTN_MC_CrdSetScaraMechPara_En                               901
#define RTN_MC_CrdSetScaraMechPara_arm1Len                          902
#define RTN_MC_CrdSetScaraMechPara_arm2Len                          903
#define RTN_MC_CrdSetScaraMechPara_pitch                            904
#define RTN_MC_CrdGetScaraMechPara_Handle                           905

#define RTN_MC_CrdSetScaraJiontPara_Handle                          906
#define RTN_MC_CrdSetScaraJiontPara_En                              907
#define RTN_MC_CrdSetScaraJiontPara_jointNo                         908
#define RTN_MC_CrdSetScaraJiontPara_encBits                         909
#define RTN_MC_CrdSetScaraJiontPara_maxAcc                          910
#define RTN_MC_CrdSetScaraJiontPara_maxVel                          911
#define RTN_MC_CrdSetScaraJiontPara_Lmt                          		912
#define RTN_MC_CrdSetScaraJiontPara_posLmt                          913
#define RTN_MC_CrdSetScaraJiontPara_ratio                           914
#define RTN_MC_CrdGetScaraJiontPara_Handle                        	915
#define RTN_MC_CrdGetScaraJiontPara_jointNo                         916

#define RTN_MC_CrdSetTransScara_Handle                              917
#define RTN_MC_CrdSetTransScara_en                                  918
#define RTN_MC_CrdSetTransScara_jointNum                            919
#define RTN_MC_CrdDelTransScara_Handle                              920
#define RTN_MC_CrdDelTransScara_en                                  921

#define RTN_MC_CrdSetFlyFollow_Handle                               922
#define RTN_MC_CrdSetFlyFollow_en                                   923
#define RTN_MC_CrdDelFlyFollow_Handle                               924
#define RTN_MC_CrdDelFlyFollow_en              											925
#define RTN_MC_MovePtpAbsPack_Handle              									926		// NMC_MtMovePtpAbsPack8 or NMC_MtMovePtpRelPack8:axisFirstHandle error
#define RTN_MC_MovePtpAbsPack_Handle2              									927		// NMC_MtMovePtpAbsPack8 or NMC_MtMovePtpRelPack8:axis out of range
#define RTN_MC_CrdBufDataPack_NoSpace					             928	// NMC_CrdBufDataPack:空间不足
#define RTN_MC_LaserTimeArrayOn_BusyOrMode                           929    // NMC_LaserTimeArrayExe:busy或者模式不是时间数组模式
#define RTN_MC_CrdBufWaitPos_Handle                                 930    // NMC_CrdBufWaitPos：handle
#define RTN_MC_CrdBufWaitPos_En                                     931    // NMC_CrdBufWaitPos：en
#define RTN_MC_CrdBufWaitPos_AxisNo                                 932    // NMC_CrdBufWaitPos：axisNo range
#define RTN_MC_CrdBufWaitPos_OverTime                               933    // NMC_CrdBufWaitPos：axisNo range
#define RTN_MC_BufSHIOGateOn_Ch			                            934	    // NMC_BufSHIOGateOn:ch错误
#define RTN_MC_BufSHIOGateOff_Ch                                    935     // NMC_BufSHIOGateOff:ch错误


#define RTN_MC_CrdEnableInterferenceProtect_groupNo					936
#define RTN_MC_CrdEnableInterferenceProtect_enable					937
#define RTN_MC_CrdEnableInterferenceProtect_mode					938
#define RTN_MC_CrdGetInterferenceSts_groupNo						939
#define RTN_MC_CrdSetInterferencePara_groupNo						940
#define RTN_MC_CrdSetInterferencePara_crdAxNo						941
#define RTN_MC_CrdSetInterferencePara_crdNo							942
#define RTN_MC_CrdSetInterferencePara_moveDir						943
#define RTN_MC_CrdSetInterferencePara_orgDis						944
#define RTN_MC_CrdSetInterferencePara_interfProtectDis				945
#define RTN_MC_CrdSetInterferencePara_stopCrdNo						946
#define RTN_MC_CrdGetInterferencePara_groupNo						947
#define RTN_MC_MtMoveJog_HANDLE             						948  // NMC_MtMoveJog:句柄

#define RTN_MC_MtSetPtpComparePara_HANDLE							949
#define RTN_MC_MtSetPtpComparePara_pos								950
#define RTN_MC_MtSetPtpComparePara_vel								951
#define RTN_MC_MtGetPtpCompareSts_HANDLE							952

#define RTN_MC_MtSetAxisInputShaping_HANDLE						    953
#define RTN_MC_MtSetAxisInputShaping_Busy							954
#define RTN_MC_MtSetAxisInputShaping_bufCount					    955
#define RTN_MC_MtSetAxisInputShaping_kCoef						    956
#define RTN_MC_MtSetAxisInputShaping_enable						    957

#define RTN_MC_SetCrdLeftLenForLaserWaveOff_Handle				958
#define RTN_MC_SetCrdLeftLenForLaserWaveOff_length				959

#define RTN_MC_MultiLineSetsysPara_active							960
#define RTN_MC_MultiLineSetsysPara_mapNum							961
#define RTN_MC_MultiLineSetsysPara_mapNo_repeated					962
#define RTN_MC_MultiLineSetsysPara_mapNo							963
#define RTN_MC_MultiLineSetsysPara_busy								964
#define RTN_MC_MultiLineDelete_busy									965
#define RTN_MultiLineSetOverRide_ratio								966
#define RTN_MC_MultiLineStart_active								967
#define RTN_MC_MultiLineStart_error									968
#define RTN_MC_MultiLineStart_pos_err								970
#define RTN_MC_MultiLineStart_alarm									970
#define RTN_MC_MultiLineClrData_busy								971
#define RTN_MC_MultiLineAddMoveData_vel								972
#define RTN_MC_MultiLineAddMoveData_acc								973
#define RTN_MC_MultiLineAddMoveData_dec								974
#define RTN_MC_MultiLineAddMoveData_ratio							975
#define RTN_MC_MultiLineAddMoveData_too_short						976
#define RTN_MC_MultiLineAddMoveData_fifo_full						977

#define RTN_MC_CrdBufSetScaleLimit_Handle								978
#define RTN_MC_CrdBufSetScaleLimit_pointer_null								979
#define RTN_MC_CrdBufSetScaleLimit_neg_bigger_than_pos								980
#define RTN_MC_CrdBufEnableFlyFollow_Handle							981
#define RTN_MC_CrdBufEnableFlyFollow_enable							982
#define RTN_MC_CrdStartMtn_fly_not_follow_up						983
#define RTN_MC_CrdGetFlyFollowSts_Handle								984

#define RTN_MC_CrdBufBeforeAxSyncMove_Handle						985
#define RTN_MC_CrdBufBeforeAxSyncMove_En						986
#define RTN_MC_CrdBufBeforeAxSyncMove_axis						987
#define RTN_MC_CrdBufBeforeAxSyncMove_vel						988
#define RTN_MC_ZeroPos_GantryIsSlave						    989     // NMC_MtZeroPos：如果轴是龙门从站，不能ZeroPos
#define RTN_CompHs1D_Chn_Range						    990     // 一维位置比较-高速，通道范围不正确
#define RTN_CompHs1D_DirNo_Range						991     // NMC_CompHs1DimensSetParam:编码器源范围不正确
#define RTN_CompHs1D_OutWidth_Range						992     // NMC_CompHs1DimensSetParam:out1Width/out2Width/out2Delay范围不正确(0,65535]
#define RTN_CompHs1D_SetData_Busy  					    993     // 一维位置比较-高速:正在输出
#define RTN_CompHs1D_PosCount_Range  					994     // NMC_CompHs1DimensSetData:位置数量超出范围
#define RTN_CompHs1D_Pos_NoData 					    995     // NMC_CompHs1DimensSetData:位置数量超出范围
#define RTN_MovePtpTwoStage_VelRange 					996     // NMC_MtMovePtpAbsTwoStage:参数速度范围
#define RTN_MovePtpTwoStage_PosRange 					997     // NMC_MtMovePtpAbsTwoStage:参数位置范围

#define RTN_MC_CrdSetTransXYZA_Handle					1400
#define RTN_MC_CrdSetTransXYZA_en						1401
#define RTN_MC_CrdDelTransXYZA_Handle					1402
#define RTN_MC_CrdDelTransXYZA_en						1403
#define RTN_MC_CrdSetXYZAToolCalc_Handle			    1404
#define RTN_MC_CrdSetXYZAToolCalc_en					1405
#define RTN_MC_CrdSetXYZAToolCalc_deltaTheta	        1406
#define RTN_MC_CrdSetXYZAPara_Handle					1407
#define RTN_MC_CrdSetXYZAPara_en						1408
#define RTN_MC_CrdSetXYZAPara_roundPulses			    1409
#define RTN_MC_CrdGetXYZAPara_Handle					1410
#define RTN_MC_SetProfilePeriod_Period         			1411  // SetProfilePeriod:周期范围
#define RTN_CompHs1D_Manual_Busy 					    1412     // 一维位置比较-高速:手动输出忙

#define RTN_MC_CrdSetXYZAJointTransCrdPos_HANDLE		1413
#define RTN_MC_CrdSetXYZAJointTransCrdPos_EN				1414
#define RTN_MC_CrdSetXYZAJointTransCrdPos_isTrns		1415

#define RTN_CrdBufWaitData_Handle 					1416     // NMC_CompHs1DimensSetData:位置数量超出范围
#define RTN_CrdBufWaitData_En 					    1417     // NMC_CompHs1DimensSetData:位置数量超出范围
#define RTN_CrdBufFlyFollowLnXY_Handle 			    1418     // NMC_CrdBufFlyFollowLineXY:坐标系句柄
#define RTN_CrdBufFlyFollowLnXY_En 					1419     // NMC_CrdBufFlyFollowLineXY:坐标系未启用
#define RTN_CrdBufFlyFollowLnXY_Vel 			    1420    // NMC_CrdBufFlyFollowLineXY:vel范围
#define RTN_CrdBufFlyFollowLnXY_Acc 			    1421    // NMC_CrdBufFlyFollowLineXY:acc范围
#define RTN_CrdBufAxFollowOnOff_En                  1422    // NMC_CrdBufAxFollowOnOff:crd未激活
#define RTN_CrdBufAxFollowOnOff_Handle              1423    // NMC_CrdBufAxFollowOnOff:crd句柄错误
#define RTN_CrdBufAxFollowOnOff_AxMaster            1424    // NMC_CrdBufAxFollowOnOff:axMaster参数范围不正确
#define RTN_MC_DoBitPulse_Busy						1425	// DoBitPulse正在输出
#define RTN_MC_CrdBufDoBitPulse_EN					1426	// DoBitPulse坐标系未使能
#define RTN_MC_CrdBufDoBitPulse_Handle				1427	// DoBitPulse坐标系句柄错误
#define RTN_MC_ConfigSHIOPara_AxMask_Cnt			1428    //  NMC_ConfigHSIOPara:axisMask错误，最多只能两个轴

#define RTN_MC_CrdBufSetLeftLenForLaserWaveOff_Handle		1428	 
#define RTN_MC_CrdBufSetLeftLenForLaserWaveOff_En				1429	 
#define RTN_MC_CrdBufSetLeftLenForLaserWaveOff_length		1430	 
#define RTN_MC_CrdBufLaserOnOff_Section									1431
#define RTN_MC_ConfigSHIOPara_k									1432    // NMC_ConfigHSIOPara:k值范围不正确[0,255]


#define RTN_MC_SetDacLimit_Val									1433    // NMC_SetDacLmt:最大值不能小于等于最小值
#define RTN_MC_AdvBufIo_Ch										1434     // AdvBufIo:ch范围不正确，[0,MAX_ADV_BUFIO_GROUP]
#define RTN_MC_AdvBufIoSetParam_OnTime				            1435     // NMC_AdvBufIoSetParam:onTime不能小于等于0
#define RTN_MC_AdvBufIoSetParam_OffTime				            1436     // NMC_AdvBufIoSetParam:offTime不能小于等于0
#define RTN_MC_GetStsMulti_AxisRange							1437     // NMC_MtGetStsMulti等multi指令轴号范围不正确
#define RTN_MC_GetStsMulti_CountRange							1438     // NMC_MtGetStsMulti等multi指令count范围不正确
#define RTN_MC_DiReverseCount_DiType							1439     // NMC_SetDiReverseCount:diType范围不正确
#define RTN_MC_DiReverseCount_DiIdx							    1440     // NMC_SetDiReverseCount:diIndex范围不正确
#define RTN_MC_DiReverseCount_Count							    1441     // NMC_SetDiReverseCount:count范围不正确
#define RTN_MC_SetDOMask_DoType                                 1442     // NMC_SetDOMask:doType范围不正确
#define RTN_MC_SetDOMask_DoGroup                                1443     // NMC_SetDOMask:groupID范围不正确
#define RTN_MC_SetCaptRepeat_Count                              1444     // NMC_MtSetCaptRepeat:count范围不正确
#define RTN_MC_SetCaptRepeat_StartNum                           1445     // NMC_MtSetCaptRepeat:StartNum范围不正确
#define RTN_MC_SetCaptRepeat_Num                                1446     // NMC_MtSetCaptRepeat:总数范围不正确
#define RTN_MC_CrdBufStopMtn_Handle                             1447     // NMC_CrdBufStopMtn:hanle
#define RTN_MC_CrdBufStopMtn_En                                 1448     // NMC_CrdBufStopMtn:en
#define RTN_MC_CrdBufStopMtn_Idx                                1449     // NMC_CrdBufStopMtn:crdIdx范围不正确，-1，0或者1
#define RTN_MC_GetDOEx_DoType                                   1450     // NMC_GetDOEx:doType范围不正确
#define RTN_MC_SetDOMask_Group                                  1451     // NMC_GetDOEx:group范围不正确
#define RTN_MC_SetDOMask_En                                     1452     // NMC_GetDOEx:扩展模块
#define RTN_NMC_MtPtStartMtnEx_no_pt_mode                       1453     // NMC_MtPtStartMtnEx:非PT模式
#define RTN_NMC_MtPtStartMtnEx_isBusy                           1454     // NMC_MtPtStartMtnEx:Busy
#define RTN_NMC_MtPtStartMtnEx_DiIndex                          1455     // NMC_MtPtStartMtnEx:diIndex范围错误


#define RTN_MC_MtGearSetDir_HANDLE															1456
#define RTN_MC_MtGearSetDir_not_gear_mode												1457
#define RTN_MC_MtGearGetDir_HANDLE															1458
#define RTN_MC_MtGearGetDir_not_gear_mode												1459
#define RTN_MC_MtGearSetMaster_HANDLE														1460
#define RTN_MC_MtGearSetMaster_not_gear_mode										1461
#define RTN_MC_MtGearSetMaster_isBusy														1462
#define RTN_MC_MtGearSetMaster_masterType												1463
#define RTN_MC_MtGearSetMaster_masterNo													1464
#define RTN_MC_MtGearGetMaster_HANDLE														1465
#define RTN_MC_MtGearGetMaster_not_gear_mode										1466
#define RTN_MC_MtGearSetRatio_HANDLE														1467
#define RTN_MC_MtGearSetRatio_not_gear_mode											1468
#define RTN_MC_MtGearSetRatio_masterEven												1469
#define RTN_MC_MtGearSetRatio_masterSlope												1470
#define RTN_MC_MtGearGetRatio_HANDLE														1471
#define RTN_MC_MtGearGetRatio_not_gear_mode											1472
#define RTN_MC_MtGearStartMtn_HANDLE														1473
#define RTN_MC_MtGearStartMtn_syncAxCnts												1474
#define RTN_MC_MtGearStartMtn_one_not_gear_mode									1475

#define RTN_NMC_FollowSetDir_HANDLE															1476
#define RTN_NMC_FollowSetDir_not_gear_mode											1477
#define RTN_NMC_FollowGetDir_HANDLE															1478
#define RTN_NMC_FollowGetDir_not_gear_mode											1479
#define RTN_NMC_SetFollowMaster_HANDLE													1480
#define RTN_NMC_SetFollowMaster_not_follow_mode									1481
#define RTN_NMC_SetFollowMaster_isBusy													1482
#define RTN_NMC_SetFollowMaster_masterType											1483
#define RTN_NMC_SetFollowMaster_masterNo												1484
#define RTN_NMC_FollowGetMaster_HANDLE													1485
#define RTN_NMC_FollowGetMaster_not_follow_mode									1486
#define RTN_NMC_FollowSetLoopCount_HANDLE												1487
#define RTN_NMC_FollowSetLoopCount_not_follow_mode							1488
#define RTN_NMC_FollowGetLoopCount_HANDLE												1489
#define RTN_NMC_FollowGetLoopCount_not_follow_mode							1490
#define RTN_NMC_FollowSetEvent_HANDLE														1491
#define RTN_NMC_FollowSetEvent_not_follow_mode									1492
#define RTN_NMC_FollowSetEvent_event														1493	
#define RTN_NMC_FollowSetEvent_pos															1494
#define RTN_NMC_FollowGetEvent_HANDLE														1495
#define RTN_NMC_FollowGetEvent_not_follow_mode									1496
#define RTN_NMC_FollowGetSpace_HANDLE														1497
#define RTN_NMC_FollowGetSpace_not_follow_mode									1498
#define RTN_NMC_FollowGetSpace_fifoNo														1499
#define RTN_NMC_FollowPushData_HANDLE														1500
#define RTN_NMC_FollowPushData_not_follow_mode									1501
#define RTN_NMC_FollowPushData_fifoNo														1502
#define RTN_NMC_FollowPushData_no_space													1503	
#define RTN_NMC_FollowPushData_masterSegment										1504				
#define RTN_NMC_FollowPushData_slaveSegment											1505				
#define RTN_NMC_FollowPushData_type															1506						
#define RTN_NMC_FollowClear_HANDLE															1507						
#define RTN_NMC_FollowClear_not_follow_mode											1508											
#define RTN_NMC_FollowClear_fifoNo															1509							
#define RTN_NMC_FollowClear_isBusy															1510											
#define RTN_NMC_FollowStart_HANDLE															1511											
#define RTN_NMC_FollowStart_syncAxCnts													1512							
#define RTN_NMC_FollowStart_no_follow_mode											1513										
	#define RTN_NMC_FollowStart_one_axis_isBusy										1514								
	#define RTN_NMC_FollowSwitch_HANDLE														1515													
#define RTN_NMC_FollowSwitch_syncAxCnts													1516										
#define RTN_NMC_FollowSwitch_no_follow_mode											1517								
#define RTN_NMC_FollowStart_one_axis_isStop											1518							

#define RTN_MC_CrdBufWait_WaitType											1519        // NMC_CrdBufWait:不支持的wait类型

#define RTN_MC_MtSetAxisDampCompParam_HANDLE											1520 
#define RTN_MC_MtSetAxisDampCompParam_enable											1521
#define RTN_MC_MtSetAxisDampCompParam_param1											1522
#define RTN_MC_MtSetAxisDampCompParam_param2											1523

#define RTN_MC_SetDOBitRevesEx_DoType										1524    // NMC_SetDOBitRevsEx:DoType参数不正确
#define RTN_MC_SetDOBitRevesEx_Group										1525    // NMC_SetDOBitRevsEx:group参数不正确
#define RTN_CommonRead_Unsupported											1525    // NMC_CommonRead:指令字不支持
#define RTN_CommonWrite_Unsupported											1525    // NMC_CommonWrite:指令字不支持
#define RTN_MC_Comp2DimensSetData_Busy										1526    // NMC_Comp2DimensSetData:busy状态下不允许清除数据
#define RTN_MC_Comp2DimensSetParam_Gatetime									1527    // Comp2DimensSetParam:Gatetime参数范围错误(1,32760]
#define RTN_MC_Comp2DimensOnoff_PopData										1528    // NMC_Comp2DimensOnoff:获取数据

#define RTN_SetEstopDIEx_Group												1529    // NMC_SetEstopDIEx:参数Group范围错误
#define RTN_SetEstopDIEx_DiType												1530    // NMC_SetEstopDIEx:参数ditype范围错误
#define RTN_SetEstopDIEx_DiIndex											1531    // NMC_SetEstopDIEx:参数diindex范围错误
#define RTN_SetEstopDIEx_Filter												1532    // NMC_SetEstopDIEx:参数Filter范围错误

#define RTN_MC_Set2DCompensationTable_tableIndex							1533	// Set2DCompensationTable:参数tableIndex范围错误
#define RTN_MC_Set2DCompensationTable_count									1534	// Set2DCompensationTable:参数count	范围错误
#define RTN_MC_Set2DCompensationTable_step									1535	// Set2DCompensationTable:参数step范围错误
#define RTN_MC_Set2DCompensation_enable										1536	// Set2DCompensationTable:参数enable范围错误
#define RTN_MC_Set2DCompensation_axisIndex									1537	// Set2DCompensation:参数axisIndex范围错误
#define RTN_MC_Set2DCompensation_axisType									1538	// Set2DCompensation:参数axisType范围错误
#define RTN_MC_Set2DCompensation_tableIndex									1539	// Set2DCompensation:参数tableIndex范围错误
#define RTN_MC_Set2DCompensation_busy										1540	// Set2DCompensation:busy
#define RTN_MC_Set2DCompensation_MemErr										1541	// Set2DCompensation:内存错误
#define RTN_MC_Set2DCompensation_DataLen									1542	// Set2DCompensation:不支持多表格或者长度
#define RTN_MC_GetTrapTime_Mode												1543 	// NMC_MtGetTrapTime:当前轴不是PTP模式
#define RTN_MC_MtPtSetPara_HANDLE											1544	// NMC_MtPtSetPara:句柄错误
#define RTN_NMC_MtPtSetPara_no_pt_mode										1545	// NMC_MtPtSetPara:不是PT模式
#define RTN_NMC_MtPtSetPara_smoothDec										1546	// NMC_MtPtSetPara:smoothDec参数范围错误
#define RTN_NMC_MtPtSetPara_abruptDec										1547	// NMC_MtPtSetPara:abruptDec参数范围错误
#define RTN_NMC_DIFilter_Index												1548	// NMC_SetDIFilter/NMC_GetDIFilter:diIndex参数范围错误
#define RTN_NMC_DIFilter_Group												1549	// NMC_SetDIFilter/NMC_GetDIFilter:diGroup
#define RTN_NMC_DIFilter_FiltTime											1550	// NMC_SetDIFilter:filtTime


#define RTN_MC_MtPvtSetStatic_HANDLE												1548
#define RTN_NMC_MtPvtSetStatic_no_pvt_mode                  1549
#define RTN_NMC_MtPvtSetStatic_onOff                        1550
#define RTN_MC_MtPvtSetPara_HANDLE                          1551
#define RTN_NMC_MtPvtSetPara_no_pvt_mode                    1552
#define RTN_NMC_MtPvtSetPara_smoothDec                      1553
#define RTN_NMC_MtPvtSetPara_abruptDec                      1554
#define RTN_MC_MtPvtGetStatic_HANDLE                        1555
#define RTN_NMC_MtPvtGetStatic_no_pvt_mode                  1556
#define RTN_MC_MtPvtGetSpace_HANDLE                         1557
#define RTN_NMC_MtPtGetSpace_no_pvt_mode                    1558
#define RTN_MtPvtData_HANDLE                                1559
#define RTN_NMC_MtPvtData_no_pt_mode                        1560
#define RTN_NMC_MtPvtData_count                             1561
#define RTN_NMC_MtPvtData_pos                               1562
#define RTN_NMC_MtPvtData_time                              1563
#define RTN_MC_MtPvtBufClr_HANDLE                           1564
#define RTN_NMC_MtPtBufClr_no_pvt_mode                      1565
#define RTN_NMC_MtPvtBufClr_busy                            1566
#define RTN_MC_MtPvtStartMtnEx_HANDLE                       1567
#define RTN_NMC_MtPvtStartMtnEx_DiIndex                     1568
#define RTN_NMC_MtPvtStartMtnEx_no_pt_mode                  1569
#define RTN_NMC_MtPvtStartMtnEx_isBusy                      1570
#define RTN_MC_MtPvtStartMtn_HANDLE                         1571
#define RTN_NMC_MtPvtStartMtn_syncAxCnts                    1572
#define RTN_NMC_MtPvtStartMtn_no_pt_mode                    1573
#define RTN_NMC_MtPvtStartMtn_one_axis_isBusy               1574
#define RTN_NMC_MtPvtStartMtn_no_data                       1575

#define RTN_MC_CrdGetDoubleHeadPara_HANDLE									1576
#define RTN_MC_CrdGetDoubleHeadPara_EN											1577
#define RTN_MC_CrdGetDoubleHeadPara_pAxisNo									1578
#define RTN_MC_CrdSetDoubleHeadPara_offset									1579
#define RTN_MC_CrdSetDoubleHeadPara_HANDLE									1580
#define RTN_MC_CrdSetDoubleHeadPara_EN											1581
#define RTN_MC_CrdSetDoubleHeadPara_pAxisNo									1582
#define RTN_MC_CrdSetDoubleHeadPara_pAxisNo_BUSY						1583
#define RTN_MC_CrdBufObjectSwitch_HANDLE										1584
#define RTN_CrdBufObjectSwitch_EN														1585
#define RTN_MC_CrdBufSetupSecondHeadSyncMove_HANDLE					1586
#define RTN_CrdBufSetupSecondHeadSyncMove_EN								1587
#define RTN_MC_CrdBufEndSecondHeadSyncMove_HANDLE					1586
#define RTN_CrdBufEndSecondHeadSyncMove_EN								1587

// ethercat
#define ECT_ERR_INIT                     10001  //obsolet
#define ECT_ERR_TIMEOUT                  10002  //obsolet
#define ECT_ERR_PARA                     10003  //参数错误，请检查参数合法性
#define ECT_ERR_MASTER_REQUEST           10004  //请求主机结构失败，一般为内存错误，动态内存不够
#define ECT_ERR_CREAT_DOMAIN             10005  //创建domain失败，一般为内存错误，动态内存不够
#define ECT_ERR_REFERENCE_CLOCK_SEL      10006  //选择参考时钟失败
#define ECT_ERR_MASTER_ACTIVE            10007  //激活主机失败，可能的原因是domain数据报内存分配失败
#define ECT_ERR_GET_DOMAIN_DATA          10008  //获取domain数据块指针失败，可能的原因是domain创建失败
#define ECT_ERR_MODULE_INIT              10009  //硬件资源初始化失败，一般为内存错误，动态内存不够
#define ECT_ERR_NET_DEV_INIT             10010 //网口驱动初始化失败，设备未注册，或内存错误
#define ECT_ERR_HWTIMER_NS_INIT          10011 //硬件纳秒定时器初始化失败
#define ECT_ERR_HWTIMER_START            10012 //硬件纳秒定时器启动失败
#define ECT_ERR_SLAVE_NOT_FOUND          10013 //未发现从站，一般原因是主站未准备好
#define ECT_ERR_IOCTL_GET_MASTER_INFO    10014 //获取主站信息失败
#define ECT_ERR_IOCTL_GET_SLAVE_INFO     10015 //获取从站信息失败
#define ECT_ERR_IOCTL_GET_SYNC           10016 //获取同步数据信息失败
#define ECT_ERR_IOCTL_GET_PDO            10017 //获取PDO(INDEX)失败
#define ECT_ERR_IOCTL_GET_PDO_ENTRY      10018 //获取PDO(ENTRY)失败
#define ECT_ERR_MASTER_NOT_OP            10019 //未进入OP状态，需要查询主站状态为OP时，方可进行其它操作
#define ECT_ERR_HOME_METHOD_GET          10020 //获取回零方式失败
#define ECT_ERR_HOME_VSWITH_GET          10021 //获取回零找开关速度失败
#define ECT_ERR_HOME_VZERO_GET           10022 //获取回零时找Z相速度失败
#define ECT_ERR_HOME_ACC_GET             10023 //获取回零加速度失败
#define ECT_ERR_HOME_METHOD_SET          10024 //设置回零方式设置失败，可能的错误：未找到从站，不支持的回零方式，内存错误
#define ECT_ERR_HOME_VSWITH_SET          10025 //设置回零找开关速度失败，可能的错误：未找到从站，内存错误
#define ECT_ERR_HOME_VZERO_SET           10026 //设置回零时找Z相速度失败，可能的错误：未找到从站，内存错误
#define ECT_ERR_HOME_ACC_SET             10027 //设置回零加速度失败，可能的错误：未找到从站，内存错误
#define ECT_ERR_NOT_SRVON                10028 //伺服未使能
#define ECT_ERR_GET_SRVON                10029 //获取伺服使能失败，可能的错误：未找到从站，主站未准备好
#define ECT_ERR_MC_READ                  10030 //PDO寄存器读失败，PDO未配置
#define ECT_ERR_MC_WRITE                 10031 //PDO寄存器写失败，PDO未配置
#define ECT_ERR_IOCTL_DEVICE_NOT_FOUND   10032 //从站未找到
#define ECT_ERR_IOCTL_DEV_NOT_MATCH      10033 //从站（vid,pid）不匹配
#define ECT_ERR_MEM_SYNC                 10034 //申请sync内存失败
#define ECT_ERR_MEM_PDO_INFO             10035 //申请pdo info内存失败
#define ECT_ERR_MEM_PDO_ENTRY            10036 //申请pdo entry内存失败
#define ECT_ERR_IOCTL_SDO_UPLOAD         10037 //SDO上传失败
#define ECT_ERR_IOCTL_SDO_DOWNLOAD       10038 //SDO下载失败
#define ECT_ERR_DEVICE_NOT_FOUND         10039 //主站未注册或主站初始化未完成
#define ECT_ERR_FIND_SLAVE               10040 //未找到从站，可能的原因，配置阶段网络掉线
#define ECT_ERR_SLAVE_CONFIG             10041 //配置从站失败
#define ECT_ERR_DEVICE_ID_NOT_MATCH      10042 //设备ID不匹配
#define ECT_ERR_SLAVE_CONFIG_PDOS        10043 //从站PDO配置失败
#define ECT_ERR_SLAVE_CONFIG_REG_PDO_ENTRY   10044//从站PDO注册失败
#define ECT_ERR_NOT_CONFIG               10045 //未配置从站，主站启动前需要先配置从站
#define ECT_ERR_NO_SUPPORT               10046 //不支持的从站设备
#define ECT_ERR_SUPPORTLIST_FULL         10047 //超出了可支持的最大从站数量
#define ECT_ERR_MASTER_NO_RUN            10048 //主站未启动
#define ECT_ERR_HOME_RUNNING             10049 //回零运行中
#define ECT_ERR_SCAN_BUSY                10050 //主站正在扫描从站，需等待主站状态完成
#define ECT_ERR_MASTER_RUNNING			 10051 //主站正在运行中，不允许的操作
#define ECT_ERR_MEM_SM                   10052 //申请sync manager内存失败
#define ECT_ERR_MEM_PDO                  10053 //申请PDO内存失败
#define ECT_ERR_DEV_TYPE                 10054 //从站类型不匹配（从站不支持）
#define ECT_ERR_NO_SLAVE                 10055 //未找到该从站

#define RTN_MC_EcatGetHomePara_HANDLE									11533		// NMC_EcatGetHomePara:句柄错误或者驱动器不存在
#define RTN_MC_EcatSetHomePara_HANDLE									11534		// NMC_EcatSetHomePara:句柄错误或者驱动器不存在
#define RTN_MC_EcatSetHomeSts_HANDLE									11535		// NMC_EcatSetHomeSt:句柄错误或者驱动器不存在
#define RTN_MC_EcatStartHome_HANDLE										11536		// NMC_EcatStartHome:句柄错误或者驱动器不存在
#define RTN_MC_EcatStopHome_HANDLE										11537		// NMC_EcatStopHome:句柄错误或者驱动器不存在
#define RTN_MC_EcatIOGetInput_ioId										11538		// NMC_EcatIOGetInput:IO模块不存在
#define RTN_EcatIOGetOutput_ioId										11539		// NMC_EcatIOSetOutput:IO模块不存在
#define RTN_EcatIOSetOutput_ioId										11540		// NMC_EcatIOSetOutput:IO模块不存在
#define RTN_MC_EcatGetAxisDi_HANDLE										11541		// NMC_EcatGetAxisDi:句柄错误或者驱动器不存在
#define RTN_MC_EcatGetAxisErrorCode_HANDLE								11542		// NMC_EcatGetAxisErrorCode:句柄错误或者驱动器不存在	
#define RTN_MC_EcatGetAxisMode_HANDLE									11543		// NMC_EcatGetAxisMode:句柄错误或者驱动器不存在
#define RTN_MC_EcatSetAxisMode_HANDLE									11544		// NMC_EcatSetAxisMode:句柄错误或者驱动器不存在
#define RTN_MC_SetGantrySlave_not_same_axis_type						11545		// NMC_SetGantrySlave:轴状态错误
#define RTN_MC_Not_support_ECAT_axis									11546		// ethercat轴不支持的功能或者轴号超出范围
#define RTN_MC_Ecat_GetInfo_End											11247		// NMC_EcatGetSaveInfo:从站号超出
#define RTN_MC_EcatStartHome_Prm										11248		// NMC_EcatStartHome:参数错误



#endif	//__H_MTN20_ERR_H__

