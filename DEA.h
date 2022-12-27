//***********************************************************************
//* Data Encryption Algorithm	(DEA or DES)							*
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

// PROCESS_TYPE 
#define ENCRYPTION		0x01
#define DECRYPTION		0x02


class CDEA
{
public:
	static void Decrypt( LPBYTE Key, LPBYTE Data, LPBYTE Result ); // Use Data Encryption Standard (DES) for encript a string
	static void Encrypt( LPBYTE Key, LPBYTE Data, LPBYTE Result ); // Use Data Encryption Standard (DES) for dencript a string
	static void DataEncryptionAlgorithm( BYTE type, UCHAR *tinp, const UCHAR *key, int tlen);

private:
	static void permutation( LPBYTE istr, const int *perm, LPBYTE ostr, const int len);
	static void leftShiftForEncrypt( LPBYTE ikey, LPBYTE okey);
	static void leftShiftForDecrypt( LPBYTE ikey, LPBYTE okey);
	static void substitution( LPBYTE in, LPBYTE out);
	static int Pack( LPBYTE destination, LPBYTE source,int len );
	static int UnPack(LPBYTE destination, LPBYTE source, int len);
	static int HexToInt( char *s );
	static int H2I( int x );

	
private:	
	static const int ip[64], e[48], cd0[56], ls[16], pc2[48], s[8][64], p[32], ip1[64];

public:
	CDEA(void);
	~CDEA(void);
};
