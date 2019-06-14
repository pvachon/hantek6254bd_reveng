// VCDSOView.h : interface of the CVCDSOView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VCDSOVIEW_H__278BDDB4_F814_4D01_808F_57D5CA93233E__INCLUDED_)
#define AFX_VCDSOVIEW_H__278BDDB4_F814_4D01_808F_57D5CA93233E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CVCDSOView : public CView
{
protected: // create from serialization only
	CVCDSOView();
	DECLARE_DYNCREATE(CVCDSOView)

// Attributes
public:
	CVCDSODoc* GetDocument();
	CVCDSODoc* m_pDoc;
	CRect m_rcGrid;

// Operations
public:
	void DrawWave(CDC* pDC,CRect Rect);
	void DrawWaveInYT(CDC* pDC,CRect Rect,USHORT nCH);
	void DrawGrid(CDC* pDC,CRect Rect);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVCDSOView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVCDSOView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVCDSOView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VCDSOView.cpp
inline CVCDSODoc* CVCDSOView::GetDocument()
   { return (CVCDSODoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCDSOVIEW_H__278BDDB4_F814_4D01_808F_57D5CA93233E__INCLUDED_)
