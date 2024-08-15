// VirtualPOSView.h : interface of the CVirtualPOSView class
//


#pragma once


class CVirtualPOSView : public CView
{
protected: // create from serialization only
	CVirtualPOSView();
	DECLARE_DYNCREATE(CVirtualPOSView)

// Attributes
public:
	CVirtualPOSDoc* GetDocument() const;

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CVirtualPOSView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in VirtualPOSView.cpp
inline CVirtualPOSDoc* CVirtualPOSView::GetDocument() const
   { return reinterpret_cast<CVirtualPOSDoc*>(m_pDocument); }
#endif

