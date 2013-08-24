// ContactsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contacts.h"
#include "ContactsDlg.h"
#include "DlgProxy.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "InsertDlg.h"
#include "LoginDlg.h"
#include "PhotoSet.h"
#include "QueryDlg.h"
#include "GroupDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
CDatabase m_database;
int CALLBACK listCompare(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);

class CAboutDlg : public CDialog
{
public:
        CAboutDlg();
        
        // Dialog Data
        //{{AFX_DATA(CAboutDlg)
        enum { IDD = IDD_ABOUTBOX };
        //}}AFX_DATA
        
        // ClassWizard generated virtual function overrides
        //{{AFX_VIRTUAL(CAboutDlg)
protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
        //}}AFX_VIRTUAL
        int textPage;
        // Implementation
protected:
        //{{AFX_MSG(CAboutDlg)
        afx_msg void OnAboutTxt();
        afx_msg void OnAboutCancel();
        //}}AFX_MSG
        DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
        //{{AFX_DATA_INIT(CAboutDlg)
        //}}AFX_DATA_INIT
        textPage = 0;
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CAboutDlg)
        //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
ON_BN_CLICKED(IDC_ABOUT_TXT, OnAboutTxt)
ON_BN_CLICKED(IDC_ABOUT_CANCEL, OnAboutCancel)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContactsDlg dialog

IMPLEMENT_DYNAMIC(CContactsDlg, CDialog);

CContactsDlg::CContactsDlg(CWnd* pParent /*=NULL*/)
: CDialog(CContactsDlg::IDD, pParent)
{
        //{{AFX_DATA_INIT(CContactsDlg)
        //}}AFX_DATA_INIT
        // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
        m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
        m_pAutoProxy = NULL;
}

CContactsDlg::~CContactsDlg()
{
        // If there is an automation proxy for this dialog, set
        //  its back pointer to this dialog to NULL, so it knows
        //  the dialog has been deleted.
        if (m_pAutoProxy != NULL)
                m_pAutoProxy->m_pDialog = NULL;
}

void CContactsDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CContactsDlg)
        DDX_Control(pDX, IDC_QUICK_SEARCH, m_edtSearch);
        DDX_Control(pDX, IDC_RECORD_LIST, m_recordList);
        //}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CContactsDlg, CDialog)
        //{{AFX_MSG_MAP(CContactsDlg)
        ON_WM_SYSCOMMAND()
        ON_WM_PAINT()
        ON_WM_QUERYDRAGICON()
        ON_WM_CLOSE()
        ON_BN_CLICKED(IDC_RECORD_INSERT, OnRecordInsert)
        ON_BN_CLICKED(IDC_RECORD_QUERY, OnRecordQuery)
        ON_BN_CLICKED(IDC_RECORD_DELETE, OnRecordDelete)
        ON_BN_CLICKED(IDC_RECORD_MODIFY, OnRecordModify)
        ON_EN_SETFOCUS(IDC_QUICK_SEARCH, OnSetfocusQuickSearch)
        ON_EN_CHANGE(IDC_QUICK_SEARCH, OnChangeQuickSearch)
        ON_EN_KILLFOCUS(IDC_QUICK_SEARCH, OnKillfocusQuickSearch)
        ON_NOTIFY(NM_DBLCLK, IDC_RECORD_LIST, OnDblclkRecordList)
        ON_NOTIFY(LVN_KEYDOWN, IDC_RECORD_LIST, OnKeydownRecordList)
        ON_COMMAND(ID_MENU_NEW_RECORD, OnMenuNewRecord)
        ON_COMMAND(ID_MENU_MODIFY, OnMenuModify)
        ON_COMMAND(ID_MENU_DELETE, OnMenuDelete)
        ON_COMMAND(ID_MENU_ABOUT, OnMenuAbout)
        ON_COMMAND(ID_MENU_QUERY, OnMenuQuery)
        ON_NOTIFY(NM_RCLICK, IDC_RECORD_LIST, OnRclickRecordList)
	ON_COMMAND(ID_MENU_REFRESH, OnMenuRefresh)
	ON_COMMAND(ID_MENU_NEW_GROUP, OnMenuNewGroup)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContactsDlg message handlers

BOOL CContactsDlg::OnInitDialog()
{
        CDialog::OnInitDialog();
        
        // Add "About..." menu item to system menu.
        
        // IDM_ABOUTBOX must be in the system command range.
        ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
        ASSERT(IDM_ABOUTBOX < 0xF000);
        
        CMenu* pSysMenu = GetSystemMenu(FALSE);
        if (pSysMenu != NULL)
        {
                CString strAboutMenu;
                strAboutMenu.LoadString(IDS_ABOUTBOX);
                if (!strAboutMenu.IsEmpty())
                {
                        pSysMenu->AppendMenu(MF_SEPARATOR);
                        pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
                }
        }
        
        
        // Set the icon for this dialog.  The framework does this automatically
        //  when the application's main window is not a dialog
        SetIcon(m_hIcon, TRUE);			// Set big icon
        SetIcon(m_hIcon, FALSE);		// Set small icon
        
        // TODO: Add extra initialization here
        
        // 初始化列表控件
        m_recordList.InsertColumn(0, "ID", LVCFMT_LEFT, 0);
        m_recordList.InsertColumn(1, "姓名", LVCFMT_LEFT);
        m_recordList.InsertColumn(2, "移动电话", LVCFMT_LEFT);
        m_recordList.InsertColumn(3, "QQ", LVCFMT_LEFT);
        m_recordList.InsertColumn(4, "电子邮件", LVCFMT_LEFT);
        m_recordList.InsertColumn(5, "群组", LVCFMT_LEFT);


        // 设置宽度
        int scroll = 17;        // 17
        RECT rectList;
        m_recordList.GetWindowRect(&rectList);
        int width = rectList.right - rectList.left - 4 - scroll;
        for (int i = 1; i < 6; i++) {
                m_recordList.SetColumnWidth(i, width / 5);
        }


        // 禁止改变列表框的标题栏
        m_recordList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
        m_recordList.GetHeaderCtrl()->EnableWindow(FALSE);
        RefreshData();
        
        return TRUE;  // return TRUE  unless you set the focus to a control
}

void CContactsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
        if ((nID & 0xFFF0) == IDM_ABOUTBOX)
        {
                CAboutDlg dlgAbout;
                dlgAbout.DoModal();
        }
        else
        {
                CDialog::OnSysCommand(nID, lParam);
        }
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CContactsDlg::OnPaint() 
{
        if (IsIconic())
        {
                CPaintDC dc(this); // device context for painting
                
                SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
                
                // Center icon in client rectangle
                int cxIcon = GetSystemMetrics(SM_CXICON);
                int cyIcon = GetSystemMetrics(SM_CYICON);
                CRect rect;
                GetClientRect(&rect);
                int x = (rect.Width() - cxIcon + 1) / 2;
                int y = (rect.Height() - cyIcon + 1) / 2;
                
                // Draw the icon
                dc.DrawIcon(x, y, m_hIcon);
        }
        else
        {
                CDialog::OnPaint();
        }
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CContactsDlg::OnQueryDragIcon()
{
        return (HCURSOR) m_hIcon;
}

// Automation servers should not exit when a user closes the UI
//  if a controller still holds on to one of its objects.  These
//  message handlers make sure that if the proxy is still in use,
//  then the UI is hidden but the dialog remains around if it
//  is dismissed.

void CContactsDlg::OnClose() 
{
        if (CanExit())
                CDialog::OnClose();
}

void CContactsDlg::OnOK() 
{
        if (CanExit())
                CDialog::OnOK();
}

void CContactsDlg::OnCancel() 
{
        if (CanExit())
                CDialog::OnCancel();
}

BOOL CContactsDlg::CanExit()
{
        // If the proxy object is still around, then the automation
        //  controller is still holding on to this application.  Leave
        //  the dialog around, but hide its UI.
        if (m_pAutoProxy != NULL)
        {
                ShowWindow(SW_HIDE);
                return FALSE;
        }
        
        return TRUE;
}

void CContactsDlg::RefreshData()
{
        
        if (!m_database.IsOpen()) {
                CString strConnection;
                strConnection.Format(_T("Contacts_db"));
                if (!m_database.Open(strConnection)) {
                        MessageBox("数据库未打开！");
                        return;
                }
        }

        CContactsSet m_contactsSet;
        m_contactsSet.m_pDatabase = &m_database;
        // 打开记录集
        m_contactsSet.Open();
        // 对列表控件的内容更新,清空原来的内容
        m_recordList.DeleteAllItems();
        // 在列表控件内显示记录
        for (int nRow = 0; !m_contactsSet.IsEOF(); nRow++) {
                CString strID;
                strID.Format("%d",  m_contactsSet.m_person_id);
                int nItem = m_recordList.InsertItem(nRow, strID);
                m_recordList.SetItemText(nItem, 1, m_contactsSet.m_person_name);
                m_recordList.SetItemText(nItem, 2, m_contactsSet.m_person_mobilephone);
                m_recordList.SetItemText(nItem, 3, m_contactsSet.m_person_qq);
                m_recordList.SetItemText(nItem, 4, m_contactsSet.m_person_email);
                m_recordList.SetItemText(nItem, 5, m_contactsSet.m_person_group);
                m_contactsSet.MoveNext();
        }
        // 按第二列排序
        for(int i = 0; i < m_recordList.GetItemCount(); i++) {
                m_recordList.SetItemData(i,i);
        }
        m_recordList.SortItems(listCompare, (DWORD)&m_recordList);    
}

void CContactsDlg::OnRecordInsert() 
{
        // TODO: Add your control notification handler code here
        CInsertDlg aDlg;
        aDlg.isInsert = true;
        aDlg.m_nID = 0;
        if (aDlg.DoModal() == IDOK) {
                RefreshData();
                if (m_edtSearch.GetWindowTextLength() != 0) {
                        m_edtSearch.SetWindowText("");  
                }
                // 列表框始终选中最后一个添加的记录
                CContactsSet m_contactsSet;
                m_contactsSet.m_pDatabase = &m_database;
                m_contactsSet.Open();
                if (!m_contactsSet.IsEOF()) {
                        m_contactsSet.MoveLast();
                        CString strID;
                        strID.Format("%d", m_contactsSet.m_person_id);
                        for (int nIndex = 0; nIndex <= m_recordList.GetItemCount(); nIndex++ ) {
                                if (m_recordList.GetItemText(nIndex, 0) == strID) {
                                        m_recordList.SetItemState(nIndex,  LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
                                        m_recordList.SetSelectionMark(nIndex); 
                                }
                        }
                }
        }
        m_recordList.SetFocus();
}

void CContactsDlg::OnRecordDelete() 
{
        // TODO: Add your control notification handler code here
        
        if (!m_recordList.GetSelectedCount()) {
                MessageBox("请选择一条记录！", "提示", MB_OK | MB_ICONINFORMATION);
        }
        else {
                int nIndex = m_recordList.GetSelectionMark();
                CString strID = m_recordList.GetItemText(nIndex, 0);
                // 删除确认
                CString str, name;
                name = m_recordList.GetItemText(nIndex, 1);
                str.Format("删除记录“%s”？", name);
                if (MessageBox(str, "确认", MB_OKCANCEL | MB_ICONQUESTION) == IDOK) {
                        // 查询所选行所在的记录
                        int id = atoi(strID);
                        CPhotoSet m_photoSet;
                        m_photoSet.m_pDatabase = &m_database;
                        m_photoSet.Open();
                        CString str;
                        str.Format("photo_person_id = %d", id);
                        m_photoSet.m_strFilter = str;
                        m_photoSet.Requery();
                        if (m_photoSet.GetRecordCount() != 0) {
                                m_photoSet.Delete();
                        }
                        m_photoSet.Close();
                        
                        CContactsSet m_contactsSet;
                        m_contactsSet.m_pDatabase = &m_database;
                        m_contactsSet.Open();
                        str.Format("person_id = %d", id);
                        m_contactsSet.m_strFilter = str;
                        m_contactsSet.Requery();
                        m_contactsSet.Delete();
                        m_contactsSet.Close();
                        
                        RefreshData();
                        if (m_recordList.GetSelectionMark() == -1) {
                                m_edtSearch.SetWindowText("");  
                        }
                        // 列表框始终选中被删除的下一条记录
                        if (nIndex >= m_recordList.GetItemCount()) {
                                nIndex = m_recordList.GetItemCount() - 1;
                        }
                        m_recordList.SetItemState(nIndex,  LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
                        m_recordList.SetSelectionMark(nIndex);
                }
                m_recordList.SetFocus();
                
        }
        
        
}

void CContactsDlg::OnRecordQuery() 
{
        // TODO: Add your control notification handler code here
        
        CQueryDlg aDlg;
        aDlg.DoModal();
        m_recordList.SetFocus();
}

void CContactsDlg::OnRecordModify() 
{
        // TODO: Add your control notification handler code here
        
        
        if (!m_recordList.GetSelectedCount()) {
                MessageBox("请选择一条记录！", "提示", MB_OK | MB_ICONINFORMATION);
        }
        
        else {
                int nIndex = m_recordList.GetSelectionMark();
                CString strID;
                CInsertDlg aDlg;
                strID = m_recordList.GetItemText(nIndex, 0);
                aDlg.isInsert = false;
                aDlg.m_nID = atoi(strID);
                if (aDlg.DoModal() == IDOK) {
                        RefreshData();
                        if (m_edtSearch.GetWindowTextLength() != 0) {
                                m_edtSearch.SetWindowText("");  
                        }
                        // 列表框始终选中被修改的记录
                        for (int nIndex = 0; nIndex <= m_recordList.GetItemCount(); nIndex++ ) {
                                if (m_recordList.GetItemText(nIndex, 0) == strID) {
                                        m_recordList.SetItemState(nIndex,  LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
                                        m_recordList.SetSelectionMark(nIndex); 
                                }
                        }
                }
                m_recordList.SetFocus(); 
        }
}

void CContactsDlg::OnSetfocusQuickSearch() 
{
        // TODO: Add your control notification handler code here
        m_edtSearch.GetWindowText(strTemp);
        if (strTemp != "") {
                m_edtSearch.SetWindowText("");	
        }
        GetDlgItem(IDC_RECORD_DELETE)->EnableWindow(FALSE);
        GetDlgItem(IDC_RECORD_MODIFY)->EnableWindow(FALSE);
}

void CContactsDlg::OnKillfocusQuickSearch() 
{
        // TODO: Add your control notification handler code here
        GetDlgItem(IDC_RECORD_DELETE)->EnableWindow(TRUE);
        GetDlgItem(IDC_RECORD_MODIFY)->EnableWindow(TRUE);
        
}

void CContactsDlg::OnChangeQuickSearch() 
{
        // TODO: If this is a RICHEDIT control, the control will not
        // send this notification unless you override the CDialog::OnInitDialog()
        // function and call CRichEditCtrl().SetEventMask()
        // with the ENM_CHANGE flag ORed into the mask.
        
        // TODO: Add your control notification handler code here
        CContactsSet m_contactsSet;
        m_contactsSet.m_pDatabase = &m_database;
        
        //对列表控件的内容更新,清空原来的内容
        m_recordList.DeleteAllItems();
        
        // 打开记录集
        m_contactsSet.Open();
        m_recordList.DeleteAllItems();
        //
        CString strSearch;
        m_edtSearch.GetWindowText(strSearch);
        // 以下为动态搜索代码
        // 若没有搜索条件，则显示所有记录
        if (strSearch == "") {
                RefreshData();
        }
        else {
                // 判断搜索条件首字是否是汉字
                // 为汉字
                if (int (strSearch.GetAt(0)) < 0) {
                        for (int nRow = 0; !m_contactsSet.IsEOF(); nRow++) {
                                if (m_contactsSet.m_person_name.Find(strSearch) == 0) {
                                        CString strID;
                                        strID.Format("%d", m_contactsSet.m_person_id);
                                        int nItem = m_recordList.InsertItem(nRow, strID);
                                        m_recordList.SetItemText(nItem, 1, m_contactsSet.m_person_name);
                                        m_recordList.SetItemText(nItem, 2, m_contactsSet.m_person_mobilephone);
                                        m_recordList.SetItemText(nItem, 3, m_contactsSet.m_person_qq);
                                        m_recordList.SetItemText(nItem, 4, m_contactsSet.m_person_email);
                                        m_recordList.SetItemText(nItem, 5, m_contactsSet.m_person_group);
                                        
                                }
                                m_contactsSet.MoveNext();
                        }
                }
                // 为字母
                else {
                        // 转换成小写
                        strSearch.MakeLower();
                        for (int nRow = 0; !m_contactsSet.IsEOF(); nRow++) {
                                CString strShortName = GetFirstLetter(m_contactsSet.m_person_name);
                                strShortName.MakeLower();
                                if (strShortName.Find(strSearch) == 0) {
                                        CString strID;
                                        strID.Format("%d", m_contactsSet.m_person_id);
                                        int nItem = m_recordList.InsertItem(nRow, strID);
                                        m_recordList.SetItemText(nItem, 1, m_contactsSet.m_person_name);
                                        m_recordList.SetItemText(nItem, 2, m_contactsSet.m_person_mobilephone);
                                        m_recordList.SetItemText(nItem, 3, m_contactsSet.m_person_qq);
                                        m_recordList.SetItemText(nItem, 4, m_contactsSet.m_person_email);
                                        m_recordList.SetItemText(nItem, 5, m_contactsSet.m_person_group);                        
                                }
                                m_contactsSet.MoveNext();
                        }
                }
        }
        m_contactsSet.Close();	
}

// 获取姓名拼音的首字母
// 如"张三"，返回 "ZS"
// 此处代码来自于网络，具体原理不清楚
CString CContactsDlg::GetFirstLetter(LPCTSTR strName)
{
        static int li_SecPosValue[] = {
                
                1601, 1637, 1833, 2078, 2274, 2302, 2433, 2594, 2787, 3106, 3212,
                        3472, 3635, 3722, 3730, 3858, 4027, 4086, 4390, 4558, 4684, 4925, 5249
        };
        
        static char* lc_FirstLetter[] = {
                "A", "B", "C", "D", "E", "F", "G", "H", "J", "K", "L", "M", "N", "O",
                        "P", "Q", "R", "S", "T", "W", "X", "Y", "Z"
        };
        
        static char* ls_SecondSecTable =
                "CJWGNSPGCGNE[Y[BTYYZDXYKYGT[JNNJQMBSGZSCYJSYY[PGKBZGY[YWJKGKLJYWKPJQHY[W[DZLSGMRYPYWWCCKZNKYYGTTNJJNYKKZYTCJNMCYLQLYPYQFQRPZSLWBTGKJFYXJWZLTBNCXJJJJTXDTTSQZYCDXXHGCK[PHFFSS[YBGXLPPBYLL[HLXS[ZM[JHSOJNGHDZQYKLGJHSGQZHXQGKEZZWYSCSCJXYEYXADZPMDSSMZJZQJYZC[J[WQJBYZPXGZNZCPWHKXHQKMWFBPBYDTJZZKQHY"
                "LYGXFPTYJYYZPSZLFCHMQSHGMXXSXJ[[DCSBBQBEFSJYHXWGZKPYLQBGLDLCCTNMAYDDKSSNGYCSGXLYZAYBNPTSDKDYLHGYMYLCXPY[JNDQJWXQXFYYFJLEJPZRXCCQWQQSBNKYMGPLBMJRQCFLNYMYQMSQYRBCJTHZTQFRXQHXMJJCJLXQGJMSHZKBSWYEMYLTXFSYDSWLYCJQXSJNQBSCTYHBFTDCYZDJWYGHQFRXWCKQKXEBPTLPXJZSRMEBWHJLBJSLYYSMDXLCLQKXLHXJRZJMFQHXHWY"
                "WSBHTRXXGLHQHFNM[YKLDYXZPYLGG[MTCFPAJJZYLJTYANJGBJPLQGDZYQYAXBKYSECJSZNSLYZHSXLZCGHPXZHZNYTDSBCJKDLZAYFMYDLEBBGQYZKXGLDNDNYSKJSHDLYXBCGHXYPKDJMMZNGMMCLGWZSZXZJFZNMLZZTHCSYDBDLLSCDDNLKJYKJSYCJLKWHQASDKNHCSGANHDAASHTCPLCPQYBSDMPJLPZJOQLCDHJJYSPRCHN[NNLHLYYQYHWZPTCZGWWMZFFJQQQQYXACLBHKDJXDGMMY"
                "DJXZLLSYGXGKJRYWZWYCLZMSSJZLDBYD[FCXYHLXCHYZJQ[[QAGMNYXPFRKSSBJLYXYSYGLNSCMHZWWMNZJJLXXHCHSY[[TTXRYCYXBYHCSMXJSZNPWGPXXTAYBGAJCXLY[DCCWZOCWKCCSBNHCPDYZNFCYYTYCKXKYBSQKKYTQQXFCWCHCYKELZQBSQYJQCCLMTHSYWHMKTLKJLYCXWHEQQHTQH[PQ[QSCFYMNDMGBWHWLGSLLYSDLMLXPTHMJHWLJZYHZJXHTXJLHXRSWLWZJCBXMHZQXSDZP"
                "MGFCSGLSXYMJSHXPJXWMYQKSMYPLRTHBXFTPMHYXLCHLHLZYLXGSSSSTCLSLDCLRPBHZHXYYFHB[GDMYCNQQWLQHJJ[YWJZYEJJDHPBLQXTQKWHLCHQXAGTLXLJXMSL[HTZKZJECXJCJNMFBY[SFYWYBJZGNYSDZSQYRSLJPCLPWXSDWEJBJCBCNAYTWGMPAPCLYQPCLZXSBNMSGGFNZJJBZSFZYNDXHPLQKZCZWALSBCCJX[YZGWKYPSGXFZFCDKHJGXDLQFSGDSLQWZKXTMHSBGZMJZRGLYJB"
                "PMLMSXLZJQQHZYJCZYDJWBMYKLDDPMJEGXYHYLXHLQYQHKYCWCJMYYXNATJHYCCXZPCQLBZWWYTWBQCMLPMYRJCCCXFPZNZZLJPLXXYZTZLGDLDCKLYRZZGQTGJHHGJLJAXFGFJZSLCFDQZLCLGJDJCSNZLLJPJQDCCLCJXMYZFTSXGCGSBRZXJQQCTZHGYQTJQQLZXJYLYLBCYAMCSTYLPDJBYREGKLZYZHLYSZQLZNWCZCLLWJQJJJKDGJZOLBBZPPGLGHTGZXYGHZMYCNQSYCYHBHGXKAMTX"
                "YXNBSKYZZGJZLQJDFCJXDYGJQJJPMGWGJJJPKQSBGBMMCJSSCLPQPDXCDYYKY[CJDDYYGYWRHJRTGZNYQLDKLJSZZGZQZJGDYKSHPZMTLCPWNJAFYZDJCNMWESCYGLBTZCGMSSLLYXQSXSBSJSBBSGGHFJLYPMZJNLYYWDQSHZXTYYWHMZYHYWDBXBTLMSYYYFSXJC[DXXLHJHF[SXZQHFZMZCZTQCXZXRTTDJHNNYZQQMNQDMMG[YDXMJGDHCDYZBFFALLZTDLTFXMXQZDNGWQDBDCZJDXBZGS"
                "QQDDJCMBKZFFXMKDMDSYYSZCMLJDSYNSBRSKMKMPCKLGDBQTFZSWTFGGLYPLLJZHGJ[GYPZLTCSMCNBTJBQFKTHBYZGKPBBYMTDSSXTBNPDKLEYCJNYDDYKZDDHQHSDZSCTARLLTKZLGECLLKJLQJAQNBDKKGHPJTZQKSECSHALQFMMGJNLYJBBTMLYZXDCJPLDLPCQDHZYCBZSCZBZMSLJFLKRZJSNFRGJHXPDHYJYBZGDLQCSEZGXLBLGYXTWMABCHECMWYJYZLLJJYHLG[DJLSLYGKDZPZXJ"
                "YYZLWCXSZFGWYYDLYHCLJSCMBJHBLYZLYCBLYDPDQYSXQZBYTDKYXJY[CNRJMPDJGKLCLJBCTBJDDBBLBLCZQRPPXJCJLZCSHLTOLJNMDDDLNGKAQHQHJGYKHEZNMSHRP[QQJCHGMFPRXHJGDYCHGHLYRZQLCYQJNZSQTKQJYMSZSWLCFQQQXYFGGYPTQWLMCRNFKKFSYYLQBMQAMMMYXCTPSHCPTXXZZSMPHPSHMCLMLDQFYQXSZYYDYJZZHQPDSZGLSTJBCKBXYQZJSGPSXQZQZRQTBDKYXZK"
                "HHGFLBCSMDLDGDZDBLZYYCXNNCSYBZBFGLZZXSWMSCCMQNJQSBDQSJTXXMBLTXZCLZSHZCXRQJGJYLXZFJPHYMZQQYDFQJJLZZNZJCDGZYGCTXMZYSCTLKPHTXHTLBJXJLXSCDQXCBBTJFQZFSLTJBTKQBXXJJLJCHCZDBZJDCZJDCPRNPQCJPFCZLCLZXZDMXMPHJSGZGSZZQLYLWTJPFSYASMCJBTZKYCWMYTCSJJLJCQLWZMALBXYFBPNLSFHTGJWEJJXXGLLJSTGSHJQLZFKCGNNNSZFDEQ"
                "FHBSAQTGYLBXMMYGSZLDYDQMJJRGBJTKGDHGKBLQKBDMBYLXWCXYTTYBKMRTJZXQJBHLMHMJJZMQASLDCYXYQDLQCAFYWYXQHZ";
        
        CString result;
        int H, L, W;
        UINT i, stringlen = _tcslen(strName);
        int j;
        for (i = 0; i < stringlen; i++) {
                H = (UCHAR) (strName[i + 0]);
                L = (UCHAR) (strName[i + 1]);
                
                if (H < 0xA1 || L < 0xA1) {
                        result += strName[i];
                        continue;
                } else {
                        W = (H - 160) * 100 + L - 160;
                }
                
                if (W > 1600 && W < 5590) {
                        for (j = 22; j >= 0; j--) {
                                if (W >= li_SecPosValue[j]) {
                                        result += lc_FirstLetter[j];
                                        i ++;
                                        break;
                                }
                        }
                        
                        continue;
                } else {
                        i++;
                        W = (H - 160 - 56) * 94 + L - 161;
                        if (W >= 0 && W <= 3007)
                                result += ls_SecondSecTable[W];
                        else {
                                result += (char) H;
                                result += (char) L;
                        }
                }
        } 
        return result;
}



void CContactsDlg::OnDblclkRecordList(NMHDR* pNMHDR, LRESULT* pResult) 
{
        // TODO: Add your control notification handler code here
        OnRecordModify();
        
        *pResult = 0;
}

void CContactsDlg::OnKeydownRecordList(NMHDR* pNMHDR, LRESULT* pResult) 
{
        LV_KEYDOWN* pLVKeyDow = (LV_KEYDOWN*)pNMHDR;
        // TODO: Add your control notification handler code here
        switch(pLVKeyDow->wVKey) {
        case VK_DELETE:
                OnRecordDelete();
                break;
        case VK_RETURN:
                OnRecordModify();
                break;
        }
        
        *pResult = 0;
}

BOOL CContactsDlg::PreTranslateMessage(MSG *pMsg)
{
        if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
        {
                return FALSE;
        }
        return CDialog::PreTranslateMessage(pMsg);
        
}

// 排序函数实现
// 原理具体不清楚
int CALLBACK listCompare(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
        CListCtrl* pListCtrl = (CListCtrl*)lParamSort;
        // 按第二列排序
        CString strItem1 = pListCtrl->GetItemText(lParam1,1);
        CString strItem2 = pListCtrl->GetItemText(lParam2,1);
        LVCOLUMN Vol;
        CString csStr("");
        TCHAR szCol[MAX_PATH];
        Vol.pszText = szCol;
        Vol.mask=LVCF_TEXT;
        Vol.cchTextMax=sizeof(szCol);
        pListCtrl->GetColumn(0,&Vol);
        csStr = CString(Vol.pszText);
        
        if (csStr.Right(1) == CString("▼"))
        {
                return _tcscmp(strItem2.GetBuffer(MAX_PATH),strItem1.GetBuffer(MAX_PATH));
        }
        else if (csStr.Right(1) == CString("▲"))
        {
                return _tcscmp(strItem1.GetBuffer(MAX_PATH),strItem2.GetBuffer(MAX_PATH));
        }
        else
        {
                return _tcscmp(strItem1.GetBuffer(MAX_PATH),strItem2.GetBuffer(MAX_PATH));
        }
}

void CContactsDlg::OnMenuNewRecord() 
{
        // TODO: Add your command handler code here
        OnRecordInsert();	
}

void CContactsDlg::OnMenuModify() 
{
        // TODO: Add your command handler code here
        OnRecordModify();
}

void CContactsDlg::OnMenuDelete() 
{
        // TODO: Add your command handler code here
        OnRecordDelete();
}

void CContactsDlg::OnMenuAbout() 
{
        // TODO: Add your command handler code here
        CAboutDlg aDlg;
        aDlg.DoModal();	
}

void CContactsDlg::OnMenuQuery() 
{
        // TODO: Add your command handler code here
        OnRecordQuery();
}

void CAboutDlg::OnAboutTxt() 
{
        // TODO: Add your control notification handler code here
        static CString AboutText[6] = {"本程序开始编写于2010-06-28，耗时两周。" , 
                "绝大部分代码和构思均属原创。" , 
                "仅供小范围使用和学习。" , 
                "程序中不免有很多未知的Bug，期待大家指出。" , 
                "他人修改及完善时请注明原作者：whypro " ,
                "The End" };
        
        GetDlgItem(IDC_ABOUT_TXT)->SetWindowText(AboutText[textPage]);
        textPage++;
        if (textPage == 6) {
                textPage = 0;
        }	
}

void CAboutDlg::OnAboutCancel() 
{
        // TODO: Add your control notification handler code here
        MessageBox("不好意思，你只能点确定。", "小提示", MB_ICONINFORMATION | MB_OK);	
}

void CContactsDlg::OnRclickRecordList(NMHDR* pNMHDR, LRESULT* pResult) 
{
        // TODO: Add your control notification handler code here
        // 右键菜单
        CMenu   m_PopMenu; 
        m_PopMenu.LoadMenu(IDR_POPUP_MENU);  
        CPoint point; 
        GetCursorPos(&point); 
        m_PopMenu.GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,point.x,point.y,this);	
        //*pResult = 0;
}

void CContactsDlg::OnMenuRefresh() 
{
        // TODO: Add your command handler code here
        int nIndex = m_recordList.GetSelectionMark();
        RefreshData();
        m_recordList.SetItemState(nIndex, LVIS_SELECTED | LVIS_FOCUSED, LVIS_SELECTED | LVIS_FOCUSED);
        m_recordList.SetSelectionMark(nIndex); 	
}

void CContactsDlg::OnMenuNewGroup() 
{
	// TODO: Add your command handler code here
        CGroupDlg dlg;
        dlg.DoModal();	
}
