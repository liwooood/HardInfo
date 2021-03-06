
// HardInfoTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "HardInfoTest.h"
#include "HardInfoTestDlg.h"
#include "afxdialogex.h"

#include <algorithm>
#include "../HardInfoDLL/HardInfoDLL.h"
#include "ImportLib.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHardInfoTestDlg 对话框



CHardInfoTestDlg::CHardInfoTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CHardInfoTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHardInfoTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CHardInfoTestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_CPUID, &CHardInfoTestDlg::OnBnClickedGetCpuid)
	ON_BN_CLICKED(IDC_GET_MAINBOADID, &CHardInfoTestDlg::OnBnClickedGetMainboadid)
	ON_BN_CLICKED(IDC_GET_DISK_ID, &CHardInfoTestDlg::OnBnClickedGetDiskId)
	ON_BN_CLICKED(IDC_GET_MACADDRESS, &CHardInfoTestDlg::OnBnClickedGetMacaddress)
	ON_BN_CLICKED(IDC_GET_BIOSID, &CHardInfoTestDlg::OnBnClickedGetBiosid)
END_MESSAGE_MAP()


// CHardInfoTestDlg 消息处理程序

BOOL CHardInfoTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CHardInfoTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CHardInfoTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CHardInfoTestDlg::OnBnClickedGetCpuid()
{
	char value[512];
	int len = sizeof(value);
	memset(value, '\0', len);

	bool bRet = false;

	bRet = GetCpuId(value, len);

	AfxMessageBox((LPCTSTR)value);
}


void CHardInfoTestDlg::OnBnClickedGetMainboadid()
{
	char value[512];
	int len = sizeof(value);
	memset(value, '\0', len);

	bool bRet = false;

	bRet = GetMainBoardId(value, len);

	AfxMessageBox((LPCTSTR)value);;
}


void CHardInfoTestDlg::OnBnClickedGetDiskId()
{
	char value[512];
	int len = sizeof(value);
	memset(value, '\0', len);

	bool bRet = false;

	bRet = GetDiskId(value, len);

	std::remove(value, value + len, ' ');

	AfxMessageBox((LPCTSTR)value);
}


void CHardInfoTestDlg::OnBnClickedGetMacaddress()
{
	char value[512];
	int len = sizeof(value);
	memset(value, '\0', len);

	bool bRet = false;

	bRet = GetMacAddress(value, len);

	AfxMessageBox((LPCTSTR)value);
}


void CHardInfoTestDlg::OnBnClickedGetBiosid()
{
	char value[512];
	int len = sizeof(value);
	memset(value, '\0', len);

	bool bRet = false;

	bRet = GetBiosId(value, len);

	
	AfxMessageBox((LPCTSTR)value);
}
