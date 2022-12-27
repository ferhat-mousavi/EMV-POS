#pragma once
#include "afxwin.h"


// CVirtualPosSetting dialog

class CVirtualPosSetting : public CDialog
{
	DECLARE_DYNAMIC(CVirtualPosSetting)

public:
	CVirtualPosSetting(CWnd* pParent = NULL);   // standard constructor
	virtual ~CVirtualPosSetting();

// Dialog Data
	enum { IDD = IDD_VPSETTING_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_cntv_ReaderCheck;
};
