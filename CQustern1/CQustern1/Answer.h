#pragma once


// CAnswer �Ի���

class CAnswer : public CDialogEx
{
	DECLARE_DYNAMIC(CAnswer)

public:
	CAnswer(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAnswer();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ERROR };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	void OnPaint();
	afx_msg void OnBnClickedButton1();
private:
	void OnDraw();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
private:
	CString m_step;
	CRect m_rect;
public:
	afx_msg void OnEnChangeEdit1();
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual void PostNcDestroy();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnMouseHover(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

