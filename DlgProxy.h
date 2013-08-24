// DlgProxy.h : header file
//

#if !defined(AFX_DLGPROXY_H__2B398CCC_2DDB_44AF_8BD8_B06B680578D6__INCLUDED_)
#define AFX_DLGPROXY_H__2B398CCC_2DDB_44AF_8BD8_B06B680578D6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CContactsDlg;

/////////////////////////////////////////////////////////////////////////////
// CContactsDlgAutoProxy command target

class CContactsDlgAutoProxy : public CCmdTarget
{
	DECLARE_DYNCREATE(CContactsDlgAutoProxy)

	CContactsDlgAutoProxy();           // protected constructor used by dynamic creation

// Attributes
public:
	CContactsDlg* m_pDialog;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CContactsDlgAutoProxy)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CContactsDlgAutoProxy();

	// Generated message map functions
	//{{AFX_MSG(CContactsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CContactsDlgAutoProxy)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CContactsDlgAutoProxy)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPROXY_H__2B398CCC_2DDB_44AF_8BD8_B06B680578D6__INCLUDED_)
