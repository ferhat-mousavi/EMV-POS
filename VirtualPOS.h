// VirtualPOS.h : main header file for the VirtualPOS application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CVirtualPOSApp:
// See VirtualPOS.cpp for the implementation of this class
//

class CVirtualPOSApp : public CWinApp
{
public:
	CVirtualPOSApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CVirtualPOSApp theApp;