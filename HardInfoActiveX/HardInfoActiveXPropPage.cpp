// HardInfoActiveXPropPage.cpp : CHardInfoActiveXPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "HardInfoActiveX.h"
#include "HardInfoActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CHardInfoActiveXPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CHardInfoActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CHardInfoActiveXPropPage, "HARDINFOACTIVE.HardInfoActivePropPage.1",
	0x7961e179, 0xdaed, 0x415e, 0xb1, 0x91, 0x60, 0x4d, 0x9e, 0x55, 0x97, 0x69)

// CHardInfoActiveXPropPage::CHardInfoActiveXPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CHardInfoActiveXPropPage ��ϵͳע�����

BOOL CHardInfoActiveXPropPage::CHardInfoActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_HARDINFOACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CHardInfoActiveXPropPage::CHardInfoActiveXPropPage - ���캯��

CHardInfoActiveXPropPage::CHardInfoActiveXPropPage() :
	COlePropertyPage(IDD, IDS_HARDINFOACTIVEX_PPG_CAPTION)
{
}

// CHardInfoActiveXPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CHardInfoActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CHardInfoActiveXPropPage ��Ϣ�������
