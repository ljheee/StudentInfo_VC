
// MFCstudentInfo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFCstudentInfoApp: 
// �йش����ʵ�֣������ MFCstudentInfo.cpp
//

class CMFCstudentInfoApp : public CWinApp
{
public:
	CMFCstudentInfoApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFCstudentInfoApp theApp;