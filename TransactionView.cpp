// TransactionView.cpp : implementation file
//

#include "stdafx.h"
#include "VirtualPOS.h"
#include "VirtualPOSDoc.h"
#include "TransactionView.h"


// CTransactionView

IMPLEMENT_DYNCREATE(CTransactionView, CListView)

CTransactionView::CTransactionView()
{
}

CTransactionView::~CTransactionView()
{
}

BEGIN_MESSAGE_MAP(CTransactionView, CListView)
END_MESSAGE_MAP()


// CTransactionView diagnostics

#ifdef _DEBUG
void CTransactionView::AssertValid() const
{
	CListView::AssertValid();
}

void CTransactionView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif //_DEBUG


// CTransactionView message handlers

void CTransactionView::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	CListCtrl& rCtrl = GetListCtrl();
	rCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES|LVS_REPORT);
	rCtrl.InsertColumn(1,"Date",LVCFMT_CENTER,80);
	rCtrl.InsertColumn(2,"Time",LVCFMT_CENTER,70);
	rCtrl.InsertColumn(3,"Batch No",LVCFMT_CENTER,75);
	rCtrl.InsertColumn(4,"Seq. No",LVCFMT_CENTER,70);
	rCtrl.InsertColumn(5,"Trans. Type",LVCFMT_CENTER,95);
	rCtrl.InsertColumn(6,"Amount",LVCFMT_CENTER,80);
	rCtrl.InsertColumn(7,"Card Number (PAN)",LVCFMT_CENTER,155);
	rCtrl.InsertColumn(8,"Exp. Date",LVCFMT_CENTER,90);
	rCtrl.InsertColumn(9,"Res. Code",LVCFMT_CENTER,75);
	rCtrl.InsertColumn(10,"Strip Data",LVCFMT_LEFT,300);
	rCtrl.InsertColumn(11,"Description",LVCFMT_LEFT,300);

	rCtrl.SetBkColor( RGB( 210, 210, 255) );
	rCtrl.SetTextBkColor( RGB( 100, 100, 100) );
	rCtrl.SetTextColor( RGB( 255, 255, 255) );


}

BOOL CTransactionView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= LVS_REPORT;

	return CListView::PreCreateWindow(cs);
}

BOOL CTransactionView::AddTarnsaction( CString Date, CString Time, CString BatchNo, CString SeqNo, CString TransType, CString Amount, CString CardNumber, CString ExpDate, CString ResCode, CString StripData, CString Description )
{


	// Prepare Card Number for display - START
	BYTE PCardNumber[24] ;

	memset( PCardNumber, 0, 24 );
	memcpy( PCardNumber, CardNumber.GetBuffer(), CardNumber.GetLength() );

	if(PCardNumber[16]>='0') 
	{
//		CardNumber.Format( "%.4s %.4s %.4s %.4s %.3s\0"
		CardNumber.Format( "%.4s **** **** %.4s %.3s\0"
		 			 ,PCardNumber
//			 		 ,PCardNumber+4
//		 			 ,PCardNumber+8
		 			 ,PCardNumber+12
		 			 ,PCardNumber+16);
	}
	else if(PCardNumber[13]>='0') 
	{
//		CardNumber.Format( "%.4s %.4s %.4s %.4s\0"
		CardNumber.Format( "%.4s **** **** %.4s\0"
		 			 ,PCardNumber
//			 		 ,PCardNumber+4
//			 		 ,PCardNumber+8
		 			 ,PCardNumber+12 );
	}
	else
	{
//		CardNumber.Format( "%.4s %.3s %.3s %.3s\0"
		CardNumber.Format( "%.4s *** *** %.3s\0"
			 		 ,PCardNumber
//			 		 ,PCardNumber+4
//			 		 ,PCardNumber+7
				 	 ,PCardNumber+10 );
	}
	// Prepare Card Number for display - START


	CListCtrl& rCtrl = GetListCtrl();

	int nItem = rCtrl.InsertItem(0, Date );
	rCtrl.SetItemText(nItem, 1, Time );
	rCtrl.SetItemText(nItem, 2, BatchNo );
	rCtrl.SetItemText(nItem, 3, SeqNo );
	rCtrl.SetItemText(nItem, 4, TransType );
	rCtrl.SetItemText(nItem, 5, Amount );
	rCtrl.SetItemText(nItem, 6, CardNumber );
	rCtrl.SetItemText(nItem, 7, ExpDate );
	rCtrl.SetItemText(nItem, 8, ResCode );
	rCtrl.SetItemText(nItem, 9, StripData );
	rCtrl.SetItemText(nItem, 10, Description );

	return TRUE;
}


