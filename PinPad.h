#pragma once
#include "afxwin.h"


// CPinPad dialog

class CPinPad : public CDialog
{
	DECLARE_DYNAMIC(CPinPad)

public:
	CPinPad(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPinPad();

// Dialog Data
	enum { IDD = IDD_PINPAD_DIALOG };

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
	afx_msg void OnEnChangePinEdit();
	CEdit cntPinDisplay;


public:
	CString	Pin;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedBackspace();
};



