// HardInfoActiveXCtrl.cpp : CHardInfoActiveXCtrl ActiveX �ؼ����ʵ�֡�

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

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CHardInfoActiveXCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CHardInfoActiveXCtrl, COleControl)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getCpuId", dispidGetCpuId, getCpuId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getMainBoardId", dispidgetMainBoardId, getMainBoardId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getBiosId", dispidgetBiosId, getBiosId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getDiskId", dispidgetDiskId, getDiskId, VT_BSTR, VTS_NONE)
	DISP_FUNCTION_ID(CHardInfoActiveXCtrl, "getMacAddress", dispidgetMacAddress, getMacAddress, VT_BSTR, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CHardInfoActiveXCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CHardInfoActiveXCtrl, 1)
	PROPPAGEID(CHardInfoActiveXPropPage::guid)
END_PROPPAGEIDS(CHardInfoActiveXCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CHardInfoActiveXCtrl, "HARDINFOACTIVEX.HardInfoActiveXCtrl.1",
	0x236a66b7, 0xa197, 0x48cb, 0x80, 0xfd, 0xb2, 0x90, 0xc1, 0xb8, 0x34, 0xae)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CHardInfoActiveXCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DHardInfoActiveX = { 0x3052EBAE, 0x7C7D, 0x4237, { 0xB6, 0x5A, 0x69, 0x34, 0x4F, 0xED, 0xDB, 0x43 } };
const IID IID_DHardInfoActiveXEvents = { 0x66E776CD, 0xAF10, 0x4F04, { 0xA7, 0x41, 0x73, 0xDB, 0xA, 0x6D, 0x71, 0xC } };

// �ؼ�������Ϣ

static const DWORD _dwHardInfoActiveXOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CHardInfoActiveXCtrl, IDS_HARDINFOACTIVEX, _dwHardInfoActiveXOleMisc)

// CHardInfoActiveXCtrl::CHardInfoActiveXCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CHardInfoActiveXCtrl ��ϵͳע�����

BOOL CHardInfoActiveXCtrl::CHardInfoActiveXCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

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


// CHardInfoActiveXCtrl::CHardInfoActiveXCtrl - ���캯��

CHardInfoActiveXCtrl::CHardInfoActiveXCtrl()
{
	InitializeIIDs(&IID_DHardInfoActiveX, &IID_DHardInfoActiveXEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CHardInfoActiveXCtrl::~CHardInfoActiveXCtrl - ��������

CHardInfoActiveXCtrl::~CHardInfoActiveXCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CHardInfoActiveXCtrl::OnDraw - ��ͼ����

void CHardInfoActiveXCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CHardInfoActiveXCtrl::DoPropExchange - �־���֧��

void CHardInfoActiveXCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CHardInfoActiveXCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CHardInfoActiveXCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CHardInfoActiveXCtrl::AboutBox - ���û���ʾ�����ڡ���

void CHardInfoActiveXCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_HARDINFOACTIVEX);
	dlgAbout.DoModal();
}


// CHardInfoActiveXCtrl ��Ϣ�������


BSTR CHardInfoActiveXCtrl::getCpuId()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������
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

	// TODO:  �ڴ���ӵ��ȴ���������

	return strResult.AllocSysString();
}


BSTR CHardInfoActiveXCtrl::getBiosId()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������

	return strResult.AllocSysString();
}


BSTR CHardInfoActiveXCtrl::getDiskId()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������

	return strResult.AllocSysString();
}


BSTR CHardInfoActiveXCtrl::getMacAddress()
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO:  �ڴ���ӵ��ȴ���������

	return strResult.AllocSysString();
}
