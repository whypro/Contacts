// UserSet.cpp : implementation file
//

#include "stdafx.h"
#include "contacts.h"
#include "UserSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CUserSet

IMPLEMENT_DYNAMIC(CUserSet, CRecordset)

CUserSet::CUserSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CUserSet)
	m_userinfo_username = _T("");
	m_userinfo_password = _T("");
	m_userinfo_privilege = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CUserSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Contacts_db");
}

CString CUserSet::GetDefaultSQL()
{
	return _T("[dbo].[table_userinfo]");
}

void CUserSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CUserSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[userinfo_username]"), m_userinfo_username);
	RFX_Text(pFX, _T("[userinfo_password]"), m_userinfo_password);
	RFX_Text(pFX, _T("[userinfo_privilege]"), m_userinfo_privilege);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CUserSet diagnostics

#ifdef _DEBUG
void CUserSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CUserSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
