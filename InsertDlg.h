#if !defined(AFX_INSERTDLG_H__183B2C3E_20D8_4E7B_BE90_6864AAEBBE01__INCLUDED_)
#define AFX_INSERTDLG_H__183B2C3E_20D8_4E7B_BE90_6864AAEBBE01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InsertDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInsertDlg dialog

class CInsertDlg : public CDialog
{
// Construction
public:
	CInsertDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInsertDlg)
	enum { IDD = IDD_INSERT_DIALOG };
	CEdit	m_edtPhotoPath;
	CStatic	m_imgPhoto;
	CEdit	m_edtGrade;
	CEdit	m_edtAddress;
	CEdit	m_edtQQ;
	CDateTimeCtrl	m_dtBirthdate;
	CComboBox	m_cmbCity;
	CComboBox	m_cmbProvince;
	CEdit	m_edtUniversity;
	CEdit	m_edtDepartment;
	CEdit	m_edtEmail;
	CEdit	m_edtMajor;
	CEdit	m_edtTelephone;
	CEdit	m_edtMobilephone;
	CEdit	m_edtName;
	CComboBox	m_cmbSex;
	CComboBox	m_cmbGroup;
	CComboBox	m_cmbBloodtype;
	//}}AFX_DATA

        int m_nID;
        bool isInsert;
        bool hasPhoto;
        bool needUpdatePhoto;
        CString strFileName;

        BOOL ShowJpgGif(CDC* pDC, CString strPath, int x, int y);
        void DrawBitmap(CString BitmapFilePath, CDC *pDC, CRect rect);
        void DrawBitmap(UINT bitmap, CDC *pDC, CRect rect);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInsertDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL OnInitDialog();

	// Generated message map functions
	//{{AFX_MSG(CInsertDlg)
	afx_msg void OnSelchangeProvince();
	afx_msg void OnCancel();
	afx_msg void OnInsertExec();
	afx_msg void OnUploadPhoto();
	afx_msg void OnClearPhoto();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INSERTDLG_H__183B2C3E_20D8_4E7B_BE90_6864AAEBBE01__INCLUDED_)
