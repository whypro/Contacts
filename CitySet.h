#if !defined(AFX_CITYSET_H__F9194438_CDDD_47F8_AE99_D30B7F439D74__INCLUDED_)
#define AFX_CITYSET_H__F9194438_CDDD_47F8_AE99_D30B7F439D74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CitySet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCitySet recordset
#include "afxdb.h"
class CCitySet : public CRecordset
{
public:
	CCitySet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCitySet)

// Field/Param Data
	//{{AFX_FIELD(CCitySet, CRecordset)
	long	m_city_id;
	CString	m_city_name;
	long	m_city_province_id;
	CString	m_city_state;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCitySet)
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

#endif // !defined(AFX_CITYSET_H__F9194438_CDDD_47F8_AE99_D30B7F439D74__INCLUDED_)
