// ContactsSet.cpp : implementation file
//

#include "stdafx.h"
#include "contacts.h"
#include "ContactsSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContactsSet

IMPLEMENT_DYNAMIC(CContactsSet, CRecordset)

CContactsSet::CContactsSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CContactsSet)
	m_person_id = 0;
	m_person_name = _T("");
	m_person_sex = _T("");
	m_person_bloodtype = _T("");
	m_person_group = _T("");
	m_person_mobilephone = _T("");
	m_person_telephone = _T("");
	m_person_qq = _T("");
	m_person_email = _T("");
	m_person_province = _T("");
	m_person_city = _T("");
	m_person_address = _T("");
	m_person_university = _T("");
	m_person_department = _T("");
	m_person_major = _T("");
	m_person_grade = _T("");
	m_nFields = 17;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CContactsSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Contacts_db");
}

CString CContactsSet::GetDefaultSQL()
{
	return _T("[dbo].[table_person]");
}

void CContactsSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CContactsSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[person_id]"), m_person_id);
	RFX_Text(pFX, _T("[person_name]"), m_person_name);
	RFX_Text(pFX, _T("[person_sex]"), m_person_sex);
	RFX_Text(pFX, _T("[person_bloodtype]"), m_person_bloodtype);
	RFX_Date(pFX, _T("[person_birthdate]"), m_person_birthdate);
	RFX_Text(pFX, _T("[person_group]"), m_person_group);
	RFX_Text(pFX, _T("[person_mobilephone]"), m_person_mobilephone);
	RFX_Text(pFX, _T("[person_telephone]"), m_person_telephone);
	RFX_Text(pFX, _T("[person_qq]"), m_person_qq);
	RFX_Text(pFX, _T("[person_email]"), m_person_email);
	RFX_Text(pFX, _T("[person_province]"), m_person_province);
	RFX_Text(pFX, _T("[person_city]"), m_person_city);
	RFX_Text(pFX, _T("[person_address]"), m_person_address);
	RFX_Text(pFX, _T("[person_university]"), m_person_university);
	RFX_Text(pFX, _T("[person_department]"), m_person_department);
	RFX_Text(pFX, _T("[person_major]"), m_person_major);
	RFX_Text(pFX, _T("[person_grade]"), m_person_grade);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CContactsSet diagnostics

#ifdef _DEBUG
void CContactsSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CContactsSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
