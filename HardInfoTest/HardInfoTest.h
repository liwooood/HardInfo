
// HardInfoTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CHardInfoTestApp: 
// �йش����ʵ�֣������ HardInfoTest.cpp
//

class CHardInfoTestApp : public CWinApp
{
public:
	CHardInfoTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CHardInfoTestApp theApp;