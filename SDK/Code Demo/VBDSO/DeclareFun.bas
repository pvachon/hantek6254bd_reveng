Attribute VB_Name = "DeclareFun"
'USB
'dsoHTSearchDevice(short* pDevInfo);
Public Declare Function dsoHTSearchDevice Lib "HTHardDll.dll" (DevInfo As Integer) As Integer
'BOOL WINAPI dsoSetUSBBus(WORD DeviceIndex)
Public Declare Function dsoSetUSBBus Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer) As Boolean
'dsoHTReadCalibrationData(WORD nDeviceIndex,WORD* pLevel,WORD nLen);
Public Declare Function dsoHTReadCalibrationData Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer, pLevel As Integer, ByVal nLen As Integer) As Integer
'dsoHTSetSampleRate(WORD nDeviceIndex,WORD *pAmpLevel,WORD nYTFormat,PRELAYCONTROL pRelayControl,PCONTROLDATA pControl)
Public Declare Function dsoHTSetSampleRate Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer, pAmpLevel As Integer, ByVal nYTFormat As Integer, pRelayControl As Any, pSTControl As Any) As Integer
'dsoHTSetCHAndTrigger(WORD nDeviceIndex,PRELAYCONTROL pRelayControl,WORD nDriverCode,PCONTROLDATA pControl)
Public Declare Function dsoHTSetCHAndTrigger Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer, rcRelayControl As Any, ByVal nTimeDiv As Integer) As Integer
'dsoHTSetHTriggerLength(WORD nDeviceIndex,ULONG nBufferLen,WORD HTriggerPos,WORD nTimeDIV,WORD nCHMod);
Public Declare Function dsoHTSetHTriggerLength Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer, ByVal nBufferLen As Long, ByVal HTriggerPos As Integer, ByVal nTimeDiv As Integer, ByVal nYTFormat As Integer) As Integer
'dsoHTGetState(WORD nDeviceIndex);
Public Declare Function dsoHTGetState Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer) As Integer
'dsoHTSetCHAndTriggerVB(WORD nDeviceIndex,WORD* pCHEnable,WORD* pCHVoltDIV,WORD* pCHCoupling,WORD* pCHBWLimit,WORD nTriggerSource,WORD nTriggerFilt,WORD nALT,WORD nDriverCode);
Public Declare Function dsoHTSetCHAndTriggerVB Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer, ByRef CHEnable As Integer, ByRef CHVoltDIV As Integer, ByRef CHCoupling As Integer, ByRef CHBWLimit As Integer, ByVal nTriggerSource As Integer, ByVal nTriggerFilt As Integer, ByVal nALT As Integer) As Integer
'dsoHTGetData(WORD nDeviceIndex,WORD* pCH1Data,WORD* pCH2Data,WORD* pCH3Data,WORD* pCH4Data,PCONTROLDATA pControl/*,ULONG* p1,ULONG* p2,ULONG* p3*/)


Public Declare Function dsoHTGetData Lib "HTHardDll.dll" (ByVal nDeviceInder As Integer, CH1Data As Integer, CH2Data As Integer, CH3Data As Integer, CH4Data As Integer, pSTControl As Any) As Integer
'dsoHTStartCollectData(WORD nDeviceIndex,WORD nStartControl)
Public Declare Function dsoHTStartCollectData Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer, ByVal startcontrol As Long) As Integer
'dsoHTSetTrigerMode(WORD m_nDeviceIndex,WORD nTriggerMode,WORD nTriggerSlop,WORD nTriggerCouple);
Public Declare Function dsoHTSetTrigerMode Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer, ByVal TriggerMode As Integer, ByVal Slop As Integer, ByVal TriCouple As Integer) As Integer
'dsoHTSetVTriggerLevel(WORD nDeviceIndex,WORD* pLevel,WORD nPos,WORD nSensitivity);
Public Declare Function dsoHTSetVTriggerLevel Lib "HTHardDll.dll" (ByVal nDeviceIndex As Integer, ByVal nPos As Integer, ByVal chmod As Integer) As Integer
'dsoHTSetCHPos(WORD nDeviceIndex,WORD* pLevel,WORD nVoltDIV,WORD nPos,WORD nCH,WORD nCHMode)
Public Declare Function dsoHTSetCHPos Lib "HTHardDll.dll" (ByVal nDeviceInder As Integer, pLevel As Integer, ByVal CHVoltDIV As Integer, ByVal CHPos As Integer, ByVal CH As Integer, ByVal chmod As Integer) As Integer

'dsoInitADCOnce(WORD DeviceIndex)
Public Declare Function dsoInitHard Lib "HTHardDll.dll" (ByVal nDeviceInder As Integer) As Integer
'dsoHTADCCHModGain(WORD DeviceIndex,WORD nCHMod);
Public Declare Function dsoHTADCCHModGain Lib "HTHardDll.dll" (ByVal nDeviceInder As Integer, ByVal nCHMod As Integer) As Integer
'dsoHTSetRamAndTrigerControl(WORD DeviceIndex,WORD nTimeDiv,WORD nCHset,WORD nTrigerSource,WORD nPeak)
Public Declare Function dsoHTSetRamAndTrigerControl Lib "HTHardDll.dll" (ByVal DeviceIndex As Integer, ByVal TimeDIV As Integer, ByVal CHSet As Integer, ByVal nTriggerSource As Integer, ByVal isPeak As Integer) As Integer

'Draw
Public Declare Function HTDrawGrid Lib "HTDisplayDll.dll" (ByVal hDC As Long, ByVal nLeft As Long, ByVal nTop As Long, ByVal nRight As Long, ByVal nBottom As Long, ByVal nHoriGridNum As Long, ByVal nVertGridNum As Long, ByVal nBright As Long, ByVal IsGrid As Long) As Long
Public Declare Function HTDrawWaveInYTVB Lib "HTDisplayDll.dll" (ByVal hDC As Long, ByVal Left As Long, ByVal Top As Long, ByVal Right As Long, ByVal Bottom As Long, ByVal R As Integer, ByVal G As Integer, ByVal B As Integer, ByVal nDisTye As Integer, ByRef pData As Integer, ByVal nLen As Long, ByVal nDisLen As Long, ByVal CenterData As Long, ByVal nDisLeverPos As Integer, ByVal Horizontal As Double, ByVal Vertical As Double, ByVal YTFormat As Integer, ByVal AlreadLen As Long) As Long


