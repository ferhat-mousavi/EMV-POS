//***********************************************************************
//* EMV Class															*
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

#define PRE_AUTHORIZED_MAESTRO

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
#define GET_AMOUNT_ABORT				155
#define OFFLINE_NOT_ACCEPTED			156


// The Tag list definition is necessary for the Generic module
// If a tag will be changed the value is modified here and the
// Generic module is not modified
// TAG DEFINITION

#define TAG_AppIdentIcc         0x004F /* Application Identifier (AID)      */
#define TAG_AppLab              0x0050 /* Application Label                 */
#define TAG_CmdToPerf           0x0052 /* Command tp Perform                */
#define TAG_Trk2EquDat          0x0057 /* Track 2 Equivalent Date           */
#define TAG_AppPan              0x005A /* Application Primary Account       */
                                       /*    Number (PAN)                   */
#define TAG_CarHolNam           0x5F20 /* Cardholder Name                   */
#define TAG_AppExpDat           0x5F24 /* Application expiration Date       */
#define TAG_AppEffDat           0x5F25 /* Application Effective Date        */
#define TAG_IssCouCod           0x5F28 /* Issuer Country Code               */
#define TAG_TraCurCod           0x5F2A /* Transaction Currency Code         */
#define TAG_LanPre              0x5F2D /* Language Preference               */
#define TAG_SerCod              0x5F30 /* Service Code                      */
#define TAG_AppPanSeqNbr        0x5F34 /* Application Primary Account Number*/
                                       /*     (PAN) Sequence Number         */
#define TAG_TraCurExp           0x5F36 /* Transaction Currency Exponent     */
#define TAG_AppTemplate         0x0061 /* Application Template              */
#define TAG_FCITemplate         0x006F /* File Control Information (FCI)    */
                                       /*     Template                      */
#define TAG_AEFTemplate         0x0070 /* Application Elementary File (AEF) */
                                       /*     Data Template                 */
#define TAG_IssuerScript1       0x0071 /* Issuer Script Template 1          */
#define TAG_IssuerScript2       0x0072 /* Issuer Script Template 2          */
#define TAG_DirDisTmp           0x0073 /* Directory Discretionary Template  */
#define TAG_RespMesTmp2         0x0077 /* Response Message Template Format 2*/
#define TAG_RespMesTmp1         0x0080 /* Response Message Template Format 1*/
#define TAG_AmtAuthorBin        0x0081 /* Amount, Authorised (Binary)       */
#define TAG_AppIntPro           0x0082 /* Application Interchange Profile   */
#define TAG_CmdeTemplate        0x0083 /* Command Template                  */
#define TAG_DFName              0x0084 /* Dedicated File (DF) Name          */
#define TAG_IssuerScriptCmde    0x0086 /* Issuer Script Command             */
#define TAG_AppPriInd           0x0087 /* Application Priority Indicator    */
#define TAG_SFI                 0x0088 /* Short File Identifier (SFI)       */
#define TAG_AuthoCode           0x0089 /* Authorisation Code                */
#define TAG_AuthoRespCode       0x008A /* Authorisation Response Code       */
#define TAG_CDOL1               0x008C /* Card Risk Management Data Object  */
                                       /*    List 1 (CDOL1)                 */
#define TAG_CDOL2               0x008D /* Card Risk Management Data Object  */
                                       /*    List 2 (CDOL2)                 */
#define TAG_CVMList             0x008E /* Cardholder Verification Metod     */
                                       /*    (CVM) List                     */
#define TAG_CerAutPubKeyIndIcc  0x008F /* Certification Authority Public Key*/
                                       /*    Index                          */
#define TAG_IssPubKeyCer        0x0090 /* Issuer Public Key Certificat      */
#define TAG_IssAuthDat          0x0091 /* Issuer Authentication Data        */
#define TAG_IssPubKeyRem        0x0092 /* Issuer Public Key Remainder       */
#define TAG_SigStaAppDat        0x0093 /* Signed Static Application Data    */
#define TAG_AppFilLoc           0x0094 /* Application File Locator (AFL)    */
#define TAG_TerVerRes           0x0095 /* Terminal Verification Results     */
#define TAG_TDOL                0x0097 /* Transaction Certificate Data      */
                                       /*    Object List (TDOL)             */
#define TAG_TCHashVal           0x0098 /* Transaction Certificate (TC) Hash */
                                       /*    Value                          */
#define TAG_TraPINDat           0x0099 /* Transaction Personal Identificati-*/
                                       /*    on Number (PIN) Data           */
#define TAG_TraDat              0x009A /* Transactin Datec                  */
#define TAG_TraStaInf           0x009B /* Transaction Status Information    */
#define TAG_TraType             0x009C /* Transaction Type                  */
#define TAG_DDFName             0x009D /* Directory Definition File (DDF)   */
                                       /*    Name                           */
#define TAG_AcqID               0x9F01 /* Acquirer Identifier               */
#define TAG_AmtAuthorNum        0x9F02 /* Amount, Authorised (Numeric)      */
#define TAG_AmtOtherNum         0x9F03 /* Amount, Other (Numeric)           */
#define TAG_AmtOtherBin         0x9F04 /* Amount, Other (Binary)            */
#define TAG_AppDisDat           0x9F05 /* Application Discretionary Data    */
#define TAG_AIDTer              0x9F06 /* Application Identifier (AID)      */
#define TAG_AppUsaCon           0x9F07 /* Application Usage Controm         */
#define TAG_AppVerNbrICC        0x9F08 /* Application Version Number (card) */
#define TAG_AppVerNbrTer        0x9F09 /* Application Version Number (term) */
#define TAG_CarHolNamExt        0x9F0B /* Cardholder Name - Extended        */
#define TAG_IssActCodDef        0x9F0D /* Issuer Action Code - Default      */
#define TAG_IssActCodDen        0x9F0E /* Issuer Action Code - Denial       */
#define TAG_IssActCodOnl        0x9F0F /* Issuer Action Code - online       */
#define TAG_IssAppDat           0x9F10 /* Issuer Application Data           */
#define TAG_IssCodTabInd        0x9F11 /* Issuer Code Table Index           */
#define TAG_AppPreNam           0x9F12 /* Application Preferred Name        */
#define TAG_LasOnlATCReg        0x9F13 /* Last Online Application Transacti-*/
                                       /*    on Counter(ATC) Registr        */
#define TAG_LowConOffLim        0x9F14 /* Lower Consecutive Offline Limit   */
#define TAG_MerCatCod           0x9F15 /* Merchant Category Code            */
#define TAG_MerID               0x9F16 /* Merchant Identifier               */
#define TAG_PinTryCou           0x9F17 /* Personal Identification Number    */
                                       /*    (PIN) Try Counter              */
#define TAG_IssuerScriptID      0x9F18 /* Issuer Script Identifier          */
#define TAG_TerCouCod           0x9F1A /* Terminal Country Code             */
#define TAG_TerFloorLimit       0x9F1B /* Terminal Floor Limit              */
#define TAG_TerID               0x9F1C /* Terminal Identification           */
#define TAG_TerRiskManDat       0x9F1D /* Terminal Risk Management Data     */
#define TAG_IFDSerNum           0x9F1E /* Interface Device (IFD) Serial     */
                                       /*     Number                        */
#define TAG_Trk1DisDat          0x9F1F /* Track 1 Discretionary Data        */
#define TAG_Trk2DisDat          0x9F20 /* Track 2 Discretionary Data        */
#define TAG_TraTim              0x9F21 /* Transaction Time                  */
#define TAG_CerAutPubKeyIndTer  0x9F22 /* Certification Authority Public Key*/
                                       /*     Index                         */
#define TAG_UppConOffLim        0x9F23 /* Upper Consecutive Offline Limit   */
#define TAG_AppCryptogram       0x9F26 /* Application Cryptogram            */
#define TAG_CryptInfDat         0x9F27 /* Cryptogramm Information Data      */
#define TAG_ICCPinPubKeyCer     0x9F2D /* ICC PIN Encipherment Public Key   */
                                       /*     Certificate                   */
#define TAG_ICCPinPubKeyExp     0x9F2E /* ICC PIN Encipherment Public Key   */
                                       /*     Exponent                      */
#define TAG_ICCPinPubKeyRem     0x9F2F /* ICC PIN Encipherment Public Key   */
                                       /*     Remainder                     */
#define TAG_IssPubKeyExp        0x9F32 /* Issuer Public Key Exponent        */
#define TAG_TerCap              0x9F33 /* Termonal Capabilities             */
#define TAG_CVMResults          0x9F34 /* Cardholder Verification Method    */
                                       /*     (CVM) Result                  */
#define TAG_TerTyp              0x9F35 /* Terminal Type                     */
#define TAG_AppTraCou           0x9F36 /* Application Trznsaction Counter   */
                                       /*     (ATC)                         */
#define TAG_UnpreNumber         0x9F37 /* Unpredictable Number              */
#define TAG_PDOL                0x9F38 /* Processing Options Data Object    */
                                       /*     List (PDOL)                   */
#define TAG_POSEntryMod         0x9F39 /* Point-of-Service (POS) Entry Mode */
#define TAG_AmtRefCur           0x9F3A /* Amount, Reference Currency        */
#define TAG_AppRefCur           0x9F3B /* Application Reference Currency    */
#define TAG_TraRefCurCod        0x9F3C /* Transaction Reference Currency    */
#define TAG_TraRefCurExp        0x9F3D /* Trancaction Reference Currency    */
                                       /*     Exponent                      */
#define TAG_AddTerCap           0x9F40 /* Additional Teminal Capabilities   */
#define TAG_TraSeqCou           0x9F41 /* Transaction seauence Counter      */
#define TAG_AppCurCod           0x9F42 /* Application Currency Code         */
#define TAG_AppRefCurExp        0x9F43 /* Application Reference Currency    */
                                       /*     Exponent                      */
#define TAG_AppCurExp           0x9F44 /* Application Currency Exponent     */
#define TAG_DatAuthCod          0x9F45 /* Data Authentication Code          */
#define TAG_ICCPubKeyCer        0x9F46 /* ICC Public Key Certificate        */
#define TAG_ICCPubKeyExp        0x9F47 /* ICC Public Key Exponent           */
#define TAG_ICCPubKeyRem        0x9F48 /* ICC Public Key Remainder          */
#define TAG_DDOL                0x9F49 /* Dynamic Data Object List (DDOL)   */
#define TAG_StaDatAuthTagLst    0x9F4A /* Static Data Authentication Tag    */
                                       /*     List                          */
#define TAG_SigDynAppDat        0x9F4B /* Signed Dynamic Application Data   */
#define TAG_ICCDynNum           0x9F4C /* ICC Dynamic Number                */
#define TAG_ADA                 0x9F52 /* ADA !!!sel???*/
#define TAG_TraCatCode          0x9F53 /* Tansaction Category Code          */
                                       /*   !!!! Europay only !!!!          */
                                       /*   !!!! NOT used in Generic !!!!   */
#define TAG_FCIPropTmp          0x00A5 /* File Control Information (FCI)    */
                                       /*     Proprietary Template          */
#define TAG_FCIIssDisDat        0xBF0C /* File Control Information (FCI)    */
                                       /*     Issuer Discretionary Data     */

// The Tag list definition is necessary for the Generic module
// If a tag will be changed the value is modified here and the
// Generic module is not modified
// TAG DEFINITION starting to DF80, end DFFE

// Proprietary Tags :

#define TAG_Language            0xDF80 /* Languages defined in the terminal */
                                       /*     (according to ISO 639)        */
#define TAG_MerNam              0xDF81 /* Merchant Name                     */
#define TAG_MerLoc              0xDF82 /* Merchant Location                 */
#define TAG_TerActCodDef        0xDF83 /* Terminal Action Code - Default    */
#define TAG_TerActCodDen        0xDF84 /* Terminal Action Code - Denial     */
#define TAG_TerActCodOnl        0xDF85 /* Terminal Action Code - Online     */
#define TAG_ReferralRequired    0xDF86
#define TAG_Threshold           0xDF87 /* Threshold Value for Biased Random */
                                       /*     Selection                     */
#define TAG_TargetPercent       0xDF88 /* Target Percentage to be used for  */
                                       /*     Random Selection              */
#define TAG_MaxTarget           0xDF89 /* Maximum Target Percentage to be   */
                                       /*     used for Biased Random        */
                                       /*     Selection                     */
#define TAG_PinResult           0xDF8A
#define TAG_TerOptSelGen        0xDF8B /* Terminal options (online forced,  */
                                       /*     amount acquisition ,easy entry*/
                                       /*     management)                   */
#define TAG_TerminalOptGen      0xDF8C
#define TAG_AIDTerList          0xDF8D
#define TAG_DEBUGTrace          0xDF8E /* Code for printing trace required  */
                                       /*     by VISA and useful in any appl*/
#define TAG_TAGErrDisplay       0xDF8F

#define TAG_SignatRequired      0xDF90
#define TAG_IssScriptRes        0xDF92 /* Issuer Script Results             */
//#define TAG_LanguageUsed        0xDF92  Language used in the transaction  
                                       /*     flow (cardholder language)    */
#define TAG_EasyEntryCard       0xDF93
#define TAG_TraTypSrv           0xDF94
#define TAG_DDOL_Default        0xDF95 /* Default Dynamic Data Authenticati-*/
                                       /*     on Data Object list (DDOL)    */
#define TAG_AuthoRespCod_List   0xDF96 /* Authorisation Response Codes List */
                                       /*     define by the acquirer        */
#define TAG_Flag_Auto           0xDF97 /* Flag for Forcing the Online tran- */
                                       /*     saction, from the Associate   */
#define TAG_TDOL_Default        0xDF98 /* Default Transaction Certificate   */
                                       /*     Data Object List (TDOL)       */


// !!!  The following constant are used in i_init.c !!!
// Old specific Tag ... The values are fixed in the MP3S protocole !!!

#define TAG_TabTerFloorLimit    0xDF99          /* CM 000214 These values must not be changed */
#define TAG_TabThreshold        0xDF9A
#define TAG_TerOptSelAss        0xDF9B
#define TAG_TerminalOptAss      0xDF9C
#define TAG_ReversalPIN         0xDF9E
#define TAG_Key_Rsa             0xDF9F

#define TAG_Key_ODOL            0xDFA0





#define BASEDEC   						10
#define BASEHEX   						16



#include "IsoLib.h"

typedef struct
{
	char * pcText; 		// item text
	BYTE ucVal;			// item index
} CHIPMENU;


typedef struct 
{
	BYTE	ucRid[5];
	BYTE	ucPKExp[3];
	BYTE	ucPKExpLen;		//1 or 3
	BYTE	ucPKModulo[256];
	BYTE	ucPKModuloLen;
	BYTE	ucPKIndex;
} CAKEYS;


//*****************************************************************************************
#pragma once

#define PRIMENUMBER(p)					(p%2==1)


// Max Lengths
#define	MAX_MODULUS_LEN				256
#define	MAX_ISSUER_SCRIPT_LEN		128
#define	MAX_PDOL_LEN				128
#define	MAX_SDA_TAG_LIST_LEN		128

#define MAX_TAG_COUNT				116

#define MAX_DATA_LEN				512 // same in IsoLib.h
#define MAX_MATCHING_APP_CNT 		10

// APP Len ranges
#define	MIN_APP_LEN		5
#define	MAX_APP_LEN		16

#define APP_INF_LEN					18	//Application Selection Indicator

#define MAX_TERMINAL_APP_CNT 		6

// Application Selection Types
#define	SELECT_PSE					0
#define	SELECT_DDF					1
#define	SELECT_ADF					2

#define	APP_SELECT_PSE				0
#define	APP_SELECT_LIST_OF_AID		1

// GENERATE AC Cryptogram Information Types
#define	AAC							0x00	// Application Authentication Cryptogram (Transaction declined)
#define	TC							0x40	// Transaction Certificate (Transaction approved)
#define	ARQC						0x80	// Authorisation Request Cryptogram (Online authorisation requested)
#define	AAR							0xC0	// Application Authorisation Referral (Referral requested by the card)

// same in IsoLib.h
// GET DATA Parameters
#define GET_PIN_TRY_COUNTER	0
#define GET_ATC				1
#define GET_LAST_ONL_ATC	2
#define GET_OFFLINE_BALANCE	3


#define MAX_DOL_LEN				512

#define	SERVICE_NOT_ALLOWED			0x01
#define	PIN_TRY_LIMIT_EXCEEDED		0x02

#define NOT_PRESENT					0x000000FF	// Same in IsoLib.h

#define STACK_EMPTY					0
#define STACK_FULL					1


// Data Sources
#define CARD		'C'
#define ISSUER		'I'
#define TERMINAL	'T'
#define CARD2		'D'

#define	MAX_SAD_LEN		  	512

#define MAX_ISS_SCRIPT_CNT   5
#define MAX_ISS_SCRIPT_LEN   128

// DOL Types
#define	DOL_PDOL	0
#define	DOL_CDOL1	1
#define	DOL_CDOL2	2
#define	DOL_TDOL	3
#define	DOL_DDOL	4


// Card Brands
#define	BRAND_VISA			1
#define	BRAND_EUROPAY		2
#define	BRAND_MASTER		3

#define PUB_KEY_MODULO_LEN		256
#define HASH_DATA_MODULO_LEN	512


#define	CA_PUBLIC_KEY_MOD			0
#define	ICC_PUBLIC_KEY_MOD			1
#define	ISS_PUBLIC_KEY_MOD			2
#define	ICC_PIN_ENC_PUBLIC_KEY_MOD	3


// AIP bits
#define	AIP_SDA		0x40
#define	AIP_DDA		0x20
#define	AIP_VERIF	0x10
#define	AIP_TRMNG	0x08		// Terminal Risk Management bit
#define	AIP_ISSAUTH	0x04		// Issuer Authentication bit


// TVR bits
// byte 1
#define	TVR_AUTH_NOT_PERFORMED		0x080
#define	TVR_SDA_FAILED				0x040
#define	TVR_ICC_DATA_MISSING		0x020
#define	TVR_CARD_IN_EXCEPT_FILE		0x010
#define	TVR_DDA_FAILED				0x008
// byte 2
#define	TVR_DIFF_APP_VERSION		0x180
#define	TVR_EXPIRED_APP				0x140
#define	TVR_APP_NOT_EFFECTIVE		0x120
#define	TVR_SERVICE_NOT_ALLOWED		0x110
#define	TVR_NEW_CARD				0x108
// byte 3
#define	TVR_VERIF_NOT_SUCCESS		0x280
#define	TVR_UNRECOG_CVM				0x240
#define	TVR_PIN_TRY_EXCEEDED		0x220
#define	TVR_PINPAD_NOT_PRESENT		0x210
#define	TVR_PIN_NOT_ENTERED			0x208
#define	TVR_ONLINE_PIN_ENTERED		0x204
// byte 4
#define	TVR_FLOOR_LIMIT_EXCEEDED	0x380
#define	TVR_LCOL_EXCEEDED			0x340
#define	TVR_UCOL_EXCEEDED			0x320
#define	TVR_TRAN_RANDOM_SELECTED	0x310
#define	TVR_MERCH_FORCED_ONLINE		0x308
// byte 5
#define	TVR_DEFAULT_TDOL_USED		0x480
#define	TVR_ISSUER_AUTH_UNSUCCESS	0x440
#define	TVR_ISSUER_SCRIPT_FAILED1	0x420
#define	TVR_ISSUER_SCRIPT_FAILED2	0x410



// TSI bits
// byte 1
#define	TSI_AUTH_PERFORMED			0x80
#define	TSI_VERIF_PERFORMED			0x40
#define	TSI_CARD_RISKMNG_PERFORMED	0x20
#define	TSI_ISSUER_AUTH_PERFORMED	0x10
#define	TSI_TERM_RISKMNG_PERFORMED	0x08
#define	TSI_ISSUER_SCRIPT_PERFORMED 0x04


// Terminal Capabilities (9F33) bits
// byte 1
#define TERMCAP_MAN_KEY_ENTRY		0x80
#define TERMCAP_MAGNETIC_STRIPE		0x40
#define TERMCAP_IC_WITH_CONTACTS	0x20
// byte 2
#define TERMCAP_PLAINTEXT_PIN_OFF	0x180
#define TERMCAP_ENCHIPERED_PIN_ONL	0x140
#define TERMCAP_SIGNATURE			0x120
#define TERMCAP_ENCHIPERED_PIN_OFF	0x110
#define TERMCAP_NO_CVM_SUPPORTED	0x108
// byte 3
#define TERMCAP_SDA					0x280
#define TERMCAP_DDA					0x240
#define TERMCAP_CARD_CAPTURE		0x220



// AUC (Application Usage Control) bits (9F07)
#define AUC_VALID_DOMESTIC_CASH				0x80
#define AUC_VALID_INTERNATIONAL_CASH 		0x40
#define AUC_VALID_DOMESTIC_GOODS			0x20
#define AUC_VALID_INTERNATIONAL_GOODS 		0x10
#define AUC_VALID_DOMESTIC_SERVICES 		0x08
#define AUC_VALID_INTERNATIONAL_SERVICES 	0x04
#define AUC_VALID_ATMS						0x02
#define AUC_VALID_NONATMS					0x01
#define AUC_ALLOWED_DOMESTIC_CASHBACK		0x180
#define AUC_ALLOWED_INTERNATIONAL_CASHBACK	0x140



// Additional Terminal Capabilities bits (9F40)
#define	ATC_CASH					0x80
#define	ATC_GOODS					0x40
#define	ATC_SERVICES				0x20
#define	ATC_CASHBACK				0x10
#define	ATC_INQUIRY					0x08
#define	ATC_TRANSFER				0x04
#define	ATC_PAYMENT					0x02
#define	ATC_ADMIN					0x01
#define	ATC_NUMERIC_KEYS			0x280
#define	ATC_ALPHABETIC_KEYS			0x240
#define	ATC_COMMAND_KEYS			0x220
#define	ATC_FUNCTION_KEYS			0x210
#define	ATC_PRINT_ATTENDANT			0x380
#define	ATC_PRINT_CARDHOLDER		0x340
#define	ATC_DISPLAY_ATTENDANT		0x320
#define	ATC_DISPLAY_CARDHOLDER		0x310
#define	ATC_CODE_TABLE_10			0x302
#define	ATC_CODE_TABLE_9			0x301
#define	ATC_CODE_TABLE_8			0x480
#define	ATC_CODE_TABLE_7			0x440
#define	ATC_CODE_TABLE_6			0x420
#define	ATC_CODE_TABLE_5			0x410
#define	ATC_CODE_TABLE_4			0x408
#define	ATC_CODE_TABLE_3			0x404
#define	ATC_CODE_TABLE_2			0x402
#define	ATC_CODE_TABLE_1			0x401


// Transaction Types
#define TRANTYPE_SALE  				0x00
#define TRANTYPE_CASH_VS			0x01
#define TRANTYPE_CASH_MC			0x17

#define	TRANTYPE_ATM				0x03
#define	TRANTYPE_CASHBACK			0x09



// CVM Results
#define CVM_SUCCESS						0x02
#define CVM_FAIL						0x01
#define CVM_UNKNOWN						0x00
#define CVM_NOT_SUPPORTED				0x03


// CVM Codes
// bit 7
#define  CVM_APLY_SUCCEEDING			0x40
#define  CVM_FAIL_VERIFICATION			0x00
// bit 6-0
#define  CVM_FAIL_CVM					0x00
#define  PLAINTEXT_PIN_ICC				0x01
#define  ENCIPHERED_PIN_ONLINE			0x02
#define  PLAINTEXT_PIN_ICC_SIGNATURE 	0x03
#define  ENCIPHERED_PIN_ICC				0x04
#define  ENCIPHERED_PIN_ICC_SIGNATURE 	0x05
#define  SIGNATURE						0x1E
#define  NO_CVM							0x1F


// VERIFY
// QUALIFIERS
#define PLAINTEXT_PIN		0x80
#define ENCHIPERED_PIN		0x88


//*****************************************************************************************
#define NO_PAD_ZERO					0
#define LEFT_PAD_ZERO				1				// Pad zero to the left of the buffer
#define RIGHT_PAD_ZERO			    2				// Pad zero to the right of the buffer

#define RIGHT_PAD                   0
#define LEFT_PAD                    1


#define NO_CUT_BYTE					0				// No cut
#define LEFT_CUT_BYTE				1				// Cut one byte from left of the buffer
#define RIGHT_CUT_BYTE			    2				// Cut one byte from right of the buffer


//*****************************************************************************************
#define LITTLE_ENDIAN 1

typedef struct {
    unsigned long state[5];
    unsigned long count[2];
    unsigned char buffer[64];
} SHA1_CTX;

#define rol(value, bits) (((value) << (bits)) | ((value) >> (32 - (bits))))

/* blk0() and blk() perform the initial expand. */
/* I got the idea of expanding during the round function from SSLeay */
#ifdef LITTLE_ENDIAN
#define blk0(i) (block->l[i] = (rol(block->l[i],24)&0xFF00FF00) \
    |(rol(block->l[i],8)&0x00FF00FF))
#else
#define blk0(i) block->l[i]
#endif
#define blk(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block->l[(i+8)&15] \
    ^block->l[(i+2)&15]^block->l[i&15],1))

/* (R0+R1), R2, R3, R4 are the different operations used in SHA1 */
#define R0(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk0(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R1(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v,5);w=rol(w,30);
#define R2(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v,5);w=rol(w,30);
#define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);
#define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);


//*****************************************************************************************
// Define the type of digits of the numbers involved in the encryption process
typedef unsigned int U_LONG;

#define B (MAX_HALF_DIGIT + 1)

// Maximum values of the used digit type and the half of a digit.
// Used to detect overflows.
#define MAX_DIGIT 0xffffffff
#define MAX_HALF_DIGIT 0xffff

// Number of bits in a digit 
// This library is designed and tested for digits of length 32 bits.
// Used for shift operations etc.
#define BITS_PER_DIGIT 32

// Used to mask the most significant bit of a digit.
// Here it is the bit to the left.
#define HIBITMASK 0x80000000

// Maximum number of digits supported.
// This is dependent on the architecture.
// Used for temporary storage in multiModulo
#define MAX_DIG_LEN 62 


// Macros used to get low or the high halves of the digits.
#define LOHALF(x) ((U_LONG)((x) & 0xffff))
#define HIHALF(x) ((U_LONG)((x) >> 16 & 0xffff))

// This macro moves the low half of a digit to its high half.
// Used in the multiprecision multiplication algorithms.
#define TOHIGH(x) ((U_LONG)((x) << 16))


// Macro used to mask digits and get the value of a bit.
#define multiNEXTBITMASK(mask, n) if(mask==1){mask=HIBITMASK;n--;}else{mask>>=1;}

//*****************************************************************************************
typedef struct
{
	BYTE	Tag[2];
	LPBYTE	Address;
	CHAR  	Requirement;	// 'C' : Conditional   'M' : Mandatory   'R' : Required   'O' : Optional
	BYTE	ucFormat;		// ANS: AlphaNumeric Special   ANU: AlphaNumeric   NUM: Numeric   CNU: Compressed Numeric   BIN: Binary   HEX: No specific format (HEXA)
	BYTE	ucSource;		// Card : 'C'  Terminal : 'T'  Issuer : 'I'
	BYTE	Description[60];
}TAG_ADDRESS;


typedef struct
{
// Terminal Tags	
	BYTE	tDF83[ 5+ 1];	// TAC-Default
	BYTE	tDF84[ 5+ 1];	// TAC-Denial
	BYTE	tDF85[ 5+ 1];	// TAC-Online
	BYTE	tDF87[ 6+ 1];	// Threshold Value for Biased Random Selection
	BYTE	tDF88[ 1+ 1];	// Target Percentage For Random Transaction Selection
	BYTE	tDF89[ 1+ 1];	// Maksimum Target Percentage For Random Transaction Selection
	BYTE	tDF95[32 +3];	// Default DDOL
	BYTE	tDF98[32 +1];	// Default TDOL
	BYTE	tDFA0[64 +1];	// Online DOL	
	BYTE	t5F2A[ 2 +1];	// Transaction currency code
	BYTE	t9F1A[ 2 +1];	// Terminal Country Code
	BYTE	t9F1B[ 4 +1];	// Terminal Floor Limit
	BYTE	t9F09[ 2 +1];	// Application Version Number
	BYTE	t5F36[ 1 +3];	// Transaction Currency Exponent
	BYTE	t81  [ 4 +3];	// Amount, Authorised (Binary)
	BYTE	t8A  [ 2 +3];	// Authorisation Response Code
	BYTE	t95  [ 5 +3];	// Terminal Verification Results (TVR)
	BYTE	t98  [20 +3];	// Transaction Certificate (TC) Hash Value
	BYTE	t99  [64 +3];	// Transaction Personal Identification Number (PIN) Data
	BYTE	t9A  [ 3 +3];	// Transaction Date
	BYTE	t9B  [ 2 +3];	// Transaction Status Information
	BYTE	t9C  [ 1 +3];	// Transaction Type
	BYTE	t9F01[11 +3];	// Acquirer Identifier
	BYTE	t9F02[ 6 +3];	// Amount, Authorised (Numeric)
	BYTE	t9F03[ 6 +3];	// Amount, Other (Numeric)
	BYTE	t9F04[ 4 +3];	// Amount, Other (Binary)
	BYTE	t9F06[16 +3];	// Application Identifier (AID)
	BYTE	t9F15[ 2 +3];	// Merchant Category Code
	BYTE	t9F16[15 +3];	// Merchant Identifier
	BYTE	t9F1C[ 8 +3];	// Terminal Identification
	BYTE	t9F1D[ 8 +3];	// Terminal Risk Management Data
	BYTE	t9F1E[ 8 +3];	// Interface Device (IFD) Serial Number
	BYTE	t9F21[ 3 +3];	// Transaction Time
	BYTE	t9F22[ 1 +3];	// Certification Authority Public Key Index
	BYTE	t9F33[ 3 +3];	// Terminal Capabilities
	BYTE	t9F34[ 3 +3];	// Cardholder Verification Method (CVM) Results
	BYTE	t9F35[ 1 +3];	// Terminal Type
	BYTE	t9F37[ 4 +3];	// Unpredictable Number
	BYTE	t9F39[ 1 +3];	// Point-of-Service (POS) Entry Mode
	BYTE	t9F3A[ 4 +3];	// Amount, Reference Currency
	BYTE	t9F3C[ 2 +3];	// Transaction Reference Currency
	BYTE	t9F3D[ 1 +3];	// Transaction Reference Currency Exponent
	BYTE	t9F40[ 5 +3];	// Additional Terminal Capabilities
	BYTE	t9F41[ 4 +3];	// Transaction Sequence Counter
	// Terminal proprietary tags
	BYTE	tDF81[ 1 +3];	// ByPass PIN	T: DF80, L:1, V:1,0, Type : Binary
	BYTE	tDF90[ 1 +3];	// Trace
	BYTE	tDF91[ 1 +3];	// Merchant forces transaction online
	// Issuer Script Tags
	BYTE	tDF92[128+3];	// Issuer Script Results
}EMV_TERM_TAGS;


typedef struct
{
// Card Tags
	BYTE	t4F  [16 +3];	// Application Identifier (AID)
	BYTE	t50  [16 +3];	// Application Label
	BYTE	t57  [19 +3];	// Track 2 Equivalent Data
	BYTE	t5A  [10 +3];	// Application Primary Account Number (PAN)
	BYTE	t5D  [16 +3];	// UNKNOWN TAG
	BYTE	t5F20[26 +3];	// Cardholder Name
	BYTE	t5F24[ 3 +3];	// Application Expiration Date
	BYTE	t5F25[ 3 +3];	// Application Effective Date
	BYTE	t5F28[ 2 +3];	// Issuer Country Code
	BYTE	t5F2D[ 8 +3];	// Language Preference
	BYTE	t5F30[ 2 +3];	// Service Code
	BYTE	t5F34[ 1 +3];	// Application Primary Account Number (PAN) Sequence Number
	BYTE	t6F  [252+3];	// File Control Information (FCI) Template
	BYTE	t71[MAX_ISSUER_SCRIPT_LEN+3];	// Issuer Script Template 1
	BYTE	t72[MAX_ISSUER_SCRIPT_LEN+3];	// Issuer Script Template 2
	BYTE	t73  [32 +3];	// Directory Discretionary Template
	BYTE	t82  [2  +3];	// Application Interchange Profile
	BYTE	t84  [16 +3];	// Dedicated File (DF) Name
	BYTE	t87  [1  +3];	// Application Priority Indicator
	BYTE	t88  [1  +3];	// Short File Identifier (SFI)
	BYTE	t8C  [252+3];	// Card Risk Management Data Object List 1 (CDOL1)
	BYTE	t8D  [252+3];	// Card Risk Management Data Object List 2 (CDOL2)
	BYTE	t8E  [252+3];	// Cardholder Verification Method (CVM) List
	BYTE	t8F  [ 1 +3];	// Certification Authority Public Key Index
	BYTE	t90[MAX_MODULUS_LEN+3];			// Issuer Public Key Certificate
	BYTE	t91  [16 +3];	// Issuer Authentication Data
	BYTE	t92[MAX_MODULUS_LEN +3+ 36];	// Issuer Public Key Remainder
	BYTE	t93[MAX_MODULUS_LEN+3];			// Signed Static Application Data
	BYTE	t94  [252+3];	// Application File Locator (AFL)
	BYTE	t97  [252+3];	// Transaction Certificate Data Object List (TDOL)
	BYTE	t9F05[32 +3];	// Application Discretionary Data
	BYTE	t9F07[ 2 +3];	// Application Usage Control
	BYTE	t9F08[ 2 +3];	// Application Version Number
	BYTE	t9F0B[45 +3];	// Cardholder Name -Extended (Not use in this library)
	BYTE	t9F0D[ 5 +3];	// Issuer Action Code - Default
	BYTE	t9F0E[ 5 +3];	// Issuer Action Code - Denial
	BYTE	t9F0F[ 5 +3];	// Issuer Action Code - Online
	BYTE	t9F10[32 +3];	// Issuer Application Data (Contains proprietary application data for transmission to the issuer in an online transaction)
	BYTE	t9F11[ 1 +3];	// Issuer Code Table Index
	BYTE	t9F12[16 +3];	// Application Preferred Name
	BYTE	t9F13[ 2 +3];	// Last Online Application Transaction Counter (ATC) Register
	BYTE	t9F14[ 1 +3];	// Lower Consecutive Offline Limit
	BYTE	t9F17[ 1 +3];	// Personal Identification Number (PIN) Try Counter
	BYTE	t9F19[252+3];	// UNKNOWN TAG
	BYTE	t9F1F[256+3];	// Track 1 Discretionary Data
	BYTE	t9F20[256+3];	// Track 2 Discretionary Data
	BYTE	t9F23[ 1 +3];	// Upper Consecutive Offline Limit
	BYTE	t9F26[ 8 +3];	// Application Cryptogram
	BYTE	t9F27[ 1 +3];	// Cryptogram Information Data
	BYTE	t9F2D[MAX_MODULUS_LEN+3];		// ICC PIN Encipherment Public Key Certificate
	BYTE	t9F2E[ 3 +3];	// ICC PIN Encipherment Public Key Exponent
	BYTE	t9F2F[MAX_MODULUS_LEN +3+ 42];	// ICC PIN Encipherment Public Key Remainder
	BYTE	t9F30[ 2 +3];	// UNKNOWN TAG
	BYTE	t9F32[ 3 +3];	// Issuer Public Key Exponent
	BYTE	t9F36[ 2 +3];	// Application Transaction Counter (ATC)
	BYTE	t9F38[MAX_PDOL_LEN+3];			// Processing Options Data Object List (PDOL)
	BYTE	t9F3B[ 2 +3];	// Application Reference Currency
	BYTE	t9F43[ 1 +3];	// Application Reference Currency Exponent
	BYTE	t9F42[ 2 +3];	// Application Currency Code
	BYTE	t9F44[ 1 +3];	// Application Currency Exponent
	BYTE	t9F45[ 2 +3];	// Data Authentication Code
	BYTE	t9F46[MAX_MODULUS_LEN+3];		// ICC Public Key Certificate
	BYTE	t9F47[ 3 +3];	// ICC Public Key Exponent
	BYTE	t9F48[MAX_MODULUS_LEN +3+ 42];	// ICC Public Key Remainder
	BYTE	t9F49[252+3];	// Dynamic Data Object List (DDOL)
	BYTE	t9F4A[MAX_SDA_TAG_LIST_LEN+3];	// Static Data Authentication Tag List
	BYTE	t9F4B[MAX_MODULUS_LEN+3];		// Signed Dynamic Application Data
	BYTE	t9F4C[ 8 +3];	// ICC Dynamic Number
	BYTE	t9F51[ 2 +3];	// UNKNOWN TAG
	BYTE	t9F52[ 2 +3];	// Application Default Action
	BYTE	t9F53[ 1 +3];	// Consecutive Transaction Limit International
	BYTE	t9F54[ 6 +3];	// Cumulative Transaction Amount Limit
	BYTE	t9F55[ 1 +3];	// Geographic Indicator
	BYTE	t9F56[ 1 +3];	// Issuer Authentication Indicator
	BYTE	t9F57[ 2 +3];	// UNKNOWN TAG
	BYTE	t9F58[ 1 +3];	// Lower Consecutive Offline Limit
	BYTE	t9F59[ 1 +3];	// Upper Consecutive Offline Limit
	BYTE	t9F72[ 1 +3];	// UNKNOWN TAG
	BYTE	t9F73[ 4 +3];	// UNKNOWN TAG
	BYTE	t9F75[ 6 +3];	// UNKNOWN TAG
	BYTE	t9F76[ 2 +3];	// UNKNOWN TAG
	BYTE	t9F7F[42 +3];	// UNKNOWN TAG
	BYTE	tBF0C[222+3];	// File Control Information (FCI) Issuer Discretionary Data
}EMV_CARD_TAGS;




typedef struct
{
	BYTE	p9F06[16];	// Application Identifier (Terminal Data)
	int		l9F06;	

	BYTE	p84[16];	// DF Name
	int		l84;
	
	BYTE	p4F[16];	// Application Identifier (Card Data)
	int		l4F;

	char	p50[16];	// Application Label
	int		l50;

    BYTE	l87;		// Application Priority Indicator
    BYTE	p87;

	BYTE	p9F38[32];	// PDOL	
	int		l9F38;
// Language Preference
	BYTE p5F2D[8];
	int	   l5F2D;
// Issuer Code Table Index
	BYTE p9F11;
// Application Preffered Name
	char p9F12[16];
	int	   l9F12;
// FCI Issuer Discreationary Data
	BYTE pBF0C[222];
	int	   lBF0C;
	int	  TermParamIndex;
	int	  Deleted;
}SELECT_RESPONSE;


typedef struct
{
	BYTE ucDirEntries[128];
	BYTE ucDirEntriesLen;
	BYTE ucSFI;
	BYTE ucRecNo;
	BYTE ucIndex;
}STACK;


// response code
typedef struct
{
	BYTE	Y1[2+1];	// Offline Approved
	BYTE	Y2[2+1];	// Offline Approved (after card-initiated referral) NOT SUPPORTED
	BYTE	Y3[2+1];	// offline Approved Unable to go online
	BYTE	Z1[2+1];	// Offline Declined
	BYTE	Z2[2+1];	// Offline Declined (after card-initiated referral) NOT SUPPORTED
	BYTE	Z3[2+1];	// Offline Declined Unable To Go Online
} RESPONSE_CODE;


// Data object format
enum FORMAT {
	ANS=0,					// AlphaNumeric Special      
	ANU,					// AlphaNumeric              
	NUM,					// Numeric                   
	CNU,					// Compressed Numeric        
	BIN,					// Binary                    
	HEX						// No specific format (HEXA) 
};


// ACCESS RESULT
enum ACCESS_REPORT {
	ACCESS_OK=0,
	ACCESS_VIOLATION,
	NO_LENGTH,
	TAG_NOT_FOUND,
	FORMAT_KO
};




class CEMV : public CIsoLib
{
	
public:
	CEMV(void);
	~CEMV(void);

private:
	// private functions
	BYTE Completion( BYTE ucOnlineError, LPBYTE ucCardDesicion );
	BYTE TermActionAnalysisDefault( LPBYTE ucTermDesicion );
	BOOL PrepareOnlineData( LPBYTE ucOnlineMsg, LPWORD iOnlineMsgLen, LPBYTE ucOnlineTags );
	BYTE CardActionAnalysis( BYTE ucTermDesicion );
	BYTE TermActionAnalysis( LPBYTE ucTermDesicion );
	BYTE TerminalRiskManagment( void );
	BYTE RandomTransactionSelection( void );
	BYTE VelocityCheck( void );
	BYTE CardholderVerify( void );
	BYTE CheckCVMConditionCode(BYTE ucCVMCode, LPBYTE ucAmountX, LPBYTE ucAmountY);
	BYTE ApplyCVM(BYTE ucCVMCode, INT *iCVMSuccess);
	BYTE OfflinePIN(BYTE ucCVMCode, BYTE iPINQualifier, INT *iCVMSuccess);
	BYTE OnlinePIN( INT *iCVMSuccess );
	BYTE GetICCEncPublicKey( LPBYTE ucICCPINEncPubKeyModLen );
	BYTE GetICCPublicKey( LPBYTE ucICCPubKeyModLen );
	BYTE RecoverICCPINEncPubKeyCert(BYTE ucIssPubKeyModLen, LPBYTE ucICCPINEncPubKeyModLen);
	BYTE ProcessRestrict( void );
	BYTE OfflineDataAuth( void );
	BYTE DetermineSDAorDDA(char *pcTypeOfAuth);
	BYTE PerformSDA( void );
	BYTE PerformDDA( void );
	int SearchCAKeys(int *piIndex);
	BYTE RecoverPubKeyCert(BYTE ucPubKeyType, BYTE ucPublicKeyModLen, LPBYTE ucExp, int iExpLen, BYTE ucCertLen, LPBYTE ucCertValue, LPBYTE ucIssPubKeyModLen);
	BYTE VerifyStaticAppData(BYTE ucPubKeyModType, BYTE ucIssPubKeyModLen, int iCAIndex);
	BYTE RecoverICCPubKeyCert(BYTE ucIssPubKeyModLen, LPBYTE ucICCPubKeyModLen);
	BYTE VerifyDynamicSign(BYTE ucPubKeyModType, BYTE ucICCPubKeyModLen, LPBYTE ucDDOLData, BYTE ucDDOLDataLen);
	BYTE CheckCertSerialNo(LPBYTE ucRID, LPBYTE ucSerialNo, BYTE ucPKIIndex);
	BYTE RecoverStaticAppData(BYTE ucPubKeyModType, BYTE ucIssPubKeyModLen);
	BYTE PrepStaticTagListData(int *iStaticTagListLen);
	BYTE ReadAppData( void );
	BYTE InitiateApplicationProcessing(void);
	BOOL IncTCC( void );
	int FillDynamicTags( void );
	BYTE GetTransAmount( void );
	void PrepDOLData(int iDOL, LPBYTE pucDOL, LPBYTE pucDOLData, LPBYTE ucDOLDataLen, BYTE ucDOLType);
	void CalculateTCHash(LPBYTE ucTCHash);
	void PrepTDOLData(int iDOL, LPBYTE pucDOL, LPBYTE pucDOLData, LPBYTE ucDOLDataLen);
	void GetByteNoAndValue(int iDefineValue, LPBYTE ucValue, int *iByteNo);
	BYTE ApplicationSelection(LPBYTE ucAppListBuf, INT iAppCnt, LPBYTE ucSelectedApp);
	BYTE SelectMatchingApp(BYTE ucSelectType);
	BYTE SelectFromCandList(BYTE ucSelectType);
	BYTE PrepCandListPSE(BYTE ucAppList[MAX_TERMINAL_APP_CNT][APP_INF_LEN], int iAppCnt, int *iMatchAppCnt);
	BYTE PrepCandList(BYTE ucAppList[MAX_TERMINAL_APP_CNT][APP_INF_LEN], int iAppCnt, int *iMatchAppCnt);
	BYTE AddToCandidateListPSE(LPBYTE ucAppId, int index, LPBYTE cMultipleOccurence);
	BYTE AddToCandidateList(BYTE *ucAppId, int index, BYTE *cMultipleOccurence);
	BYTE AddToEmvTAGS(LPBYTE Msg, int MsgLen, char cDataSource);
	BYTE SearchInTermAIDs(BYTE ucAppList[MAX_TERMINAL_APP_CNT][APP_INF_LEN], int iAppCnt);
	BYTE GetLastRow(STACK *ucStack, BYTE *ucRow);
	BYTE AddToStack(STACK *ucStack, BYTE *ucStackData, BYTE ucStackDataLen, BYTE ucIndex, BYTE ucSFI, BYTE ucRecordNo);
	BYTE GetFromStack(STACK *ucStack, BYTE *ucStackRow);
	void ClearCurrentStackRow(STACK *ucStack, BYTE ucStackRow);
	int GetLenOfDataEl(LPBYTE ucDataEl, LPBYTE ucLenOfLen);
	void SetNextDataEl(BYTE *ucData, int *iDataIndex);
	BYTE SELECT(LPBYTE pucAppName, BYTE ucAppLen, BOOL MultOccurence, BYTE ucSelectType);
	BYTE ParseSelectResp(BYTE ucSelectType);

public:
	// public functions
	BYTE EMVTransaction( void );
	BYTE GetCardBrand( void );
	BYTE GetDataElement(WORD usTag, LPBYTE ucTagValue, PWORD ucLenTag);



private:
	// private variables
	SELECT_RESPONSE m_CandList[MAX_MATCHING_APP_CNT];
	INT			m_SelectedAppIndex;
	BYTE		m_IssScriptMsg[MAX_ISS_SCRIPT_LEN*MAX_ISS_SCRIPT_CNT];
	INT			m_StaticAppDataLen;
	BYTE		m_StaticAppData[MAX_SAD_LEN];

	BYTE		m_TransactionType;

protected:
	// public static variables
	static EMV_CARD_TAGS	m_EMVCardTags;
	static EMV_TERM_TAGS	m_EMVTermTags;

	// public constant variables!
	static const TAG_ADDRESS		m_TagAddress[MAX_TAG_COUNT];
	static const RESPONSE_CODE		m_RespCode;	

	// public variables
	BYTE	m_ApplBuffer[512];
	BYTE	m_ApplicationList[MAX_TERMINAL_APP_CNT*APP_INF_LEN+1];
	BYTE	m_CertifType;	// Card Desicion
	BYTE	m_Approval[3];	// response code 
	BOOL	m_IsApproved;	// IsApproved : TRUE, FALSE
	BOOL	m_PreAuthorized;
	ULONG	m_OfflineBalance;

	BYTE	m_CAPubKeyMod[PUB_KEY_MODULO_LEN];
	BYTE	m_IssPubKeyMod[PUB_KEY_MODULO_LEN];
	BYTE	m_ICCPubKeyMod[PUB_KEY_MODULO_LEN];
	BYTE	m_RecPubKeyMod[PUB_KEY_MODULO_LEN];
	BYTE	m_RecoveredData[PUB_KEY_MODULO_LEN];

	BYTE	m_ICCPINEncPubKeyMod[PUB_KEY_MODULO_LEN];
	BYTE	m_PINEncData[PUB_KEY_MODULO_LEN];
	BYTE	m_EncryptedPINData[PUB_KEY_MODULO_LEN];


	BYTE	m_HashData[HASH_DATA_MODULO_LEN];

	BYTE	m_SDATermData[256];

	BYTE	m_CDOL1Data[MAX_DOL_LEN];

	CAKEYS	m_cakeys[25];
	BYTE	m_NumOfCakeys;
	BYTE	m_NumOfRevokeKey;

	BYTE	m_SignPrint;

	BYTE	m_NoPinPad;

	BYTE	m_EMVData[528+1];
	WORD	m_EMVDataLen;
	BYTE	m_EMVDataRcv[528+1];
	WORD	m_EMVDataRcvLen;

	BYTE	m_CurTXType[3];

protected:
	virtual BYTE ExtractFromChip( void );

	virtual BYTE SendSmartData(WORD SendLen, LPBYTE CardSendData, WORD &OutLen, LPBYTE CardReplyData); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE FillTermParams( void ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual void PrepCAKEYS( void ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual void SetTermVersion( void ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE CheckPinBlockBIN( void ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE GetPin( BYTE UseMAC, LPBYTE PinBl ,BYTE PlainFlag ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE GetTxType( void ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE SplitSale( LPBYTE PCardNumber, LPDWORD pxTotAmount ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual void GetOnlineTags( LPBYTE OnlineTags ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE GetBankDecision( void ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE InputAmount( ULONG &Amount ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE DisplayDebug( CString message ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE DisplayMessage( WORD Line, CString message, BOOL ClearLines=TRUE );
	virtual BYTE DisplayClear( void );
	//virtual BYTE DisplayMessage( CString message ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual BYTE AddRec( void );
	virtual INT DisplayAppMenu( CHIPMENU *pxMenu, UCHAR ucSize ); // Virtual Function. Must Define in derived class (Ferhat)
	virtual bool WriteLogFile(CString logMessage); // Virtual Function. Must Define in derived class (Ferhat)
	virtual bool WriteLogFile(CString title, CString logMessage); // Virtual Function. Must Define in derived class (Ferhat)
	virtual bool WriteLogFile(DWORD BuffLen, LPBYTE BuffData);  // Virtual Function. Must Define in derived class (Ferhat)
	virtual bool WriteLogFile(CString title, DWORD index, CString logMessage);  // Virtual Function. Must Define in derived class (Ferhat)
	virtual bool WriteLogFile(CString title, const BYTE Tag[2], LPBYTE Address);  // Virtual Function. Must Define in derived class (Ferhat)


public:
	void UnPack(UCHAR Base, UCHAR *CompressedForm,UCHAR *OpenForm,UCHAR Length);
	void Pack(UCHAR Base, UCHAR *OpenForm,UCHAR *CompressedForm,UCHAR Length);

private:
	WORD Bin2Lng(LPBYTE buff, WORD buff_len);
	void Lng2Bcd(int lngValue, unsigned char *buff, int len);
	void Short2Bin(unsigned short int shortValue, unsigned char *buff);
	unsigned Bcd2Lng(unsigned char *buff, unsigned buff_len);
	int power( int a, int b );
public:
	char *Bcd2Str(unsigned char *buff, unsigned buff_len, int cut_type, char *str);
	unsigned char *Str2Bcd(char *str, unsigned str_len, int pad_type, unsigned char *bcd, int bcdlen, int pad_dir);

private:
	void compute_hash_str( unsigned char* buffer, int bufferlen, unsigned char digest[20] );
	void SHA1Init(SHA1_CTX* context);
	void SHA1Update(SHA1_CTX* context, unsigned char* data, unsigned long len);
	void SHA1Final(unsigned char digest[20], SHA1_CTX* context);
	void SHA1Transform(unsigned long state[5], unsigned char buffer[64]);
	void SHA1Invert(unsigned char *buf);

private:
	unsigned int mod_size; // RSA ENCRIPTION KEY MODE SIZE
	int RSAEncrypt(unsigned char ucPubKeyType, int PubKeyLen, unsigned char *exp, int expLen, unsigned char *mesaj, int mesajLen);
	void memrev(unsigned char *indata, unsigned char *outdata, int inlen);
	int multiModExp(U_LONG y[], U_LONG x[], U_LONG e[], U_LONG m[], unsigned int ndigits);
	unsigned int multiSizeof(U_LONG a[], unsigned int ndigits);
	void multiSetEqual(U_LONG a[], U_LONG b[], unsigned int ndigits);
	int multiModMult(U_LONG a[], U_LONG x[], U_LONG y[], U_LONG m[], unsigned int ndigits);
	int multiMultiply(U_LONG w[], U_LONG u[], U_LONG v[], unsigned int ndigits);
	int multiModulo(U_LONG r[], U_LONG u[], unsigned int udigits, U_LONG v[], unsigned int vdigits);
	void multiSetZero(U_LONG a[], unsigned int ndigits);
	int singleMultiply(U_LONG p[2], U_LONG x, U_LONG y);
	int multiDivide(U_LONG q[], U_LONG r[], U_LONG u[], unsigned int udigits, U_LONG v[], unsigned int vdigits);
	U_LONG multiShortDiv(U_LONG q[], U_LONG u[], U_LONG v, unsigned int ndigits);
	int multiCompare(U_LONG a[], U_LONG b[], unsigned int ndigits);
	void multiSetDigit(U_LONG a[], U_LONG d, unsigned int ndigits);
	U_LONG multiShiftLeft(U_LONG a[], U_LONG b[], unsigned int x, unsigned int ndigits);
	U_LONG singleDivide(U_LONG *q, U_LONG *r, U_LONG u[2], U_LONG v);
	int QhatTooBig(U_LONG qhat, U_LONG rhat, U_LONG vn2, U_LONG ujn2);
//	static int QhatTooBig(U_LONG qhat, U_LONG rhat, U_LONG vn2, U_LONG ujn2);
	U_LONG multiMultSub(U_LONG wn, U_LONG w[], U_LONG v[], U_LONG q, unsigned int n);
//	static U_LONG multiMultSub(U_LONG wn, U_LONG w[], U_LONG v[], U_LONG q, unsigned int n);
	U_LONG multiAdd(U_LONG w[], U_LONG u[], U_LONG v[], unsigned int ndigits);
	U_LONG multiShiftRight(U_LONG a[], U_LONG b[], unsigned int x, unsigned int ndigits);
	void singleMultSub(U_LONG uu[2], U_LONG qhat, U_LONG v1, U_LONG v0);
//	static void singleMultSub(U_LONG uu[2], U_LONG qhat, U_LONG v1, U_LONG v0);
};
