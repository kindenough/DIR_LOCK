
// DirLock.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDirLockApp:
// �йش����ʵ�֣������ DirLock.cpp
//

class CDirLockApp : public CWinApp
{
public:
	CDirLockApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDirLockApp theApp;