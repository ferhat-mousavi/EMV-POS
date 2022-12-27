#pragma once
#include "afxwin.h"

#include "ExEditBox.h"


// CInputAmount dialog

class CInputAmount : public CDialog
{
	DECLARE_DYNAMIC(CInputAmount)

public:
	CInputAmount(CWnd* pParent = NULL);   // standard constructor
	virtual ~CInputAmount();

// Dialog Data
	enum { IDD = IDD_INPUTAMOUNT_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	
// Implementation
protected:
	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();


	DECLARE_MESSAGE_MAP()
public:
	CExEditBox cntAmountEdit;


private:
public:
	CString strAmount;
	ULONG Amount;
	afx_msg void OnEnChangeAmountEdit();
};
