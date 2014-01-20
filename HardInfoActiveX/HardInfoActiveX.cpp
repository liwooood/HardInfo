// HardInfoActiveX.cpp : CHardInfoActiveXApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "HardInfoActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CHardInfoActiveXApp theApp;

const GUID CDECL _tlid = { 0x114D5E4B, 0x4250, 0x4E9A, { 0xB6, 0x92, 0x9E, 0x88, 0x95, 0xC1, 0x1, 0x15 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CHardInfoActiveXApp::InitInstance - DLL 初始化

BOOL CHardInfoActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CHardInfoActiveXApp::ExitInstance - DLL 终止

int CHardInfoActiveXApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
