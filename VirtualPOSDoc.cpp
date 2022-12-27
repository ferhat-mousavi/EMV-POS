// VirtualPOSDoc.cpp : implementation of the CVirtualPOSDoc class
//

#include "stdafx.h"
#include "VirtualPOS.h"

#include "VirtualPOSDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CVirtualPOSDoc

IMPLEMENT_DYNCREATE(CVirtualPOSDoc, CDocument)

BEGIN_MESSAGE_MAP(CVirtualPOSDoc, CDocument)
	
END_MESSAGE_MAP()


// CVirtualPOSDoc construction/destruction

CVirtualPOSDoc::CVirtualPOSDoc()
{
	// TODO: add one-time construction code here

}

CVirtualPOSDoc::~CVirtualPOSDoc()
{
}

BOOL CVirtualPOSDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CVirtualPOSDoc serialization

void CVirtualPOSDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CVirtualPOSDoc diagnostics

#ifdef _DEBUG
void CVirtualPOSDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVirtualPOSDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CVirtualPOSDoc commands

