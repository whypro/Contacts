#if !defined(AFX_PROVINCESET_H__6B88AE0C_68A6_459E_B218_529A38FC441C__INCLUDED_)
#define AFX_PROVINCESET_H__6B88AE0C_68A6_459E_B218_529A38FC441C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ProvinceSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CProvinceSet recordset
#include "afxdb.h"
class CProvinceSet : public CRecordset
{
public:
	CProvinceSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CProvinceSet)

// Field/Param Data
	//{{AFX_FIELD(CProvinceSet, CRecordset)
	long	m_province_id;
	CString	m_province_name;
	CString	m_province_type;
	CString	m_province_state;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProvinceSet)
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

#endif // !defined(AFX_PROVINCESET_H__6B88AE0C_68A6_459E_B218_529A38FC441C__INCLUDED_)
