#if !defined(AFX_USERSET_H__7306DEE6_7E82_4223_869D_7FE910C65142__INCLUDED_)
#define AFX_USERSET_H__7306DEE6_7E82_4223_869D_7FE910C65142__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UserSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUserSet recordset
#include "afxdb.h"
class CUserSet : public CRecordset
{
public:
	CUserSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CUserSet)

// Field/Param Data
	//{{AFX_FIELD(CUserSet, CRecordset)
	CString	m_userinfo_username;
	CString	m_userinfo_password;
	CString	m_userinfo_privilege;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUserSet)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERSET_H__7306DEE6_7E82_4223_869D_7FE910C65142__INCLUDED_)
