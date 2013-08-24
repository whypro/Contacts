// QueryDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contacts.h"
#include "QueryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg dialog
#include "ContactsSet.h"
extern CDatabase m_database;

CQueryDlg::CQueryDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CQueryDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQueryDlg)
	//}}AFX_DATA_INIT
}


void CQueryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQueryDlg)
	DDX_Control(pDX, IDC_QUERY_FILTER, m_edtQueryFilter);
	DDX_Control(pDX, IDC_QUERY_METHOD, m_cmbQueryMethod);
	DDX_Control(pDX, IDC_QUERY_LIST, m_resultList);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQueryDlg, CDialog)
	//{{AFX_MSG_MAP(CQueryDlg)
	ON_BN_CLICKED(IDC_QUERY_EXEC, OnQueryExec)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQueryDlg message handlers

BOOL CQueryDlg::OnInitDialog()
{
        CDialog::OnInitDialog();
        
        // ��ʼ����Ͽ�
        m_cmbQueryMethod.AddString("");
        m_cmbQueryMethod.AddString("����");     // 1
        m_cmbQueryMethod.AddString("�Ա�");     // 2
        m_cmbQueryMethod.AddString("Ѫ��");     // 3
        m_cmbQueryMethod.AddString("����");     // 4
        m_cmbQueryMethod.AddString("Ⱥ��");     // 5
        m_cmbQueryMethod.AddString("�ƶ��绰"); // 6
        m_cmbQueryMethod.AddString("�̶��绰"); // 7
        m_cmbQueryMethod.AddString("QQ");       // 8
        m_cmbQueryMethod.AddString("E-Mail");   // 9
        m_cmbQueryMethod.AddString("ʡ��");     // 10
        m_cmbQueryMethod.AddString("����");     // 11
        m_cmbQueryMethod.AddString("��ַ");     // 12
        m_cmbQueryMethod.AddString("��ѧ");     // 13
        m_cmbQueryMethod.AddString("Ժϵ");     // 14
        m_cmbQueryMethod.AddString("רҵ");     // 15
        m_cmbQueryMethod.AddString("�꼶");     // 16

        // ��ʼ���б�ؼ�
        m_resultList.InsertColumn(0, "ID", LVCFMT_LEFT, 0);
        m_resultList.InsertColumn(1, "����", LVCFMT_LEFT, 60);
        m_resultList.InsertColumn(2, "�ƶ��绰", LVCFMT_LEFT, 60);
        m_resultList.InsertColumn(3, "QQ", LVCFMT_LEFT, 60);
        m_resultList.InsertColumn(4, "�����ʼ�", LVCFMT_LEFT, 60);
        m_resultList.InsertColumn(5, "Ⱥ��", LVCFMT_LEFT, 60);

        // ���ÿ��
        RECT rectList;
        m_resultList.GetWindowRect(&rectList);
        int width = rectList.right - rectList.left - 4;
        for (int i = 1; i < 6; i++) {
                m_resultList.SetColumnWidth(i, width / 5);
        }
        // ��ֹ�ı��б��ı�����
        m_resultList.SetExtendedStyle(LVS_EX_FULLROWSELECT);
        m_resultList.GetHeaderCtrl()->EnableWindow(FALSE);

        return TRUE;
}

void CQueryDlg::OnQueryExec() 
{
        // TODO: Add your control notification handler code here
        int methodID = m_cmbQueryMethod.GetCurSel();
        CContactsSet m_contactsSet;
        m_contactsSet.m_pDatabase = &m_database;
        m_contactsSet.Open();
        m_contactsSet.m_strFilter = "";
        m_contactsSet.Requery();
        CString strFilter;
        m_edtQueryFilter.GetWindowText(strFilter);
        if (methodID == 0 || strFilter == "") {
                MessageBox("��ѡ���ѯ��ʽ��������", "��ʾ", MB_OK | MB_ICONINFORMATION);
                return;
        }
        
        
        m_resultList.DeleteAllItems();
        int nRow = 0;
        if (!m_contactsSet.IsEOF()) {
                m_contactsSet.MoveFirst();
        }
        while (!m_contactsSet.IsEOF()) {
                
                CString str;
                m_contactsSet.GetFieldValue(methodID, str);
                // ���б����ʾ
                if (methodID != 1 && str.Find(strFilter) != -1 || methodID == 1 && str == strFilter) {
                        // ���б�ؼ�����ʾ��¼
                        CString strID;
                        strID.Format("%d",  m_contactsSet.m_person_id);
                        int nItem = m_resultList.InsertItem(nRow, strID);
                        m_resultList.SetItemText(nItem, 1, m_contactsSet.m_person_name);
                        m_resultList.SetItemText(nItem, 2, m_contactsSet.m_person_mobilephone);
                        m_resultList.SetItemText(nItem, 3, m_contactsSet.m_person_qq);
                        m_resultList.SetItemText(nItem, 4, m_contactsSet.m_person_email);
                        m_resultList.SetItemText(nItem, 5, m_contactsSet.m_person_group);
                        nRow++;    
                }
                m_contactsSet.MoveNext();  
        } 
        int resultCount = m_resultList.GetItemCount();
        CString strResultCount;
        strResultCount.Format("���ҵ�%d����¼��", resultCount);
        MessageBox(strResultCount, "��ʾ", MB_OK | MB_ICONINFORMATION);
        m_resultList.SetFocus();
}

void CQueryDlg::OnCancel() 
{
	// TODO: Add your control notification handler code here
        CDialog::OnCancel();
}

