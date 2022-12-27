// MainFrm.h : interface of the CMainFrame class
//
#pragma once

#include "smartcard.h"
#include "EMV.h"
#include "afxwin.h"
#include "afxcmn.h"

#include "DEA.h"
class CDEA;

class CSmartCardReader;
class CSmartCardReaderManager;


#define ACK	     		6
#define NAK	    		21
#define ENQ	     		5
#define DLE	    		16
#define EOT	     		4
#define SOH      		1
#define STX	     		2
#define ETX	     		3
#define FS	    		28
#define US	    		31
#define CAN     		24


typedef struct 
{
	WORD 	SequenceNo;
		// do not change the order from Year to Minute, ST_CLOCK is copied
	BYTE 	Year;
	BYTE 	Month;
	BYTE	Day;
	BYTE	Hour;
	BYTE	Minute;
	BYTE 	Void;
	BYTE	DataSource;
	BYTE	AuthSource;
	BYTE	IDCode;
	BYTE	TXType;
	BYTE	NameOffset;
	BYTE	InfoByte;
	BYTE 	CardLen;
	BYTE 	PCardNo[11];
	BYTE 	Expiry[2];
	DWORD 	Amount;
	BYTE 	AuthNo[6];
	BYTE 	AdviseFlag;
	BYTE 	ScriptRes[5];
	BYTE	AC[8];
	BYTE	TVR[5];
	BYTE	ATC[2];
	BYTE	AIP[2];
	BYTE	UnprNum[4];
	BYTE	IssAppData[32];
	BYTE	IssAppDataLen;
	BYTE	DFName[16];
	BYTE	DFNameLen;
	BYTE	CID;
	BYTE	AppVersNum[2];
	BYTE	PANSeqNo;
	BYTE	DiffByte;
} MDCTYPE; /* Size 38 */




class CInfoFrame;
class CTransactionView;
class CVirtualPOSDoc;


class CMainFrame : public CFrameWnd , CEMV 
{
	
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)


// Overrides
public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CSplitterWnd	m_wndSplitter;
	CStatusBar		m_wndStatusBar;
	CToolBar		m_wndToolBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnActivate(UINT nState,CWnd* pWndOther,BOOL bMinimized);
	afx_msg void OnShowWindow(BOOL bShow,UINT nStatus);


	DECLARE_MESSAGE_MAP()


private:
	CString m_ReaderName;


private:
	void XOR( LPBYTE B1, LPBYTE B2, LPBYTE Result );

public:
	BYTE		m_CardNumber[24];
	BYTE		m_Expiry[5];
	BYTE		m_ServiceCode[4];
	BYTE		m_StripeData[65];
	BYTE		m_CardHolderName[25];
	BYTE		m_MasterKey[16];
	BYTE		m_InsKey[16];
	MDCTYPE		m_T;


	DWORD		m_BatchNo;
	DWORD		m_SeqNo;

	CString		m_strTerminalID;
	CString		m_strMerchantID;
	CString		m_strMerchantName;
	CString		m_strAmount;
	CString		m_strCardNumber;
	CString		m_strExpiry;
	CString		m_strStripeData;
	CString		m_strResponseCode;
	CString		m_strTranType;

private:
	CRITICAL_SECTION			m_cs;
	CSmartCardReader*			m_pReader;
	CSmartCardReaderManager*	m_ReaderManager;
	CSmartCard					m_card;
	BOOL						m_bReady;

public:
	void Lock() { EnterCriticalSection(&m_cs); };
	void Unlock() { LeaveCriticalSection(&m_cs); };
	void OnReaderMessage(CSmartCardReader* pReader);
	void OnReaderMessageEx(CSmartCardReader* pReader);
	afx_msg LONG OnReaderMessage(WPARAM wParam, LPARAM dummy);
	void OnInsertCard(CSmartCardReader* pReader, LPSCARD_READERSTATE pReaderState);
	void OnRemoveCard(CSmartCardReader* pReader);

	// Override class CEMV virtual functions
	virtual BYTE ExtractFromChip( void );

	virtual BYTE SendSmartData(WORD SendLen, LPBYTE CardSendData, WORD &OutLen, LPBYTE CardReplyData);
	virtual BYTE FillTermParams( void );
	virtual void SetTermVersion( void );
	virtual BYTE CheckPinBlockBIN( void );
	virtual BYTE GetPin( BYTE UseMAC, LPBYTE PinBl ,BYTE PlainFlag );
	virtual void PrepCAKEYS( void );
	virtual BYTE GetTxType( void );
	virtual BYTE SplitSale( LPBYTE PCardNumber, LPDWORD pxTotAmount );
	virtual void GetOnlineTags( LPBYTE OnlineTags );
	virtual BYTE GetBankDecision( void );
	virtual BYTE InputAmount( ULONG &Amount );
	virtual BYTE DisplayDebug( CString message );
	//virtual BYTE DisplayMessage( CString message );
	virtual BYTE DisplayMessage( WORD Line, CString message, BOOL ClearLines=TRUE );
	virtual BYTE DisplayClear( void );
	virtual BYTE AddRec( void );
	virtual INT DisplayAppMenu( CHIPMENU *pxMenu, UCHAR ucSize );
	
	virtual bool WriteLogFile(CString logMessage);
	virtual bool WriteLogFile(CString title, CString logMessage);
	virtual bool WriteLogFile(DWORD BuffLen, LPBYTE BuffData); 
	virtual bool WriteLogFile(CString title, DWORD index, CString logMessage);
	virtual bool WriteLogFile(CString title, const BYTE Tag[2], LPBYTE Address);

	bool WriteSmartLogFile( LPBYTE Input, WORD InputLen, LPBYTE Output, WORD OutputLen );
	bool WriteSmartLogFile( CString message );

	bool WriteTagLogFile( void );

	BYTE GetSerialNumber(UCHAR *SerialNum);


	afx_msg void OnVirtualPosSetting();
};


