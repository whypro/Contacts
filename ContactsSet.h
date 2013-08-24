#if !defined(AFX_CONTACTSSET_H__A7CB6126_8719_4567_A555_6263408FCB9A__INCLUDED_)
#define AFX_CONTACTSSET_H__A7CB6126_8719_4567_A555_6263408FCB9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ContactsSet.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CContactsSet recordset
#include "afxdb.h"
class CContactsSet : public CRecordset
{
public:
	CContactsSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CContactsSet)

// Field/Param Data
	//{{AFX_FIELD(CContactsSet, CRecordset)
	long	m_person_id;
	CString	m_person_name;
	CString	m_person_sex;
	CString	m_person_bloodtype;
	CTime	m_person_birthdate;
	CString	m_person_group;
	CString	m_person_mobilephone;
	CString	m_person_telephone;
	CString	m_person_qq;
	CString	m_person_email;
	CString	m_person_province;
	CString	m_person_city;
	CString	m_person_address;
	CString	m_person_university;
	CString	m_person_department;
	CString	m_person_major;
	CString	m_person_grade;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsSet)
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

#endif // !defined(AFX_CONTACTSSET_H__A7CB6126_8719_4567_A555_6263408FCB9A__INCLUDED_)
