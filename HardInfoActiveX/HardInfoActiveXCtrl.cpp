// HardInfoActiveXCtrl.cpp : CHardInfoActiveXCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "HardInfoActiveX.h"
#include "HardInfoActiveXCtrl.h"
#include "HardInfoActiveXPropPage.h"
#include "afxdialogex.h"

#include <algorithm>
#include "../HardInfoDLL/HardInfoDLL.h"
#include "ImportLib.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CHardInfoActiveXCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CHardInfoActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CHardInfoActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getCpuId", dispidGetCpuId, getCpuId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getMainBoardId", dispidgetMainBoardId, getMainBoardId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getBiosId", dispidgetBiosId, getBiosId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getDiskId", dispidgetDiskId, getDiskId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getMacAddress", dispidgetMacAddress, getMacAddress, VT_BSTR, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CHardInfoActiveXCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CHardInfoActiveXCtrl, 1)
	PROPPAGEID(CHardInfoActiveXPropPage::guid)
END_PROPPAGEIDS(CHardInfoActiveXCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CHardInfoActiveXCtrl, "HARDINFOACTIVEX.HardInfoActiveXCtrl.1",
	0x236a66b7, 0xa197, 0x48cb, 0x80, 0xfd, 0xb2, 0x90, 0xc1, 0xb8, 0x34, 0xae)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CHardInfoActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DHardInfoActiveX = { 0x3052EBAE, 0x7C7D, 0x4237, { 0xB6, 0x5A, 0x69, 0x34, 0x4F, 0xED, 0xDB, 0x43 } };
const IID IID_DHardInfoActiveXEvents = { 0x66E776CD, 0xAF10, 0x4F04, { 0xA7, 0x41, 0x73, 0xDB, 0xA, 0x6D, 0x71, 0xC } };

// 控件类型信息

static const DWORD _dwHardInfoActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHardInfoActiveXCtrl, IDS_HARDINFOACTIVEX, _dwHardInfoActiveXOleMisc)

// CHardInfoActiveXCtrl::CHardInfoActiveXCtrlFactory::UpdateRegistry -
// 添加或移除 CHardInfoActiveXCtrl 的系统注册表项

BOOL CHardInfoActiveXCtrl::CHardInfoActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_HARDINFOACTIVEX,
			IDB_HARDINFOACTIVEX,
			afxRegApartmentThreading,
			_dwHardInfoActiveXOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CHardInfoActiveXCtrl::CHardInfoActiveXCtrl - 构造函数

CHardInfoActiveXCtrl::CHardInfoActiveXCtrl()
{
	InitializeIIDs(&IID_DHardInfoActiveX, &IID_DHardInfoActiveXEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CHardInfoActiveXCtrl::~CHardInfoActiveXCtrl - 析构函数

CHardInfoActiveXCtrl::~CHardInfoActiveXCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CHardInfoActiveXCtrl::OnDraw - 绘图函数

void CHardInfoActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  用您自己的绘图代码替换下面的代码。
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CHardInfoActiveXCtrl::DoPropExchange - 持久性支持

void CHardInfoActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// CHardInfoActiveXCtrl::OnResetState - 将控件重置为默认状态

void CHardInfoActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CHardInfoActiveXCtrl::AboutBox - 向用户显示“关于”框

void CHardInfoActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_HARDINFOACTIVEX);
	dlgAbout.DoModal();
}


// CHardInfoActiveXCtrl 消息处理程序


BSTR CHardInfoActiveXCtrl::getCpuId()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  在此添加调度处理程序代码
	char value[512];
	int len = sizeof(value);
	memset(value, '\0', len);
	bool bRet = false;

	bRet = GetCpuId(value, len);

	if (bRet)
		strResult = value;
	else
		strResult = "";

	return strResult.AllocSysString();
}


BSTR CHardInfoActiveXCtrl::getMainBoardId()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  在此添加调度处理程序代码

	return strResult.AllocSysString();
}


BSTR CHardInfoActiveXCtrl::getBiosId()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  在此添加调度处理程序代码

	return strResult.AllocSysString();
}


BSTR CHardInfoActiveXCtrl::getDiskId()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  在此添加调度处理程序代码

	return strResult.AllocSysString();
}


BSTR CHardInfoActiveXCtrl::getMacAddress()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  在此添加调度处理程序代码

	return strResult.AllocSysString();
}
