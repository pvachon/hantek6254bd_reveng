// Hard.cpp: implementation of the CHard class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VCDSO.h"
#include "Hard.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHard::CHard()
{
	m_nLeverPos[CH1] = 192;
	m_nLeverPos[CH2] = 160;
	m_nLeverPos[CH3] = 96;
	m_nLeverPos[CH4] = 64; 
	ULONG i = 0;
	m_nDeviceIndex = 0;
	m_nDeviceNum = 0;
	for(i=0;i<MAX_CH_NUM;i++)
	{
		m_pSrcData[i] = new short[BUF_4K_LEN];
	}
	m_clrRGB[CH1] = RGB(255,255,0);
	m_clrRGB[CH2] = RGB(0,255,255);
	m_clrRGB[CH3] = RGB(255,0,255);
	m_clrRGB[CH4] = RGB(0,255,0);
	memset(m_nCalLevel,0,sizeof(m_nCalLevel));
	m_nTimeDIV = 12;
	m_nYTFormat = YT_NORMAL;
	m_stControl.nCHSet = 0x0F;//所有通道打开
	m_stControl.nTimeDIV = m_nTimeDIV;//Factory Setup
	m_stControl.nTriggerSource = CH1;//通道1为触发通道
	m_stControl.nHTriggerPos = 50;//水平触发位置（0-100）
	m_stControl.nVTriggerPos = m_nLeverPos[CH1];//垂直触发位置和通道1相同
	m_stControl.nTriggerSlope = RISE;//边沿触发的触发方式：上升沿
	m_stControl.nBufferLen = BUF_4K_LEN;//采集深度
	m_stControl.nReadDataLen = BUF_4K_LEN;//读取长度<=采集深度
	m_stControl.nAlreadyReadLen = 0;//只在扫描滚动情况下有效，用来记录已经读取的长度
	m_stControl.nALT = 0;//Factory Setup
	for(i=0;i<MAX_CH_NUM;i++)
	{
		RelayControl.bCHEnable[i] = 1;
		RelayControl.nCHVoltDIV[i] = 8;
		RelayControl.nCHCoupling[i] = DC;
		RelayControl.bCHBWLimit[i] = 0;
	}	
	RelayControl.nTrigSource = CH1;
	RelayControl.bTrigFilt = 0;
	RelayControl.nALT = 0;
	m_nTriggerMode = EDGE;
	m_nTriggerSlope = RISE;
	m_nTriggerSweep = AUTO;

	m_bCollect=TRUE;
	m_nReadOK = 0;

	for(i=0;i<AMPCALI_Len;i++){pAmpLevel[i]=1024;}//所有幅度修正设置为1024/1024=1.0
}

CHard::~CHard()
{

}

void CHard::Init()
{
	m_nDeviceIndex = 0;
	dsoSetUSBBus(m_nDeviceIndex);//上电后总线设置
	dsoInitHard(m_nDeviceIndex);//硬件初始化
	dsoHTADCCHModGain(m_nDeviceIndex,4);//设置由通道模式引起的幅度修正
	dsoHTReadCalibrationData(m_nDeviceIndex,m_nCalLevel,CAL_LEVEL_LEN);//读取0电平校准数据
	{
		if(m_nCalLevel[CAL_LEVEL_LEN-1]!=ZERO_FLAG)//如果未设置侧载入默认值
		{	
				for(int i=0;i< ZEROCALI_LEN;i++){
					int nVolt=(i%ZEROCALI_PER_CH_LEN)/ZEROCALI_PER_VOLT_LEN;
					if(nVolt==5||nVolt==8||nVolt==11){
						switch((i%ZEROCALI_PER_CH_LEN)%ZEROCALI_PER_VOLT_LEN){
						case 0:
							m_nCalLevel[i]=16602;
							break;
						case 1:
							m_nCalLevel[i]=60111;
							break;
						case 2:
							m_nCalLevel[i]=17528;
							break;
						case 3:
							m_nCalLevel[i]=59201;
							break;
						case 4:
							m_nCalLevel[i]=17710;
							break;
						case 5:
							m_nCalLevel[i]=58900;
							break;
						default:
							m_nCalLevel[i]=0;
							break;
						}							
					}
				}
			}
	}
	dsoHTSetSampleRate(m_nDeviceIndex,pAmpLevel,m_nYTFormat,&RelayControl,&m_stControl);//设置采样率
	dsoHTSetCHAndTrigger(m_nDeviceIndex,&RelayControl,m_stControl.nTimeDIV);//设置通道开关和电压档位
	dsoHTSetRamAndTrigerControl(m_nDeviceIndex,m_stControl.nTimeDIV,m_stControl.nCHSet,m_stControl.nTriggerSource,0);//设置触发源
	for(int i=0;i<MAX_CH_NUM;i++)
	{
		dsoHTSetCHPos(m_nDeviceIndex,m_nCalLevel,RelayControl.nCHVoltDIV[i],m_nLeverPos[i],i,4);
	}
	dsoHTSetVTriggerLevel(m_nDeviceIndex,m_nLeverPos[CH1],4);
	switch (m_nTriggerMode) {//触发设置
        case EDGE:
            dsoHTSetTrigerMode(m_nDeviceIndex,m_nTriggerMode,m_stControl.nTriggerSlope,DC);
            break;
			/*
        case VIDEO:
			{
			double dbVolt=m_dbVoltDIV[RelayControl.nCHVoltDIV[m_nALTSelCH]];
			short nPositive=nVideoPositive==POSITIVE?TRIGGER_VIDEO_POSITIVE:TRIGGER_VIDEO_NEGATIVE;
			WORD nTriggerLevel=255-GetCHLeverPos(m_nALTSelCH)+short((256*nPositive)/(dbVolt*V_GRID_NUM)+0.5);
            dsoHTSetTrigerMode(m_nDeviceIndex,m_nTriggerMode,m_stControl.nTriggerSlope,m_Trigger.m_nTriggerCouple);
            dsoHTSetVideoTriger(m_nDeviceIndex,nVideoStandard,nVideoSyncSelect,nVideoHsyncNumOption,nVideoPositive,nTriggerLevel,GetLogicTriggerSource(m_nALTSelCH));
            break;}
		case PULSE:
			dsoHTSetTrigerMode(m_nDeviceIndex,m_nTriggerMode,m_stControl.nTriggerSlope,m_Trigger.m_nTriggerCouple);
			dsoHTSetPulseTriger(m_nDeviceIndex,nPW,nPWCondition);
			break;
		case FORCE:
			dsoHTSetTrigerMode(m_nDeviceIndex,m_nTriggerMode,m_stControl.nTriggerSlope,m_Trigger.m_nTriggerCouple);
			*/
        default:
            break;
       }

}
void CHard::ReadData()
{
	int i=0;
	USHORT* pReadData[MAX_CH_NUM];
	for(i=0;i<MAX_CH_NUM;i++)
	{
		pReadData[i] = new USHORT[m_stControl.nReadDataLen];
		memset(pReadData[i],0,m_stControl.nReadDataLen*sizeof(USHORT));//
	}
	m_nReadOK = dsoHTGetData(m_nDeviceIndex,pReadData[CH1],pReadData[CH2],pReadData[CH3],pReadData[CH4],&m_stControl);//每通道i第j个点的实际电压值=(pReadData[i][j]-m_nLeverPos[i])*8*电压值/255
	if(m_nReadOK == 1)
	{
		for(i=0;i<MAX_CH_NUM;i++)
		{
			SourceToDisplay(pReadData[i],m_stControl.nReadDataLen,i);//为了方便显示
		}
	}

	for(i=0;i<MAX_CH_NUM;i++)
	{
		delete pReadData[i];
	}
}

void CHard::SourceToDisplay(USHORT* pData,ULONG nDataLen,USHORT nCH)
{
	for(ULONG i=0;i<nDataLen;i++)
	{
		*(m_pSrcData[nCH]+i) = *(pData+i)-(MAX_DATA - m_nLeverPos[nCH]);
	}
}