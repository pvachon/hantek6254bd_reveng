Attribute VB_Name = "DeclareGlobalVal"
Type RelayControl 'Ïê¼ûSDK_HTHardDll_CHS.pdf
    bCHEnable(3) As Long
    nCHVoltDIV(3) As Integer
    nCHCoupling(3) As Long
    bCHBWLimit(3) As Integer
    nTrigSource As Integer
    bTrigFilt As Long
    nALT As Integer
End Type

Type CONTROLDATA 'SDK_HTSoftDll_CHS.pdf
        
    nCHSet As Integer
    nTimeDiv As Integer
    nTriggerSource As Integer
    nHTriggerPos As Integer
    nVTriggerPos As Integer
    nTriggerSlope As Integer
    nBufferLen As Long
    nReadDataLen As Long
    nAlreadyReadLen As Long
    nALT As Integer
    nETSOpen As Integer
    nDriverCode As Integer
    nLastAddress As Long
End Type

Type COLORREF
    R As Integer
    G As Integer
    B As Integer
End Type

Type RECT
    Left As Integer
    Top As Integer
    Right As Integer
    Bottom As Integer
End Type
'''''''''''''

Public DeviceNum As Long
Public DeviceIndex As Integer
Public CH1SrcData(4096) As Integer
Public CH2SrcData(4096) As Integer
Public CH3SrcData(4096) As Integer
Public CH4SrcData(4096) As Integer
Public CH1Color As COLORREF
Public CH2Color As COLORREF
Public CH3Color As COLORREF
Public CH4Color As COLORREF
Public CalLevel(578) As Integer
Public TimeDIV As Integer
Public YTFormat As Integer
Public stControl As CONTROLDATA
Public rcRelayControl As RelayControl
Public TriggerMode As Integer
Public TriggerSweep As Integer
Public TriggerSlope As Integer
Public LeverPos(3) As Integer
Public ReadOK As Long
Public StartNew As Boolean
Public DisLen As Long
Public Collect As Integer
Public pAmpLevel(578) As Integer
