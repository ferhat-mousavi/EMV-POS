// VirtualPosSetting.cpp : implementation file
//

#include "stdafx.h"
#include "VirtualPOS.h"
#include "VirtualPosSetting.h"


// CVirtualPosSetting dialog

IMPLEMENT_DYNAMIC(CVirtualPosSetting, CDialog)
CVirtualPosSetting::CVirtualPosSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CVirtualPosSetting::IDD, pParent)
	, m_cntv_ReaderCheck(FALSE)
{
	m_cntv_ReaderCheck=TRUE;
}

CVirtualPosSetting::~CVirtualPosSetting()
{
}

void CVirtualPosSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_READER_CHECK, m_cntv_ReaderCheck);
}


BEGIN_MESSAGE_MAP(CVirtualPosSetting, CDialog)
END_MESSAGE_MAP()


// CVirtualPosSetting message handlers
