// ProvinceSet.cpp : implementation file
//

#include "stdafx.h"
#include "contacts.h"
#include "ProvinceSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CProvinceSet

IMPLEMENT_DYNAMIC(CProvinceSet, CRecordset)

CProvinceSet::CProvinceSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CProvinceSet)
	m_province_id = 0;
	m_province_name = _T("");
	m_province_type = _T("");
	m_province_state = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CProvinceSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Contacts_db");
}

CString CProvinceSet::GetDefaultSQL()
{
	return _T("[dbo].[table_province]");
}

void CProvinceSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CProvinceSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[province_id]"), m_province_id);
	RFX_Text(pFX, _T("[province_name]"), m_province_name);
	RFX_Text(pFX, _T("[province_type]"), m_province_type);
	RFX_Text(pFX, _T("[province_state]"), m_province_state);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CProvinceSet diagnostics

#ifdef _DEBUG
void CProvinceSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CProvinceSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
