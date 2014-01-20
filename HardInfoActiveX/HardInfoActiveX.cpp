// HardInfoActiveX.cpp : CHardInfoActiveXApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "HardInfoActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CHardInfoActiveXApp theApp;

const GUID CDECL _tlid = { 0x114D5E4B, 0x4250, 0x4E9A, { 0xB6, 0x92, 0x9E, 0x88, 0x95, 0xC1, 0x1, 0x15 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CHardInfoActiveXApp::InitInstance - DLL ��ʼ��

BOOL CHardInfoActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CHardInfoActiveXApp::ExitInstance - DLL ��ֹ

int CHardInfoActiveXApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
