// VirtualPOSView.cpp : implementation of the CVirtualPOSView class
//

#include "stdafx.h"
#include "VirtualPOS.h"

#include "VirtualPOSDoc.h"
#include "VirtualPOSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVirtualPOSView

IMPLEMENT_DYNCREATE(CVirtualPOSView, CView)

BEGIN_MESSAGE_MAP(CVirtualPOSView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CVirtualPOSView construction/destruction

CVirtualPOSView::CVirtualPOSView()
{
	// TODO: add construction code here

}

CVirtualPOSView::~CVirtualPOSView()
{
}

BOOL CVirtualPOSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CVirtualPOSView drawing

void CVirtualPOSView::OnDraw(CDC* /*pDC*/)
{
	CVirtualPOSDoc* pDoc = GetDocument();
	ASSERT_VALID((CObject*)pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CVirtualPOSView printing

BOOL CVirtualPOSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CVirtualPOSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CVirtualPOSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CVirtualPOSView diagnostics

#ifdef _DEBUG
void CVirtualPOSView::AssertValid() const
{
	CView::AssertValid();
}

void CVirtualPOSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CVirtualPOSDoc* CVirtualPOSView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CVirtualPOSDoc)));
	return (CVirtualPOSDoc*)m_pDocument;
}
#endif //_DEBUG


// CVirtualPOSView message handlers
