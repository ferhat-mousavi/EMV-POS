//***********************************************************************
//* ISO COMMANDS FOR SMARTCARDS											*
//*																		*
//* Copyright (C) Verisoft Bilgi Islem 2006								*
//* All rights reserved.												*
//* 																	*
//*																		*
//* Provided by:														*
//*		Ferhat Mousavi													*
//*																		*
//*	Environment:														*
//*		Visual C++ 2003													*
//***********************************************************************
#pragma once


// Return Codes
#define PROCESS_OK 						100
#define SET_PROTOCOL_ERROR 				101
#define CARD_COM_ERROR 					102
#define CARD_REJECTED 					103
#define TERM_PARAM_NOT_SET 				104
#define NO_MATCHING_APP					105
#define DATA_FORMAT_INCORRECT			106
#define ISS_COD_TBL_OUT_OF_RANGE		107
#define DUPLICATE_CARD_DATA_ELEMENT		108
#define GET_AMOUNT_ERROR 				109
#define AMOUNT_CANCELLED 				110
#define LEN_INCORRECT 					111
#define AIP_NOT_RECEIVED 				112
#define AFL_NOT_RECEIVED 				113
#define AFL_LEN_OUT_OF_RANGE 			114
#define SFI_OUT_OF_RANGE 				115
#define AFL_INCORRECT 					116
#define EXP_DATE_INCORRECT 				117
#define EFF_DATE_INCORRECT 				118
#define MISSING_MANDATORY_OBJECT 		119
#define CA_PUBKEY_NOT_FOUND 			120
#define CVMLIST_LEN_INCORRECT 			121
#define CRYPTOGRAM_TYPE_INCORRECT		122
#define SERVIC_NOT_ALLOWED 				123
#define APPLIST_PARSE_ERROR 			124
#define NO_SELECTED_APP					125
#define CARD_ERROR						126
#define PSE_NOT_SUPPORTED_BY_CARD		127
#define COND_NOT_SATISFIED				128
#define NO_TERM_APP						129
#define CARD_CHECK_ERROR				130
#define APP_SELECT_PSE_ERROR			131
#define DATA_ELEMENT_OUT_OF_RANGE		132
#define NO_BIN_PERMISSION				133
#define EXTRACT_ERROR					134	
#define PIN_TRY_LIMIT_EXC				135
#define FILE_CORRUPT					136
#define INS_NOT_SUPPORTED				137
#define CLA_NOT_SUPPORTED				138
#define WRONG_LENGTH					139
#define NOT_ENOUGH_SPACE				140
#define INCORRECT_P1P2					141
#define FCP_PARAMETERS_INCORRECT		142
#define SECURITY_NOT_SATISFY			143
#define CONDITION_NOT_SATISFY			144
#define FILE_ALREADY_EXISTS				145
#define DF_NAME_ALREADY_EXISTS			146
#define MEMORY_FAILURE					147
#define SELECTED_FILE_INVALIDATED		148
#define FILE_NOT_FOUND					149
#define AUTHENTICATION_BLOCKED			150
#define AUTHENTICATION_FAILURE			151
#define VERIFICATION_FAILURE			152
#define REFERANCE_NOT_FOUND				153
#define COMMAND_NOT_ALLOWED				154

// same in EMV.h
// GET DATA Parameters
#define GET_PIN_TRY_COUNTER	0
#define GET_ATC				1
#define GET_LAST_ONL_ATC	2
#define GET_OFFLINE_BALANCE	3


// same in EMV.h
#define NOT_PRESENT					0x000000FF
#define MAX_DATA_LEN				512


typedef struct
{
	unsigned char	CLA;
	unsigned char	INS;
	unsigned char	P1;
	unsigned char	P2;
	unsigned char	Lc;
	unsigned char	send_data[MAX_DATA_LEN];
	unsigned char	Le;
	unsigned char	read_data[MAX_DATA_LEN];
	int		        read_len;
	unsigned char	SW1;
	unsigned char	SW2;
}T0_APDU;


class CIsoLib
{
public:


	CIsoLib(void);
	~CIsoLib(void);

	T0_APDU m_Apdu;
	BYTE	m_SW1,m_SW2;

	int		m_protocol;


	BYTE SELECT(LPBYTE pucAppName, BYTE ucAppLen, BOOL MultOccurence);
	BYTE READ_RECORD(BYTE ucSFI, BYTE ucRecordNo);
	BYTE GET_DATA( INT iNameOfData );
	BYTE GET_PROCESSING_OPTIONS(LPBYTE pPDOLData, BYTE ucPDOLDataLen);
	BYTE GET_RESPONSE( BYTE Le );
	BYTE INTERNAL_AUTHENTICATE(LPBYTE ucAuthData, BYTE ucAuthDataLen);
	BYTE GET_CHALLENGE( void );
	BYTE VERIFY_PIN(BYTE TypeOfPIN, LPBYTE ucPINData, BYTE ucPINLen);
	BYTE GENERATE_AC( LPBYTE ucCDOLData, BYTE ucCDOLDataLen, BYTE ucCryptInfData );
	BYTE CIsoLib::EXTERNAL_AUTHENTICATE( LPBYTE IssuerAuthData);

	BYTE SendData( void );		
	virtual BYTE SendSmartData(WORD SendLen, LPBYTE CardSendData, WORD &OutLen, LPBYTE CardReplyData); // Virtual Function. Must Define in derived class (Ferhat)

};
