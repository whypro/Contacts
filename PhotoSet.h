#if !defined(AFX_PHOTOSET_H__B0E60D46_D528_470B_9165_4F87EBCC3946__INCLUDED_)
#define AFX_PHOTOSET_H__B0E60D46_D528_470B_9165_4F87EBCC3946__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PhotoSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPhotoSet recordset
#include "afxdb.h"
class CPhotoSet : public CRecordset
{
public:
	CPhotoSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPhotoSet)

// Field/Param Data
	//{{AFX_FIELD(CPhotoSet, CRecordset)
	long	m_photo_id;
	long	m_photo_person_id;
	CString	m_photo_title;
	CString	m_photo_type;
	CLongBinary	m_photo_data;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPhotoSet)
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

#endif // !defined(AFX_PHOTOSET_H__B0E60D46_D528_470B_9165_4F87EBCC3946__INCLUDED_)
