// GroupSet.cpp : implementation file
//

#include "stdafx.h"
#include "contacts.h"
#include "GroupSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGroupSet

IMPLEMENT_DYNAMIC(CGroupSet, CRecordset)

CGroupSet::CGroupSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CGroupSet)
	m_group_id = 0;
	m_group_name = _T("");
	m_nFields = 2;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CGroupSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Contacts_db");
}

CString CGroupSet::GetDefaultSQL()
{
	return _T("[dbo].[table_group]");
}

void CGroupSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CGroupSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[group_id]"), m_group_id);
	RFX_Text(pFX, _T("[group_name]"), m_group_name);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CGroupSet diagnostics

#ifdef _DEBUG
void CGroupSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CGroupSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
