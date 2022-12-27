#include "StdAfx.h"
#include ".\emv.h"

#include "VirtualPosFile.h"


EMV_CARD_TAGS	CEMV::m_EMVCardTags;
EMV_TERM_TAGS	CEMV::m_EMVTermTags;


// if any new TAG will be added/deleted increase/decrease MAX_TAG_COUNT value
const TAG_ADDRESS CEMV::m_TagAddress[MAX_TAG_COUNT] =
{
// Terminal Tags
	0x5F, 0x2A, m_EMVTermTags.t5F2A,	0x00,	NUM, 'T',	"Transaction Currency Code",
	0x5F, 0x36, m_EMVTermTags.t5F36,	0x00,	NUM, 'T',	"Transaction Currency Exponent",
	0x81, 0x00, m_EMVTermTags.t81,		0x00,	BIN, 'T',	"Amount, Authorised (Binary)",
	0x8A, 0x00, m_EMVTermTags.t8A,		0x00,	ANU, 'T',	"Authorisation Response Code",
	0x95, 0x00, m_EMVTermTags.t95,		0x00,	BIN, 'T',	"Terminal Verification Results (TVR)",
	0x98, 0x00, m_EMVTermTags.t98,		0x00,	BIN, 'T',	"Transaction Certificate (TC) Hash Value",
	0x99, 0x00, m_EMVTermTags.t99,		0x00,	BIN, 'T',	"Transaction Personal Identification Number (PIN) Data",
	0x9A, 0x00, m_EMVTermTags.t9A,		0x00,	NUM, 'T',	"Transaction Date",
	0x9B, 0x00, m_EMVTermTags.t9B,		0x00,	BIN, 'T',	"Transaction Status Information",
	0x9C, 0x00, m_EMVTermTags.t9C,		0x00,	NUM, 'T',	"Transaction Type",
	0x9F, 0x01, m_EMVTermTags.t9F01,	0x00,	NUM, 'T',	"Acquirer Identifier",
	0x9F, 0x02, m_EMVTermTags.t9F02,	0x00,	NUM, 'T',	"Amount, Authorised (Numeric)",
	0x9F, 0x03, m_EMVTermTags.t9F03,	0x00,	NUM, 'T',	"Amount, Other (Numeric)",
	0x9F, 0x04, m_EMVTermTags.t9F04,	0x00,	BIN, 'T',	"Amount, Other (Binary)",
	0x9F, 0x06, m_EMVTermTags.t9F06,	0x00,	BIN, 'T',	"Application Identifier (AID)",
	0x9F, 0x09, m_EMVTermTags.t9F09,	0x00,	BIN, 'T',	"Application Version Number",
	0x9F, 0x15, m_EMVTermTags.t9F15,	0x00,	NUM, 'T',	"Merchant Category Code",
	0x9F, 0x16, m_EMVTermTags.t9F16,	0x00,	ANS, 'T',	"Merchant Identifier",
	0x9F, 0x1A, m_EMVTermTags.t9F1A,	0x00,	NUM, 'T',	"Terminal Country Code",
	0x9F, 0x1B, m_EMVTermTags.t9F1B,	0x00,	BIN, 'T',	"Terminal Floor Limit",
	0x9F, 0x1C, m_EMVTermTags.t9F1C,	0x00,	NUM, 'T',	"Terminal Identification",
	0x9F, 0x1D, m_EMVTermTags.t9F1D,	0x00,	BIN, 'T',	"Terminal Risk Management Data",
	0x9F, 0x1E, m_EMVTermTags.t9F1E,	0x00,	ANU, 'T',	"Interface Device (IFD) Serial Number",
	0x9F, 0x21, m_EMVTermTags.t9F21,	0x00,	NUM, 'T',	"Transaction Time",
	0x9F, 0x22, m_EMVTermTags.t9F22,	0x00,	BIN, 'T',	"Certification Authority Public Key Index",
	0x9F, 0x33, m_EMVTermTags.t9F33,	0x00,	BIN, 'T',	"Terminal Capabilities",
	0x9F, 0x34, m_EMVTermTags.t9F34,	0x00,	BIN, 'T',	"Cardholder Verification Method (CVM) Results",
	0x9F, 0x35, m_EMVTermTags.t9F35,	0x00,	NUM, 'T',	"Terminal Type",
	0x9F, 0x37, m_EMVTermTags.t9F37,	0x00,	BIN, 'T',	"Unpredictable Number",
	0x9F, 0x39, m_EMVTermTags.t9F39,	0x00,	NUM, 'T',	"Point-of-Service (POS) Entry Mode",
	0x9F, 0x3A, m_EMVTermTags.t9F3A,	0x00,	BIN, 'T',	"Amount, Reference Currency",
	0x9F, 0x3C, m_EMVTermTags.t9F3C,	0x00,	NUM, 'T',	"Transaction Reference Currency",
	0x9F, 0x3D, m_EMVTermTags.t9F3D,	0x00,	NUM, 'T',	"Transaction Reference Currency Exponent",
	0x9F, 0x40, m_EMVTermTags.t9F40,	0x00,	BIN, 'T',	"Additional Terminal Capabilities",
	0x9F, 0x41, m_EMVTermTags.t9F41,	0x00,	NUM, 'T',	"Transaction Sequence Counter",			
 // Card Tags
	0x4F, 0x00, m_EMVCardTags.t4F,		'R',		BIN, 'C',	"Application Identifier (AID)",
	0x50, 0x00, m_EMVCardTags.t50,		'R',		ANU, 'C',	"Application Label",		
	0x57, 0x00, m_EMVCardTags.t57,		'O',		BIN, 'C',	"Track 2 Equivalent Data",		
	0x5A, 0x00, m_EMVCardTags.t5A,		'M',		CNU, 'C',	"Application Primary Account Number (PAN)",
	0x5D, 0x00, m_EMVCardTags.t5D,		'C',		BIN, 'C',	"DESCRIPTION NOT FOUND",
	0x5F, 0x20, m_EMVCardTags.t5F20,	'R',		ANS, 'C',	"Cardholder Name",
	0x5F, 0x24, m_EMVCardTags.t5F24,	'M',		NUM, 'C',	"Application Expiration Date",
	0x5F, 0x25, m_EMVCardTags.t5F25,	'O',		NUM, 'C',	"Application Effective Date",
	0x5F, 0x28, m_EMVCardTags.t5F28,	'C',		NUM, 'C',	"Issuer Country Code",
	0x5F, 0x2D, m_EMVCardTags.t5F2D,	'O',		ANU, 'C',	"Language Preference",
	0x5F, 0x30, m_EMVCardTags.t5F30,	'O',		NUM, 'C',	"Service Code",
	0x5F, 0x34, m_EMVCardTags.t5F34,	'O',		NUM, 'C',	"Application Primary Account Number (PAN) Sequence Number",
	0x6F, 0x00, m_EMVCardTags.t6F,		'R',		BIN, 'C',	"File Control Information (FCI) Template",
	0x71, 0x00, m_EMVCardTags.t71,		'C',		BIN, 'C',	"Issuer Script Template 1",
	0x72, 0x00, m_EMVCardTags.t72,		'C',		BIN, 'C',	"Issuer Script Template 2",
	0x73, 0x00, m_EMVCardTags.t73,		'O',		NUM, 'C',	"Directory Discretionary Template",
	0x82, 0x00, m_EMVCardTags.t82,		'M',		BIN, 'C',	"Application Interchange Profile",
	0x84, 0x00, m_EMVCardTags.t84,		'R',		BIN, 'C',	"Dedicated File (DF) Name",
	0x87, 0x00, m_EMVCardTags.t87,		'C',		BIN, 'C',	"Application Priority Indicator",
	0x88, 0x00, m_EMVCardTags.t88,		0x00,		BIN, 'C',	"Short File Identifier (SFI)",
	0x8C, 0x00, m_EMVCardTags.t8C,		'M',		BIN, 'C',	"Card Risk Management Data Object List 1 (CDOL1)",
	0x8D, 0x00, m_EMVCardTags.t8D,		'M',		BIN, 'C',	"Card Risk Management Data Object List 2 (CDOL2)",
	0x8E, 0x00, m_EMVCardTags.t8E,		'C',		BIN, 'C',	"Cardholder Verification Method (CVM) List",
	0x8F, 0x00, m_EMVCardTags.t8F,		'C',		BIN, 'C',	"Certification Authority Public Key Index",
	0x90, 0x00, m_EMVCardTags.t90,		'C',		BIN, 'C',	"Issuer Public Key Certificate",
	0x91, 0x00, m_EMVCardTags.t91,		'O',		BIN, 'C',	"Issuer Authentication Data",
	0x92, 0x00, m_EMVCardTags.t92,		'C',		BIN, 'C',	"Issuer Public Key Remainder",
	0x93, 0x00, m_EMVCardTags.t93,		'C',		BIN, 'C',	"Signed Static Application Data",
	0x94, 0x00, m_EMVCardTags.t94,		'R',		BIN, 'C',	"Application File Locator (AFL)",
	0x97, 0x00, m_EMVCardTags.t97,		'C',		BIN, 'C',	"Transaction Certificate Data Object List (TDOL)",
	0x9F, 0x05, m_EMVCardTags.t9F05,	'O',		BIN, 'C',	"Application Discretionary Data",
	0x9F, 0x07, m_EMVCardTags.t9F07,	'O',		BIN, 'C',	"Application Usage Control",
	0x9F, 0x08, m_EMVCardTags.t9F08,	'O',		BIN, 'C',	"Application Version Number",  
	0x9F, 0x0D, m_EMVCardTags.t9F0D,	'R',		BIN, 'C',	"Issuer Action Code - Default",
	0x9F, 0x0E, m_EMVCardTags.t9F0E,	'R',		BIN, 'C',	"Issuer Action Code - Denial",
	0x9F, 0x0F, m_EMVCardTags.t9F0F,	'R',		BIN, 'C',	"Issuer Action Code - Online",
	0x9F, 0x10, m_EMVCardTags.t9F10,	'R',		BIN, 'C',	"Issuer Application Data",
	0x9F, 0x11, m_EMVCardTags.t9F11,	'C',		NUM, 'C',	"Issuer Code Table Index",
	0x9F, 0x12, m_EMVCardTags.t9F12,	'O',		ANU, 'C',	"Application Preferred Name",
	0x9F, 0x13, m_EMVCardTags.t9F13,	'C',		BIN, 'C',	"Last Online Application Transaction Counter (ATC) Register",
	0x9F, 0x14, m_EMVCardTags.t9F14,	'C',		BIN, 'C',	"Lower Consecutive Offline Limit",
	0x9F, 0x17, m_EMVCardTags.t9F17,	'C',		BIN, 'C',	"Personal Identification Number (PIN) Try Counter",
	0x9F, 0x19, m_EMVCardTags.t9F19,	'C',		BIN, 'C',	"DESCRIPTION NOT FOUND",
	0x9F, 0x1F, m_EMVCardTags.t9F1F,	'R',		ANS, 'C',	"Track 1 Discretionary Data",
	0x9F, 0x20, m_EMVCardTags.t9F20,	'C',		CNU, 'C',	"Track 2 Discretionary Data",
	0x9F, 0x23, m_EMVCardTags.t9F23,	'C',		BIN, 'C',	"Upper Consecutive Offline Limit",
	0x9F, 0x26, m_EMVCardTags.t9F26,	'C',		BIN, 'C',	"Application Cryptogram",
	0x9F, 0x27, m_EMVCardTags.t9F27,	'R',		BIN, 'C',	"Cryptogram Information Data",
	0x9F, 0x2D, m_EMVCardTags.t9F2D,	'C',		BIN, 'C',	"ICC PIN Encipherment Public Key Certificate",
	0x9F, 0x2E, m_EMVCardTags.t9F2E,	'C',		BIN, 'C',	"ICC PIN Encipherment Public Key Exponent",
	0x9F, 0x2F, m_EMVCardTags.t9F2F,	'C',		BIN, 'C',	"ICC PIN Encipherment Public Key Remainder",
	0x9F, 0x32, m_EMVCardTags.t9F32,	'C',		BIN, 'C',	"Issuer Public Key Exponent",
	0x9F, 0x36, m_EMVCardTags.t9F36,	'R',		BIN, 'C',	"Application Transaction Counter (ATC)",
	0x9F, 0x38, m_EMVCardTags.t9F38,	'C',		BIN, 'C',	"Processing Options Data Object List (PDOL)",
	0x9F, 0x3B, m_EMVCardTags.t9F3B,	'O',		NUM, 'C',	"Application Reference Currency",
	0x9F, 0x42, m_EMVCardTags.t9F42,	'C',		NUM, 'C',	"Application Currency Code",
	0x9F, 0x43, m_EMVCardTags.t9F43,	'O',		NUM, 'C',	"Application Reference Currency Exponent",
	0x9F, 0x44, m_EMVCardTags.t9F44,	'C',		NUM, 'C',	"Application Currency Exponent",
	0x9F, 0x45, m_EMVCardTags.t9F45,	'O',		BIN, 'C',	"Data Authentication Code",
	0x9F, 0x46, m_EMVCardTags.t9F46,	'C',		BIN, 'C',	"ICC Public Key Certificate",
	0x9F, 0x47, m_EMVCardTags.t9F47,	'C',		BIN, 'C',	"ICC Public Key Exponent",
	0x9F, 0x48, m_EMVCardTags.t9F48,	'C',		BIN, 'C',	"ICC Public Key Remainder",
	0x9F, 0x49, m_EMVCardTags.t9F49,	'C',		BIN, 'C',	"Dynamic Data Object List (DDOL)",
	0x9F, 0x4A, m_EMVCardTags.t9F4A,	'C',		BIN, 'C',	"Static Data Authentication Tag List",
	0x9F, 0x4B, m_EMVCardTags.t9F4B,	'C',		BIN, 'C',	"Signed Dynamic Application Data",
	0x9F, 0x4C, m_EMVCardTags.t9F4C,	'O',		BIN, 'C',	"ICC Dynamic Number",
	0x9F, 0x51, m_EMVCardTags.t9F51,	'C',		NUM, 'C',	"DESCRIPTION NOT FOUND",
	0x9F, 0x52, m_EMVCardTags.t9F52,	'C',		BIN, 'C',	"Application Default Action",
	0x9F, 0x53, m_EMVCardTags.t9F53,	'C',		BIN, 'C',	"Consecutive Transaction Limit International",
	0x9F, 0x54, m_EMVCardTags.t9F54,	'C',		BIN, 'C',	"Cumulative Transaction Amount Limit",
	0x9F, 0x55, m_EMVCardTags.t9F55,	'C',		BIN, 'C',	"Geographic Indicator",
	0x9F, 0x56, m_EMVCardTags.t9F56,	'C',		BIN, 'C',	"Issuer Authentication Indicator",
	0x9F, 0x57, m_EMVCardTags.t9F57,	'C',		NUM, 'C',	"DESCRIPTION NOT FOUND",
	0x9F, 0x58, m_EMVCardTags.t9F58,	'C',		BIN, 'C',	"Lower Consecutive Offline Limit",
	0x9F, 0x59, m_EMVCardTags.t9F59,	'C',		BIN, 'C',	"Upper Consecutive Offline Limit",
	0x9F, 0x72, m_EMVCardTags.t9F72,	'C',		BIN, 'C',	"DESCRIPTION NOT FOUND",
	0x9F, 0x73, m_EMVCardTags.t9F73,	'C',		BIN, 'C',	"DESCRIPTION NOT FOUND",
	0x9F, 0x75, m_EMVCardTags.t9F75,	'C',		BIN, 'C',	"DESCRIPTION NOT FOUND",
	0x9F, 0x76, m_EMVCardTags.t9F76,	'C',		NUM, 'C',	"DESCRIPTION NOT FOUND",
	0x9F, 0x7F, m_EMVCardTags.t9F7F,	0x00,		BIN, 'C',	"DESCRIPTION NOT FOUND",
	0xBF, 0x0C, m_EMVCardTags.tBF0C,	'O',		BIN, 'C',	"File Control Information (FCI) Issuer Discretionary Data"
};


const RESPONSE_CODE	CEMV::m_RespCode =
{
	"Y1",	// BYTE	Y1[2+1]; Offline Approved
	"Y2",	// BYTE	Y2[2+1]; Offline Approved (after card-initiated referral) NOT SUPPORTED
	"Y3",	// BYTE	Y3[2+1]; offline Approved Unable to go online
	"Z1",	// BYTE	Z1[2+1]; Offline Declined
	"Z2",	// BYTE	Z2[2+1]; Offline Declined (after card-initiated referral) NOT SUPPORTED
	"Z3"	// BYTE	Z3[2+1]; Offline Declined Unable To Go Online
};




CEMV::CEMV(void)
{
	mod_size = 32;
	m_SignPrint = 0;
}

CEMV::~CEMV(void)
{
}


BYTE CEMV::EMVTransaction( void )
{
	       
	BOOL	bIsOffline = FALSE;	
	BOOL	bIsOnlineError = FALSE;
	BYTE	Certif_type = AAC; // default certificate type : denial
	BYTE	ucDataValue[64];
	WORD	usDataLen;
	BYTE	ucRet;
	BYTE	ucSelectedAID[17], ucEMVTranType=0;
	BYTE	ucOnlineTags[30];
    BYTE 	ucTermDesicion;

	m_IsApproved = FALSE;
	m_PreAuthorized = FALSE;

	// Init EMV TAG structures
	memset(&m_EMVTermTags, 0, sizeof(m_EMVTermTags));
	memset(&m_EMVCardTags, 0, sizeof(m_EMVCardTags));

	WriteLogFile("EMVTransaction","Start");


	PrepCAKEYS();
	FillTermParams();


	ucRet = ApplicationSelection( &m_ApplicationList[1], m_ApplicationList[0]/APP_INF_LEN, ucSelectedAID );

	if( ucRet != PROCESS_OK )
	{
		CString tmp;
		tmp.Format( "SELECT APP. RET: %d",ucRet );
		WriteLogFile( tmp );

		if (ucRet != CARD_REJECTED) 
		{
			if( (m_SW1==0x62 && m_SW2==0x83) || (m_SW1==0x6A && m_SW2==0x81)) 
			{
			
			}
			else 
			{
//				FallBackFlag=TRUE;
				DisplayMessage( 1, "PLEASE USE MAG. STRIP", TRUE );
				MessageBeep( MB_ICONEXCLAMATION );
			}	
		}	
   		return ucRet;
   	}

	
	GetTxType();

	ucRet = InitiateApplicationProcessing();
	if( ucRet != PROCESS_OK )
	    return ucRet;

	ucRet = ReadAppData();
	if( ucRet != PROCESS_OK )
	    return ucRet;
  
	ucRet = ExtractFromChip();
	if( ucRet != PROCESS_OK )
	{
		DisplayMessage(1, "EXTRACT ERROR", TRUE );
		return ucRet;
	}

	//if (!CheckTXTypes()) 	
	//    return NO_BIN_PERMISSION;

	ucRet = OfflineDataAuth();
	if( ucRet != PROCESS_OK )
	{
		WriteLogFile("EMV_Tran","OfflineDataAuth NOT OK");
	    return ucRet;
	}

	WriteLogFile("EMV_Tran","OfflineDataAuth OK");

	    
	ucRet = ProcessRestrict();
	if( ucRet != PROCESS_OK )
	    return ucRet;

	ucRet = CardholderVerify();
	if( ucRet != PROCESS_OK )
	    return ucRet;

	WriteLogFile("EMV_Tran","CardholderVerify OK");


    ucRet = TerminalRiskManagment();
	if( ucRet != PROCESS_OK )
	    return ucRet;

	ucRet = TermActionAnalysis( &ucTermDesicion );
	if( ucRet != PROCESS_OK )
	    return ucRet;
	
	switch( m_CertifType )
	{
		case AAC:
			WriteLogFile( "m_CertifType = AAC" );
			break;
		case TC:
			WriteLogFile( "m_CertifType = TC" );
			break;
		case ARQC:
			WriteLogFile( "m_CertifType = ARQC" );
			break;
		case AAR:
			WriteLogFile( "m_CertifType = AAR" );
			break;
	}

	if( m_CertifType == TC )
	{
		strcpy( (char*)m_Approval, "00" );
	}

    ucRet = CardActionAnalysis( ucTermDesicion );

   	if( ucRet != PROCESS_OK )
   	{
    	// According to the EVAL test script 2CK017
    	if (ucRet == CRYPTOGRAM_TYPE_INCORRECT)
    	{
			DisplayMessage( 1, "NOT ACCEPTED", TRUE );
			MessageBeep( MB_ICONEXCLAMATION );
   		}
		else 
		{
//			FallBackFlag=TRUE;
			DisplayMessage( 1, "PLEASE USE MAG. STRIP", TRUE );
			MessageBeep( MB_ICONEXCLAMATION );
		}	

		return ucRet;
   	}

	////////////////////////////
	// add ExtractFromChip2 here
	////////////////////////////
	
   	if( (m_CertifType == ARQC) || (m_CertifType == AAR) )
   	{
		if( m_CertifType == ARQC )
		{
			memset( m_EMVData, 0, 528+1 );
			m_EMVDataLen=0;

			GetOnlineTags( ucOnlineTags );

			if( !PrepareOnlineData( m_EMVData, &m_EMVDataLen, ucOnlineTags ) )
			{
				return FALSE;
			}

			ucRet = GetBankDecision();

			if( ucRet != PROCESS_OK )
			{
				bIsOffline = TRUE;
			}
		
			
		}	

		if( (atoi( (char*)m_CurTXType )==1 || atoi( (char*)m_CurTXType )==40) && bIsOffline ) 
		{
			DisplayMessage( 1, "CAN NOT BE COMPLETED OFFLINE", TRUE );
			return OFFLINE_NOT_ACCEPTED;
		}


   		if( bIsOffline == FALSE )
    	{
			ucRet = AddToEmvTAGS( m_EMVDataRcv, m_EMVDataRcvLen, ISSUER);
// Bu kontrollerin comment'lenmesinin nedeni 2CO034 testinde Issuer Script uzunluunun yanl olmas durumunda
// transaction'n terminate edilmemesi gerekmesidir.
//			if( ucRet != PROCESS_OK )
// 				return ucRet;

       		ucRet = GetDataElement( TAG_AuthoRespCode, ucDataValue, &usDataLen );
			if (ucRet!=ACCESS_OK)
       			return FALSE;

			if( (ucDataValue[0]<0x30) || (ucDataValue[0]>0x39) )
       		{
				bIsOnlineError = TRUE;
               //!!!sel???     ISOTranData.ReversalRequired = 1;
			}		
			else
			{
				bIsOnlineError = FALSE;
			}


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
			//ucRet = IssuerScriptProcessing1();

			//if( ucRet != PROCESS_OK )
			//{
			//	return ucRet;
			//}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
		}


		ucRet = Completion( bIsOnlineError, &m_CertifType );

		if (ucRet != PROCESS_OK)
		{
			return ucRet;
		}

		memset( m_Approval, 0, 3);
		memcpy( m_Approval, &m_EMVTermTags.t8A[1], 2 );
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
		//ucRet = IssuerScriptProcessing2();
		//if (ucRet != PROCESS_OK)
		//{
		//	return ucRet;
		//}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


/*		if((ucRet != PROCESS_OK)&&(ucRet != CARD_COM_ERROR))
       	{
           		// According to the EVAL test script 2CK017
				sprintf(dummy,"C TRAN RET:%d",ucRet);
				VPrinterPut(dummy);

          		if (ucRet == CRYPTOGRAM_TYPE_INCORRECT)
          		{
          			sDisplayPutXY (1, 1, N2_EMV_MSG_NOT_ACCEPTED);
					ucWaitKey();
				}

				UpdateReverseFl(1);
  
          		//GetErrorMessage();
       	}
		
       	ucRet = GetDataElement(TAG_AuthoRespCode, ucDataValue, &usDataLen);
       
		if(  ucRet!=ACCESS_OK ||
				(ucDataValue[0]<0x30) || (ucDataValue[0]>0x39) ||
				(ucDataValue[1]<0x30) || (ucDataValue[1]>0x39) ) 
		{
		
			UpdateReverseFl(1);
		}
*/
	}

	if( m_CertifType == TC )
	{
		m_IsApproved = TRUE;
	}
	else
	{
		m_IsApproved = FALSE;
	}
	

	AddRec();


	return PROCESS_OK;
}



// Send 2.GENERATE AC command to the card
BYTE CEMV::Completion( BYTE ucOnlineError, LPBYTE ucCardDesicion )
{
	BYTE	ucCDOL2Data[MAX_DOL_LEN];
	LPBYTE	ucAuthRespCode = &m_EMVTermTags.t8A[1];
	LPBYTE	ucAIP = &m_EMVCardTags.t82[1];
	LPBYTE	ucTSI = &m_EMVTermTags.t9B[1];
	LPBYTE	ucTVR = &m_EMVTermTags.t95[1];
	BYTE	ucCDOL2DataLen, ucValue;
	BYTE	ucCryptInfData = m_EMVCardTags.t9F27[1];
	BYTE	ucKey, ucLenOfLen;
	BYTE	ucTermDesicion, ucRet;
	int		len, iByteNo, iMsgIndex=1;
//	char	str[64];




	GetByteNoAndValue(TSI_CARD_RISKMNG_PERFORMED, &ucValue, &iByteNo);
	ucTSI[iByteNo] = ucTSI[iByteNo]|ucValue;
	if( ucCryptInfData == TC )
	{
		return PROCESS_OK;
	}
	if( ucCryptInfData == AAC )
	{
		return PROCESS_OK;
	}	
	if( (ucCryptInfData == AAR) || ((memcmp(ucAuthRespCode, "01", 2)==0)) )
	{
		if( ucCryptInfData == AAR )
		{
			m_EMVTermTags.t8A[0] = 2;
			memcpy(&m_EMVTermTags.t8A[1], m_RespCode.Z2 , 2); //EVAL1.6
		}
		else if( memcmp(ucAuthRespCode, "01", 2)==0 )
		{
			
			//strcpy(str, "PAN:");
			//Bcd2Str(&m_EMVCardTags.t5A[1], m_EMVCardTags.t5A[0], 0, &str[4]);
			//VDisplay(2, (UCHAR *)str);
			//VDisplay(1,GetText3(N3_MSGCallBank));
			//VDisplay(3,GetText3(N3_MSGOnayRed));

			ucKey = FALSE;//ucWaitKey();
			if( ucKey == TRUE )
			{
				if( ucCryptInfData == AAR )
				{
					m_EMVTermTags.t8A[0] = 2;
					memcpy(&m_EMVTermTags.t8A[1], "00", 2); //EVAL1.6
				}
// EVAL1.6 Start
				if( memcmp(ucAuthRespCode, "01", 2)==0 )
				{
					m_EMVTermTags.t8A[0] = 2;
// Here is commented at the test 2CM077/ARC_issuer_referral
//					memcpy(&m_EMVTermTags.t8A[1], "00", 2);
				}
// EVAL1.6 End
				ucTermDesicion = TC;
			}
			else 
			{
				if (ucCryptInfData == AAR) 
				{
					m_EMVTermTags.t8A[0] = 2;
					memcpy(&m_EMVTermTags.t8A[1], "51", 2); //EVAL1.6
				}
// EVAL1.6 Start
				if (memcmp(ucAuthRespCode, "01", 2)==0) 
				{
					m_EMVTermTags.t8A[0] = 2;
//		            memcpy(&m_EMVTermTags.t8A[1], "51", 2);
				}
// EVAL1.6 End
				ucTermDesicion = AAC;
			}
		}
	}

	if( (ucCryptInfData&0x01) == SERVICE_NOT_ALLOWED )
	{
		//sDisplayClear();
		//VDisplay(1, GetText3(N3_EMV_MSG_NOT_ACCEPTED));
		//ucWaitKey();
		//!!!sel???return SERVIC_NOT_ALLOWED;
	}
// EVAL1.6 Start
	/*if ((ucCryptInfData&0x02) == PIN_TRY_LIMIT_EXCEEDED)
	{
		sDisplayClear();
		VDisplay(1,GetText3(N3_PIN_TRY_LIMIT_EXCEEDED)); 
		ucWaitKey();
		//!!!sel???return PIN_TRY_LIMIT_EXC;
	}!!!sel??? mandatory degil*/
// EVAL1.6 End

// Check the response code returned from online
	if( memcmp(ucAuthRespCode, "00", 2) == 0) 
	{
		ucTermDesicion = TC;
	}
	else if( (memcmp(ucAuthRespCode, "01", 2) != 0) && (memcmp(ucAuthRespCode, "02", 2) != 0)) 
	{
		ucTermDesicion = AAC;
	}	

//	if (ucOnlineError == TRUE)
//vPrintMsg("ucOnlineError", &ucOnlineError, 1);
//vPrintMsg("ucCryptInfData", &ucCryptInfData, 1);
	if( (ucOnlineError == TRUE)&&(ucCryptInfData != AAR) ) //EVAL1.6
	{
		TermActionAnalysisDefault(&ucTermDesicion);
	}
/*	if (ucOnlineError == FALSE)
		if (m_EMVCardTags.t91[0] == 0)
			return PROCESS_OK;
*/
// Check if AIP shows card supports Issuer Authentication
	GetByteNoAndValue(AIP_ISSAUTH, &ucValue, &iByteNo);
	if ((ucAIP[iByteNo]&ucValue) == ucValue)
	{
            // Terminal Issues EXTERNAL_AUTHENTICATE command
		if (m_EMVCardTags.t91[0] != 0)
		{
			ucRet = EXTERNAL_AUTHENTICATE( m_EMVCardTags.t91 );
			if (ucRet != PROCESS_OK)
				return ucRet;

// Terminal sets Issuer Authentication Performed bit to '1' in TSI
			GetByteNoAndValue(TSI_ISSUER_AUTH_PERFORMED, &ucValue, &iByteNo);
			ucTSI[iByteNo] = ucTSI[iByteNo]|ucValue;
//!!!sel??? burasi return'lardan sonra idi 			
// If Response shows Authentication unsuccessfull set Issuer Authentication was unsuccessfull bit to '1' in TVR
			if( (m_SW1 != 0x90) || (m_SW2 != 0x0) )
			{
				GetByteNoAndValue(TVR_ISSUER_AUTH_UNSUCCESS, &ucValue, &iByteNo);
				ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			}

// This condition is stated in EVAL 2CI032 script
			if( ( (m_SW1 != 0x90) || (m_SW2 != 0x0) ) && 
				( (m_SW1 != 0x63) || ((m_SW2&0xF0) != 0xC0) ) && 
				( (m_SW1 != 0x62) || (m_SW2 != 0x83) ) ) 
			{
				return COND_NOT_SATISFIED;
			}
			if( (m_SW1 == 0x69) && (m_SW2 == 0x85) )
			{
				return COND_NOT_SATISFIED;
			}
		}
	}
// Prepare CDOL2 Data
	len = GetLenOfDataEl(m_EMVCardTags.t8D, &ucLenOfLen);
	PrepDOLData(len, &m_EMVCardTags.t8D[ucLenOfLen], ucCDOL2Data, &ucCDOL2DataLen, DOL_CDOL2);

// Send CDOL2 data in GENERATE_AC command
	ucRet = GENERATE_AC( ucCDOL2Data, ucCDOL2DataLen, ucTermDesicion );
     
	if (ucRet != PROCESS_OK)
		return ucRet;

	if( (m_Apdu.read_data[0] != 0x80) && (m_Apdu.read_data[0] != 0x77) ) 
	{
		return DATA_FORMAT_INCORRECT;
	}

	if( m_Apdu.read_data[0] == 0x80 )
	{
// Parse the response According to the Format 1 : SW1 SW2 80 len (Cryptogram Information Data(1 byte )) (ATC(2 byte)) (AC(8 byte))+Issuer App DAta
		if( (m_Apdu.read_data[iMsgIndex]&0x80) == 0x80 )
		{
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
			ucLenOfLen = m_Apdu.read_data[iMsgIndex]&0x7F;
			len = Bin2Lng( &m_Apdu.read_data[iMsgIndex+1], ucLenOfLen );
			iMsgIndex += ucLenOfLen+1;
		}
		else
		{
// The length of the length field of the data element is coded as one byte
			len = m_Apdu.read_data[iMsgIndex++];
		}

// Allocate memory for Cryptogram Information Type
		m_EMVCardTags.t9F27[0] = 1;
		m_EMVCardTags.t9F27[1] = m_Apdu.read_data[iMsgIndex++];

// Allocate memory for ATC
		m_EMVCardTags.t9F36[0] = 2;
		memcpy( &m_EMVCardTags.t9F36[1], &m_Apdu.read_data[iMsgIndex], 2 );
		iMsgIndex+=2;

// Allocate memory for Application Cryptogram
		m_EMVCardTags.t9F26[0] = 8;
		memcpy( &m_EMVCardTags.t9F26[1], &m_Apdu.read_data[iMsgIndex], 8 );
		iMsgIndex+=8;

// Allocate memory for Issuer Application Data
		m_EMVCardTags.t9F10[0] = len-11;
		memcpy( &m_EMVCardTags.t9F10[1], &m_Apdu.read_data[13], m_EMVCardTags.t9F10[0] );
		iMsgIndex+=m_EMVCardTags.t9F10[0];
	}
	else if( m_Apdu.read_data[0] == 0x77 )
	{
		if( (m_Apdu.read_data[iMsgIndex]&0x80) == 0x80 )
		{
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
			ucLenOfLen = m_Apdu.read_data[iMsgIndex]&0x7F;
			len = Bin2Lng( &m_Apdu.read_data[iMsgIndex+1], ucLenOfLen );
			iMsgIndex += ucLenOfLen+1;
		}
		else
		{
// The length of the length field of the data element is coded as one byte
			ucLenOfLen = 1;
			len = m_Apdu.read_data[iMsgIndex++];
		}
// Parse the response According to the Format 2 : SW1 SW2 77 len BER TLV Data Objects
		ucRet = AddToEmvTAGS( &m_Apdu.read_data[1+ucLenOfLen], len, CARD2 );
		if (ucRet != PROCESS_OK) 
		{
			return ucRet;
		}	
	}


	*ucCardDesicion = m_EMVCardTags.t9F27[1]&0xC0;
        if( ucTermDesicion == AAC )
        {
            if ((*ucCardDesicion == ARQC)||(*ucCardDesicion == TC))
            {
                *ucCardDesicion=AAC;
                return CRYPTOGRAM_TYPE_INCORRECT;
            }
        }

	if (ucTermDesicion == ARQC)
		if( *ucCardDesicion == TC )
		{
			return CRYPTOGRAM_TYPE_INCORRECT;
		}


	if( ucTermDesicion == TC )
		if( (*ucCardDesicion == ARQC) || (*ucCardDesicion == AAR) )
			*ucCardDesicion = AAC;
	return PROCESS_OK;
}



BYTE CEMV::TermActionAnalysisDefault( LPBYTE ucTermDesicion )
{
	LPBYTE	ucTVR = &m_EMVTermTags.t95[1];
	BYTE	ucTACDefault[5], ucLenOfLen;
	BYTE	ucIACDefault[5];
	BYTE	ucCheckBit=0x80;
	int i, len;

// If IAC-Default not present use IAC-Default default value of all bits set to 0
	len = GetLenOfDataEl(m_EMVCardTags.t9F0D, &ucLenOfLen);
	if (len == 0)
		memset(ucIACDefault, 0xFF, 5);
	else
		memcpy(ucIACDefault, &m_EMVCardTags.t9F0D[ucLenOfLen], 5);

// If TAC-Default not present use TAC-Default default value of all bits set to 0
	if (m_EMVTermTags.tDF83[0] == 0)
		memset(ucTACDefault, 0, 5);
	else
		memcpy(ucTACDefault, &m_EMVTermTags.tDF83[1], 5);

	for (i=0;i<5;i++)
	{
		ucCheckBit = 0x80;
		do
		{
// Check if the controlled bit of TVR is set to 1
			if ((ucTVR[i]&ucCheckBit) == ucCheckBit)
			{
// Check if the controlled bit of one of the TAC-Denial and IAC-Denial is set to 1
				if (((ucTACDefault[i]&ucCheckBit) == ucCheckBit)||((ucIACDefault[i]&ucCheckBit) == ucCheckBit))
				{
// Set Authorization Response Code to Offline Declined
					goto OfflineDecline;
				}
				else
				{
					ucCheckBit>>=1;
				}
			}
			else
				ucCheckBit>>=1;
		}
		while (ucCheckBit!=0);
	}

OfflineDecline:
	if( ucCheckBit != 0 )
	{
		m_EMVTermTags.t8A[0] = 2;
		memcpy(&m_EMVTermTags.t8A[1], "Z3", 2);
	    *ucTermDesicion = AAC;
	    return TRUE;
	}
	else
	{
		m_EMVTermTags.t8A[0] = 2;
		memcpy(&m_EMVTermTags.t8A[1], "Y3", 2);
	    *ucTermDesicion = TC;
	    return TRUE;
	}

}





// Prepares the message to be sent to host
BOOL CEMV::PrepareOnlineData( LPBYTE ucOnlineMsg, LPWORD iOnlineMsgLen, LPBYTE ucOnlineTags )
{
	WORD	index, msgindex,i, iTableSize, len;
	BYTE	ucTag[2], ucLen, ucLenOfLen;
	LPBYTE	ucODOL;

	memcpy( m_EMVTermTags.tDFA0, ucOnlineTags, ucOnlineTags[0]+1 );
	ucODOL = &m_EMVTermTags.tDFA0[1];

	if( ucODOL[0] == 0 )
		return FALSE;

	index = 0;
	msgindex = 0;
	do
	{
// Get tag from Online Tags
		if ((ucODOL[index]&0x1F) == 0x1F)
		{
			ucTag[0] = ucODOL[index++];
			ucTag[1] = ucODOL[index++];
			ucLen = ucODOL[index++];
		}
		else
		{
			ucTag[0] = ucODOL[index++];
			ucLen = ucODOL[index++];
		}

		iTableSize = sizeof(m_TagAddress)/sizeof(TAG_ADDRESS);
// Find the tag in table
		for (i=0;i<iTableSize;i++)
		{
			if (m_TagAddress[i].Tag[0] == ucTag[0])
			{
				if ((ucTag[0]& 0x1F)!=0x1F)
					break;
				else
					if (m_TagAddress[i].Tag[1] == ucTag[1])
						break;
			}
		}

// The tag found
		if (i != iTableSize)
		{
			len = GetLenOfDataEl(m_TagAddress[i].Address, &ucLenOfLen);
			if (len != 0)
			{
			
				ucOnlineMsg[msgindex++] = ucTag[0];
				if ((ucTag[0]& 0x1F)==0x1F)
					ucOnlineMsg[msgindex++] = ucTag[1];
				if (ucLen==0)
					ucLen = (BYTE)len;
				ucOnlineMsg[msgindex++] = ucLen;
				memcpy(&ucOnlineMsg[msgindex], &m_TagAddress[i].Address[ucLenOfLen], ucLen);
				msgindex += ucLen;
			}
			else
			{
			
				ucOnlineMsg[msgindex++] = ucTag[0];
				if( (ucTag[0]& 0x1F) == 0x1F )
					ucOnlineMsg[msgindex++] = ucTag[1];
				if( ucLen == 0 )
					ucLen = (BYTE)len;
				ucOnlineMsg[msgindex++] = ucLen;
				memset( &ucOnlineMsg[msgindex], 0, ucLen );
				msgindex += ucLen;
			}
		}
		else
		{
		
			ucOnlineMsg[msgindex++] = ucTag[0];
			if( (ucTag[0]& 0x1F)==0x1F )
				ucOnlineMsg[msgindex++] = ucTag[1];
			ucOnlineMsg[msgindex++] = ucLen;
			memset( &ucOnlineMsg[msgindex], 0, ucLen );
			msgindex += ucLen;
		}

	}
	while( index < m_EMVTermTags.tDFA0[0] );

	*iOnlineMsgLen = msgindex;
    return TRUE;

}





// Prepares CDOL1 Data
// Sends GENERATE_AC command to the card
// Receives the response of the card
// Saves the response of the card in the global structure
BYTE CEMV::CardActionAnalysis( BYTE ucTermDesicion )
{
	BYTE 	ucLenOfLen, ucRet, ucCDOL1DataLen;
	BYTE	ucCDOL1[256], ucCDOL1D[MAX_DOL_LEN];
	INT 	len, iMsgIndex=1;

	len = GetLenOfDataEl( m_EMVCardTags.t8C, &ucLenOfLen );
	memcpy( ucCDOL1, &m_EMVCardTags.t8C[ucLenOfLen], len );
// Prepare CDOL1 Data
	PrepDOLData( len, ucCDOL1, ucCDOL1D, &ucCDOL1DataLen, DOL_CDOL1 );
	memcpy( m_CDOL1Data, ucCDOL1D, ucCDOL1DataLen );

	// The terminal provides the data requested by the card in the CDOL1. 
	// Send CDOL1 data in GENERATE_AC command
	ucRet = GENERATE_AC( m_CDOL1Data, ucCDOL1DataLen, ucTermDesicion );
	if( ucRet != PROCESS_OK )
		return ucRet;

// The format of the returned message from card
	if( (m_SW1 != 0x90) || (m_SW2 != 0x00) )
		return CARD_REJECTED;

	if( (m_Apdu.read_data[0] != 0x80) && (m_Apdu.read_data[0] != 0x77) )
		return DATA_FORMAT_INCORRECT;

	if( m_Apdu.read_data[0] == 0x80 )
	{
// Parse the response According to the Format 1 : SW1 SW2 80 len (Cryptogram Information Data(1 byte )) (ATC(2 byte)) (AC(8 byte))+Issuer App DAta
		if( (m_Apdu.read_data[iMsgIndex]&0x80) == 0x80 )
		{
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
			ucLenOfLen = m_Apdu.read_data[iMsgIndex]&0x7F;
			len = Bin2Lng( &m_Apdu.read_data[iMsgIndex+1], ucLenOfLen );
			iMsgIndex += ucLenOfLen+1;
		}
		else
		{
// The length of the length field of the data element is coded as one byte
			len = m_Apdu.read_data[iMsgIndex++];
		}

// Allocate memory for Cryptogram Information Type
		m_EMVCardTags.t9F27[0] = 1;
		m_EMVCardTags.t9F27[1] = m_Apdu.read_data[iMsgIndex++];

// Allocate memory for ATC
		m_EMVCardTags.t9F36[0] = 2;
		memcpy( &m_EMVCardTags.t9F36[1], &m_Apdu.read_data[iMsgIndex], 2 );
		iMsgIndex += 2;

// Allocate memory for Application Cryptogram
		m_EMVCardTags.t9F26[0] = 8;
		memcpy( &m_EMVCardTags.t9F26[1], &m_Apdu.read_data[iMsgIndex], 8 );
		iMsgIndex += 8;

// Allocate memory for Issuer Application Data
		m_EMVCardTags.t9F10[0] = len-11;
		memcpy( &m_EMVCardTags.t9F10[1], &m_Apdu.read_data[13], m_EMVCardTags.t9F10[0] );
		iMsgIndex += m_EMVCardTags.t9F10[0];
	}
	else if( m_Apdu.read_data[0] == 0x77 )
	{
		if( (m_Apdu.read_data[iMsgIndex]&0x80) == 0x80 )
		{
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
			ucLenOfLen = m_Apdu.read_data[iMsgIndex]&0x7F;
			len = Bin2Lng( &m_Apdu.read_data[iMsgIndex+1], ucLenOfLen );
			iMsgIndex += ucLenOfLen+1;
		}
		else
		{
// The length of the length field of the data element is coded as one byte
			ucLenOfLen = 1;
			len = m_Apdu.read_data[iMsgIndex++];
		}
// Parse the response According to the Format 2 : SW1 SW2 77 len BER TLV Data Objects
		ucRet = AddToEmvTAGS( &m_Apdu.read_data[1+ucLenOfLen], len, CARD2 );
		//!!!sel??? sonra degisti ATC duplicate ucRet = AddToEmvTAGS( &m_Apdu.read_data[1+ucLenOfLen], len, CARD );
		if (ucRet != PROCESS_OK)
			return ucRet;
	}

	if( (m_EMVCardTags.t9F27[1]&0x01) == 0x01 )
	{
		DisplayMessage(1, "NOT ACCEPTED", TRUE);
	}

	m_CertifType = m_EMVCardTags.t9F27[1]&0xC0;
	
	if( ucTermDesicion == AAC )
		if( (m_CertifType == ARQC) || (m_CertifType == TC) || (m_CertifType == AAR) )
			return CRYPTOGRAM_TYPE_INCORRECT;

	if( ucTermDesicion == ARQC )
		if( m_CertifType == TC )
			return CRYPTOGRAM_TYPE_INCORRECT;

	return PROCESS_OK;
}






// Compares the bits in the IACs and TACs to the corresponding bits in the TVR .
// If the corresponding bits in the TVR and the IAC or TAC are both set to '1',
// the disposition for the IAC or TAC is used. (See example on document ICCTerminal.pdf Section 10.4)
BYTE CEMV::TermActionAnalysis( LPBYTE ucTermDesicion )
{
	LPBYTE ucTVR = &m_EMVTermTags.t95[1];
// Terminal Action Codes
	BYTE ucTACDenial[5];
	BYTE ucTACOnline[5];
// Issuer Action Codes
	BYTE ucIACDenial[5];
	BYTE ucIACOnline[5];
// Authorization Response Code
	BYTE ucCheckBit = 0x80;
	INT i, len;
	BYTE ucLenOfLen;


// If IAC-Denial not present use IAC-Denial default value of all bits set to 0
	len = GetLenOfDataEl(m_EMVCardTags.t9F0E, &ucLenOfLen);
	if (len == 0)
		memset(ucIACDenial, 0, 5);
	else
		memcpy(ucIACDenial, &m_EMVCardTags.t9F0E[ucLenOfLen], 5);

/////////////////////////////////////////////////////////////
	WriteLogFile( "IAC Denial" );
	WriteLogFile( 5, ucIACDenial );
/////////////////////////////////////////////////////////////

// If TAC-Denial not present use TAC-Denial default value of all bits set to 0
	if (m_EMVTermTags.tDF84[0] == 0)
		memset(ucTACDenial, 0, 5);
	else
		memcpy(ucTACDenial, &m_EMVTermTags.tDF84[1], 5);

/////////////////////////////////////////////////////////////
	WriteLogFile( "TAC Denial" );
	WriteLogFile( 5, ucTACDenial );
/////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////
	WriteLogFile( "TVR" );
	WriteLogFile( 5, ucTVR );
/////////////////////////////////////////////////////////////



	for (i=0;i<5;i++)
	{
		ucCheckBit = 0x80;
		do
		{
// Check if the controlled bit of TVR is set to 1
			if ((ucTVR[i]&ucCheckBit) == ucCheckBit)
			{
// Check if the controlled bit of one of the TAC-Denial and IAC-Denial is set to 1
				if (((ucTACDenial[i]&ucCheckBit) == ucCheckBit)||((ucIACDenial[i]&ucCheckBit) == ucCheckBit))
				{
// Set Authorization Response Code to Offline Declined
					goto OfflineDecline;
				}
				else
				{
					ucCheckBit>>=1;
				}
			}
			else
				ucCheckBit>>=1;
		}
		while (ucCheckBit!=0);
	}

OfflineDecline:
	if (ucCheckBit != 0)
	{
		m_EMVTermTags.t8A[0] = 2;
		memcpy(&m_EMVTermTags.t8A[1], m_RespCode.Z1 , 2);
	    *ucTermDesicion = AAC;
	    return PROCESS_OK;
	}

// If IAC-Online not present use IAC-Online default value of all bits set to 0
	len = GetLenOfDataEl(m_EMVCardTags.t9F0F, &ucLenOfLen);
	if (len == 0)
		memset(ucIACOnline, 0xFF, 5);
	else
	{
		memcpy(ucIACOnline, &m_EMVCardTags.t9F0F[ucLenOfLen], 5);
    }


/////////////////////////////////////////////////////////////
	WriteLogFile( "IAC Online" );
	WriteLogFile( 5, ucIACOnline );
/////////////////////////////////////////////////////////////


// If TAC-Online not present use TAC-Online default value of all bits set to 0
	if (m_EMVTermTags.tDF85[0] == 0)
		memset(ucTACOnline, 0x0, 5);
	else
		memcpy(ucTACOnline, &m_EMVTermTags.tDF85[1], 5);


/////////////////////////////////////////////////////////////
	WriteLogFile( "TAC Online" );
	WriteLogFile( 5, ucTACOnline );
/////////////////////////////////////////////////////////////


	for (i=0;i<5;i++)
	{
		ucCheckBit = 0x80;
		do
		{
// Check if the controlled bit of TVR is set to 1
			if ((ucTVR[i]&ucCheckBit) == ucCheckBit)
			{
// Check if the controlled bit of one of the TAC-Denial and IAC-Denial is set to 1
				if (((ucTACOnline[i]&ucCheckBit) == ucCheckBit)||((ucIACOnline[i]&ucCheckBit) == ucCheckBit))
				{
					goto Online;
				}
				else
				{
					ucCheckBit>>=1;
				}
			}
			else
				ucCheckBit>>=1;
		}
		while (ucCheckBit!=0);
	}

Online:
	if (ucCheckBit != 0)
	{
/////////////////////////////////////////////////////////////
	WriteLogFile( "ARQC-TVR" );
	WriteLogFile( 5, ucTVR );
/////////////////////////////////////////////////////////////
	    *ucTermDesicion = ARQC;
	}
	else
	{

/////////////////////////////////////////////////////////////
	WriteLogFile( "TC-TVR" );
	WriteLogFile( 5, ucTVR );
/////////////////////////////////////////////////////////////

		m_EMVTermTags.t8A[0] = 2;
		memcpy(&m_EMVTermTags.t8A[1], m_RespCode.Y1 , 2);
	    *ucTermDesicion = TC;
	}

	return PROCESS_OK;
}





BYTE CEMV::TerminalRiskManagment( void )
{
	INT 	iByteNo;
	BYTE 	ucValue, ucRet;
	LPBYTE	ucTVR = &m_EMVTermTags.t95[1];
	LPBYTE	ucAIP = &m_EMVCardTags.t82[1];
	LPBYTE	ucTSI = &m_EMVTermTags.t9B[1];

	WriteLogFile("TerminalRiskMng","Start function");

// Check if terminal risk management is supported in AIP
	GetByteNoAndValue( AIP_TRMNG, &ucValue, &iByteNo );
	if( (ucAIP[iByteNo]&ucValue) != ucValue )
		return PROCESS_OK;

// According to the terminal parameters, randomly selects the transaction for online
	ucRet = RandomTransactionSelection();
	if (ucRet != PROCESS_OK)
		return ucRet;

// Permits issuers to request online processing after a specified number of consecutive offline transactions
	ucRet = VelocityCheck();
	if (ucRet != PROCESS_OK)
		return ucRet;

// Merchant forces transaction online
	if (m_EMVTermTags.tDF91[1] == 1)
	{
		GetByteNoAndValue(TVR_MERCH_FORCED_ONLINE, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	}

// Set Terminal Risk Management Performed bit to 1 in TSI
	GetByteNoAndValue(TSI_TERM_RISKMNG_PERFORMED, &ucValue, &iByteNo);
	ucTSI[iByteNo] = ucTSI[iByteNo]|ucValue;

	return PROCESS_OK;
}


// According to the terminal parameters, randomly selects the transaction for online
BYTE CEMV::RandomTransactionSelection( void )
{
	DWORD	i;
	DWORD	iTranAmount=0, iTranAmount2;
	DWORD	iFloorLimit=0, iThresholdValue;
	DWORD	iTranTargetPerc, iMaxTargetPerc;
	DWORD	iTargetPerc, iRandomNumber, iIntFactor, ulLogAmount=0;
	LPBYTE	ucTVR = &m_EMVTermTags.t95[1];
	INT		iByteNo;
	BYTE	ucValue;
	CTime	dateTime  = CTime::GetCurrentTime();
	DWORD	stAmount;

	WriteLogFile("RandomTranSelect","Start function");

// Get transaction log amount
	SplitSale( &m_EMVCardTags.t5A[0], &stAmount );
    ulLogAmount = stAmount;
// The Floor Limit should be present on terminal

	if (m_EMVTermTags.t9F1B[0] != 0)
	{
        iTranAmount = Bcd2Lng(&m_EMVTermTags.t9F02[1], m_EMVTermTags.t9F02[0]);
        
// Check if transaction amount exceeds floor limit
	    if (m_EMVTermTags.t9F03[0] != 0)
    	    iTranAmount2 = Bcd2Lng(&m_EMVTermTags.t9F03[1], m_EMVTermTags.t9F03[0]);
        else
			iTranAmount2 = 0;
//!!!sel??? vPrintMsg ("iTranAmount2", &iTranAmount2,4); 

   	    iTranAmount = Bcd2Lng(&m_EMVTermTags.t9F02[1], m_EMVTermTags.t9F02[0]);
//!!!sel???vPrintMsg ("iTranAmount", &iTranAmount,4);

        iFloorLimit = Bin2Lng(&m_EMVTermTags.t9F1B[1], m_EMVTermTags.t9F1B[0]);
//!!!sel???vPrintMsg ("iFloorLimit", &iFloorLimit,4); 
//!!!sel???vPrintMsg ("ulLogAmount", &ulLogAmount,4); 

        if (ulLogAmount+iTranAmount+iTranAmount2 >= iFloorLimit)
		{

			GetByteNoAndValue(TVR_FLOOR_LIMIT_EXCEEDED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			return PROCESS_OK;
		}
	}

// These are optionel tags. Random Transaction Selection is optional on terminal
	if (m_EMVTermTags.tDF87[0] == 0)
		return PROCESS_OK;
	if (m_EMVTermTags.tDF88[0] == 0)
		return PROCESS_OK;
	if (m_EMVTermTags.tDF89[0] == 0)
		return PROCESS_OK;

	iThresholdValue = Bin2Lng(&m_EMVTermTags.tDF87[1], m_EMVTermTags.tDF87[0]);
	iTargetPerc =  Bin2Lng(&m_EMVTermTags.tDF88[1], m_EMVTermTags.tDF88[0]);
	iMaxTargetPerc =  Bin2Lng(&m_EMVTermTags.tDF89[1], m_EMVTermTags.tDF89[0]);
	
// Generate a random number between 0..100

	CString currDateTime = dateTime.Format( "%S%M%H%W" );
	i = atoi( currDateTime.GetBuffer() );
	srand((unsigned)i);
	iRandomNumber = (int)rand()%100;

	if (iTranAmount < iThresholdValue)
	{
		if (iTargetPerc >= iRandomNumber)
		{
			GetByteNoAndValue(TVR_TRAN_RANDOM_SELECTED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			return PROCESS_OK;
		}
	}
// In the case of Transaction Amount greater than Floor Limit select transaction for online
	else if (iTranAmount > iFloorLimit)
	{
	}
// In the case of Transaction Amount lower than Floor Limit and greater than ThresholdValue
	else
	{
		iIntFactor = ((100*(iTranAmount-iThresholdValue))/(iFloorLimit-iThresholdValue));
		iTranTargetPerc = iIntFactor*(iMaxTargetPerc-iTargetPerc)+iTargetPerc*100;
		if (iTranTargetPerc >= iRandomNumber*100)
		{
			GetByteNoAndValue(TVR_TRAN_RANDOM_SELECTED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			return PROCESS_OK;
		}
	}

	return PROCESS_OK;
}


// Permits issuers to request online processing after a specified number of consecutive offline transactions
BYTE CEMV::VelocityCheck( void )
{
	int 	iATC=0, iLOATC=0, iByteNo;
	LPBYTE	ucTVR 	= &m_EMVTermTags.t95[1];
	BYTE 	ucValue, LCOL, UCOL, ucRet, ucLenOfLen;


	WriteLogFile("VelocityCheck","Start function");

// If one of the Lower Consecutive Offline Limit and Upper Consecutive Offline Limit tags aren't present
// bypass the Velocity Checking
	if( (m_EMVCardTags.t9F23[0] == 0) || (m_EMVCardTags.t9F14[0] == 0) )
		return PROCESS_OK;

// The card parameters. LCOL : Lower Consecutive Offline Limit, UCOL : Upper Consecutive Offline Limit
	LCOL = m_EMVCardTags.t9F14[1];
	UCOL = m_EMVCardTags.t9F23[1];

// Get ATC from card
	ucRet = GET_DATA( GET_ATC );
	if (ucRet != PROCESS_OK)
		return ucRet;

// The Response Format from GET_DATA : SW1 SW2 9F 36 LenOfATC, ATC
	if( (m_SW1 == 0x90) && (m_SW2 == 0) )
	{
		ucRet = AddToEmvTAGS( &m_Apdu.read_data[0], m_Apdu.read_len-2, CARD );
		if( ucRet == PROCESS_OK )
			iATC = Bcd2Lng( &m_EMVCardTags.t9F36[1], 2 );
	}

	if (GetLenOfDataEl(m_EMVCardTags.t9F36, &ucLenOfLen)  == 0)
	{
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
// Set LCOL and UCOL Exceeded in TVR


		GetByteNoAndValue(TVR_LCOL_EXCEEDED, &ucValue, &iByteNo);

		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_UCOL_EXCEEDED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

	if( (m_SW1 != 0x90) || (m_SW2 != 0) )
	{
		GetByteNoAndValue( TVR_ICC_DATA_MISSING, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
// Set LCOL and UCOL Exceeded in TVR
		GetByteNoAndValue( TVR_LCOL_EXCEEDED, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
		GetByteNoAndValue( TVR_UCOL_EXCEEDED, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
		return PROCESS_OK;
	}

// Get Last Online ATC Register from card
	ucRet = GET_DATA( GET_LAST_ONL_ATC );
	if( ucRet != PROCESS_OK )
		return ucRet;

// The Response Format from GET_DATA : SW1 SW2 9F 36 LenOfATC, ATC
	if( (m_SW1 == 0x90) && (m_SW2 == 0) )
	{
		ucRet = AddToEmvTAGS( &m_Apdu.read_data[0], m_Apdu.read_len-2, CARD );
		if( ucRet == PROCESS_OK )
			iLOATC = Bcd2Lng( &m_EMVCardTags.t9F13[1], 2 );

	}

	if( (m_SW1 != 0x90)||(m_SW2 != 0) )
	{
		GetByteNoAndValue( TVR_ICC_DATA_MISSING, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
// Set LCOL and UCOL Exceeded in TVR
		GetByteNoAndValue( TVR_LCOL_EXCEEDED, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
		GetByteNoAndValue( TVR_UCOL_EXCEEDED, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
		return PROCESS_OK;
	}

	if( GetLenOfDataEl( m_EMVCardTags.t9F13, &ucLenOfLen )  == 0 )
	{
		GetByteNoAndValue( TVR_ICC_DATA_MISSING, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
// Set LCOL and UCOL Exceeded in TVR
		GetByteNoAndValue( TVR_LCOL_EXCEEDED, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
		GetByteNoAndValue( TVR_UCOL_EXCEEDED, &ucValue, &iByteNo );
		ucTVR[iByteNo] = ucTVR[iByteNo] | ucValue;
		return PROCESS_OK;
	}

	if ((iATC-iLOATC)>LCOL)
	{
		GetByteNoAndValue(TVR_LCOL_EXCEEDED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	}

	if ((iATC-iLOATC)>UCOL)
	{
		GetByteNoAndValue(TVR_UCOL_EXCEEDED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	}

// New card checking
	if (iLOATC == 0)
	{
		GetByteNoAndValue(TVR_NEW_CARD, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	}
	return PROCESS_OK;
}


BYTE CEMV::CardholderVerify( void )
{
	BYTE	ucAmountX[4], ucAmountY[4], ucCVMCode, ucCVMCondCode, ucValue;
	LPBYTE	ucTVR 		= &m_EMVTermTags.t95[1];
	LPBYTE	ucTSI 		= &m_EMVTermTags.t9B[1];
	LPBYTE	ucAIP 		= &m_EMVCardTags.t82[1];
	LPBYTE	ucCVMList 	= &m_EMVCardTags.t8E[1];
	BYTE	ucRet, ucLenOfLen;
	int   iLenCVMList = m_EMVCardTags.t8E[0];
	int   iCVMIndex=0, iCVMSuccess;
	int   iByteNo;

	WriteLogFile("CardholderVerify","Start Function");
	WriteLogFile("CVM LIST",(const BYTE*)"\x8E\x00",m_EMVCardTags.t8E);

// Does the AIP show card supports CVM
	GetByteNoAndValue(AIP_VERIF, &ucValue, &iByteNo);
	if ((ucAIP[iByteNo]&ucValue) != ucValue)
		return PROCESS_OK;

	m_EMVTermTags.t9F34[0] = 3;

// Check if CVM List present

	if (GetLenOfDataEl(m_EMVCardTags.t8E, &ucLenOfLen) == 0)
	{
		m_EMVTermTags.t9F34[1] = 0x3F;
		m_EMVTermTags.t9F34[2] = 0;
		m_EMVTermTags.t9F34[3] = 0;
	
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		m_EMVTermTags.t9F34[0] = 0x3F ;
		return PROCESS_OK;
	}

// Check if CVM List contains any Cardholder Verification Rules
	if (iLenCVMList <= 8)
	{
		return CVMLIST_LEN_INCORRECT;
	}


// Get the amount fields in CVM (The first 8 byte)
	memcpy(ucAmountX, ucCVMList, 4);
	memcpy(ucAmountY, ucCVMList+4, 4);
	iCVMIndex += 8;

	while (iCVMIndex < iLenCVMList)
	{
// Take the CVM Condition Code from CVM
		ucCVMCondCode = ucCVMList[iCVMIndex+1];
// Check if the CVM Condition Code satisfied
		ucRet = CheckCVMConditionCode(ucCVMCondCode, ucAmountX, ucAmountY);
		if (ucRet == TRUE)
		{
			ucCVMCode = ucCVMList[iCVMIndex];
// Apply CVM
 			ucRet = ApplyCVM(ucCVMCode, &iCVMSuccess);
			if (ucRet != PROCESS_OK) {
				 return ucRet;
// CVM not successfull
			}
			if( iCVMSuccess == CVM_FAIL ) 
			{
// if CVM Code = Fail CVM set TVR and TSI
//#if !defined ZIRAAT
				if ((ucCVMCode&CVM_APLY_SUCCEEDING) != CVM_APLY_SUCCEEDING) 
				{
					
					m_EMVTermTags.t9F34[1] = ucCVMCode;
					m_EMVTermTags.t9F34[2] = ucCVMCondCode;
// EVAL1.6 Start (2CJ082.02)
					if (((ucCVMCode&0x3F) == 3)||((ucCVMCode&0x3F) == 5)||((ucCVMCode&0x3F) == 0x1F))
						m_EMVTermTags.t9F34[3] = 0;
// EVAL1.6 End
					else
						m_EMVTermTags.t9F34[3] = iCVMSuccess;
						GetByteNoAndValue(TVR_VERIF_NOT_SUCCESS, &ucValue, &iByteNo);
						ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
						GetByteNoAndValue(TSI_VERIF_PERFORMED, &ucValue, &iByteNo);
						ucTSI[iByteNo] = ucTSI[iByteNo]|ucValue;
						return PROCESS_OK;
				}
//#endif				
			}
// CVM successfull
			else if (iCVMSuccess != CVM_NOT_SUPPORTED)     //EVAL1.6
			{
				m_EMVTermTags.t9F34[1] = ucCVMCode;
				m_EMVTermTags.t9F34[2] = ucCVMCondCode;
// EVAL1.6 Start (2CJ082.02)
				if (((ucCVMCode&0x3F) == 3)||((ucCVMCode&0x3F) == 5)||((ucCVMCode&0x3F) == 0x1F))
					m_EMVTermTags.t9F34[3] = 0;
// EVAL1.6 End
				else
    				m_EMVTermTags.t9F34[3] = iCVMSuccess;
					GetByteNoAndValue(TSI_VERIF_PERFORMED, &ucValue, &iByteNo);
					ucTSI[iByteNo] = ucTSI[iByteNo]|ucValue;
					return PROCESS_OK;
			}
		}
		iCVMIndex+=2;
	}
// The CVM List is exhausted
	if (iCVMIndex >= iLenCVMList)
	{
// No CVM performed

		m_EMVTermTags.t9F34[1] = 0x3F;
		m_EMVTermTags.t9F34[2] = 0;
		m_EMVTermTags.t9F34[3] = 0;
		GetByteNoAndValue(TVR_VERIF_NOT_SUCCESS, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TSI_VERIF_PERFORMED, &ucValue, &iByteNo);
		ucTSI[iByteNo] = ucTSI[iByteNo]|ucValue;
		return PROCESS_OK;
	}
	return PROCESS_OK;
}


// Check if the CVM Condition is satisfied
BYTE CEMV::CheckCVMConditionCode(BYTE ucCVMCode, LPBYTE ucAmountX, LPBYTE ucAmountY)
{
	BYTE ucTranType = m_EMVTermTags.t9C[1];
	LPBYTE ucTranCurCode = &m_EMVTermTags.t5F2A[1];
	BYTE ucTranCurCodeLen, ucAppCurCodeLen, ucLenOfLen;
	LPBYTE ucAppCurCode  = &m_EMVCardTags.t9F42[1];
	ULONG iAmountX, iAmountY, iTranAmount;
   
	WriteLogFile("CheckCVMCondCode","Start Function");

	UCHAR ucCashType; 

	iAmountX = Bin2Lng(ucAmountX, 4);
	iAmountY = Bin2Lng(ucAmountY, 4);

	ucTranCurCodeLen = GetLenOfDataEl(m_EMVTermTags.t5F2A, &ucLenOfLen);
	ucAppCurCodeLen = GetLenOfDataEl(m_EMVCardTags.t9F42, &ucLenOfLen);

	if (GetCardBrand() == BRAND_VISA)
		ucCashType=TRANTYPE_CASH_VS;
	else	
		ucCashType=TRANTYPE_CASH_MC;

	switch(ucCVMCode)
	{
		case 0x00:
// Always
			return TRUE;
		case 0x01:
// If cash or cashback
			if ((ucTranCurCode == 0)||(ucAppCurCode == 0))
				return FALSE;
							
			if ((ucTranType == ucCashType)||(ucTranType == TRANTYPE_CASHBACK))
				return TRUE;
			else
				return FALSE;
			break;
		case 0x02:
// If not cash or cashback
			if ((ucTranCurCode == 0)||(ucAppCurCode == 0))
				return FALSE;
			if ((ucTranType == ucCashType)||(ucTranType == TRANTYPE_CASHBACK))
				return FALSE;
			else
				return TRUE;
		case 0x03:
// If terminal supports the CVM. In the case of Offline PIN CVM, this means "If Offline PIN Pad present"
// In the case of Online PIN CVM, this means "If Online PIN Pad present"
			return TRUE;
		case 0x04:
// RFU
			return FALSE;
		case 0x05:
// RFU
			return FALSE;
		case 0x06:
			if ((ucTranCurCodeLen == 0)||(ucAppCurCodeLen == 0))
				return FALSE;
// If transaction is in application currency and is under X value
			if (m_EMVTermTags.t9F02[0] == 0)
				return FALSE;

			iTranAmount = Bcd2Lng(&m_EMVTermTags.t9F02[1], m_EMVTermTags.t9F02[0]);
			if (memcmp(ucTranCurCode, ucAppCurCode, 2) == 0)
			{
				if (iTranAmount<iAmountX)
					return TRUE;
				else
					return FALSE;
			}
			else
				return FALSE;
		case 0x07:
// If transaction is in application currency and is over X value
			if ((ucTranCurCodeLen == 0)||(ucAppCurCodeLen == 0))
				return FALSE;
			if (m_EMVTermTags.t9F02[0] == 0)
				return FALSE;
			iTranAmount = Bcd2Lng(&m_EMVTermTags.t9F02[1], m_EMVTermTags.t9F02[0]);
			if ((ucTranCurCode == NULL)||(ucAppCurCode == NULL))
				return FALSE;
			if (memcmp(ucTranCurCode, ucAppCurCode, 2) == 0)
			{
				if (iTranAmount>iAmountX)
					return TRUE;
				else
					return FALSE;
			}
			else
				return FALSE;
		case 0x08:
// If transaction is in application currency and is under Y value
			if ((ucTranCurCodeLen == 0)||(ucAppCurCodeLen == 0))
				return FALSE;
			if (m_EMVTermTags.t9F02[0] == 0)
				return FALSE;
			iTranAmount = Bcd2Lng(&m_EMVTermTags.t9F02[1], m_EMVTermTags.t9F02[0]);
			if ((ucTranCurCode == NULL)||(ucAppCurCode == NULL))
				return FALSE;
			if (memcmp(ucTranCurCode, ucAppCurCode, 2) == 0)
			{
				if (iTranAmount<iAmountY)
					return TRUE;
				else
					return FALSE;
			}
			else
				return FALSE;
		case 0x09:
// If transaction is in application currency and is over Y value
			if ((ucTranCurCodeLen == 0)||(ucAppCurCodeLen == 0))
				return FALSE;
			if (m_EMVTermTags.t9F02[0] == 0)
				return FALSE;
			iTranAmount = Bcd2Lng(&m_EMVTermTags.t9F02[1], m_EMVTermTags.t9F02[0]);
			if ((ucTranCurCode == NULL)||(ucAppCurCode == NULL))
				return FALSE;
			if (memcmp(ucTranCurCode, ucAppCurCode, 2) == 0)
			{
				if (iTranAmount>iAmountY)
					return TRUE;
				else
					return FALSE;
			}
			else
				return FALSE;
		default:
			return FALSE;
	}
}


BYTE CEMV::ApplyCVM(BYTE ucCVMCode, INT *iCVMSuccess)
{
	INT 	iByteNo;
	LPBYTE 	ucTVR 	= &m_EMVTermTags.t95[1];
	LPBYTE	ucTermCap 	= &m_EMVTermTags.t9F33[1];
	BYTE 	ucValue, ucRet;


	WriteLogFile("ApplyCVM","Start Function");


// The most significant two bits of CVM Code is not important at processing CVM
	ucCVMCode = 0x3F&ucCVMCode;
	switch (ucCVMCode)
	{
// Fail CVM Processing
		case 0x00:
			WriteLogFile("ApplyCVM","CVM_FAIL");
	//	*iCVMSuccess = CVM_SUCCESS; 
// Look at EVAL script 2CJ083
			*iCVMSuccess = CVM_FAIL; 
			return PROCESS_OK;
// Plaintext PIN
		case 0x01:
			ucRet = OfflinePIN(ucCVMCode, PLAINTEXT_PIN, iCVMSuccess);

			return ucRet;
// Enchipered PIN online
		case 0x02:
			OnlinePIN(iCVMSuccess);
			return PROCESS_OK;
// Plaintext PIN and Signature
		case 0x03:
			m_SignPrint=1;
			ucRet = OfflinePIN(ucCVMCode, PLAINTEXT_PIN, iCVMSuccess);
			return ucRet;
// Enchipered PIN performed by ICC
		case 0x04:
			ucRet = OfflinePIN(ucCVMCode, ENCHIPERED_PIN, iCVMSuccess);

			return ucRet;
// Enchipered PIN performed by ICC and Signature
		case 0x05:
			m_SignPrint=1;
			ucRet = OfflinePIN(ucCVMCode, ENCHIPERED_PIN, iCVMSuccess);
			return ucRet;
// Signature
		case 0x1E:
			WriteLogFile("ApplyCVM","CVM_UNKNOWN");
			m_SignPrint=1;
			*iCVMSuccess = CVM_UNKNOWN;
			return PROCESS_OK;
// No CVM required
		case 0x1F:
			WriteLogFile("ApplyCVM","CVM_NOT_SUPPORTED");
			GetByteNoAndValue(TERMCAP_NO_CVM_SUPPORTED, &ucValue, &iByteNo);
			if ((ucTermCap[iByteNo]&ucValue) != ucValue)
					*iCVMSuccess = CVM_NOT_SUPPORTED;
			else
				*iCVMSuccess = CVM_SUCCESS;

			return PROCESS_OK;
		default:
			WriteLogFile("ApplyCVM","default CVM_FAIL");
			GetByteNoAndValue(TVR_UNRECOG_CVM, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			*iCVMSuccess = CVM_FAIL;
			return PROCESS_OK;
	}
}




// Handle Offline Plaintext and Enciphered PIN Verification
BYTE CEMV::OfflinePIN(BYTE ucCVMCode, BYTE iPINQualifier, INT *iCVMSuccess)
{
	INT   	iByteNo=0, iPinTryCnt=0,i=0, len1=0, len2=0;
	BYTE	ucLenOfLen1, ucLenOfLen2, ucICCPINEncPubKeyModLen, ucICCPubKeyModLen;
	LPBYTE	ucTermCap 	= &m_EMVTermTags.t9F33[1];
	LPBYTE	ucTVR 		= &m_EMVTermTags.t95[1];
	BYTE 	ucPIN[12], ucValue, ucRet;
	BYTE 	ucByPassPIN = m_EMVTermTags.tDF81[1];
	BYTE 	ucPinBlock[12], UnpNum[8];
	WORD	usPINLen;
	BYTE	ucPINFNDigit[12],GotoFl=0;
	
//        GetEMVMsg(LANGUAGE, EMV_MSG_ENTER_PIN, cDisplayMsg);

	DisplayMessage(2, "OFFLINE PIN", TRUE);
	WriteLogFile("OfflinePIN","Start Function");


	memset( m_ICCPINEncPubKeyMod, 0, sizeof(m_ICCPINEncPubKeyMod) );
	memset( m_ICCPubKeyMod, 0, sizeof(m_ICCPubKeyMod) );
	memset( m_PINEncData, 0, sizeof(m_PINEncData) );
	memset( m_EncryptedPINData, 0, sizeof(m_EncryptedPINData) );

	GetByteNoAndValue(TERMCAP_PLAINTEXT_PIN_OFF, &ucValue, &iByteNo);
	if ((ucTermCap[iByteNo]&ucValue) != ucValue)
	{
		
////////////////////////////////////////////////////////////////////////////////////////////////////		
////////////////////////////////////////////////////////////////////////////////////////////////////		
//				ferhat
////////////////////////////////////////////////////////////////////////////////////////////////////		
////////////////////////////////////////////////////////////////////////////////////////////////////		
		*iCVMSuccess = CVM_SUCCESS;
		return PROCESS_OK;		
////////////////////////////////////////////////////////////////////////////////////////////////////		
////////////////////////////////////////////////////////////////////////////////////////////////////		
////////////////////////////////////////////////////////////////////////////////////////////////////		
////////////////////////////////////////////////////////////////////////////////////////////////////		
		
		
//#if !defined ZIRAAT	
		GetByteNoAndValue(TVR_PINPAD_NOT_PRESENT, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
//#endif		
		*iCVMSuccess = CVM_FAIL;
		return PROCESS_OK;
	}

	len1 = GetLenOfDataEl(m_EMVCardTags.t9F46, &ucLenOfLen1);
	len2 = GetLenOfDataEl(m_EMVCardTags.t9F2D, &ucLenOfLen2);
	if (iPINQualifier == ENCHIPERED_PIN)
	{
		if ((len1 == 0)&&(len2 == 0))
		{
			*iCVMSuccess = CVM_FAIL;
			return PROCESS_OK;
		}
	}
	GetByteNoAndValue(TERMCAP_PLAINTEXT_PIN_OFF, &ucValue, &iByteNo);
// Check if terminal supports palintext pin for offline verification
	if ((ucTermCap[iByteNo]&ucValue) != ucValue)
	{
// Terminal doesn't support plaintext pin for offline verification
		GetByteNoAndValue(TVR_PINPAD_NOT_PRESENT, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		*iCVMSuccess = CVM_FAIL;
		return PROCESS_OK;
	}

// Check if merchant or cardholder directs the terminal to bypass the pin entry
	if (ucByPassPIN == TRUE)
	{
		GetByteNoAndValue(TVR_PIN_NOT_ENTERED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		*iCVMSuccess = CVM_FAIL;
		return PROCESS_OK;
	}
	if (iPINQualifier == ENCHIPERED_PIN) 
	{
		if (len2 != 0) 
		{
// Get ICC PIN Encipherment Public Key for Enciphering the PIN Data
			ucRet = GetICCEncPublicKey( &ucICCPINEncPubKeyModLen );
			if (ucRet == FALSE) {
// CVM is not successfull
				GetByteNoAndValue(TVR_VERIF_NOT_SUCCESS, &ucValue, &iByteNo);
				ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				*iCVMSuccess = CVM_FAIL;
				return PROCESS_OK;
			}
		}
		else if (len1 != 0)  
		{
// Get ICC Public Key for Enciphering the PIN Data
			ucRet = GetICCPublicKey(&ucICCPubKeyModLen);
			if (ucRet == FALSE) {
// CVM is not successfull
				GetByteNoAndValue(TVR_VERIF_NOT_SUCCESS, &ucValue, &iByteNo);
				ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				*iCVMSuccess = CVM_FAIL;
				return PROCESS_OK;
			}
		}
	}
// Get Pin Try Counter value from the card
	ucRet = GET_DATA( GET_PIN_TRY_COUNTER );
	if (ucRet != PROCESS_OK)
		return ucRet;

// The Response Format from GET_DATA : SW1 SW2 9F 17 LenOfPinTryCounter, ValueOfPinTryCounter
	if( (m_SW1 == 0x90) && (m_SW2 == 0) )
	{
		if( CheckPinBlockBIN()!=PROCESS_OK )
		{
			ucRet = AddToEmvTAGS( &m_Apdu.read_data[0], m_Apdu.read_len-2, CARD );

			if( ucRet != PROCESS_OK )
				goto VerifyStart;

			if( m_EMVCardTags.t9F17[0] == 0 )
				goto VerifyStart;

			iPinTryCnt = m_EMVCardTags.t9F17[1];
		}	
		else 
		{
			iPinTryCnt = m_Apdu.read_data[3];

			GotoFl = 0;

//			if( ucRet = BlockPin( &iPinTryCnt, &GotoFl, m_SW1, m_SW2 ) ) return ucRet;

			if( GotoFl ) goto VerifyStart;
		}	

// Check if there are any remainig PIN tries

		if (iPinTryCnt == 0)
		{
// No PIN try remaining
			GetByteNoAndValue(TVR_PIN_TRY_EXCEEDED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			*iCVMSuccess = CVM_FAIL;

			DisplayMessage( 1, "PIN BLOCKED", TRUE );
			return PROCESS_OK;
		}
		else if (iPinTryCnt == 1)
		{
			DisplayMessage( 1, "LAST PIN TRY", TRUE );
//			ucWaitKey();
		}
	}

VerifyStart:

	memset(ucPIN, 0, sizeof(ucPIN));
      


VerifyContinue:
	ucRet = GetPin( 1, ucPIN, 1 );
	usPINLen = (WORD) strlen((char *)ucPIN);
	if( ucRet==FALSE ) 
	{
		if( m_NoPinPad ) 
		{
			GetByteNoAndValue(TVR_PINPAD_NOT_PRESENT, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			*iCVMSuccess = CVM_FAIL;
			return PROCESS_OK;
		}

		GetByteNoAndValue(TVR_PIN_NOT_ENTERED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		*iCVMSuccess = CVM_FAIL;
		return PROCESS_OK;
	}
// Prepare PIN Block
	ucPinBlock[0] = 0x20+usPINLen;
	if (usPINLen%2 == 1)
	{
		memcpy(ucPINFNDigit, ucPIN, usPINLen-1);
		ucPINFNDigit[usPINLen-1] = 0;
		Str2Bcd((char *)ucPINFNDigit, (WORD)strlen((char *)ucPINFNDigit), NO_PAD_ZERO, &ucPinBlock[1], (usPINLen-1)/2, LEFT_PAD);
		Str2Bcd((char *)&ucPIN[usPINLen-1], (WORD)strlen((char *)&ucPIN[usPINLen-1]), NO_PAD_ZERO, &ucPinBlock[(usPINLen+1)/2], 1, LEFT_PAD);
		ucPinBlock[(usPINLen+1)/2] <<= 4;
		ucPinBlock[(usPINLen+1)/2] |= 0x0F;
	}
	else
	{
		Str2Bcd((char *)ucPIN, (WORD)strlen((char *)ucPIN), NO_PAD_ZERO, &ucPinBlock[1], (usPINLen)/2, LEFT_PAD);
	}

	for (i=1+(usPINLen+1)/2; i<12;i++)
		ucPinBlock[i] = 0xFF;

	if( iPINQualifier == ENCHIPERED_PIN )
	{
// Prepare the PIN data to be enciphered like Table 4-16 in EMV 3.1.1 Card Specification
// Get Unpredictable Number from the card
		ucRet = GET_CHALLENGE();
		
		if (ucRet != PROCESS_OK)
			return ucRet;

// The format of the returned data : SW1|SW2|Unpred Num(8 byte)
		/*!!!sel???if (Apdu.read_len != 10)
			return LEN_INCORRECT;*/


		if( (m_SW1==0x90) && (m_SW2 == 0x00) )
		{
			if( m_Apdu.read_len != 10 )
				return LEN_INCORRECT;

			memcpy( UnpNum, m_Apdu.read_data, 8 );
		}
		else
		{

	
// Terminate Transaction
			return CARD_REJECTED;
		
		}

		m_PINEncData[0] = 0x7F;
		memcpy( m_PINEncData+1, ucPinBlock, 8 );
		memcpy( m_PINEncData+9, UnpNum, 8 );
// Check if ICC Pin Encipherment Public Key Certificate received from the card
		if (len2 != 0)
		{
			memcpy( &m_PINEncData[17], m_ICCPINEncPubKeyMod, ucICCPINEncPubKeyModLen-17 );
			memcpy( &m_PINEncData[17], m_EMVTermTags.t9F37, 5 );
			memcpy( &m_PINEncData[22], m_EMVTermTags.t9F41, 5 );
			RSAEncrypt( ICC_PIN_ENC_PUBLIC_KEY_MOD, ucICCPINEncPubKeyModLen, 
						&m_EMVCardTags.t9F2E[1], m_EMVCardTags.t9F2E[0], m_PINEncData, ucICCPINEncPubKeyModLen );
			ucRet = VERIFY_PIN( ENCHIPERED_PIN, m_RecoveredData, ucICCPINEncPubKeyModLen );
							
		}
		else if (len1 != 0)
		{
			memcpy( &m_PINEncData[17], m_ICCPINEncPubKeyMod, ucICCPubKeyModLen-17 );
			memcpy( &m_PINEncData[17], m_EMVTermTags.t9F37, 5 );
			memcpy( &m_PINEncData[22], m_EMVTermTags.t9F41, 5 );
			RSAEncrypt( ICC_PUBLIC_KEY_MOD, ucICCPubKeyModLen, 
						&m_EMVCardTags.t9F47[1], m_EMVCardTags.t9F47[0], m_PINEncData, ucICCPubKeyModLen );
			ucRet = VERIFY_PIN( ENCHIPERED_PIN, m_RecoveredData, ucICCPubKeyModLen );
		}
		if (ucRet != PROCESS_OK)
			return ucRet;
	}
	else
	{
		ucRet = VERIFY_PIN( PLAINTEXT_PIN, ucPinBlock, 8 );
		if( ucRet != PROCESS_OK )
			return ucRet;
	}


	if( (m_SW1 == 0x90) && (m_SW2 == 0x00) )
	{
		DisplayMessage( 1, "PIN OK" );
		*iCVMSuccess = CVM_SUCCESS;
		return PROCESS_OK;
	}
	else if( (m_SW1 == 0x69) && (m_SW2 == 0x83) )
	{
// PIN try limit exceeded
		GetByteNoAndValue(TVR_PIN_TRY_EXCEEDED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		*iCVMSuccess = CVM_FAIL;
		return PROCESS_OK;
	}
	else if( (m_SW1 == 0x69) && (m_SW2 == 0x84) )
	{
// PIN try limit exceeded
		GetByteNoAndValue(TVR_PIN_TRY_EXCEEDED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		*iCVMSuccess = CVM_FAIL;
		return PROCESS_OK;
	}
	else if( (m_SW1 == 0x63) && ((m_SW2&0xF0) == 0xC0) )
	{
		DisplayMessage( 1, "PIN INCORRECT", TRUE );
		

		if( (m_SW2&0x0F) == 0x00 )
		{
// PIN try limit exceeded
			GetByteNoAndValue(TVR_PIN_TRY_EXCEEDED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			*iCVMSuccess = CVM_FAIL;
			return PROCESS_OK;
		}
		else if( (m_SW2&0x0F) == 0x01 )
		{
// Last PIN Try
			DisplayMessage( 1, "PIN LAST TRY", TRUE );
			goto VerifyContinue;
		}
		else
		{
// PIN Try Again
			DisplayMessage( 1, "PIN TRY AGAIN", TRUE );
			goto VerifyContinue;
		}
	}
	else
		return CARD_REJECTED;

	return PROCESS_OK;
}




BYTE CEMV::OnlinePIN( INT *iCVMSuccess )
{
	LPBYTE	ucTermCap 	= &m_EMVTermTags.t9F33[1];
	LPBYTE	ucTVR      = &m_EMVTermTags.t95[1];
	BYTE	ucValue, ucPIN[12], ucPinBlock[20];
	WORD	usPINLen;
	int		iByteNo, iRet;
	
	DisplayMessage( 1, "ONLINE PIN");
	WriteLogFile("OnlinePIN","Start Function");

// Check if terminal supports Online PIN
	GetByteNoAndValue(TERMCAP_ENCHIPERED_PIN_ONL, &ucValue, &iByteNo);
	if ((ucTermCap[iByteNo]&ucValue) != ucValue)
	{

		GetByteNoAndValue(TVR_PINPAD_NOT_PRESENT, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		*iCVMSuccess = CVM_FAIL;
		return TRUE;

	}
// Get online pin from cardholder
	else
	{
		memset(ucPIN, 0, sizeof(ucPIN));

		iRet = GetPin( 1,ucPinBlock,0 );
		
		if( iRet == FALSE )
		{
			if( m_NoPinPad )
			{
				GetByteNoAndValue(TVR_PINPAD_NOT_PRESENT, &ucValue, &iByteNo);
				ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				*iCVMSuccess = CVM_FAIL;
				return TRUE;
			}
			GetByteNoAndValue(TVR_PIN_NOT_ENTERED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			*iCVMSuccess = CVM_FAIL;
			return TRUE;
		}
		else
		{
			
			Pack(16,ucPinBlock,ucPIN,16);
			ucPIN[8]='\0';
			
			GetByteNoAndValue(TVR_ONLINE_PIN_ENTERED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			*iCVMSuccess = CVM_UNKNOWN;
			usPINLen = (WORD)strlen((char *)ucPIN);
		}
	}
	return TRUE;
}



BYTE CEMV::GetICCEncPublicKey( LPBYTE ucICCPINEncPubKeyModLen )
{
	int 	index,iExpLen,len;
	BYTE	ucPublicKeyModLen, ucIssPubKeyModLen;
	BYTE	ucExp[3], ucLenOfLen;
	BYTE	ucRet;

	memset( m_CAPubKeyMod, 0, sizeof(m_CAPubKeyMod) );
	memset( m_IssPubKeyMod, 0, sizeof(m_IssPubKeyMod) );
	memset( m_ICCPINEncPubKeyMod, 0, sizeof(m_ICCPINEncPubKeyMod) );

// Find the appropriate CAKey on the terminal matching with the PKIndex received from the card
// Returns the index of the CAKey in the array of CAKeys



	ucRet = SearchCAKeys( &index );
	ucPublicKeyModLen = m_cakeys[index].ucPKModuloLen;
	memcpy( m_CAPubKeyMod, &m_cakeys[index].ucPKModulo, ucPublicKeyModLen );
	iExpLen = m_cakeys[index].ucPKExpLen;
  	memcpy( ucExp, m_cakeys[index].ucPKExp, iExpLen );

// The ICC Pin Encipherment PK Certificate Len received from the card should be equal to PK Modulo Len
	len = GetLenOfDataEl( m_EMVCardTags.t90, &ucLenOfLen );
// WARNING : Type casting
	if( ucPublicKeyModLen != (BYTE)len )
	{
		return FALSE;
	}
// Decrypt the PKCertificate and check the format of the decrypted message
	ucRet = RecoverPubKeyCert(CA_PUBLIC_KEY_MOD, ucPublicKeyModLen, ucExp, iExpLen, len, &m_EMVCardTags.t90[ucLenOfLen], &ucIssPubKeyModLen);

	if( ucRet == FALSE )
	{
		return FALSE;
	}		
	memcpy( m_IssPubKeyMod, m_RecPubKeyMod, ucIssPubKeyModLen );
	

	len = GetLenOfDataEl(m_EMVCardTags.t9F2D, &ucLenOfLen);
	if( ucIssPubKeyModLen != (BYTE)len )
	{
		return FALSE;
	}	

	ucRet = RecoverICCPINEncPubKeyCert(ucIssPubKeyModLen, ucICCPINEncPubKeyModLen);

	if (ucRet == FALSE) {
		return FALSE;
	}	
//	memcpy(ucICCPINEncPubKeyMod, ucRecPubKeyMod, *ucICCPINEncPubKeyModLen);

	return TRUE;
}


BYTE CEMV::GetICCPublicKey( LPBYTE ucICCPubKeyModLen )
{
	int 	index, len;
	BYTE	ucPublicKeyModLen;
	BYTE	ucExp[3], iExpLen;
	BYTE	ucLenOfLen, ucRet, ucIssPubKeyModLen;

	memset( m_CAPubKeyMod, 0, sizeof(m_CAPubKeyMod) );
	memset( m_IssPubKeyMod, 0, sizeof(m_IssPubKeyMod) );
	memset( m_ICCPubKeyMod, 0, sizeof(m_ICCPubKeyMod) );

// Find the appropriate CAKey on the terminal matching with the PKIndex received from the card
// Returns the index of the CAKey in the array of CAKeys
// The ICC Pin Encipherment PK Certificate Len received from the card should be equal to PK Modulo Len
	ucRet = SearchCAKeys( &index );

	ucPublicKeyModLen = m_cakeys[index].ucPKModuloLen;
	len = GetLenOfDataEl( m_EMVCardTags.t90, &ucLenOfLen );
	if( ucPublicKeyModLen != (BYTE)len )
		return FALSE;
	memcpy( m_CAPubKeyMod, &m_cakeys[index].ucPKModulo, ucPublicKeyModLen );
	iExpLen = m_cakeys[index].ucPKExpLen;
  	memcpy(ucExp, m_cakeys[index].ucPKExp, iExpLen);

	len = GetLenOfDataEl(m_EMVCardTags.t90, &ucLenOfLen);

// Decrypt the PKCertificate and check the format of the decrypted message
	ucRet = RecoverPubKeyCert(	CA_PUBLIC_KEY_MOD, ucPublicKeyModLen, ucExp, 
								iExpLen, len, &m_EMVCardTags.t90[ucLenOfLen], &ucIssPubKeyModLen );
	if( ucRet == FALSE )
	{
		return FALSE;
	}	
	memcpy( m_IssPubKeyMod, m_RecPubKeyMod, ucIssPubKeyModLen );

	len = GetLenOfDataEl( m_EMVCardTags.t9F46, &ucLenOfLen );
	if( ucIssPubKeyModLen != (BYTE)len )
	{
		return FALSE;
	}
	ucRet = RecoverICCPubKeyCert(ucIssPubKeyModLen, ucICCPubKeyModLen);
	if (ucRet == FALSE) {
		return FALSE;
	}	

	return TRUE;
}




// Recover the ICC PIN Encipherment Public Key Data from the ICC PIN Encipherment Public Key Certificate
// Check the format of the recovered data
// Calculates the hash of the received message
// Checks the hash values are equal
BYTE CEMV::RecoverICCPINEncPubKeyCert(BYTE ucIssPubKeyModLen, LPBYTE ucICCPINEncPubKeyModLen)
{
	int len;
	BYTE 	ucLenOfLen, ucRet;

	len = GetLenOfDataEl( m_EMVCardTags.t9F2D, &ucLenOfLen );
	memset( m_RecoveredData, 0, sizeof(m_RecoveredData) );
	ucRet = RSAEncrypt( ISS_PUBLIC_KEY_MOD, ucIssPubKeyModLen, 
						&m_EMVCardTags.t9F32[1], m_EMVCardTags.t9F32[0], &m_EMVCardTags.t9F2D[ucLenOfLen], len);
	if( ucRet == FALSE )
	{
		return FALSE;
	}	

// Check the format of the recovered data

// Check the header
	if( m_RecoveredData[0] != 0x6A )
	{
		return FALSE;
	}	

// Check the Certificate Format
	if( m_RecoveredData[1] != 0x04 )
	{
		return FALSE;
	}	

// Check the footer
	if( m_RecoveredData[ucIssPubKeyModLen-1] != 0xBC )
	{
		return FALSE;
	}	

// Get the ICC PIN Encipherment Public Key from the Recovered Data
	memcpy( m_ICCPINEncPubKeyMod, m_RecoveredData+21, ucIssPubKeyModLen-42);
	*ucICCPINEncPubKeyModLen	= m_RecoveredData[19];
	len = GetLenOfDataEl( m_EMVCardTags.t9F2F, &ucLenOfLen );
	if( len != 0 )
		memcpy( m_ICCPINEncPubKeyMod+ucIssPubKeyModLen-42, &m_EMVCardTags.t9F2F[ucLenOfLen], len );
	return TRUE;
}






// Check Card And Terminal Application Versions
// Check Application Usage Control and Additional Terminal Capabilities
BYTE CEMV::ProcessRestrict( void )
{
	int 	iByteNo;
	LPBYTE	ucTVR = &m_EMVTermTags.t95[1];
	LPBYTE	ucAUC = &m_EMVCardTags.t9F07[1];
	BYTE	ucAUCLen = m_EMVCardTags.t9F07[0];
	BYTE	TranType = m_EMVTermTags.t9C[1];
	LPBYTE	ucAddTermCap = &m_EMVTermTags.t9F40[1];
	LPBYTE	ucAppEffDate = &m_EMVCardTags.t5F25[1];
	LPBYTE	ucAppExpDate = &m_EMVCardTags.t5F24[1];
	int		iAppEffDate, iAppExpDate, iCurrentDate;
	LPBYTE	ucCurrentDate= &m_EMVTermTags.t9A[1];
	BYTE	ucValue,ucCashType;

	if (ucAUCLen == 0)
		return PROCESS_OK;

	WriteLogFile("ProcessRestrict","Start Function");

	SetTermVersion();

// Check card and terminal application version numbers
	if ((memcmp(&m_EMVTermTags.t9F09[1], &m_EMVCardTags.t9F08[1], m_EMVCardTags.t9F08[0]) != 0)&&(m_EMVCardTags.t9F08[0] != 0))
	{
		GetByteNoAndValue(TVR_DIFF_APP_VERSION, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	}

	if ((m_EMVTermTags.t9F1A[0] != 0)||(m_EMVCardTags.t5F28[0] != 0))
	{
		if( GetCardBrand() == BRAND_VISA )
			ucCashType=TRANTYPE_CASH_VS;
		else	
			ucCashType=TRANTYPE_CASH_MC;
		

// Check terminal and card country codes to understand the transaction is domestic or international
		if (memcmp(&m_EMVTermTags.t9F1A[1], &m_EMVCardTags.t5F28[1], m_EMVCardTags.t5F28[0]) == 0)
		{
// Domestic Transactions
			if (TranType == ucCashType)
			{
				GetByteNoAndValue(ATC_CASH	, &ucValue, &iByteNo);
// Check if terminal supports domestic cash transactions
				if ((ucAddTermCap[iByteNo]&ucValue) != ucValue)
				{
				
					GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
					ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				}
				GetByteNoAndValue(AUC_VALID_DOMESTIC_CASH	, &ucValue, &iByteNo);
// Check if card supports domestic cash transactions
				if ((ucAUC[iByteNo]&ucValue) != ucValue)
				{
				
					GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
					ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				}
			}
			else if (TranType == TRANTYPE_SALE)
			{
				GetByteNoAndValue(ATC_GOODS, &ucValue, &iByteNo);
// Check if terminal supports domestic goods
				if ((ucAddTermCap[iByteNo]&ucValue) != ucValue)
				{
					GetByteNoAndValue(ATC_SERVICES, &ucValue, &iByteNo);
// Check if terminal supports domestic services
					if ((ucAddTermCap[iByteNo]&ucValue) != ucValue)
					{
					
						GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
						ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
					}
				}
				GetByteNoAndValue(AUC_VALID_DOMESTIC_GOODS, &ucValue, &iByteNo);
// Check if card supports domestic goods
				if ((ucAUC[iByteNo]&ucValue) != ucValue)
				{
					GetByteNoAndValue(AUC_VALID_DOMESTIC_SERVICES, &ucValue, &iByteNo);
// Check if card supports domestic services
					if ((ucAUC[iByteNo]&ucValue) != ucValue)
					{
					
						GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
						ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
					}
				}
			}
			else if( TranType == TRANTYPE_CASHBACK )
			{
				GetByteNoAndValue(ATC_CASHBACK	, &ucValue, &iByteNo);
// Check if card supports domestic cashback transactions
				if ((ucAddTermCap[iByteNo]&ucValue) != ucValue)
				{
				
					GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
					ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				}
				GetByteNoAndValue(AUC_ALLOWED_DOMESTIC_CASHBACK	, &ucValue, &iByteNo);
// Check if terminal supports domestic cashback transactions
				if ((ucAUC[iByteNo]&ucValue) != ucValue)
				{
				
					GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
					ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				}
			}
		}
		else
		{
// International Transaction
			if (TranType == ucCashType)
			{
				GetByteNoAndValue(ATC_CASH	, &ucValue, &iByteNo);
// Check if terminal supports domestic cash transactions
				if ((ucAddTermCap[iByteNo]&ucValue) != ucValue)
				{
				
					GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
					ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				}
				GetByteNoAndValue(AUC_VALID_INTERNATIONAL_CASH	, &ucValue, &iByteNo);
// Check if card supports domestic cash transactions
				if ((ucAUC[iByteNo]&ucValue) != ucValue)
				{
				
					GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
					ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				}
			}
			else if (TranType == TRANTYPE_SALE)
			{
				GetByteNoAndValue(ATC_GOODS, &ucValue, &iByteNo);
// Check if terminal supports domestic goods
				if ((ucAddTermCap[iByteNo]&ucValue) != ucValue)
				{
					GetByteNoAndValue(ATC_SERVICES, &ucValue, &iByteNo);
// Check if terminal supports domestic services
					if ((ucAddTermCap[iByteNo]&ucValue) != ucValue)
					{
					
						GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
						ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
					}
				}
				GetByteNoAndValue(AUC_VALID_INTERNATIONAL_GOODS, &ucValue, &iByteNo);
// Check if card supports domestic goods
				if ((ucAUC[iByteNo]&ucValue) != ucValue)
				{
					GetByteNoAndValue(AUC_VALID_INTERNATIONAL_SERVICES, &ucValue, &iByteNo);
// Check if card supports domestic services
					if ((ucAUC[iByteNo]&ucValue) != ucValue)
					{
					
						GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
						ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
					}
				}
			}
			else if (TranType == TRANTYPE_CASHBACK)
			{
				GetByteNoAndValue(ATC_CASHBACK	, &ucValue, &iByteNo);
// Check if card supports domestic cashback transactions
				if ((ucAddTermCap[iByteNo]&ucValue) != ucValue)
				{
				
					GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
					ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				}
				GetByteNoAndValue(AUC_ALLOWED_INTERNATIONAL_CASHBACK	, &ucValue, &iByteNo);
// Check if terminal supports domestic cashback transactions
				if ((ucAUC[iByteNo]&ucValue) != ucValue)
				{
				
					GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
					ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
				}
			}
		}
	}

// Check if the card is valid another than ATM devices
	GetByteNoAndValue(AUC_VALID_NONATMS, &ucValue, &iByteNo);
	if ((ucAUC[iByteNo]&ucValue) != ucValue)
	{

		GetByteNoAndValue(TVR_SERVICE_NOT_ALLOWED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	}

// Check if application is effective
	if (ucAppEffDate[0] < 0x50)
		iAppEffDate = ucAppEffDate[0]+0x100;
	else
		iAppEffDate = (int)ucAppEffDate[0];

	if (ucCurrentDate[0] < 0x50)
		iCurrentDate = (int)ucCurrentDate[0]+0x100;
	else
		iCurrentDate = (int)ucCurrentDate[0];

	if (iAppEffDate > iCurrentDate)
	{
		GetByteNoAndValue(TVR_APP_NOT_EFFECTIVE, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	}
	else if (iAppEffDate == iCurrentDate)
	{
		if (ucAppEffDate[1] > ucCurrentDate[1])
		{
			GetByteNoAndValue(TVR_APP_NOT_EFFECTIVE, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		}
		else if (ucAppEffDate[2] > ucCurrentDate[2]) {
			GetByteNoAndValue(TVR_APP_NOT_EFFECTIVE, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		}	
	}


// Check if application is expired
	if (ucAppExpDate[0] < 0x50)
		iAppExpDate = (int)ucAppExpDate[0]+0x100;
	else
		iAppExpDate = (int)ucAppExpDate[0];

	if (ucCurrentDate[0] < 0x50)
		iCurrentDate = (int)ucCurrentDate[0]+0x100;
	else
		iCurrentDate = (int)ucCurrentDate[0];

	if (iAppExpDate < iCurrentDate)
	{
		GetByteNoAndValue(TVR_EXPIRED_APP, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	}
	if (iAppExpDate == iCurrentDate)
	{
		if (ucAppExpDate[1] < ucCurrentDate[1])
		{
			GetByteNoAndValue(TVR_EXPIRED_APP, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		}
		else if (ucAppExpDate[2] < ucCurrentDate[2])
		{
			GetByteNoAndValue(TVR_EXPIRED_APP, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		}
	}

	WriteLogFile("ProcessRestrict","Finish Function");
	return PROCESS_OK;
}




BYTE CEMV::OfflineDataAuth( void )
{
	char	cTypeOfAuth;
	BYTE	ucRet;

	DisplayMessage( 2, "PLEASE WAIT... PROCESSING...");
	WriteLogFile("OfflineDataAuth","Start function");

// Determine what kind of authentication does the card request (SDA, DDA)
	ucRet = DetermineSDAorDDA(&cTypeOfAuth);
	if (ucRet != PROCESS_OK)
		return ucRet;

	if (cTypeOfAuth == 'S')
	{
		WriteLogFile("OfflineDataAuth","PerformSDA");
		ucRet = PerformSDA();
		if (ucRet != PROCESS_OK)
		return ucRet;
	}

	else if (cTypeOfAuth == 'D')
	{
		WriteLogFile("OfflineDataAuth","PerformDDA");
		ucRet = PerformDDA();
		if (ucRet != PROCESS_OK)
		return ucRet;
	}
	return PROCESS_OK;
}


BYTE CEMV::DetermineSDAorDDA(char *pcTypeOfAuth)
{
	int iByteNo;
	BYTE ucValue;
	BYTE *ucAIP = &m_EMVCardTags.t82[1];
	BYTE ucAIPLen = m_EMVCardTags.t82[0];
	BYTE *ucTVR = &m_EMVTermTags.t95[1];
	BYTE ucTVRLen = m_EMVTermTags.t95[0];
	BYTE ucTSILen = m_EMVTermTags.t9B[0];
	BYTE *ucTermCap = &m_EMVTermTags.t9F33[1];
	BYTE ucTermCapLen = m_EMVTermTags.t9F33[0];


	if ((ucAIPLen == 0)||(ucTVRLen == 0)||(ucTSILen == 0)||(ucTermCapLen == 0)) {
		return MISSING_MANDATORY_OBJECT;
	}	
// Check DDA in AIP
	GetByteNoAndValue(AIP_DDA, &ucValue, &iByteNo);
	if ((ucAIP[iByteNo]&ucValue) == ucValue)
	{
// Check DDA in Terminal Capabilities (9F33)
		GetByteNoAndValue(TERMCAP_DDA, &ucValue, &iByteNo);
		if ((ucTermCap[iByteNo]&ucValue) == ucValue)
		{
//DDA Processing
			*pcTypeOfAuth = 'D';
			return PROCESS_OK;
		}
	}

// Check SDA in AIP
	GetByteNoAndValue(AIP_SDA, &ucValue, &iByteNo);
	if ((ucAIP[iByteNo]&ucValue) == ucValue)
	{
// Check SDA in Terminal Capabilities (9F33)
		GetByteNoAndValue(TERMCAP_SDA, &ucValue, &iByteNo);
		if ((ucTermCap[iByteNo]&ucValue) == ucValue)
		{
//SDA Processing
			*pcTypeOfAuth = 'S';
			return PROCESS_OK;
		}
	}



// Set "Offline Data Authentication is not performed" bit in TVR
	GetByteNoAndValue(TVR_AUTH_NOT_PERFORMED, &ucValue, &iByteNo);
	ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
	*pcTypeOfAuth = 'N';


	return PROCESS_OK;
}



BYTE CEMV::PerformSDA( void )
{
	int   index, iByteNo, len, iExpLen;
	BYTE ucIssPubKeyModLen;
	BYTE ucPublicKeyModLen;
	BYTE ucExp[3];
	BYTE *ucTVR = &m_EMVTermTags.t95[1];
	BYTE ucTVRLen = m_EMVTermTags.t95[0];
	BYTE *ucTSI = &m_EMVTermTags.t9B[1];
	BYTE ucTSILen = m_EMVTermTags.t9B[0];
	BYTE ucValue, ucRet, ucLenOfLen;
	
	memset(m_CAPubKeyMod, 0, sizeof(m_CAPubKeyMod));
	memset(m_IssPubKeyMod, 0, sizeof(m_IssPubKeyMod));
	
	if (ucTVRLen == 0) {
		return MISSING_MANDATORY_OBJECT;
	}	

	if (ucTSILen == 0) {
		return MISSING_MANDATORY_OBJECT;
	}	

	GetByteNoAndValue(TSI_AUTH_PERFORMED, &ucValue, &iByteNo);
	ucTSI[iByteNo] = ucTSI[iByteNo]|ucValue;

// Find the appropriate CAKey on the terminal matching with the PKIndex received from the card
// Returns the index of the CAKey in the array of CAKeys


	if (m_EMVCardTags.t8F[0] == 0)
	{
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		
		GetByteNoAndValue(TVR_SDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;

		return PROCESS_OK;
	}


	ucRet = SearchCAKeys(&index);
	if (ucRet == FALSE)
	{
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_SDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
    }
	ucPublicKeyModLen = m_cakeys[index].ucPKModuloLen;
	memcpy( m_CAPubKeyMod, &m_cakeys[index].ucPKModulo, ucPublicKeyModLen);
	iExpLen = m_cakeys[index].ucPKExpLen;
  	memcpy( ucExp, m_cakeys[index].ucPKExp, iExpLen);

// Check if the mandatory data elements received from the card for DDA
// If the Issuer Public Key Certificate (Tag 90) wasn't received from the card set related bits in TVR

	len = GetLenOfDataEl(m_EMVCardTags.t90, &ucLenOfLen);
	if (len == 0)
	{
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_SDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

// If the Issuer Public Exponent Certificate (Tag 9F32) wasn't received from the card set related bits in TVR
	len = GetLenOfDataEl(m_EMVCardTags.t9F32, &ucLenOfLen);
	if (len == 0)
	{
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_SDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}
// If the Signed Static Application Data (Tag 93) wasn't received from the card set related bits in TVR


	len = GetLenOfDataEl(m_EMVCardTags.t93, &ucLenOfLen);
	if (len == 0)
	{
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_SDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}


// The PK Certificate Len received from the card should be equal to PK Modulo Len
	len = GetLenOfDataEl(m_EMVCardTags.t90, &ucLenOfLen);
	if (ucPublicKeyModLen != (BYTE)len)
	{
		GetByteNoAndValue(TVR_SDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

// Decrypt the PKCertificate and check the format of the decrypted message
	

	ucRet = RecoverPubKeyCert(CA_PUBLIC_KEY_MOD, ucPublicKeyModLen, ucExp, iExpLen, len, &m_EMVCardTags.t90[ucLenOfLen], &ucIssPubKeyModLen);
	if (ucRet == FALSE)
	{
		GetByteNoAndValue(TVR_SDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}
	memcpy( m_IssPubKeyMod, m_RecPubKeyMod, ucIssPubKeyModLen);
// Decrypt the Signed Application Data received from the card and check the format of the decrypted massage

	ucRet = VerifyStaticAppData(ISS_PUBLIC_KEY_MOD, ucIssPubKeyModLen, index);
	if (ucRet == FALSE)
	{
		GetByteNoAndValue(TVR_SDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}
	return PROCESS_OK;
}


BYTE CEMV::PerformDDA( void )
{
	int 	index, iByteNo,i, len, iExpLen;
	BYTE 	ucICCPubKeyModLen, ucIssPubKeyModLen;
	BYTE	ucPublicKeyModLen;
	BYTE	ucExp[3], ucLenOfLen, ucDDOLDataLen;
	BYTE 	*ucTVR = &m_EMVTermTags.t95[1];
	BYTE 	ucTVRLen = m_EMVTermTags.t95[0];
	BYTE 	*ucTSI = &m_EMVTermTags.t9B[1];
	BYTE 	ucTSILen = m_EMVTermTags.t9B[0];
	BYTE 	ucValue, ucRet;
	BYTE 	ucDDOLD[MAX_DOL_LEN];



	memset( m_CAPubKeyMod, 0, sizeof( m_CAPubKeyMod ) );
	memset( m_IssPubKeyMod, 0, sizeof( m_IssPubKeyMod ) );
    memset( ucDDOLD, 0, sizeof(ucDDOLD));

	if (ucTVRLen == 0) {
		return MISSING_MANDATORY_OBJECT;
	}	
	if (ucTSILen == 0) {
		return MISSING_MANDATORY_OBJECT;
	}	
	GetByteNoAndValue(TSI_AUTH_PERFORMED, &ucValue, &iByteNo);
	ucTSI[iByteNo] = ucTSI[iByteNo]|ucValue;

// Find the appropriate CAKey on the terminal matching with the PKIndex received from the card
// Returns the index of the CAKey in the array of CAKeys

	if (m_EMVCardTags.t8F[0] == 0)
	{


		
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

	ucRet = SearchCAKeys(&index);
	if (ucRet == FALSE)
	{


		
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}
	ucPublicKeyModLen = m_cakeys[index].ucPKModuloLen;
	memcpy( m_CAPubKeyMod, &m_cakeys[index].ucPKModulo, ucPublicKeyModLen);
	iExpLen = m_cakeys[index].ucPKExpLen;
  	memcpy(ucExp, m_cakeys[index].ucPKExp, iExpLen);


// Check if the mandatory data elements received from the card for DDA
// If the Issuer Public Key Certificate (Tag 90) wasn't received from the card set related bits in TVR
	len = GetLenOfDataEl(m_EMVCardTags.t90, &ucLenOfLen);
	if (len == 0)
	{




		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}
// If the Issuer Public Exponent Certificate (Tag 9F32) wasn't received from the card set related bits in TVR
	len = GetLenOfDataEl(m_EMVCardTags.t9F32, &ucLenOfLen);
	if (len == 0)
	{



		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}
// If the ICC Public Key Certificate(Tag 9F46) wasn't received from the card set related bits in TVR
	len = GetLenOfDataEl(m_EMVCardTags.t9F46, &ucLenOfLen);
	if (len == 0)
	{



		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}
// If the ICC Public Key Exponent(Tag 9F47) wasn't received from the card set related bits in TVR
	len = GetLenOfDataEl(m_EMVCardTags.t9F47, &ucLenOfLen);
	if (len == 0)
	{



		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

// The PK Certificate Len received from the card should be equal to PK Modulo Len

	len = GetLenOfDataEl(m_EMVCardTags.t90, &ucLenOfLen);
	if (ucPublicKeyModLen != (BYTE)len)
	{



		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

// Decrypt the PKCertificate and check the format of the decrypted message
	ucRet = RecoverPubKeyCert(CA_PUBLIC_KEY_MOD, ucPublicKeyModLen, ucExp, iExpLen, len, &m_EMVCardTags.t90[ucLenOfLen], &ucIssPubKeyModLen);
	
	if (ucRet == FALSE)
	{



		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

	memcpy( m_IssPubKeyMod, m_RecPubKeyMod, ucIssPubKeyModLen);


	len = GetLenOfDataEl(m_EMVCardTags.t9F46, &ucLenOfLen);
// WARNING : Type Casting

	if (ucIssPubKeyModLen != (BYTE)len)
	{



		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}


	ucRet = RecoverICCPubKeyCert(ucIssPubKeyModLen, &ucICCPubKeyModLen);

	if (ucRet == FALSE)
	{



		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

//In the case of there is no DDOL received from the card, use default DDOL (9F37)
	len = GetLenOfDataEl(m_EMVCardTags.t9F49, &ucLenOfLen);
	if (len == 0)
	{
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		len = GetLenOfDataEl(m_EMVTermTags.tDF95, &ucLenOfLen);
		if (len == 0)
		{



			GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			return PROCESS_OK;
		}
		for (i=0;i<len-1;i++)
		{
// The 9F37 should be present in Default DDOL
			if ((m_EMVTermTags.tDF95[ucLenOfLen] == 0x9F)&&(m_EMVTermTags.tDF95[ucLenOfLen+1] == 0x37))
				break;
		}
		if (i == (len-1))
		{



			GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			return PROCESS_OK;
		}
// Prep DDOL Data to be used in INTERNAL_AUTHENTICATE command. Use default DDOL parametre on terminal
		PrepDOLData(len, &m_EMVTermTags.tDF95[ucLenOfLen], ucDDOLD, &ucDDOLDataLen, DOL_DDOL);
	}
	else
	{
		len = GetLenOfDataEl(m_EMVCardTags.t9F49, &ucLenOfLen);
		for (i=0;i<len-1;i++)
		{
// The 9F37 should be present in DDOL
			if ((m_EMVCardTags.t9F49[ucLenOfLen+i] == 0x9F)&&(m_EMVCardTags.t9F49[ucLenOfLen+i+1] == 0x37))
				break;
		}
		if (i == (len-1))
		{



			GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
			return PROCESS_OK;
		}

// Prep DDOL Data to be used in INTERNAL_AUTHENTICATE command
		PrepDOLData(len, &m_EMVCardTags.t9F49[ucLenOfLen], ucDDOLD, &ucDDOLDataLen, DOL_DDOL);
	}

// Get dynamic signature from card
	ucRet = INTERNAL_AUTHENTICATE(ucDDOLD, ucDDOLDataLen);
	if (ucRet != PROCESS_OK)
		return ucRet;


	if( (m_SW1 != 0x90) || (m_SW2 != 0x0) )
		return CARD_REJECTED;

// The response data is in the Format 1    SW1 SW2 80 len Data
	if( m_Apdu.read_data[0] == 0x80 )
	{
		if( (m_Apdu.read_data[1]&0x80) == 0x80 )
		{
			ucLenOfLen = m_Apdu.read_data[1]&0x7F;
			len = Bin2Lng (&m_Apdu.read_data[2], ucLenOfLen) ;
		}
		else
		{
			ucLenOfLen = 1;
			len = m_Apdu.read_data[1];
		}
		if( len != m_Apdu.read_len-3-ucLenOfLen )
			return LEN_INCORRECT;
		m_EMVCardTags.t9F4B[0] = len;
		memcpy(&m_EMVCardTags.t9F4B[1], &m_Apdu.read_data[1+ucLenOfLen], len);

	}
// The response data is in the Format2
	else if( m_Apdu.read_data[0] == 0x77 )
	{
		len = GetLenOfDataEl( &m_Apdu.read_data[1], &ucLenOfLen );

		ucRet = AddToEmvTAGS( &m_Apdu.read_data[1+ucLenOfLen], len, CARD );
		if (ucRet != PROCESS_OK)
			return ucRet;
	}
	else
		return DATA_FORMAT_INCORRECT;

// Verify dynamic signature read from the card by ICC Public Key
	ucRet = VerifyDynamicSign(ICC_PUBLIC_KEY_MOD, ucICCPubKeyModLen, ucDDOLD, ucDDOLDataLen);
	if (ucRet == FALSE)
	{



		GetByteNoAndValue(TVR_DDA_FAILED, &ucValue, &iByteNo);
		ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return PROCESS_OK;
	}

	return PROCESS_OK;
}

int CEMV::SearchCAKeys(int *piIndex)
{
	int			i, iByteNo;
	LPBYTE		ucRID = &m_EMVCardTags.t84[1];
	BYTE		ucPKI  = m_EMVCardTags.t8F[1];
	LPBYTE		ucTVR  = &m_EMVTermTags.t95[1];
	BYTE		ucValue;

	if (m_EMVCardTags.t8F[0] == 0)
	{
		GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
				ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		return FALSE;
	}


	//len = sizeof(cakeys)/sizeof( CAKEYS);  NumOfCakeys kullaniliyor
	for( i=0; i<m_NumOfCakeys; i++ )
	{
		if( (memcmp( m_cakeys[i].ucRid, ucRID, 5) == 0) && (m_cakeys[i].ucPKIndex == ucPKI) )
		{
	        *piIndex = i;
            return TRUE;
		}
	}
	return FALSE;
}

// Recover the Issuer Public Key Data from the Issuer Public Key Certificate (Tag : 90)
// Check the format of the recovered data
// Calculates the hash of the received message
// Checks the hash values are equal
BYTE CEMV::RecoverPubKeyCert(BYTE ucPubKeyType, BYTE ucPublicKeyModLen, LPBYTE ucExp, int iExpLen, BYTE ucCertLen, LPBYTE ucCertValue, LPBYTE ucIssPubKeyModLen)
{
	LPBYTE 	ucTVR = &m_EMVTermTags.t95[1];
	BYTE 	ucIssIdNum[4], ucRet;
	BYTE 	ucExpireDate[2];
	BYTE 	digest[20], year[2], ucValue;
	BYTE	ucLenOfLen, ucSerialNo[3], ucRID[5];
	int 	iHashDataIndex, iExpireDate, iyear, iByteNo, len;
	BYTE	ucIssIdNumLen,TmpStr1[10],TmpStr2[10];

	CTime dateTime = CTime::GetCurrentTime();

    memset( m_HashData, 0, sizeof(m_HashData) );
	memset( m_RecoveredData, 0, sizeof(m_RecoveredData) );

	ucRet = RSAEncrypt(ucPubKeyType, ucPublicKeyModLen, ucExp, iExpLen, ucCertValue, ucCertLen);
	if (ucRet == FALSE) 
	{
		return FALSE;
	}	

// Check the format of the recovered data

// Check the header
	if( m_RecoveredData[0] != 0x6A )
	{
		return FALSE;
	}	


// Check the Certificate Format
	if( m_RecoveredData[1] != 0x02 )
	{
		return FALSE;
	}	

// Check the hash algorithm indicator
	if( m_RecoveredData[11] != 0x01 )
	{
		return FALSE;
	}
// Check the Issuer Public Key algorithm indicator
	if( m_RecoveredData[12] != 0x01 )
	{
		return FALSE;
	}	


// Check the trailer of the recovered data
	if( m_RecoveredData[ucPublicKeyModLen-1] != 0xBC )
	{
		return FALSE;
	}	

// Get the Issuer Public Key from the Recovered Data

	memcpy( m_RecPubKeyMod, m_RecoveredData+15, ucPublicKeyModLen-36 );
// Check if Issuer Public Key Remainder (t92) is present.
	len = GetLenOfDataEl(m_EMVCardTags.t92, &ucLenOfLen);
	if(len != 0)
	{
		memcpy( m_RecPubKeyMod + ucPublicKeyModLen-36, &m_EMVCardTags.t92[ucLenOfLen], len );
	}
	else
	{
		// !ZO EMV patch 13/02/2006 : 1408 bits or greater does not have remainder
		if (ucPublicKeyModLen<176) { 
			GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		}
	}

	*ucIssPubKeyModLen = m_RecoveredData[13];
// Prepare the hash data according to EMV 3.1.1 Card Specification Part 4 Section 1.3
	iHashDataIndex = 0;
	memcpy( m_HashData, m_RecoveredData+1, 14 + ucPublicKeyModLen - 36);
	iHashDataIndex += 14 + ucPublicKeyModLen - 36;

// Pad Issuer Public Key Remainder (if present) to the Hash Data
	if( len != 0 )
	{
		memcpy( m_HashData+iHashDataIndex, &m_EMVCardTags.t92[ucLenOfLen], len );
		iHashDataIndex += len;
	}
// Pad Issuer Public Key Exponent (if present) to the Hash Data
	memcpy( m_HashData+iHashDataIndex, &m_EMVCardTags.t9F32[1], m_EMVCardTags.t9F32[0]);
	iHashDataIndex += m_EMVCardTags.t9F32[0];

	compute_hash_str( m_HashData, iHashDataIndex, digest );


//  Check if the calculated hash result equals to hash received from the card
	if( memcmp(digest, &m_RecoveredData[ucPublicKeyModLen-21], 20) != 0 )
	{
		return FALSE;
	}

// Check if Issuer Identification Number matches the leftmost 3-8 digits of PAN
	memcpy( ucIssIdNum, m_RecoveredData+2, 4 );

	Bcd2Str( ucIssIdNum, 4, 0, (char*)TmpStr1 );
	Bcd2Str( &m_EMVCardTags.t5A[1], 4, 0, (char*)TmpStr2 );
	
	ucIssIdNumLen=3;
	while( ucIssIdNumLen<8 )
	{
		if (TmpStr1[ucIssIdNumLen]=='F') break;
		ucIssIdNumLen++;
	}

	if( memcmp(TmpStr1, TmpStr2, ucIssIdNumLen) != 0 )
	{
//!!!sel??? hatali idi	if (memcmp(ucIssIdNum, &m_EMVCardTags.t5A[1], 3) != 0) {
		return FALSE;
	}	

// Check the Certification Expiration date to see if certificate has expired
// The format is ddmmyy in the string
	Lng2Bcd( dateTime.GetYear() - 2000, year, 1 );

	memcpy( ucExpireDate, m_RecoveredData+6, 2);
	if (ucExpireDate[0] > 0x12) {
		return FALSE;
	}	


	if (year[0] < 0x50)
		iyear = year[0]+0x100;
	else
		iyear = (int)year[0];

// In the POS year is calculated from the year 1900
	if (ucExpireDate[1] < 0x50)
		iExpireDate = ucExpireDate[1]+0x100;
	else
		iExpireDate = (int)ucExpireDate[1];

	if (iExpireDate < iyear)
	{
		return FALSE;
	}
	else if( iExpireDate == iyear ) 
	{
		if( ucExpireDate[0] < dateTime.GetMonth() )
		{
			return FALSE;
		}
	}	


// Verify that the concatenation of the RID, CA Public Key Index and Certificate Serial
// number is valid
	//PrepRevoc();
	memcpy( ucRID, &m_EMVTermTags.t9F06[1], 5 );
	memcpy( ucSerialNo, m_RecoveredData+8, 3 );

	ucRet = CheckCertSerialNo( ucRID, ucSerialNo, m_EMVCardTags.t8F[1] );
	return ucRet;
}


BYTE CEMV::VerifyStaticAppData(BYTE ucPubKeyModType, BYTE ucIssPubKeyModLen, int iCAIndex)
{
	int 	len;
	BYTE 	ucLenOfLen, ucRet;

// If the signed static application data has a length different from the length of the Issuer Public Key
// Modulus, return FALSE
	len = GetLenOfDataEl(m_EMVCardTags.t93, &ucLenOfLen);
	if( (BYTE)len != ucIssPubKeyModLen )
	{
		return FALSE;
	}

	ucRet = RecoverStaticAppData(ucPubKeyModType, ucIssPubKeyModLen);

	if (ucRet == FALSE)
		return FALSE;
	return TRUE;

}

// Recover the ICC Public Key Data from the ICC Public Key Certificate
// Check the format of the recovered data
// Calculates the hash of the received message
// Checks the hash values are equal
BYTE CEMV::RecoverICCPubKeyCert(BYTE ucIssPubKeyModLen, LPBYTE ucICCPubKeyModLen)
{
	BYTE	*ucTVR = &m_EMVTermTags.t95[1];
	BYTE 	ucLenOfLen, ucRet, ucValue;
	BYTE 	ucExpireDate[2], year[2], digest[20];
	int 	iHashDataIndex, iyear, iExpireDate, len, iSDATermLen, iByteNo;

	CTime dateTime = CTime::GetCurrentTime();

	memset( m_HashData, 0, sizeof(m_HashData) );
	memset( m_RecoveredData, 0, sizeof(m_RecoveredData) );
	memset( m_ICCPubKeyMod, 0, sizeof(m_ICCPubKeyMod) );
	len = GetLenOfDataEl( m_EMVCardTags.t9F46, &ucLenOfLen );


	ucRet = RSAEncrypt(ISS_PUBLIC_KEY_MOD, ucIssPubKeyModLen, &m_EMVCardTags.t9F32[1], m_EMVCardTags.t9F32[0], &m_EMVCardTags.t9F46[ucLenOfLen], len);
	if (ucRet == FALSE) 
	{



		return FALSE;
	}	

// Check the format of the recovered data

// Check the header
	if( m_RecoveredData[0] != 0x6A) 
	{
		return FALSE;
	}	

// Check the Certificate Format
	if( m_RecoveredData[1] != 0x04) 
	{
		return FALSE;
	}	

// Check the ICC Public Key Algorithm Indicator
	if( m_RecoveredData[18] != 0x01) 
	{
		return FALSE;
	}	

// Check the trailer of the recovered data
	if( m_RecoveredData[ucIssPubKeyModLen-1] != 0xBC) 
	{
		return FALSE;
	}	

// Get the ICC Public Key from the Recovered Data
	memcpy( m_ICCPubKeyMod, m_RecoveredData+21, ucIssPubKeyModLen-42 );
	*ucICCPubKeyModLen = m_RecoveredData[19];
	len = GetLenOfDataEl( m_EMVCardTags.t9F48, &ucLenOfLen );

// Check that if there should be ICC Public Key Remainder in the card

	if(len != 0)
	{
		memcpy( m_ICCPubKeyMod+ucIssPubKeyModLen-42, &m_EMVCardTags.t9F48[ucLenOfLen], len);
	}
	else
	{
		if(ucIssPubKeyModLen-42 < *ucICCPubKeyModLen)
		{
			GetByteNoAndValue(TVR_ICC_DATA_MISSING, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		}
	}

// Prepare the hash data according to EMV 3.1.1 Card Specification Part 4 Section 1.3
	iHashDataIndex = 0;
	memcpy( m_HashData, m_RecoveredData+1, 20 + ucIssPubKeyModLen-42);
	iHashDataIndex += 20 + ucIssPubKeyModLen - 42;

// Pad ICC Public Key Remainder (if present) to the Hash Data
	if (len != 0)
	{
		memcpy( m_HashData+iHashDataIndex, &m_EMVCardTags.t9F48[ucLenOfLen], len );
		iHashDataIndex += len;
	}

// Pad ICC Public Key Exponent (if present) to the Hash Data
	memcpy( m_HashData+iHashDataIndex, &m_EMVCardTags.t9F47[1], m_EMVCardTags.t9F47[0] );
	iHashDataIndex += m_EMVCardTags.t9F47[0];

	memcpy( m_HashData+iHashDataIndex, m_StaticAppData, m_StaticAppDataLen );
	iHashDataIndex += m_StaticAppDataLen;

	len = GetLenOfDataEl( m_EMVCardTags.t9F4A, &ucLenOfLen );
	if (len != 0)
	{
		PrepStaticTagListData(&iSDATermLen);
// In the case of processing of SDA Tag List failed
		if (iSDATermLen == 0)
		{



			return FALSE;
		}
		memcpy( m_HashData+iHashDataIndex, m_SDATermData, iSDATermLen);
		iHashDataIndex += iSDATermLen;
	}

	compute_hash_str( m_HashData, iHashDataIndex, digest);
//  Check if the calculated hash result equals to hash received from the card
	if( memcmp(digest, &m_RecoveredData[ucIssPubKeyModLen-21], 20 ) != 0 ) 
	{
		return FALSE;
	}
// Check if Recovered PAN equals to Application PAN read from the card
	if( memcmp( m_RecoveredData+2, &m_EMVCardTags.t5A[1], m_EMVCardTags.t5A[0] ) != 0 ) 
	{
		return FALSE;
	}	

// Check the Certification Expiration date to see if certificate has expired
	Lng2Bcd( dateTime.GetYear() - 2000, year, 1);
	Lng2Bcd( dateTime.GetMonth(), &year[1], 1);
	memcpy( ucExpireDate, m_RecoveredData+12, 2);
	if (ucExpireDate[0] > 0x12) 
	{
		return FALSE;
	}	

	if (year[0] < 0x50)
		iyear = year[0]+0x100;
	else
		iyear = (int)year[0];

// In the POS year is calculated from the year 1900
	if (ucExpireDate[1] < 0x50)
		iExpireDate = ucExpireDate[1]+0x100;
	else
		iExpireDate = (int)ucExpireDate[1];

	if (iExpireDate < iyear) 
	{
		return FALSE;
	}	
	else if (iExpireDate == iyear) {
		if (ucExpireDate[0] < year[1]) 
		{
			return FALSE;
		}
	}		
	

	if( m_RecoveredData[17] != 0x01 ) 
	{
		return FALSE;
	}	

	if( m_RecoveredData[18] != 0x01 )
	{
		return FALSE;
	}	

	return TRUE;
}

// Verifies the dynamic signature received in the response of the INTERNAL_AUTHENTICATE command by the
// public key of the card (ICC Public Key)
BYTE CEMV::VerifyDynamicSign(BYTE ucPubKeyModType, BYTE ucICCPubKeyModLen, LPBYTE ucDDOLData, BYTE ucDDOLDataLen)
{
	int	 	iHashIndex=0, len;
	BYTE 	ucLenOfLen, ucRet, digest[20];

	memset( m_HashData, 0, sizeof(m_HashData) );
	memset( m_RecoveredData, 0, sizeof(m_RecoveredData) );

	len = GetLenOfDataEl(m_EMVCardTags.t9F4B, &ucLenOfLen);
// The format of the Dynamic Signature : 90 00 80 Len DynSig[0].....DynSig[Len-1]
	if( ucICCPubKeyModLen != (BYTE)len )
		return FALSE;

	ucRet = RSAEncrypt(ucPubKeyModType, ucICCPubKeyModLen, &m_EMVCardTags.t9F47[1], m_EMVCardTags.t9F47[0], &m_EMVCardTags.t9F4B[ucLenOfLen], len);
	if( ucRet == FALSE )
		return FALSE;

// Check the header
	if( m_RecoveredData[0] != 0x6A )
		return FALSE;

// Check Signed Data Format
	if( m_RecoveredData[1] != 0x05 )
		return FALSE;

// Check Hash Algorithm Indicator
	if( m_RecoveredData[2] != 0x01 )
		return FALSE;

// Check the footer
	if( m_RecoveredData[ucICCPubKeyModLen-1] != 0xBC )
		return FALSE;

// Prepare the hash data
	memcpy( m_HashData+iHashIndex ,  m_RecoveredData+1, 3 + (ucICCPubKeyModLen -25) );
	iHashIndex += 3 + (ucICCPubKeyModLen -25);
	memcpy( m_HashData+iHashIndex, ucDDOLData, ucDDOLDataLen );
	iHashIndex += ucDDOLDataLen;

	compute_hash_str( m_HashData, iHashIndex, digest );
//  Check if the calculated hash result equals to hash received from the card
	if( memcmp(digest, m_RecoveredData+ucICCPubKeyModLen-21, 20 ) != 0 )
		return FALSE;

	return TRUE;
}


BYTE CEMV::CheckCertSerialNo(LPBYTE ucRID, LPBYTE ucSerialNo, BYTE ucPKIIndex)
{
    //int i;

    //for (i=0; i<m_NumOfRevokeKey/*sizeof(RevokeKeyDataTable)/sizeof(REVOC_TABLE)*/; i++)
    //{
    //    if ( (memcmp(RevokeKeyDataTable[i].ucRID, ucRID, 5)==0) &&
    //         (RevokeKeyDataTable[i].ucPKI == ucPKIIndex) &&
    //         (memcmp(RevokeKeyDataTable[i].ucPKSerial, ucSerialNo, 3)==0) )
    //        //key found in revocation table
    //    {
    //        return FALSE;
    //    }
    //}
//key not found in revocation table
    return TRUE;
}


// Recovers the data from SAD using the Issuer Public Key
// Checks the recovered data format
// Calculates the hash of the received message
// Checks the hash values are equal
BYTE CEMV::RecoverStaticAppData(BYTE ucPubKeyModType, BYTE ucIssPubKeyModLen)
{
	int	 	iHashIndex=0, iSDATermLen, len;
	BYTE 	digest[20], ucLenOfLen, ucRet;
	

	len = GetLenOfDataEl(m_EMVCardTags.t93, &ucLenOfLen);

	memset( m_RecoveredData, 0, sizeof(m_RecoveredData));
	ucRet = RSAEncrypt(ucPubKeyModType, ucIssPubKeyModLen, &m_EMVCardTags.t9F32[1], m_EMVCardTags.t9F32[0], &m_EMVCardTags.t93[ucLenOfLen], len);
	if (ucRet == FALSE) {
		return FALSE;
	}	
// Check header of the recovered data
	if( m_RecoveredData[0] != 0x6A )
	{
		return FALSE;
	}	

// Check Signed Data Format
	if( m_RecoveredData[1] != 0x03 )
	{
		return FALSE;
	}	

	if( m_RecoveredData[2] != 0x01 )
	{
		return FALSE;
	}	

// Check the trailer of the recovered data
	if( m_RecoveredData[ucIssPubKeyModLen-1] != 0xBC )
	{
		return FALSE;
	}	

// Prepare the hash data
	memcpy( m_HashData+iHashIndex ,  m_RecoveredData+1, 4 + (ucIssPubKeyModLen -26) );
	iHashIndex += 4 + (ucIssPubKeyModLen -26);
	memcpy( m_HashData+iHashIndex, m_StaticAppData, m_StaticAppDataLen);
	iHashIndex += m_StaticAppDataLen;
	len = GetLenOfDataEl(m_EMVCardTags.t9F4A, &ucLenOfLen);
	if (len != 0)
	{
		PrepStaticTagListData(&iSDATermLen);

// In the case of processing of SDA Tag List failed
		if (iSDATermLen == 0) 
		{
			return FALSE;
		}
		memcpy( m_HashData+iHashIndex, m_SDATermData, iSDATermLen);
		iHashIndex += iSDATermLen;
	}
		

	compute_hash_str( m_HashData, iHashIndex, digest);


	if (memcmp(digest, m_RecoveredData+ucIssPubKeyModLen-21, 20) != 0) {
		return FALSE;
	}
	//!!!sel??? sonradan eklendi
	m_EMVCardTags.t9F45[0] = 2;
	memcpy(&m_EMVCardTags.t9F45[1], m_RecoveredData+3, 2);
	
	return TRUE;
}

BYTE CEMV::PrepStaticTagListData(int *iStaticTagListLen)
{
	int index, msgindex,i, iTableSize, len, iSTLLen;
	BYTE ucTag[2], ucLenOfLen;
	BYTE *ucStaticTags;

	iSTLLen = GetLenOfDataEl(m_EMVCardTags.t9F4A, &ucLenOfLen);
	ucStaticTags = &m_EMVCardTags.t9F4A[ucLenOfLen];

	index = 0;
	msgindex = 0;
	do
	{
		if ((ucStaticTags[index] == 0x9F)||(ucStaticTags[index] == 0x5F))
		{
			ucTag[0] = ucStaticTags[index++];
			ucTag[1] = ucStaticTags[index++];
		}
		else
		{
			ucTag[0] = ucStaticTags[index++];
		}

		iTableSize = sizeof(m_TagAddress)/sizeof(TAG_ADDRESS);
// Find the tag in table
		for (i=0;i<iTableSize;i++)
		{
			if (m_TagAddress[i].Tag[0] == ucTag[0])
			{
				if ((ucTag[0] != 0x9F)&&(ucTag[0] != 0x5F))
					break;
				else
					if (m_TagAddress[i].Tag[1] == ucTag[1])
						break;
			}
		}

// The tag found
		if (i != iTableSize)
		{
			if (m_TagAddress[i].Address[0] != 0)
			{
				len = GetLenOfDataEl(m_TagAddress[i].Address, &ucLenOfLen);
				memcpy( &m_SDATermData[msgindex], &m_TagAddress[i].Address[ucLenOfLen], len);
				msgindex += len;
			}
		}

	}while(index < iSTLLen);

	*iStaticTagListLen = msgindex;

	return TRUE;

}

BYTE CEMV::ExtractFromChip( void )
{
	// Virtual Function
	return PROCESS_OK;
}


// Read Application Data from the card
BYTE CEMV::ReadAppData( void )
{
	int		AFLLen, OffLineCnt, iReadDataLen, iReadIndex, iSADIndex, iAFLIndex, len, iRet;
	BYTE	*ucAFL, ucSFI, ucRealSFI, ucFirstRecNo, ucLastRecNo, ucRecordNo;
	BYTE    ucExpDate[3], ucLenOfLen;
	BYTE    ucEffDate[3], ucRet;
   

	len = GetLenOfDataEl(m_EMVCardTags.t94, &ucLenOfLen);
	iAFLIndex = ucLenOfLen;
	m_StaticAppDataLen = 0;
	AFLLen = len;
	if (AFLLen < 4)
		return AFL_LEN_OUT_OF_RANGE;

	while (iAFLIndex < AFLLen)
	{
		ucAFL = &(m_EMVCardTags.t94[iAFLIndex]);
		iAFLIndex += 4;

		ucSFI 		= ucAFL[0];	 // The short File Identifier of the file to be read
		ucFirstRecNo	= ucAFL[1];	 // The first record to be read
		ucLastRecNo  	= ucAFL[2];	 // The last record to be read
		OffLineCnt 	= ucAFL[3];   // The count of the data to be read for offline static data list

// The range of SFI: 0..31
// WARNING : It is supposed that there is not any restriction on the range of SFI in
// EUROPAY M-Chip Lite application

		if (ucSFI>>3 == 0)
			return SFI_OUT_OF_RANGE;

		if ((ucSFI>>3) > 30)
			return SFI_OUT_OF_RANGE;


// The first record number can't be 0
		if (ucFirstRecNo == 0)
			return AFL_INCORRECT;

		if (ucFirstRecNo > ucLastRecNo)
			return AFL_INCORRECT;

		if (OffLineCnt > ucLastRecNo-ucFirstRecNo+1)
			return AFL_INCORRECT;

		for (ucRecordNo=ucFirstRecNo;ucRecordNo<=ucLastRecNo;ucRecordNo++)
		{
			iReadIndex=0;
			ucRet = READ_RECORD(ucSFI, ucRecordNo);
			if (ucRet != PROCESS_OK)
				return ucRet;

// The format of the returned message SW1|SW2|70|length|Record Template
			if( (m_SW1 != 0x90) || (m_SW2 != 0x0) ) 
			{
				return CARD_REJECTED;
			}	
			
			while( (m_Apdu.read_data[iReadIndex] == 0) || (m_Apdu.read_data[iReadIndex] == 0xFF) )
            	iReadIndex++;

			if( m_Apdu.read_data[iReadIndex] != 0x70 && ucSFI<=31 )
				return DATA_FORMAT_INCORRECT;

			iReadIndex +=1;
			if( (m_Apdu.read_data[iReadIndex]&0x80) == 0x80 )
			{
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
				ucLenOfLen = m_Apdu.read_data[iReadIndex]&0x7F;
				iReadDataLen = Bin2Lng( &m_Apdu.read_data[iReadIndex+1], ucLenOfLen);
				iReadIndex += ucLenOfLen+1;
			}
			else
			{
// The length of the length field of the data element is coded as one byte
				iReadDataLen = m_Apdu.read_data[iReadIndex];	// The len of the data read
				iReadIndex++;
			}

// Parse data and add to the EMVTags structure
			ucRet = AddToEmvTAGS( &m_Apdu.read_data[iReadIndex], iReadDataLen, CARD);
// In the case of formaty error return FALSE
			if (ucRet != PROCESS_OK)
			{
// The proprietary data elements doesn't have to be in TLV format
				if (ucSFI <= 31)
					return ucRet;
            }
            len = GetLenOfDataEl(m_EMVCardTags.t8E, &ucLenOfLen);
            if ((len>0)&&(len<=8))
            {
	            return DATA_FORMAT_INCORRECT;
            }
// If there is any Static Application Related Data add it to a global string(ucStaticAppData)
			if (OffLineCnt != 0)
			{
				OffLineCnt--;
				iSADIndex = m_StaticAppDataLen;
// Real SFI is the most significant 5 bits
				ucRealSFI = ucSFI>>3;
// The SFI Range for EMV
				if( (ucRealSFI >= 1) && (ucRealSFI<=10) )
				{
					memcpy( &m_StaticAppData[iSADIndex], &m_Apdu.read_data[iReadIndex], iReadDataLen );
					m_StaticAppDataLen += iReadDataLen;
				}
// The SFI Range for proprietary applications
				else if ((ucRealSFI >= 11)&&(ucRealSFI<=30))
				{
		          if( m_Apdu.read_data[0] == 0x70 ) //EVAL1.6 Script 2CJ018/SDA_proprietary_not_TLV
   			       {

						memcpy( &m_StaticAppData[iSADIndex], &m_Apdu.read_data[0], m_Apdu.read_len-2);
						m_StaticAppDataLen += m_Apdu.read_len-2;
					}	
				}
			}
		}
	}

// Check if all of the mandatory data objects received
	for (iRet=0;iRet<sizeof(m_TagAddress)/sizeof(TAG_ADDRESS);iRet++)
	{
		if ((m_TagAddress[iRet].Requirement == 'M')&&(GetLenOfDataEl(m_TagAddress[iRet].Address, &ucLenOfLen) == 0))
		{
			return MISSING_MANDATORY_OBJECT;
		}
	}

// Check if Application Expiration Date is out of range
	memcpy(ucExpDate, &m_EMVCardTags.t5F24[1], 3);
	if (ucExpDate[1] > 0x12)
		return EXP_DATE_INCORRECT;
	if (ucExpDate[2] > 0x31)
		return EXP_DATE_INCORRECT;

// Check if Application Effective Date is out of range
	memcpy(ucEffDate, &m_EMVCardTags.t5F25[1], 3);
	if (ucEffDate[1] > 0x12)
		return EFF_DATE_INCORRECT;
	if (ucEffDate[2] > 0x31)
		return EFF_DATE_INCORRECT;

	return PROCESS_OK;
}


// During Initiate Application Processing, the terminal signals to the card that
// transaction processing is beginning. The terminal accomplishes this by
// sending the GET PROCESSING OPTIONS command to the card. When
// issuing this command, the terminal supplies the card with any data elements
// requested by the card in a Processing Options Data Objects List (PDOL). The
// PDOL (a list of tags and lengths of data elements) is optionally provided by
// the card to the terminal during Application Selection.
// The card responds to the GET PROCESSING OPTIONS command with the
// Application File Locator (AFL), a list of files and records, which the terminal
// needs to read from the card. The card also provides the Application
// Interchange Profile (AIP), a list of functions to be performed in processing
// the transaction.
BYTE CEMV::InitiateApplicationProcessing( void )
{
	BYTE 	ucPDOLData[MAX_DOL_LEN];
	BYTE  	ucRet;
	BYTE	*pucPDOL, ucPDOLDataLen=0;
	int		len, iMsgIndex=0;
	int		iPDOLLen;
	BYTE 	ucLenOfLen;

#ifdef PRE_AUTHORIZED_MAESTRO
	WORD 	TermAidLen;
	BYTE 	ucDataValue[20];
	BYTE 	dummy[100];
#endif

    WriteLogFile("InitiateApplicationProcessing","Start function");

	
	// Increment transaction sequence counter
	IncTCC();

start:
	memset(m_IssScriptMsg, 0, MAX_ISS_SCRIPT_LEN*MAX_ISS_SCRIPT_CNT);

// 9F37(Unpredictable Number), 9A(Transaction Date) are filled
	FillDynamicTags();
// Get Transaction Type
	m_EMVTermTags.t9C[0] = 1;
	m_EMVTermTags.t9C[1] = m_TransactionType;

#ifdef PRE_AUTHORIZED_MAESTRO

	TermAidLen=0;

	GetDataElement(TAG_AppIdentIcc, ucDataValue, &TermAidLen);

	if (TermAidLen)
	{
		Bcd2Str(ucDataValue, TermAidLen, 0, (char*)dummy);
	}
	else 
	{
		GetDataElement(TAG_DFName, ucDataValue, &TermAidLen);
		Bcd2Str(ucDataValue, TermAidLen, 0, (char*)dummy);
	}	

	m_PreAuthorized = FALSE;
	m_OfflineBalance = 0;


	if (memcmp(dummy,"A0000000043060", TermAidLen) == 0) // pre-authorized maestro aid
	{
		ucRet = GET_DATA( GET_OFFLINE_BALANCE );
		if( ucRet != PROCESS_OK ) return ucRet;
			
		if(m_SW1==0x90 && m_SW2==0x00)
		{
			sprintf( (char*)dummy, "%s", m_Apdu.read_data+3);
			dummy[6] = '\0';

			Bcd2Str( m_Apdu.read_data+3, 6, 0 , (char*)dummy);

			m_OfflineBalance = atol( (const char*)dummy );
			m_PreAuthorized = TRUE;

			CString tmp;
			tmp.Format("OFFLINE BALLANCE: %d", m_OfflineBalance);
			DisplayMessage( 3, tmp, FALSE );
		}
		else
		{
			//return CARD_REJECTED;
		}
		
	}

	

#endif


	ucRet=GetTransAmount();
	if (ucRet != PROCESS_OK)
	    return ucRet;


// Init TVR and TSI
	m_EMVTermTags.t95[0] = 5;
	m_EMVTermTags.t9B[0] = 2;

// Init Authorization response code
	m_EMVTermTags.t8A[0] = 2;

// Prepare PDOL Data. It will be sent to the card in the GET_PROCESSING_OPTIONS command
	len = GetLenOfDataEl(m_EMVCardTags.t9F38, &ucLenOfLen);
	pucPDOL = &m_EMVCardTags.t9F38[ucLenOfLen];
	iPDOLLen = len;

//  PDOL Data Template : 0x83
	ucPDOLData[0] = 0x83;
	if (iPDOLLen == 0)	
		ucPDOLData[1] = 0x0;
	else
	{
		PrepDOLData(iPDOLLen, pucPDOL, ucPDOLData+2, &ucPDOLDataLen, DOL_PDOL);
		ucPDOLData[1] = ucPDOLDataLen;
	}
	ucPDOLDataLen += 2;

// Get AIP(82) and AFL(94)	from the card
	ucRet = GET_PROCESSING_OPTIONS(ucPDOLData, ucPDOLDataLen);
	if (ucRet != PROCESS_OK)
		return ucRet;
	//BONUS
	if( m_Apdu.read_data[ m_Apdu.read_len-2 ]==0x61 ) 
	{
		ucRet = GET_RESPONSE( m_Apdu.read_data[ m_Apdu.read_len-1 ] );	
		if (ucRet != PROCESS_OK)
			return ucRet;
	}

// Condition of use not satisfied. The application should be removed from the candidate list.
	if( (m_SW1 == 0x69) && (m_SW2 == 0x85) )
	{
		DisplayMessage(1, "NOT ACCEPTED", TRUE);
		MessageBeep( MB_ICONEXCLAMATION );

		m_CandList[m_SelectedAppIndex].Deleted = TRUE;
		ucRet = SelectMatchingApp(APP_SELECT_LIST_OF_AID);
		
		if (ucRet != PROCESS_OK)
			return ucRet;
		goto start;
	}

	if( (m_SW1 != 0x90) || (m_SW2 != 0x0) ) 
	{
		return CARD_REJECTED;
	}

    while( (m_Apdu.read_data[iMsgIndex] == 0) || (m_Apdu.read_data[iMsgIndex] == 0xFF) )
       	iMsgIndex++;

// The response is in the Format1
	if( m_Apdu.read_data[iMsgIndex] == 0x80 )
	{
		iMsgIndex++;
		if( (m_Apdu.read_data[iMsgIndex]&0x80) == 0x80 )
		{
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
			ucLenOfLen = m_Apdu.read_data[iMsgIndex]&0x7F;
			len = Bin2Lng( &m_Apdu.read_data[iMsgIndex+1], ucLenOfLen);
			iMsgIndex += ucLenOfLen+1;
		}
		else
		{
// The length of the length field of the data element is coded as one byte
			ucLenOfLen = 1;
			len = m_Apdu.read_data[iMsgIndex++];
		}
// The len of the returned data (AIP+AFL)
		if (len != m_Apdu.read_len-3-ucLenOfLen)
			return LEN_INCORRECT;

// Move AIP to the global structure
		m_EMVCardTags.t82[0] = 2;
		memcpy(&m_EMVCardTags.t82[1], m_Apdu.read_data+iMsgIndex, m_EMVCardTags.t82[0]);
		iMsgIndex += m_EMVCardTags.t82[0];

		
// Move AFL to the global structure
		m_EMVCardTags.t94[0] = len-2;
		memcpy(&m_EMVCardTags.t94[1], m_Apdu.read_data+iMsgIndex, m_EMVCardTags.t94[0]);
		iMsgIndex += m_EMVCardTags.t94[0];
	}
// The response is in the Format2 (BER-TLV data format)   SW1 SW2 77 len (TLV)
	else if( m_Apdu.read_data[iMsgIndex] == 0x77 )
	{
// Find len
		iMsgIndex++;
		if((m_Apdu.read_data[iMsgIndex]&0x80) == 0x80 )
		{
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
			ucLenOfLen = m_Apdu.read_data[iMsgIndex]&0x7F;
			len = Bin2Lng( &m_Apdu.read_data[iMsgIndex+1], ucLenOfLen);
			iMsgIndex += ucLenOfLen+1;
		}
		else
		{
// The length of the length field of the data element is coded as one byte
			len = m_Apdu.read_data[iMsgIndex++];
		}

		ucRet = AddToEmvTAGS( &m_Apdu.read_data[iMsgIndex], len, CARD );
		
		if( ucRet != PROCESS_OK )
			return ucRet;
// AIP is a mandatory field
		if( m_EMVCardTags.t82[0] == 0 )
			return AIP_NOT_RECEIVED;
// AFL is a mandatory field
		if( m_EMVCardTags.t94[0] == 0 )
			return AFL_NOT_RECEIVED;
	}
	else
		return DATA_FORMAT_INCORRECT;

	return PROCESS_OK;
}


// Increase Transaction Sequence Counter
BOOL CEMV::IncTCC( void )
{
	BYTE		ucBcdTCC[4];
	CString		strTCC;
	int			iTCC;

// Get Transaction Sequence Counter
	m_EMVTermTags.t9F41[0] = 4;

	CVirtualPosFile sFile( TSC );

	if( !sFile.m_state )
		return FALSE;

	if( !sFile.Read( strTCC ) )
		return FALSE;

// In the case of file is empty write 0 to file
	if( sFile.m_Read_Len == 0)
	{
		strTCC = "0";
		sFile.Write( strTCC );
	}

	iTCC = atoi( (const char*)strTCC.GetBuffer() );
	if (iTCC == 99999999)
		iTCC = 0;

// Increase transaction sequence counter
	iTCC++;
	strTCC.Format( "%d", iTCC);

	if( !sFile.Write( strTCC ) )
		return FALSE;

	if( Str2Bcd( strTCC.GetBuffer(), strTCC.GetLength(), LEFT_PAD_ZERO, ucBcdTCC, 4, RIGHT_PAD) == NULL )
		return FALSE;

	memcpy(&m_EMVTermTags.t9F41[1], ucBcdTCC, 4);
	return TRUE;
}


// 9F37(Unpredictable Number), 9A(Transaction Date) tags are filled
int CEMV::FillDynamicTags( void )
{
	UCHAR		ucUN[4];
	int 		iUN,i;

	WriteLogFile("FillDynamicTags","Start function");

	// Terminal produces unpredictable number for DDA
	CTime t = CTime::GetCurrentTime();
	CString currDateTime = t.Format( "%S%M%H%W" );

	WriteLogFile("FillDynamicTags-unpredictable number",currDateTime);

	i = atoi( currDateTime.GetBuffer() );
	srand(i);
	iUN = rand()%100000000;
	Lng2Bcd(iUN, ucUN, 4);
	m_EMVTermTags.t9F37[0] = 4;
	memcpy(&m_EMVTermTags.t9F37[1], ucUN, m_EMVTermTags.t9F37[0]);

// Fill Transaction Date
	m_EMVTermTags.t9A[0] = 3;

	Lng2Bcd( t.GetYear() - 2000, &m_EMVTermTags.t9A[1], 1);
	Lng2Bcd( t.GetMonth() , &m_EMVTermTags.t9A[2], 1);
	Lng2Bcd( t.GetDay() , &m_EMVTermTags.t9A[3], 1);

// Fill Transaction Time
	m_EMVTermTags.t9F21[0] = 3;

	Lng2Bcd( t.GetHour() , &m_EMVTermTags.t9F21[1], 1);
	Lng2Bcd( t.GetMinute() , &m_EMVTermTags.t9F21[2], 1);
	Lng2Bcd( t.GetSecond() , &m_EMVTermTags.t9F21[3], 1);

	return TRUE;
}



// Get the value of the specific data element
BYTE CEMV::GetDataElement (WORD usTag, LPBYTE ucTagValue, PWORD ucLenTag)
{
	BYTE 	ucTag[2], Temp, ucLenOfLen;
	INT		TagCnt, i;
	WORD	len;

	WriteLogFile("GetDataElement","Start function");

	Short2Bin(usTag, ucTag);
// Reverse the bytes for the one-byte tags
	if ((ucTag[0] == 0)&&(ucTag[1] != 0))
	{
		Temp = ucTag[0];
		ucTag[0] = ucTag[1];
		ucTag[1] = Temp;
	}

	TagCnt = sizeof(m_TagAddress)/sizeof(TAG_ADDRESS);
	for (i=0;i<TagCnt;i++)
	{
// Check if the data element is present in the m_TagAddress table
		if ((m_TagAddress[i].Tag[0] == ucTag[0])&&((m_TagAddress[i].Tag[1] == ucTag[1])||(m_TagAddress[i].Tag[1] == 0x0)))
		{
			len = GetLenOfDataEl(m_TagAddress[i].Address, &ucLenOfLen);
			*ucLenTag = len;
			memcpy(ucTagValue, &m_TagAddress[i].Address[ucLenOfLen], len);
			break;
		}
	}
// Check if tag be found in table
	if (i==TagCnt)
	{
		WriteLogFile("GetDataElement","TAG_NOT_FOUND");
		return TAG_NOT_FOUND;
	}

	return ACCESS_OK;
}




BYTE CEMV::GetTransAmount( void )
{
	BYTE	ucAuthAmount[4],ucRet,ucBcdAmount[6],TmpStr[4];
	ULONG	stAmount;
	char    Amount[1024];
	
	memset(ucAuthAmount, 0, 4);

	// Get Transaction Amount
	ucRet = InputAmount( stAmount );

	if (ucRet != PROCESS_OK) 
	{
		return GET_AMOUNT_ABORT;
	}
	sprintf( Amount, "%d", stAmount );
	
	if (Str2Bcd(Amount, (WORD)strlen(Amount), LEFT_PAD_ZERO, ucBcdAmount, 6, RIGHT_PAD) == NULL)  
	{
        return GET_AMOUNT_ERROR;
    }    
    
    memset(TmpStr,0,4);
    memcpy(TmpStr,&stAmount,4);
    ucAuthAmount[0]=TmpStr[3];
    ucAuthAmount[1]=TmpStr[2];
    ucAuthAmount[2]=TmpStr[1];
    ucAuthAmount[3]=TmpStr[0];

// Set authorization amount (9F03)
	m_EMVTermTags.t9F02[0] = 6;
	memcpy(&m_EMVTermTags.t9F02[1], ucBcdAmount, 6);

// Set other amount (9F03)
//	m_EMVTermTags.t9F03[0] = 6;
//	Lng2Bcd(ulOtherAmount, &ucTSC2, &m_EMVTermTags.t9F03[1], 6);

// Set binary amount
	m_EMVTermTags.t81[0] = 4;
	memcpy(&m_EMVTermTags.t81[1], ucAuthAmount, 4);
	return (PROCESS_OK);
}


// Prepare DOL related data according to the DOL taken from the card
void CEMV::PrepDOLData(int iDOL, LPBYTE pucDOL, LPBYTE pucDOLData, LPBYTE ucDOLDataLen, BYTE ucDOLType)
{
	int 	i,TagCnt,index=0;
	BYTE	len1, len, ch;
	BYTE	ucTCHash[20], ucLenOfLen, brand;

	*ucDOLDataLen = 0;
	TagCnt = sizeof(m_TagAddress)/sizeof(TAG_ADDRESS);
	while (index < iDOL)
	{
		for (i=0;i<TagCnt;i++)
		{
			if ((m_TagAddress[i].Tag[0] == pucDOL[index])&&((m_TagAddress[i].Tag[1] == pucDOL[index+1])||(m_TagAddress[i].Tag[1] == 0x0)))
			{
				if (m_TagAddress[i].Tag[1] == 0x0)
				{
					index++;
				}
				else
				{
					index += 2; // index length'e konumlandý
                }
				len = pucDOL[index++];
// For GENERATE_AC(CDOL1 or CDOL2) calculate TC Hash Value
				if (m_TagAddress[i].Tag[0] == 0x98)
				{
					CalculateTCHash(ucTCHash);
					if (len == 20)
					{
						memcpy(&pucDOLData[*ucDOLDataLen], ucTCHash, len);
						*ucDOLDataLen += len;
						break;
					}
					else if (len > 20)
					{
						memset(&pucDOLData[*ucDOLDataLen], 0, len-20);
						*ucDOLDataLen+=len-20;
						memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[1], 20);
						*ucDOLDataLen += 20;
						break;
					}
				}
// Check if the searched data element is belong to card.
// The term tags first in the table
// In this case fill zeroes if DOL is PDOL as stated in EVAL CJ005 script
// THIS BLOCK IS COMMENTED AT THE SCRIPT 2CA017(short_other_pdol)
// Kapattýðýmýz zaman da 2CA099'da fail ediyor.
				if ((m_TagAddress[i].ucSource == 'C')&&(ucDOLType == DOL_PDOL))
				{
					memset(&pucDOLData[*ucDOLDataLen], 0, len);
					*ucDOLDataLen += len;
					break;
				}

				len1 = GetLenOfDataEl(m_TagAddress[i].Address, &ucLenOfLen);
				if (len1 == 0)
				{
					memset(&pucDOLData[*ucDOLDataLen], 0, len);
					*ucDOLDataLen += len;
					break;
				}
				else
				{
// Check if the length stated in DOL is lower than the actual length
					if (len < len1)
					{
// Truncate leftmost bytes
						brand = GetCardBrand();
						if (brand == BRAND_VISA)
						{
							if (ucDOLType==DOL_CDOL2 && m_TagAddress[i].Tag[0]==0x91) {
									// !ZO EMV patch 07/03/2006: Dubai + Bosna CCD card
								memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len);
								*ucDOLDataLen += len;
							}
							else if ((m_TagAddress[i].ucFormat == NUM)||(m_TagAddress[i].ucFormat == CNU)||(m_TagAddress[i].ucFormat == BIN))
							{
								memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen+m_TagAddress[i].Address[0]-len], len);
								*ucDOLDataLen += len;
								break;
							}
// Truncate rightmost bytes
							else
							{
								memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len);
								*ucDOLDataLen += len;
								break;
							}
						}
						else if ((brand == BRAND_EUROPAY)||(brand == BRAND_MASTER))
						{
// Truncate leftmost bytes
							if (m_TagAddress[i].ucFormat == NUM)
							{
								memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen+m_TagAddress[i].Address[0]-len], len);
								*ucDOLDataLen += len;
								break;
							}
// Truncate rightmost bytes
							else
							{
								memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len);
								*ucDOLDataLen += len;
								break;
							}
						}
					}
// Check if the length stated in DOL is greater than the actual length
					else if (len > len1)
					{
						if (m_TagAddress[i].ucFormat == NUM)
						{
// Pad leading hexadecimal zeroes
							memset(&pucDOLData[*ucDOLDataLen], 0, len-m_TagAddress[i].Address[0]);
							*ucDOLDataLen+=len-m_TagAddress[i].Address[0];
							memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len1);
							*ucDOLDataLen += len1;
							break;
						}
// Pad trailing hexadecimal FFs
						else if (m_TagAddress[i].ucFormat == CNU)
						{
// Pad leading hexadecimal zeroes
							memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len1);
							*ucDOLDataLen += len1;
							memset(&pucDOLData[*ucDOLDataLen], 0xFF, len-m_TagAddress[i].Address[0]);
							*ucDOLDataLen+=len-m_TagAddress[i].Address[0];
							break;
						}
// Pad trailing hexadecimal zeroes
						else
						{
							memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len1);
							*ucDOLDataLen += m_TagAddress[i].Address[0];
							memset(&pucDOLData[*ucDOLDataLen], 0x0, len-len1);
							*ucDOLDataLen+=len-len1;
							break;
						}
					}
// Check if the length stated in DOL is equal to the actual length
					else
					{
						memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[1], len);
						*ucDOLDataLen += len;
						break;
					}
				}
			}
		}
		if (i==TagCnt) // Tag tabloda bulunamadý
		{
			ch = pucDOL[index]&0x1F;
			if (ch == 0x1F)
			{
				index++;
				while ((pucDOL[index]&0xF0) == 0xF0)
				{
					index++;
				};
			}
			index++;
            if (index < iDOL)
            {
 	           len = GetLenOfDataEl(&pucDOL[index], &ucLenOfLen);
               index += ucLenOfLen;
// If tag not found, fill by zeroes
               memset(&pucDOLData[*ucDOLDataLen], 0, len);
               *ucDOLDataLen+=len;
            }
            else
            {
    	        memset(&pucDOLData[*ucDOLDataLen], 0, 1);
        	    *ucDOLDataLen+=1;
            }
		}
	}

}


// Calculates Transaction Certificate using TDOL (taken from the card or default) which may be
// requested by the card in GENERATE_AC command
void CEMV::CalculateTCHash(LPBYTE ucTCHash)
{
	LPBYTE	ucTDOL;
	LPBYTE	ucTVR = &m_EMVTermTags.t95[1];
	BYTE	ucValue=0, ucLenOfLen=0, ucTDOLDataLen=0;
	INT		iTDOLLen;
	int		iByteNo, len;


	len = GetLenOfDataEl(m_EMVCardTags.t97, &ucLenOfLen);
	iTDOLLen = len;
	ucTDOL = &m_EMVCardTags.t97[ucLenOfLen];
// If there is no TDOL received from the card, use the Default TDOL on terminal
	if (iTDOLLen == 0)
	{
		len = GetLenOfDataEl(m_EMVTermTags.tDF98, &ucLenOfLen);
		iTDOLLen = len;
		ucTDOL = &m_EMVTermTags.tDF98[ucLenOfLen];
		if (iTDOLLen != 0)
		{
			GetByteNoAndValue(TVR_DEFAULT_TDOL_USED, &ucValue, &iByteNo);
			ucTVR[iByteNo] = ucTVR[iByteNo]|ucValue;
		}
	}

	PrepTDOLData(iTDOLLen, ucTDOL, m_ApplBuffer, &ucTDOLDataLen);
	compute_hash_str(m_ApplBuffer, ucTDOLDataLen, ucTCHash);
}

// Prepare DOL related data according to the DOL taken from the card
void CEMV::PrepTDOLData(int iDOL, LPBYTE pucDOL, LPBYTE pucDOLData, LPBYTE ucDOLDataLen)
{
	int 	i,TagCnt,index=0;
	BYTE	len1, len;
	BYTE	ucLenOfLen;

	*ucDOLDataLen = 0;
	TagCnt = sizeof(m_TagAddress)/sizeof(TAG_ADDRESS);
	while (index < iDOL)
	{
		for (i=0;i<TagCnt;i++)
		{
			if ((m_TagAddress[i].Tag[0] == pucDOL[index])&&((m_TagAddress[i].Tag[1] == pucDOL[index+1])||(m_TagAddress[i].Tag[1] == 0x0)))
			{
				if (m_TagAddress[i].Tag[1] == 0x0)
				{
					index++;
				}
				else
				{
					index += 2; // index length'e konumlandý
                }
				len = pucDOL[index++];

// For GENERATE_AC(CDOL1 or CDOL2) calculate TC Hash Value
				len1 = GetLenOfDataEl(m_TagAddress[i].Address, &ucLenOfLen);
				if (len1 == 0)
				{
					memset(&pucDOLData[*ucDOLDataLen], 0, len);
					*ucDOLDataLen += len;
					break;
				}
				else
				{
// Check if the length stated in DOL is lower than the actual length
					if (len < len1)
					{
// Truncate leftmost bytes
						if ((m_TagAddress[i].ucFormat == NUM)||(m_TagAddress[i].ucFormat == CNU)||(m_TagAddress[i].ucFormat == BIN))
						{
							memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen+m_TagAddress[i].Address[0]-len], len);
							*ucDOLDataLen += len;
							break;
						}
// Truncate rightmost bytes
						else
						{
							memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len);
							*ucDOLDataLen += len;
							break;
						}
					}
// Check if the length stated in DOL is greater than the actual length
					else if (len > len1)
					{
						if ((m_TagAddress[i].ucFormat == NUM)||(m_TagAddress[i].ucFormat == BIN))
						{
// Pad leading hexadecimal zeroes
							memset(&pucDOLData[*ucDOLDataLen], 0, len-m_TagAddress[i].Address[0]);
							*ucDOLDataLen+=len-m_TagAddress[i].Address[0];
							memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len1);
							*ucDOLDataLen += len1;
							break;
						}
// Pad trailing hexadecimal FFs
						else if (m_TagAddress[i].ucFormat == CNU)
						{
							memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len1);
							*ucDOLDataLen += len1;
							memset(&pucDOLData[*ucDOLDataLen], 0xFF, len-len1);
							*ucDOLDataLen+=len-len1;
							break;
						}
// Pad trailing hexadecimal zeroes
						else
						{
							memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[ucLenOfLen], len1);
							*ucDOLDataLen += m_TagAddress[i].Address[0];
							memset(&pucDOLData[*ucDOLDataLen], 0x0, len-len1);
							*ucDOLDataLen+=len-len1;
							break;
						}
					}
// Check if the length stated in DOL is equal to the actual length
					else
					{
						memcpy(&pucDOLData[*ucDOLDataLen], &m_TagAddress[i].Address[1], len);
						*ucDOLDataLen += len;
						break;
					}
				}
			}
		}
		if (i==TagCnt) // Tag tabloda bulunamadý
		{
			if ((pucDOL[index] == 0x9F)||(pucDOL[index] == 0x5F))
				index += 2;
			else
				index++;

			len = 	pucDOL[index++];
// If tag not found, fill by zeroes
			memset(&pucDOLData[*ucDOLDataLen], 0, len);
			*ucDOLDataLen+=len;
		}
	}

}


BYTE CEMV::GetCardBrand( void )
{
	char	ucCardBrand[32];

    Bcd2Str(&m_EMVCardTags.t84[5], 3, NO_PAD_ZERO, ucCardBrand);

    if (strcmp(ucCardBrand, "031010") == 0)
		return BRAND_VISA;
	else if (strcmp(ucCardBrand, "041010") == 0)
		return BRAND_MASTER;
	else if (strcmp(ucCardBrand, "043060") == 0)
		return BRAND_EUROPAY;
	else
		return 0;
}

void CEMV::GetByteNoAndValue(int iDefineValue, LPBYTE ucValue, int *iByteNo)
{
	*iByteNo = iDefineValue/0x100;
	*ucValue  = iDefineValue - (*iByteNo)*0x100;
}


// Application Selection is the process of determining which of the applications
// that are supported by both the card and terminal will be used to conduct the
// transaction. This process takes place in two steps:
// 1. The terminal builds a candidate list of mutually supported applications.
// 2. A single application from this list is identified and selected to process the
// transaction.
BYTE CEMV::ApplicationSelection(LPBYTE ucAppListBuf, INT iAppCnt, LPBYTE ucSelectedApp)
{
	BYTE	ucAppList[MAX_TERMINAL_APP_CNT][APP_INF_LEN];
	BYTE	ucRet;
	INT 	index = 0, i, iRealAppCnt;
 	INT 	iMatchAppCnt;
    

	WriteLogFile( "ApplicationSelection","Start Function" );

	
	memset(ucAppList, 0, APP_INF_LEN*MAX_TERMINAL_APP_CNT);
	iRealAppCnt = 0;

    for (i=0;i<iAppCnt;i++)
    {
    	// Check Terminal Application List
    	if( (ucAppListBuf[index] < MIN_APP_LEN) || (ucAppListBuf[index] > MAX_APP_LEN) )
    	{
			// if not valid AID, check next
    	   	index+=APP_INF_LEN;
    	}
    	else
    	{
			// if valid AID, add  to EMV library list
    	   	memcpy(ucAppList[iRealAppCnt++], &ucAppListBuf[index], APP_INF_LEN);
    	   	index+=APP_INF_LEN;
    	}
    }

	// if Terminal does not have AID list, terminate transaction and return error
	if (iRealAppCnt == 0) return NO_TERM_APP;

	// Set application priority indicator to zero
	for (i=0;i<MAX_MATCHING_APP_CNT;i++)
    {
        m_CandList[i].l87 = 0;
    }

	// Send a message to display
	DisplayMessage( 2,"PLEASE WAIT", TRUE);
	DisplayMessage( 3,"RECOGNIZING CARD", FALSE);
	
// Find the matching applications between card and terminal
// Try first the PSE method
	ucRet = PrepCandListPSE(ucAppList, iAppCnt, &iMatchAppCnt);

	if (ucRet == PSE_NOT_SUPPORTED_BY_CARD) 	
	{
// if PSE method is unsuccessful, try directory selection method

		ucRet = PrepCandList(ucAppList, iAppCnt, &iMatchAppCnt);

		if (ucRet != PROCESS_OK) 
		{
			return ucRet;
		}	
		WriteLogFile( "AppSelect","APP_SELECT_LIST_OF_AID" );
		ucRet = SelectMatchingApp(APP_SELECT_LIST_OF_AID);
		if (ucRet != PROCESS_OK)
			return ucRet;

		if (m_EMVCardTags.t4F[0] == 0)
		{
			ucSelectedApp[0] = (UCHAR)m_CandList[m_SelectedAppIndex].l84;
			memcpy(&ucSelectedApp[1], m_CandList[m_SelectedAppIndex].p84, m_CandList[m_SelectedAppIndex].l84);
			return PROCESS_OK;
		}
		else
		{
			ucSelectedApp[0] = (UCHAR)m_CandList[m_SelectedAppIndex].l4F;
			memcpy(&ucSelectedApp[1], m_CandList[m_SelectedAppIndex].p4F, m_CandList[m_SelectedAppIndex].l4F);
			return PROCESS_OK;
		}

	}
   	else if (ucRet != PROCESS_OK) 
	{
		return ucRet;
    }	

	ucRet = SelectMatchingApp(APP_SELECT_PSE);
	if (ucRet != PROCESS_OK)
		return ucRet;


	if (m_EMVCardTags.t4F[0] == 0)
	{
		ucSelectedApp[0] = (UCHAR)m_CandList[m_SelectedAppIndex].l84;
		memcpy(&ucSelectedApp[1], m_CandList[m_SelectedAppIndex].p84, m_CandList[m_SelectedAppIndex].l84);
		return PROCESS_OK;
	}
	else
	{
		ucSelectedApp[0] = (UCHAR)m_CandList[m_SelectedAppIndex].l4F;
		memcpy(&ucSelectedApp[1], m_CandList[m_SelectedAppIndex].p4F, m_CandList[m_SelectedAppIndex].l4F);
		return PROCESS_OK;
	}
}


// Send SELECT command for one of the applications in the candidate list
BYTE CEMV::SelectMatchingApp(BYTE ucSelectType)
{
	BYTE	MultOccur=FALSE;
	BYTE 	ucRet;

	WriteLogFile( "SelectMatchingApp","Start Function" );



start:
	memset(&m_EMVCardTags, 0, sizeof(EMV_CARD_TAGS));

	ucRet = SelectFromCandList(ucSelectType);

	if (ucRet != PROCESS_OK)
		return ucRet;

	WriteLogFile( "SelectMatchingApp","After SelectFromCandList" );

	MultOccur=FALSE;
	if (ucSelectType == APP_SELECT_PSE) 
	{
		ucRet = SELECT( m_CandList[m_SelectedAppIndex].p4F, m_CandList[m_SelectedAppIndex].l4F, MultOccur, SELECT_ADF );
	}	
	else 
	{
		ucRet = SELECT( m_CandList[m_SelectedAppIndex].p84, m_CandList[m_SelectedAppIndex].l84, MultOccur, SELECT_ADF );
	}
	if (ucRet != PROCESS_OK)
		return ucRet;


// Card blocked. Terminate session
	if( (m_SW1 == 0x6A)&&(m_SW2 == 0x81) )
	{
        m_CandList[m_SelectedAppIndex].Deleted = TRUE;
        //		return PROCESS_OK;  // Look at the EVAL script 2CJ008
        goto start;
//According to EVAL perform no other action
	}
// Application blocked. Continue with the next application id in terminal list
	else if( (m_SW1 == 0x62) && (m_SW2 == 0x83) )
	{
        m_CandList[m_SelectedAppIndex].Deleted = TRUE;
        goto start;
//		return FALSE;
	}
	else if( (m_SW1 == 0x90)&&(m_SW2 == 0x0) )
    {
        memcpy( &m_EMVTermTags.t9F06[1], m_CandList[m_SelectedAppIndex].p9F06, m_CandList[m_SelectedAppIndex].l9F06 );
        m_EMVTermTags.t9F06[0] = m_CandList[m_SelectedAppIndex].l9F06;
        return PROCESS_OK;
	}
	else
	{
		m_CandList[m_SelectedAppIndex].Deleted = TRUE;
		goto start;
	}
	return PROCESS_OK;
}


// Selects one of the applications in the candidate list
BYTE CEMV::SelectFromCandList(BYTE ucSelectType)
{
	CHIPMENU  Menu[MAX_MATCHING_APP_CNT];
	char 	Msg[MAX_MATCHING_APP_CNT][40];
	BYTE 	*ucAddTermCap = &m_EMVTermTags.t9F40[1];
	BYTE 	ucPriority[MAX_MATCHING_APP_CNT];
	BYTE 	ucIssCodeMask =1, ucDispPrefName = FALSE, ucDispLabel = FALSE;
	BYTE 	ucItemPresent = FALSE;
	UINT 	iMin;
	int 	i,j,iCandIndex=0;
	int 	iMatchAppCnt=0, MenuIndex=0;
//	int 	iMaxPriority=0x100;
	int 	iMinPriority=-1;


	WriteLogFile( "SelectFromCandList","Start Function" );



	memset(Menu, 0, sizeof(CHIPMENU)*MAX_MATCHING_APP_CNT);
	do
	{
		ucItemPresent = FALSE;
		iMin = 0x100;
		for (i=0;i<MAX_MATCHING_APP_CNT;i++)
		{

// If application is deleted from the candidate list then continue with the next application
			if( m_CandList[i].Deleted == TRUE )
			{
				WriteLogFile("SelectFromCandList",i,"Deleted");
				continue;
			}
			if( ucSelectType == APP_SELECT_PSE )
			{
// There is not a matching application. Look at the next index
				if( m_CandList[i].l4F == 0 )
					continue;
			}
			else
			{
// There is not a matching application. Look at the next index
				if( m_CandList[i].l84 == 0 )
					continue;
			}
			if( m_CandList[i].l87 == 0 )
			{
				ucItemPresent = TRUE;
				iCandIndex = i;
				m_CandList[i].l87=1;
				break;
			}
			
			if( m_CandList[i].p87 > iMinPriority )
			{
				if( m_CandList[i].p87 <= iMin )
				{
					ucItemPresent = TRUE;
					iMin = (BYTE)m_CandList[i].p87;
					iCandIndex = i;
				}
			}
		}
		if( ucItemPresent == TRUE )
		{
			ucPriority[iMatchAppCnt++] = iCandIndex;
			for( i=0; i<MAX_MATCHING_APP_CNT; i++ )
			{
				if( ucSelectType == APP_SELECT_PSE )
				{
					if( m_CandList[i].l4F != 0 )
						if( ((BYTE)iMin == m_CandList[i].p87)&&(iCandIndex != i)&&(m_CandList[i].Deleted == FALSE) )
							ucPriority[iMatchAppCnt++] = i;
				}
				else
				{
					if (m_CandList[i].l84 != 0)
						if (((BYTE)iMin == m_CandList[i].p87)&&(iCandIndex != i)&&(m_CandList[i].Deleted == FALSE))
							ucPriority[iMatchAppCnt++] = i;
				}
			}
		}
		iMinPriority = iMin;
	}while (iMin != 0x100);

	if (iMatchAppCnt == 0)
    {
		WriteLogFile( "SelectFromCandList","Application not found for Matching" );
        return NO_MATCHING_APP;
    }
	if ((iMatchAppCnt == 1)&&((m_CandList[0].p87&0x80) == 0x0))
	{
    	m_SelectedAppIndex = 0;
		return PROCESS_OK;
    }
	for (i=0;i<iMatchAppCnt;i++)
	{
		ucDispPrefName = FALSE;   // EVAL1.6
		ucDispLabel = FALSE;      // EVAL1.6

		iCandIndex = ucPriority[i];
// If Application Preffered Name and Issuer Code Table Index present in the SELECT response
// check if the terminal supports the character set. If it supports,  display the
// Application label in selection list.
		if (m_CandList[iCandIndex].l9F12 != 0)
		{
			if (m_CandList[iCandIndex].p9F11 != 0)
			{
				if (m_CandList[iCandIndex].p9F11<=8)
				{
					ucIssCodeMask = ucIssCodeMask << (m_CandList[iCandIndex].p9F11-1);
					if ((ucAddTermCap[4]&ucIssCodeMask) == ucIssCodeMask)
					{
						Menu[MenuIndex].ucVal = iCandIndex;
						Menu[MenuIndex++].pcText = m_CandList[iCandIndex].p9F12;
						ucDispPrefName = TRUE;
					}
				}
				else
				{
				
					ucIssCodeMask = ucIssCodeMask << (m_CandList[iCandIndex].p9F11-15);
					
					if ((ucAddTermCap[3]&ucIssCodeMask) == ucIssCodeMask)
					{
						Menu[MenuIndex].ucVal = iCandIndex;
						Menu[MenuIndex++].pcText = m_CandList[iCandIndex].p9F12;
						ucDispPrefName = TRUE;
					}
				}

			}
		}
// If application label is present print it
		if (m_CandList[iCandIndex].l50 != 0)
		{
// In the case of Application Preffered Name not displayed
			if (ucDispPrefName == FALSE)
			{
				ucDispLabel = TRUE;
				Menu[MenuIndex].ucVal = iCandIndex;
				Menu[MenuIndex++].pcText = m_CandList[iCandIndex].p50;
			}
		}
		if ((ucDispPrefName == FALSE)&&(ucDispLabel == FALSE))
		{
			if (ucSelectType == APP_SELECT_PSE)
			{
				for (j=0;j<m_CandList[iCandIndex].l4F;j++)
				{
					sprintf(&Msg[i][j*2], "%2.2X", m_CandList[iCandIndex].p4F[j]);
				}
			}
			else
			{
				for( j=0; j<m_CandList[iCandIndex].l84; j++ )
				{
					sprintf( &Msg[i][j*2], "%02X", m_CandList[iCandIndex].p84[j] );
				}
			}
			Menu[MenuIndex].ucVal = iCandIndex;
			Menu[MenuIndex++].pcText = Msg[i];
		}
	}

	m_SelectedAppIndex = DisplayAppMenu ( Menu, iMatchAppCnt);


	if( m_SelectedAppIndex == -1 )
    {
    	return NO_SELECTED_APP;
    }
	return PROCESS_OK;
}



// Directory Selection Method-Optional for cards and terminals, but if
// supported by the terminal, it is attempted first. In the Directory Selection
// Method, the terminal reads a directory (associated with the PSE(Payment System Environment)) 
// from the card. This directory is a list of the applications supported by the card. The
// terminal adds any applications listed both in the card list and in the
// terminal list on the candidate list.
BYTE CEMV::PrepCandListPSE(BYTE ucAppList[MAX_TERMINAL_APP_CNT][APP_INF_LEN], int iAppCnt, int *iMatchAppCnt)
{
	int		ucRecordNo=0, index=0;
	BYTE 	ucRet, ucSFI, dirOffset, ucStackRow, ucLenOfLen;
	BYTE	ucDDFName[16], ucDDFLen;
	BYTE	ucDirDiscTemplate[16], ucDDTLen;
	BYTE	ucLenOfDirEntry,ucDataLen=0;
	char	cDDFRead=FALSE;
	BYTE	PSEReadLast = FALSE, ucSFIOfPSE, ucRecOfPSE=0, ucFirstPSESelect=TRUE;
	STACK	stStack[5];
	BYTE	MultOccur=FALSE;


	WriteLogFile( "PrepCandListPSE","Start Function" );


	*iMatchAppCnt=0;

	memset( &stStack, 0, 5*sizeof(STACK) );
	memset( m_CandList, 0, sizeof(SELECT_RESPONSE)*MAX_MATCHING_APP_CNT );
	memset( &m_EMVCardTags, 0, sizeof(EMV_CARD_TAGS) );

	// The name of the PSE file is 1PAY.SYS.DDF01.
	ucDDFLen = 14;
	memcpy( ucDDFName, "1PAY.SYS.DDF01", ucDDFLen );

//*****************
// Start Select PSE
StartSelect:

	memset( &m_EMVCardTags, 0, sizeof(m_EMVCardTags) );
	ucRecordNo = 0;

	// The terminal selects the PSE, which is a special DDF, using the SELECT
	// command. The name of the PSE file is 1PAY.SYS.DDF01.
	ucRet = SELECT(ucDDFName, ucDDFLen, MultOccur, SELECT_PSE);

	if (ucRet != PROCESS_OK)
	{
            return ucRet;
	}
    
	if( ucFirstPSESelect == TRUE ) // look at v2CB022
	{
		if( (m_SW1 == 0x6A) && (m_SW2 == 0x82) )
			return PSE_NOT_SUPPORTED_BY_CARD;

		if( (m_SW1 != 0x90) || (m_SW2 != 0x00) )
			return PSE_NOT_SUPPORTED_BY_CARD;
	}

	// look at test 2CB022
	if( (m_SW1 != 0x90) || (m_SW2 != 0x00) )
    {
		memset(&m_EMVCardTags, 0, sizeof(m_EMVCardTags));
        ucRet = SELECT( (UCHAR *)"1PAY.SYS.DDF01", 14, 0, SELECT_PSE );
        if (ucRet != PROCESS_OK)
        {
			return ucRet;
        }

        ucRet = GetFromStack(stStack, &ucStackRow);

		// No data in stack
        if (ucRet == STACK_EMPTY)
        {
			if (memcmp(ucDDFName, "1PAY.SYS.DDF01", 14) == 0) PSEReadLast = TRUE;

			// Check if the last selected DDF is PSE
            if (PSEReadLast == TRUE) return PROCESS_OK;
            else
            {
				return PROCESS_OK;
            }
        }
        else
        {
				// In the case of the return code is different from 90 00 to the SELECT DDF, terminal
				// shall resume
                index = stStack[ucStackRow].ucIndex;
            	ucSFI = stStack[ucStackRow].ucSFI;
                ucRecordNo = stStack[ucStackRow].ucRecNo;
                m_Apdu.read_len = stStack[ucStackRow].ucDirEntriesLen;
                memcpy( m_Apdu.read_data, stStack[ucStackRow].ucDirEntries, stStack[ucStackRow].ucDirEntriesLen );
                ClearCurrentStackRow(stStack, ucStackRow);
                if( m_Apdu.read_len == index+2 )
                {
                    goto StartRead;
                }
                goto continueReadDir;
            }
	}

	// The SFI of the Directory File to be read
	ucSFI = m_EMVCardTags.t88[1];

	// SFI is the out of range
	if( ucSFI > 30 )
		return PSE_NOT_SUPPORTED_BY_CARD;

	if( GetLenOfDataEl(m_EMVCardTags.t9F11, &ucLenOfLen) != 0 )
	{
		if ((m_EMVCardTags.t9F11[ucLenOfLen]>10)||m_EMVCardTags.t9F11[ucLenOfLen]==0)
			return PSE_NOT_SUPPORTED_BY_CARD;
	}

	if (ucFirstPSESelect == TRUE)
	{
		ucRecOfPSE++;
		ucSFIOfPSE = ucSFI;
	}

	ucFirstPSESelect = FALSE;

//***************
// Start Read PSE
StartRead:

	index = 0;
	ucRecordNo++;
	cDDFRead = FALSE;

	// The terminal reads the Payment Systems Directory using the SFI for the
	// Payment Systems Directory to identify the file to be read.
	// The terminal uses the READ RECORD command to read each record in
	// the Payment Systems Directory until the card responds that there are no
	// more records (SW1 SW2 = “6A83”).
	// If the candidate list is empty and there are no more records, the terminal
	// attempts to build the candidate list using the List of AIDs Method.	
	ucRet = READ_RECORD(ucSFI<<3, ucRecordNo);

	if (ucRet != PROCESS_OK) return ucRet;

	PSEReadLast = FALSE;

	// The last record
	if( (m_SW1 == 0x6A) || (m_SW2 == 0x83) )
	{
		if( (memcmp(ucDDFName, "1PAY.SYS.DDF01", 14) == 0)&&(ucRecordNo==1) )
			return PSE_NOT_SUPPORTED_BY_CARD;

		// Get stack context
		ucRet = GetFromStack(stStack, &ucStackRow);

		if( ucRet != STACK_EMPTY )
		{
			// In the case of previous DDF Name is "1PAY.SYS.DDF01", return OK
			memset(&m_EMVCardTags, 0, sizeof(m_EMVCardTags));
			ucRet = SELECT((UCHAR *)"1PAY.SYS.DDF01", 14, 0, SELECT_PSE);
			if( ucRet != PROCESS_OK )
			{
				return ucRet;
			}

			index = stStack[ucStackRow].ucIndex;
			ucSFI = stStack[ucStackRow].ucSFI;
			ucRecordNo = stStack[ucStackRow].ucRecNo;
			m_Apdu.read_len = stStack[ucStackRow].ucDirEntriesLen;
			memcpy( m_Apdu.read_data, stStack[ucStackRow].ucDirEntries, stStack[ucStackRow].ucDirEntriesLen );
			ClearCurrentStackRow((STACK *)&stStack, ucStackRow);
			if( m_Apdu.read_len == index+2 )
			{
          		goto StartRead;
			}
            goto continueReadDir;
		}
		else
		{
		   	return PROCESS_OK;
		}

	}
	else if( (m_SW1 != 0x90)||(m_SW2 != 0x0)) 
	{
		return CARD_REJECTED;
	}	

	// Record read
	if( m_Apdu.read_data[index++] != 0x70 )
	{
		return DATA_FORMAT_INCORRECT;
	}
	ucDataLen = m_Apdu.read_data[index++];

	if (ucDataLen == 0)
		return DATA_FORMAT_INCORRECT;

//***************
// Parse PSE data
continueReadDir:

	if( m_Apdu.read_data[index] != 0x61 )
	{
		while( (m_Apdu.read_data[index] != 0x61) && (index<m_Apdu.read_len-2))
		{
			SetNextDataEl( m_Apdu.read_data, &index);
		}
		if( index >= m_Apdu.read_len-2 )
			return DATA_FORMAT_INCORRECT;
	}

	index++;
	ucLenOfDirEntry = m_Apdu.read_data[index++];
	dirOffset = index;

	// DDF Directory Entry format
	while( (m_Apdu.read_data[index] != 0x9D) && (m_Apdu.read_data[index] != 0x4F) && (index<m_Apdu.read_len-2) )
	{
		SetNextDataEl( m_Apdu.read_data, &index);
	}

	if( index >= m_Apdu.read_len-2 )
		return DATA_FORMAT_INCORRECT;

	if( m_Apdu.read_data[index] == 0x9D )
	{
		index++;
		cDDFRead = TRUE;
		ucDDFLen = m_Apdu.read_data[index++];
		memcpy( ucDDFName, &m_Apdu.read_data[index], ucDDFLen );
		index += ucDDFLen;

		if (index-dirOffset > ucLenOfDirEntry)
			return DATA_FORMAT_INCORRECT;
		else if (index-dirOffset< ucLenOfDirEntry)
		{
			while( (m_Apdu.read_data[index] != 0x73) && (index < m_Apdu.read_len-2) )
			{
				SetNextDataEl( m_Apdu.read_data, &index);
			}
			index++;

			if( index >= m_Apdu.read_len-2 )
				return DATA_FORMAT_INCORRECT;
			ucDDTLen = m_Apdu.read_data[index++];
			memcpy( ucDirDiscTemplate, &m_Apdu.read_data[index], ucDDTLen );
			index += ucDDTLen;

			if( index-dirOffset != ucLenOfDirEntry )
				return DATA_FORMAT_INCORRECT;

		}

        AddToStack( stStack, m_Apdu.read_data, m_Apdu.read_len, index, ucSFI, ucRecordNo );
		goto StartSelect;

	}
	else
	{
		// Clear the previous application selection data
		memset(m_EMVCardTags.t4F, 0, sizeof(m_EMVCardTags.t4F));
		memset(m_EMVCardTags.t50, 0, sizeof(m_EMVCardTags.t50));
		memset(m_EMVCardTags.t9F12, 0, sizeof(m_EMVCardTags.t9F12));
		memset(m_EMVCardTags.t87, 0, sizeof(m_EMVCardTags.t87));
		memset(m_EMVCardTags.t73, 0, sizeof(m_EMVCardTags.t73));

		ucRet = AddToEmvTAGS( &m_Apdu.read_data[index], ucLenOfDirEntry, CARD );

		if (ucRet != PROCESS_OK)
			return PSE_NOT_SUPPORTED_BY_CARD;

		if( GetLenOfDataEl(m_EMVCardTags.t50, &ucLenOfLen) == 0 ) 
		{
			return MISSING_MANDATORY_OBJECT;
		}	
		
		if( SearchInTermAIDs(ucAppList, iAppCnt) == TRUE )
		{
			AddToCandidateListPSE( m_EMVCardTags.t4F, (*iMatchAppCnt)++, &MultOccur );
        }

		index += ucLenOfDirEntry;
		if (index == ucDataLen+2)     //+2 : 70 len (The first 2 byte of READ_RECORD)


		{
			goto StartRead;
		}
		else if (index > ucDataLen+2)
			return DATA_FORMAT_INCORRECT;
		else
			goto continueReadDir;
	}
}



// Sends SELECT command to the card for each application in terminal list
// Adds the matching applications between card and terminal to the Candidate List
BYTE CEMV::PrepCandList(BYTE ucAppList[MAX_TERMINAL_APP_CNT][APP_INF_LEN], int iAppCnt, int *iMatchAppCnt)
{
	int		i;
	BYTE 	ucRet;
	BYTE	AppId[20];
	BYTE	AppLen;
	BYTE	MultOccur=FALSE;
	
	memset( m_CandList, 0, sizeof(SELECT_RESPONSE)*MAX_MATCHING_APP_CNT );
	*iMatchAppCnt=0;


	WriteLogFile( "PrepCandList", "Start Function" );

	
	for( i=0; i<iAppCnt; i++)
	{
		
		memset(&m_EMVCardTags, 0, sizeof(EMV_CARD_TAGS));
		memcpy(AppId, &ucAppList[i][1], ucAppList[i][0]);
		
		// The first byte of the Application Id (9F06) indicates the length of the Application Id
		AppLen = ucAppList[i][0];

		ucRet = SELECT( AppId, AppLen, MultOccur, SELECT_ADF );

		if( ucRet != PROCESS_OK ) return ucRet;
		
		// 6A81—Card is blocked or command not supported. Terminate session
		if( ( m_SW1 == 0x6A ) && ( m_SW2 == 0x81 ) )
		{

			if( MultOccur==TRUE )
			{
				MultOccur = FALSE;
				continue;
			}

			// Terminate the card session
			// Here is commented in the test 2CB025 partial6A81 EVAL1.6  

			else if( m_CandList[0].l84==0 )
			{
				WriteLogFile( "PrepCandList","CARD_REJECTED" );
				return CARD_REJECTED;
			}
				
			//else 
			//{
			//	return PROCESS_OK;
			//}
				
		}
		// 6283—Application is blocked. Continue with the next application id in terminal list
		else if( ( m_SW1 == 0x62) && (m_SW2 == 0x83) )
		{
			if( MultOccur == FALSE )
			{
				// Check for the possibility of multiple occurences of the application in the ICC
				// before selecting the next AID from the list
				MultOccur = TRUE;	
				i--;			
				continue;
			}
			else
			{
				// Check for the possibility of multiple occurences of the application in the ICC				
				MultOccur = TRUE;
				i--;		
				continue;
			}
		}
		else if( (m_SW1 == 0x6A) && (m_SW2 == 0x82) )
		{
			// Continue with the next application on terminal list
			MultOccur=FALSE;
			continue;
		}
		// SELECT command successful. Add the application to the candidate list.
		else if( (m_SW1 == 0x90) && (m_SW2 == 0x00) )
		{
			ucRet = AddToCandidateList(ucAppList[i], *iMatchAppCnt, &MultOccur);
			(*iMatchAppCnt)++;
			// Format Error
          	if( ucRet == FALSE )
				continue;
			
			// There are more than one application on the card starting by this application id. 
			// Continue with the same application id
			if( MultOccur == TRUE )
			{
				i--;
				continue;
			}
		}
// Anything else continue with the next application id in terminal list
		else
		{
			MultOccur=FALSE;
			continue;
		}
	}
	return PROCESS_OK;
}



// Adds the matching applications between card and terminal to the candidate list
BYTE CEMV::AddToCandidateListPSE(LPBYTE ucAppId, int index, LPBYTE cMultipleOccurence)
{

	int TermAidLen, CardAidLen, len;
	BYTE	Temp[32], ucLenOfLen;


	WriteLogFile( "AddToCandidateListPSE","Start Function" );


	*cMultipleOccurence = 0;

// Read 84
	if (m_EMVCardTags.t84[0] == 0)
		return FALSE;

// Read 4F
	if (m_EMVCardTags.t4F[0] == 0)
		return FALSE;

	TermAidLen = ucAppId[0];
	CardAidLen = m_EMVCardTags.t4F[0];
	if (TermAidLen < CardAidLen)
	{
		if (memcmp(&ucAppId[1], &m_EMVCardTags.t4F[1], TermAidLen) == 0) {
// There is more than one application on the card matching with the terminal aid
			if (ucAppId[APP_INF_LEN-1]==1)	
				*cMultipleOccurence = 1;
			else	
				return FALSE;	
		}		
	}
	else if (TermAidLen == CardAidLen)
	{
		if (memcmp(&ucAppId[1], &m_EMVCardTags.t4F[1], TermAidLen) != 0)
			return FALSE;
	}
	else
	{
		return FALSE;
	}
	memcpy(m_CandList[index].p9F06, &ucAppId[1], ucAppId[0]);
	m_CandList[index].l9F06 = (UINT)ucAppId[0];
	memcpy(m_CandList[index].p4F, &m_EMVCardTags.t4F[1], m_EMVCardTags.t4F[0]);
	m_CandList[index].l4F = (UINT)m_EMVCardTags.t4F[0];

// Read 50
	len = GetLenOfDataEl(m_EMVCardTags.t50, &ucLenOfLen);
	if (len != 0)
	{
		memcpy(Temp, m_EMVCardTags.t50+ucLenOfLen, len);
		memcpy(m_CandList[index].p50, (char *)Temp, len);
		m_CandList[index].l50 = (UINT)len;
	}

// Read 87
	len = GetLenOfDataEl(m_EMVCardTags.t87, &ucLenOfLen);
	if (len != 0)
	{
        m_CandList[index].l87=1;
		m_CandList[index].p87 = m_EMVCardTags.t87[1];
	}

// Read 9F38
	len = GetLenOfDataEl(m_EMVCardTags.t9F38, &ucLenOfLen);
	if (len != 0)
	{
		memcpy(m_CandList[index].p9F38, &m_EMVCardTags.t9F38[ucLenOfLen], len);
		m_CandList[index].l9F38 = (UINT)len;
	}

// Read 5F2D
	len = GetLenOfDataEl(m_EMVCardTags.t5F2D, &ucLenOfLen);
	if (len != 0)
	{
		memcpy(m_CandList[index].p5F2D, &m_EMVCardTags.t5F2D[ucLenOfLen], len);
		m_CandList[index].l5F2D = (UINT)len;
	}

// Read 9F11
	if (m_EMVCardTags.t9F11[0] != 0)
	{
		m_CandList[index].p9F11 = m_EMVCardTags.t9F11[1];
	}

// Read 9F12
	len = GetLenOfDataEl(m_EMVCardTags.t9F12, &ucLenOfLen);
	if (len != 0)
	{
		memcpy(m_CandList[index].p9F12, (char *)&m_EMVCardTags.t9F12[ucLenOfLen], len);
		m_CandList[index].l9F12 = len;
	}

// Read BF0C
	len = GetLenOfDataEl(m_EMVCardTags.tBF0C, &ucLenOfLen);
	if (len != 0)
	{
		memcpy(m_CandList[index].pBF0C, &m_EMVCardTags.tBF0C[ucLenOfLen], len);
		m_CandList[index].lBF0C = len;
	}
	return TRUE;
}


// Adds the matching applications between card and terminal to the candidate list
BYTE CEMV::AddToCandidateList(BYTE *ucAppId, int index, BYTE *cMultipleOccurence)
{
	int  	len;
	BYTE	Temp[32], ucLenOfLen, TermAidLen, CardAidLen;



	WriteLogFile( "AddToCandidateList","Start Function" );


	*cMultipleOccurence = FALSE;

// Read 84
	if (m_EMVCardTags.t84[0] == 0)
	{
		WriteLogFile( "AddToCandidateList","Tag 84 Empty" );
		return FALSE;
	}

	TermAidLen = ucAppId[0];
	CardAidLen = m_EMVCardTags.t84[0];
	if (TermAidLen < CardAidLen)
	{
		if (memcmp(&ucAppId[1], &m_EMVCardTags.t84[1], TermAidLen) == 0) 
		{
// There is more than one application on the card matching with the terminal aid
			
			if (ucAppId[APP_INF_LEN-1]==1)	//New
				*cMultipleOccurence = TRUE;
			else	//New
				return FALSE;	//New
		}		
	}
	else if (TermAidLen == CardAidLen)
	{
		if (memcmp(&ucAppId[1], &m_EMVCardTags.t84[1], TermAidLen) != 0)
		{
			WriteLogFile( "AddToCandidateList","Can Not Add to App List.  TermAid!=CardAid" );
			return FALSE;
		}
	}
	else
	{
		WriteLogFile( "AddToCandidateList","TermAidLen > CardAidLen" );
		return FALSE;
	}


	memcpy(m_CandList[index].p9F06, &ucAppId[1], ucAppId[0]);
	m_CandList[index].l9F06 = (UINT)ucAppId[0];
	memcpy(m_CandList[index].p84, &m_EMVCardTags.t84[1], m_EMVCardTags.t84[0]);
	m_CandList[index].l84 = (UINT)m_EMVCardTags.t84[0];
// Read 50
	len = GetLenOfDataEl(m_EMVCardTags.t50, &ucLenOfLen);
	if (len != 0)
	{
		WriteLogFile( "AddToCandidateList","Tag 50 Added" );
		memcpy(Temp, m_EMVCardTags.t50+ucLenOfLen, len);
		memcpy(m_CandList[index].p50, (char *)Temp, len);
		m_CandList[index].l50 = len;
	}

// Read 87
	len = GetLenOfDataEl(m_EMVCardTags.t87, &ucLenOfLen);
	if (len != 0)
	{
		WriteLogFile( "AddToCandidateList","Tag 87 Added" );
		m_CandList[index].l87=1;
		m_CandList[index].p87 = m_EMVCardTags.t87[1];
	}

// Read 9F38
	len = GetLenOfDataEl(m_EMVCardTags.t9F38, &ucLenOfLen);
	if (len != 0)
	{
		WriteLogFile( "AddToCandidateList","Tag 9F38 Added" );
		memcpy(m_CandList[index].p9F38, &m_EMVCardTags.t9F38[ucLenOfLen], len);
		m_CandList[index].l9F38 = len;
	}

// Read 5F2D
	len = GetLenOfDataEl(m_EMVCardTags.t5F2D, &ucLenOfLen);
	if (len != 0)
	{
		WriteLogFile( "AddToCandidateList","Tag 5F2D Added" );
		memcpy(m_CandList[index].p5F2D, &m_EMVCardTags.t5F2D[ucLenOfLen], len);
		m_CandList[index].l5F2D = len;
	}

// Read 9F11
	if (m_EMVCardTags.t9F11[0] != 0)
	{
		WriteLogFile( "AddToCandidateList","Tag 9F11 Added" );
		m_CandList[index].p9F11 = m_EMVCardTags.t9F11[1];
	}

// Read 9F12
	len = GetLenOfDataEl(m_EMVCardTags.t9F12, &ucLenOfLen);
	if (len != 0)
	{
		WriteLogFile( "AddToCandidateList","Tag 9F12 Added" );
		memcpy(m_CandList[index].p9F12, (char *)&m_EMVCardTags.t9F12[ucLenOfLen], len);
		m_CandList[index].l9F12 = len;
	}

// Read BF0C
	len = GetLenOfDataEl(m_EMVCardTags.tBF0C, &ucLenOfLen);
	if (len != 0)
	{
		WriteLogFile( "AddToCandidateList","Tag BF0C Added" );
		memcpy(m_CandList[index].pBF0C, &m_EMVCardTags.tBF0C[ucLenOfLen], len);
		m_CandList[index].lBF0C = len;
	}
	return TRUE;
}


// Parses the data in TLV format and locates the parsed data into global structure
BYTE CEMV::AddToEmvTAGS(LPBYTE Msg, int MsgLen, char cDataSource)
{
	int i,TagCnt,index=0,len,iIssScriptIndex=0, iIssScriptLen;
	BYTE ucLenOfLen;



	WriteLogFile( "AddToEmvTAGS","Start Function" );
	WriteLogFile( m_Apdu.read_len-4,m_Apdu.read_data+2 );



	TagCnt = sizeof(m_TagAddress)/sizeof(TAG_ADDRESS);
	while (index < MsgLen)
	{
// Terminal ignores if a data element is right padded with 0 or FF
		if( (Msg[index] == 0) || (Msg[index] == 0xFF) )
		{
            index++;
			continue;
		}
// Move the issuer script commands to the global structure if it is coming from online response.
		if( (Msg[index] == 0x71) && (cDataSource == ISSUER) )
		{
			iIssScriptLen = Msg[index+1];
            memcpy( &m_IssScriptMsg[iIssScriptIndex], &Msg[index], iIssScriptLen+2 );
			iIssScriptIndex += iIssScriptLen+2;
			index += iIssScriptLen+2;
			continue;
		}
		if( (Msg[index] == 0x72) && (cDataSource == ISSUER))
        {
            iIssScriptLen = Msg[index+1];
			memcpy( &m_IssScriptMsg[iIssScriptIndex], &Msg[index], iIssScriptLen+2 );
			iIssScriptIndex += iIssScriptLen+2;
			index += iIssScriptLen+2;
			continue;
		}
        if (Msg[index] == 0xDF)
        {
	        len = Msg[index+2];
    	    switch(Msg[index+1])
            {
            case 0x81:
        	    memcpy(m_EMVTermTags.tDF81, &Msg[index+2], len+1);
                break;
            case 0x83:
                memcpy(m_EMVTermTags.tDF83, &Msg[index+2], len+1);
            	break;
            case 0x84:
                memcpy(m_EMVTermTags.tDF84, &Msg[index+2], len+1);
					 break;
            case 0x85:
                memcpy(m_EMVTermTags.tDF85, &Msg[index+2], len+1);
                break;
            case 0x87:
                memcpy(m_EMVTermTags.tDF87, &Msg[index+2], len+1);
                break;
            case 0x88:
                memcpy(m_EMVTermTags.tDF88, &Msg[index+2], len+1);
                break;
            case 0x89:
                memcpy(m_EMVTermTags.tDF89, &Msg[index+2], len+1);
                break;
            case 0x90:
                memcpy(m_EMVTermTags.tDF90, &Msg[index+2], len+1);
                break;
            case 0x91:
                memcpy(m_EMVTermTags.tDF91, &Msg[index+2], len+1);
                break;
            case 0x92:
                memcpy(m_EMVTermTags.tDF92, &Msg[index+2], len+1);
                break;
            case 0x95:
                memcpy(m_EMVTermTags.tDF95, &Msg[index+2], len+1);
					 break;
            case 0x98:
                memcpy(m_EMVTermTags.tDF98, &Msg[index+2], len+1);
                break;
            case 0xA0:
                memcpy(m_EMVTermTags.tDFA0, &Msg[index+2], len+1);
                break;
                index += len+3;
                continue;
           }
       }

		
       
    	for (i=0;i<TagCnt;i++)
		{
// The message coming contains A5 template. There is no data to be received from templates
			if (Msg[index] == 0xA5)
			{
                index+=2;
				break;
			}
			
// Check if the data element is present in the m_TagAddress table
			if( (m_TagAddress[i].Tag[0] == Msg[index]) && 
				( (m_TagAddress[i].Tag[1] == Msg[index+1]) || (m_TagAddress[i].Tag[1] == 0x0) ) )
			{
				WriteLogFile("AddToEmvTAGS-FIND", m_TagAddress[i].Tag, (LPBYTE)"\x02\x00\x00" );
				if (cDataSource == CARD)
				{
// Duplicate data element from the card
					if (m_TagAddress[i].Address[0] != 0)
					{
						WriteLogFile("AddToEmvTAGS","DUPLICATE_CARD_DATA_ELEMENT");
						return DUPLICATE_CARD_DATA_ELEMENT;
					}
				}
				if(m_TagAddress[i].Tag[1] == 0x0)
					index++;
				else
					index += 2;

// Index located at length field
				if((Msg[index]&0x80) == 0x80)
				{
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
					ucLenOfLen = Msg[index]&0x7F;
					
					if (Msg[index+1]<=0x7F) 
					{
						ucLenOfLen=0;
						index++;
					}
					memcpy(m_TagAddress[i].Address, &Msg[index], ucLenOfLen+1);
					WriteLogFile("AddToEmvTAGS-ADDED", m_TagAddress[i].Tag, m_TagAddress[i].Address );
					index += ucLenOfLen+1;
				}
				else
				{
// The length of the length field of the data element is coded as one byte
					m_TagAddress[i].Address[0] = Msg[index++];
				}
				len = GetLenOfDataEl(m_TagAddress[i].Address, &ucLenOfLen);
				if (len != 0)
				{
// If the length of the Data Element is not zero, allocate memory for coming data
					memcpy(&m_TagAddress[i].Address[ucLenOfLen], &Msg[index], len);
					WriteLogFile("AddToEmvTAGS-ADDED", m_TagAddress[i].Tag, m_TagAddress[i].Address );
				}
				index += len;
// Index located to the next Data Element
				break;
			}
		}
// Check if tag be found in table
		if (i==TagCnt)
		{
			SetNextDataEl(Msg, &index);
		}
		
	}
// Check if there is a format error in the message
	if (index > MsgLen)
    {
		return DATA_FORMAT_INCORRECT;
	}
	
	return PROCESS_OK;
}


BYTE CEMV::SearchInTermAIDs(BYTE ucAppList[MAX_TERMINAL_APP_CNT][APP_INF_LEN], int iAppCnt)
{
	int i;

	for (i=0;i<iAppCnt;i++)
	{
		if (memcmp(&m_EMVCardTags.t4F[1], &ucAppList[i][1], ucAppList[i][0]) == 0)
            return TRUE;
	}
	if (i==iAppCnt)
		return FALSE;
		
	return TRUE;
}


BYTE CEMV::GetLastRow(STACK *ucStack, BYTE *ucRow)
{
	BYTE i=0;
	BYTE ucTemp[128];

	memset(ucTemp, 0, 128);

	while (1)
	{
		if (i==5)
		{
			return STACK_FULL;
		}
		if ((memcmp(ucTemp, ucStack[i].ucDirEntries, 128)==0)&&(ucStack[i].ucSFI ==0))
            break;
        else
        	i++;
	}
	if (i == 0)
		return STACK_EMPTY;
	*ucRow = i-1;
	return TRUE;
}


BYTE CEMV::AddToStack(STACK *ucStack, BYTE *ucStackData, BYTE ucStackDataLen, BYTE ucIndex, BYTE ucSFI, BYTE ucRecordNo)
{
	BYTE ucRow, ucRet;


	ucRet = GetLastRow(ucStack, &ucRow);
	if (ucRet == STACK_FULL)
		return ucRet;
	if (ucRet != STACK_EMPTY)
		ucRow++;
	else
		ucRow = 0;

	ucStack[ucRow].ucDirEntriesLen = ucStackDataLen;
	memcpy(&ucStack[ucRow].ucDirEntries, ucStackData, ucStackDataLen);
	ucStack[ucRow].ucSFI = ucSFI;
	ucStack[ucRow].ucIndex = ucIndex;
	ucStack[ucRow].ucRecNo = ucRecordNo;
	return TRUE;
}


BYTE CEMV::GetFromStack(STACK *ucStack, BYTE *ucStackRow)
{
	BYTE 	ucRow, ucRet;

	ucRet = GetLastRow(ucStack, &ucRow);
	if (ucRet != TRUE)
		return ucRet;

	*ucStackRow = ucRow;

	return TRUE;
}

void CEMV::ClearCurrentStackRow(STACK *ucStack, BYTE ucStackRow)
{
	memset(&ucStack[ucStackRow], 0, sizeof(STACK));
}


int CEMV::GetLenOfDataEl(LPBYTE ucDataEl, LPBYTE ucLenOfLen)
{
	int len;
// The length of the length field of the data element is coded more than one byte
// Find the length of the length field of Data Element
	if( (ucDataEl[0]&0x80) == 0x80 )
	{
		*ucLenOfLen = ucDataEl[0]&0x7F;
		len = Bin2Lng(&ucDataEl[1], *ucLenOfLen);
		(*ucLenOfLen)++;
		return len;
	}
	else
	{
		*ucLenOfLen = 1;
		return (int)ucDataEl[0];
	}
}

void CEMV::SetNextDataEl(BYTE *ucData, int *iDataIndex)
{
	int   len;
	BYTE ch, ucLenOfLen;

	ch = ucData[*iDataIndex]&0x1F;
	if (ch == 0x1F)
	{
		(*iDataIndex)++;
		while ((ucData[*iDataIndex]&0xF0) == 0xF0)
		{
			(*iDataIndex)++;
		};
	}
	(*iDataIndex)++;

    len = GetLenOfDataEl(&ucData[*iDataIndex], &ucLenOfLen);
	(*iDataIndex) += (int)ucLenOfLen;
	(*iDataIndex) += len;
}

BYTE CEMV::SELECT(LPBYTE pucAppName, BYTE ucAppLen, BOOL MultOccurence, BYTE ucSelectType)
{
	BYTE	resp;
	CIsoLib::SELECT( pucAppName, ucAppLen, MultOccurence );
    resp = ParseSelectResp(ucSelectType);
	if (resp != PROCESS_OK)
		return resp;
    return PROCESS_OK;
}

BYTE CEMV::ParseSelectResp(BYTE ucSelectType)
{
	int   index=0,len, lenA5;
	BYTE iIssCodeTblIndex, ucRet;
	

// Only SW1 SW2
		if(m_Apdu.read_len == 2)
			return PROCESS_OK;
// Check FCI Template (6F) (Mandatory field)
		while( (m_Apdu.read_data[index] != 0x6F) && (index < m_Apdu.read_len-2) )
		{
			SetNextDataEl( m_Apdu.read_data, &index );
		}
		if(index >= m_Apdu.read_len-2)
			return DATA_FORMAT_INCORRECT;
		index++;

// Check FCI Template Len
		if( m_Apdu.read_data[index++] == 0x00 )
			return DATA_FORMAT_INCORRECT;
// Ignore left padding FFs
		while( (m_Apdu.read_data[index] == 0xFF) || (m_Apdu.read_data[index] == 0x00) )
		{
			index++;
			continue;
		}
		if( index >= m_Apdu.read_len-2 )
			return DATA_FORMAT_INCORRECT;

// Check DFName
		while( (m_Apdu.read_data[index] != 0x84) && (index < m_Apdu.read_len-2) )
		{
			SetNextDataEl( m_Apdu.read_data, &index );
		}
		if( index >= m_Apdu.read_len-2 )
			return DATA_FORMAT_INCORRECT;
		index++;

// Check DFName len
		len = m_Apdu.read_data[index++];
		index += len;
		if( index >= m_Apdu.read_len-2 )
			return DATA_FORMAT_INCORRECT;

// Ignore left padding FFs
		while( (m_Apdu.read_data[index] == 0xFF) || (m_Apdu.read_data[index] == 0x0) )
		{
			index++;
			continue;
		}
		if( index >= m_Apdu.read_len-2 )
			return DATA_FORMAT_INCORRECT;

// Check FCI Proprietary Template
		while( (m_Apdu.read_data[index] != 0xA5) && (index < m_Apdu.read_len-2) )
		{
			SetNextDataEl( m_Apdu.read_data, &index );
		}
		if( index >= m_Apdu.read_len-2 )
			return DATA_FORMAT_INCORRECT;
		index++;
                lenA5 = m_Apdu.read_data[index++];
		if( lenA5+index > m_Apdu.read_len-2 )
			return DATA_FORMAT_INCORRECT;

		if( ucSelectType == SELECT_PSE )
		{
// Check SFI of the directory elemantary file
			while( (m_Apdu.read_data[index] == 0xFF) || (m_Apdu.read_data[index] == 0x00) )
			{
				index++;
				continue;
			}
			if( index >= m_Apdu.read_len-2 )
				return DATA_FORMAT_INCORRECT;
			while( (m_Apdu.read_data[index] != 0x88) && (index < m_Apdu.read_len-2) )
			{
				SetNextDataEl( m_Apdu.read_data, &index );
			}
// The len and the value of tag 88 (2 bytes)
			index+=2;
			if( index > m_Apdu.read_len-2 )
				return DATA_FORMAT_INCORRECT;
		}

		ucRet = AddToEmvTAGS( m_Apdu.read_data+2, m_Apdu.read_len-4, CARD);
		if( ucRet != PROCESS_OK )
			return ucRet;

/*		len = GetLenOfDataEl(m_EMVCardTags.t50, &ucLenOfLen);
    if (len == 0)
				return DATA_FORMAT_INCORRECT;
*/

// Check if the Issuer Code Table Index is out of the range
		if(m_EMVCardTags.t9F11[0] != 0)
		{
			iIssCodeTblIndex = m_EMVCardTags.t9F11[1];
			if( iIssCodeTblIndex > 0x10 )
				return ISS_COD_TBL_OUT_OF_RANGE;
		}
		return PROCESS_OK;
}


BYTE CEMV::FillTermParams( void )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}

void CEMV::PrepCAKEYS( void )
{
	// Virtual Function
	// Must Define in derived class
}

void CEMV::SetTermVersion( void )
{
	// Virtual Function
	// Must Define in derived class
}

BYTE CEMV::CheckPinBlockBIN( void )
{
	// Virtual Function
	// Must Define in derived class
	return NO_BIN_PERMISSION;
}

BYTE CEMV::GetPin( BYTE UseMAC, LPBYTE PinBl ,BYTE PlainFlag )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}

BYTE CEMV::GetTxType( void )
{
	// Virtual Function
	// Must Define in derived class
	m_TransactionType = 0;
	return PROCESS_OK;
}

BYTE CEMV::SplitSale( LPBYTE PCardNumber, LPDWORD pxTotAmount )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}


void CEMV::GetOnlineTags( LPBYTE OnlineTags )
{
	// Virtual Function
	// Must Define in derived class
}

BYTE CEMV::GetBankDecision( void )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}



BYTE CEMV::InputAmount( ULONG &Amount )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}

BYTE CEMV::SendSmartData(WORD SendLen, LPBYTE CardSendData, WORD &OutLen, LPBYTE CardReplyData)
{
	// Virtual Function
	// Must Define in derived class
	
	OutLen = 0;
	CardReplyData = NULL;

	return PROCESS_OK;
}

BYTE CEMV::DisplayDebug( CString message )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}

BYTE CEMV::DisplayClear( void )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}
BYTE CEMV::DisplayMessage( WORD Line, CString message, BOOL ClearLines )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}


BYTE CEMV::AddRec( void )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}


// Menu function
//--------------------------------------------------------------
//	pxMenu : pointer to menu definition
//	ucSize : Number of menu entries
//--------------------------------------------------------------
// Return
//	Menu index (=0xFF if cancel)
//**************************************************************
INT CEMV::DisplayAppMenu( CHIPMENU *pxMenu, UCHAR ucSize )
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}



/************************************************************************
*  Function      : Pack()						*
*************************************************************************
*  Parameters    : OpenForm - character stream that will be comressed	*
*		   CompressedForm - converted character stream		*
*		   Length - length of CardNo before compression         *
*  Outputs	 : CompressedForm                                       *
*  Return Values : None                                                 *
*  Description   : Compresses numerical strings				*
*		   Principle is to store two digits in one byte		*
*									*
*		   Examle :						*
*		   CardNo     CompressedForm   Length			*
*		   ========   ==============   ======			*
*		   "493846"        "1&."          6			*
*									*
*		   '1' -> ASCII 49     					*
*		   '&'-> ASCII 38					*
*		   '.'-> ASCII 46					*
*									*
*		   Used for BIN compression so that 			*
*		   for each call Length is 6 or (2*3)			*
*************************************************************************/
void CEMV::Pack(UCHAR Base, UCHAR *OpenForm,UCHAR *CompressedForm,UCHAR Length)
{
	UCHAR ch,Flag;
	Flag=1;
	while (Length--) 
	{
		if (Base==10) 
		{
			ch= (*OpenForm>='0' && *OpenForm<='9') ? ((*OpenForm)-'0'):0;
		}
		else 
		{
			ch= (*OpenForm>='0' && *OpenForm<='9') ? ((*OpenForm)-'0'):((*OpenForm)-'A'+10);
		}
		if (Flag) 
		{
			*CompressedForm=ch*Base;
		}
		else 
		{
			*CompressedForm+=ch;
			CompressedForm++;
		}
		OpenForm++;
		Flag=1-Flag;
	}
}

/************************************************************************
*  Function      : UnPack()						*
*************************************************************************
*  Parameters    : CompressedForm - compressed stream to be uncompressed*
*		   OpenForm - storage variable after uncompression	*
*		   Length         - length of CardNo to be uncommpressed*
*  Outputs	 : None                                                 *
*  Return Values : None                                                 *
*  Description   : Uncompresses streams					*
*		   Principle is to store 1 byte in two digits		*
*									*
*		   Examle :						*
*		   CompressedForm   CardNo    Length			*
*		   ==============   ========  ======			*
*		       "1&."       "493846"    6			*
*									*
*		   '1' -> ASCII 49					*
*		   '&'-> ASCII 38					*
*		   '.'-> ASCII 46					*
*									*
*		   Used for uncompression of compressed BINs		*
*		   so that for each call Length is 6 (2 times 3)	*
*************************************************************************/
void CEMV::UnPack(UCHAR Base, UCHAR *CompressedForm,UCHAR *OpenForm,UCHAR Length)
{
	UCHAR Flag;
	Flag=1;
	while (Length--) 
	{
		if (Flag) 
		{
			*OpenForm=(*CompressedForm)/Base;
		}
		else 
		{
			*OpenForm=(*CompressedForm)%Base;
			CompressedForm++;
		}
		*OpenForm+=(Base==BASEDEC || (*OpenForm)<10)?'0':'A'-10;
		OpenForm++;
		Flag=1-Flag;
	}
}

WORD CEMV::Bin2Lng(LPBYTE buff, WORD buff_len)
{
	WORD        Lng,i,j;
	BYTE		buf[4];									// 4 : The size of Long type.

	if( (buff_len > 4)||(buff_len < 0) )
		return (WORD)-1;
	i=0;
	if( buff_len<4 )  
		for (i=0;i<4-buff_len;i++)						// Reset first bytes .
			buf[i]=0;

	for (j=i;j<4;j++)											// Fill last bytes.
		buf[j] = buff[j-i];

	Lng = (buf[0]<<24)|(buf[1]<<16)|(buf[2]<<8)|(buf[3]); // Prep Lng
	return Lng;
}

void CEMV::Lng2Bcd(int lngValue, unsigned char *buff, int len)
{
	unsigned char	str[20];
    int             buff_len,i;
    unsigned char   buf[20];

	sprintf((char *)str, "%d", lngValue);

    buff_len = (INT)strlen((char *)str)/2 + (INT)strlen((char *)str)%2;

	Str2Bcd((char *)str, (WORD)strlen((char *)str), LEFT_PAD_ZERO, buf, 20, LEFT_PAD);
//	Str2Bcd(str, strlen((char *)str), NO_PAD_ZERO, buf);

    if (len > buff_len)
    {
        for(i=0;i<len-buff_len;i++)
            buff[i] = 0;
        for (i=len-buff_len;i<len;i++)
            buff[i] = buf[i-len+buff_len];
    }
    else
        for (i=0;i<len;i++)
            buff[i] = buf[i];
}

void CEMV::Short2Bin(unsigned short int shortValue, unsigned char *buff)
{
	buff[1] = shortValue&0xFF;
	buff[0] = (shortValue>>8)&0xFF;
}

unsigned CEMV::Bcd2Lng(unsigned char *buff, unsigned buff_len)
{
	unsigned		Lng;
	unsigned		i,j;
	int				FrstNibble;
	int				ScndNibble;

// log(2^32) = 9.5 so the buff_len shouldn't be more than 5
	if ((buff_len > 9)||(buff_len < 0))
		return (unsigned)-1;
// If buff_len = 5, buff[0] shouln't br greater than 3
	if (buff_len == 9)
	{
		if (buff[0] > 0x03)
			return (unsigned)-1;
	}

	Lng = 0;

	for (i=0;i<buff_len;i++)
	{
		j = buff_len-1-i;
		FrstNibble = buff[j]&0x0F;
		ScndNibble = buff[j]>>4;
//		if ((FrstNibble > 0x09)||(ScndNibble > 0x09))
//			return FALSE;
		Lng += (FrstNibble)*power(10,2*i);
		Lng += (ScndNibble)*power(10,2*i+1);
	}

	return Lng;
}


char *CEMV::Bcd2Str(unsigned char *buff, unsigned buff_len, int cut_type, char *str)
{
	unsigned        i;
	unsigned char   *str_buf;
	int				str_len;

	if (buff_len==0) return NULL; // !ZO EMV patch 27/03/2006

// The length of ASCII string is two times of length of BCD string plus one NULL character
	str_buf = new BYTE[ buff_len*2+1 ];

//    sMemAlloc(buff_len*2+1, (char **)&str_buf);
//	malloc((char **)&str_buf,buff_len*2+1);

	//if (str_buf == NULL)
	//	return NULL;

	str_len = buff_len*2;

	for (i=0;i<buff_len;i++)
	{
		sprintf((char *)str_buf+i*2, "%2.2X",buff[i]);
	}

// If the length of string is odd value, right or left pad the string
	if (cut_type == LEFT_CUT_BYTE)
	{
		memcpy(str, str_buf+1, str_len-1);
		str[str_len-1] = 0;
	}
	else if (cut_type == RIGHT_CUT_BYTE)
	{
		memcpy(str, str_buf, str_len-1);
		str[str_len-1] = 0;
	}
	else
	{
		memcpy(str, str_buf, str_len);
		str[str_len] = 0;
	}

	delete str_buf;

	//sMemFree((char *)str_buf);
	return str;
}

/*	String bit düzeninde verilmiþ bir buffer'ý BCD bit düzenine çevirir.				*/
/*  str_len deðeri tek sayý verilmiþ ise string'in soluna ve saðýna 0 ekler.		*/
/*	Mesela str = "792" ve PAD_ZERO = LEFT_PAD_ZERO olarak tanýmlanmýþsa					*/
/*  bcd = 07 92, str = "792" ve pad type = LEFT_PAD_ZERO olarak tanýmlanmýþsa		*/
/*  bcd = 79 20 döner. */
/*  Örnek Data = str = "11234567", str_len = 8 ise bcd = 0x11 0x23 0x45 0x67    */
/*  pad_dir : RIGHT_PAD : Saða dayalý */
/*  pad_dir : LEFT_PAD : Sola dayalý */

unsigned char *CEMV::Str2Bcd(char *str, unsigned str_len, int pad_type, unsigned char *bcd, int bcdlen, int pad_dir)
{
	WORD			i,index;
	unsigned char	lnibble;
	unsigned char	unibble;
	unsigned char   *str_buf;
	unsigned		str_buf_len;

	if (bcdlen==0) return NULL; 

	str_buf = new BYTE[str_len + str_len%2];
//    sMemAlloc(str_len + str_len%2, (char **)&str_buf);

	if( PRIMENUMBER(str_len) )
	{
		if (pad_type == LEFT_PAD_ZERO)			// Left Pad
		{
			str_buf[0] = '0';
			memcpy(str_buf+1, str, str_len);
			str_buf_len = str_len +1;
		}
		else if (pad_type == RIGHT_PAD_ZERO)	// Right Pad
		{
			memcpy(str_buf, str, str_len);
			str_buf[str_len] = '0';
			str_buf_len = str_len +1;
		}
		else
		{
			memcpy(str_buf, str, str_len);
			str_buf_len = str_len;
		}
	}
	else
	{
		memcpy(str_buf, str, str_len);
		str_buf_len = str_len;
	}

	memset(bcd, 0, bcdlen);
		
	i=(str_len+1)/2;
	if( (pad_dir == RIGHT_PAD) && (bcdlen>i) )
		index = bcdlen-i;
	else
		index=0;

	for (i=0;i<str_buf_len;i++)
	{
		if( PRIMENUMBER(i) == 0 )
		{
			if ((str_buf[i]>= 0x30)&&(str_buf[i]<= 0x39))					// 0..9
				unibble = str_buf[i]-0x30;									// upper nibble of byte
			else if ((str_buf[i]>= 0x41)&&(str_buf[i]<= 0x46))				// A..F
				unibble = str_buf[i]-0x37;
			else
			{
				delete str_buf;
//				sMemFree((char *)str_buf);
				return NULL;
			}
	        bcd[index+i/2] = unibble;
		}
		else
		{
			if ((str_buf[i]>= 0x30)&&(str_buf[i]<= 0x39))		// 0..9
				lnibble = str_buf[i]-0x30;						// lower nibble of byte
			else if ((str_buf[i]>= 0x41)&&(str_buf[i]<= 0x46))	// A..F
				lnibble = str_buf[i]-0x37;
			else
			{
				delete str_buf;
//				sMemFree((char *)str_buf);
				return NULL;
			}
			bcd[index+i/2] = (unibble << 4)|(lnibble);
		}
	}

	delete str_buf;

	//	sMemFree((char *)str_buf);
	return bcd;
}



int CEMV::power( int a, int b )
{
	int res;
	int i;

	res = 1;
	for (i=0;i<b;i++)
	{
		res = res*a;
	}

	return res;
}






void CEMV::compute_hash_str( unsigned char* buffer, int bufferlen, unsigned char digest[20] )
{
    SHA1_CTX context;

    SHA1Init(&context);
    
    SHA1Update(&context, buffer, bufferlen);

	SHA1Final(digest, &context);
}

void CEMV::SHA1Init(SHA1_CTX* context)
{
    /* SHA1 initialization constants */
    context->state[0] = 0x67452301;
    context->state[1] = 0xEFCDAB89;
    context->state[2] = 0x98BADCFE;
    context->state[3] = 0x10325476;
    context->state[4] = 0xC3D2E1F0;
    context->count[0] = context->count[1] = 0;
}

void CEMV::SHA1Update(SHA1_CTX* context, unsigned char* data, unsigned long len)
{
	unsigned int i, j;

    j = (context->count[0] >> 3) & 63;
    if ((context->count[0] += len << 3) < (len << 3)) context->count[1]++;
    context->count[1] += (len >> 29);
    if ((j + len) > 63) 
	{
        memcpy(&context->buffer[j], data, (i = 64-j));
       
        SHA1Transform(context->state, context->buffer);
        for ( ; i + 63 < len; i += 64) 
		{
            SHA1Transform(context->state, &data[i]);
        }
        j = 0;
    }
    else i = 0;
    memcpy(&context->buffer[j], &data[i], len - i);
}


void CEMV::SHA1Final(unsigned char digest[20], SHA1_CTX* context)
{
	unsigned long i, j;
	unsigned char finalcount[8];

    for (i = 0; i < 8; i++) 
	{
        finalcount[i] = (unsigned char)((context->count[(i >= 4 ? 0 : 1)]
													>> ((3-(i & 3)) * 8) ) & 255);  /* Endian independent */
    }
    
	SHA1Update(context, (unsigned char *)"\200", 1);
    
	while ((context->count[0] & 504) != 448) 
	{
        SHA1Update(context, (unsigned char *)"\0", 1);
    }
    
	SHA1Update(context, finalcount, 8);  /* Should cause a SHA1Transform() */
    
	for (i = 0; i < 20; i++) 
	{
        digest[i] = (unsigned char)((context->state[i>>2] >> ((3-(i & 3)) * 8) ) & 255);
    }
    /* Wipe variables */
    i = j = 0;
    memset(context->buffer, 0, 64);
    memset(context->state, 0, 20);
    memset(context->count, 0, 8);
    memset(finalcount, 0, 8);
}

void CEMV::SHA1Transform(unsigned long state[5], unsigned char buffer[64])
{
	unsigned long a, b, c, d, e;
	typedef struct
	{
	//  unsigned char c[64];
		unsigned long l[16];
	} CHAR64LONG16;
	
	CHAR64LONG16 *block;
	int i,j;
	

	block = new CHAR64LONG16[sizeof(CHAR64LONG16)];
	
	//sMemAlloc(sizeof(CHAR64LONG16),(char **)&block);

	//block = malloc(sizeof(CHAR64LONG16));

	for (i=0;i<64;i+=4)
	{
		SHA1Invert(&buffer[i]);

		j=((i+1)/4);
		block->l[j]=Bin2Lng(&buffer[i], 4);
	}

//    block = (CHAR64LONG16*)buffer;
    /* Copy context->state[] to working vars */
    
    a = state[0];
    b = state[1];
    c = state[2];
    d = state[3];
    e = state[4];
    /* 4 rounds of 20 operations each. Loop unrolled. */
	i=rol(block->l[0], 24);
    R0(a,b,c,d,e, 0); R0(e,a,b,c,d, 1); R0(d,e,a,b,c, 2); R0(c,d,e,a,b, 3);
    R0(b,c,d,e,a, 4); R0(a,b,c,d,e, 5); R0(e,a,b,c,d, 6); R0(d,e,a,b,c, 7);
    R0(c,d,e,a,b, 8); R0(b,c,d,e,a, 9); R0(a,b,c,d,e,10); R0(e,a,b,c,d,11);
    R0(d,e,a,b,c,12); R0(c,d,e,a,b,13); R0(b,c,d,e,a,14); R0(a,b,c,d,e,15);
    R1(e,a,b,c,d,16); R1(d,e,a,b,c,17); R1(c,d,e,a,b,18); R1(b,c,d,e,a,19);
    R2(a,b,c,d,e,20); R2(e,a,b,c,d,21); R2(d,e,a,b,c,22); R2(c,d,e,a,b,23);
    R2(b,c,d,e,a,24); R2(a,b,c,d,e,25); R2(e,a,b,c,d,26); R2(d,e,a,b,c,27);
    R2(c,d,e,a,b,28); R2(b,c,d,e,a,29); R2(a,b,c,d,e,30); R2(e,a,b,c,d,31);
    R2(d,e,a,b,c,32); R2(c,d,e,a,b,33); R2(b,c,d,e,a,34); R2(a,b,c,d,e,35);
    R2(e,a,b,c,d,36); R2(d,e,a,b,c,37); R2(c,d,e,a,b,38); R2(b,c,d,e,a,39);
    R3(a,b,c,d,e,40); R3(e,a,b,c,d,41); R3(d,e,a,b,c,42); R3(c,d,e,a,b,43);
    R3(b,c,d,e,a,44); R3(a,b,c,d,e,45); R3(e,a,b,c,d,46); R3(d,e,a,b,c,47);
    R3(c,d,e,a,b,48); R3(b,c,d,e,a,49); R3(a,b,c,d,e,50); R3(e,a,b,c,d,51);
    R3(d,e,a,b,c,52); R3(c,d,e,a,b,53); R3(b,c,d,e,a,54); R3(a,b,c,d,e,55);
    R3(e,a,b,c,d,56); R3(d,e,a,b,c,57); R3(c,d,e,a,b,58); R3(b,c,d,e,a,59);
    R4(a,b,c,d,e,60); R4(e,a,b,c,d,61); R4(d,e,a,b,c,62); R4(c,d,e,a,b,63);
    R4(b,c,d,e,a,64); R4(a,b,c,d,e,65); R4(e,a,b,c,d,66); R4(d,e,a,b,c,67);
    R4(c,d,e,a,b,68); R4(b,c,d,e,a,69); R4(a,b,c,d,e,70); R4(e,a,b,c,d,71);
    R4(d,e,a,b,c,72); R4(c,d,e,a,b,73); R4(b,c,d,e,a,74); R4(a,b,c,d,e,75);
    R4(e,a,b,c,d,76); R4(d,e,a,b,c,77); R4(c,d,e,a,b,78); R4(b,c,d,e,a,79);
    /* Add the working vars back into context.state[] */
    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;
    state[4] += e;
    /* Wipe variables */
    a = b = c = d = e = 0;

	delete block;
//    sMemFree((char *)block);
}

void CEMV::SHA1Invert(unsigned char *buf)
{
	unsigned char temp[4];

	temp[0] = buf[3];
	temp[1] = buf[2];
	temp[2] = buf[1];
	temp[3] = buf[0];

	memcpy(buf, temp, 4);
}




/*************************************************************/
/*  Function name     : memrev                               */
/*  Purpose           : Reverse a char array in the memory   */
/*  Input Parameter(s): unsigned char *indata data to reverse*/
/*                      int inlen     length of the data     */
/*  Output Parameter  : unsigned char *outdata               */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : RSAEncrypt                           */
/*************************************************************/
void CEMV::memrev(unsigned char *indata, unsigned char *outdata, int inlen)
{
	int i;

	for (i=0; i<inlen; i++)
		outdata[i] = indata[inlen-i-1];
}

/*************************************************************/
/*  Function name     : RSAEncrypt                           */
/*  Purpose           : RSA Encryption                       */
/*  Input Parameter(s):                                      */
/*                                                           */
/*  unsigned char ucPubKeyType                               */
/*  int PubKeyLen                                            */
/*  unsigned char *exp                                       */
/*  int expLen                                               */
/*  unsigned char *mesaj                                     */
/*  int mesajLen                                             */
/*                                                           */
/*  Output Parameter  : m_RecoveredData                      */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*************************************************************/
int CEMV::RSAEncrypt(unsigned char ucPubKeyType, int PubKeyLen, unsigned char *exp, int expLen, unsigned char *mesaj, int mesajLen)
{

	U_LONG *e, *c, *n, *m;
	UCHAR RevKey[256], RevMsg[256],PubKey[256];
	short int digit_size; 

	digit_size = sizeof(ULONG);
	mod_size = PubKeyLen / digit_size;
	if (PubKeyLen%digit_size) mod_size++;
	
	memset(RevKey, 0, 256);
	memset(RevMsg, 0, 256);

	switch (ucPubKeyType)
	{
		case CA_PUBLIC_KEY_MOD:
			memcpy(PubKey, m_CAPubKeyMod, PubKeyLen);
			break;
		case ICC_PUBLIC_KEY_MOD:
			memcpy(PubKey, m_ICCPubKeyMod, PubKeyLen);
			break;
		case ISS_PUBLIC_KEY_MOD:
			memcpy(PubKey, m_IssPubKeyMod, PubKeyLen);
			break;
		case ICC_PIN_ENC_PUBLIC_KEY_MOD:
			memcpy(PubKey, m_ICCPINEncPubKeyMod, PubKeyLen);
			break;
	}
	memrev(mesaj, RevMsg, mesajLen);
	memrev(PubKey, RevKey, PubKeyLen);

	
	e = new U_LONG[mod_size*digit_size];
	c = new U_LONG[mod_size*digit_size];
	n = new U_LONG[mod_size*digit_size];
	m = new U_LONG[mod_size*digit_size];

//	sMemAlloc(mod_size*digit_size,(char **)&e);
//	sMemAlloc(mod_size*digit_size,(char **)&c);
//	sMemAlloc(mod_size*digit_size,(char **)&n);
//	sMemAlloc(mod_size*digit_size,(char **)&m);


	memset(m,0,mod_size*digit_size);
	memset(n,0,mod_size*digit_size);
	memset(e,0,mod_size*digit_size);
	memset(c,0,mod_size*digit_size);

	memcpy(e, exp, expLen);
	memcpy(m, RevMsg, mesajLen);
	memcpy(n, RevKey, PubKeyLen);

	multiModExp(c, m, e, n, mod_size);

	memcpy(RevKey, c, PubKeyLen);
	memrev(RevKey, m_RecoveredData, PubKeyLen);

	delete e;
	delete c;
	delete n;
	delete m;

//	sMemFree((char *)e);
//	sMemFree((char *)c);
//	sMemFree((char *)n);
//	sMemFree((char *)m);
	
	return (TRUE);
}

/*************************************************************/
/*  Function name     : multiModExp                          */
/*  Purpose           : Modular exponentiation function      */
/*                      Calculates y = x^e mod m             */
/*  Input Parameter(s): U_LONG x[] operand                   */
/*                      U_LONG e[] exponent                  */
/*                      U_LONG m[] moduli                    */
/*                      unsigned int ndigits number of digits*/
/*  Output Parameter  : U_LONG y[] result                    */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : Binary left-to-right method          */
/*  Used by           : RSAEncrypt                           */
/*************************************************************/
int CEMV::multiModExp(U_LONG y[], U_LONG x[], U_LONG e[], U_LONG m[], unsigned int ndigits)
{
	
	U_LONG mask;
	unsigned int n;
	
	if (ndigits == 0) return -1;

	/* e deki ikinci en anlamlý biti bul */
	n = multiSizeof(e, ndigits);
	for (mask = HIBITMASK; mask > 0; mask >>= 1)
	{
		if (e[n-1] & mask)
			break;
	}
	multiNEXTBITMASK(mask, n);

	/* y = x */
	multiSetEqual(y, x, ndigits);

	
	while (n)
	{
		multiModMult(y, y, y, m, ndigits);		/* Kare */
		if (e[n-1] & mask)
			multiModMult(y, y, x, m, ndigits);	/* Çarp */
		
		/* Bir sonraki bite geç */
		multiNEXTBITMASK(mask, n);
	}

	return 0;
}

/*************************************************************/
/*  Function name     : multiSizeof                          */
/*  Purpose           : Returns size of significant digits   */
/*                      in a                                 */
/*  Input Parameter(s): U_LONG a[]                           */
/*                      unsigned int ndigits length of a     */
/*  Output Parameter  : ...                                  */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiModMult                         */
/*                      multiDivide                          */
/*************************************************************/
unsigned int CEMV::multiSizeof(U_LONG a[], unsigned int ndigits)
{	/*  a daki anlamlý digit sayýsýný döner */
	
	while(ndigits--)
	{
		if (a[ndigits] != 0)
			return (++ndigits);
	}
	return 0;
}

/*************************************************************/
/*  Function name     : multiSetEqual                        */
/*  Purpose           : Sets a = b                           */
/*  Input Parameter(s): U_LONG a[], U_LONG b[]               */
/*                      unsigned int ndigits number of digits*/
/*                                           in a and b      */
/*                                                           */
/*  Output Parameter  : ...                                  */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiModExp                          */
/*                      multiModulo                          */
/*                      multiDivide                          */
/*************************************************************/
void CEMV::multiSetEqual(U_LONG a[], U_LONG b[], unsigned int ndigits)
{	/* a = b yapar */
	unsigned int i;
	
	for (i = 0; i < ndigits; i++)
	{
		a[i] = b[i];
	}
}


/*************************************************************/
/*  Function name     : multiModMult                         */
/*  Purpose           : Modular multiplication unction       */
/*                      Computes a = (x * y) mod m           */
/*  Input Parameter(s): U_LONG x[] first operand             */
/*                      U_LONG y[] second operand            */
/*                      U_LONG m[] moduli                    */
/*                      unsigned int ndigits number of digits*/
/*  Output Parameter  : U_LONG a[] result                    */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiModExp                          */
/*************************************************************/
int CEMV::multiModMult(U_LONG a[], U_LONG x[], U_LONG y[], U_LONG m[], unsigned int ndigits)
{	/*	a = (x * y) mod m yi hesaplar*/
	
	
	U_LONG p[MAX_DIG_LEN * 2];

	/* p[2n] = x * y */
	multiMultiply(p, x, y, ndigits);

	
	multiModulo(a, p, ndigits * 2, m, ndigits);

	multiSetZero(p, ndigits * 2);
	return 0;
}

/*************************************************************/
/*  Function name     : multiMultiply                        */
/*  Purpose           : Multiplies two n digit numbers       */
/*                      Computes product w = u * v           */
/*  Input Parameter(s):	U_LONG u[], v[] numbers to multiply  */
/*                      unsigned int ndigits number of digits*/
/*                      in the multiplied numbers            */
/*                                                           */
/*  Output Parameter  : U_LONG w[] result of the             */
/*						multiplication (2n digits long)      */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : Knuth Vol 2 Ch 4.3.1 p253 Algorithm M*/
/*  Used by           : multiModMult                         */
/*************************************************************/
int CEMV::multiMultiply(U_LONG w[], U_LONG u[], U_LONG v[], unsigned int ndigits)
{
	/*	
		u, v : n digit multiprecision integer
		w    : 2n digit multiprecision integer
		w = u * v
	*/

	U_LONG k, t[2];
	unsigned int i, j, m, n;

	m = n = ndigits;

	
	/* Clear the result array*/
	for (i = 0; i < 2 * m; i++)
		w[i] = 0;

	for (j = 0; j < n; j++)
	{
		
		if (v[j] == 0)
		{
			w[j + m] = 0;
		}
		else
		{
			
			k = 0;
			for (i = 0; i < m; i++)
			{
				
				/* t = u_i * v_j + w_(i+j) + k */
				singleMultiply(t, u[i], v[j]);

				t[0] += k;
				if (t[0] < k)
					t[1]++;
				t[0] += w[i+j];
				if (t[0] < w[i+j])
					t[1]++;

				w[i+j] = t[0];
				k = t[1];
			}	
			
			w[j+m] = k;
		}
	}	

	return 0;
}

/*************************************************************/
/*  Function name     : multiModulo                          */
/*  Purpose           : Multiprecision modulation function   */
/*                      Calculates r = u mod v               */
/*  Input Parameter(s): U_LONG u[], U_LONG v[]   */
/*                      multiprecision integers              */
/*                      unsigned int udigits length of u     */
/*                      unsigned int vdigits length of v, r  */
/*  Output Parameter  : U_LONG r[]                           */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiModMult                         */
/*************************************************************/
int CEMV::multiModulo(U_LONG r[], U_LONG u[], unsigned int udigits, U_LONG v[], unsigned int vdigits)
{

	/* Double-length temp variable for divide fn */
	U_LONG qq[MAX_DIG_LEN * 2];
	/* Use a double-length temp for r to allow overlap of r and v */
	U_LONG rr[MAX_DIG_LEN * 2];

	/* rr[2n] = u[2n] mod v[n] */
	multiDivide(qq, rr, u, udigits, v, vdigits);

	multiSetEqual(r, rr, vdigits);
	multiSetZero(rr, udigits);
	multiSetZero(qq, udigits);

	return 0;
}

/*************************************************************/
/*  Function name     : multiSetZero                         */
/*  Purpose           : Clear an array to all zeros          */
/*  Input Parameter(s): U_LONG a[] array to zero             */
/*                      unsigned int ndigits number of digits*/
/*                                                           */
/*  Output Parameter  : ...                                  */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiModMult                         */
/*                      multiModulo                          */
/*                      multiDivide                          */
/*************************************************************/
void CEMV::multiSetZero(U_LONG a[], unsigned int ndigits)
{	/* a = 0 yapar */
	unsigned int i;
	
	for (i = 0; i < ndigits; i++)
	{
		a[i] = 0;
	}
}

/*************************************************************/
/*  Function name     : singleMultiply                       */
/*  Purpose           : Computes p = x * y                   */
/*  Input Parameter(s): U_LONG x, U_LONG y operands          */
/*  Output Parameter  : U_LONG p[2] result                   */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiMultSub                         */
/*                      multiMultiply                        */
/*                      QhatTooBig                           */
/*************************************************************/
int CEMV::singleMultiply(U_LONG p[2], U_LONG x, U_LONG y)
{	
	U_LONG x0, y0, x1, y1;
	U_LONG t, u, carry;

	/*	Split each x,y into two halves
		x = x0 + B*x1
		y = y0 + B*y1
		where B = 2^16, half the digit size
		Product is
		xy = x0y0 + B(x0y1 + x1y0) + B^2(x1y1)
	*/

	x0 = LOHALF(x);
	x1 = HIHALF(x);
	y0 = LOHALF(y);
	y1 = HIHALF(y);

	p[0] = x0 * y0;


	t = x0 * y1;
	u = x1 * y0;
	t += u;
	if (t < u)
		carry = 1;
	else
		carry = 0;

	carry = TOHIGH(carry) + HIHALF(t);

	t = TOHIGH(t);
	p[0] += t;
	if (p[0] < t)
		carry++;

	p[1] = x1 * y1;
	p[1] += carry;


	return 0;
}



/*************************************************************/
/*  Function name     : multiDivide                          */
/*  Purpose           : Computes quotient q = u / v and      */
/*                              remainder r = u mod v        */
/*  Input Parameter(s): U_LONG u[], U_LONG v[]               */
/*                      unsigned int udigits                 */
/*                      unsigned int vdigits                 */
/*                                                           */
/*  Output Parameter  : U_LONG q[], U_LONG r[]               */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : Knuth Vol 2 Ch 4.3.1 p257 Algorithm D*/
/*  Used by           : multiModulo                          */
/*************************************************************/
int CEMV::multiDivide(U_LONG q[], U_LONG r[], U_LONG u[], unsigned int udigits, U_LONG v[], unsigned int vdigits)
{	
	
	unsigned int shift;
	int n, m, j;
	U_LONG bitmask, overflow;
	U_LONG qhat, rhat, t[2];
	U_LONG *uu, *ww;
	int qhatOK, cmp;

	multiSetZero(q, udigits);
	multiSetZero(r, udigits);

	n = (int)multiSizeof(v, vdigits);
	m = (int)multiSizeof(u, udigits);
	m -= n;

	if (n == 0)
		return -1;	/* Sýfýra bölme */

	if (n == 1)
	{	
		r[0] = multiShortDiv(q, u, v[0], udigits);
		return 0;
	}

	if (m < 0)
	{	
		multiSetEqual(r, u, udigits);
		return 0;
	}

	if (m == 0)
	{	/* u ve v ayný boyda mý? */
		cmp = multiCompare(u, v, (unsigned int)n);
		if (cmp < 0)
		{	/* v > u*/
			multiSetEqual(r, u, udigits);
			return 0;
		}
		else if (cmp == 0)
		{	/* v == u */
			multiSetDigit(q, 1, udigits);
			return 0;
		}
	}

	bitmask = HIBITMASK;
	for (shift = 0; shift < BITS_PER_DIGIT; shift++)
	{
		if (v[n-1] & bitmask)
			break;
		bitmask >>= 1;
	}

	overflow = multiShiftLeft(v, v, shift, n);

	overflow = multiShiftLeft(r, u, shift, n + m);
	uu = r;	

	t[0] = overflow;

	for (j = m; j >= 0; j--)
	{
		qhatOK = 0;
		t[1] = t[0];
		t[0] = uu[j+n-1];
		overflow = singleDivide(&qhat, &rhat, t, v[n-1]);

		
		if (overflow)
		{	
			qhat = MAX_DIGIT;
			rhat = uu[j+n-1];
			rhat += v[n-1];
			if (rhat < v[n-1])	/* Taþma */
				qhatOK = 1;
		}
		if (!qhatOK && QhatTooBig(qhat, rhat, v[n-2], uu[j+n-2]))
		{	
			qhat--;
			rhat += v[n-1];
			if (!(rhat < v[n-1]))
				if (QhatTooBig(qhat, rhat, v[n-2], uu[j+n-2]))
					qhat--;
		}


		
		ww = &uu[j];
		overflow = multiMultSub(t[1], ww, v, qhat, (unsigned int)n);

		
		q[j] = qhat;
		if (overflow)
		{	
			q[j]--;
			overflow = multiAdd(ww, ww, v, (unsigned int)n);
		}

		t[0] = uu[j+n-1];

	}	


	for (j = n; j < m+n; j++)
		uu[j] = 0;

	multiShiftRight(r, r, shift, n);
	multiShiftRight(v, v, shift, n);

	return 0;
}

/*************************************************************/
/*  Function name     : multiShortDiv                        */
/*  Purpose           : Calculates quotient q = u div v      */
/*                      Returns remainder r = u mod v        */
/*  Input Parameter(s): U_LONG u[], U_LONG v                 */
/*                      unsigned int ndigits number of digits*/
/*                                           in q and u      */
/*  Output Parameter  : U_LONG q[] quotient                  */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : Knuth Vol 2 Ch 4.3.1 Exercise 16 p582*/
/*  Used by           : multiDivide                          */
/*************************************************************/
U_LONG CEMV::multiShortDiv(U_LONG q[], U_LONG u[], U_LONG v, unsigned int ndigits)
{

	unsigned int j;
	U_LONG t[2], r;
	unsigned int shift;
	U_LONG bitmask, overflow, *uu;

	if (ndigits == 0) return 0;
	if (v == 0)	return 0;	/* Sýfýra bölme */

	bitmask = HIBITMASK;
	for (shift = 0; shift < BITS_PER_DIGIT; shift++)
	{
		if (v & bitmask)
			break;
		bitmask >>= 1;
	}

	v <<= shift;
	overflow = multiShiftLeft(q, u, shift, ndigits);
	uu = q;
	
	r = overflow;
	j = ndigits;
	while (j--)
	{
		t[1] = r;
		t[0] = uu[j];
		overflow = singleDivide(&q[j], &r, t, v);
	}

	r >>= shift;
	
	return r;
}


/*************************************************************/
/*  Function name     : multiCompare                         */
/*  Purpose           : Returns sign of (a - b)              */
/*  Input Parameter(s): U_LONG a[], U_LONG b[] operands      */
/*                      unsigned int ndigits number of digits*/
/*                                           in a and b      */
/*  Output Parameter  : ...                                  */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiDivide                          */
/*************************************************************/
int CEMV::multiCompare(U_LONG a[], U_LONG b[], unsigned int ndigits)
{
	/*	(a - b) nin iþaretini döner
	*/

	if (ndigits == 0) return 0;

	while (ndigits--)
	{
		if (a[ndigits] > b[ndigits])
			return 1;	/* GT */
		if (a[ndigits] < b[ndigits])
			return -1;	/* LT */
	}

	return 0;	/* EQ */
}

/*************************************************************/
/*  Function name     : multiSetDigit                        */
/*  Purpose           : Sets a = d where d is a single digit */
/*  Input Parameter(s): U_LONG a[], U_LONG d                 */
/*                      unsigned int ndigits number of digits*/
/*                                          in a             */
/*  Output Parameter  : ...                                  */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiDivide                          */
/*************************************************************/
void CEMV::multiSetDigit(U_LONG a[], U_LONG d, unsigned int ndigits)
{	/* d tek digit iken a = d yapar */
	unsigned int i;
	
	for (i = 1; i < ndigits; i++)
	{
		a[i] = 0;
	}
	a[0] = d;
}


/*************************************************************/
/*  Function name     : multiShiftLeft                       */
/*  Purpose           : Computes a = b << x                  */
/*  Input Parameter(s): U_LONG b[] number to shift left      */
/*                      unsigned int x number of bits to     */
/*                                     shift left            */
/*                      unsigned int ndigits number of digits*/
/*                                           in a and b      */
/*                                                           */
/*  Output Parameter  : U_LONG a[] result                    */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiDivide                          */
/*                      multiShortDiv                        */
/*************************************************************/
U_LONG CEMV::multiShiftLeft(U_LONG a[], U_LONG b[], unsigned int x, unsigned int ndigits)
{	/* a = b << x yi hesaplar*/
	unsigned int i, y;
	U_LONG mask, carry, nextcarry;

	if (x >= BITS_PER_DIGIT)
		return 0;

	
	mask = HIBITMASK;
	for (i = 1; i < x; i++)
	{
		mask = (mask >> 1) | mask;
	}
	if (x == 0) mask = 0x0;
	
	y = BITS_PER_DIGIT - x;
	carry = 0;
	for (i = 0; i < ndigits; i++)
	{
		nextcarry = (b[i] & mask) >> y;
		a[i] = b[i] << x | carry;
		carry = nextcarry;
	}

	return carry;
}


/*************************************************************/
/*  Function name     : singleDivide                         */
/*  Purpose           : Computes quotient q = u / v,         */
/*                              remainder r = u mod v        */
/*                      where u is a double precision digit  */
/*	                    q, v, r are single precision digits. */
/*  Input Parameter(s): U_LONG u[2], U_LONG v operands       */
/*  Output Parameter  : U_LONG *q quotient                   */
/*                      U_LONG *r remainder                  */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : Knuth Vol 2 Ch 4.3.1 p257 Algorithm D*/
/*  Used by           : multiShortDiv                        */
/*                      multiDivide                          */
/*************************************************************/
U_LONG CEMV::singleDivide(U_LONG *q, U_LONG *r, U_LONG u[2], U_LONG v)
{	
	U_LONG qhat, rhat, t, v0, v1, u0, u1, u2, u3;
	U_LONG uu[2], q2;

	if (!(v & HIBITMASK))
	{
		*q = *r = 0;
		return MAX_DIGIT;
	}
	
	/* Split up into half-digits */
	v0 = LOHALF(v);
	v1 = HIHALF(v);
	u0 = LOHALF(u[0]);
	u1 = HIHALF(u[0]);
	u2 = LOHALF(u[1]);
	u3 = HIHALF(u[1]);

	qhat = u3 / v1;
	if (qhat > 0)
	{
		rhat = u3 - qhat * v1;
		t = TOHIGH(rhat) | u2;
		if (qhat * v0 > t)
			qhat--;
	}
	uu[1] = 0;		/* (u4) */
	uu[0] = u[1];	/* (u3u2) */
	if (qhat > 0)
	{
		singleMultSub(uu, qhat, v1, v0);
		if (HIHALF(uu[1]) != 0)
		{	
			qhat--;
			uu[0] += v;
			uu[1] = 0;
		}
	}
	q2 = qhat;

	t = uu[0];
	qhat = t / v1;
	rhat = t - qhat * v1;
	t = TOHIGH(rhat) | u1;
	if ((qhat == B) || (qhat * v0 > t))
	{
		qhat--;
		rhat += v1;
		t = TOHIGH(rhat) | u1;
		if ((rhat < B) && (qhat * v0 > t))
			qhat--;
	}

	uu[1] = HIHALF(uu[0]);	/* (0u3) */
	uu[0] = TOHIGH(LOHALF(uu[0])) | u1;	/* (u2u1) */
	singleMultSub(uu, qhat, v1, v0);
	if (HIHALF(uu[1]) != 0)
	{	
		qhat--;
		uu[0] += v;
		uu[1] = 0;
	}

	*q = TOHIGH(qhat);

	t = uu[0];
	qhat = t / v1;
	rhat = t - qhat * v1;
	t = TOHIGH(rhat) | u0;
	if ((qhat == B) || (qhat * v0 > t))
	{
		qhat--;
		rhat += v1;
		t = TOHIGH(rhat) | u0;
		if ((rhat < B) && (qhat * v0 > t))
			qhat--;
	}

	uu[1] = HIHALF(uu[0]);	/* (0u2) */
	uu[0] = TOHIGH(LOHALF(uu[0])) | u0;	/* (u1u0) */
	singleMultSub(uu, qhat, v1, v0);
	if (HIHALF(uu[1]) != 0)
	{	
		qhat--;
		uu[0] += v;
		uu[1] = 0;
	}

	/* q0 = qhat */
	*q |= LOHALF(qhat);

	*r = uu[0];
	return q2;
}

/*************************************************************/
/*  Function name     : QhatTooBig                           */
/*  Purpose           : Returns true if Qhat is too big      */
/*  Input Parameter(s): U_LONG qhat, U_LONG rhat,            */
/*                      U_LONG vn2, U_LONG ujn2              */
/*  Output Parameter  : ...                                  */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiDivide                          */
/*************************************************************/
//static int CEMV::QhatTooBig(U_LONG qhat, U_LONG rhat, U_LONG vn2, U_LONG ujn2)
int CEMV::QhatTooBig(U_LONG qhat, U_LONG rhat, U_LONG vn2, U_LONG ujn2)
{	/*	Qhat çok büyükse true döner...
		if (Qhat * Vn-2) > (b.Rhat + Uj+n-2)
	*/
	U_LONG t[2];

	singleMultiply(t, qhat, vn2);
	if (t[1] < rhat)
		return 0;
	else if (t[1] > rhat)
		return 1;
	else if (t[0] > ujn2)
		return 1;

	return 0;
}


/*************************************************************/
/*  Function name     : multiMultSub                         */
/*  Purpose           : Compute w = w - qv                   */
/*                      where w = (WnW[n-1]...W[0])          */
/*                      returns modified wn                  */
/*  Input Parameter(s): U_LONG w[], U_LONG v[], U_LONG q     */
/*                      unsigned int n                       */
/*  Output Parameter  : U_LONG wn                            */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiDivide                          */
/*************************************************************/
//static U_LONG CEMV::multiMultSub(U_LONG wn, U_LONG w[], U_LONG v[], U_LONG q, unsigned int n)
U_LONG CEMV::multiMultSub(U_LONG wn, U_LONG w[], U_LONG v[], U_LONG q, unsigned int n)
{

	U_LONG k, t[2];
	unsigned int i;

	if (q == 0)
		return wn;

	k = 0;

	for (i = 0; i < n; i++)
	{
		singleMultiply(t, q, v[i]);
		w[i] -= k;
		if (w[i] > MAX_DIGIT - k)
			k = 1;
		else
			k = 0;
		w[i] -= t[0];
		if (w[i] > MAX_DIGIT - t[0])
			k++;
		k += t[1];
	}

	wn -= k;

	return wn;
}


/*************************************************************/
/*  Function name     : multiAdd                             */
/*  Purpose           : Calculates w = u + v                 */
/*                      where w, u, v are multiprecision     */
/*						integers of ndigits each             */
/*		                Returns carry if overflow.           */
/*						Carry = 0 or 1.                      */
/*  Input Parameter(s): U_LONG u[], U_LONG v[] operands      */
/*                      unsigned int ndigits number of digits*/
/*                                           in u,v and w    */
/*  Output Parameter  : U_LONG w[] result                    */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : Knuth Vol 2 Ch 4.3.1 p251 Algorithm A*/
/*  Used by           : multiDivide                          */
/*************************************************************/
U_LONG CEMV::multiAdd(U_LONG w[], U_LONG u[], U_LONG v[], unsigned int ndigits)
{
	/*	w, u, v gibi n digit uzunluðunda multiprecision integer sayýlar için
		w = u + v yi hesaplar
		Taþma olursa eldeyi döner. Elde = 0 veya 1.
	*/

	U_LONG k;
	unsigned int j;

	
	k = 0;

	for (j = 0; j < ndigits; j++)
	{
		/*	w_j = (u_j + v_j + k)
			taþma varsa k = 1
		*/
		w[j] = u[j] + k;
		if (w[j] < k)
			k = 1;
		else
			k = 0;
		
		w[j] += v[j];
		if (w[j] < v[j])
			k++;

	}

	return k;	/* w_n = k */
}

/*************************************************************/
/*  Function name     : multiShiftRight                      */
/*  Purpose           : Computes a = b >> x                  */
/*  Input Parameter(s): U_LONG b[] number to shift right     */
/*                      unsigned int x number of bits to     */
/*                                     shift right           */
/*                      unsigned int ndigits number of digits*/
/*                                           in a and b      */
/*                                                           */
/*  Output Parameter  : U_LONG a[] result                    */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : multiDivide                          */
/*************************************************************/
U_LONG CEMV::multiShiftRight(U_LONG a[], U_LONG b[], unsigned int x, unsigned int ndigits)
{	/* a = b >> x yi hesaplar*/
	unsigned int i, y;
	U_LONG mask, carry, nextcarry;

	
	if (x >= BITS_PER_DIGIT)
		return 0;

	
	mask = 0x1;
	for (i = 1; i < x; i++)
	{
		mask = (mask << 1) | mask;
	}
	if (x == 0) mask = 0x0;
	
	y = BITS_PER_DIGIT - x;
	carry = 0;
	i = ndigits;
	while (i--)
	{
		nextcarry = (b[i] & mask) << y;
		a[i] = b[i] >> x | carry;
		carry = nextcarry;
	}

	return carry;
}

/*************************************************************/
/*  Function name     : singleMultSub                        */
/*  Purpose           : Compute uu = uu - q(v1v0)            */
/*                      where uu = u3u2u1u0, u3 = 0          */
/*  Input Parameter(s): U_LONG qhat, U_LONG v1, U_LONG v0    */
/*  Output Parameter  : U_LONG uu[2]                         */
/*  Data structures   : ...                                  */
/*  Used Algorithm(s) : ...                                  */
/*  Used by           : singleDivide                         */
/*************************************************************/
//static void CEMV::singleMultSub(U_LONG uu[2], U_LONG qhat, U_LONG v1, U_LONG v0)
void CEMV::singleMultSub(U_LONG uu[2], U_LONG qhat, U_LONG v1, U_LONG v0)
{
	/*	Compute uu = uu - q(v1v0) 
		where uu = u3u2u1u0, u3 = 0
		and u_n, v_n are all half-digits
		even though v1, v2 are passed as full digits.
	*/
	U_LONG p0, p1, t;

	p0 = qhat * v0;
	p1 = qhat * v1;
	t = p0 + TOHIGH(LOHALF(p1));
	uu[0] -= t;
	if (uu[0] > MAX_DIGIT - t)
		uu[1]--;
	uu[1] -= HIHALF(p1);
}



bool CEMV::WriteLogFile(DWORD BuffLen, LPBYTE BuffData)
{
	// Virtual Function
	// Must Define in derived class
	return true;
}


bool CEMV::WriteLogFile(CString title, CString logMessage)
{
	// Virtual Function
	// Must Define in derived class
	return true;
}

bool CEMV::WriteLogFile(CString logMessage)
{
	// Virtual Function
	// Must Define in derived class
	return true;
}

bool CEMV::WriteLogFile(CString title, DWORD index, CString logMessage)
{
	// Virtual Function
	// Must Define in derived class
	return true;
}

bool CEMV::WriteLogFile(CString title, const BYTE Tag[2], LPBYTE Address)
{
	// Virtual Function
	// Must Define in derived class
	return true;
}



