
// CQustern1Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Answer.h"




// CCQustern1Dlg 对话框
class CCQustern1Dlg : public CDialogEx
{
// 构造
public:
	CFont m_editFont;
	CCQustern1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CQUSTERN1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
