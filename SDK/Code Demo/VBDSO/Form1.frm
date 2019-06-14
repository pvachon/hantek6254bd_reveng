VERSION 5.00
Begin VB.Form MainForm 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "DSO-3064 (SDK Ver1.0.2)"
   ClientHeight    =   6645
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   10485
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   6645
   ScaleWidth      =   10485
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  'CenterScreen
   Begin VB.Timer GetDataLoop 
      Interval        =   50
      Left            =   9360
      Top             =   5880
   End
   Begin VB.PictureBox BackPicture 
      BackColor       =   &H80000001&
      BeginProperty Font 
         Name            =   "ËÎÌו"
         Size            =   9
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   6840
      Left            =   0
      ScaleHeight     =   6780
      ScaleWidth      =   10560
      TabIndex        =   0
      Top             =   0
      Width           =   10620
      Begin VB.PictureBox DisplayPicture 
         AutoRedraw      =   -1  'True
         BackColor       =   &H80000008&
         Height          =   6375
         Left            =   120
         ScaleHeight     =   421
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   677
         TabIndex        =   1
         Top             =   120
         Width           =   10215
      End
   End
End
Attribute VB_Name = "MainForm"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Private Sub GetDataLoop_Timer()
    Dim Grid As RECT
    Grid.Left = 15
    Grid.Top = 15
    Grid.Right = MainForm.DisplayPicture.ScaleWidth - 15
    Grid.Bottom = MainForm.DisplayPicture.ScaleHeight - 15
    DrawGrid
   CollectData
   result = HTDrawWaveInYTVB(MainForm.DisplayPicture.hDC, 15, 15, MainForm.DisplayPicture.ScaleWidth - 15, MainForm.DisplayPicture.ScaleHeight - 15, 255, 255, 0, 0, CH1SrcData(0), stControl.nReadDataLen, DisLen, stControl.nReadDataLen / 2, LeverPos(0), 1#, 1#, 0, stControl.nAlreadyReadLen)
   result = HTDrawWaveInYTVB(MainForm.DisplayPicture.hDC, 15, 15, MainForm.DisplayPicture.ScaleWidth - 15, MainForm.DisplayPicture.ScaleHeight - 15, 0, 255, 255, 0, CH2SrcData(0), stControl.nReadDataLen, DisLen, stControl.nReadDataLen / 2, LeverPos(1), 1#, 1#, 0, stControl.nAlreadyReadLen)
   result = HTDrawWaveInYTVB(MainForm.DisplayPicture.hDC, 15, 15, MainForm.DisplayPicture.ScaleWidth - 15, MainForm.DisplayPicture.ScaleHeight - 15, 255, 0, 255, 0, CH3SrcData(0), stControl.nReadDataLen, DisLen, stControl.nReadDataLen / 2, LeverPos(2), 1#, 1#, 0, stControl.nAlreadyReadLen)
   result = HTDrawWaveInYTVB(MainForm.DisplayPicture.hDC, 15, 15, MainForm.DisplayPicture.ScaleWidth - 15, MainForm.DisplayPicture.ScaleHeight - 15, 0, 255, 0, 0, CH4SrcData(0), stControl.nReadDataLen, DisLen, stControl.nReadDataLen / 2, LeverPos(3), 1#, 1#, 0, stControl.nAlreadyReadLen)
'HTDrawWaveInYTVB(HDC hDC,int left,int top,int right, int bottom, USHORT R, USHORT G,
                                   '   USHORT B,USHORT nDisType,short* pSrcData,ULONG nSrcDataLen,ULONG nDisDataLen,ULONG nCenterData,
                                    '  USHORT nDisLeverPos,double dbHorizontal,double dbVertical,USHORT nYTFormat,ULONG nScanLen);
'HTDrawWaveInYT(HDC hDC,RECT Rect,COLORREF clrRGB,USHORT nDisType,short* pSrcData,ULONG nSrcDataLen,ULONG nDisDataLen,ULONG nCenterData,USHORT nDisLeverPos,double dbHorizontal,double dbVertical,USHORT nYTFormat,ULONG nScanLen);

'HTDrawWaveInYT(pDC->GetSafeHdc(),Rect,clrRGB,nDisType,pData,nSrcDataLen,nDisDataLen,nCenterData,nDisLeverPos,dbHorizontal,dbVertical,nYTFormat,m_pDoc->m_Hard.m_stControl.nAlreadyReadLen);//DLL import
End Sub

Public Sub DrawGrid()
    Dim result As Long
    MainForm.DisplayPicture.Cls
    result = HTDrawGrid(MainForm.DisplayPicture.hDC, 15, 15, MainForm.DisplayPicture.ScaleWidth - 15, MainForm.DisplayPicture.ScaleHeight - 15, 10, 8, 200, 1)
End Sub
