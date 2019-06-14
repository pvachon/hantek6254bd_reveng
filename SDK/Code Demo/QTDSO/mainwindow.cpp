#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLibrary>
#include <QPaintEvent>
#define LEFT_MARGIN 16
#define RIGHT_MARGIN 16
#define TOP_MARGIN 16
#define BOTTOM_MARGIN 16
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    hard.Init();
    setBackgroundRole(QPalette::Dark);
    setAutoFillBackground(true);
    setAttribute(Qt::WA_PaintOnScreen);
    colletdata.setInterval(500);
    colletdata.start();
    m_GridPixmap=QPixmap(size()-QSize(LEFT_MARGIN+RIGHT_MARGIN,TOP_MARGIN+BOTTOM_MARGIN));
    connect(&colletdata,SIGNAL(timeout()),this,SLOT(timeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::timeout()
{
    hard.ReadData();
    QRect Rect;
    Rect.setLeft(LEFT_MARGIN);
    Rect.setTop(TOP_MARGIN);
    Rect.setSize(size()-QSize(LEFT_MARGIN+RIGHT_MARGIN,TOP_MARGIN+BOTTOM_MARGIN));
    if(hard.m_bDraw)
    {
        update();
    }

}
void MainWindow::DrawWave()
{
    int i = 0;
    HWND hWin=(HWND)this->winId();
    HDC  hDC=GetDC(hWin);
    QRect Rect;
    Rect.setLeft(LEFT_MARGIN);
    Rect.setTop(TOP_MARGIN);
    Rect.setSize(size()-QSize(LEFT_MARGIN+RIGHT_MARGIN,TOP_MARGIN+BOTTOM_MARGIN));
    DrawGrid(hDC,Rect);
    for(i=0;i<4;i++)
    {
        DrawWaveInYT(hDC,Rect,i);
    }
}

void MainWindow::DrawWaveInYT(HDC hDC,QRect Rect,USHORT nCH)
{
    short* pData = hard.m_pSrcData[nCH];//源数据
    ULONG nDisDataLen = 2500;//网格内要画的数据长度
    ULONG nSrcDataLen = BUF_4K_LEN;//源数据的长度
    USHORT nDisLeverPos = 128;//m_pDoc->m_Hard.m_nLeverPos[nCH];//零电平的显示位置
    ULONG nCenterData = BUF_4K_LEN/2;//
    COLORREF clrRGB = hard.m_clrRGB[nCH];//颜色
    USHORT nHTriggerPos = hard.m_stControl.nHTriggerPos;//水平触发点位置
    USHORT nYTFormat = 0;
    USHORT nDisType = 0;//显示类型，点或线
    double dbVertical = 1.0;//
    double dbHorizontal = 1.0;
    //HTDrawWaveInYTVB(HDC hDC,int left,int top,int right, int bottom, USHORT R, USHORT G,
    //                                       USHORT B,USHORT nDisType,short* pSrcData,ULONG nSrcDataLen,ULONG nDisDataLen,ULONG nCenterData,
    //                                     USHORT nDisLeverPos,double dbHorizontal,double dbVertical,USHORT nYTFormat,ULONG nScanLen);

    QLibrary hardLib("HTDisplayDll.dll");
    typedef WORD (*MyPrototype8)(HDC,int,int,int,int, USHORT,USHORT,
                                 USHORT,USHORT,short*,ULONG,ULONG,ULONG ,
                                 USHORT,double,double,USHORT,ULONG);
    MyPrototype8 myFunction8 = (MyPrototype8) hardLib.resolve("HTDrawWaveInYTVB");
    short *p=hard.m_pSrcData[nCH];
    myFunction8(hDC,15,15,Rect.width(),Rect.height(),USHORT(255&clrRGB),(USHORT)((clrRGB>>8)&255),
                (USHORT)((clrRGB>>16)&255),0,hard.m_pSrcData[nCH],(ULONG)4096,(ULONG)2500,(ULONG)2048,
                hard.m_nLeverPos[nCH],(double)1.0,(double)1.0,(USHORT)0,(ULONG)0);
}

void MainWindow::DrawGrid(HDC hDC,QRect Rect)
{
    //画网格
    QLibrary hardLib("HTDisplayDll.dll");
    typedef WORD (*MyPrototype88)(HDC,int,int,int,int, USHORT,USHORT,USHORT,USHORT);
    MyPrototype88 myFunction88 = (MyPrototype88) hardLib.resolve("HTDrawGrid");
    myFunction88(hDC,Rect.left(),Rect.top(),Rect.right(),Rect.bottom(),(USHORT)10,(USHORT)8,(USHORT)200,(USHORT)1);//DLL import
}
void MainWindow::paintEvent(QPaintEvent *e)
{
    if(hard.m_bDraw)
    {
        DrawWave();
        hard.m_bDraw=false;
        hard.m_bStartC=true;
    }
    {
        e->ignore();
    }
}
void MainWindow::resizeEvent(QResizeEvent *e)
{
    DrawWave();
}
