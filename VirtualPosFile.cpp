#include "StdAfx.h"
#include ".\virtualposfile.h"

CVirtualPosFile::CVirtualPosFile( BYTE type )
{
	m_state = FALSE;
	m_Read_Len = 0;
	m_Write_Len = 0;

	if( type==TSC )
	{
		m_FileType = type;
		m_FileHandle.Open("TSC.vpf", CFile::modeCreate | CFile::modeNoTruncate | 
							CFile::modeReadWrite | CFile::typeText );

		if(!m_FileHandle)
		{
			 AfxMessageBox("Can not open TSC.vpf");
		}
		else
		{
			m_state = TRUE;
		}
	}
	else
	{
		m_FileType = type;
		m_FileHandle.Open("ERROR.vpf", CFile::modeCreate | CFile::modeNoTruncate | 
							CFile::modeReadWrite | CFile::typeText );

		if(!m_FileHandle)
		{
			 AfxMessageBox("Can not open ERROR.vpf");
		}
		else
		{
			m_state = TRUE;
		}
	}
}

CVirtualPosFile::~CVirtualPosFile(void)
{
	m_FileHandle.Close();
}


BOOL CVirtualPosFile::Read( CString &string )
{
	m_Read_Len = 0;

	string = "1";
	m_Read_Len = 1;

	return TRUE;
}


BOOL CVirtualPosFile::Write( CString string )
{
	m_Write_Len = 0;
	
	m_Write_Len = 1;

	return TRUE;

}


