// Answer.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CQustern1.h"
#include "Answer.h"
#include "afxdialogex.h"
# include <stdlib.h>

// CAnswer �Ի���

IMPLEMENT_DYNAMIC(CAnswer, CDialogEx)

CAnswer::CAnswer(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_ERROR, pParent)
	, m_step(_T(""))
{

}

CAnswer::~CAnswer()
{
}

void CAnswer::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_step);
}




BEGIN_MESSAGE_MAP(CAnswer, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CAnswer::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CAnswer::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CAnswer::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CAnswer::OnEnChangeEdit1)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON4, &CAnswer::OnBnClickedButton4)
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CAnswer ��Ϣ�������


//void CAnswer::OnPaint()
//{
//	CPaintDC dc(this);
//	//CPaintDCֻ��OnPaint��������Ч��
//	
//	//dc.TextOutW(100, 100, TEXT("Ϊ�˲���"));
//
//	dc.Ellipse(10, 10, 100, 100);
//	UpdateData(FALSE);
//}


void CAnswer::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDC * pDC = GetDC();
	/*CTestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);*/
	//ld = CPoint(-88, -88), rt = CPoint(88, 88);
	//pDC->Ellipse(CRect(CPoint(-140, -90), CPoint(140, 90)));
	extern int arr[22][22] ;
	extern int ans[410];
	extern int N;
	CString str1 = "";
	for (int i = 0; i<20; ++i)
	{
		CString str2 = "";
		str2.Format("%d, ", ans[i]);
		str1 += str2;
	}
	//MessageBox(str1);
	//���Ʊ��  һ���߳�λ N*50 ��ʼλ��Ϊ ��50��50�� 
	//1������߳�
	int size = N * 50;
	int between = N - 1;
	pDC->MoveTo(50,50);
	pDC->LineTo(50, 50 + size);
	pDC->LineTo(50 + size, 50 + size);
	pDC->LineTo(50 + size, 50);
	pDC->LineTo(50, 50);
	for (int i = 1; i <= between; i++)
	{
		pDC->MoveTo(50 + i * 50, 50);
		pDC->LineTo(50 + i * 50, 50 + size);
	}
	for (int i = 1; i <= between; i ++ )
	{
		pDC->MoveTo(50, 50 + i * 50);
		pDC->LineTo(50 + size, 50 + i * 50);
	}
	CString data;
	data.Format("r%d", arr[0][1]);
	//pDC->TextOut(75, 25, data);
	//pDC->Ellipse(CRect(CPoint(60, 10), CPoint(90, 40)));
	CString on = "���";
	CString out = "����";
	pDC->TextOut(15, 75, on);
	pDC->TextOut(size + 60, size + 25, out);

	//for (int i = 0; ans[i + 1] != 0; i++)
		
	//������ʱ�������붨ʱ������ÿ�� 400ms ��һ��
	SetTimer(1, 400, NULL);


	//pDC->Ellipse(10, 10, 100, 100);//������Բ
	//����ֱ��
	/*pDC->MoveTo(150, 100);
	pDC->LineTo(300, 400);*/
	//���û���
	//CPen pen1(PS_DASH, 4, RGB(255, 0, 0)); //���� ��4 ��ɫ
	//pDC->SelectObject(&pen1);
	//pDC->MoveTo(100, 150);
	//pDC->LineTo(400, 300);
	////������ CreatePen���廭��
	//CPen pen2;
	//pen2.CreatePen(PS_DASHDOTDOT, 1, RGB(0, 255, 0)); //˫�㻭�� ��2 ��ɫ
	//pDC->SelectObject(&pen2);
	//pDC->MoveTo(100, 150);
	//pDC->LineTo(500, 200);

	////���ƾ���
	////���������
	//CPoint point1(100, 150);
	//CPoint point2(400, 300);
	////���ƾ���
	//pDC->Rectangle(point1.x, point1.y, point2.x, point2.y);
	////���û�ˢ�������ɫ
	//CPen pen, *OldPen;
	//pen.CreatePen(PS_DASH, 2, RGB(0, 0, 255)); //���� ��2 ��ɫ
	//OldPen = pDC->SelectObject(&pen);

	//pDC->SelectObject(&pen);
	//CBrush brush,*OldBrush;
	//brush.CreateSolidBrush(RGB(255, 0, 0));
	//OldBrush = pDC->SelectObject(&brush);

	//pDC->SelectObject(brush);
	//pDC->Rectangle(point1.x, point1.y, point2.x, point2.y);
	//

	////��������
	//CString str3 = "����Բ �뾶=";
	//int r = 50;
	//CString data;
	//data.Format("%s %d", str3, r);
	//pDC->TextOut(105, 105, data);

	////����֮��Ҫ���
	//pDC->SelectObject(OldPen);
	//pen.DeleteObject();
	//pDC->SelectObject(OldBrush);
	//brush.DeleteObject();
	//CPaintDC dc(this);
	////CPaintDCֻ��OnPaint��������Ч��

	////dc.TextOutW(100, 100, TEXT("Ϊ�˲���"));

	//dc.Ellipse(10, 10, 100, 100);
	//UpdateData(TRUE);
}

int MAX;
void CAnswer::OnTimer(UINT_PTR nIDEvent)
{
	switch(nIDEvent)
	{
	case 1:
	{
		
		static CDC * pDC = GetDC();
		extern int ans[410];
		extern int N;
		int row;   //��
		int column; //��
		static int i = 0;
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		//���û���
		static CPen pen1(PS_DASH, 4, RGB(255, 0, 0)); //���� ��4 ��ɫ
		pDC->SelectObject(&pen1);
		if (i == 0)
		{
			pDC->MoveTo(75, 75);
			i++;
		}
		//for ( i = 0; ans[i + 1] != 0; i++)
		//{
		row = ans[i] / N;
		column = ans[i] % N;
		pDC->LineTo(75 + column * 50, 75 + row * 50);
		i++;
		CString str;
		str.Format("%d", i-1);
		m_step = str;
		UpdateData(FALSE);
		//}
		if (ans[i] == 0)
		{
			//	row = ans[i] / N;
			//	column = ans[i] % N;
			//	pDC->LineTo(75 + column * 50, 75 + row * 50);
			//	i++;
			////	CString str;
			//	str.Format("%d", i);
			//	m_step = str;
			//	UpdateData(FALSE);
		/*	Sleep(500);
			pDC->LineTo(25 + N * 50, 25 + N * 50);*/
			//	Sleep(400);
			////	i++;
			////	CString str;
			//	str.Format("%d", i);
			//	m_step = str;
			//	UpdateData(FALSE);
			//	//MessageBox(TEXT("��������"));
			MAX = i;
			i = 0;//����һ������
			KillTimer(1); //�����������ʱ
		}
		break;
	}
	case 2:
	{
		//static CDC * pDC = GetDC();
		//extern int guocheng[410];
		//extern int N;
		//int row;   //��
		//int column; //��
		//static int i = 0;
		//// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		////���û���
		//static CPen pen1(PS_DASH, 4, RGB(255, 0, 0)); //���� ��4 ��ɫ
		//pDC->SelectObject(&pen1);
		//if (i == 0)
		//	pDC->MoveTo(75, 75);
		////for ( i = 0; ans[i + 1] != 0; i++)
		////{
		//row = guocheng[i] / N;
		//column = guocheng[i] % N;
		//pDC->LineTo(75 + column * 50, 75 + row * 50);
		//i++;

		//CString str;
		//str.Format("%d", i);
		//m_step = str;
		//UpdateData(FALSE);
		////}
		//if (i != 1 && guocheng[i] == 0)
		//{
		//	//	row = ans[i] / N;
		//	//	column = ans[i] % N;
		//	//	pDC->LineTo(75 + column * 50, 75 + row * 50);
		//	//	i++;
		//	////	CString str;
		//	//	str.Format("%d", i);
		//	//	m_step = str;
		//	//	UpdateData(FALSE);
		//	Sleep(500);
		//	pDC->LineTo(25 + N * 50, 25 + N * 50);
		//	//	Sleep(400);
		//	////	i++;
		//	////	CString str;
		//	//	str.Format("%d", i);
		//	//	m_step = str;
		//	//	UpdateData(FALSE);
		//	//	//MessageBox(TEXT("��������"));
		//	MAX = i;
		//	i = 0;//����һ������
		//	KillTimer(1); //�����������ʱ
		}
		//break;
	
	default:
		break;
	}
	
	CDialogEx::OnTimer(nIDEvent);
}


void CAnswer::OnBnClickedButton2()
{
	TCHAR szFilter[] = _T("ͼƬ�ļ�(*.bmp)|*.bmp|�����ļ�(*.*)|*.*||");
	// ���챣���ļ��Ի���   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("·��ͼƬ"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		szFilter, this);
	CString strFilePath;
	// ��ʾ�����ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		//SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
	else
	{
		AfxMessageBox(_T("ERROR"));
		return;
	}
	extern int N;
	// ��ȡ����DC
	CDC* pDC = GetDC();

	// �������󶨻滭DC��Bitmap
	CDC memDC;
	CBitmap bitmap;
	memDC.CreateCompatibleDC(pDC);
	bitmap.CreateCompatibleBitmap(pDC, N*70, 70*N);
	memDC.SelectObject(&bitmap);

	// ��ָ�����������ͼƬ������ͼDC��
	memDC.BitBlt(0, 0, 50 + N * 60, 50 + N * 60, pDC, 0, 0, SRCCOPY);

	// ��Bitmap��ͼƬ���浽ָ��·��
	CImage imgTemp;
	imgTemp.Attach(bitmap.operator HBITMAP());
	imgTemp.Save(strFilePath);

	memDC.DeleteDC();
	bitmap.DeleteObject();
	MessageBox(TEXT("����ͼƬ�ɹ���"), TEXT("ͼƬ"));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CAnswer::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	TCHAR szFilter[] = _T("�ı��ļ�(*.txt)|*.txt|�����ļ�(*.*)|*.*||");
	// ���챣���ļ��Ի���   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("·������"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		szFilter, this);
	CString strFilePath;
	// ��ʾ�����ļ��Ի���   
	if (IDOK == fileDlg.DoModal())
	{
		// ���������ļ��Ի����ϵġ����桱��ť����ѡ����ļ�·����ʾ���༭����   
		strFilePath = fileDlg.GetPathName();
		//SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
	else
	{
		AfxMessageBox(_T("��ѡ�񱣴��ļ�"));
		return;
	}
	CFile file;
	extern int ans[410]; extern int N;
	extern int guocheng[1000];
	extern char *beifang;
	extern char *nanfang;
	extern char *beilu;
	file.Open(strFilePath, CFile::modeCreate | CFile::modeWrite);
 //����ļ����ھ����  Ȼ��д��
	int StepNum = 1;
	CString str1 = "";
	CString str2 = "";
	str2.Format("%d, ", ans[0]);
	str1 += str2;
	for (int i = 1; ans[i]!=0; ++i)
	{
		//CString str2 = "";
		str2.Format("%d, ", ans[i]);
		str1 += str2;
	}
	CString str3 = "";
	int intermediate = 0;
	for (int i = 0; i<1000; ++i)
	{
		if (guocheng[i] == 0 && guocheng[i + 1] == 0)
			break;
		

		CString str2 = "";
		str2.Format("%d, ", guocheng[i]);
		if (i != 0 && i % 10 == 0)
			str3 += '\n';
		str3 += str2;
		intermediate++;
	}
	/*CString tip = "·������Ϊ:";*/
	CString beifang1 = "";
	CString nanfang1 = "";
	CString guimo = "";
	CString beilu1 = "";
	guimo.Format("%d", N);
	beifang1.Format("%s", beifang);
	nanfang1.Format("%s", nanfang);
	beilu1.Format("%s", beilu);
	file.Write(TEXT("�û�����Ϊ\n"),15);
	file.Write(TEXT("�㳡��ģ:"), 10);
	file.Write(guimo, guimo.GetLength());
	file.Write(TEXT("\n���������ϼ�����:"), 20);
	file.Write(beilu1, beilu1.GetLength());
	file.Write(TEXT("\n�Ϸ������ϼ�����:"), 20);
	file.Write(nanfang1, nanfang1.GetLength());
	CString tip = "\n·������Ϊ:";
	file.Write(tip, tip.GetLength());
	file.Write(str1,str1.GetLength());
	//char *num;
	//_itoa(tmp, num, 10);
	//_itoa_s(tmp, num, 10);
	CString str4 = "";
	str4.Format("%d, ", MAX);
	CString count = "\n����:";
	file.Write(count, count.GetLength());
	file.Write(str4 , 2);
	CString process = "\n��������Ϊ��\n";
	file.Write(process, process.GetLength());
	file.Write(str3, str3.GetLength());
	
	file.Close();
	MessageBox(TEXT("�����ļ��ɹ���"), TEXT("�ļ�"));
}


void CAnswer::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CAnswer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CAnswer::OnSize(UINT nType, int cx, int cy)
{
	//CDialogEx::OnSize(nType, cx, cy);
	//CWnd *pWnd;
	//pWnd = GetDlgItem(IDC_BUTTON1);     //��ȡ�ؼ����
	//if (nType == 1) return;   //����Ǵ�����С����ʲô������
	//if (pWnd)//�ж��Ƿ�Ϊ�գ���Ϊ�Ի��򴴽�ʱ����ô˺���������ʱ�ؼ���δ����
	//{
	//	CRect rect;   //��ȡ�ؼ��仯ǰ��С
	//	LONG cWidth, cHeight; //��¼�ؼ����Ҳ��������Ҳ��ľ��룬��¼�ؼ��ĵײ�������ײ��ľ���
	//	pWnd->GetWindowRect(&rect);
	//	ScreenToClient(&rect);//���ؼ���Сת��Ϊ�ڶԻ����е���������
	//	cWidth = m_rect.Width() - rect.right;
	//	cHeight = m_rect.Height() - rect.bottom;
	//	rect.left = cx - rect.Width() - cWidth;
	//	rect.right = cx - cWidth;
	//	rect.top = cy - rect.Height() - cHeight;
	//	rect.bottom = cy - cHeight;
	//	pWnd->MoveWindow(rect);//���ÿؼ���С
	//}
	//GetClientRect(&m_rect);//���仯��ĶԻ����С��Ϊ�ɴ�С
	// TODO: �ڴ˴������Ϣ����������
}
//extern int arr[22][22] = { 0 };
////int count_ans = 0;
//extern int ans[410];
//���ٴ���ʱ����
void CAnswer::PostNcDestroy()
{
	// TODO: �ڴ����ר�ô����/����û���
	extern int ans[410];
	extern int arr[22][22] ;
	extern int guocheng[1000];
	memset(arr, 0, sizeof(arr));
	memset(ans, 0, sizeof(ans));
	memset(guocheng, 0, sizeof(guocheng));
	CDialogEx::PostNcDestroy();
}


void CAnswer::OnBnClickedButton4()
{
	CDC * pDC = GetDC();
	extern int arr[22][22];
	extern int ans[410];
	extern int N;
	CString str1 = "";
	for (int i = 0; i<20; ++i)
	{
		CString str2 = "";
		str2.Format("%d, ", ans[i]);
		str1 += str2;
	}
	int size = N * 50;
	int between = N - 1;
	pDC->MoveTo(50, 50);
	pDC->LineTo(50, 50 + size);
	pDC->LineTo(50 + size, 50 + size);
	pDC->LineTo(50 + size, 50);
	pDC->LineTo(50, 50);
	for (int i = 1; i <= between; i++)
	{
		pDC->MoveTo(50 + i * 50, 50);
		pDC->LineTo(50 + i * 50, 50 + size);
	}
	for (int i = 1; i <= between; i++)
	{
		pDC->MoveTo(50, 50 + i * 50);
		pDC->LineTo(50 + size, 50 + i * 50);
	}
	CString data;
	data.Format("r%d", arr[0][1]);
	//pDC->TextOut(75, 25, data);
	//pDC->Ellipse(CRect(CPoint(60, 10), CPoint(90, 40)));
	CString on = "���";
	CString out = "����";
	pDC->TextOut(15, 75, on);
	pDC->TextOut(size + 60, size + 25, out);

	//������ʱ�������붨ʱ������ÿ�� 400ms ��һ��
	SetTimer(2, 400, NULL);
	
}


void CAnswer::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	extern int N;
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetClientRect(&m_rect);
	//�趨���ڴ�С
	HWND hWnd = AfxGetMainWnd()->m_hWnd;//��ȡ���ھ��
	CWnd * pCWnd = FromHandle(hWnd);
	SetWindowPos(pCWnd, 570, 260, 300 + 50 * N, 150 + 50 * N, SWP_SHOWWINDOW);
	CDialogEx::OnMouseHover(nFlags, point);
}


void CAnswer::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	extern int N;
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	GetClientRect(&m_rect);
	//�趨���ڴ�С
	HWND hWnd = AfxGetMainWnd()->m_hWnd;//��ȡ���ھ��
	CWnd * pCWnd = FromHandle(hWnd);
	SetWindowPos(pCWnd, 570, 260, 120 + 60 * N, 60 * N+60, SWP_SHOWWINDOW);
	CDialogEx::OnMouseMove(nFlags, point);
}
