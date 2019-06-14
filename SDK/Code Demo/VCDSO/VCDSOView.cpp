// VCDSOView.cpp : implementation of the CVCDSOView class
//

#include "stdafx.h"
#include "VCDSO.h"

#include "VCDSODoc.h"
#include "VCDSOView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVCDSOView

IMPLEMENT_DYNCREATE(CVCDSOView, CView)

BEGIN_MESSAGE_MAP(CVCDSOView, CView)
	//{{AFX_MSG_MAP(CVCDSOView)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVCDSOView construction/destruction

CVCDSOView::CVCDSOView()
{
	// TODO: add construction code here

}

CVCDSOView::~CVCDSOView()
{
}

BOOL CVCDSOView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CVCDSOView drawing

void CVCDSOView::OnDraw(CDC* pDC)
{
	CVCDSODoc* pDoc = GetDocument();
	AfxMessageBox(_T("No suitble LAN device was found!"));
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CVCDSOView printing

BOOL CVCDSOView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVCDSOView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVCDSOView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CVCDSOView diagnostics

#ifdef _DEBUG
void CVCDSOView::AssertValid() const
{
	CView::AssertValid();
}

void CVCDSOView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);


}

CVCDSODoc* CVCDSOView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVCDSODoc)));
	return (CVCDSODoc*)m_pDocument;
}
#endif //_DEBUG


void CVCDSOView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();	
	// TODO: Add your specialized code here and/or call the base class
	//Init
	m_pDoc = GetDocument();
	short nDevInfo[MAX_USB_DEV_NUMBER];	
	m_pDoc->m_Hard.m_nDeviceNum = dsoHTSearchDevice(nDevInfo);
	if(m_pDoc->m_Hard.m_nDeviceNum > 0)
	{
		m_pDoc->m_Hard.Init();
		SetTimer(0,30,NULL);
	}
	else
	{
		AfxMessageBox(_T("No suitble device was found!"));
	}

}
void CVCDSOView::DrawWave(CDC* pDC,CRect Rect)
{
	int i = 0;
	//CH1/CH2/CH3/CH4
	for(i=0;i<MAX_CH_NUM;i++)
	{
		DrawWaveInYT(pDC,Rect,i);
	}
}

void CVCDSOView::DrawWaveInYT(CDC* pDC,CRect Rect,USHORT nCH)
{
	short* pData = m_pDoc->m_Hard.m_pSrcData[nCH];//源数据
	ULONG nDisDataLen = 2500;//网格内要画的数据长度
	ULONG nSrcDataLen = BUF_4K_LEN;//源数据的长度
	USHORT nDisLeverPos = m_pDoc->m_Hard.m_nLeverPos[nCH];//零电平的显示位置
	ULONG nCenterData = BUF_4K_LEN/2;//
	COLORREF clrRGB = m_pDoc->m_Hard.m_clrRGB[nCH];//颜色
	USHORT nHTriggerPos = m_pDoc->m_Hard.m_stControl.nHTriggerPos;//水平触发点位置
	USHORT nYTFormat = 0;
	USHORT nDisType = 0;//显示类型，点或线
	double dbVertical = 1.0;//
	double dbHorizontal = 1.0;
	//HTDrawWaveInYT(pDC->GetSafeHdc(),Rect,clrRGB,nDisType,pData,nSrcDataLen,nDisDataLen,nCenterData,nDisLeverPos,dbHorizontal,dbVertical,nYTFormat,m_pDoc->m_Hard.m_stControl.nAlreadyReadLen);//DLL import
 	HTDrawWaveInYT(pDC->GetSafeHdc(),Rect,clrRGB,nDisType,pData,nSrcDataLen,nDisDataLen,nCenterData,nDisLeverPos,
		dbHorizontal,dbVertical,nYTFormat,m_pDoc->m_Hard.m_stControl.nAlreadyReadLen);//DLL import
}

void CVCDSOView::DrawGrid(CDC* pDC,CRect Rect)
{
	//画网格
	HTDrawGrid(pDC->GetSafeHdc(),Rect.left,Rect.top,Rect.right,Rect.bottom,10,8,200,1);//DLL import
}

void CVCDSOView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_pDoc->CollectData();
	if(m_pDoc->m_bStartNew == TRUE)
		Invalidate();	
	CView::OnTimer(nIDEvent);
}

void CVCDSOView::OnPaint() 
{
	CPaintDC dc(this); // device context for paintin
	//return;
	// TODO: Add your message handler code here
	CRect Rect;
	GetClientRect(&Rect);
	CDC dcMem;
	CBitmap bmpMem;
	dcMem.CreateCompatibleDC(&dc);
	bmpMem.CreateCompatibleBitmap(&dc,Rect.Width(),Rect.Height());
	dcMem.SelectObject(&bmpMem);
	CRect m_rcDraw = Rect;
	m_rcDraw.DeflateRect(15,15,15,15);
	DrawGrid(&dcMem,m_rcDraw);
	
	if(m_pDoc->m_Hard.m_nDeviceNum > 0)
	{
		DrawWave(&dcMem,m_rcDraw);
	}
	dc.BitBlt(0,0,Rect.Width(),Rect.Height(),&dcMem,0,0,SRCCOPY);
	dcMem.DeleteDC();
	DeleteObject(bmpMem);
	// Do not call CView::OnPaint() for painting messages
}

BOOL CVCDSOView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return TRUE;
	
	return CView::OnEraseBkgnd(pDC);
}
