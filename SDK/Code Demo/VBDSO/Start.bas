Attribute VB_Name = "Start"

Sub Main()
    Dim DevInfo(63) As Integer
    Dim result As Long
    Dim ip(4) As Integer
    InitializeVariables '初始化变量
    DeviceNum = dsoHTSearchDevice(DevInfo(0))
    If DeviceNum = 0 Then
        MsgBox ("DSO not found!")
        End
    End If
    InitHard '初始化硬件
    MainForm.Visible = True
    MainForm.GetDataLoop.Enabled = True
End Sub

Public Sub InitializeVariables()
Dim i As Long
    i = 0
    DeviceNum = 0
    DeviceIndex = 0 '设备索引值
    LeverPos(0) = 192 'CH1位置
    LeverPos(1) = 160    'CH2位置
    LeverPos(2) = 96   'CH3位置
    LeverPos(3) = 64   'CH4位置
    TimeDIV = 11 '时基索引值
    YTFormat = 0    'YT模式
    stControl.nCHSet = 15 '16进制下是0x0F表示4个通道全部打开
    stControl.nTimeDiv = TimeDIV
    stControl.nTriggerSource = 0 '触发源
    stControl.nHTriggerPos = 50 '水平触发位置
    stControl.nVTriggerPos = LeverPos(0) '垂直触发位置
    stControl.nTriggerSlope = 0 '以上升沿作为触发方式
    stControl.nBufferLen = 4096 ' 采集数据的长度
    stControl.nReadDataLen = 4096 ' 读取数据的长度
    stControl.nAlreadyReadLen = 0 ' 已经读取的长度，仅在扫描滚动使用
    DisLen = 2500 '屏幕显示总点数
    stControl.nALT = 0 '是否交替触发注意交替触发是软件功能
    For i = 0 To 3
        rcRelayControl.bCHEnable(i) = 1 '开启通道
        rcRelayControl.nCHVoltDIV(i) = 8 '设置电压档位
        rcRelayControl.nCHCoupling(i) = 1 '设计耦合模式 AC/DC
        rcRelayControl.bCHBWLimit(i) = 0 '是否开启20M滤波
    Next i
    rcRelayControl.nTrigSource = stControl.nTriggerSource
    rcRelayControl.bTrigFilt = 0
    rcRelayControl.nALT = stControl.nALT
    TriggerMode = 0 '边沿触发
    TriggerSlope = 0 '边沿触发的触发源
    TriggerSweep = 0 '自动触发
    ReadOK = 0
    StartNew = True
    ForceTriggerCnt = 0
    Collect = 1
    For i = 0 To 578
        pAmpLevel(i) = 1024 '给硬件下1024，实际上1024表示1.0，即不做修正
    Next i
    
End Sub


Public Sub InitHard()
    Dim result As Long
    DeviceIndex = 0
    Dim i As Integer
    Dim nVolt As Integer
    result = dsoSetUSBBus(DeviceIndex) '链接后调用的第一个函数
    result = dsoInitHard(DeviceIndex) ' 硬件连接后调用的第二个函数
    result = dsoHTADCCHModGain(DeviceIndex, 4) '设置模拟端幅度修正
    result = dsoHTReadCalibrationData(DeviceIndex, CalLevel(0), 577) '读取零电平校准数据
    If (CalLevel(576) And &HFFFF) <> &HFBCF Then '如果没有校准数据载入默认
        For i = 0 To 576
            nVolt = (i Mod 144) / 12
            If (nVolt = 5 Or nVolt = 8 Or nVolt = 11) Then
                Dim nTemp As Integer
                nTemp = (i Mod 144) Mod 12
                If nTemp = 0 Then
                    CalLevel(i) = 16602
                ElseIf nTemp = 1 Then
                    CalLevel(i) = 60111
                ElseIf nTemp = 2 Then
                    CalLevel(i) = 17528
                ElseIf nTemp = 3 Then
                    CalLevel(i) = 59201
                ElseIf nTemp = 4 Then
                    CalLevel(i) = 17710
                ElseIf nTemp = 5 Then
                    CalLevel(i) = 58900
                Else
                    CalLevel(i) = 0
                End If
            End If
        Next i
    End If
    result = dsoHTSetSampleRate(DeviceIndex, pAmpLevel(0), YTFormat, rcRelayControl, stControl) '设置采样率
    result = dsoHTSetCHAndTrigger(DeviceIndex, rcRelayControl, stControl.nTimeDiv) '设置通道开关和电压档位
    result = dsoHTSetRamAndTrigerControl(DeviceIndex, (stControl.nTimeDiv), (stControl.nCHSet), (stControl.nTriggerSource), 0) '设置触发源
    For i = 0 To 3
        result = dsoHTSetCHPos(DeviceIndex, CalLevel(0), rcRelayControl.nCHVoltDIV(i), LeverPos(i), i, 4) '设置通道垂直位置
    Next i

    result = dsoHTSetVTriggerLevel(DeviceIndex, LeverPos(0), 4) '设置触发垂直位置与通道1相同
    If TriggerMode = 0 Then 'EDGE
        result = dsoHTSetTrigerMode(DeviceIndex, TriggerMode, stControl.nTriggerSlope, 0) '如果是边沿触发调用此函数
    End If
End Sub


Public Sub CollectData()
    Dim nState As Long
    Dim result As Long
    If (StartNew) Then
        Dim nStartControl As Integer
        nStartControl = 0
        nStartControl = nStartControl + IIf(TriggerSweep = 0, 1, 0)
        nStartControl = nStartControl + IIf(YTFormat = 0, 0, 2)
        nStartControl = nStartControl + IIf(Collect = 1, 0, 4)
        result = dsoHTStartCollectData(DeviceIndex, nStartControl)
        StartNew = False
   End If
    nState = dsoHTGetState(DeviceIndex)
    If (nState And 2) = 2 Then ' 采集结束侧开始读数据
        ReadData
        StartNew = True
    Else
        
        StartNew = False
            
    End If
End Sub

Public Sub ReadData()
    Dim i As Long
    
    Dim result As Integer
    Dim CH1ReadData(4096) As Integer
    Dim CH2ReadData(4096) As Integer
    Dim CH3ReadData(4096) As Integer
    Dim CH4ReadData(4096) As Integer
    result = dsoHTGetData(DeviceIndex, CH1ReadData(0), CH2ReadData(0), CH3ReadData(0), CH4ReadData(0), stControl) '每通道1第j个点的实际电压值=(CH1ReadData[j]-LeverPos(0))*8*电压值/255
    If result = 1 Then
        For i = 0 To stControl.nReadDataLen - 1
            CH1SrcData(i) = CH1ReadData(i) - (255 - LeverPos(0))
            CH2SrcData(i) = CH2ReadData(i) - (255 - LeverPos(1))
            CH3SrcData(i) = CH3ReadData(i) - (255 - LeverPos(2))
            CH4SrcData(i) = CH4ReadData(i) - (255 - LeverPos(3))
        Next i
    End If
End Sub




























