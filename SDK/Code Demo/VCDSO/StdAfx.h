// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__336356C1_85E9_445D_975B_E43ACC6F0A81__INCLUDED_)
#define AFX_STDAFX_H__336356C1_85E9_445D_975B_E43ACC6F0A81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls

#include <math.h>
#include "..\\..\\HeadFiles\\DefMacro.h"
#include "..\\..\\HeadFiles\\HTSoftDll.h"
#include "..\\..\\HeadFiles\\HTDisplayDll.h"
#include "..\\..\\HeadFiles\\HTHardDll.h"


//导入画图DLL
#pragma comment(lib,"..\\..\\Lib\\HTDisplayDll.lib")
//导入操作硬件DLL
#pragma comment(lib,"..\\..\\Lib\\HTHardDll.lib")
//


#define MAX_DATA					255
#define BUF_10K_LEN					10240
#define CH1							0
#define CH2							1
#define CH3							2
#define CH4							3
#define MAX_CH_NUM					4
//#define CAL_LEVEL_LEN				72
#define DC							0
#define AC							1
#define GND							2
#define X1							0
#define X10							1
#define X100						2
#define X1000						3
#define EDGE						0
#define RISE						0
#define FALL						1
#define AUTO						0
#define NORMAL						1
#define SINGLE						2

#endif // _AFX_NO_AFXCMN_SUPPORT


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__336356C1_85E9_445D_975B_E43ACC6F0A81__INCLUDED_)
