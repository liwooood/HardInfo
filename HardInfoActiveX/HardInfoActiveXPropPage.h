#pragma once

// HardInfoActiveXPropPage.h : CHardInfoActiveXPropPage 属性页类的声明。


// CHardInfoActiveXPropPage : 有关实现的信息，请参阅 HardInfoActiveXPropPage.cpp。

class CHardInfoActiveXPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CHardInfoActiveXPropPage)
	DECLARE_OLECREATE_EX(CHardInfoActiveXPropPage)

// 构造函数
public:
	CHardInfoActiveXPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_HARDINFOACTIVEX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

