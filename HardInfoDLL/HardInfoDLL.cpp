#include "HardInfoDLL.h"

#include <tchar.h>
#include <comdef.h>
#include <Wbemidl.h>
#pragma comment(lib, "wbemuuid.lib")


bool GetCpuId(char* id)
{
	return GetHardInfoByWMI("SELECT * FROM Win32_Processor", L"ProcessorID", id);
}

bool GetMainBoardId(char* id)
{
	return GetHardInfoByWMI("SELECT * FROM Win32_BaseBoard", L"SerialNumber", id);
}

bool GetBiosId(char* id)
{
	return GetHardInfoByWMI("SELECT * FROM Win32_BIOS", L"SerialNumber", id);
}

bool GetDiskId(char* id)
{
	return GetHardInfoByWMI("SELECT * FROM Win32_DiskDrive", L"SerialNumber", id);
}

bool GetMacAddress(char* mac)
{
	return GetHardInfoByWMI("SELECT * FROM Win32_NetworkAdapter WHERE (MACAddress Is Not NULL) AND (NetConnectionStatus = 2) AND (PNPDeviceID LIKE '%PCI%')", L"MACAddress", mac);
}

bool GetHardInfoByWMI(const char* wql, LPCWSTR prop, char* value)
{
	bool bRet = false;

	HRESULT hr;
	IWbemLocator *pLoc = NULL;
	IWbemServices *pSvc = NULL;
	IEnumWbemClassObject* pEnumerator = NULL;
	IWbemClassObject *pclsObj = NULL;

	if (wql == NULL || prop == NULL)
		return bRet;

	hr = CoInitializeEx(0, COINIT_MULTITHREADED);
	if (FAILED(hr))
	{
		return bRet;
	}


	hr = CoInitializeSecurity(
		NULL,
		-1,      // COM negotiates service                  
		NULL,    // Authentication services
		NULL,    // Reserved
		RPC_C_AUTHN_LEVEL_DEFAULT,    // authentication
		RPC_C_IMP_LEVEL_IMPERSONATE,  // Impersonation
		NULL,             // Authentication info 
		EOAC_NONE,        // Additional capabilities
		NULL              // Reserved
		);
	if (FAILED(hr))
	{
		goto error;
	}


	hr = CoCreateInstance(
		CLSID_WbemLocator,
		0,
		CLSCTX_INPROC_SERVER,
		IID_IWbemLocator, (LPVOID *)&pLoc);
	if (FAILED(hr))
	{
		goto error;
	}


	hr = pLoc->ConnectServer(
		_bstr_t(L"ROOT\\CIMV2"), // WMI namespace
		NULL,                    // User name
		NULL,                    // User password
		0,                       // Locale
		NULL,                    // Security flags                 
		0,                       // Authority       
		0,                       // Context object
		&pSvc                    // IWbemServices proxy
		);
	if (FAILED(hr))
	{
		goto error;
	}

	hr = CoSetProxyBlanket(
		pSvc,                         // the proxy to set
		RPC_C_AUTHN_WINNT,            // authentication service
		RPC_C_AUTHZ_NONE,             // authorization service
		NULL,                         // Server principal name
		RPC_C_AUTHN_LEVEL_CALL,       // authentication level
		RPC_C_IMP_LEVEL_IMPERSONATE,  // impersonation level
		NULL,                         // client identity 
		EOAC_NONE                     // proxy capabilities     
		);
	if (FAILED(hr))
	{
		goto error;
	}

	
	hr = pSvc->ExecQuery(
		bstr_t("WQL"),
		bstr_t(wql),
		WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
		NULL,
		&pEnumerator);
	if (FAILED(hr))
	{
		goto error;
	}


	ULONG uReturn = 0;

	while (pEnumerator)
	{
		hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

		if (0 == uReturn)
		{
			break;
		}

		VARIANT vtProp;

		// Get the value of the Name property
		
		hr = pclsObj->Get(prop, 0, &vtProp, 0, 0);
		_bstr_t bstr = vtProp.bstrVal;
		value = bstr;
		bRet = true;
	
		

		VariantClear(&vtProp);
		pclsObj->Release();
		pclsObj = NULL;
	}
	


error:
	if (pSvc != NULL)
	{
		pSvc->Release();
		pSvc = NULL;
	}

	if (pLoc != NULL)
	{
		pLoc->Release();
		pLoc = NULL;
	}

	if (pEnumerator != NULL)
	{
		pEnumerator->Release();
		pEnumerator = NULL;
	}



	CoUninitialize();

	return bRet;
}
