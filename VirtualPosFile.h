#define TSC		0x01

#pragma once

class CVirtualPosFile //: public CObject
{
private:
	CStdioFile m_FileHandle;
	BYTE m_FileType;
public:
	CVirtualPosFile( BYTE type );
	~CVirtualPosFile(void);

	BOOL m_state;
	ULONG m_Read_Len;
	ULONG m_Write_Len;

	BOOL Read( CString &string ); // Read from secured file
	BOOL Write( CString string ); // Write into secured file

};
