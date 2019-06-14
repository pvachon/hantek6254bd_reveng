// VCDSODoc.h : interface of the CVCDSODoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VCDSODOC_H__075741D5_45D3_407B_BB3D_D1FEF66BE19C__INCLUDED_)
#define AFX_VCDSODOC_H__075741D5_45D3_407B_BB3D_D1FEF66BE19C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Hard.h"


class CVCDSODoc : public CDocument
{
protected: // create from serialization only
	CVCDSODoc();
	DECLARE_DYNCREATE(CVCDSODoc)

// Attributes
public:
	CHard m_Hard;

	BOOL m_bStartNew;//是否启动新一次采集
	//USHORT m_nAutoTriggerCnt;

// Operations
public:
	void CollectData();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVCDSODoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVCDSODoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CVCDSODoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCDSODOC_H__075741D5_45D3_407B_BB3D_D1FEF66BE19C__INCLUDED_)
