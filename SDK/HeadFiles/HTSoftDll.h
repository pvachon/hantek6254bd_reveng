#ifndef _HT_SOFT_DLL_H
#define _HT_SOFT_DLL_H

#ifndef DLL_API
#define DLL_API extern "C" _declspec(dllimport)
#endif
#define WINAPI __stdcall

typedef struct _HT_CONTROL_DATA
{
		WORD nCHSet;
        WORD nTimeDIV;
        WORD nTriggerSource;
        WORD nHTriggerPos;
		WORD nVTriggerPos;
		WORD nTriggerSlope;
		ULONG nBufferLen;//对应于10K，1M，2M.....16M
		ULONG nReadDataLen;//记录本次将要从硬件读取的数据总共长度
		ULONG nAlreadyReadLen;//记录本次已经读取的数据长度，在扫描/滚动模式下有效,在NORMAL模式下无效
    	WORD nALT;
		WORD nETSOpen;
		WORD nDriverCode;		//驱动编号
		ULONG nLastAddress;  //    记录扫描模式上次读取的终止地址
		WORD nFPGAVersion;//FPGA 版本号
		//WORD nAddressOffset;//触发抖动加偏移
		
		
}CONTROLDATA,*PCONTROLDATA;


DLL_API WORD WINAPI dsoSFInsert(WORD* pSourceData,WORD* pBufferData,PCONTROLDATA pControl,WORD nInsertMode,WORD nCH,ULONG* pState);
//
DLL_API WORD WINAPI dsoSFProcessALTData(WORD* pOutData,WORD* pInData1,WORD* pInData2,ULONG nDataLen,WORD nHTriggerPos,WORD nCalData);

DLL_API ULONG WINAPI dsoSFFindTrigger(WORD* SourceData,WORD* BufferData,PCONTROLDATA Control,double dInsert);//zhang addd dInsert

DLL_API WORD WINAPI dsoSFFindTriggerCopy(WORD* SourceData,WORD* BufferData,PCONTROLDATA Control,ULONG TriggerPoint);

DLL_API WORD WINAPI dsoSFInsertDataStep(WORD* SourceData,WORD* pBuffer,double div_data,PCONTROLDATA Control);

DLL_API WORD WINAPI dsoSFInsertDataLine(WORD* SourceData,WORD* pBuffer,double div_data,PCONTROLDATA Control);

DLL_API WORD WINAPI dsoSFInsertDataSin(WORD* SourceData,WORD* BufferData,PCONTROLDATA Control, double dbInsertNum,double* dbSinSheet);

DLL_API WORD WINAPI dsoSFCalSinSheet(double div_data,double* dbSinSheet);

DLL_API double WINAPI dsoSFGetInsertNum(WORD nTimeDIV, WORD nALT, WORD nCHSet);   //modified by zhang  to fit 6104  from "bool bSingle" to "nCHSet"

DLL_API void WINAPI dsoSFProcessInsertData(WORD* SourceData,WORD* BufferData,PCONTROLDATA pControl,WORD nInsertMode,BOOL bSingle,double* dbSinSheet,USHORT nCH);

DLL_API ULONG WINAPI dsoSFGetSampleRate(WORD nTimeDIV,WORD nALT,WORD nCHState,WORD nCH);

DLL_API short WINAPI HTPosConvertToScale(int x,int y);

DLL_API POINT WINAPI HTGetTracePoint(RECT Rect,POINT pt,short nData,USHORT nDisLeverPos);

DLL_API ULONG WINAPI HTGetTracePointIndex(RECT Rect,POINT pt,ULONG nDisDataLen,ULONG nSrcDataLen,USHORT nHTriggerPos);

DLL_API WORD WINAPI dsoSFMathOperate(USHORT nOperate,const short* pSrcA,const short* pSrcB,short* pMathData,ULONG nDataLen);

DLL_API WORD WINAPI dsoSFChooseData(WORD* pSrcData,ULONG nSrcDataLen,ULONG nChoose,WORD* pOutData,ULONG nOutDataLen);

DLL_API WORD WINAPI dsoSFGetFFTSrcData(short* pSrcData,ULONG nCenterData,short* pFFTSrcData);

DLL_API double WINAPI dsoSFGetFFTSa(double dbTime);

DLL_API BOOL WINAPI dsoSFCalPassFailData(short* pSrcData,ULONG nSrcDataLen,short* pOutData,float fH,float fV);

DLL_API BOOL WINAPI dsoSFPassFail(short* pPFData,short* pSrcData,ULONG nDataLen);

DLL_API WORD WINAPI dsoSFProcessALTData4CH(WORD* pOutData,WORD* pInData1,WORD* pInData2,WORD* pInData3,WORD* pInData4,ULONG nDataLen,WORD nHTriggerPos,WORD nCalData);

DLL_API double WINAPI dsoSFGetMiniScopeFFTSa(USHORT nTimeDIV,USHORT nCHNum,USHORT nMode);//返回的是Hz

DLL_API void WINAPI dsoGetSoftTriggerPos(USHORT nTimeDIV,USHORT nTriggerSource,ULONG* pState,USHORT nFPGAVersion);

DLL_API void WINAPI dsoGetSoftTriggerPosNew(PCONTROLDATA Control,ULONG* pState,USHORT nFPGAVersion);

DLL_API void WINAPI dsoAdjustSquareWave(WORD* pSrcData, ULONG nSrcDataLen);
DLL_API void WINAPI dsoAdjustADC(WORD* pSrcData, ULONG nSrcDataLen);
#endif
