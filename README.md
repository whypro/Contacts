# Contacts

Visual C++ 实现的通讯录管理程序

该程序使用 Visual C++ 6.0，基于 MFC 编写，使用 ODBC 作为数据源，数据库默认使用 MS-SQLSERVER 2000。

1. 配置文件
DSN.txt 为数据源的配置文件，其格式为：

        DSN: [数据源名称]
        Sever: (local)
        UID: [数据库用户名]
        PWD: [数据库密码]
        Default DB: [数据库名称]

2. 数据库默认使用 MS-SQLSERVER 2000，请自行安装和配置。