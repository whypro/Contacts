#if !defined(AFX_QUERYDLG_H__9E5679A4_4FE9_455E_A9E1_A4D7F097B791__INCLUDED_)
#define AFX_QUERYDLG_H__9E5679A4_4FE9_455E_A9E1_A4D7F097B791__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// QueryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog

class CQueryDlg : public CDialog
{
// Construction
public:
	BOOL OnInitDialog();
	CQueryDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CQueryDlg)
	enum { IDD = IDD_QUERY_DIALOG };
	CEdit	m_edtQueryFilter;
	CComboBox	m_cmbQueryMethod;
	CListCtrl	m_resultList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CQueryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CQueryDlg)
	afx_msg void OnQueryExec();
	afx_msg void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_QUERYDLG_H__9E5679A4_4FE9_455E_A9E1_A4D7F097B791__INCLUDED_)
