// LoginDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contacts.h"
#include "LoginDlg.h"
#include "ContactsDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg dialog
#include "UserSet.h"
extern CDatabase m_database;

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLoginDlg)
	//}}AFX_DATA_INIT
}


void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLoginDlg)
	DDX_Control(pDX, IDC_USERNAME, m_strUsername);
	DDX_Control(pDX, IDC_PASSWORD, m_strPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialog)
	//{{AFX_MSG_MAP(CLoginDlg)
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLoginDlg message handlers

void CLoginDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here
        if (m_database.IsOpen()) {
                MessageBox("数据库已打开！");
                return;
        }
        static int errorCount = 0;
	CString username, password;
        m_strUsername.GetWindowText(username);
        m_strPassword.GetWindowText(password);
        CString strConnection;
        strConnection.Format(_T("Contacts_db"));

        if (m_database.Open(strConnection)) {
                CUserSet m_userSet;
                m_userSet.m_pDatabase = &m_database;
                m_userSet.Open();
                CString str;
                str.Format("userinfo_username = '%s' And userinfo_password = '%s'", username, password);
                m_userSet.m_strFilter = str;
                m_userSet.Requery();
                if (m_userSet.GetRecordCount() == 0) {
                        if (++errorCount < 5) {
                                MessageBox("用户名或密码错误！", "错误", MB_OK | MB_ICONERROR);
                                m_strUsername.SetWindowText("");
                                m_strPassword.SetWindowText("");
                                m_strUsername.SetFocus();
                        }
                        else {
                                MessageBox("密码输入错误 5 次，系统将自动退出！", "错误", MB_OK | MB_ICONERROR);
                                
                                CDialog::OnCancel();
                        }
                }
                else {
                        errorCount = 0;
                        CDialog::OnOK();
                }
                m_userSet.Close();
        }
        m_database.Close();
}
