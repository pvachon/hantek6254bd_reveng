// VCDSODoc.cpp : implementation of the CVCDSODoc class
//

#include "stdafx.h"
#include "VCDSO.h"

#include "VCDSODoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVCDSODoc

IMPLEMENT_DYNCREATE(CVCDSODoc, CDocument)

BEGIN_MESSAGE_MAP(CVCDSODoc, CDocument)
	//{{AFX_MSG_MAP(CVCDSODoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVCDSODoc construction/destruction

CVCDSODoc::CVCDSODoc()
{
	// TODO: add one-time construction code here

}

CVCDSODoc::~CVCDSODoc()
{
}

BOOL CVCDSODoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CVCDSODoc serialization

void CVCDSODoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CVCDSODoc diagnostics

#ifdef _DEBUG
void CVCDSODoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVCDSODoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

void CVCDSODoc::CollectData()
{
	short nState = 0;

	if(m_bStartNew)
	{
		WORD nStartControl=0;
		nStartControl|=((m_Hard.m_nTriggerSweep==AUTO)?0x01:0);//add by zhang
		nStartControl|=((m_Hard.m_nYTFormat== YT_ROLL)?0x02:0);//add by zhang
		nStartControl|=m_Hard.m_bCollect?0:0x04;//add by zhang
		dsoHTStartCollectData(m_Hard.m_nDeviceIndex,nStartControl);
	//	dsoHTStartTrigger(m_Hard.m_nDeviceIndex);
//		m_nAutoTriggerCnt = 0;
		m_bStartNew = FALSE;
	}
	nState = dsoHTGetState(m_Hard.m_nDeviceIndex);
	if(nState&0x02)	
	{
		m_Hard.ReadData();
		m_bStartNew = TRUE;		
		
	}else{
		m_bStartNew = FALSE;	
	}
}
/////////////////////////////////////////////////////////////////////////////
// CVCDSODoc commands
