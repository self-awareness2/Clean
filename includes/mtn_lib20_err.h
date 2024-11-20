////*****************************************************************
// Moudle Name  :   nmc_lib20_err.h
// Abstract     :   ������붨��
// Note :			��//��֮��Ϊ�������˵�����ڶ���'//'֮��Ϊ����Ľ���Ĵ�����
////*****************************************************************
#ifndef __H_MTN20_ERR_H__
#define __H_MTN20_ERR_H__

// ���󷵻�ֵ���:���ģʽ
#define     RTN_LIB_UNSUPPORT           -1              // ��ָ�֧�� 
#define     RTN_LIB_PARA_ERROR           -2              //��ָ�������֧�� 
#define     RTN_DRV_ERROR                   -3              // �����ݳ���ָ���峤�ȳ� 
#define     RTN_FRAME_ERROR               -4              // �����ݳ���ָ���峤�ȳ� 
#define     RTN_FRAME_UNSUPPORT     -5              // �����Ͳ�֧�ִ���         
#define     RTN_FRAME_TIMEOUT           -6              // �����ݳ�ʱ               
#define     RTN_FRAME_SUM_ERROR      -7              // ����ʹ���               
#define     RTN_VEC_FHASE_ERROR        -8              // ʸ��������ʱ��֧��     
#define     RTN_VEC_FIFO_FULL              -9              // ��������                                                           
#define     RTN_CMD_UNSUPPORT        -10              // ָ�֧��               
#define     RTN_CMD_PARA_ERROR        -11              //����1����Χ����         
#define     RTN_CMD_EXE_ERROR           -12              // ִ��ʧ��                 
#define     RTN_CMD_PARA2_ERROR        -13             //����2����Χ����   
#define     RTN_CMD_PARA3_ERROR        -14             //����3����Χ����   
#define     RTN_CMD_PARA4_ERROR        -15             //����4����Χ����   
#define     RTN_CMD_PARA5_ERROR        -16             //����5����Χ����   
#define     RTN_CMD_PARA6_ERROR        -17             //����6����Χ����   
#define     RTN_CMD_PARA7_ERROR        -18             //����7����Χ����   
#define     RTN_CMD_PARA8_ERROR        -19             //����8����Χ����   
#define     RTN_CMD_PARA9_ERROR        -20             //����9����Χ����   
#define     RTN_CMD_PARA_OTHER         -21			   //��������     


// �������
#define RTN_CMD_SUCCESS			0		        // ָ��ɹ�ִ��
#define RTN_CMD_TBD				999				// TBD

// return error code form Library,[1,99]
#define RTN_LIB_SEARCH_MODE						1	// NMC_DevSearch:��֧�ֵ�����ģʽ
#define RTN_LIB_OPEN_INDEX						2	// NMC_DevOpen:��Ų���С��0
#define RTN_LIB_OPEN_COMM						3	// NMC_DevOpen:�˿ڴ򿪴���
#define RTN_LIB_OPEN_COMM2						4	// NMC_DevOpenByID:�˿ڴ򿪴���
#define RTN_LIB_ID_WRITE						5	// NMC_DevWriteID:дID����
#define RTN_LIB_ID_READ							6	// NMC_DevReadID:��ID����
#define RTN_LIB_NOT_CONNECT						7	// NMC_CrdOpen:�豸δ��
#define RTN_LIB_MT_INDEX						8	// NMC_MtOpen:���С��0���ߴ���16
#define RTN_LIB_LINE_AXCNT						9	// NMC_CrdLineXYZ:��������Χ����ȷ
#define RTN_LIB_LOCK							10	// ͨѶ������
#define RTN_LIB_DEBUG_MODE						11	// NMC_SetCmdDebug:��Debugģʽ����
#define RTN_LIB_DEBUG_FILE_CRT					12	// NMC_SetCmdDebug:debug�ļ�����
#define RTN_LIB_DEBUG_FILE_OPEN					13	// NMC_SetCmdDebug:debug�ļ���
#define RTN_LIB_DEBUG_H_OPEN					14	// NMC_SetCmdDebug:ͨѶ��
#define RTN_LIB_CRDGetAxisPos_Cnt				15	// NMC_CrdGetAxisPos:cnts������Χ����ȷ[1,N]
#define RTN_LIB_CRDGetPos_Cnt					16	// NMC_CrdGetPrfPos��cnts������Χ����ȷ[1,N]
#define RTN_LIB_CRDGetEncPos_Cnt				17	// NMC_CrdGetEncPos��cnts������Χ����ȷ[1,N]
#define RTN_LIB_BackSramWrite_LEN				18	// NMC_BackSramWrite���ݳ��ȳ�����Χ[1,240]
#define RTN_LIB_BackSramRead_LEN				19	// NMC_BackSramRead���ݳ��ȳ�����Χ[1,240]
#define RTN_LIB_UserParaWr_LEN					20	// NMC_UserParaWr���ݳ��ȳ�����Χ[1,240]
#define RTN_LIB_UserParaRd_LEN					21	// NMC_UserParaRd���ݳ��ȳ�����Χ[1,240]
#define RTN_LIB_CRDLINEXYZPACK_Cnt				22	// NMC_CrdLineXYZPack:��Χ����ȷ��[1,5]
#define RTN_LIB_COLLECT_DATA_LEN				23	// NMC_GetCollectData:len
#define RTN_LIB_CONFIG_FILE						24	// NMC_SaveConfigToFile:�����ļ�����
#define RTN_LIB_NOT_READY						25	// �Զ�����û��׼����
#define RTN_LIB_AXIS_CNT						26	// ��������������
#define RTN_LIB_DEV_COMM						27	// PCIE����ʵ��ͨѶ����
#define RTN_LIB_CFG_FILE						28	// CFG�ļ����������ļ���ʽ��������Ҳ���ĳЩ���������Ϣ

// return error code form HostComm,[100,199]
#define RTN_COMM_PARA_LEN						100	// �������Ȳ�����
#define RTN_COMM_CMD_UNSUPPORT					101	// ָ���ֲ�֧��
#define RTN_COMM_TOP_UNSUPPORT					102	// ����ָ���ֲ�֧��
#define RTN_COMM_TOP_PARA						103	// ���˲�������
#define RTN_COMM_BACKSRAMREAD					104	// NMC_BackSramRead:��������//����ַ�����Ƿ����
#define RTN_COMM_BACKSRAMWRITE					105	// NMC_BackSramWrite:��������//����ַ�����Ƿ����
#define RTN_COMM_SYSUPGRADEEX					106	// NMC_SYSUPGRADEEXִ��ʧ��
#define RTN_COMM_DEVSETPARA						107	// NMC_DevSetParaִ��ʧ��
#define RTN_COMM_DEVGETPARA						108	// NMC_DevGetParaִ��ʧ��
#define RTN_COMM_GETTIME						109 // NMC_GetTimeִ�д���
#define RTN_COMM_USERPARAWR_PRM					110 // NMC_UserParaWr��������
#define RTN_COMM_USERPARAWR_EXE					111 // NMC_UserParaWrִ�д���
#define RTN_COMM_USERPARARD_PRM					112 // NMC_UserParaRd��������

// return error code form Command
#define RTN_MC_MT_OPEN_INDEX						1000	// NMC_MtOpen:itemNo�������ش���
#define RTN_MC_MT_LMT_POSSWT						1001	// NMC_MtLmtOnOff:posSwt������Χ����ȷ[0,1]
#define RTN_MC_MT_LMT_NEGSWT						1002	// NMC_MtLmtOnOff:negSwt������Χ����ȷ[0,1]
#define RTN_MC_MT_LMT_HANDLE						1003	// NMC_MtLmtOnOff:axisHandle����
#define RTN_MC_MT_GETLMT_HANDLE						1004	// NMC_MtGetLmtOnOff:axisHandle����
#define RTN_MC_MT_LMTSNS_POSSWT						1005	// NMC_MtLmtSns:posSwt������Χ����ȷ[0,1]
#define RTN_MC_MT_LMTSNS_NEGSWT						1006	// NMC_MtLmtSns:negSwt������Χ����ȷ[0,1]
#define RTN_MC_MT_LMTSNS_HANDLE						1007	// NMC_MtLmtSns:axisHandle����
#define RTN_MC_MT_GETLMTSNS_HANDLE					1008	// NMC_MtGetLmtSns:axisHandle����

#define RTN_MC_MT_ALMON_SWT							1010	// NMC_MtAlarmOnOff:swt������Χ����ȷ[0,1]
#define RTN_MC_MT_ALMON_HANDLE						1011	// NMC_MtAlarmOnOff:axisHandle����
#define RTN_MC_MT_GETALMON_HANDLE					1012	// NMC_MtGetAlarmOnOff:axisHandle����
#define RTN_MC_MT_ALMSns_SWT						1013	// NMC_MtAlarmSns:swt������Χ����ȷ[0,1]
#define RTN_MC_MT_ALMSns_HANDLE						1014	// NMC_MtAlarmSns:axisHandle����
#define RTN_MC_MT_GETALSns_HANDLE					1015	// NMC_MtGetAlarmSns:axisHandle����
#define RTN_MC_MT_SwLmtOn_SWT						1016	// NMC_MtSwLmtOnOff:swt������Χ����ȷ[0,1]
#define RTN_MC_MT_SwLmtOn_HANDLE					1017	// NMC_MtSwLmtOnOff:axisHandle����
#define RTN_MC_MT_GetSwLmtOn_HANDLE					1018	// NMC_MtGetSwLmtOnOff:axisHandle����
#define RTN_MC_MT_SwLmtV_POS						1019	// NMC_MtSwLmtValue:��������λֵ��Ӧ��С�ڵ��ڸ���
#define RTN_MC_MT_SwLmtV_HANDLE						1020	// NMC_MtSwLmtValue:axisHandle����
#define RTN_MC_MT_GetSwLmtV_HANDLE					1021	// NMC_MtGetSwLmtValue:axisHandle����
#define RTN_MC_MT_PosErr_VALUE						1022	// NMC_MtSetPosErrLmt:posErrλ������С��0
#define RTN_MC_MT_PosErr_HANDLE						1023	// NMC_MtSetPosErrLmt:axisHandle����
#define RTN_MC_MT_GetPosErr_HANDLE					1024	// NMC_MtGetPosErrLmt:axisHandle����
#define RTN_MC_MT_SafePara_HANDLE					1025	// NMC_MtSetSafePara:axisHandle����
#define RTN_MC_MT_SafeParaEdec						1026	// NMC_MtSetSafePara:estpDec�������0
#define RTN_MC_MT_SafeParaMaxV						1027	// NMC_MtSetSafePara:maxVel�������0
#define RTN_MC_MT_SafeParaMaxA						1028	// NMC_MtSetSafePara:maxAcc�������0
#define RTN_MC_MT_GetSafePara_HANDLE				1029	// NMC_MtGetSafePara:axisHandle����
#define RTN_MC_SvrOn_HANDLE							1030	// NMC_MtSetSvOn:axisHandle����
#define RTN_MC_SvrOff_HANDLE						1031	// NMC_MtSetSvOn:axisHandle����
#define RTN_MC_SetPos_HANDLE						1032	// NMC_MtSetAxisPos:axisHandle����
#define RTN_MC_SetEncPos_HANDLE						1033	// NMC_MtSetEncPos:axisHandle����
#define RTN_MC_GetAPos_HANDLE						1034	// NMC_MtGetAxisPos:axisHandle����
#define RTN_MC_GetPPos_HANDLE						1035	// NMC_MtGetPrfPos:axisHandle����
#define RTN_MC_GetEPos_HANDLE						1036	// NMC_MtGetEncPos:axisHandle����
#define RTN_MC_GetCPos_HANDLE						1037	// NMC_MtGetCmdPos:axisHandle����
#define RTN_MC_SetCapSns_HANDLE						1038	// NMC_MtSetCaptSns:axisHandle����
#define RTN_MC_GetCapSns_HANDLE						1039	// NMC_MtGetCaptSns:axisHandle����
#define RTN_MC_SetCap_HANDLE						1040	// NMC_MtSetCapt:axisHandle����
#define RTN_MC_GetCapPos_HANDLE						1041	// NMC_MtGetCaptPos:axisHandle����
#define RTN_MC_GetSts_HANDLE						1042	// NMC_MtGetSts:axisHandle����
#define RTN_MC_SetStepMode_HANDLE					1043	// NMC_MtSetStepMode:axisHandle����
#define RTN_MC_SetStepMode_Mode						1044	// NMC_MtSetStepMode:mode������Χ����[0,1]
#define RTN_MC_SetStepMode_Invert					1045	// NMC_MtSetStepMode:invert������Χ����[0,1]
#define RTN_MC_GetStepMode_HANDLE					1046	// NMC_MtGetStepMode:axisHandle����
#define RTN_MC_GetMIo_HANDLE						1047	// NMC_MtGetMotionIO:axisHandle����
#define RTN_MC_GetStsP_Count						1048	// NMC_MtGetStsPack:axisHandle����
#define RTN_MC_GetStsP_AxNum						1049	// NMC_MtGetStsPack:axisHandle����
#define RTN_MC_SvClr_HANDLE							1050	// NMC_MtSetSvClr:axisHandle����
#define RTN_IO_SetDo_GROUP							1051	// NMC_SetDO:groupID��Χ����[0,n]
#define RTN_IO_GetDo_GROUP							1052	// NMC_GetDO:gourpID��Χ����[0,n]
#define RTN_IO_SetDoBit_INDEX						1053	// NMC_SetDOBit:bitIndex����
#define RTN_IO_SetDoBit_GROUP						1054	// NMC_SetDOBit:gourpID����
#define RTN_IO_GetDi_GROUP							1055	// NMC_GetDI:gourpID����
#define RTN_IO_GetDiBit_INDEX						1056	// NMC_GetDIBit:bitIndex����
#define RTN_IO_GetDiBit_GROUP						1057	// NMC_GetDIBit:gourpID����
#define RTN_IO_GetEncV_INDEX						1058	// NMC_GetEncVel:encId����
#define RTN_IO_GetEncPos_INDEX						1059	// NMC_GetEncPos:axisHandle����
#define RTN_MC_SetVar_ID							1060	// NMC_SetVar8B:varID����
#define RTN_MC_GetVar_ID							1061	// NMC_GetVar8B:varID����
#define RTN_MC_SysGetVar_ID							1062	// NMC_SysSetVar8B:varID����
#define RTN_MC_SysSetVar_ID							1063	// NMC_SysGetVar8B:varID����
#define RTN_MC_GetEncMode_ID						1064	// NMC_GetEncMode:encID����
#define RTN_MC_SetEncMode_ID						1065	// NMC_SetEncMode:encID����
#define RTN_MC_SetEncMode_MOVE						1066	// NMC_SetEncMode:�����˶�����������
#define RTN_MC_SetStepFilt_HANDLE					1067	// NMC_MtSetStepFilter:axisHandle����
#define RTN_MC_PrfCfg_HANDLE						1068	// NMC_MtPrfConfig:axisHandle����
#define RTN_MC_PrfCfg_PORT							1069	// NMC_MtPrfConfig:port��Χ����[0,1]
#define RTN_MC_GetPrfCfg_HANDLE						1070	// NMC_MtGetPrfConfig:axisHandle����
#define RTN_MC_SetPrfMode_HANDLE					1071	// NMC_MtSetPrfMode:axisHandle����
#define RTN_MC_SetPrfMode_UNSUPPORT					1072	// NMC_MtSetPrfMode:ģʽ��֧�ִ���
#define RTN_MC_GetPrfMode_HANDLE					1073	// NMC_MtGetPrfMode:axisHandle����
#define RTN_MC_SetPtpPrm_HANDLE						1074	// NMC_MtSetPtpPara:axisHandle����
#define RTN_MC_SetPtpPrm_SVEL						1075	// NMC_MtSetPtpPara:startVel����С��0
#define RTN_MC_SetPtpPrm_EVEL						1076	// NMC_MtSetPtpPara:endVel����С��0
#define RTN_MC_SetPtpPrm_ACC						1077	// NMC_MtSetPtpPara:acc����С�ڵ���0
#define RTN_MC_SetPtpPrm_DEC						1078	// NMC_MtSetPtpPara:dec����С�ڵ���0
#define RTN_MC_SetPtpPrm_SMTH						1079	// NMC_MtSetPtpPara:smoothCoef����С��0
#define RTN_MC_GetPtpPrm_HANDLE						1080	// NMC_MtGetPtpPara:axisHandle����
#define RTN_MC_SetJogPrm_HANDLE						1081	// NMC_MtSetJogPara:axisHandle����
#define RTN_MC_SetJogPrm_ACC						1082	// NMC_MtSetJogPara:acc����С�ڵ���0
#define RTN_MC_SetJogPrm_DEC						1083	// NMC_MtSetJogPara:dec����С�ڵ���0
#define RTN_MC_SetJogPrm_SMTH						1084	// NMC_MtSetJogPara:smoothCoef����С��0
#define RTN_MC_GetJogPrm_HANDLE						1085	// NMC_MtGetJogPara:axisHandle����
#define RTN_MC_SetVel_HANDLE						1086	// NMC_MtSetVel:axisHandle����
#define RTN_MC_SetVel_VEL							1087	// NMC_MtSetVel:vel��Χ����ȷ,����PTP��0,4500),����JOG(-4500,4500)
#define RTN_MC_SetVel_VEL2							1088	// NMC_MtSetVel:vel��Χ����ȷ,����PTP��0,4500),����JOG(-4500,4500)
#define RTN_MC_GetVel_HANDLE						1089	// NMC_MtGetVel:axisHandle����
#define RTN_MC_SetPtpTgtPos_HANDLE					1090	// NMC_MtSetPtpTgtPos:axisHandle����
#define RTN_MC_SetPtpTgtPos_POS						1091	// NMC_MtSetPtpTgtPos:pos��Χ����
#define RTN_MC_GetPtpTgtPos_HANDLE					1092	// NMC_MtGetPtpTgtPos:axisHandle����
#define RTN_MC_UPDATE_HANDLE						1093	// NMC_MtUpdate:axisHandle����
#define RTN_MC_STOP_HANDLE							1094	// NMC_MtStop:axisHandle����
#define RTN_MC_ESTOP_HANDLE							1095	// NMC_MtEstp:axisHandle����
#define RTN_MC_GetPrfVel_HANDLE						1096	// NMC_MtGetPrfVel:axisHandle����
#define RTN_MC_ZeroPos_HANDLE						1097	// NMC_MtZeroPos:axisHandle����
#define RTN_MC_ZeroPos_MOVE							1098	// NMC_MtZeroPos:�����˶�������ִ�иò���

#define RTN_MC_CrdCfg_HANDLE						1099	// NMC_CrdConfig:crdHandle����
#define RTN_MC_CrdCfg_DISABLE						1100	// NMC_CrdConfig:crd�޷�ʹ��
#define RTN_MC_CrdCfg_AXIS							1101	// NMC_CrdConfig:��������Ŀ����
#define RTN_MC_CrdCfg_AXIS_INDEX					1102	// NMC_CrdConfig:��������Ŵ���
#define RTN_MC_CrdCfg_BUSY							1103	// NMC_CrdConfig:����ϵ�����˶�
#define RTN_MC_GetCrdCfg_HANDLE						1104	// NMC_CrdGetConfig:crdHandle����
#define RTN_MC_CrdDel_HANDLE						1105	// NMC_CrdDelete:crdHandle����
#define RTN_MC_CrdDel_BUSY							1106	// NMC_CrdDelete:����ϵ�����˶�,����ִ�иò���
#define RTN_MC_CrdSetPrm_HANDLE						1107	// NMC_CrdSetPara:crdHandle����
#define RTN_MC_CrdSetPrm_EN							1108	// NMC_CrdSetPara:����ϵδ����
#define RTN_MC_CrdSetPrm_ACC						1109	// NMC_CrdSetPara:synAccMax��Χ����ȷ��(0,max]
#define RTN_MC_CrdSetPrm_VEL						1110	// NMC_CrdSetPara:synVelMax��Χ����ȷ��(0,max]
#define RTN_MC_CrdGetPrm_HANDLE						1111	// NMC_CrdGetPara:crdHandle����
#define RTN_MC_CrdGetPrm_EN							1112	// NMC_CrdGetPara:����ϵδ����
#define RTN_MC_CrdSetExtPrm_HANDLE					1113	// NMC_CrdSetExtPara:crdHandle����
#define RTN_MC_CrdSetExtPrm_EN						1114	// NMC_CrdSetExtPara:����ϵδ����
#define RTN_MC_CrdSetExtPrm_T						1115	// NMC_CrdSetExtPara:T��Χ����ȷ��(0,max]
#define RTN_MC_CrdSetExtPrm_VEL						1116	// NMC_CrdSetExtPara:startVel��Χ����ȷ��[0,max]
#define RTN_MC_CrdSetExtPrm_EDEC					1117	// NMC_CrdSetExtPara:abruptDec��Χ����ȷ��(0,max]
#define RTN_MC_CrdSetExtPrm_SDEC					1118	// NMC_CrdSetExtPara:smoothDec��Χ����ȷ��(0,max]
#define RTN_MC_CrdGetExtPrm_HANDLE					1119	// NMC_CrdGetExtPara:crdHandle����
#define RTN_MC_CrdGetExtPrm_EN						1120	// NMC_CrdGetExtPara:����ϵδ����
#define RTN_MC_StartMtn_HANDLE						1121	// NMC_CrdStartMtn:crdHandle����
#define RTN_MC_StartMtn_EN							1122	// NMC_CrdStartMtn:����ϵδ���û��������˶�
#define RTN_MC_StopMtn_HANDLE						1123	// NMC_CrdStopMtn:crdHandle����
#define RTN_MC_StopMtn_EN							1124	// NMC_CrdStopMtn:����ϵδ����
#define RTN_MC_EStopMtn_HANDLE						1125	// NMC_CrdEstopMtn:crdHandle����
#define RTN_MC_EStopMtn_EN							1126	// NMC_CrdEstopMtn:����ϵδ����
#define RTN_MC_GetCrdSts_HANDLE						1127	// NMC_CrdGetSts:crdHandle����
#define RTN_MC_GetCrdSts_EN							1128	// NMC_CrdGetSts:����ϵδ����
#define RTN_MC_GetCrdPos_HANDLE						1129	// NMC_CrdGetPrfPos:crdHandle����
#define RTN_MC_GetCrdPos_EN							1130	// NMC_CrdGetPrfPos:����ϵδ����
#define RTN_MC_GetCrdPos_COUNT						1131	// NMC_CrdGetPrfPos:cnts��Χ����ȷ
#define RTN_MC_GetCrdVel_HANDLE						1132	// NMC_CrdGetVel:crdHandle����
#define RTN_MC_GetCrdVel_EN							1133	// NMC_CrdGetVel:����ϵδ����
#define RTN_MC_SetOvrd_HANDLE						1134	// NMC_CrdSetOverRide:crdHandle����
#define RTN_MC_SetOvrd_EN							1135	// NMC_CrdSetOverRide:����ϵδ����
#define RTN_MC_SetOvrd_OVERIDE						1136	// NMC_CrdSetOverRide:overRide��Χ����
#define RTN_MC_GetOvrd_HANDLE						1137	// NMC_CrdGetOverRide:crdHandle����
#define RTN_MC_GetOvrd_EN							1138	// NMC_CrdGetOverRide:����ϵδ����
#define RTN_MC_GetBufFree_HANDLE					1139	// NMC_CrdBufGetFree:crdHandle����
#define RTN_MC_GetBufFree_EN						1140	// NMC_CrdBufGetFree:����ϵδ����
#define RTN_MC_GetBufUsed_HANDLE					1141	// NMC_CrdBufGetUsed:crdHandle����
#define RTN_MC_GetBufUsed_EN						1142	// NMC_CrdBufGetUsed:����ϵδ����
#define RTN_MC_CrdBufClr_HANDLE						1143	// NMC_CrdBufClr:crdHandle����
#define RTN_MC_CrdBufClr_EN							1144	// NMC_CrdBufClr:����ϵδ����
#define RTN_MC_GetSegNo_HANDLE						1145	// NMC_CrdGetUserSegNo:crdHandle����
#define RTN_MC_GetSegNo_EN							1146	// NMC_CrdGetUserSegNo:����ϵδ����
#define RTN_MC_GetBufAllCnt_HANDLE					1147	// NMC_CrdGetBufAllCmdCnt:crdHandle����
#define RTN_MC_GetBufAllCnt_EN						1148	// NMC_CrdGetBufAllCmdCnt:����ϵδ����
#define RTN_MC_EndMtn_HANDLE						1149	// NMC_CrdEndMtn:crdHandle����
#define RTN_MC_EndMtn_EN							1150	// NMC_CrdEndMtn:����ϵδ����
#define RTN_MC_GetCrdEncPos_HANDLE					1151	// NMC_CrdGetEncPos:crdHandle����
#define RTN_MC_GetCrdEncPos_EN						1152	// NMC_CrdGetEncPos:����ϵδ����
#define RTN_MC_GetCrdEncPos_COUNT					1153	// NMC_CrdGetEncPos:count��Χ����
#define RTN_MC_CrdClrErr_HANDLE						1154	// NMC_CrdClrError:crdHandle����
#define RTN_MC_CrdClrErr_EN							1155	// NMC_CrdClrError:����ϵδ����
#define RTN_MC_CrdSetVFolw_HANDLE					1156	// NMC_CrdSetValueFollow:crdHandle����
#define RTN_MC_CrdSetVFolw_EN						1157	// NMC_CrdSetValueFollow:����ϵδ����
#define RTN_MC_CrdLineXYZ_HANDLE					1158	// NMC_CrdLineXYZ:crdHandle����
#define RTN_MC_CrdLineXYZ_EN						1159	// NMC_CrdLineXYZ:����ϵδ����
#define RTN_MC_CrdLineXYZ_VEL						1160	// NMC_CrdLineXYZ:Vel��Χ����ȷ
#define RTN_MC_CrdLineXYZ_ACC						1161	// NMC_CrdLineXYZ:synAcc��Χ����ȷ
#define RTN_MC_CrdArcR_HANDLE						1162	// NMC_CrdArcRadius:crdHandle����
#define RTN_MC_CrdArcR_EN							1163	// NMC_CrdArcRadius:����ϵδ����
#define RTN_MC_CrdArcR_VEL							1164	// NMC_CrdArcRadius:Vel��Χ����ȷ
#define RTN_MC_CrdArcR_ACC							1165	// NMC_CrdArcRadius:synAcc��Χ����ȷ
#define RTN_MC_CrdArcC_HANDLE						1166	// NMC_CrdArcCenter:crdHandle����
#define RTN_MC_CrdArcC_EN							1167	// NMC_CrdArcCenter:����ϵδ����
#define RTN_MC_CrdArcC_VEL							1168	// NMC_CrdArcCenter:Vel��Χ����ȷ
#define RTN_MC_CrdArcC_ACC							1169	// NMC_CrdArcCenter:synAcc��Χ����ȷ
#define RTN_MC_CrdArcP_HANDLE						1170	// NMC_CrdArcPPP:crdHandle����
#define RTN_MC_CrdArcP_EN							1171	// NMC_CrdArcPPP:����ϵδ����
#define RTN_MC_CrdArcP_VEL							1172	// NMC_CrdArcPPP:Vel��Χ����ȷ
#define RTN_MC_CrdArcP_ACC							1173	// NMC_CrdArcPPP:synAcc��Χ����ȷ
#define RTN_MC_CrdHelixC_HANDLE						1174	// NMC_CrdHelixCenter:crdHandle����
#define RTN_MC_CrdHelixC_EN							1175	// NMC_CrdHelixCenter:����ϵδ����
#define RTN_MC_CrdHelixC_VEL						1176	// NMC_CrdHelixCenter:Vel��Χ����ȷ
#define RTN_MC_CrdHelixC_ACC						1177	// NMC_CrdHelixCenter:synAcc��Χ����ȷ
#define RTN_MC_CrdHelixC_ROUND						1178	// NMC_CrdHelixCenter:rounds��Χ����ȷ
#define RTN_MC_CrdBufDo_HANDLE						1179	// NMC_CrdBufDo:crdHandle����
#define RTN_MC_CrdBufDo_EN							1180	// NMC_CrdBufDo:����ϵδ����
#define RTN_MC_CrdBufDo_GOURP						1181	// NMC_CrdBufDo:group��Χ����ȷ
#define RTN_MC_CrdBufDo_OPBITS						1182	// NMC_CrdBufDo:opbits��Χ����ȷ
#define RTN_MC_CrdBufOut_HANDLE						1183	// NMC_CrdBufOut:crdHandle����
#define RTN_MC_CrdBufOut_EN							1184	// NMC_CrdBufOut:����ϵδ����
#define RTN_MC_CrdBufOut_CH							1185	// NMC_CrdBufOut:ch��Χ����ȷ
#define RTN_MC_CrdBufOut_GROUP						1186	// NMC_CrdBufOut:group��Χ����ȷ
#define RTN_MC_CrdBufDelay_HANDLE					1187	// NMC_CrdBufDelay:crdHandle����
#define RTN_MC_CrdBufDelay_EN						1188	// NMC_CrdBufDelay:����ϵδ����
#define RTN_MC_CrdBufDelay_SCALE					1189	// NMC_CrdBufDelay:ch��Χ����ȷ
#define RTN_MC_CrdBufDelay_COUNT					1190	// NMC_CrdBufDelay:group��Χ����ȷ
#define RTN_MC_CrdBufDi_HANDLE						1191	// NMC_CrdBufWaitDI:crdHandle����
#define RTN_MC_CrdBufDi_EN							1192	// NMC_CrdBufWaitDI:����ϵδ����
#define RTN_MC_CrdBufDi_INDEX						1193	// NMC_CrdBufWaitDI:index��Χ����ȷ
#define RTN_MC_CrdBufDi_COUNT						1194	// NMC_CrdBufWaitDI:waitTimeInMs��Χ����ȷ
#define RTN_MC_CrdBufAx_HANDLE						1195	// NMC_CrdBufAxMove:crdHandle����
#define RTN_MC_CrdBufAx_EN							1196	// NMC_CrdBufAxMove:����ϵδ����
#define RTN_MC_CrdBufAx_AXIS						1197	// NMC_CrdBufAxMove:axisNum��Χ����ȷ
#define RTN_MC_BufSetPtpMovePara_HANDLE				1198	// NMC_CrdBufSetPtpMovePara:crdHandle����
#define RTN_MC_BufSetPtpMovePara_EN					1199	// NMC_CrdBufSetPtpMovePara:����ϵδ����
#define RTN_MC_BufSetPtpMovePara_AXIS				1200	// NMC_CrdBufSetPtpMovePara:axis��Χ����ȷ
#define RTN_MC_BufSetPtpMovePara_VEL				1201	// NMC_CrdBufSetPtpMovePara:vel��Χ����ȷ
#define RTN_MC_BufSetPtpMovePara_ACC				1202	// NMC_CrdBufSetPtpMovePara:acc��Χ����ȷ
#define RTN_MC_BufSetPtpMovePara_SMTH				1203	// NMC_CrdBufSetPtpMovePara:smooth��Χ����ȷ
#define RTN_MC_CrdBufFollow_HANDLE					1204	// NMC_CrdBufWaitDI:crdHandle����
#define RTN_MC_BufPushData_EN						1205	// NMC_CrdPushData:crdHandle����
#define RTN_MC_BufPushData_HANDLE					1206	// NMC_CrdPushData:����ϵδ����

#define RTN_MC_INN_GetCenter_OVER					1207	// �岹ָ��Բ����������//����Բ�������Ƿ����
#define RTN_MC_INN_GetRad_OVER						1208	// �岹ָ��Բ����������//����Բ�������Ƿ����
#define RTN_MC_INN_GetCircDist_NULL					1209	// �岹ָ��Բ����������//����Բ�������Ƿ����
#define RTN_MC_INN_ARC_ONLYXY						1210	// Ŀǰֻ֧��XYƽ���Բ���岹
#define RTN_MC_INN_ARC_ONLYXY2						1211	// Ŀǰֻ֧��XYƽ���Բ���岹
#define RTN_MC_INN_ARC_ENDP							1212	// Բ���յ㲻����������߹�С
#define RTN_MC_INN_ARC_R_CIRCLE						1213	// �뾶����������֧��������Բ
#define RTN_MC_INN_ARC_R_CENTER						1214	// Բ��λ�ò�����
#define RTN_MC_INN_ARC_PPP_SAME						1215	// 3���غ�
#define RTN_MC_INN_ARC_PPP_LINE						1216	// 3�㹲��
#define RTN_MC_INN_HELIX_NULL						1217	// ����������Ϊ��
#define RTN_MC_INN_HELIX_ENDP						1218	// �����������յ㲻����������߹�С
#define RTN_MC_INN_HELIX_CIRCLE						1219	// �����߲���������Բ
#define RTN_MC_INN_HELIX_CENTER						1220	// ������Բ��λ�ò�����
#define RTN_MC_INN_HELIX_POS						1221	// �����������յ㲻����
#define RTN_MC_INN_HELIX_LEN						1222	// �����߳��Ȳ�����
#define RTN_MC_INN_DOWNDATA_NULL					1223	// ��������Ϊ��
#define RTN_MC_INN_DA_CH							1224	// DACͨ����Χ����ȷ
#define RTN_MC_INN_DOWNLINE_NULL					1225	// ��������Ϊ��
#define RTN_MC_INN_DOWNLINE_POS						1226	// ��������λ�ò�����������߹�С
#define RTN_MC_INN_ENDVEL_ZERO						1227	// ������յ��ٶ�С��0
#define RTN_MC_INN_VEL_ZERO							1228	// �����Ŀ���ٶ�С��0
#define RTN_MC_INN_ACC_ZERO							1229	// �����Ŀ���ٶ�С��0
#define RTN_MC_INN_DOWNARC_NULL						1230	// ��������Ϊ��
#define RTN_MC_INN_ARC_Z							1231	// Z�������λ�ƣ�Ŀǰ֧��XYƽ��
#define RTN_MC_INN_C_ENDPOS							1232	// �յ�λ�ò�����������߹�С
#define RTN_MC_INN_CD_CIRCLE						1233	// Բ�����أ��뾶����������������Բ
#define RTN_MC_INN_CD_CENTER						1234	// Բ�����أ�Բ�����겻����
#define RTN_MC_INN_CD_PPP_S							1235	// Բ�����أ������غ�
#define RTN_MC_INN_CD_PPP_L							1236	// Բ�����أ����㹲��
#define RTN_MC_INN_HELIX_D_NULL						1237	// ����������Ϊ��
#define RTN_MC_INN_HELIX_D_ENDP						1238	// �����������յ㲻����������߹�С
#define RTN_MC_INN_HELIX_D_CIRCLE					1239	// �����߲���������Բ
#define RTN_MC_INN_HELIX_D_CENTER					1240	// ������Բ��λ�ò�����
#define RTN_MC_INN_HELIX_D_POS						1241	// �����������յ㲻����
#define RTN_MC_INN_HELIX_D_LEN						1242	// �����߳��ȷ�Χ����ȷ
#define RTN_MC_INN_HELIX_D_VELEND					1243	// �������յ��ٶȷ�Χ����ȷ
#define RTN_MC_INN_HELIX_D_VEL						1244	// �������ٶȷ�Χ����ȷ
#define RTN_MC_INN_HELIX_D_ACC						1245	// �����߼��ٶȷ�Χ����ȷ
#define RTN_MC_INN_CRV_TYPE							1246	// ָ�������쳣
#define RTN_MC_INN_DS_NULL							1247	// �²��·�����Ϊ��
#define RTN_MC_INN_DC_VEL							1248	// Բ�������ٶȳ�����Χ
#define RTN_MC_INN_DC_ENDVEL						1249	// Բ�������ٶȳ�����Χ
#define RTN_MC_INN_DC_ACC							1250	// Բ�������ٶȳ�����Χ
#define RTN_MC_INN_DC_ENDPOS						1251	// Բ�������յ㲻����������߹�С
#define RTN_MC_CRD_NO_SPACE							1252	// �岹������������
#define RTN_MC_MT_SetAxisFilter_Err					1253	// �������ٶ��˲���������
#define RTN_MC_AX_ON_ALARM				1254	// axis on ����������:�ŷ�����
#define RTN_MC_AX_ON_POSERR				1255	// axis on ����������:λ��Խ��
#define RTN_MC_EnableCrdSdram			1256	// ʹ��crd��sdram���ò�������
#define RTN_MC_Sdram_no_Space			1257	// SDRAM���㹻�ռ�
#define RTN_MC_Push_Sdram_err			1258	// push���ݵ�SDRAM����
#define RTN_MC_AX_HOME_PARA				1259	// ������ʱ����������ȷ
#define RTN_MC_CrdGetConfig_EN			1260	// NMC_CrdGetConfig��ȡ����ʱ��δʹ�ܲ岹ģ��
#define RTN_MC_ClrCrdSts_HANDLE			1261	// NMC_ClrCrdSts�������

#define RTN_MC_SetHomePara_HANDLE		1262	// NMC_MtSetHomePara�������
#define RTN_MC_GetHomeSts_HANDLE		1263	// NMC_MtGetHomeSts�������
#define RTN_MC_HomeStart_HANDLE			1264	// NMC_MtHome�������
#define RTN_MC_HomeStop_HANDLE			1265	// NMC_MtHomeStop�������
#define RTN_MC_GetHomeError_HANDLE		1266	// NMC_MtGetHomeError�������
#define RTN_MC_GetHomePara_HANDLE		1267	// NMC_MtGetHomePara�������
#define RTN_MC_TryHome_HANDLE			1268	// NMC_MtTryHome�������
#define RTN_MC_HomeStartInNegLmt_HANDLE	1269	// NMC_MtHome����NMC_MtTryHome����ʱ�����������λ���������Ҹ�����λ����δ����������
#define RTN_MC_HomeStartInPosLmt_HANDLE	1270	// NMC_MtHome����NMC_MtTryHome����ʱ�����������λ����������������λ����δ����������
#define RTN_MC_HomeStartInAlarm_HANDLE	1271	// NMC_MtHome����NMC_MtTryHome����ʱ���������
#define RTN_MC_HomeStartInMoving_HANDLE	1272	// NMC_MtHome����NMC_MtTryHome����ʱ����������˶�
#define RTN_MC_GetCrdAxisPos_HANDLE		1273	// NMC_CrdGetAxisPos�������
#define RTN_MC_GetCrdAxisPos_EN			1274	// NMC_CrdGetAxisPos����ϵδ��ʼ��
#define RTN_MC_GetCrdAxisPos_COUNT		1275	// NMC_CrdGetAxisPos cnts��������
#define RTN_MC_CrdBufClr_CrdBusy		1276	// NMC_CrdBufClr Crd busy
#define RTN_MC_GetCrdStsPack3_HANDLE	1277	// NMC_CrdGetStsPack3�������
#define RTN_MC_GetCrdStsPack3_EN		1278	// NMC_CrdGetStsPack3����ϵδ��ʼ��
#define RTN_MC_CrdSetExtPara_CrdBusy	1279	// NMC_CrdSetExtPara:��ǰ����ϵ�����˶�
#define RTN_MC_CrdSetPara_CrdBusy		1280	// NMC_CrdSetPara:��ǰ����ϵ�����˶�
#define RTN_MC_CrdConfig_CrdBusy		1281	// NMC_CrdConfig:��ǰ����ϵ�����˶�
#define RTN_MC_CrdStartMtn_Mode			1282	// NMC_CrdStartMtn:����ʱ�����ģʽ����
#define RTN_MC_SetPrfMode_Busy			1283	// NMC_SetPrfMode:��Ҫ�л�ģʽ���ᴦ��busy״̬
#define RTN_MC_MtUpdate_error			1284	// NMC_MtUpdate����ģʽ���󣬵�ǰ��ģʽ���ڸ�������Χ
#define RTN_MC_SetPrfCoe_HANDLE			1285	// NMC_MtSetPrfCoe:�������
#define RTN_MC_GetPrfCoe_HANDLE			1286	// NMC_MtGetPrfCoe:�������
#define RTN_MC_SetPrfCoe_Range			1287	// NMC_MtSetPrfCoe:ϵ����Χ����ȷ// inCoe��Ч��Χ��(0,1]
#define RTN_MC_SetPrfCoe_Busy			1288	// NMC_MtSetPrfCoe:��æ����������
#define RTN_MC_SetPrfCoe_PosNotZero		1289	// NMC_MtSetPrfCoe:��ǰλ�ò�Ϊ0����������// �Ȼ�ԭ�㣬���λ�ã�Ȼ��������
#define RTN_MC_GetIOModuleSts_Unsupport	1290	// NMC_GetIOModuleSts:IO��չģ�鲻֧��
#define RTN_MC_SetIOModuleEn_Param		1291	// NMC_SetIOModuleEn:��������chDevId��Χ����ȷ
#define RTN_MC_SetIOModuleEn_Unsupport	1292	// NMC_SetIOModuleEn:IO��չģ�鲻֧��
#define RTN_MC_GetDI_En					1293	// NMC_GetDI:��ӦIOģ��δ����
#define RTN_MC_BackSramWrite_out_rang	1294	// NMC_BackSramWrite������ַԽ��
#define RTN_MC_BackSramRead_out_rang	1295	// NMC_BackSramRead������ַԽ��
#define RTN_MC_BackSramWrite_Len		1296	// NMC_BackSramWrite:дsram����д�볤�Ȳ���ȷ
#define RTN_MC_BackSramRead_Len			1297	// NMC_BackSramRead:��sram���󣬶�ȡ���Ȳ���ȷ
#define RTN_MC_CrdLineXYZPack_Count		1298	// NMC_CrdLineXYZPack:count��Χ����ȷ[1,5]
#define RTN_MC_CrdLineXYZPack_Handle	1299	// NMC_CrdLineXYZPack:�������
#define RTN_MC_CrdLineXYZPack_En		1300	// NMC_CrdLineXYZPack:����ϵδ��ʼ��
#define RTN_MC_CrdLineXYZPack_NoSpace	1301	// NMC_CrdLineXYZPack:û���㹻�Ŀռ� // ���ռ��Ƿ��㹻
#define RTN_MC_CrdSetArcSecPara_Handle	1302	// NMC_CrdSetArcSecPara:�������
#define RTN_MC_CrdSetArcSecPara_En		1303	// NMC_CrdSetArcSecPara:����ϵδ��ʼ��
#define RTN_MC_CrdSetArcSecPara_R_Rise	1304	// NMC_CrdSetArcSecPara:���뾶���rֵ�����ϣ��������
#define RTN_MC_CrdSetArcSecPara_Err		1305	// NMC_CrdSetArcSecPara:���뾶���errֵ����С�ڵ���0
#define RTN_MC_CrdSetArcSecPara_Diff	1306	// NMC_CrdSetArcSecPara:maxArcDiff��Χ����ȷ������С��1
#define RTN_MC_CrdSetArcSecPara_Sec		1307	// NMC_CrdSetArcSecPara:minSectionLen����С��0
#define RTN_MC_CrdGetArcSecPara_Handle	1308	// NMC_CrdGetArcSecPara:�������
#define RTN_MC_CrdGetArcSecPara_En		1309	// NMC_CrdGetArcSecPara:����ϵδ��ʼ��
#define RTN_IO_GetDIBit_En				1310	// NMC_GetDIBit:��չģ��δʹ�� //���ȵ���NMC_SetIOModuleEnʹ����Ӧģ��
#define	RTN_IO_SetDoBit_En				1311	// NMC_SetDOBit:��չģ��δʹ�� //���ȵ���NMC_SetIOModuleEnʹ����Ӧģ��
#define	RTN_IO_SetDo_En					1312	// NMC_SetDO:��չģ��δʹ�� //���ȵ���NMC_SetIOModuleEnʹ����Ӧģ��
#define	RTN_IO_GetDo_En					1313	// NMC_GetDO:��չģ��δʹ�� //���ȵ���NMC_SetIOModuleEnʹ����Ӧģ��
#define RTN_MC_GetCollectDataAddr_BUSY 	1314 	// NMC_GetCollectDataAddr:�������ݲɼ�
#define RTN_MC_GetCollectDataAddr_index 1315 	// NMC_GetCollectDataAddr:index ������Χ
#define RTN_MC_ConfigCollect_BUSY 		1316 	// NMC_ConfigCollect:���ڲɼ����ݣ�����������
#define RTN_MC_StartCollect_ErrFlag 	1317 	// NMC_StartCollect:���ڲɼ�����
#define RTN_MC_GetCollectData_Err 		1318 	// NMC_GetCollectData:ȡ����ʧ��
#define	RTN_MC_ConfigCollect_count		1319 	// MC_ConfigCollect:count ������Χ
#define	RTN_MC_SetJogPara_Busy			1320 	// NMC_MtSetJogPara:æ
#define	RTN_MC_SetJogPara_Mode			1321 	// NMC_MtSetJogPara:��jogģʽ�²���������
#define	RTN_MC_SetPtpPara_Busy			1322 	// NMC_MtSetPtpPara:æ
#define	RTN_MC_SetPtpPara_Mode			1323 	// NMC_MtSetPtpPara:��PTPģʽ�²���������
#define	RTN_MC_SetAxisPos_Busy			1324 	// NMC_MtSetAxisPos:�Ǿ�ֹ״̬�½�ֹ����
#define RTN_IO_SetEncPos_INDEX			1325	// NMC_MtSetEncPos:encId��Χ����ȷ
#define RTN_MC_SetEncCoe_HANDLE			1326	// NMC_MtSetEncCoe:�������
#define RTN_MC_GetEncCoe_HANDLE			1327	// NMC_MtGetEncCoe:�������
#define RTN_MC_SetEncCoe_Range			1328	// NMC_MtSetEncCoe:ϵ����Χ����ȷ// inCoe��Ч��Χ��(0,1]
#define RTN_MC_SetEncCoe_Busy			1329	// NMC_MtSetEncCoe:��æ����������
#define RTN_MC_SetEncCoe_PosNotZero		1330	// NMC_MtSetEncCoe:��ǰλ�ò�Ϊ0����������// �Ȼ�ԭ�㣬���λ�ã�Ȼ��������
#define	RTN_MC_ConfigCollect_Interval	1331    // MC_ConfigCollect:interval ������Χ

#define RTN_MC_SetLaserPower_group 		1332	// NMC_SetLaserPower���ü�����������ų���Χ
#define RTN_MC_SetLaserPower_points		1334	// NMC_SetLaserPower���ü������������ڵ�������λ
#define RTN_MC_LaserOn_group					1335	//  NMC_LaserOn�򿪼������ų���Χ
#define RTN_MC_LaserOn_type						1336	// 	NMC_LaserOn�򿪼�������Ͳ���
#define RTN_MC_LaserOff_group					1337	//  NMC_LaserOff�رռ������ų���Χ
#define RTN_MC_LaserOff_type					1338 	//  NMC_LaserOff�رռ�������Ͳ���
#define RTN_MC_LaserConfig_laserType	1339	// NMC_LaserConfig���ü�������Ͳ���
#define RTN_MC_LaserConfig_val_err		1340	// NMC_LaserConfig���ü����optionֵ����
#define RTN_MC_DelGantryGroup_exe_err	1341	// NMC_DelGantryGroup:ִ�д���
#define RTN_MC_DelGantryGroup_axisHandle_err	1342	//NMC_DelGantryGroup:�������
#define RTN_MC_SetGantrySlave_have_Set	1343	// NMC_SetGantrySlave:���ô���
#define RTN_MC_SetGantryMaster_Busy		1344	// NMC_SetGantrySlave:�����˶�
#define RTN_MC_SetGantrySlave_HANDLE	1345	// NMC_SetGantrySlave:�������
#define RTN_MC_SetGantryMaster_HANDLE	1346	// NMC_SetGantryMaster:�������
#define RTN_MC_SetGantryMaster_have_master	1347	// NMC_SetGantryMaster:master����
#define RTN_MC_CrdLineXYZ_Len_Zero		1348	// NMC_CrdLineXYZ:ֱ�߲岹����Ϊ0
#define RTN_MC_CrdGotoBreak_VEL				1349	// CrdGotoBreak:�ٶ����ô���
#define RTN_MC_CrdGotoBreak_ACC				1350	// CrdGotoBreak:���ٶ����ô���
#define RTN_MC_CrdGotoBreak_axis_busy  1351	// CrdGotoBreak:�ضϵ�����æ
#define RTN_MC_CrdSetOffset_count			1352	// CrdSetOffset ���õ�ƫ�Ƹ�������
#define RTN_MC_CrdStartMtn_stPos_err	1353	// CrdStartMtn ����ʱ��λ���������㲻һ�£�������Ҫ�ص��ϵ㴦
#define RTN_MC_MtSetLmtCfg_Handle	1354	// NMC_MtSetLmtCfg:��λ���þ������
#define RTN_MC_MtSetAlarmCfg_Handle	1355	// NMC_MtSetAlarmCfg�������þ������
#define RTN_MC_CrdGotoBreak_En          1356            // NMC_CrdGotoBreakδ����
#define RTN_MC_CrdGotoBreak_Handle		1357            // NMC_CrdGotoBreak:crd�������
#define RTN_MC_CrdSetOffset_En          1358            // NMC_CrdSetOffsetδ����
#define RTN_MC_CrdSetOffset_Handle		1359            // NMC_CrdSetOffset:crd�������
#define RTN_MC_CrdSetOffset_Axis_Busy	1360            // NMC_CrdSetOffset:��������˶�
#define RTN_MC_CrdGotoBreak_NoData		1361			// NMC_CrdGotoBreak:�޶ϵ���Ϣ
#define RTN_MC_MtSetEncPos_Busy			1362			// NMC_MtSetEncPos:æ�������˶�
#define RTN_MC_SetGantrySlave_Busy		1363			// NMC_SetGantrySlave:æ
#define RTN_MC_SetGantrySlave_Pos		1364			// NMC_SetGantrySlave:�����ᵱǰλ�ó�?
#define RTN_MC_GantryGroup_Range		1365			// gantry gourp������Χ����ȷ����Ч��Χ[0,]
#define RTN_MC_SetGantrySlave_ErrLmt_Range 1367			// NMC_SetGantrySlave��gantryErrLmt�������0


#define RTN_MC_BufSHIOGateOn_HANDLE			500	// NMC_BufSHIOGateOn:�������
#define RTN_MC_BufSHIOGateOn_EN			501		//  NMC_BufSHIOGateOn:���ø�ָ��δ�����岹����ϵ
#define RTN_MC_BufSHIOGateOff_HANDLE			502	//  NMC_BufSHIOGateOff:�������
#define RTN_MC_BufSHIOGateOff_EN			503		//  NMC_BufSHIOGateOff:���ø�ָ��δ�����岹����ϵ
#define RTN_MC_LaserConfig_mode_err			504	//  NMC_LaserConfig:����ģʽ����û�и�ģʽ
#define RTN_MC_ConfigSHIOPara_isArray			505  //  NMC_ConfigHSIOPara:isArray��������
#define RTN_MC_ConfigSHIOPara_outMode			506	//  NMC_ConfigHSIOPara:outMode��������
#define RTN_MC_ConfigSHIOPara_posSrc			507	//  NMC_ConfigHSIOPara:posSrc��������
#define RTN_MC_ConfigSHIOPara_gateTime			508	//  NMC_ConfigHSIOPara:gateTime��������
#define RTN_MC_ConfigSHIOPara_delay			509	//  NMC_ConfigHSIOPara:delay����С��0
#define RTN_MC_ConfigSHIOPara_gateDistance			510	//  NMC_ConfigHSIOPara:gateDistance��������
#define RTN_MC_SHIOTriggerOn_triggerFreq			511	//  NMC_SHIOTriggerOn:triggerFreq��������
#define RTN_MC_SHIOTriggerOn_triggerWidth			512	//  NMC_SHIOTriggerOn:triggerWidth��������
#define RTN_MC_SetLaserMode_mode			513	//  NMC_SetLaserMode:����ģʽ����û�и�ģʽ
#define RTN_MC_ConfigSHIOPara_axisMask			514	//  NMC_SetLaserMode:����ģʽ����û�и�ģʽ
#define RTN_MC_SHIOChangeAxisMask_axisMask			515	//  NMC_SetLaserMode:����ģʽ����û�и�ģʽ
#define RTN_MC_MtClrError_Handle				516	//  NMC_MtClrStsByBits����NMC_MtClrError:�������
#define RTN_MC_MtClrCaptSts_Handle				517	//  NMC_MtClrCaptSts:�������
#define RTN_MC_ExitHandWheel_HANDLE				518	//  NMC_ExitHandWheel:�����
#define RTN_MC_SetHandWheel_HANDLE				519	//  NMC_SetHandWheel:�����
#define RTN_MC_SetHandWheel_Ratio				520	//  NMC_SetHandWheel:ratio ��Χ����ȷ
#define RTN_MC_SetHandWheel_Acc					521	//  NMC_SetHandWheel:acc ��Χ����ȷ
#define RTN_MC_SetHandWheel_Vel					522	//  NMC_SetHandWheel:vel ��Χ����ȷ
#define RTN_MC_SetHandWheel_Busy				523	//  NMC_SetHandWheel:busy
#define RTN_MC_ExitHandWheel_Busy				524	//  NMC_ExitHandWheel:busy
#define RTN_MC_SetHandWheel_isHandWheel_Mode 	525	//  NMC_SetHandWheel:�Ѿ�������ģʽ
#define RTN_MC_SelectHandWheelInput_Index 		526	//  NMC_SelectHandWheelInput:ͨ����Χ����ȷ��[0,9]
#define RTN_MC_ExitHandWheel_Mode				527	//  NMC_ExitHandWheel:busy
#define RTN_MC_SetHandWheelRatio_Ratio			528	//  NMC_SetHandWheelRatio:ratio����Ϊ0
#define RTN_MC_SetWatchDog_Mode	                529	//  NMC_SetWatchDog:stopMode��������ȷ
#define RTN_MC_SetWatchDog_DoGroup              530	//  NMC_SetWatchDog:groupID��������ȷ
#define RTN_MC_MtPtSetStatic_HANDLE				531	//  NMC_MtPtSetStatic:���
#define RTN_MC_MtPtGetStatic_HANDLE				532 //  NMC_MtPtGetStatic:���
#define RTN_NMC_MtPtSetStatic_no_pt_mode		533 //  NMC_MtPtSetStatic:��PTģʽ
#define RTN_NMC_MtPtSetStatic_onOff				534 //  NMC_MtPtSetStatic:onOff��������ȷ[0,1]
#define RTN_MC_MtPtGetSpace_HANDLE				535 //  NMC_MtPtGetSpace:��� 
#define RTN_NMC_MtPtGetSpace_no_pt_mode			536 //  NMC_MtPtGetSpace:��PTģʽ
#define RTN_MC_MtPtPush_HANDLE					537 //  NMC_MtPtPush:��� 
#define RTN_NMC_MtPtPush_no_pt_mode				538 //  NMC_MtPtPush:��PTģʽ 
#define RTN_NMC_MtPtPush_count					539 //  NMC_MtPtPush:count��������ȷ 
#define RTN_NMC_MtPtPush_pos					540 //  NMC_MtPtPush:λ�ò�������ȷ 
#define RTN_NMC_MtPtPush_time					541 //  NMC_MtPtPush:ʱ���������ȷ  
#define RTN_NMC_MtPtPush_type					542 //  NMC_MtPtPush:���Ͳ�������ȷ   
#define RTN_MC_MtPtBufClr_HANDLE				543 //  NMC_MtPtBufClr:���     
#define RTN_NMC_MtPtBufClr_no_pt_mode			544 //  NMC_MtPtBufClr:��PTģʽ
#define RTN_NMC_MtPtBufClr_busy					545 //  NMC_MtPtBufClr:æ        
#define RTN_MC_MtPtStartMtn_HANDLE				546 //  NMC_MtPtStartMtn:���         
#define RTN_NMC_MtPtStartMtn_syncAxCnts			547 //  NMC_MtPtStartMtn:axCnts��������ȷ
#define RTN_NMC_MtPtStartMtn_no_pt_mode			548 //  NMC_MtPtStartMtn:��PTģʽ 
#define  RTN_NMC_MtPtStartMtn_one_axis_isBusy  	549 //  NMC_MtPtStartMtn:�������˶�
#define  RTN_NMC_MtPtStartMtn_no_data			550 //  NMC_MtPtStartMtn:��PT����
#define RTN_MC_Password_Paser                   551	//  ϵͳ�����������
#define RTN_MC_Password_Format                  552	//  ϵͳ�����ʽ����
#define RTN_MC_Password_Verify                  553	//   ϵͳ������֤ʧ��
#define RTN_MC_Password_Deny             	    554	//   ϵͳ������֤����Ƶ��
#define RTN_MC_Password_Load             	    555	//   ϵͳ������֤:����
#define RTN_MC_Password_Save             	    556	//   ϵͳ������֤:����
#define RTN_MC_SetTime_TimeFormat               557	//  NMC_SetTime:ʱ���ʽ����ȷ
#define RTN_MC_SetTime_Save			            558	//  NMC_SetTime:����ϵͳʱ�����
#define RTN_MC_DacChanelInvalid			        559	//  dacͨ����Ч
#define RTN_MC_SetDacMode_ModeInvalid	        560	//  dacģʽ��Ч
#define RTN_MC_SetDacMode_Set			        561	//  dacģʽ���ô���
#define RTN_MC_SetDac_Value						562 //  dac�趨ֵ��Χ����ȷ
#define RTN_MC_SetDac_Set						563 //  dac�������
#define RTN_MC_GetAdc_Get						564 //  adc��ȡ����
#define RTN_MC_CrdLaserFollow_Handle			565 //  CrdLaserFollow:CrdHandle
#define RTN_MC_CrdLaserFollow_not_set_laserType 566 // CrdLaserFollow:��������δ����
#define RTN_MC_CrdLaserFollow_followType_err		567 // CrdLaserFollow������ϵ���������ٶ����Ͳ�������
#define RTN_MC_CrdEnableLaserFollow_Handle			568 // CrdEnableLaserFollow:CrdHandle
#define RTN_MC_CrdEnableLaserFollow_onOff				569 // CrdEnableLaserFollow��onOff��������
#define RTN_MC_AdcChanelInvalid					570	// adcͨ����Ч
#define RTN_MC_CrdBufOut_DacValue				571 // CrdBufOut:da�趨ֵ��Ч
#define RTN_MC_LaserSetParam_OnDelay				572 // NMC_LaserSetParam:onDelay��Χ����
#define RTN_MC_LaserSetParam_OffDelay				573 // NMC_LaserSetParam:offDelay��Χ����
#define RTN_MC_LaserSetParam_Ch					574 // NMC_LaserSetParam:ch��Χ����
#define RTN_MC_LaserGetParam_Ch							575	// NMC_LaserGetParam:ch��Χ����
#define RTN_MC_CrdBufLaserOnOff_Handle					576	// NMC_LaserGetOnOffDelay:ch��Χ����
#define RTN_MC_CrdBufLaserOnOff_En					    577	// NMC_LaserGetOnOffDelay:����ϵδʹ��
#define RTN_MC_CrdBufLaserOnOff_OnOff					578	// NMC_LaserGetOnOffDelay:onOff��Χ����
#define RTN_MC_CrdBufLaserOnOff_Ch					    579	// NMC_LaserGetOnOffDelay:ch��Χ����
#define RTN_MC_CrdBufLaserPower_Handle					580	// NMC_CrdBufLaserPower:handle����
#define RTN_MC_CrdBufLaserPower_En					    581	// NMC_CrdBufLaserPower:����ϵδʹ��
#define RTN_MC_CrdBufLaserPower_Power					582	// NMC_CrdBufLaserPower:power��Χ����
#define RTN_MC_CrdBufLaserPower_Ch					    583	// NMC_CrdBufLaserPower:ch��Χ����
#define RTN_MC_SetDac_CtrlMode						    584	// SetDac:DAC����ģʽ����
#define RTN_MC_LaserSetParam_LaserType				585 // LaserSetParam: ����ʱ����������δ����
#define RTN_MC_LaserSetMode_Ch				586 // NMC_LaserSetMode:ch��������ȷ
#define RTN_MC_LaserSetMode_Set				587 // NMC_LaserSetMode:����ģʽ
#define RTN_MC_LaserSetParam_StandbyPower		588 // NMC_LaserSetStandbyPower:ch��������ȷ
#define RTN_MC_LaserSetOutputType_Index		589 // NMC_LaserSetOutputType:index��������ȷ
#define RTN_MC_LaserSetOutputType_Set		590 // NMC_LaserSetOutputType:���ô���
#define RTN_MC_LaserSetOutputType_Ch				591 // NMC_LaserSetOutputType:ch��Χ����
#define RTN_MC_LaserTimeArrayOn_Ch				592 // NMC_LaserTimeArrayOn:ch��Χ����
#define RTN_MC_LaserTimeArrayOff_Ch				593 // NMC_LaserTimeArrayOff:ch��Χ����
#define RTN_MC_LaserSetPower_Ch	    594	// NMC_LaserSetPower:ch��Χ����
#define RTN_MC_LaserOnOff_Mode		595	// NMC_LaserOnOff:��ǰģʽ�²�֧��
#define RTN_MC_LaserOnOff_OnOff     596	// NMC_LaserOnOff:onOff������Χ����
#define RTN_MC_LaserOnOff_Ch		597 // NMC_LaserOnOff:ch������Χ����
#define RTN_MC_SHIOGateOnOff_Mode		598 // NMC_SHIOGateOn:mode����ȷ
#define RTN_MC_LaserConfig_laserType_occupied		599 // NMC_LaserConfig:���õ�laserType��ռ����
#define RTN_MC_LaserConfig_conflict_laserType		600 // NMC_LaserConfig:���õ�laserType�����г�ͻ
#define RTN_MC_SetLaserMode_conflict_mode				601 // NMC_SetLaserMode:���õ�ģʽ�г�ͻ
#define RTN_MC_CrdBufMotion_LookaheadDis				602 // Crd:lookaheadDis������Χ����
#define RTN_MC_SetLaserPower_Time					603 // NMC_LaserSetTimeArrayPower:ʱ�����ô���

#define RTN_MC_LinearCompSetParam_dimens	  	604 // NMC_LinearCompSetParam�����õ�ά����������
#define RTN_MC_LinearCompSetParam_axisMask		605 // NMC_LinearCompSetParam�����õ���ӳ�䲻��
#define RTN_MC_LinearCompSetParam_src			606 // NMC_LinearCompSetParam�����õıȽ�Դ��������
#define RTN_MC_LinearCompSetParam_cmpMode		607 // NMC_LinearCompSetParam�����õıȽ�Դ��������
#define RTN_MC_LinearCompSetParam_gateTime		608 // NMC_LinearCompSetParam�����õıȽ�����������Ȳ�������
#define RTN_MC_LinearCompSetParam_chn			609 // NMC_LinearCompSetParam�����õ����ͨ����������


#define RTN_MC_LinearCompInterval_count			610 // NMC_LinearCompInterval�����õıȽ�������������
#define RTN_MC_LinearCompInterval_section		611 // NMC_LinearCompInterval�����õıȽ�����ϸ�ֶ�������
#define RTN_MC_LinearCompInterval_cmpmode		612 // NMC_LinearCompInterval�����õıȽ����ݵıȽ�ģʽ����

#define RTN_MC_LinearCompOnOff_onOff			613	// NMC_LinearCompOnOff: onOff��������

#define RTN_MC_Comp2DimensSetParam_chnType			614	// NMC_Comp2DimensSetParam: chnType��������	
#define RTN_MC_Comp2DimensSetParam_dirNo				615	// NMC_Comp2DimensSetParam: dirNo��������	
#define RTN_MC_Comp2DimensSetParam_errZone			616	// NMC_Comp2DimensSetParam: errZone��������	
#define RTN_MC_Comp2DimensSetParam_gateTime			617	// NMC_Comp2DimensSetParam: gateTime��������	
#define RTN_MC_Comp2DimensSetParam_outputType		618	// NMC_Comp2DimensSetParam: outputType��������	
#define RTN_MC_Comp2DimensSetParam_outputchn		619	// NMC_Comp2DimensSetParam: outputchn��������	
#define RTN_MC_Comp2DimensSetParam_posSrc				620	// NMC_Comp2DimensSetParam: posSrc��������	
#define RTN_MC_Comp2DimensSetParam_stLevel			621	// NMC_Comp2DimensSetParam: stLevel��������	
#define RTN_MC_Comp2DimensSetData_count					622	// NMC_Comp2DimensSetData: count��������	
#define RTN_MC_Comp2DimensOnoff_onOff						623	// NMC_Comp2DimensOnoff: onOff��������	
#define RTN_MC_Comp2DimensSetData_push_data_failed 624 //NMC_Comp2DimensSetData:ѹ������ʧ�� 
#define RTN_MC_Comp2DimensSetParam_group				625	// NMC_Comp2DimensSetParam:group��������
#define RTN_MC_Comp2DimensGetParam_group				626 // NMC_Comp2DimensGetParam:group��������
#define RTN_MC_Comp2DimensSetData_group					627	// NMC_Comp2DimensSetData:group��������
#define RTN_MC_Comp2DimensOnoff_group						628	// NMC_Comp2DimensOnoff:group��������
#define RTN_MC_Comp2DimensStatus_group					629	// NMC_Comp2DimensStatus:group��������
#define RTN_MC_SetDiFilter_Range					630	// NMC_SetDIFilter:��������

#define RTN_MC_CrdEnableMatrixCalc_enable											630	// NMC_CrdEnableMatrixCalc:enable��������
#define RTN_MC_CrdEnableMatrixCalc_rotAxisNo									631	// NMC_CrdEnableMatrixCalc:rotAxisNo��������
#define RTN_MC_CrdEnableMatrixCalc_angleRadEqual							632	// NMC_CrdEnableMatrixCalc:angleRadEqual��������
#define RTN_MC_LinearCompSetData_count			633 // NMC_LinearCompSetData�����õıȽ�������������
#define RTN_MC_LinearCompSetData_section		634 // NMC_LinearCompSetData�����õıȽ�����ϸ�ֶ�������
#define RTN_MC_LinearCompSetData_cmpmode		635 // NMC_LinearCompSetData�����õıȽ����ݵıȽ�ģʽ����
#define RTN_MC_LaserSetParam_Busy				636 // NMC_LaserSetParam:���������²��������ò���


#define RTN_MC_CrdEnableMatrixCalc_HANDLE 	637   // NMC_CrdEnableMatrixCalc:�������
#define RTN_MC_CrdSetSafePara_HANDLE 				638   // NMC_CrdSetSafePara:�������
#define RTN_MC_CrdEnableMatrixCalc_En 			639   // NMC_CrdEnableMatrixCalc:����ϵδʹ��

#define RTN_MC_CrdSetPolarType_En						640   // NMC_CrdSetPolarType:����ϵ������ʹ��
#define RTN_MC_CrdSetPolarType_HANDLE				641   // NMC_CrdSetPolarType:�������
#define RTN_MC_CrdSetPolarType_rotAxNo			642   // NMC_CrdSetPolarType:���������ת��ų���Χ
#define RTN_MC_CrdSetPolarType_transAxNo		643   // NMC_CrdSetPolarType:�������ƽ����ų���Χ
#define RTN_MC_CrdSetPolarType_rotAxNo_transAxNo_equal		644   // NMC_CrdSetPolarType:��������ת���ƽ����ѡ���������ͬ
#define RTN_MC_CrdSetPolarType_rotEquiv			645   // NMC_CrdSetPolarType:��������ת�ᵱ������

#define RTN_MC_CrdRunToPolarPos_HANDLE			646   // NMC_CrdRunToPolarPos:�������

#define RTN_MC_CrdDeletePolar_HANDLE				647   // NMC_CrdDeletePolar:�������
#define RTN_CrdDeletePolar_En								648   // NMC_CrdDeletePolar:����ϵδ�ر�
#define RTN_MC_CrdRunToPolarPos_En					649		// NMC_CrdRunToPolarPos:����ϵ������ʹ��
#define RTN_MC_CrdRunToPolarPos_not_polar		650		// NMC_CrdRunToPolarPos:����ϵδ���óɼ�����

#define RTN_MC_CrdRunToPolarTheta_HANDLE		651
#define RTN_MC_CrdRunToPolarTheta_En				652
#define RTN_MC_CrdRunToPolarTheta_not_polar			653
#define RTN_MC_CrdRunToPolarTheta_clrRoundFlag 		654
#define RTN_MC_LaserSetTimeArrayPara_Ch 			655	//NMC_LaserSetTimeArrayPara��������ch
#define RTN_MC_LaserSetTimeArrayPara_OutType 		656	//NMC_LaserSetTimeArrayPara��������ouputType
#define RTN_MC_LaserSetTimeArrayPara_OutCh 		657	//NMC_LaserSetTimeArrayPara��������outputCh
#define RTN_MC_LaserSetTimeArrayPara_PWMWidth 		658	//NMC_LaserSetTimeArrayPara��������pwmWidth
#define RTN_MC_LaserSetTimeArrayPara_Period		659	//NMC_LaserSetTimeArrayPara��������pwmPeriod
#define RTN_MC_LaserTimeArrayOn_group				660	//NMC_LaserTimeArrayExe��������group
#define RTN_MC_CrdBufLaserTimeArrayExe_En			661 //NMC_CrdBufLaserTimeArrayExe:crd not enable
#define RTN_MC_CrdBufLaserTimeArrayExe_Ch			662	//NMC_CrdBufLaserTimeArrayExe��������ch
#define RTN_MC_CrdBufLaserTimeArrayExe_Group		663	//NMC_CrdBufLaserTimeArrayExe��������gourp
#define RTN_MC_CrdBufWaitEncInPosition_En		664	//NMC_CrdBufWaitEncInPosition����ϵδ����
#define RTN_MC_CrdBufWaitEncInPosition_AxisMask		665	//NMC_CrdBufWaitEncInPosition��������axisMask
#define RTN_MC_CrdBufWaitEncInPosition_overTime		666	//NMC_CrdBufWaitEncInPosition��������overTime

#define RTN_MC_MtSetAxisArrivalPara_HANDLE					667 //NMC_MtSetAxisArrivalParan��������handle
#define RTN_MC_MC_MtSetAxisArrivalPara_arrivalBand	668 //NMC_MtSetAxisArrivalParan��������arrivalBand
#define RTN_MC_MC_MtSetAxisArrivalPara_stableTime		669  //NMC_MtSetAxisArrivalParan��������stableTime
#define RTN_MC_MtGetAxisArrivalPara_HANDLE					670  //NMC_MtGetAxisArrivalParan��������Handle


#define RTN_MC_CrdArc3D_HANDLE						671  //NMC_CrdArc3D��������Handle
#define RTN_MC_CrdArc3D_EN							672  //NMC_CrdArc3D��������en
#define RTN_MC_CrdArc3D_VEL							673  //NMC_CrdArc3D��������vel
#define RTN_MC_CrdArc3D_ACC							674  //NMC_CrdArc3D��������acc
#define RTN_MC_CrdArc3D_Less_3D						675  //NMC_CrdArc3D ����ʱ��δ����3D����ϵ

#define RTN_MC_INN_CD_3D_S							676	// 3DԲ�����أ������غ�
#define RTN_MC_INN_CD_3D_L							677	// 3DԲ�����أ����㹲��
#define RTN_MC_INN_CD_3D_CIR_DEGRAD					678	// 3DԲ����������˻�
#define RTN_LIB_NOT_ACTIVE						    679	// û�м���Ĺ���

#define RTN_MC_LinearCompSetData_pos		 	680 // ����λ�ñȽϵ�λ�ô���

#define RTN_MC_CompXDimensSetParam_chn					681				//NMC_CompXDimensSetParam��������chn
#define RTN_MC_CompXDimensSetParam_outCnts			682				//NMC_CompXDimensSetParam��������outCnts
#define RTN_MC_CompXDimensSetParam_outChnType		683				//NMC_CompXDimensSetParam��������outChnType
#define RTN_MC_CompXDimensSetParam_gateTime			684				//NMC_CompXDimensSetParam��������gateTime
#define RTN_MC_CompXDimensSetParam_stLevel			685				//NMC_CompXDimensSetParam��������stLevel	
#define RTN_MC_CompXDimensSetParam_dimens				686				//NMC_CompXDimensSetParam��������dimens
#define RTN_MC_CompXDimensSetParam_errZone			687				//NMC_CompXDimensSetParam��������errZone
#define RTN_MC_CompXDimensSetParam_posSrc				688				//NMC_CompXDimensSetParam��������posSrc
#define RTN_MC_CompXDimensSetParam_outType     	689				//NMC_CompXDimensSetParam��������outType 
#define  RTN_MC_CompXDimensSetParam_outIndex   	690				//NMC_CompXDimensSetParam��������outIndex

#define RTN_MC_CompXDimensGetParam_chn                	691				//NMC_CompXDimensGetParam��������chn

#define RTN_MC_CompXDimensSetData_chn                 	692				//NMC_CompXDimensSetData��������chn
#define RTN_MC_CompXDimensSetData_count               	693				//NMC_CompXDimensSetData��������count
#define RTN_MC_CompXDimensSetData_push_data_failed    	694				//NMC_CompXDimensSetData����ѹ��SDARM����

#define RTN_MC_NMC_CompXDimensOnoff_chn               	695				//NMC_CompXDimensOnoff��������chn
#define RTN_MC_NMC_CompXDimensOnoff_onOff             	696				//NMC_CompXDimensOnoff��������onOff 

#define RTN_MC_CompXDimensStatus_chn                  	697				//NMC_CompXDimensStatus��������chn

#define RTN_MC_CrdBufMotion_Polar_err_start							698				// �������˶�������ֱ�ߵ����ӣ�0,0��λ�ó���


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

#define RTN_MC_SelectPID_HANDLE                  				729		// NMC_MtSetPIDIndex:�������
#define RTN_MC_GetUsingPIDIndex_HANDLE                  730		// NMC_MtGetPIDIndex���������
#define RTN_MC_GetUsingPIDIndex_ctrlMode                731		// NMC_MtGetPIDIndex������ģʽ
#define RTN_CrdBufSetEstopDI_HANDLE 										732		// NMC_CrdBufSetEstopDI�����
#define RTN_CrdBufSetEstopDI_Axis 											733		// NMC_CrdBufSetEstopDI����ŷ�Χ����ȷ
#define RTN_MC_UserPassword_UserNotSupport 							734		// �û�����֧�֣���ǰֻ֧��"USER1"

// ��ʱ����
#define RTN_MC_MtSetLeadScrewPara_HANDLE 				735	// NMC_MtSetLeadScrewPara:�������
#define RTN_MC_MtSetLeadScrewPara_number 				736
#define RTN_MC_MtSetLeadScrewPara_lenPos 				737
#define RTN_MC_MtSetLeadScrewCompPos_HANDLE 		738
#define RTN_MC_MtSetLeadScrewCompPos_index 			739
#define RTN_MC_MtEnableLeadScrew_HANDLE 				740
#define RTN_MC_MtSetLeadScrewCompPos_not_config 741
#define RTN_MC_MtSetLeadScrewCompPos_enable 		742
#define RTN_MC_MtSetEstopDI_HANDLE							743
#define RTN_MC_MtGetEstopDI_HANDLE							744
#define RTN_MC_SetDIBitRevs_Index 							745 // NMC_SetDIBitRevs:bitIndex��Χ����ȷ

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
#define RTN_MC_CrdBufDataPack_HANDLE						759	// NMC_CrdBufDataPack:�������
#define RTN_MC_CrdBufDataPack_En								760	// NMC_CrdBufDataPack:����ϵδ����
#define RTN_MC_CrdBufDataPack_UnknowCmd					761	// NMC_CrdBufDataPack:δ֪������
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
#define RTN_MC_MtSetAdvCaptParam_Filter		775								// NMC_MtSetAdvCaptParam:filterȡֵ��Χ����ȷ


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
#define RTN_MC_ClrPassword_Err									789			// ClrPassword:�������ݲ���ȷ

#define RTN_MC_CrdSetIsShortLine_HANDLE									790
#define RTN_MC_CrdSetIsShortLine_EN											791
#define RTN_MC_CrdSetIsShortLine_isShortLine						792

#define RTN_MC_CrdSetLookAheadCentriAcc_HANDLE					793
#define RTN_MC_CrdSetLookAheadCentriAcc_EN							794
#define RTN_MC_CrdSetLookAheadCentriAcc_isUsingSetAcc		795
#define RTN_MC_CrdSetLookAheadCentriAcc_centriAcc				796

#define RTN_NMC_SetDioMapping_PinGrp				797 // NMC_SetDioMapping:pinGrp/newGrp��Χ����
#define RTN_NMC_SetDioMapping_PinIndex				798 // NMC_SetDioMapping:pinIndex/newIndex��Χ����
#define RTN_NMC_SetDioMapping_Full				799 // NMC_SetDioMapping:���ֻ������16��ӳ������

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
#define RTN_MC_LaserGetOnOff_Ch										823			// NMC_LaserGetOnOff:ch��Χ����ȷ
#define RTN_MC_LaserSetOutputType_DacMode					824			// MC_LaserSetOutputType:DAC��ռ��
#define RTN_MC_MtSetCtrlMode_dac_mode							825			// MC_MtSetCtrlMode:DAC��ռ��
#define RTN_MC_AdcFilterRange											826			// ADC�˲���Χ���ò���ȷ
#define RTN_MC_MtXXX_HANDLE												827			// ������Ч
#define RTN_MC_SetDacMode_Busy										828			// SetDacMode:DACͨ����ռ�ã�������Ϊ�˼�������ȣ�
#define RTN_MC_LaserSetParam_MinValue							829 // NMC_LaserSetParam:onDelay��Χ����
#define RTN_MC_LaserSetParam_MaxValue							830 // NMC_LaserSetParam:offDelay��Χ����
#define RTN_MC_LinearCompSetParam_Busy						831 // NMC_LinearCompSetParam:������
#define RTN_MC_SHIOGatePulse_Ch										832 // NMC_SHIOGatePulse:ͨ���ŷ�Χ����ȷ
#define RTN_MC_SHIOGatePulse_Busy									833 // NMC_SHIOGatePulse:GateOnʱ�������
#define RTN_MC_PwmPulseOut_Ch											834 // NMC_PwmPulseOut:ͨ���ŷ�Χ����ȷ
#define RTN_MC_PwmPulseOut_Busy										835 // NMC_PwmPulseOut:LaserOnʱ�������
#define RTN_MC_ClrErrorEx_Count										836 // NMC_MtClrErrorEx:count��Χ����

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
#define RTN_MC_UserParaEx_Add_Range					870 // ��չ�û���������ʼ��ַ������Χ
#define RTN_MC_UserParaEx_Len_Range					871 // ��չ�û���������д���ȳ�����Χ

#define RTN_MC_SetLaserPowerCmpTable_xCount													872
#define RTN_MC_SetLaserPowerCmpTable_yCount													873
#define RTN_MC_SetLaserPowerCmpTable_pXCmpPos_not_linear_increasing 874
#define RTN_MC_SetLaserPowerCmpTable_pYCmpPos_not_linear_increasing 875
#define RTN_MC_StopLaserPowerComp_chn																876
#define RTN_MC_SetLaserPowerCmpTable_Chn														877		// NMC_SetLaserPowerCmpTable,����ͨ����Χ����
#define RTN_MC_IOModuleRw_Param																			878		// ��չIOģ����ʴ���:��������//���offset����дλ��
#define RTN_MC_IOModuleRw_Comm																			879		// ��չIOģ����ʴ���:ģ��ID����//���ͨѶ�����Ƿ�ʹ��
#define RTN_MC_IOModuleRw_DevType																		880		// ��չIOģ����ʴ���:ģ���д//���ͨѶ�����Ƿ�ʹ�ܻ��߲���
#define RTN_MC_IOModuleRw_Other																			881		// ��չIOģ����ʴ���:��������
#define RTN_MC_IOModuleRw_En																				881		// ��չIOģ����ʴ���:��վδʹ��

#define RTN_MC_INN_A_POS_DIFF																				890
#define RTN_MC_INN_ARC_A																						891
#define RTN_MC_CrdSetAxisATolVel_HANDLE															892
#define RTN_MC_CrdSetAxisATolVel_EN																	893
#define RTN_MC_CrdSetAxisATolVel_tolVel															894
#define RTN_MC_DoBitPulse_Ch																				895		// DoBitPulseͨ����Χ����ȷ,[0,MAX_NUM_DOBIT_PULSE)
#define RTN_MC_DoBitPulse_DoIndex																		896		// DoBitPulse��doIndex��������ȷ
#define RTN_MC_DoBitPulse_HighLevelTime															897		// DoBitPulse��highLevelTime��������С�ڵ���0
#define RTN_MC_DoBitPulse_lowLevelTime															898		// DoBitPulse��lowLevelTime��������С�ڵ���0
#define RTN_MC_DoBitPulse_OutCount																	899		// DoBitPulse��outCount��������С�ڵ���0
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
#define RTN_MC_CrdBufDataPack_NoSpace					             928	// NMC_CrdBufDataPack:�ռ䲻��
#define RTN_MC_LaserTimeArrayOn_BusyOrMode                           929    // NMC_LaserTimeArrayExe:busy����ģʽ����ʱ������ģʽ
#define RTN_MC_CrdBufWaitPos_Handle                                 930    // NMC_CrdBufWaitPos��handle
#define RTN_MC_CrdBufWaitPos_En                                     931    // NMC_CrdBufWaitPos��en
#define RTN_MC_CrdBufWaitPos_AxisNo                                 932    // NMC_CrdBufWaitPos��axisNo range
#define RTN_MC_CrdBufWaitPos_OverTime                               933    // NMC_CrdBufWaitPos��axisNo range
#define RTN_MC_BufSHIOGateOn_Ch			                            934	    // NMC_BufSHIOGateOn:ch����
#define RTN_MC_BufSHIOGateOff_Ch                                    935     // NMC_BufSHIOGateOff:ch����


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
#define RTN_MC_MtMoveJog_HANDLE             						948  // NMC_MtMoveJog:���

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
#define RTN_MC_ZeroPos_GantryIsSlave						    989     // NMC_MtZeroPos������������Ŵ�վ������ZeroPos
#define RTN_CompHs1D_Chn_Range						    990     // һάλ�ñȽ�-���٣�ͨ����Χ����ȷ
#define RTN_CompHs1D_DirNo_Range						991     // NMC_CompHs1DimensSetParam:������Դ��Χ����ȷ
#define RTN_CompHs1D_OutWidth_Range						992     // NMC_CompHs1DimensSetParam:out1Width/out2Width/out2Delay��Χ����ȷ(0,65535]
#define RTN_CompHs1D_SetData_Busy  					    993     // һάλ�ñȽ�-����:�������
#define RTN_CompHs1D_PosCount_Range  					994     // NMC_CompHs1DimensSetData:λ������������Χ
#define RTN_CompHs1D_Pos_NoData 					    995     // NMC_CompHs1DimensSetData:λ������������Χ
#define RTN_MovePtpTwoStage_VelRange 					996     // NMC_MtMovePtpAbsTwoStage:�����ٶȷ�Χ
#define RTN_MovePtpTwoStage_PosRange 					997     // NMC_MtMovePtpAbsTwoStage:����λ�÷�Χ

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
#define RTN_MC_SetProfilePeriod_Period         			1411  // SetProfilePeriod:���ڷ�Χ
#define RTN_CompHs1D_Manual_Busy 					    1412     // һάλ�ñȽ�-����:�ֶ����æ

#define RTN_MC_CrdSetXYZAJointTransCrdPos_HANDLE		1413
#define RTN_MC_CrdSetXYZAJointTransCrdPos_EN				1414
#define RTN_MC_CrdSetXYZAJointTransCrdPos_isTrns		1415

#define RTN_CrdBufWaitData_Handle 					1416     // NMC_CompHs1DimensSetData:λ������������Χ
#define RTN_CrdBufWaitData_En 					    1417     // NMC_CompHs1DimensSetData:λ������������Χ
#define RTN_CrdBufFlyFollowLnXY_Handle 			    1418     // NMC_CrdBufFlyFollowLineXY:����ϵ���
#define RTN_CrdBufFlyFollowLnXY_En 					1419     // NMC_CrdBufFlyFollowLineXY:����ϵδ����
#define RTN_CrdBufFlyFollowLnXY_Vel 			    1420    // NMC_CrdBufFlyFollowLineXY:vel��Χ
#define RTN_CrdBufFlyFollowLnXY_Acc 			    1421    // NMC_CrdBufFlyFollowLineXY:acc��Χ
#define RTN_CrdBufAxFollowOnOff_En                  1422    // NMC_CrdBufAxFollowOnOff:crdδ����
#define RTN_CrdBufAxFollowOnOff_Handle              1423    // NMC_CrdBufAxFollowOnOff:crd�������
#define RTN_CrdBufAxFollowOnOff_AxMaster            1424    // NMC_CrdBufAxFollowOnOff:axMaster������Χ����ȷ
#define RTN_MC_DoBitPulse_Busy						1425	// DoBitPulse�������
#define RTN_MC_CrdBufDoBitPulse_EN					1426	// DoBitPulse����ϵδʹ��
#define RTN_MC_CrdBufDoBitPulse_Handle				1427	// DoBitPulse����ϵ�������
#define RTN_MC_ConfigSHIOPara_AxMask_Cnt			1428    //  NMC_ConfigHSIOPara:axisMask�������ֻ��������

#define RTN_MC_CrdBufSetLeftLenForLaserWaveOff_Handle		1428	 
#define RTN_MC_CrdBufSetLeftLenForLaserWaveOff_En				1429	 
#define RTN_MC_CrdBufSetLeftLenForLaserWaveOff_length		1430	 
#define RTN_MC_CrdBufLaserOnOff_Section									1431
#define RTN_MC_ConfigSHIOPara_k									1432    // NMC_ConfigHSIOPara:kֵ��Χ����ȷ[0,255]


#define RTN_MC_SetDacLimit_Val									1433    // NMC_SetDacLmt:���ֵ����С�ڵ�����Сֵ
#define RTN_MC_AdvBufIo_Ch										1434     // AdvBufIo:ch��Χ����ȷ��[0,MAX_ADV_BUFIO_GROUP]
#define RTN_MC_AdvBufIoSetParam_OnTime				            1435     // NMC_AdvBufIoSetParam:onTime����С�ڵ���0
#define RTN_MC_AdvBufIoSetParam_OffTime				            1436     // NMC_AdvBufIoSetParam:offTime����С�ڵ���0
#define RTN_MC_GetStsMulti_AxisRange							1437     // NMC_MtGetStsMulti��multiָ����ŷ�Χ����ȷ
#define RTN_MC_GetStsMulti_CountRange							1438     // NMC_MtGetStsMulti��multiָ��count��Χ����ȷ
#define RTN_MC_DiReverseCount_DiType							1439     // NMC_SetDiReverseCount:diType��Χ����ȷ
#define RTN_MC_DiReverseCount_DiIdx							    1440     // NMC_SetDiReverseCount:diIndex��Χ����ȷ
#define RTN_MC_DiReverseCount_Count							    1441     // NMC_SetDiReverseCount:count��Χ����ȷ
#define RTN_MC_SetDOMask_DoType                                 1442     // NMC_SetDOMask:doType��Χ����ȷ
#define RTN_MC_SetDOMask_DoGroup                                1443     // NMC_SetDOMask:groupID��Χ����ȷ
#define RTN_MC_SetCaptRepeat_Count                              1444     // NMC_MtSetCaptRepeat:count��Χ����ȷ
#define RTN_MC_SetCaptRepeat_StartNum                           1445     // NMC_MtSetCaptRepeat:StartNum��Χ����ȷ
#define RTN_MC_SetCaptRepeat_Num                                1446     // NMC_MtSetCaptRepeat:������Χ����ȷ
#define RTN_MC_CrdBufStopMtn_Handle                             1447     // NMC_CrdBufStopMtn:hanle
#define RTN_MC_CrdBufStopMtn_En                                 1448     // NMC_CrdBufStopMtn:en
#define RTN_MC_CrdBufStopMtn_Idx                                1449     // NMC_CrdBufStopMtn:crdIdx��Χ����ȷ��-1��0����1
#define RTN_MC_GetDOEx_DoType                                   1450     // NMC_GetDOEx:doType��Χ����ȷ
#define RTN_MC_SetDOMask_Group                                  1451     // NMC_GetDOEx:group��Χ����ȷ
#define RTN_MC_SetDOMask_En                                     1452     // NMC_GetDOEx:��չģ��
#define RTN_NMC_MtPtStartMtnEx_no_pt_mode                       1453     // NMC_MtPtStartMtnEx:��PTģʽ
#define RTN_NMC_MtPtStartMtnEx_isBusy                           1454     // NMC_MtPtStartMtnEx:Busy
#define RTN_NMC_MtPtStartMtnEx_DiIndex                          1455     // NMC_MtPtStartMtnEx:diIndex��Χ����


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

#define RTN_MC_CrdBufWait_WaitType											1519        // NMC_CrdBufWait:��֧�ֵ�wait����

#define RTN_MC_MtSetAxisDampCompParam_HANDLE											1520 
#define RTN_MC_MtSetAxisDampCompParam_enable											1521
#define RTN_MC_MtSetAxisDampCompParam_param1											1522
#define RTN_MC_MtSetAxisDampCompParam_param2											1523

#define RTN_MC_SetDOBitRevesEx_DoType										1524    // NMC_SetDOBitRevsEx:DoType��������ȷ
#define RTN_MC_SetDOBitRevesEx_Group										1525    // NMC_SetDOBitRevsEx:group��������ȷ
#define RTN_CommonRead_Unsupported											1525    // NMC_CommonRead:ָ���ֲ�֧��
#define RTN_CommonWrite_Unsupported											1525    // NMC_CommonWrite:ָ���ֲ�֧��
#define RTN_MC_Comp2DimensSetData_Busy										1526    // NMC_Comp2DimensSetData:busy״̬�²������������
#define RTN_MC_Comp2DimensSetParam_Gatetime									1527    // Comp2DimensSetParam:Gatetime������Χ����(1,32760]
#define RTN_MC_Comp2DimensOnoff_PopData										1528    // NMC_Comp2DimensOnoff:��ȡ����

#define RTN_SetEstopDIEx_Group												1529    // NMC_SetEstopDIEx:����Group��Χ����
#define RTN_SetEstopDIEx_DiType												1530    // NMC_SetEstopDIEx:����ditype��Χ����
#define RTN_SetEstopDIEx_DiIndex											1531    // NMC_SetEstopDIEx:����diindex��Χ����
#define RTN_SetEstopDIEx_Filter												1532    // NMC_SetEstopDIEx:����Filter��Χ����

#define RTN_MC_Set2DCompensationTable_tableIndex							1533	// Set2DCompensationTable:����tableIndex��Χ����
#define RTN_MC_Set2DCompensationTable_count									1534	// Set2DCompensationTable:����count	��Χ����
#define RTN_MC_Set2DCompensationTable_step									1535	// Set2DCompensationTable:����step��Χ����
#define RTN_MC_Set2DCompensation_enable										1536	// Set2DCompensationTable:����enable��Χ����
#define RTN_MC_Set2DCompensation_axisIndex									1537	// Set2DCompensation:����axisIndex��Χ����
#define RTN_MC_Set2DCompensation_axisType									1538	// Set2DCompensation:����axisType��Χ����
#define RTN_MC_Set2DCompensation_tableIndex									1539	// Set2DCompensation:����tableIndex��Χ����
#define RTN_MC_Set2DCompensation_busy										1540	// Set2DCompensation:busy
#define RTN_MC_Set2DCompensation_MemErr										1541	// Set2DCompensation:�ڴ����
#define RTN_MC_Set2DCompensation_DataLen									1542	// Set2DCompensation:��֧�ֶ�����߳���
#define RTN_MC_GetTrapTime_Mode												1543 	// NMC_MtGetTrapTime:��ǰ�᲻��PTPģʽ
#define RTN_MC_MtPtSetPara_HANDLE											1544	// NMC_MtPtSetPara:�������
#define RTN_NMC_MtPtSetPara_no_pt_mode										1545	// NMC_MtPtSetPara:����PTģʽ
#define RTN_NMC_MtPtSetPara_smoothDec										1546	// NMC_MtPtSetPara:smoothDec������Χ����
#define RTN_NMC_MtPtSetPara_abruptDec										1547	// NMC_MtPtSetPara:abruptDec������Χ����
#define RTN_NMC_DIFilter_Index												1548	// NMC_SetDIFilter/NMC_GetDIFilter:diIndex������Χ����
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
#define ECT_ERR_PARA                     10003  //����������������Ϸ���
#define ECT_ERR_MASTER_REQUEST           10004  //���������ṹʧ�ܣ�һ��Ϊ�ڴ���󣬶�̬�ڴ治��
#define ECT_ERR_CREAT_DOMAIN             10005  //����domainʧ�ܣ�һ��Ϊ�ڴ���󣬶�̬�ڴ治��
#define ECT_ERR_REFERENCE_CLOCK_SEL      10006  //ѡ��ο�ʱ��ʧ��
#define ECT_ERR_MASTER_ACTIVE            10007  //��������ʧ�ܣ����ܵ�ԭ����domain���ݱ��ڴ����ʧ��
#define ECT_ERR_GET_DOMAIN_DATA          10008  //��ȡdomain���ݿ�ָ��ʧ�ܣ����ܵ�ԭ����domain����ʧ��
#define ECT_ERR_MODULE_INIT              10009  //Ӳ����Դ��ʼ��ʧ�ܣ�һ��Ϊ�ڴ���󣬶�̬�ڴ治��
#define ECT_ERR_NET_DEV_INIT             10010 //����������ʼ��ʧ�ܣ��豸δע�ᣬ���ڴ����
#define ECT_ERR_HWTIMER_NS_INIT          10011 //Ӳ�����붨ʱ����ʼ��ʧ��
#define ECT_ERR_HWTIMER_START            10012 //Ӳ�����붨ʱ������ʧ��
#define ECT_ERR_SLAVE_NOT_FOUND          10013 //δ���ִ�վ��һ��ԭ������վδ׼����
#define ECT_ERR_IOCTL_GET_MASTER_INFO    10014 //��ȡ��վ��Ϣʧ��
#define ECT_ERR_IOCTL_GET_SLAVE_INFO     10015 //��ȡ��վ��Ϣʧ��
#define ECT_ERR_IOCTL_GET_SYNC           10016 //��ȡͬ��������Ϣʧ��
#define ECT_ERR_IOCTL_GET_PDO            10017 //��ȡPDO(INDEX)ʧ��
#define ECT_ERR_IOCTL_GET_PDO_ENTRY      10018 //��ȡPDO(ENTRY)ʧ��
#define ECT_ERR_MASTER_NOT_OP            10019 //δ����OP״̬����Ҫ��ѯ��վ״̬ΪOPʱ�����ɽ�����������
#define ECT_ERR_HOME_METHOD_GET          10020 //��ȡ���㷽ʽʧ��
#define ECT_ERR_HOME_VSWITH_GET          10021 //��ȡ�����ҿ����ٶ�ʧ��
#define ECT_ERR_HOME_VZERO_GET           10022 //��ȡ����ʱ��Z���ٶ�ʧ��
#define ECT_ERR_HOME_ACC_GET             10023 //��ȡ������ٶ�ʧ��
#define ECT_ERR_HOME_METHOD_SET          10024 //���û��㷽ʽ����ʧ�ܣ����ܵĴ���δ�ҵ���վ����֧�ֵĻ��㷽ʽ���ڴ����
#define ECT_ERR_HOME_VSWITH_SET          10025 //���û����ҿ����ٶ�ʧ�ܣ����ܵĴ���δ�ҵ���վ���ڴ����
#define ECT_ERR_HOME_VZERO_SET           10026 //���û���ʱ��Z���ٶ�ʧ�ܣ����ܵĴ���δ�ҵ���վ���ڴ����
#define ECT_ERR_HOME_ACC_SET             10027 //���û�����ٶ�ʧ�ܣ����ܵĴ���δ�ҵ���վ���ڴ����
#define ECT_ERR_NOT_SRVON                10028 //�ŷ�δʹ��
#define ECT_ERR_GET_SRVON                10029 //��ȡ�ŷ�ʹ��ʧ�ܣ����ܵĴ���δ�ҵ���վ����վδ׼����
#define ECT_ERR_MC_READ                  10030 //PDO�Ĵ�����ʧ�ܣ�PDOδ����
#define ECT_ERR_MC_WRITE                 10031 //PDO�Ĵ���дʧ�ܣ�PDOδ����
#define ECT_ERR_IOCTL_DEVICE_NOT_FOUND   10032 //��վδ�ҵ�
#define ECT_ERR_IOCTL_DEV_NOT_MATCH      10033 //��վ��vid,pid����ƥ��
#define ECT_ERR_MEM_SYNC                 10034 //����sync�ڴ�ʧ��
#define ECT_ERR_MEM_PDO_INFO             10035 //����pdo info�ڴ�ʧ��
#define ECT_ERR_MEM_PDO_ENTRY            10036 //����pdo entry�ڴ�ʧ��
#define ECT_ERR_IOCTL_SDO_UPLOAD         10037 //SDO�ϴ�ʧ��
#define ECT_ERR_IOCTL_SDO_DOWNLOAD       10038 //SDO����ʧ��
#define ECT_ERR_DEVICE_NOT_FOUND         10039 //��վδע�����վ��ʼ��δ���
#define ECT_ERR_FIND_SLAVE               10040 //δ�ҵ���վ�����ܵ�ԭ�����ý׶��������
#define ECT_ERR_SLAVE_CONFIG             10041 //���ô�վʧ��
#define ECT_ERR_DEVICE_ID_NOT_MATCH      10042 //�豸ID��ƥ��
#define ECT_ERR_SLAVE_CONFIG_PDOS        10043 //��վPDO����ʧ��
#define ECT_ERR_SLAVE_CONFIG_REG_PDO_ENTRY   10044//��վPDOע��ʧ��
#define ECT_ERR_NOT_CONFIG               10045 //δ���ô�վ����վ����ǰ��Ҫ�����ô�վ
#define ECT_ERR_NO_SUPPORT               10046 //��֧�ֵĴ�վ�豸
#define ECT_ERR_SUPPORTLIST_FULL         10047 //�����˿�֧�ֵ�����վ����
#define ECT_ERR_MASTER_NO_RUN            10048 //��վδ����
#define ECT_ERR_HOME_RUNNING             10049 //����������
#define ECT_ERR_SCAN_BUSY                10050 //��վ����ɨ���վ����ȴ���վ״̬���
#define ECT_ERR_MASTER_RUNNING			 10051 //��վ���������У�������Ĳ���
#define ECT_ERR_MEM_SM                   10052 //����sync manager�ڴ�ʧ��
#define ECT_ERR_MEM_PDO                  10053 //����PDO�ڴ�ʧ��
#define ECT_ERR_DEV_TYPE                 10054 //��վ���Ͳ�ƥ�䣨��վ��֧�֣�
#define ECT_ERR_NO_SLAVE                 10055 //δ�ҵ��ô�վ

#define RTN_MC_EcatGetHomePara_HANDLE									11533		// NMC_EcatGetHomePara:����������������������
#define RTN_MC_EcatSetHomePara_HANDLE									11534		// NMC_EcatSetHomePara:����������������������
#define RTN_MC_EcatSetHomeSts_HANDLE									11535		// NMC_EcatSetHomeSt:����������������������
#define RTN_MC_EcatStartHome_HANDLE										11536		// NMC_EcatStartHome:����������������������
#define RTN_MC_EcatStopHome_HANDLE										11537		// NMC_EcatStopHome:����������������������
#define RTN_MC_EcatIOGetInput_ioId										11538		// NMC_EcatIOGetInput:IOģ�鲻����
#define RTN_EcatIOGetOutput_ioId										11539		// NMC_EcatIOSetOutput:IOģ�鲻����
#define RTN_EcatIOSetOutput_ioId										11540		// NMC_EcatIOSetOutput:IOģ�鲻����
#define RTN_MC_EcatGetAxisDi_HANDLE										11541		// NMC_EcatGetAxisDi:����������������������
#define RTN_MC_EcatGetAxisErrorCode_HANDLE								11542		// NMC_EcatGetAxisErrorCode:����������������������	
#define RTN_MC_EcatGetAxisMode_HANDLE									11543		// NMC_EcatGetAxisMode:����������������������
#define RTN_MC_EcatSetAxisMode_HANDLE									11544		// NMC_EcatSetAxisMode:����������������������
#define RTN_MC_SetGantrySlave_not_same_axis_type						11545		// NMC_SetGantrySlave:��״̬����
#define RTN_MC_Not_support_ECAT_axis									11546		// ethercat�᲻֧�ֵĹ��ܻ�����ų�����Χ
#define RTN_MC_Ecat_GetInfo_End											11247		// NMC_EcatGetSaveInfo:��վ�ų���
#define RTN_MC_EcatStartHome_Prm										11248		// NMC_EcatStartHome:��������



#endif	//__H_MTN20_ERR_H__

