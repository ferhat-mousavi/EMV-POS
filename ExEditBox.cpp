// ExtendedEditBox.cpp : implementation file
//

#include "stdafx.h"
#include "ExEditBox.h"

#include <math.h>


// Static Members
const BYTE CExEditBox::EDT_NUMERIC = 0x01;
const BYTE CExEditBox::EDT_ALPHANUMERIC = 0x02;
const BYTE CExEditBox::EDT_FLOATINGPOINT = 0x04;
const BYTE CExEditBox::EDT_AMOUNT = 0x08;
const BYTE CExEditBox::EDT_HEX = 0x10;

const BYTE CExEditBox::EDT_COLOR_WHITE = 0x01;
const BYTE CExEditBox::EDT_COLOR_YELLOW = 0x02;
const BYTE CExEditBox::EDT_COLOR_RED = 0x04;
const BYTE CExEditBox::EDT_COLOR_BLACK = 0x08;


// CExtendedEditBox

IMPLEMENT_DYNAMIC(CExEditBox, CEdit)
CExEditBox::CExEditBox():
				m_MaxLen( 2048 ),
				m_EditType( EDT_ALPHANUMERIC ),
				m_w_FlotingPoint( 2 ),
				m_b_Separator( '.' )
{
	ExSetBackColor( EDT_COLOR_WHITE );
	ExSetTextColor( EDT_COLOR_BLACK );
}

CExEditBox::~CExEditBox()
{
	  m_br_Background.DeleteObject();
}


BEGIN_MESSAGE_MAP(CExEditBox, CEdit)

	ON_CONTROL_REFLECT_EX(EN_UPDATE, OnUpdate)
	ON_WM_CTLCOLOR_REFLECT()
	
	//ON_WM_PAINT()

END_MESSAGE_MAP()



// CExEditBox message handlers

void CExEditBox::OnPaint()
{
    CPaintDC dc(this); // device context for painting

    // TODO: Add your message handler code here
	CString strText;
	GetWindowText( strText );
	// Delete the old brush
    m_br_Background.DeleteObject();
    // Create a new brush in the specified color
    m_br_Background.CreateSolidBrush(m_clr_Background);
    CDC* pDC = GetDC();
    pDC->SetBkMode(OPAQUE);
    pDC->SetBkColor(m_clr_Background);
    // Select the brush into this window’s device context
    pDC->SelectObject(&m_br_Background);
    CRect rc;
    // Get the client area of the edit control
    GetClientRect(&rc);
    ScreenToClient(&rc);
    // Apply the device context to the client area of the edit control
    pDC->Rectangle(0, 0, rc.Width(), rc.Height());
    // Rewrite the text since the backcolor paint
    // overwrote the existing text
    pDC->SetTextColor( m_clr_Foreground );
   // pDC->TextOut(2, 2, m_EditText.GetBuffer(m_EditText.GetLength()));
	SetWindowText(strText);

	//OnUpdate();
    // Do not call CEdit::OnPaint() for painting messages
	CEdit::OnPaint();
}

HBRUSH CExEditBox::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	pDC->SetTextColor( m_clr_Foreground );		// color of the text
	pDC->SetBkColor( m_clr_Background );		// color of the text background

    m_br_Background.DeleteObject();
	m_br_Background.CreateSolidBrush( m_clr_Background );
	return m_br_Background;
}


BOOL CExEditBox::OnUpdate() 
{
	//	Local Variables
	CString strText;
	CString strSave;
	int nSelBeg;
	int nSelEnd;


	GetWindowText( strText );
	strSave = strText;			
	GetSel( nSelBeg,nSelEnd );

	ValidateText(strText);

	if(strSave != strText)
	{
		SetWindowText(strText);
		if( m_EditType==EDT_HEX ) nSelBeg=nSelEnd=strText.GetLength();
		SetSel(nSelBeg,nSelEnd);
	}
	return(FALSE);
}



void CExEditBox::ValidateText(CString& Text)
{
	CString CurrentText;
	LPBYTE	pCurrentText = new BYTE[m_MaxLen+3];
	LPBYTE	pCurrectText = new BYTE[m_MaxLen+3];
	WORD	wLen, i, j;

	if( Text.GetLength()>=m_MaxLen )
	{
		wLen = m_MaxLen;
	}
	else
	{
		wLen = Text.GetLength();
	}

	memcpy( pCurrentText, Text.GetBuffer(), wLen );
	pCurrentText[wLen]=0;

	switch( m_EditType )
	{
		case EDT_ALPHANUMERIC:
			memcpy( pCurrectText, pCurrentText, wLen );
			pCurrectText[wLen]=0;
			break;
		case EDT_FLOATINGPOINT:
		case EDT_AMOUNT:
			WORD wPoitPos;
			for( j=0, i=0; i<wLen; i++ )
				if( (pCurrentText[i]>='0' && pCurrentText[i]<='9') || pCurrentText[i]==m_b_Separator ) pCurrectText[j++]=pCurrentText[i];
			pCurrectText[j] = 0;
			wLen = (WORD) strlen( (char*)pCurrectText );
			memcpy( pCurrentText, pCurrectText, wLen );
			pCurrentText[wLen]=0;
			{	// find separator of floatingpoint number and check for only typing one separator
				BOOL PointFounded=FALSE;
				for( i=0; i<wLen; i++ )
				{
					if( pCurrentText[i]==m_b_Separator && PointFounded )
					{
						pCurrentText[i]=0;
					}
					if( pCurrentText[i]==m_b_Separator && !PointFounded ) 
					{ 
						PointFounded=TRUE;
						pCurrentText[i+m_w_FlotingPoint+1]=0; 
					}
				}
			}
			wPoitPos = i;
			wLen = (WORD) strlen( (char*)pCurrentText );
			memcpy( pCurrectText, pCurrentText, wLen );
			pCurrectText[wLen] = 0;
			break;
		case EDT_HEX:
			for( j=0, i=0; i<wLen; i++ )
				if( (pCurrentText[i]>='0' && pCurrentText[i]<='9')||
					(pCurrentText[i]>='A' && pCurrentText[i]<='F')||
					(pCurrentText[i]>='a' && pCurrentText[i]<='f')) pCurrectText[j++]=pCurrentText[i];
			pCurrectText[j] = 0;
			wLen = (WORD) strlen( (char*)pCurrectText );
			memcpy( pCurrentText, pCurrectText, wLen );
			for( j=0, i=0; i<wLen; i++ ) 
				if( pCurrentText[i]>='a' && pCurrentText[i]<='f' ) pCurrentText[i]=pCurrentText[i]+('A'-'a');
			for( j=0, i=0; i<wLen; i++ ) 
				if( (i+1)%2 ) pCurrectText[j++]=pCurrentText[i];
				else { pCurrectText[j++]=pCurrentText[i]; pCurrectText[j++]=' '; }
			if( pCurrectText[j-1]==' ' ) pCurrectText[j-1]=0;
			else pCurrectText[j] = 0;
			wLen = (WORD) strlen( (char*)pCurrectText );
			break;
		default:
			sprintf( (char*)pCurrectText, "< ERROR >" );
			break;
	}

	Text = CString( pCurrectText );
	delete []pCurrentText;
	delete []pCurrectText;
}

void CExEditBox::ExSetFloatingPoint( WORD wFlotingPoint )
{
	m_w_FlotingPoint = wFlotingPoint;
}

void CExEditBox::ExSetEditType( BYTE EditType )
{
	switch( EditType )
	{
		case EDT_NUMERIC:
			m_EditType = EDT_NUMERIC;
			break;
		case EDT_FLOATINGPOINT:
			m_EditType = EDT_FLOATINGPOINT;
			break;
		case EDT_AMOUNT:
			m_EditType = EDT_AMOUNT;
			break;
		case EDT_HEX:
			m_EditType = EDT_HEX;
			break;
		default:
			m_EditType = EDT_ALPHANUMERIC;
	}
}

void CExEditBox::ExSetText( CString csText )
{
	ExSetText( csText.GetBuffer() );
}

void CExEditBox::ExSetText( LPCSTR lpszText )
{
	CString strText = lpszText;		

	ValidateText(strText);			
	SetWindowText(strText);		
	OnUpdate();
}

void CExEditBox::ExGetText( CString& rcsText )
{
	CString csWinText;
	GetWindowText( csWinText );
	rcsText = csWinText;
}

void CExEditBox::ExGetDWORD( DWORD& rdwNumber )
{
	DWORD	number=0;
	WORD	i, j, wLen;
	LPBYTE	pCurrentText = new BYTE[m_MaxLen+1];
	LPBYTE	pCurrectText = new BYTE[m_MaxLen+1];
	CString csText;
	WORD wPoitPos, wFloatNum;

	if( m_EditType==EDT_AMOUNT || m_EditType==EDT_FLOATINGPOINT )
	{
		ExGetText( csText );
		wLen = csText.GetLength();

		memcpy( pCurrentText, csText.GetBuffer(), wLen );
		pCurrentText[wLen]=0;

		for( i=0; i<wLen; i++ )
				if( pCurrentText[i]==m_b_Separator ) break;
		wPoitPos = i;
		if( wLen==wPoitPos ) wFloatNum=0;
		else wFloatNum = wLen - wPoitPos - 1;

		for( j=0, i=0; i<wLen; i++ )
				if( (pCurrentText[i]>='0' && pCurrentText[i]<='9') ) pCurrectText[j++]=pCurrentText[i];
		pCurrectText[j] = 0;
		wLen = (WORD) strlen( (char*)pCurrectText );
		number = atol( (char*)pCurrectText ) * (DWORD)pow(10, m_w_FlotingPoint-wFloatNum );
		rdwNumber=number;
	}
	else
	{
		rdwNumber=number;
	}
	delete []pCurrentText;
	delete []pCurrectText;

}


void CExEditBox::ExSetMaxLen( WORD wLen )
{
	if( wLen<=2048 )
        m_MaxLen = wLen;
	else
		m_MaxLen = 2048;
}

void CExEditBox::ExSetSeparator( BYTE bSep )
{
	if( bSep=='.' || bSep==',' ) m_b_Separator=bSep;
}

void CExEditBox::ExSetBackColor( BYTE bBackColor )
{
	switch( bBackColor )
	{
		case EDT_COLOR_WHITE:
			m_clr_Background = RGB( 255, 255, 255);
			break;
		case EDT_COLOR_YELLOW:
			m_clr_Background = RGB( 255, 255, 0);
			break;
		case EDT_COLOR_RED:
			m_clr_Background = RGB( 255, 0, 0);
			break;
		case EDT_COLOR_BLACK:
			m_clr_Background = RGB( 0, 0, 0);
			break;
		default:
			break;
	}
}

void CExEditBox::ExSetTextColor( BYTE bForeColor )
{
	switch( bForeColor )
	{
		case EDT_COLOR_WHITE:
			m_clr_Foreground = RGB( 255, 255, 255);
			break;
		case EDT_COLOR_YELLOW:
			m_clr_Foreground = RGB( 255, 255, 0);
			break;
		case EDT_COLOR_RED:
			m_clr_Foreground = RGB( 255, 0, 0);
			break;
		case EDT_COLOR_BLACK:
			m_clr_Foreground = RGB( 0, 0, 0);
			break;
		default:
			break;
	}
}

