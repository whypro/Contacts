// CitySet.cpp : implementation file
//

#include "stdafx.h"
#include "contacts.h"
#include "CitySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCitySet

IMPLEMENT_DYNAMIC(CCitySet, CRecordset)

CCitySet::CCitySet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCitySet)
	m_city_id = 0;
	m_city_name = _T("");
	m_city_province_id = 0;
	m_city_state = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCitySet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Contacts_db");
}

CString CCitySet::GetDefaultSQL()
{
	return _T("[dbo].[table_city]");
}

void CCitySet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCitySet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[city_id]"), m_city_id);
	RFX_Text(pFX, _T("[city_name]"), m_city_name);
	RFX_Long(pFX, _T("[city_province_id]"), m_city_province_id);
	RFX_Text(pFX, _T("[city_state]"), m_city_state);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCitySet diagnostics

#ifdef _DEBUG
void CCitySet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCitySet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
