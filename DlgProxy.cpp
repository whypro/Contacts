// DlgProxy.cpp : implementation file
//

#include "stdafx.h"
#include "Contacts.h"
#include "DlgProxy.h"
#include "ContactsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContactsDlgAutoProxy

IMPLEMENT_DYNCREATE(CContactsDlgAutoProxy, CCmdTarget)

CContactsDlgAutoProxy::CContactsDlgAutoProxy()
{
	EnableAutomation();
	
	// To keep the application running as long as an automation 
	//	object is active, the constructor calls AfxOleLockApp.
	AfxOleLockApp();

	// Get access to the dialog through the application's
	//  main window pointer.  Set the proxy's internal pointer
	//  to point to the dialog, and set the dialog's back pointer to
	//  this proxy.
	ASSERT (AfxGetApp()->m_pMainWnd != NULL);
	ASSERT_VALID (AfxGetApp()->m_pMainWnd);
	ASSERT_KINDOF(CContactsDlg, AfxGetApp()->m_pMainWnd);
	m_pDialog = (CContactsDlg*) AfxGetApp()->m_pMainWnd;
	m_pDialog->m_pAutoProxy = this;
}

CContactsDlgAutoProxy::~CContactsDlgAutoProxy()
{
	// To terminate the application when all objects created with
	// 	with automation, the destructor calls AfxOleUnlockApp.
	//  Among other things, this will destroy the main dialog
	if (m_pDialog != NULL)
		m_pDialog->m_pAutoProxy = NULL;
	AfxOleUnlockApp();
}

void CContactsDlgAutoProxy::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CCmdTarget::OnFinalRelease();
}

BEGIN_MESSAGE_MAP(CContactsDlgAutoProxy, CCmdTarget)
	//{{AFX_MSG_MAP(CContactsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CContactsDlgAutoProxy, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CContactsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IContacts to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {064CFB5F-DA32-4F24-86A3-9048E8C382DB}
static const IID IID_IContacts =
{ 0x64cfb5f, 0xda32, 0x4f24, { 0x86, 0xa3, 0x90, 0x48, 0xe8, 0xc3, 0x82, 0xdb } };

BEGIN_INTERFACE_MAP(CContactsDlgAutoProxy, CCmdTarget)
	INTERFACE_PART(CContactsDlgAutoProxy, IID_IContacts, Dispatch)
END_INTERFACE_MAP()

// The IMPLEMENT_OLECREATE2 macro is defined in StdAfx.h of this project
// {DCD9A98B-43BC-4522-BE15-2DCF86106043}
IMPLEMENT_OLECREATE2(CContactsDlgAutoProxy, "Contacts.Application", 0xdcd9a98b, 0x43bc, 0x4522, 0xbe, 0x15, 0x2d, 0xcf, 0x86, 0x10, 0x60, 0x43)

/////////////////////////////////////////////////////////////////////////////
// CContactsDlgAutoProxy message handlers
