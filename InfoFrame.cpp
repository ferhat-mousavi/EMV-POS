// InfoFrame.cpp : implementation file
//

#include "stdafx.h"
#include "VirtualPOS.h"
#include "InfoFrame.h"



// CInfoFrame

IMPLEMENT_DYNCREATE(CInfoFrame, CFormView)

CInfoFrame::CInfoFrame()
	: CFormView(CInfoFrame::IDD)	
{

}

CInfoFrame::~CInfoFrame()
{
}

void CInfoFrame::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_TRANSTYPE, cntTransType);
	DDX_Control(pDX, IDC_READER_NAME, cntReaderName);
	DDX_Control(pDX, IDC_LIST2, cntSmartTransList);
	DDX_Control(pDX, IDC_TERMINALID, cntTerminalID);
	DDX_Control(pDX, IDC_MERCHANTID, cntMerchantID);
	DDX_Control(pDX, IDC_CURRBATCHNO, cntCurrBatchNo);
	DDX_Control(pDX, IDC_CURRSEQNO, cntCurrSeqNo);
	DDX_Control(pDX, IDC_MESSAGE_BOX1, cntMessageBox1);
	DDX_Control(pDX, IDC_MESSAGE_BOX2, cntMessageBox2);
	DDX_Control(pDX, IDC_MESSAGE_BOX3, cntMessageBox3);
	DDX_Control(pDX, IDC_MERCHANTNAME, cntMerchantName);
}

void CInfoFrame::OnInitialUpdate( )
{
	CFormView::OnInitialUpdate( );

	cntTransType.SetCurSel( 0 );


	
	cntSmartTransList.SetExtendedStyle( LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES  );
	cntSmartTransList.InsertColumn(1, "Smart Sent Data", LVCFMT_LEFT, 200);
	cntSmartTransList.InsertColumn(2, "Smart Recieved Data", LVCFMT_LEFT, 200);

	cntMessageBox1.SetWindowText( "PLESE INSERT YOUR CARD" );
	cntMessageBox2.SetWindowText( "" );
	cntMessageBox3.SetWindowText( "" );

//	cntTerminalID.Set

}

BEGIN_MESSAGE_MAP(CInfoFrame, CFormView)
END_MESSAGE_MAP()


// CInfoFrame diagnostics

#ifdef _DEBUG
void CInfoFrame::AssertValid() const
{
	CFormView::AssertValid();
}

void CInfoFrame::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CInfoFrame message handlers




