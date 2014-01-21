#pragma once

// HardInfoActiveXCtrl.h : CHardInfoActiveXCtrl ActiveX 控件类的声明。


// CHardInfoActiveXCtrl : 有关实现的信息，请参阅 HardInfoActiveXCtrl.cpp。

class CHardInfoActiveXCtrl : public COleControl
{
	DECLARE_DYNCREATE(CHardInfoActiveXCtrl)

// 构造函数
public:
	CHardInfoActiveXCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CHardInfoActiveXCtrl();

	DECLARE_OLECREATE_EX(CHardInfoActiveXCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CHardInfoActiveXCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CHardInfoActiveXCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CHardInfoActiveXCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
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

