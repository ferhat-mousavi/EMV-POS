#pragma once


// CTransactionView view

class CTransactionView : public CListView
{
	DECLARE_DYNCREATE(CTransactionView)

protected:
	CTransactionView();           // protected constructor used by dynamic creation
	virtual ~CTransactionView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);


public:
	BOOL AddTarnsaction( CString Date, CString Time, CString BatchNo, CString SeqNo, CString TransType, CString Amount, CString CardNumber, CString ExpDate, CString ResCode, CString StripData, CString Description );


};


