// ContactsDlg.h : header file
//

#if !defined(AFX_CONTACTSDLG_H__9C1F0ACD_05B1_4C29_816D_6A528E903E06__INCLUDED_)
#define AFX_CONTACTSDLG_H__9C1F0ACD_05B1_4C29_816D_6A528E903E06__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ContactsSet.h"
class CContactsDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CContactsDlg dialog

class CContactsDlg : public CDialog
{
	DECLARE_DYNAMIC(CContactsDlg);
	friend class CContactsDlgAutoProxy;

// Construction
public:
	BOOL PreTranslateMessage(MSG* pMsg);
	CString strTemp;
	CString GetFirstLetter(LPCTSTR strName);
	void RefreshData();
	CContactsDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CContactsDlg();

// Dialog Data
	//{{AFX_DATA(CContactsDlg)
	enum { IDD = IDD_CONTACTS_DIALOG };
	CEdit	m_edtSearch;
	CListCtrl	m_recordList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CContactsDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CContactsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnRecordInsert();
	afx_msg void OnRecordQuery();
	afx_msg void OnRecordDelete();
	afx_msg void OnRecordModify();
	afx_msg void OnSetfocusQuickSearch();
	afx_msg void OnChangeQuickSearch();
	afx_msg void OnKillfocusQuickSearch();
	afx_msg void OnDblclkRecordList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKeydownRecordList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuNewRecord();
	afx_msg void OnMenuModify();
	afx_msg void OnMenuDelete();
	afx_msg void OnMenuAbout();
	afx_msg void OnMenuQuery();
	afx_msg void OnRclickRecordList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuRefresh();
	afx_msg void OnMenuNewGroup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTACTSDLG_H__9C1F0ACD_05B1_4C29_816D_6A528E903E06__INCLUDED_)
