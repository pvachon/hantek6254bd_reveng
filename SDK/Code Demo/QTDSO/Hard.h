#ifndef HARD_H
#define HARD_H
#include "../../HeadFiles/HTHardDll.h"

#include <windows.h>
#include "../../HeadFiles/DefMacro.h"


class Hard
{

public:
    Hard();
    void Init();
    void Init2();
    void Init3();
    void Init4();
    void ReadData();
    WORD startAStatus();
    void SourceToDisplay(USHORT* pData,ULONG nDataLen,USHORT nCH);
public:
    bool m_bDraw;
    bool m_bStartC;
    USHORT m_nDeviceIndex;
    USHORT m_nDeviceNum;
    short* m_pSrcData[MAX_CH_NUM];//读取的数据减去零电平的位置(-255 ~ 255)
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
    USHORT m_nReadOK;//本次读数据是否正确,0,不正确；非0不正确。
};

#endif // HARD_H
