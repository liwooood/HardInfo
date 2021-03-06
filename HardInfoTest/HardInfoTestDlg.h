
// HardInfoTestDlg.h : 头文件
//

#pragma once


// CHardInfoTestDlg 对话框
class CHardInfoTestDlg : public CDialogEx
{
// 构造
public:
	CHardInfoTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_HARDINFOTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGetCpuid();
	afx_msg void OnBnClickedGetMainboadid();
	afx_msg void OnBnClickedGetDiskId();
	afx_msg void OnBnClickedGetMacaddress();
	afx_msg void OnBnClickedGetBiosid();
};
