
// CQustern1Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "Answer.h"




// CCQustern1Dlg �Ի���
class CCQustern1Dlg : public CDialogEx
{
// ����
public:
	CFont m_editFont;
	CCQustern1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CQUSTERN1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CAnswer dlg;
	CStatic m_text1;
	CStatic m_text2;
	CStatic m_text3;
public:
	afx_msg void OnBnClickedButton2();
private:
	CString m_N;
	CString m_arr;
	CString m_arr1;
	
public:
	//afx_msg void OnStnClickedtext2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg bool correctNumGo(int x, int y, int z);
	afx_msg bool dfs(int i, int j, int N);
};
//class Selfdef
//{
//public:
//	bool correctNumGo(int x, int y, int z);
//	bool dfs(int i, int j);
//};
