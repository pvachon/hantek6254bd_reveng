
//**************************************************************
//File Name:	MeasDll.h
//Description:
//			MeasDll.h ---- Header file

//Author:	YuT
//Email:	----
//Date:		09/15/2009
//Update:

//Note: ���ļ�������֮����,ֻ������HTKʾ����
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
	// pMaxData:		ָ�����ͣ����������Ϣ.(��Ҫ�ⲿ����ռ�,������СΪ5)
	// pMinData:		ָ�����ͣ���С������Ϣ.(��Ҫ�ⲿ����ռ�,������СΪ5)
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// nSrcDataLen:	ULONG��Դ���ݵĳ���.
//Description:
	//�õ���������Ҫ�ı�Ҫ��Ϣ
//Return:	void

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���в���֮ǰ��������ô˺����Ի�ñ�Ҫ�Ĳ�����Ϣ.
//********************************************************************************
DLL_API void WINAPI PreMeas(short* pMaxData,short* pMinData,const short* pSrcData,ULONG nSrcDataLen);

//********************************************************************************
//Function:				FindPeriod
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.(��Ҫ�ⲿ����ռ�,������СΪ3)
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// pMinData:		ָ�����ͣ���С������Ϣ.
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// nSrcDataLen:	ULONG��Դ���ݵĳ���.
//Description:
	//�õ�������������Ҫ�ı�Ҫ��Ϣ
//Return:	void

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
//����ˮƽ����֮ǰ��������ô˺����Ի�ñ�Ҫ�Ĳ�����Ϣ.
//********************************************************************************
DLL_API void WINAPI FindPeriod(ULONG* PeriodInfo,const short* pMaxData,const short* pMinData,const short* pSrcData,ULONG nSrcDataLen);

//********************************************************************************
//Function:				CalAverage
//Parameters:
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// nSrcDataLen:	ULONG��Դ���ݵĳ���.
//Description:
	// �õ�Դ���ݵ�ƽ��ֵ
//Return:
	// double,����ƽ��ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:

//********************************************************************************
DLL_API double WINAPI CalAverage(const short* pSrcData,ULONG nSrcDataLen);


/***********************************************************************************ˮƽ(ʱ��)*****************************************************************/

//********************************************************************************
//Function:				CalFrequency
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.
	// dbTimeInterval:	double����������֮���ʱ�䳤��
//Description:
	// ����Ƶ��
//Return:
	// double,����Ƶ��ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���ݺ���FindPeriod�õ���PeriodInfo����Ƶ��ֵ
//********************************************************************************
DLL_API double WINAPI CalFrequency(const ULONG* PeriodInfo,double dbTimeInterval);//Ƶ��

//********************************************************************************
//Function:				CalPeriod
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.
	// dbTimeInterval:	double����������֮���ʱ�䳤��
//Description:
	// ��������
//Return:
	// double,��������ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���ݺ���FindPeriod�õ���PeriodInfo��������ֵ
//********************************************************************************
DLL_API double WINAPI CalPeriod(const ULONG* PeriodInfo,double dbTimeInterval);//����

//********************************************************************************
//Function:				CalRiseTime
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// pMinData:		ָ�����ͣ���С������Ϣ.
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// nSrcDataLen:	ULONG��Դ���ݵĳ���.
	// dbTimeInterval:	double����������֮���ʱ�䳤��.
	// fTop:			fTop����������ʱ��ʱ����ֵΪ0.9.
	// fBottom:			fBottom����������ʱ��ʱ����ֵΪ0.1.
//Description:
	// ��������ʱ��
//Return:
	// double,��������ʱ��ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���ݺ���PreMeas�õ���MaxData��MinData��������ʱ��
//********************************************************************************
DLL_API double WINAPI CalRiseTime(const short* pMaxData,const short* pMinData,const short* pSrcData,ULONG nSrcDataLen,double dbTimeInterval,float fTop,float fBottom);//����ʱ��

//********************************************************************************
//Function:				CalFallTime
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// pMinData:		ָ�����ͣ���С������Ϣ.
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// nSrcDataLen:	ULONG��Դ���ݵĳ���.
	// dbTimeInterval:	double����������֮���ʱ�䳤��.
	// fTop:			fTop����������ʱ��ʱ����ֵΪ0.9.
	// fBottom:			fBottom����������ʱ��ʱ����ֵΪ0.1.
//Description:
	// �����½�ʱ��
//Return:
	// double,�����½�ʱ��ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���ݺ���PreMeas�õ���MaxData��MinData�����½�ʱ��
//********************************************************************************
DLL_API double WINAPI CalFallTime(const short* pMaxData,const short* pMinData,const short* pSrcData,ULONG nSrcDataLen,double dbTimeInterval,float fTop,float fBottom);//�½�ʱ��

//********************************************************************************
//Function:				CalPDutyCycle
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.
//Description:
	// ������ռ�ձ�
//Return:
	// double,������ռ�ձ�

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���ݺ���FindPeriod�õ���PeriodInfo������ռ�ձ�
//********************************************************************************
DLL_API double WINAPI CalPDutyCycle(const ULONG* PeriodInfo);//��ռ�ձ�

//********************************************************************************
//Function:				CalNDutyCycle
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.
//Description:
	// ���㸺ռ�ձ�
//Return:
	// double,���ظ�ռ�ձ�

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���ݺ���FindPeriod�õ���PeriodInfo���㸺ռ�ձ�
//********************************************************************************
DLL_API double WINAPI CalNDutyCycle(const ULONG* PeriodInfo);//��ռ�ձ�

//********************************************************************************
//Function:				CalPPulseWidth
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.
	// dbTimeInterval:	double����������֮���ʱ�䳤��.
//Description:
	// ����������
//Return:
	// double,����������ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���ݺ���FindPeriod�õ���PeriodInfo����������ֵ
//********************************************************************************
DLL_API double WINAPI CalPPulseWidth(const ULONG* PeriodInfo,double dbTimeInterval);//������

//********************************************************************************
//Function:				CalNPulseWidth
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.
	// dbTimeInterval:	double����������֮���ʱ�䳤��.
//Description:
	// ���㸺����
//Return:
	// double,���ظ�����ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	//���ݺ���FindPeriod�õ���PeriodInfo���㸺����ֵ
//********************************************************************************
DLL_API double WINAPI CalNPulseWidth(const ULONG* PeriodInfo,double dbTimeInterval);//������

/*
DLL_API double WINAPI CalPDelay12(ULONG* CH1PeriodInfo,ULONG* CH2PeriodInfo,double dbCH1Interval,double dbCH2Interval);
DLL_API double WINAPI CalNDelay12(short* pCH1MaxData,short* pCH1MinData,
								  short* pCH2MaxData,short* pCH2MinData,
								  short* pCH1SrcData,ULONG nCH1SrcDataLen,
								  short* pCH2SrcData,ULONG nCH2SrcDataLen,
								  double dbCH1Interval,double dbCH2Interval);
*/
/***********************************************************************************��ֱ(��ѹ)*****************************************************************/

//********************************************************************************
//Function:				CalMaxVolt
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ��������ѹֵ
//Return:
	// double,��������ѹֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalMaxVolt(const short* pMaxData,double dbVoltDIV,short nMaxData);//����ѹֵ

//********************************************************************************
//Function:				CalMinVolt
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ������С��ѹֵ
//Return:
	// double,������С��ѹֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalMinVolt(const short* pMaxData,double dbVoltDIV,short nMaxData);//��С��ѹֵ

//********************************************************************************
//Function:				CalVpp
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// pMinData:		ָ�����ͣ���С������Ϣ.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ������ֵ
//Return:
	// double,���ط��ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalVpp(const short* pMaxData,short* pMinData,double dbVoltDIV,short nMaxData);//���ֵ

//********************************************************************************
//Function:				CalTopVolt
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ���㶥��ֵ
//Return:
	// double,���ض���ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalTopVolt(const short* pMaxData,double dbVoltDIV,short nMaxData);//����ֵ

//********************************************************************************
//Function:				CalBaseVolt
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short�� ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ����ײ�ֵ
//Return:
	// double,���صײ�ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalBaseVolt(const short* pMinData,double dbVoltDIV,short nMaxData);//�ײ�ֵ

//********************************************************************************
//Function:				CalMidVolt
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// pMinData:		ָ�����ͣ���С������Ϣ.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// �����м�ֵ
//Return:
	// double,�����м�ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalMidVolt(const short* pMaxData,const short* pMinData,double dbVoltDIV,short nMaxData);//�м�ֵ

//********************************************************************************
//Function:				CalRMS
//Parameters:
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// nSrcDataLen:	ULONG��Դ���ݵĳ���.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ������Чֵ
//Return:
	// double,������Чֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalRMS(const short* pSrcData,ULONG nSrcDataLen,double dbVoltDIV,short nMaxData);//��Чֵ

//********************************************************************************
//Function:				CalCRMS
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ����һ�����ڵ���Чֵ
//Return:
	// double,����һ�����ڵ���Чֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalCRMS(const ULONG* PeriodInfo,const short* pSrcData,double dbVoltDIV,short nMaxData);//����һ�����ڵ���Чֵ

//********************************************************************************
//Function:				CalAmplitude
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// pMinData:		ָ�����ͣ���С������Ϣ.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// �������ֵ
//Return:
	// double,���ط���ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalAmplitude(const short* pMaxData,const short* pMinData,double dbVoltDIV,short nMaxData);//����ֵ

//********************************************************************************
//Function:				CalMean
//Parameters:
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// nSrcDataLen:	ULONG��Դ���ݵĳ���.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ����ƽ��ֵ
//Return:
	// double,����ƽ��ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalMean(const short* pSrcData,ULONG nSrcDataLen,double dbVoltDIV,short nMaxData);//ƽ��ֵ

//********************************************************************************
//Function:				CalCMean
//Parameters:
	// PeriodInfo:		ָ�����ͣ�������Ϣ.
	// pSrcData:		ָ�����ͣ���Ҫ�����Դ����.
	// dbVoltDIV:		double��ʵ�ʵ�ѹ��λ.
	// nMaxData:		short, ��������. 8Bit����,���ֵ��Ϊ255
//Description:
	// ��������ƽ��ֵ
//Return:
	// double,��������ƽ��ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalCMean(const ULONG* PeriodInfo,const short* pSrcData,double dbVoltDIV,short nMaxData);//����ƽ��ֵ

//********************************************************************************
//Function:				CalPreShoot
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// pMinData:		ָ�����ͣ���С������Ϣ.
//Description:
	// ����Ԥ��
//Return:
	// double,����Ԥ��ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalPreShoot(const short* pMaxData,const short* pMinData);//Ԥ��

//********************************************************************************
//Function:				CalOverShoot
//Parameters:
	// pMaxData:		ָ�����ͣ����������Ϣ.
	// pMinData:		ָ�����ͣ���С������Ϣ.
//Description:
	// �������
//Return:
	// double,���ع���ֵ

//Author:	YuT
//Email:	------
//Date:		09/15/2009
//Update:

//Note:
	
//********************************************************************************
DLL_API double WINAPI CalOverShoot(const short* pMaxData,const short* pMinData);//����


//

//����CH1/CH2���������ӳٲ�
DLL_API double WINAPI CalPDelay12(ULONG* CH1PeriodInfo,ULONG* CH2PeriodInfo,double dbCH1Interval,double dbCH2Interval);
//����CH1/CH2���½����ӳٲ�
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

DLL_API USHORT WINAPI GetMaxMinData(short* pMaxData,short* pMinData,const short* pSrcData,ULONG nSrcDataLen);//�����ֵ��Сֵ
DLL_API float WINAPI GetAutoMotiveMaxMinData(float* pMaxData,float* pMinData,const float* pSrcData,ULONG nSrcDataLen);
DLL_API short WINAPI GetAmpData(const short* pSrcData,ULONG nSrcDataLen);


//20100124
//ȥ����1������- nZeroLevel

//20100125
//��Ӻ��� CursorFFTFrequency

//20110105

DLL_API double WINAPI AMCalSecondaryIgnitionPlugLead(const short* pSrcData,ULONG nSrcDataLen,double dbTimeInterval,double* pdbDUR,short* pVpp,double* pdbBurnTime,short* pBurnVolt);

#endif
