Attribute VB_Name = "Start"

Sub Main()
    Dim DevInfo(63) As Integer
    Dim result As Long
    Dim ip(4) As Integer
    InitializeVariables '��ʼ������
    DeviceNum = dsoHTSearchDevice(DevInfo(0))
    If DeviceNum = 0 Then
        MsgBox ("DSO not found!")
        End
    End If
    InitHard '��ʼ��Ӳ��
    MainForm.Visible = True
    MainForm.GetDataLoop.Enabled = True
End Sub

Public Sub InitializeVariables()
Dim i As Long
    i = 0
    DeviceNum = 0
    DeviceIndex = 0 '�豸����ֵ
    LeverPos(0) = 192 'CH1λ��
    LeverPos(1) = 160    'CH2λ��
    LeverPos(2) = 96   'CH3λ��
    LeverPos(3) = 64   'CH4λ��
    TimeDIV = 11 'ʱ������ֵ
    YTFormat = 0    'YTģʽ
    stControl.nCHSet = 15 '16��������0x0F��ʾ4��ͨ��ȫ����
    stControl.nTimeDiv = TimeDIV
    stControl.nTriggerSource = 0 '����Դ
    stControl.nHTriggerPos = 50 'ˮƽ����λ��
    stControl.nVTriggerPos = LeverPos(0) '��ֱ����λ��
    stControl.nTriggerSlope = 0 '����������Ϊ������ʽ
    stControl.nBufferLen = 4096 ' �ɼ����ݵĳ���
    stControl.nReadDataLen = 4096 ' ��ȡ���ݵĳ���
    stControl.nAlreadyReadLen = 0 ' �Ѿ���ȡ�ĳ��ȣ�����ɨ�����ʹ��
    DisLen = 2500 '��Ļ��ʾ�ܵ���
    stControl.nALT = 0 '�Ƿ��津��ע�⽻�津�����������
    For i = 0 To 3
        rcRelayControl.bCHEnable(i) = 1 '����ͨ��
        rcRelayControl.nCHVoltDIV(i) = 8 '���õ�ѹ��λ
        rcRelayControl.nCHCoupling(i) = 1 '������ģʽ AC/DC
        rcRelayControl.bCHBWLimit(i) = 0 '�Ƿ���20M�˲�
    Next i
    rcRelayControl.nTrigSource = stControl.nTriggerSource
    rcRelayControl.bTrigFilt = 0
    rcRelayControl.nALT = stControl.nALT
    TriggerMode = 0 '���ش���
    TriggerSlope = 0 '���ش����Ĵ���Դ
    TriggerSweep = 0 '�Զ�����
    ReadOK = 0
    StartNew = True
    ForceTriggerCnt = 0
    Collect = 1
    For i = 0 To 578
        pAmpLevel(i) = 1024 '��Ӳ����1024��ʵ����1024��ʾ1.0������������
    Next i
    
End Sub


Public Sub InitHard()
    Dim result As Long
    DeviceIndex = 0
    Dim i As Integer
    Dim nVolt As Integer
    result = dsoSetUSBBus(DeviceIndex) '���Ӻ���õĵ�һ������
    result = dsoInitHard(DeviceIndex) ' Ӳ�����Ӻ���õĵڶ�������
    result = dsoHTADCCHModGain(DeviceIndex, 4) '����ģ��˷�������
    result = dsoHTReadCalibrationData(DeviceIndex, CalLevel(0), 577) '��ȡ���ƽУ׼����
    If (CalLevel(576) And &HFFFF) <> &HFBCF Then '���û��У׼��������Ĭ��
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
    result = dsoHTSetSampleRate(DeviceIndex, pAmpLevel(0), YTFormat, rcRelayControl, stControl) '���ò�����
    result = dsoHTSetCHAndTrigger(DeviceIndex, rcRelayControl, stControl.nTimeDiv) '����ͨ�����غ͵�ѹ��λ
    result = dsoHTSetRamAndTrigerControl(DeviceIndex, (stControl.nTimeDiv), (stControl.nCHSet), (stControl.nTriggerSource), 0) '���ô���Դ
    For i = 0 To 3
        result = dsoHTSetCHPos(DeviceIndex, CalLevel(0), rcRelayControl.nCHVoltDIV(i), LeverPos(i), i, 4) '����ͨ����ֱλ��
    Next i

    result = dsoHTSetVTriggerLevel(DeviceIndex, LeverPos(0), 4) '���ô�����ֱλ����ͨ��1��ͬ
    If TriggerMode = 0 Then 'EDGE
        result = dsoHTSetTrigerMode(DeviceIndex, TriggerMode, stControl.nTriggerSlope, 0) '����Ǳ��ش������ô˺���
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
    If (nState And 2) = 2 Then ' �ɼ������࿪ʼ������
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
    result = dsoHTGetData(DeviceIndex, CH1ReadData(0), CH2ReadData(0), CH3ReadData(0), CH4ReadData(0), stControl) 'ÿͨ��1��j�����ʵ�ʵ�ѹֵ=(CH1ReadData[j]-LeverPos(0))*8*��ѹֵ/255
    If result = 1 Then
        For i = 0 To stControl.nReadDataLen - 1
            CH1SrcData(i) = CH1ReadData(i) - (255 - LeverPos(0))
            CH2SrcData(i) = CH2ReadData(i) - (255 - LeverPos(1))
            CH3SrcData(i) = CH3ReadData(i) - (255 - LeverPos(2))
            CH4SrcData(i) = CH4ReadData(i) - (255 - LeverPos(3))
        Next i
    End If
End Sub




























