
// CQustern1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCQustern1App: 
// �йش����ʵ�֣������ CQustern1.cpp
//

class CCQustern1App : public CWinApp
{
public:
	CCQustern1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCQustern1App theApp;