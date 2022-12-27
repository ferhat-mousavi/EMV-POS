#pragma once

// CExtendedEditBox

class CExEditBox : public CEdit
{
	DECLARE_DYNAMIC(CExEditBox)

public:
	CExEditBox();
	virtual ~CExEditBox();
	void ExSetMaxLen( WORD wLen ); // Set Input Type
	void ExSetSeparator( BYTE bSep ); // Set Separator of Flotingpoint
	void ExSetBackColor( BYTE bBackColor ); // Set Background Color of Text
	void ExSetTextColor( BYTE bForeColor ); // Set Text Color
	void ExSetEditType( BYTE EditType ); // Set Input Type
	void ExSetText( LPCSTR lpszText ); // Set EditBox Text
	void ExSetText( CString csText ); // Set EditBox Text
	void ExGetText( CString& rcsText ); // Set EditBox Text
	void ExGetDWORD( DWORD& rdwNumber );
	void ExSetFloatingPoint( WORD wFlotingPoint );

	static const BYTE EDT_NUMERIC;
	static const BYTE EDT_ALPHANUMERIC;
	static const BYTE EDT_FLOATINGPOINT;
	static const BYTE EDT_AMOUNT;
	static const BYTE EDT_HEX;

	static const BYTE EDT_COLOR_WHITE;
	static const BYTE EDT_COLOR_YELLOW;
	static const BYTE EDT_COLOR_RED;
	static const BYTE EDT_COLOR_BLACK;


protected:
	void OnPaint();

	afx_msg BOOL OnUpdate();
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	DECLARE_MESSAGE_MAP()

private:
	void	ValidateText(CString& Text);

	WORD		m_MaxLen;
	BYTE		m_EditType;
	WORD		m_w_FlotingPoint;
	BYTE		m_b_Separator;
	COLORREF	m_clr_Background;	//  Color of the control background
	COLORREF	m_clr_Foreground;	//  Color of the control foreground
	CBrush		m_br_Background;   //	Brush for the background
};


