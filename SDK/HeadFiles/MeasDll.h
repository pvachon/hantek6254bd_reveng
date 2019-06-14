
//**************************************************************
//File Name:	MeasDll.h
//Description:
//			MeasDll.h ---- Header file

//Author:	YuT
//Email:	----
//Date:		09/15/2009
//Update:

//Note: 本文件所声明之函数,只适用于HTK示波器
//**************************************************************

#ifndef _MEASURE_DLL_H_
#define _MEASURE_DLL_H_
/*******************************************/
#ifdef DLL_API
#else
#define DLL_API extern "C" _declspec(dllimport)
#endif

#define WINAPI __stdcall

//********************************************************************************
//Function:				PreMeas
//Parameters:
	// pMaxData:		指针类型，最大数据信息.(需要外部申请空间,长度最小为5)
	// pMinData:		指针类型，最小数据信息.(需要外部申请空间,长度最小为5)
	// pSrcData:		指针类型，所要计算的源数据.
	// nSrcDataLen:	ULONG，源数据的长度.
//Description:
	//得到测量所需要的必要信息
//Return:	void

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//进行测量之前，必须调用此函数以获得必要的测量信息.
//********************************************************************************
DLL_API void WINAPI PreMeas(short* pMaxData,short* pMinData,const short* pSrcData,ULONG nSrcDataLen);

//********************************************************************************
//Function:				FindPeriod
//Parameters:
	// PeriodInfo:		指针类型，周期信息.(需要外部申请空间,长度最小为3)
	// pMaxData:		指针类型，最大数据信息.
	// pMinData:		指针类型，最小数据信息.
	// pSrcData:		指针类型，所要计算的源数据.
	// nSrcDataLen:	ULONG，源数据的长度.
//Description:
	//得到测量周期所需要的必要信息
//Return:	void

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
//进行水平测量之前，必须调用此函数以获得必要的测量信息.
//********************************************************************************
DLL_API void WINAPI FindPeriod(ULONG* PeriodInfo,const short* pMaxData,const short* pMinData,const short* pSrcData,ULONG nSrcDataLen);

//********************************************************************************
//Function:				CalAverage
//Parameters:
	// pSrcData:		指针类型，所要计算的源数据.
	// nSrcDataLen:	ULONG，源数据的长度.
//Description:
	// 得到源数据的平均值
//Return:
	// double,返回平均值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:

//********************************************************************************
DLL_API double WINAPI CalAverage(const short* pSrcData,ULONG nSrcDataLen);


/***********************************************************************************水平(时间)*****************************************************************/

//********************************************************************************
//Function:				CalFrequency
//Parameters:
	// PeriodInfo:		指针类型，周期信息.
	// dbTimeInterval:	double，数据两点之间的时间长度
//Description:
	// 计算频率
//Return:
	// double,返回频率值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//根据函数FindPeriod得到的PeriodInfo计算频率值
//********************************************************************************
DLL_API double WINAPI CalFrequency(const ULONG* PeriodInfo,double dbTimeInterval);//频率

//********************************************************************************
//Function:				CalPeriod
//Parameters:
	// PeriodInfo:		指针类型，周期信息.
	// dbTimeInterval:	double，数据两点之间的时间长度
//Description:
	// 计算周期
//Return:
	// double,返回周期值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//根据函数FindPeriod得到的PeriodInfo计算周期值
//********************************************************************************
DLL_API double WINAPI CalPeriod(const ULONG* PeriodInfo,double dbTimeInterval);//周期

//********************************************************************************
//Function:				CalRiseTime
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// pMinData:		指针类型，最小数据信息.
	// pSrcData:		指针类型，所要计算的源数据.
	// nSrcDataLen:	ULONG，源数据的长度.
	// dbTimeInterval:	double，数据两点之间的时间长度.
	// fTop:			fTop，计算上升时间时，此值为0.9.
	// fBottom:			fBottom，计算上升时间时，此值为0.1.
//Description:
	// 计算上升时间
//Return:
	// double,返回上升时间值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//根据函数PreMeas得到的MaxData，MinData计算上升时间
//********************************************************************************
DLL_API double WINAPI CalRiseTime(const short* pMaxData,const short* pMinData,const short* pSrcData,ULONG nSrcDataLen,double dbTimeInterval,float fTop,float fBottom);//上升时间

//********************************************************************************
//Function:				CalFallTime
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// pMinData:		指针类型，最小数据信息.
	// pSrcData:		指针类型，所要计算的源数据.
	// nSrcDataLen:	ULONG，源数据的长度.
	// dbTimeInterval:	double，数据两点之间的时间长度.
	// fTop:			fTop，计算上升时间时，此值为0.9.
	// fBottom:			fBottom，计算上升时间时，此值为0.1.
//Description:
	// 计算下降时间
//Return:
	// double,返回下降时间值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//根据函数PreMeas得到的MaxData，MinData计算下降时间
//********************************************************************************
DLL_API double WINAPI CalFallTime(const short* pMaxData,const short* pMinData,const short* pSrcData,ULONG nSrcDataLen,double dbTimeInterval,float fTop,float fBottom);//下降时间

//********************************************************************************
//Function:				CalPDutyCycle
//Parameters:
	// PeriodInfo:		指针类型，周期信息.
//Description:
	// 计算正占空比
//Return:
	// double,返回正占空比

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//根据函数FindPeriod得到的PeriodInfo计算正占空比
//********************************************************************************
DLL_API double WINAPI CalPDutyCycle(const ULONG* PeriodInfo);//正占空比

//********************************************************************************
//Function:				CalNDutyCycle
//Parameters:
	// PeriodInfo:		指针类型，周期信息.
//Description:
	// 计算负占空比
//Return:
	// double,返回负占空比

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//根据函数FindPeriod得到的PeriodInfo计算负占空比
//********************************************************************************
DLL_API double WINAPI CalNDutyCycle(const ULONG* PeriodInfo);//负占空比

//********************************************************************************
//Function:				CalPPulseWidth
//Parameters:
	// PeriodInfo:		指针类型，周期信息.
	// dbTimeInterval:	double，数据两点之间的时间长度.
//Description:
	// 计算正脉宽
//Return:
	// double,返回正脉宽值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//根据函数FindPeriod得到的PeriodInfo计算正脉宽值
//********************************************************************************
DLL_API double WINAPI CalPPulseWidth(const ULONG* PeriodInfo,double dbTimeInterval);//正脉宽

//********************************************************************************
//Function:				CalNPulseWidth
//Parameters:
	// PeriodInfo:		指针类型，周期信息.
	// dbTimeInterval:	double，数据两点之间的时间长度.
//Description:
	// 计算负脉宽
//Return:
	// double,返回负脉宽值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//根据函数FindPeriod得到的PeriodInfo计算负脉宽值
//********************************************************************************
DLL_API double WINAPI CalNPulseWidth(const ULONG* PeriodInfo,double dbTimeInterval);//负脉宽

/*
DLL_API double WINAPI CalPDelay12(ULONG* CH1PeriodInfo,ULONG* CH2PeriodInfo,double dbCH1Interval,double dbCH2Interval);
DLL_API double WINAPI CalNDelay12(short* pCH1MaxData,short* pCH1MinData,
								  short* pCH2MaxData,short* pCH2MinData,
								  short* pCH1SrcData,ULONG nCH1SrcDataLen,
								  short* pCH2SrcData,ULONG nCH2SrcDataLen,
								  double dbCH1Interval,double dbCH2Interval);
*/
/***********************************************************************************垂直(电压)*****************************************************************/

//********************************************************************************
//Function:				CalMaxVolt
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算最大电压值
//Return:
	// double,返回最大电压值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalMaxVolt(const short* pMaxData,double dbVoltDIV,short nMaxData);//最大电压值

//********************************************************************************
//Function:				CalMinVolt
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算最小电压值
//Return:
	// double,返回最小电压值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalMinVolt(const short* pMaxData,double dbVoltDIV,short nMaxData);//最小电压值

//********************************************************************************
//Function:				CalVpp
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// pMinData:		指针类型，最小数据信息.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算峰峰值
//Return:
	// double,返回峰峰值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalVpp(const short* pMaxData,short* pMinData,double dbVoltDIV,short nMaxData);//峰峰值

//********************************************************************************
//Function:				CalTopVolt
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算顶部值
//Return:
	// double,返回顶部值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalTopVolt(const short* pMaxData,double dbVoltDIV,short nMaxData);//顶部值

//********************************************************************************
//Function:				CalBaseVolt
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short， 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算底部值
//Return:
	// double,返回底部值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalBaseVolt(const short* pMinData,double dbVoltDIV,short nMaxData);//底部值

//********************************************************************************
//Function:				CalMidVolt
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// pMinData:		指针类型，最小数据信息.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算中间值
//Return:
	// double,返回中间值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalMidVolt(const short* pMaxData,const short* pMinData,double dbVoltDIV,short nMaxData);//中间值

//********************************************************************************
//Function:				CalRMS
//Parameters:
	// pSrcData:		指针类型，所要计算的源数据.
	// nSrcDataLen:	ULONG，源数据的长度.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算有效值
//Return:
	// double,返回有效值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalRMS(const short* pSrcData,ULONG nSrcDataLen,double dbVoltDIV,short nMaxData);//有效值

//********************************************************************************
//Function:				CalCRMS
//Parameters:
	// PeriodInfo:		指针类型，周期信息.
	// pSrcData:		指针类型，所要计算的源数据.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算一个周期的有效值
//Return:
	// double,返回一个周期的有效值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalCRMS(const ULONG* PeriodInfo,const short* pSrcData,double dbVoltDIV,short nMaxData);//计算一个周期的有效值

//********************************************************************************
//Function:				CalAmplitude
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// pMinData:		指针类型，最小数据信息.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算幅度值
//Return:
	// double,返回幅度值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalAmplitude(const short* pMaxData,const short* pMinData,double dbVoltDIV,short nMaxData);//幅度值

//********************************************************************************
//Function:				CalMean
//Parameters:
	// pSrcData:		指针类型，所要计算的源数据.
	// nSrcDataLen:	ULONG，源数据的长度.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算平均值
//Return:
	// double,返回平均值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalMean(const short* pSrcData,ULONG nSrcDataLen,double dbVoltDIV,short nMaxData);//平均值

//********************************************************************************
//Function:				CalCMean
//Parameters:
	// PeriodInfo:		指针类型，周期信息.
	// pSrcData:		指针类型，所要计算的源数据.
	// dbVoltDIV:		double，实际电压档位.
	// nMaxData:		short, 数据上限. 8Bit精度,最大值即为255
//Description:
	// 计算周期平均值
//Return:
	// double,返回周期平均值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalCMean(const ULONG* PeriodInfo,const short* pSrcData,double dbVoltDIV,short nMaxData);//周期平均值

//********************************************************************************
//Function:				CalPreShoot
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// pMinData:		指针类型，最小数据信息.
//Description:
	// 计算预冲
//Return:
	// double,返回预冲值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalPreShoot(const short* pMaxData,const short* pMinData);//预冲

//********************************************************************************
//Function:				CalOverShoot
//Parameters:
	// pMaxData:		指针类型，最大数据信息.
	// pMinData:		指针类型，最小数据信息.
//Description:
	// 计算过冲
//Return:
	// double,返回过冲值

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalOverShoot(const short* pMaxData,const short* pMinData);//过冲


//

//计算CH1/CH2的上升沿延迟差
DLL_API double WINAPI CalPDelay12(ULONG* CH1PeriodInfo,ULONG* CH2PeriodInfo,double dbCH1Interval,double dbCH2Interval);
//计算CH1/CH2的下降沿延迟差
DLL_API double WINAPI CalNDelay12(short* pCH1MaxData,short* pCH1MinData,
								  short* pCH2MaxData,short* pCH2MinData,
								  short* pCH1SrcData,ULONG nCH1SrcDataLen,
								  short* pCH2SrcData,ULONG nCH2SrcDataLen,
								  double dbCH1Interval,double dbCH2Interval);
//Cursor Measure

DLL_API double WINAPI CursorTime(long x1, long x2, double dbTime);

DLL_API double WINAPI CursorFrequency(long x1, long x2, double dbTime);

DLL_API double WINAPI CursorVoltage(long y1,long y2,double dbVolt);

DLL_API double WINAPI CursorTraceVoltage(short nData,double dbVolt);

DLL_API double WINAPI CursorFFTFrequency(long x1,long x2,double dbFreq);

//20091220

DLL_API USHORT WINAPI GetMaxMinData(short* pMaxData,short* pMinData,const short* pSrcData,ULONG nSrcDataLen);//求最大值最小值
DLL_API float WINAPI GetAutoMotiveMaxMinData(float* pMaxData,float* pMinData,const float* pSrcData,ULONG nSrcDataLen);
DLL_API short WINAPI GetAmpData(const short* pSrcData,ULONG nSrcDataLen);


//20100124
//去掉了1个参数- nZeroLevel

//20100125
//添加函数 CursorFFTFrequency

//20110105

DLL_API double WINAPI AMCalSecondaryIgnitionPlugLead(const short* pSrcData,ULONG nSrcDataLen,double dbTimeInterval,double* pdbDUR,short* pVpp,double* pdbBurnTime,short* pBurnVolt);

#endif
