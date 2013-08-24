#if !defined(AFX_GROUPDLG_H__27895EC0_1B1D_433E_88C7_2511C3018C7D__INCLUDED_)
#define AFX_GROUPDLG_H__27895EC0_1B1D_433E_88C7_2511C3018C7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GroupDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGroupDlg dialog

class CGroupDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CGroupDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGroupDlg)
	enum { IDD = IDD_GROUP_DIALOG };
	CListCtrl	m_listGroup;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGroupDlg)
	afx_msg void OnGroupAdd();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GROUPDLG_H__27895EC0_1B1D_433E_88C7_2511C3018C7D__INCLUDED_)
