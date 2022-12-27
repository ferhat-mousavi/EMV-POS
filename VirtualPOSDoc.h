// VirtualPOSDoc.h : interface of the CVirtualPOSDoc class
// Ferhat Mousavi July, 2006

#pragma once



class CVirtualPOSDoc : public CDocument
{
protected: // create from serialization only
	CVirtualPOSDoc();
	DECLARE_DYNCREATE(CVirtualPOSDoc)

// Attributes
public:
// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CVirtualPOSDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()



};


