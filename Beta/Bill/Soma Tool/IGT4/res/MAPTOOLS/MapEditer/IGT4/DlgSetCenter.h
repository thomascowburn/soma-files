#if !defined(AFX_SETCENTERDLG_H__922E4522_50CD_11D3_9559_00C026EE03FC__INCLUDED_)
#define AFX_SETCENTERDLG_H__922E4522_50CD_11D3_9559_00C026EE03FC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSetCenter.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSetCenter dialog
#include "Resource.h"

class CDlgSetCenter : public CDialog
{
// Construction
public:
	CDlgSetCenter(CWnd* pParent = NULL);   // standard constructor
	~CDlgSetCenter();

	CPoint GetCenter();
// Dialog Data
	//{{AFX_DATA(CDlgSetCenter)
	enum { IDD = IDD_SET_CENTER };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetCenter)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CPoint m_ptCenter; // 센터점..
	CRect m_rcDefaultClient; // 처음 클라이언트 영역

	LPDIRECTDRAWSURFACE m_lpdds; // 프리뷰 서피스..

	// Generated message map functions
	//{{AFX_MSG(CDlgSetCenter)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnClose();
	afx_msg void OnPaint();
	afx_msg void OnViewPicture();
	afx_msg void OnChangeCenterX();
	afx_msg void OnChangeCenterY();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCENTERDLG_H__922E4522_50CD_11D3_9559_00C026EE03FC__INCLUDED_)
