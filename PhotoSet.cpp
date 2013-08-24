// PhotoSet.cpp : implementation file
//

#include "stdafx.h"
#include "contacts.h"
#include "PhotoSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPhotoSet

IMPLEMENT_DYNAMIC(CPhotoSet, CRecordset)

CPhotoSet::CPhotoSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPhotoSet)
	m_photo_id = 0;
	m_photo_person_id = 0;
	m_photo_title = _T("");
	m_photo_type = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPhotoSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=Contacts_db");
}

CString CPhotoSet::GetDefaultSQL()
{
	return _T("[dbo].[table_photo]");
}

void CPhotoSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPhotoSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[photo_id]"), m_photo_id);
	RFX_Long(pFX, _T("[photo_person_id]"), m_photo_person_id);
	RFX_Text(pFX, _T("[photo_title]"), m_photo_title);
	RFX_Text(pFX, _T("[photo_type]"), m_photo_type);
	RFX_LongBinary(pFX, _T("[photo_data]"), m_photo_data);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CPhotoSet diagnostics

#ifdef _DEBUG
void CPhotoSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPhotoSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
