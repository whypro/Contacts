// GroupDlg.cpp : implementation file
//

#include "stdafx.h"
#include "contacts.h"
#include "GroupDlg.h"
#include "GroupSet.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CDatabase m_database;
/////////////////////////////////////////////////////////////////////////////
// CGroupDlg dialog


CGroupDlg::CGroupDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGroupDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGroupDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGroupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGroupDlg)
	DDX_Control(pDX, IDC_GROUP_LISTBOX, m_listGroup);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGroupDlg, CDialog)
	//{{AFX_MSG_MAP(CGroupDlg)
	ON_BN_CLICKED(IDC_GROUP_ADD, OnGroupAdd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGroupDlg message handlers

BOOL CGroupDlg::OnInitDialog()
{
        CDialog::OnInitDialog();
        CGroupSet m_groupSet;
        m_groupSet.m_pDatabase = &m_database;
        m_groupSet.Open();
        m_groupSet.m_strFilter = "";
        m_groupSet.Requery();
        // m_listGroup.InsertColumn(0, "群组名");

        
        m_listGroup.InsertColumn(0, "群组名", LVCFMT_LEFT);
        m_listGroup.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES); 
        CRect rect;
        m_listGroup.GetWindowRect(rect);
        m_listGroup.SetColumnWidth(0, rect.Width() - 4);

        m_listGroup.DeleteAllItems();
        for (int i = 0; !m_groupSet.IsEOF(); ++i, m_groupSet.MoveNext()) {
                m_listGroup.InsertItem(0, m_groupSet.m_group_name);
                //m_listGroup.SetItemText(nItem, 1, m_groupSet.m_group_name);
        }
        m_listGroup.GetHeaderCtrl()->EnableWindow(FALSE);
        return TRUE;
}

void CGroupDlg::OnGroupAdd() 
{
	// TODO: Add your control notification handler code here
}
