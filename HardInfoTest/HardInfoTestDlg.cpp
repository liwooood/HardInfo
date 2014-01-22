
// HardInfoTestDlg.cpp : ʵ���ļ�
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


// CHardInfoTestDlg �Ի���



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


// CHardInfoTestDlg ��Ϣ�������

BOOL CHardInfoTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CHardInfoTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
