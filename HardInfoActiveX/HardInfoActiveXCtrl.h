#pragma once

// HardInfoActiveXCtrl.h : CHardInfoActiveXCtrl ActiveX �ؼ����������


// CHardInfoActiveXCtrl : �й�ʵ�ֵ���Ϣ������� HardInfoActiveXCtrl.cpp��

class CHardInfoActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CHardInfoActiveXCtrl)

// ���캯��
public:
	CHardInfoActiveXCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CHardInfoActiveXCtrl();

	DECLARE_OLECREATE_EX(CHardInfoActiveXCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CHardInfoActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CHardInfoActiveXCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CHardInfoActiveXCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidgetMacAddress = 5L,
		dispidgetDiskId = 4L,
		dispidgetBiosId = 3L,
		dispidgetMainBoardId = 2L,
		dispidGetCpuId = 1L
	};
protected:
	BSTR getCpuId();
	BSTR getMainBoardId();
	BSTR getBiosId();
	BSTR getDiskId();
	BSTR getMacAddress();
};

