// Hard.h: interface for the CHard class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HARD_H__0825ABE2_BBFA_4220_9826_6FCBBDB4BA92__INCLUDED_)
#define AFX_HARD_H__0825ABE2_BBFA_4220_9826_6FCBBDB4BA92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHard  
{
public:
	CHard();
	virtual ~CHard();
//Attributes
public:
	USHORT m_nDeviceIndex;
	USHORT m_nDeviceNum;
	//USHORT m_nComType;//0:USB; 1:LAN
	short* m_pSrcData[MAX_CH_NUM];//��ȡ�����ݼ�ȥ���ƽ��λ��(-255 ~ 255)
	USHORT m_nCalLevel[CAL_LEVEL_LEN];//Cal Level
	USHORT m_nTimeDIV;
	USHORT m_nYTFormat;
	BOOL m_bCollect;
	CONTROLDATA m_stControl;
	RELAYCONTROL RelayControl;
	USHORT m_nTriggerMode;
	USHORT m_nTriggerSweep;
	USHORT m_nTriggerSlope;
	USHORT m_nLeverPos[MAX_CH_NUM];
	COLORREF m_clrRGB[MAX_CH_NUM];
	WORD pAmpLevel[AMPCALI_Len];

	USHORT m_nReadOK;//���ζ������Ƿ���ȷ,0,����ȷ����0����ȷ��
//Operations
public:
	void Init();
	void ReadData();
	void CHard::SourceToDisplay(USHORT* pData,ULONG nDataLen,USHORT nCH);

};

#endif // !defined(AFX_HARD_H__0825ABE2_BBFA_4220_9826_6FCBBDB4BA92__INCLUDED_)
