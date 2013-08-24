; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CInsertDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "contacts.h"
LastPage=0

ClassCount=14
Class1=CCitySet
Class2=CContactsApp
Class3=CAboutDlg
Class4=CContactsDlg
Class5=CContactsSet
Class6=CContactsDlgAutoProxy
Class7=CGroupSet
Class8=CInsertDlg
Class9=CLoginDlg
Class10=CPhotoSet
Class11=CProvinceSet
Class12=CQueryDlg

ResourceCount=10
Resource1=IDD_GROUP_DIALOG
Resource2=IDD_LOGIN_DIALOG
Resource3=IDD_QUERY_DIALOG
Resource4=IDD_GROUP_ADD_DIALOG
Resource5=IDD_USER_DIALOG
Resource6=IDR_CONTACTS_MENU
Resource7=IDD_INSERT_DIALOG
Resource8=IDD_CONTACTS_DIALOG
Class13=CUserSet
Class14=CGroupDlg
Resource9=IDD_ABOUTBOX
Resource10=IDR_POPUP_MENU

[CLS:CCitySet]
Type=0
HeaderFile=CitySet.h
ImplementationFile=CitySet.cpp
LastObject=CCitySet

[CLS:CContactsApp]
Type=0
BaseClass=CWinApp
HeaderFile=Contacts.h
ImplementationFile=Contacts.cpp
LastObject=CContactsApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ContactsDlg.cpp
ImplementationFile=ContactsDlg.cpp
LastObject=ID_MENU_MODIFY
Filter=D
VirtualFilter=dWC

[CLS:CContactsDlg]
Type=0
BaseClass=CDialog
HeaderFile=ContactsDlg.h
ImplementationFile=ContactsDlg.cpp
LastObject=CContactsDlg
Filter=D
VirtualFilter=dWC

[CLS:CContactsSet]
Type=0
HeaderFile=ContactsSet.h
ImplementationFile=ContactsSet.cpp
LastObject=CContactsSet

[CLS:CContactsDlgAutoProxy]
Type=0
BaseClass=CCmdTarget
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
LastObject=CContactsDlgAutoProxy

[CLS:CGroupSet]
Type=0
HeaderFile=GroupSet.h
ImplementationFile=GroupSet.cpp
LastObject=CGroupSet

[CLS:CInsertDlg]
Type=0
BaseClass=CDialog
HeaderFile=InsertDlg.h
ImplementationFile=InsertDlg.cpp
LastObject=CInsertDlg

[CLS:CLoginDlg]
Type=0
BaseClass=CDialog
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
LastObject=CLoginDlg

[CLS:CPhotoSet]
Type=0
HeaderFile=PhotoSet.h
ImplementationFile=PhotoSet.cpp
LastObject=CPhotoSet

[CLS:CProvinceSet]
Type=0
HeaderFile=ProvinceSet.h
ImplementationFile=ProvinceSet.cpp

[CLS:CQueryDlg]
Type=0
BaseClass=CDialog
HeaderFile=QueryDlg.h
ImplementationFile=QueryDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CQueryDlg

[DB:CCitySet]
DB=1

[DB:CContactsSet]
DB=1

[DB:CGroupSet]
DB=1

[DB:CPhotoSet]
DB=1

[DB:CProvinceSet]
DB=1

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=7
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Control5=IDC_ABOUT_CANCEL,button,1342242816
Control6=IDC_STATIC,static,1342308352
Control7=IDC_ABOUT_TXT,static,1342182145

[DLG:IDD_CONTACTS_DIALOG]
Type=1
Class=CContactsDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_QUICK_SEARCH,edit,1350631552
Control3=IDC_RECORD_INSERT,button,1342242816
Control4=IDC_RECORD_DELETE,button,1342177280
Control5=IDC_RECORD_QUERY,button,1342242816
Control6=IDC_RECORD_MODIFY,button,1342242816
Control7=IDC_RECORD_LIST,SysListView32,1350631837

[DLG:IDD_INSERT_DIALOG]
Type=1
Class=CInsertDlg
ControlCount=46
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_NAME,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_SEX,combobox,1344339971
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BLOODTYPE,combobox,1344339971
Control8=IDC_STATIC,static,1342308352
Control9=IDC_BIRTHDATE,SysDateTimePick32,1342242849
Control10=IDC_STATIC,static,1342308352
Control11=IDC_GROUP,combobox,1344339971
Control12=IDC_STATIC,button,1342177287
Control13=IDC_STATIC,static,1342308352
Control14=IDC_PROVINCE,combobox,1344339971
Control15=IDC_STATIC,static,1342308352
Control16=IDC_CITY,combobox,1344339971
Control17=IDC_STATIC,static,1342308352
Control18=IDC_ADDRESS,edit,1350631492
Control19=IDC_STATIC,button,1342177287
Control20=IDC_STATIC,static,1342308352
Control21=IDC_MOBILEPHONE,edit,1350631552
Control22=IDC_STATIC,static,1342308352
Control23=IDC_TELEPHONE,edit,1350631552
Control24=IDC_STATIC,static,1342308352
Control25=IDC_QQ,edit,1350631552
Control26=IDC_STATIC,static,1342308352
Control27=IDC_EMAIL,edit,1350631552
Control28=IDC_STATIC,button,1342177287
Control29=IDC_STATIC,static,1342308352
Control30=IDC_UNIVERSITY,edit,1350631552
Control31=IDC_STATIC,static,1342308352
Control32=IDC_DEPARTMENT,edit,1350631552
Control33=IDC_STATIC,static,1342308352
Control34=IDC_MAJOR,edit,1350631552
Control35=IDC_STATIC,static,1342308352
Control36=IDC_GRADE,edit,1350631552
Control37=IDC_PHOTO,static,1342181384
Control38=IDC_PHOTO_PATH,edit,1350568064
Control39=IDC_UPLOAD_PHOTO,button,1342242816
Control40=IDC_CLEAR_PHOTO,button,1342242816
Control41=IDC_INSERT_EXEC,button,1342242816
Control42=IDC_CANCEL,button,1342242817
Control43=IDC_PRE,button,1073807360
Control44=IDC_NEXT,button,1073807360
Control45=IDC_FIRST,button,1073807360
Control46=IDC_LAST,button,1073807360

[DLG:IDD_LOGIN_DIALOG]
Type=1
Class=CLoginDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308352
Control2=IDC_USERNAME,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PASSWORD,edit,1350631584
Control5=IDC_LOGIN,button,1342242817
Control6=IDCANCEL,button,1342242816

[DLG:IDD_QUERY_DIALOG]
Type=1
Class=CQueryDlg
ControlCount=7
Control1=IDC_STATIC,static,1342308352
Control2=IDC_QUERY_METHOD,combobox,1344339971
Control3=IDC_STATIC,static,1342308352
Control4=IDC_QUERY_FILTER,edit,1350631552
Control5=IDC_QUERY_LIST,SysListView32,1350631709
Control6=IDC_QUERY_EXEC,button,1342242817
Control7=IDC_CANCEL,button,1342242816

[MNU:IDR_CONTACTS_MENU]
Type=1
Class=CContactsDlg
Command1=ID_MENU_NEW_RECORD
Command2=ID_MENU_NEW_GROUP
Command3=ID_APP_EXIT
Command4=ID_MENU_MODIFY
Command5=ID_MENU_DELETE
Command6=ID_MENU_QUERY
Command7=ID_MENU_PREFERENCE
Command8=ID_MENU_REFRESH
Command9=ID_MENUITEM32787
Command10=ID_MENU_HELP
Command11=ID_MENU_ABOUT
CommandCount=11

[MNU:IDR_POPUP_MENU]
Type=1
Class=CContactsDlg
Command1=ID_MENU_NEW_RECORD
Command2=ID_MENU_DELETE
Command3=ID_MENU_QUERY
Command4=ID_MENU_MODIFY
Command5=ID_MENU_IMPORT
Command6=ID_MENU_EXPORT
Command7=ID_MENU_REFRESH
CommandCount=7

[DLG:IDD_USER_DIALOG]
Type=1
Class=?
ControlCount=5
Control1=IDCANCEL,button,1342242816
Control2=IDC_LIST_USER,SysListView32,1350631693
Control3=IDC_ADD_USER,button,1342242816
Control4=IDC_DEL_USER,button,1342242816
Control5=IDC_MOD_PWD,button,1342242816

[CLS:CUserSet]
Type=0
HeaderFile=UserSet.h
ImplementationFile=UserSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CUserSet]
DB=1
DBType=ODBC
ColumnCount=3
Column1=[userinfo_username], -9, 60
Column2=[userinfo_password], -9, 60
Column3=[user_privilege], 1, 1

[DLG:IDD_GROUP_DIALOG]
Type=1
Class=CGroupDlg
ControlCount=5
Control1=IDC_GROUP_LISTBOX,SysListView32,1350631437
Control2=IDC_GROUP_ADD,button,1342242816
Control3=IDC_GROUP_DEL,button,1342242816
Control4=IDC_GROUP_CANCEL,button,1342242816
Control5=IDC_GROUP_RENAME,button,1342242816

[CLS:CGroupDlg]
Type=0
HeaderFile=GroupDlg.h
ImplementationFile=GroupDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_GROUP_NAMEBOX
VirtualFilter=dWC

[DLG:IDD_GROUP_ADD_DIALOG]
Type=1
Class=?
ControlCount=3
Control1=IDOK,button,1342242816
Control2=IDCANCEL,button,1342242817
Control3=IDC_GROUP_NAME,edit,1350631552

