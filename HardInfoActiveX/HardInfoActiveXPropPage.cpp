// HardInfoActiveXPropPage.cpp : CHardInfoActiveXPropPage 属性页类的实现。

#include "stdafx.h"
#include "HardInfoActiveX.h"
#include "HardInfoActiveXPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CHardInfoActiveXPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CHardInfoActiveXPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CHardInfoActiveXPropPage, "HARDINFOACTIVE.HardInfoActivePropPage.1",
	0x7961e179, 0xdaed, 0x415e, 0xb1, 0x91, 0x60, 0x4d, 0x9e, 0x55, 0x97, 0x69)

// CHardInfoActiveXPropPage::CHardInfoActiveXPropPageFactory::UpdateRegistry -
// 添加或移除 CHardInfoActiveXPropPage 的系统注册表项

BOOL CHardInfoActiveXPropPage::CHardInfoActiveXPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_HARDINFOACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CHardInfoActiveXPropPage::CHardInfoActiveXPropPage - 构造函数

CHardInfoActiveXPropPage::CHardInfoActiveXPropPage() :
	COlePropertyPage(IDD, IDS_HARDINFOACTIVEX_PPG_CAPTION)
{
}

// CHardInfoActiveXPropPage::DoDataExchange - 在页和属性间移动数据

void CHardInfoActiveXPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CHardInfoActiveXPropPage 消息处理程序
