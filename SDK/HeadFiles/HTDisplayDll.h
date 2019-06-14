#ifndef _HT_DSO_DISPLAY_H
#define _HT_DSO_DISPLAY_H

#ifndef DLL_API
#define DLL_API extern "C" __declspec(dllimport)
#endif

#define WIN_API __stdcall

DLL_API long WINAPI UserRound(double dbVal);

DLL_API void WINAPI HTDrawGridBorder(HDC hDC,int nLeft,int nTop,int nRight,int nBottom);

DLL_API void WINAPI HTDrawGrid(HDC hDC,int nLeft,int nTop,int nRight,int nBottom,USHORT nHoriGridNum,USHORT nVertGridNum,USHORT nBright,USHORT IsGrid);

DLL_API void WINAPI HTDrawKnob(HDC hDC,WORD nTotalScale,COLORREF clr,WORD Value);

DLL_API void WINAPI HTDrawRightPentagon(HDC hDC,int nCenterX,int nCenterY,COLORREF clr);

DLL_API void WINAPI HTDrawLeftPentagon(HDC hDC,int nCenterX,int nCenterY,COLORREF clr);

DLL_API void WINAPI HTDrawTopPentagon(HDC hDC,int nCenterX,int nCenterY,COLORREF clr);

DLL_API void WINAPI HTDrawBottomPentagon(HDC hDC,int nCenterX,int nCenterY,COLORREF clr);

DLL_API void WINAPI HTDrawCouplingImage(HDC hDC,int nLeftTopX,int nLeftTopY,COLORREF clr,USHORT nCoupling);

DLL_API void WINAPI HTDrawEdgeSlope(HDC hDC,int nCenterX,int nCenterY,COLORREF clr, USHORT nSlope);

DLL_API void WINAPI HTDrawPulseWidth(HDC hDC,int nCenterX,int nCenterY,COLORREF clr,USHORT nPW);

DLL_API void WINAPI HTDrawDefineText(HDC hDC,short nFontHeight,LPCTSTR lpszFontType,int nBkMode,LPCTSTR lpszStr,int nCount, int x,int y);

DLL_API void WINAPI HTDrawWaveInYT(HDC hDC,RECT Rect,COLORREF clrRGB,USHORT nDisType,short* pSrcData,ULONG nSrcDataLen,ULONG nDisDataLen,ULONG nCenterData,USHORT nDisLeverPos,double dbHorizontal,double dbVertical,USHORT nYTFormat,ULONG nScanLen);

DLL_API void WINAPI HTDrawCursorLine(HDC hDC,RECT Rect,POINT ptFirst,POINT ptSecond,USHORT nType);

DLL_API void WINAPI HTDrawCursorTraceLine(HDC hDC,RECT Rect,POINT pt);

DLL_API void WINAPI HTDrawWaveInXY(HDC hDC,RECT Rect,short* pXSrcData,short* pYSrcData,USHORT nXDisLeverPos,USHORT nYDisLeverPos,ULONG nDataLen,COLORREF clrRGB);

DLL_API void WINAPI HTDrawPrintGrid(HDC hDC,int nLeft,int nTop,int nRight,int nBottom,USHORT nHoriGridNum,USHORT nVertGridNum,USHORT nBright,USHORT IsGrid);

DLL_API void WINAPI HTDrawPrintGridBorder(HDC hDC,RECT Rect,USHORT nBright);

DLL_API void WINAPI HTDrawAcquireMode(HDC hDC,int x,int y,COLORREF clr,USHORT nMode);

DLL_API void WINAPI HTDrawWaveInYTVB(HDC hDC,int left,int top,int right, int bottom, USHORT R, USHORT G,
									  USHORT B,USHORT nDisType,short* pSrcData,ULONG nSrcDataLen,ULONG nDisDataLen,ULONG nCenterData,
									  USHORT nDisLeverPos,double dbHorizontal,double dbVertical,USHORT nYTFormat,ULONG nScanLen);

DLL_API void WINAPI HTDrawSquareWaveInYT(HDC hDC,RECT Rect,COLORREF clrRGB,USHORT nDisType,short* pSrcData,ULONG nSrcDataLen,ULONG nDisDataLen,ULONG nCenterData,USHORT nDisLeverPos,double dbHorizontal,double dbVertical,USHORT nYTFormat,ULONG nScanLen);

DLL_API void WINAPI HTDrawGeneratorRect(HDC hDC,int nLeft,int nTop,int nRight,int nBottom);

DLL_API void WINAPI HTDrawLevel(HDC hDC,int nCenterX,int nCenterY,COLORREF clr, USHORT nLevel);

DLL_API void WINAPI HTDrawMeasLine(HDC hDC,RECT Rect,POINT ptFirst,USHORT nType);



//Logic
DLL_API void WINAPI HTDrawGridLA(HDC hDC,int nLeft,int nTop,int nRight,int nBottom,USHORT nHoriGridNum,USHORT nVertGridNum,USHORT nBright,USHORT IsGrid);
DLL_API void WINAPI HTDrawGroupGridLA(HDC hDC,int nLeft,int nTop,int nRight,int nBottom,USHORT nHoriGridNum,USHORT nVertGridNum,USHORT nBright,USHORT IsGrid);
DLL_API void WINAPI HTDrawLASquareSignal(HDC hDC,CONST RECT* lpRect,COLORREF SignalColor,ULONG* pData,ULONG nDataLen,ULONG nCenterData,double fPT,ULONG nBit);

//add by yt 20120317
DLL_API void WINAPI HTDrawGridNew(HDC hDC,int nLeft,int nTop,int nRight,int nBottom,USHORT nHoriGridNum,USHORT nVertGridNum,USHORT nBright,USHORT IsGrid);
DLL_API void WINAPI HTDrawWaveInXYNew(HDC hDC,RECT Rect,short* pXSrcData,short* pYSrcData,USHORT nXDisLeverPos,USHORT nYDisLeverPos,ULONG nDataLen,COLORREF clrRGB);



DLL_API void WINAPI HTDrawWaveInYTNew(HDC hDC,RECT Rect,COLORREF clrRGB,USHORT nDisType,short* pSrcData,ULONG nSrcDataLen,ULONG nDisDataLen,__int64 nCenterData,USHORT nDisLeverPos,double dbHorizontal,double dbVertical,USHORT nYTFormat,ULONG nScanLen);

//add by yt 20120723
DLL_API void WINAPI HTDrawGridARB(HDC hDC,int nLeft,int nTop,int nRight,int nBottom,USHORT nHoriGridNum,USHORT nVertGridNum,USHORT nBright,USHORT IsGrid);

DLL_API void WINAPI HTDrawEllipse(HDC hDC,int left,int top,int width,int height,COLORREF color);//add by zhang
#endif
