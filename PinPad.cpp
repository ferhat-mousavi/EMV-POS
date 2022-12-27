// PinPad.cpp : implementation file
//

#include "stdafx.h"
#include "VirtualPOS.h"
#include "PinPad.h"
#include ".\pinpad.h"


// CPinPad dialog

IMPLEMENT_DYNAMIC(CPinPad, CDialog)
CPinPad::CPinPad(CWnd* pParent /*=NULL*/)
	: CDialog(CPinPad::IDD, pParent)
	, Pin(_T(""))
{
}

CPinPad::~CPinPad()
{
}

void CPinPad::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIN_EDIT, cntPinDisplay);
}


BEGIN_MESSAGE_MAP(CPinPad, CDialog)
	ON_EN_CHANGE(IDC_PIN_EDIT, OnEnChangePinEdit)
	ON_BN_CLICKED(IDC_BUTTON_1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, OnBnClickedButton0)
	ON_BN_CLICKED(IDC_CLEAR, OnBnClickedClear)
	ON_BN_CLICKED(IDC_BACKSPACE, OnBnClickedBackspace)
END_MESSAGE_MAP()

BOOL CPinPad::OnInitDialog()
{
	CDialog::OnInitDialog();

	cntPinDisplay.SetWindowText(Pin);


	return TRUE;
}
// CPinPad message handlers

void CPinPad::OnEnChangePinEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CPinPad::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "1";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "2";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "3";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "4";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "5";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "6";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "7";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "8";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "9";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedButton0()
{
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()<4 )
	{
		Pin += "0";
		cntPinDisplay.SetWindowText(Pin);
	}
}

void CPinPad::OnBnClickedClear()
{
	// TODO: Add your control notification handler code here
	Pin = "";
	cntPinDisplay.SetWindowText(Pin);
}

void CPinPad::OnBnClickedBackspace()
{
	BYTE	tmpPin[24];
	BYTE	tmpPinLen;
	// TODO: Add your control notification handler code here
	if( Pin.GetLength()>0 )
	{
		tmpPinLen =  Pin.GetLength();
		memcpy( tmpPin, Pin.GetBuffer(), tmpPinLen );
		tmpPin[tmpPinLen-1] = 0;
		Pin = CString( tmpPin );
		cntPinDisplay.SetWindowText(Pin);

	}
}



void CPinPad::OnOK() 
{
	CDialog::OnOK();
}

void CPinPad::OnCancel() 
{
	CDialog::OnCancel();
}

