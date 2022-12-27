#include "StdAfx.h"
#include ".\isolib.h"


CIsoLib::CIsoLib(void): m_SW1(0),
						m_SW2(0)					
{
}

CIsoLib::~CIsoLib(void)
{
}

BYTE CIsoLib::SELECT(LPBYTE pucAppName, BYTE ucAppLen, BOOL MultOccurence)
{
	BYTE	resp;
	
	memset(&m_Apdu,0,sizeof(m_Apdu));

	m_Apdu.CLA = 0x00;
	m_Apdu.INS = 0xA4;
	m_Apdu.P1 = 0x04;
	m_Apdu.P2 = 0x00;
  	if( MultOccurence ) m_Apdu.P2 = 0x02;
	m_Apdu.Lc = ucAppLen;
	if( m_protocol==0 )	m_Apdu.Le = NOT_PRESENT;
	else m_Apdu.Le = 0x00;
	
  	memcpy(m_Apdu.send_data, pucAppName, ucAppLen);

	resp = SendData();
    if (resp != PROCESS_OK)
		return resp;

    return PROCESS_OK;
}

BYTE CIsoLib::READ_RECORD(BYTE ucSFI, BYTE ucRecordNo)
{
	BYTE	resp;

	memset( &m_Apdu , 0 , sizeof(m_Apdu) );
	m_Apdu.CLA = 0x00;
	m_Apdu.INS = 0xB2;
	m_Apdu.P1 = ucRecordNo;
	m_Apdu.P2 = ucSFI+4;
	m_Apdu.Lc = NOT_PRESENT;
	m_Apdu.Le = 0x00;
	resp = SendData();
	return resp;
}


BYTE CIsoLib::GET_DATA( INT iNameOfData )
{
	BYTE resp;

	memset (&m_Apdu,0,sizeof(m_Apdu));
	
	m_Apdu.CLA = 0x80;
	m_Apdu.INS = 0xCA;
	m_Apdu.P1 = 0x9F;
  	
	switch (iNameOfData)
  	{
  		case GET_PIN_TRY_COUNTER:
			m_Apdu.P2 = 0x17;
	  		break;
  		case GET_ATC:
			m_Apdu.P2 = 0x36;
	  		break;
  		case GET_LAST_ONL_ATC:
			m_Apdu.P2 = 0x13;
	  		break;
		case GET_OFFLINE_BALANCE:
			m_Apdu.P2 = 0x50;
			break;
  	}
	m_Apdu.Lc = NOT_PRESENT;
	m_Apdu.Le = 0x00;

	resp = SendData();

	return resp;
}


BYTE CIsoLib::GET_PROCESSING_OPTIONS(LPBYTE pPDOLData, BYTE ucPDOLDataLen)
{
	BYTE	resp;
	
	memset( &m_Apdu,0,sizeof(m_Apdu) );
	m_Apdu.CLA = 0x80;
	m_Apdu.INS = 0xA8;
	m_Apdu.P1 = 0x0;
	m_Apdu.P2 = 0x0;
	m_Apdu.Lc = ucPDOLDataLen;
	if( m_protocol==0 )	m_Apdu.Le = NOT_PRESENT;
	else m_Apdu.Le = 0x00;

	memcpy( m_Apdu.send_data, pPDOLData, ucPDOLDataLen);

	resp = SendData();
	if (resp != PROCESS_OK)
		return resp;
	return PROCESS_OK;
}


BYTE CIsoLib::GET_RESPONSE( BYTE Le )
{
	BYTE	resp;
	memset( &m_Apdu,0, sizeof(m_Apdu));
	m_Apdu.CLA = 0x00;
	m_Apdu.INS = 0xC0;
	m_Apdu.P1 = 0x00;
	m_Apdu.P2 = 0x00;
	m_Apdu.Lc = NOT_PRESENT;
	m_Apdu.Le = Le;

	resp = SendData();
	return resp;
}


BYTE CIsoLib::INTERNAL_AUTHENTICATE(LPBYTE ucAuthData, BYTE ucAuthDataLen)
{
	BYTE	resp;

	memset (&m_Apdu,0,sizeof(m_Apdu));

	m_Apdu.CLA = 0x00;
	m_Apdu.INS = 0x88;
	m_Apdu.P1 = 0x00;
	m_Apdu.P2 = 0x00;
	m_Apdu.Lc = ucAuthDataLen;
	if( m_protocol==0 )	m_Apdu.Le = NOT_PRESENT;
	else m_Apdu.Le = 0x00;
  	memcpy(m_Apdu.send_data, ucAuthData, ucAuthDataLen);
	resp = SendData();
	return resp;
}


BYTE CIsoLib::GET_CHALLENGE( void )
{
	BYTE    resp;

	memset( &m_Apdu,0,sizeof(m_Apdu) );
	m_Apdu.CLA = 0x00;
	m_Apdu.INS = 0x84;
	m_Apdu.P1 = 0x00;
	m_Apdu.P2 = 0x00;
	m_Apdu.Lc = NOT_PRESENT;
	if( m_protocol==0 )	m_Apdu.Le = NOT_PRESENT;
	else m_Apdu.Le = 0x00;
	resp = SendData();

	return resp;

}


BYTE CIsoLib::VERIFY_PIN(BYTE TypeOfPIN, LPBYTE ucPINData, BYTE ucPINLen)
{
	BYTE	resp;
	memset( &m_Apdu,0,sizeof(m_Apdu) );
	m_Apdu.CLA = 0x00;
	m_Apdu.INS = 0x20;
	m_Apdu.P1 = 0x00;
	m_Apdu.P2 = TypeOfPIN;
	m_Apdu.Lc = ucPINLen;
	m_Apdu.Le = NOT_PRESENT;
  	memcpy( m_Apdu.send_data, ucPINData, ucPINLen);

	resp = SendData();
	return resp;
}


BYTE CIsoLib::GENERATE_AC( LPBYTE ucCDOLData, BYTE ucCDOLDataLen, BYTE ucCryptInfData )
{
	BYTE	resp;
	memset( &m_Apdu, 0, sizeof(m_Apdu) );
	m_Apdu.CLA = 0x80;
	m_Apdu.INS = 0xAE;
	m_Apdu.P1 = ucCryptInfData;
	m_Apdu.P2 = 0x0;
	m_Apdu.Lc = ucCDOLDataLen;
	if( m_protocol==0 )	m_Apdu.Le = NOT_PRESENT;
	else m_Apdu.Le = 0x00;
  	memcpy( m_Apdu.send_data, ucCDOLData, ucCDOLDataLen );

	resp = SendData();

	if (resp != PROCESS_OK)
		return resp;

	return PROCESS_OK;

}


BYTE CIsoLib::EXTERNAL_AUTHENTICATE( LPBYTE IssuerAuthData )
{
	BYTE	resp;

	memset( &m_Apdu,0,sizeof(m_Apdu) );
	
	m_Apdu.CLA = 0x00;
	m_Apdu.INS = 0x82;
	m_Apdu.P1 = 0x00;
	m_Apdu.P2 = 0x00;
	m_Apdu.Lc = IssuerAuthData[0];
	m_Apdu.Le = NOT_PRESENT;
  	memcpy( m_Apdu.send_data, &IssuerAuthData[1], IssuerAuthData[0] );

	resp = SendData();

	return resp;
}




BYTE CIsoLib::SendData( void )
{
	BYTE	ucRet;
    WORD	usOutLen = MAX_DATA_LEN;
    WORD	usCmdLen;
	BYTE	ucCardReplyData[MAX_DATA_LEN];
	BYTE	ucCardSendData[MAX_DATA_LEN];
    int		iIndex=0;

  	
    memset(ucCardReplyData, 0, MAX_DATA_LEN);
    memset(ucCardSendData, 0, MAX_DATA_LEN); 

    
    ucCardSendData[iIndex++] = m_Apdu.CLA;
    ucCardSendData[iIndex++] = m_Apdu.INS;
    ucCardSendData[iIndex++] = m_Apdu.P1;
    ucCardSendData[iIndex++] = m_Apdu.P2;
    if( m_Apdu.Lc != NOT_PRESENT )
	{
		ucCardSendData[iIndex++] = m_Apdu.Lc;
        memcpy(&ucCardSendData[iIndex], m_Apdu.send_data, m_Apdu.Lc);
	    iIndex += m_Apdu.Lc;
	}
    if( m_Apdu.Le != NOT_PRESENT )
	    ucCardSendData[iIndex++] = m_Apdu.Le;
   
   	usCmdLen = iIndex;

	ucRet = SendSmartData( usCmdLen, ucCardSendData, usOutLen, ucCardReplyData );

    if(ucRet != PROCESS_OK)
    {
		m_SW1 = ucCardReplyData[usOutLen-2];
		m_SW2 = ucCardReplyData[usOutLen-1];

        return ucRet; 
    }
    else
    {
		memcpy( m_Apdu.read_data, ucCardReplyData, usOutLen );

		m_Apdu.read_len = usOutLen;

		m_SW1 = ucCardReplyData[usOutLen-2];
		m_SW2 = ucCardReplyData[usOutLen-1];

		return PROCESS_OK;
	}
}

BYTE CIsoLib::SendSmartData(WORD SendLen, LPBYTE CardSendData, WORD &OutLen, LPBYTE CardReplyData)
{
	// Virtual Function
	// Must Define in derived class
	return PROCESS_OK;
}


