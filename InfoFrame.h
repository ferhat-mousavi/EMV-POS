

#pragma once
#include "afxwin.h"




// CInfoFrame form view

class CInfoFrame : public CFormView 
{
	DECLARE_DYNCREATE(CInfoFrame)


protected:
	CInfoFrame();           // protected constructor used by dynamic creation
	virtual ~CInfoFrame();

public:
	enum { IDD = IDD_INFO_FRAME };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate( );

	DECLARE_MESSAGE_MAP()

public:
	CComboBox cntTransType;
	CStatic cntReaderName;
	CListCtrl cntSmartTransList;
	CStatic cntMessageBox1;
	CStatic cntMessageBox2;
	CStatic cntMessageBox3;
	CEdit cntTerminalID;
	CEdit cntMerchantID;
	CEdit cntCurrBatchNo;
	CEdit cntCurrSeqNo;
	CEdit cntMerchantName;
};


