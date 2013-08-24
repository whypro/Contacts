// InsertDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Contacts.h"
#include "InsertDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInsertDlg dialog
#include "ContactsSet.h"
#include "ProvinceSet.h"
#include "CitySet.h"
#include "GroupSet.h"
#include "PhotoSet.h"
extern CDatabase m_database;

CInsertDlg::CInsertDlg(CWnd* pParent /*=NULL*/)
: CDialog(CInsertDlg::IDD, pParent)
{
        //{{AFX_DATA_INIT(CInsertDlg)
        // NOTE: the ClassWizard will add member initialization here
        //}}AFX_DATA_INIT
}


void CInsertDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
        //{{AFX_DATA_MAP(CInsertDlg)
        DDX_Control(pDX, IDC_PHOTO_PATH, m_edtPhotoPath);
        DDX_Control(pDX, IDC_PHOTO, m_imgPhoto);
        DDX_Control(pDX, IDC_GRADE, m_edtGrade);
        DDX_Control(pDX, IDC_ADDRESS, m_edtAddress);
        DDX_Control(pDX, IDC_QQ, m_edtQQ);
        DDX_Control(pDX, IDC_BIRTHDATE, m_dtBirthdate);
        DDX_Control(pDX, IDC_CITY, m_cmbCity);
        DDX_Control(pDX, IDC_PROVINCE, m_cmbProvince);
        DDX_Control(pDX, IDC_UNIVERSITY, m_edtUniversity);
        DDX_Control(pDX, IDC_DEPARTMENT, m_edtDepartment);
        DDX_Control(pDX, IDC_EMAIL, m_edtEmail);
        DDX_Control(pDX, IDC_MAJOR, m_edtMajor);
        DDX_Control(pDX, IDC_TELEPHONE, m_edtTelephone);
        DDX_Control(pDX, IDC_MOBILEPHONE, m_edtMobilephone);
        DDX_Control(pDX, IDC_NAME, m_edtName);
        DDX_Control(pDX, IDC_SEX, m_cmbSex);
        DDX_Control(pDX, IDC_GROUP, m_cmbGroup);
        DDX_Control(pDX, IDC_BLOODTYPE, m_cmbBloodtype);
        //}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInsertDlg, CDialog)
//{{AFX_MSG_MAP(CInsertDlg)
ON_CBN_SELCHANGE(IDC_PROVINCE, OnSelchangeProvince)
ON_BN_CLICKED(IDC_INSERT_EXEC, OnInsertExec)
ON_BN_CLICKED(IDC_UPLOAD_PHOTO, OnUploadPhoto)
ON_BN_CLICKED(IDC_CLEAR_PHOTO, OnClearPhoto)
ON_BN_CLICKED(IDC_CANCEL, OnCancel)
ON_WM_PAINT()
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInsertDlg message handlers

BOOL CInsertDlg::OnInitDialog()
{
        CDialog::OnInitDialog();
        // �Ա���Ͽ��ʼ��
        m_cmbSex.AddString("");
        m_cmbSex.AddString("��");
        m_cmbSex.AddString("Ů");
        // Ѫ����Ͽ��ʼ��
        m_cmbBloodtype.AddString("");
        m_cmbBloodtype.AddString("A��");
        m_cmbBloodtype.AddString("B��");
        m_cmbBloodtype.AddString("AB��");
        m_cmbBloodtype.AddString("O��");
        m_cmbBloodtype.AddString("����");
        // ʡ����Ͽ��ʼ��
        CProvinceSet m_provinceSet;
        m_provinceSet.m_pDatabase = &m_database;
        m_provinceSet.Open();
        m_provinceSet.m_strFilter = "";
        m_provinceSet.Requery();
        m_cmbProvince.AddString("");
        while (!m_provinceSet.IsEOF()) {
                CString strProvinceName;
                m_provinceSet.GetFieldValue(1, strProvinceName);
                m_cmbProvince.AddString(strProvinceName);
                m_provinceSet.MoveNext();
        }
        m_provinceSet.Close();
        // ������Ͽ��ʼ��
        m_cmbCity.AddString("");
        // Ⱥ����Ͽ��ʼ��
        CGroupSet m_groupSet;
        m_groupSet.m_pDatabase = &m_database;
        m_groupSet.Open();
        m_groupSet.m_strFilter = "";
        m_groupSet.Requery();
        m_cmbGroup.AddString("");
        while (!m_groupSet.IsEOF()) {
                CString strGroupName;
                m_groupSet.GetFieldValue(1, strGroupName);
                m_cmbGroup.AddString(strGroupName);
                m_groupSet.MoveNext();
        }
        m_groupSet.Close();
        hasPhoto = false;
        needUpdatePhoto = false;
        if (m_nID) {
                SetWindowText("�޸�");  // �ı����
                GetDlgItem(IDC_INSERT_EXEC)->SetWindowText("�޸�");     // �ñ䰴��
                
                CContactsSet m_contactsSet;
                m_contactsSet.m_pDatabase = &m_database;
                CString strSQL;
                strSQL.Format("Select * From table_person Where person_id = %d", m_nID);
                m_contactsSet.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
                // ����ֵ��ʾ����
                m_edtName.SetWindowText(m_contactsSet.m_person_name);
                m_cmbSex.SelectString(-1, m_contactsSet.m_person_sex);
                m_cmbBloodtype.SelectString(-1, m_contactsSet.m_person_bloodtype);
                m_dtBirthdate.SetTime(&m_contactsSet.m_person_birthdate);
                m_cmbGroup.SelectString(-1, m_contactsSet.m_person_group);
                m_edtMobilephone.SetWindowText(m_contactsSet.m_person_mobilephone);
                m_edtTelephone.SetWindowText(m_contactsSet.m_person_telephone);
                m_edtQQ.SetWindowText(m_contactsSet.m_person_qq);
                m_edtEmail.SetWindowText(m_contactsSet.m_person_email);
                m_cmbProvince.SelectString(-1, m_contactsSet.m_person_province);
                OnSelchangeProvince();
                m_cmbCity.SelectString(-1, m_contactsSet.m_person_city);
                m_edtAddress.SetWindowText(m_contactsSet.m_person_address);
                m_edtUniversity.SetWindowText(m_contactsSet.m_person_university);
                m_edtDepartment.SetWindowText(m_contactsSet.m_person_department);
                m_edtMajor.SetWindowText(m_contactsSet.m_person_major);
                m_edtGrade.SetWindowText(m_contactsSet.m_person_grade);
                m_contactsSet.Close();
                CPhotoSet m_photoSet;
                m_photoSet.m_pDatabase = &m_database;
                strSQL.Format("Select * From table_photo Where photo_person_id = %d", m_contactsSet.m_person_id);
                m_photoSet.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
                if (!m_photoSet.IsEOF()) {
                        hasPhoto = true;
                        strFileName = m_photoSet.m_photo_title;
                        strFileName += m_photoSet.m_photo_type;
                        m_edtPhotoPath.SetWindowText(strFileName);
                        char tmpPath[_MAX_PATH + 1];
                        GetTempPath(_MAX_PATH,tmpPath);
                        
                        strFileName.Insert(0,tmpPath);
                        
                        CFile outFile(strFileName,CFile::modeCreate|CFile::modeWrite);
                        LPSTR buffer = (LPSTR)GlobalLock(m_photoSet.m_photo_data.m_hData);
                        outFile.WriteHuge(buffer,m_photoSet.m_photo_data.m_dwDataLength);
                        GlobalUnlock(m_photoSet.m_photo_data.m_hData);
                        outFile.Close(); 
                }
                m_photoSet.Close();
                
                
        }
        // ���տؼ���ʼ��
        m_dtBirthdate.SetFormat("yyyy-MM-dd");
        return TRUE;
}

void CInsertDlg::OnSelchangeProvince() 
{
        // TODO: Add your control notification handler code here
        // ��ʡ��ֵ�ı�ʱ�����³�����Ͽ������
        m_cmbCity.ResetContent();
        CString strPovince;
        m_cmbProvince.GetWindowText(strPovince);
        CCitySet m_recordSet;
        CString strSQL;
        strSQL.Format(
                "Select * From table_city Where city_province_id = (Select province_id From table_province Where province_name = '%s')",
                strPovince);
        m_recordSet.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
        m_cmbCity.ResetContent();
        m_cmbCity.AddString("");
        while (!m_recordSet.IsEOF()) {
                CString strCity;
                m_recordSet.GetFieldValue(1, strCity);
                m_cmbCity.AddString(strCity);
                m_recordSet.MoveNext();
        }
        m_recordSet.Close();
}

void CInsertDlg::OnInsertExec() 
{
        // TODO: Add your control notification handler code here
        UpdateData();
        if (m_edtName.GetWindowTextLength() == 0) {
                MessageBox("���������Ƿ�Ϊ�գ�", "��ʾ", MB_OK | MB_ICONINFORMATION);
                m_edtName.SetFocus();
                return;
        }
        CContactsSet m_contactsSet;
        m_contactsSet.m_pDatabase = &m_database;
        
        // �� m_nID == 0 ������ ID ������
        if (isInsert) {
                // �����µ� ID
                m_contactsSet.Open();
                if (!m_contactsSet.IsEOF()) {
                        m_contactsSet.MoveLast();
                        m_nID = m_contactsSet.m_person_id + 1;
                }
                else {
                        m_nID = 1;
                }
                // �����¼�¼
                m_contactsSet.SetFieldNull(&m_contactsSet.m_person_birthdate, TRUE);
                m_contactsSet.AddNew();
                m_contactsSet.m_person_id = m_nID;
        }
        // �� m_nID != 0 �����޸ļ�¼
        else {
                CString strSQL;
                strSQL.Format("Select * From table_person Where person_id = %d", m_nID);
                m_contactsSet.Open(AFX_DB_USE_DEFAULT_TYPE, strSQL);
                m_contactsSet.Edit();
        }
        // ������
        m_edtName.GetWindowText(m_contactsSet.m_person_name);
        m_cmbSex.GetWindowText(m_contactsSet.m_person_sex);
        m_cmbBloodtype.GetWindowText(m_contactsSet.m_person_bloodtype);
        m_dtBirthdate.GetTime(m_contactsSet.m_person_birthdate);
        m_cmbGroup.GetWindowText(m_contactsSet.m_person_group);
        m_edtMobilephone.GetWindowText(m_contactsSet.m_person_mobilephone);
        m_edtTelephone.GetWindowText(m_contactsSet.m_person_telephone);
        m_edtQQ.GetWindowText(m_contactsSet.m_person_qq);
        m_edtEmail.GetWindowText(m_contactsSet.m_person_email);
        m_cmbProvince.GetWindowText(m_contactsSet.m_person_province);
        m_cmbCity.GetWindowText(m_contactsSet.m_person_city);
        m_edtAddress.GetWindowText(m_contactsSet.m_person_address);
        m_edtUniversity.GetWindowText(m_contactsSet.m_person_university);
        m_edtDepartment.GetWindowText(m_contactsSet.m_person_department);
        m_edtMajor.GetWindowText(m_contactsSet.m_person_major);
        m_edtGrade.GetWindowText(m_contactsSet.m_person_grade);
        m_contactsSet.Update();
        m_contactsSet.Close();
        
        // ������Ƭ
        if (needUpdatePhoto == true && m_edtPhotoPath.GetWindowTextLength() != 0) {
                
                CPhotoSet m_photoSet;
                m_photoSet.m_pDatabase = &m_database;
                
                m_photoSet.Open();
                CString str;
                str.Format("photo_person_id = %d", m_contactsSet.m_person_id);
                m_photoSet.m_strFilter = str;
                m_photoSet.Requery();
                if (isInsert) {
                        m_photoSet.AddNew();
                }
                else if (m_photoSet.GetRecordCount() != 0) {
                        m_photoSet.Edit();
                }
                else { 
                        m_photoSet.AddNew(); 
                }
                
                CFile fileImage;
                CFileStatus fileStatus;
                CString filePath;
                m_edtPhotoPath.GetWindowText(filePath);
                fileImage.Open(filePath, CFile::modeRead);
                fileImage.GetStatus(fileStatus);
                
                
                m_photoSet.m_photo_person_id = m_nID;
                m_edtName.GetWindowText(m_photoSet.m_photo_title);
                m_photoSet.m_photo_data.m_dwDataLength = fileStatus.m_size;
                
                HGLOBAL hGlobal	= GlobalAlloc(GPTR,fileStatus.m_size);
                m_photoSet.m_photo_data.m_hData = GlobalLock(hGlobal);
                
                fileImage.ReadHuge(m_photoSet.m_photo_data.m_hData, fileStatus.m_size);
                
                m_photoSet.SetFieldDirty(&m_photoSet.m_photo_data);
                m_photoSet.SetFieldNull(&m_photoSet.m_photo_data,FALSE);
                m_photoSet.Update();
                hasPhoto = true;
                GlobalUnlock(hGlobal);
                
                
                m_photoSet.Close();
        }   
        else if (needUpdatePhoto == true && m_edtPhotoPath.GetWindowTextLength() == 0){
                hasPhoto = false;
                
                CPhotoSet m_photoSet;
                m_photoSet.m_pDatabase = &m_database;
                m_photoSet.Open();
                CString str;
                str.Format("photo_person_id = %d", m_contactsSet.m_person_id);
                m_photoSet.m_strFilter = str;
                m_photoSet.Requery();
                if (m_photoSet.GetRecordCount() != 0) {
                        m_photoSet.Delete();
                }
                m_photoSet.Close();
                
        }
        
        
        CDialog::OnOK();
}

void CInsertDlg::OnCancel() 
{
        // TODO: Add your control notification handler code here
        CDialog::OnCancel();
        
}

void CInsertDlg::OnUploadPhoto() 
{
        // TODO: Add your control notification handler code here
        // TODO: ���ļ��Ի���
        TCHAR szFilters[]= _T("Image Files (*.bmp)|*.bmp||");
        CFileDialog dlg(TRUE, NULL, NULL, OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY, szFilters);
        // ���ļ��Ի���ı�����
        dlg.m_ofn.lpstrTitle = _T("ѡ��ͼƬ");
        // �ж��Ƿ���ͼƬ
        if( dlg.DoModal() == IDOK ) {	
                
                // ��ȡͼƬ·��	
                strFileName = dlg.GetPathName();
                m_edtPhotoPath.SetWindowText(strFileName);
                hasPhoto = true;
                needUpdatePhoto = true;
        }
        /*  For JPG, GIF
        CString fileType = strFileName.Right(4);
        fileType.MakeLower();
        if (fileType == ".bmp") {
        DrawBitmap(strFileName, m_imgPhoto.GetDC(), rect); 
        }
        else if (fileType == ".jpg" || fileType == ".gif") {
        ShowJpgGif(m_imgPhoto.GetDC(), strFileName, 0, 0);
        }
        */
}

void CInsertDlg::OnClearPhoto() 
{    
        m_edtPhotoPath.SetWindowText("");
        hasPhoto = false;
        needUpdatePhoto = true;
        CRect rect;
        m_imgPhoto.GetClientRect(&rect); 
        InvalidateRect(rect);
        UpdateWindow();
}

/*
//ͨ����Դ��ͼ    
void   CInsertDlg::DrawBitmap(UINT bitmap,CDC *pDC,CRect rect)    
{    
        CBitmap bmp;    
        if   (bmp.LoadBitmap(bitmap))    
        {    
                BITMAP bmpInfo;    
                bmp.GetBitmap(&bmpInfo);    
                CDC dcMemory;    
                dcMemory.CreateCompatibleDC(pDC);    
                dcMemory.SelectObject(&bmp);    
                pDC->SetStretchBltMode(HALFTONE);    
                pDC->StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&dcMemory,0,0,bmpInfo.bmWidth,bmpInfo.bmHeight,SRCCOPY);    
        }    
}  
*/
//ͨ��BMP�ļ���ͼ    
void CInsertDlg::DrawBitmap(CString BitmapFilePath, CDC *pDC, CRect rect)    
{    
        HANDLE filehandle=::LoadImage(NULL,BitmapFilePath,IMAGE_BITMAP,0,0,LR_LOADFROMFILE);    
        if(filehandle!=NULL)    
        {    
                CBitmap bmp;
                if(bmp.Attach(filehandle))    
                {    
                        BITMAP  bmpInfo;    
                        bmp.GetBitmap(&bmpInfo);    
                        CDC   dcMemory;    
                        dcMemory.CreateCompatibleDC(pDC);    
                        dcMemory.SelectObject(&bmp);    
                        pDC->SetStretchBltMode(HALFTONE);    
                        pDC->StretchBlt(rect.left,rect.top,rect.Width(),rect.Height(),&dcMemory,0,0,bmpInfo.bmWidth,bmpInfo.bmHeight,SRCCOPY);    
                        bmp.Detach();    
                }    
        }    
} 


/*
//��ȡ�ļ���Ϣ��ʽ��JPG��ͼƬ�ļ�  
BOOL CInsertDlg::ShowJpgGif(CDC* pDC,CString strPath, int x, int y)
{  
        IStream *pStm;    
        CFileStatus fstatus;    
        CFile file;    
        LONG cb;    
        //���ļ�������ļ�����Ч��  
        if (file.Open(strPath,CFile::modeRead)&&  
                file.GetStatus(strPath,fstatus)&&   
                ((cb = fstatus.m_size) != -1))    
        {    
                HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);    
                LPVOID pvData = NULL;    
                if (hGlobal != NULL)    
                {    
                        pvData = GlobalLock(hGlobal);  
                        if (pvData != NULL)    
                        {    
                                file.ReadHuge(pvData, cb);  //6.0�п��������������  
                                //file.Read(pvData, cb);  //VC2005.NET�����������  
                                GlobalUnlock(hGlobal);    
                                CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);    
                        }   
                }   
        }  
        else  
        {  
                return false;  
        }  //���ļ�����  
        //��ʾJPEG��GIF��ʽ��ͼƬ��GIFֻ����ʾһ֡����������ʾ������  
        //Ҫ��ʾ����GIF��ʹ��ACTIVE�ؼ���  
        IPicture *pPic;   
        //load image from file stream  
        if(SUCCEEDED(OleLoadPicture(pStm,fstatus.m_size,TRUE,IID_IPicture,(LPVOID*)&pPic)))   
        {   
                OLE_XSIZE_HIMETRIC hmWidth;    
                OLE_YSIZE_HIMETRIC hmHeight;    
                pPic->get_Width(&hmWidth);    
                pPic->get_Height(&hmHeight);    
                double fX,fY;    
                //get image height and width  
                fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth/((double)pDC->GetDeviceCaps(HORZSIZE)*100.0);    
                fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight/((double)pDC->GetDeviceCaps(VERTSIZE)*100.0);    
                //use render function display image  
                
                if(FAILED(pPic->Render(*pDC,x,y,(DWORD)fX,(DWORD)fY,0,hmHeight,hmWidth,-hmHeight,NULL)))    
                {  
                        pPic->Release();  
                        return false;  
                }  
                pPic->Release();    
        }    
        else    
        {  
                return false;    
        }  
        return true;  
}  
*/

void CInsertDlg::OnPaint() 
{
        CPaintDC dc(this); // device context for painting
        
        // TODO: Add your message handler code here
        
        // Do not call CDialog::OnPaint() for painting messages
        //��ȡStatic�ؼ��Ĵ�С��Χ
        CRect rect;
        m_imgPhoto.GetClientRect(&rect); 
        if (hasPhoto) {
                GetDlgItem(IDC_CLEAR_PHOTO)->EnableWindow(TRUE);
                DrawBitmap(strFileName, m_imgPhoto.GetDC(), rect); 
        }
        else {
                GetDlgItem(IDC_CLEAR_PHOTO)->EnableWindow(FALSE);
                CBrush brs;
                brs.CreateSolidBrush(RGB(0xFF, 0xFF, 0xFF));
                m_imgPhoto.GetDC()->FillRect(rect, &brs);
        }
}
