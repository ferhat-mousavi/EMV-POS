// InputAmount.cpp : implementation file
//

#include "stdafx.h"
#include "VirtualPOS.h"
#include "InputAmount.h"
#include ".\inputamount.h"


// CInputAmount dialog

IMPLEMENT_DYNAMIC(CInputAmount, CDialog)
CInputAmount::CInputAmount(CWnd* pParent /*=NULL*/)
	: CDialog(CInputAmount::IDD, pParent)
	, Amount(0)
{
}

CInputAmount::~CInputAmount()
{
}

void CInputAmount::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_AMOUNT_EDIT, cntAmountEdit);
}


BEGIN_MESSAGE_MAP(CInputAmount, CDialog)
	ON_EN_CHANGE(IDC_AMOUNT_EDIT, OnEnChangeAmountEdit)
END_MESSAGE_MAP()


BOOL CInputAmount::OnInitDialog()
{
	CDialog::OnInitDialog();

	cntAmountEdit.ExSetEditType( CExEditBox::EDT_AMOUNT );
	cntAmountEdit.ExSetMaxLen( 10 );
	cntAmountEdit.ExSetSeparator( ',' );
	cntAmountEdit.ExSetTextColor( CExEditBox::EDT_COLOR_RED );
	cntAmountEdit.ExSetBackColor( CExEditBox::EDT_COLOR_YELLOW );
	
	return TRUE;
}

// CInputAmount message handlers

void CInputAmount::OnEnChangeAmountEdit()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	cntAmountEdit.ExGetText( strAmount );
	cntAmountEdit.ExGetDWORD( Amount );

}

void CInputAmount::OnOK() 
{
	CDialog::OnOK();
}

void CInputAmount::OnCancel() 
{
	CDialog::OnCancel();
}



