#pragma once

// HardInfoActiveXPropPage.h : CHardInfoActiveXPropPage ����ҳ���������


// CHardInfoActiveXPropPage : �й�ʵ�ֵ���Ϣ������� HardInfoActiveXPropPage.cpp��

class CHardInfoActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CHardInfoActiveXPropPage)
	DECLARE_OLECREATE_EX(CHardInfoActiveXPropPage)

// ���캯��
public:
	CHardInfoActiveXPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_HARDINFOACTIVEX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

