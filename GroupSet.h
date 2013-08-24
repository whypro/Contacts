#if !defined(AFX_GROUPSET_H__AC41331F_1545_406D_99C7_FA581EA68A00__INCLUDED_)
#define AFX_GROUPSET_H__AC41331F_1545_406D_99C7_FA581EA68A00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GroupSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGroupSet recordset
#include "afxdb.h"
class CGroupSet : public CRecordset
{
public:
	CGroupSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CGroupSet)

// Field/Param Data
	//{{AFX_FIELD(CGroupSet, CRecordset)
	long	m_group_id;
	CString	m_group_name;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGroupSet)
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

#endif // !defined(AFX_GROUPSET_H__AC41331F_1545_406D_99C7_FA581EA68A00__INCLUDED_)
