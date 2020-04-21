// Answer.cpp : 实现文件
//

#include "stdafx.h"
#include "CQustern1.h"
#include "Answer.h"
#include "afxdialogex.h"
# include <stdlib.h>

// CAnswer 对话框

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


// CAnswer 消息处理程序


//void CAnswer::OnPaint()
//{
//	CPaintDC dc(this);
//	//CPaintDC只在OnPaint函数里有效。
//	
//	//dc.TextOutW(100, 100, TEXT("为了部落"));
//
//	dc.Ellipse(10, 10, 100, 100);
//	UpdateData(FALSE);
//}


void CAnswer::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
	//绘制表格  一个边长位 N*50 开始位置为 （50，50） 
	//1、计算边长
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
	CString on = "入口";
	CString out = "出口";
	pDC->TextOut(15, 75, on);
	pDC->TextOut(size + 60, size + 25, out);

	//for (int i = 0; ans[i + 1] != 0; i++)
		
	//开启定时器，进入定时器函数每隔 400ms 走一步
	SetTimer(1, 400, NULL);


	//pDC->Ellipse(10, 10, 100, 100);//绘制椭圆
	//绘制直线
	/*pDC->MoveTo(150, 100);
	pDC->LineTo(300, 400);*/
	//设置画笔
	//CPen pen1(PS_DASH, 4, RGB(255, 0, 0)); //虚线 粗4 红色
	//pDC->SelectObject(&pen1);
	//pDC->MoveTo(100, 150);
	//pDC->LineTo(400, 300);
	////方法二 CreatePen定义画笔
	//CPen pen2;
	//pen2.CreatePen(PS_DASHDOTDOT, 1, RGB(0, 255, 0)); //双点画线 粗2 绿色
	//pDC->SelectObject(&pen2);
	//pDC->MoveTo(100, 150);
	//pDC->LineTo(500, 200);

	////绘制矩形
	////定义坐标点
	//CPoint point1(100, 150);
	//CPoint point2(400, 300);
	////绘制矩形
	//pDC->Rectangle(point1.x, point1.y, point2.x, point2.y);
	////设置画刷的填充颜色
	//CPen pen, *OldPen;
	//pen.CreatePen(PS_DASH, 2, RGB(0, 0, 255)); //虚线 粗2 蓝色
	//OldPen = pDC->SelectObject(&pen);

	//pDC->SelectObject(&pen);
	//CBrush brush,*OldBrush;
	//brush.CreateSolidBrush(RGB(255, 0, 0));
	//OldBrush = pDC->SelectObject(&brush);

	//pDC->SelectObject(brush);
	//pDC->Rectangle(point1.x, point1.y, point2.x, point2.y);
	//

	////绘制文字
	//CString str3 = "绘制圆 半径=";
	//int r = 50;
	//CString data;
	//data.Format("%s %d", str3, r);
	//pDC->TextOut(105, 105, data);

	////画完之后要清除
	//pDC->SelectObject(OldPen);
	//pen.DeleteObject();
	//pDC->SelectObject(OldBrush);
	//brush.DeleteObject();
	//CPaintDC dc(this);
	////CPaintDC只在OnPaint函数里有效。

	////dc.TextOutW(100, 100, TEXT("为了部落"));

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
		int row;   //行
		int column; //列
		static int i = 0;
		// TODO: 在此添加消息处理程序代码和/或调用默认值
		//设置画笔
		static CPen pen1(PS_DASH, 4, RGB(255, 0, 0)); //虚线 粗4 红色
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
			//	//MessageBox(TEXT("走完啦！"));
			MAX = i;
			i = 0;//找完一次清零
			KillTimer(1); //运行完结束定时
		}
		break;
	}
	case 2:
	{
		//static CDC * pDC = GetDC();
		//extern int guocheng[410];
		//extern int N;
		//int row;   //行
		//int column; //列
		//static int i = 0;
		//// TODO: 在此添加消息处理程序代码和/或调用默认值
		////设置画笔
		//static CPen pen1(PS_DASH, 4, RGB(255, 0, 0)); //虚线 粗4 红色
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
		//	//	//MessageBox(TEXT("走完啦！"));
		//	MAX = i;
		//	i = 0;//找完一次清零
		//	KillTimer(1); //运行完结束定时
		}
		//break;
	
	default:
		break;
	}
	
	CDialogEx::OnTimer(nIDEvent);
}


void CAnswer::OnBnClickedButton2()
{
	TCHAR szFilter[] = _T("图片文件(*.bmp)|*.bmp|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("路径图片"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		szFilter, this);
	CString strFilePath;
	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		//SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
	else
	{
		AfxMessageBox(_T("ERROR"));
		return;
	}
	extern int N;
	// 获取窗口DC
	CDC* pDC = GetDC();

	// 创建并绑定绘画DC和Bitmap
	CDC memDC;
	CBitmap bitmap;
	memDC.CreateCompatibleDC(pDC);
	bitmap.CreateCompatibleBitmap(pDC, N*70, 70*N);
	memDC.SelectObject(&bitmap);

	// 把指定窗口区域的图片画到绘图DC中
	memDC.BitBlt(0, 0, 50 + N * 60, 50 + N * 60, pDC, 0, 0, SRCCOPY);

	// 把Bitmap的图片保存到指定路径
	CImage imgTemp;
	imgTemp.Attach(bitmap.operator HBITMAP());
	imgTemp.Save(strFilePath);

	memDC.DeleteDC();
	bitmap.DeleteObject();
	MessageBox(TEXT("保存图片成功！"), TEXT("图片"));
	// TODO: 在此添加控件通知处理程序代码
}


void CAnswer::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造保存文件对话框   
	CFileDialog fileDlg(FALSE, _T("doc"), _T("路径代号"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		szFilter, this);
	CString strFilePath;
	// 显示保存文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 如果点击了文件对话框上的“保存”按钮，则将选择的文件路径显示到编辑框里   
		strFilePath = fileDlg.GetPathName();
		//SetDlgItemText(IDC_SAVE_EDIT, strFilePath);
	}
	else
	{
		AfxMessageBox(_T("请选择保存文件"));
		return;
	}
	CFile file;
	extern int ans[410]; extern int N;
	extern int guocheng[1000];
	extern char *beifang;
	extern char *nanfang;
	extern char *beilu;
	file.Open(strFilePath, CFile::modeCreate | CFile::modeWrite);
 //如果文件存在就清空  然后写入
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
	/*CString tip = "路径代号为:";*/
	CString beifang1 = "";
	CString nanfang1 = "";
	CString guimo = "";
	CString beilu1 = "";
	guimo.Format("%d", N);
	beifang1.Format("%s", beifang);
	nanfang1.Format("%s", nanfang);
	beilu1.Format("%s", beilu);
	file.Write(TEXT("用户输入为\n"),15);
	file.Write(TEXT("广场规模:"), 10);
	file.Write(guimo, guimo.GetLength());
	file.Write(TEXT("\n北方箭靶上箭数量:"), 20);
	file.Write(beilu1, beilu1.GetLength());
	file.Write(TEXT("\n南方箭靶上箭数量:"), 20);
	file.Write(nanfang1, nanfang1.GetLength());
	CString tip = "\n路径代号为:";
	file.Write(tip, tip.GetLength());
	file.Write(str1,str1.GetLength());
	//char *num;
	//_itoa(tmp, num, 10);
	//_itoa_s(tmp, num, 10);
	CString str4 = "";
	str4.Format("%d, ", MAX);
	CString count = "\n步数:";
	file.Write(count, count.GetLength());
	file.Write(str4 , 2);
	CString process = "\n搜索过程为：\n";
	file.Write(process, process.GetLength());
	file.Write(str3, str3.GetLength());
	
	file.Close();
	MessageBox(TEXT("保存文件成功！"), TEXT("文件"));
}


void CAnswer::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


BOOL CAnswer::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CAnswer::OnSize(UINT nType, int cx, int cy)
{
	//CDialogEx::OnSize(nType, cx, cy);
	//CWnd *pWnd;
	//pWnd = GetDlgItem(IDC_BUTTON1);     //获取控件句柄
	//if (nType == 1) return;   //如果是窗体最小化则什么都不做
	//if (pWnd)//判断是否为空，因为对话框创建时会调用此函数，而当时控件还未创建
	//{
	//	CRect rect;   //获取控件变化前大小
	//	LONG cWidth, cHeight; //记录控件的右部到窗体右部的距离，记录控件的底部到窗体底部的距离
	//	pWnd->GetWindowRect(&rect);
	//	ScreenToClient(&rect);//将控件大小转换为在对话框中的区域坐标
	//	cWidth = m_rect.Width() - rect.right;
	//	cHeight = m_rect.Height() - rect.bottom;
	//	rect.left = cx - rect.Width() - cWidth;
	//	rect.right = cx - cWidth;
	//	rect.top = cy - rect.Height() - cHeight;
	//	rect.bottom = cy - cHeight;
	//	pWnd->MoveWindow(rect);//设置控件大小
	//}
	//GetClientRect(&m_rect);//将变化后的对话框大小设为旧大小
	// TODO: 在此处添加消息处理程序代码
}
//extern int arr[22][22] = { 0 };
////int count_ans = 0;
//extern int ans[410];
//销毁窗口时调用
void CAnswer::PostNcDestroy()
{
	// TODO: 在此添加专用代码和/或调用基类
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
	CString on = "入口";
	CString out = "出口";
	pDC->TextOut(15, 75, on);
	pDC->TextOut(size + 60, size + 25, out);

	//开启定时器，进入定时器函数每隔 400ms 走一步
	SetTimer(2, 400, NULL);
	
}


void CAnswer::OnMouseHover(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	extern int N;
	// TODO:  在此添加额外的初始化
	GetClientRect(&m_rect);
	//设定窗口大小
	HWND hWnd = AfxGetMainWnd()->m_hWnd;//获取窗口句柄
	CWnd * pCWnd = FromHandle(hWnd);
	SetWindowPos(pCWnd, 570, 260, 300 + 50 * N, 150 + 50 * N, SWP_SHOWWINDOW);
	CDialogEx::OnMouseHover(nFlags, point);
}


void CAnswer::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	extern int N;
	// TODO:  在此添加额外的初始化
	GetClientRect(&m_rect);
	//设定窗口大小
	HWND hWnd = AfxGetMainWnd()->m_hWnd;//获取窗口句柄
	CWnd * pCWnd = FromHandle(hWnd);
	SetWindowPos(pCWnd, 570, 260, 120 + 60 * N, 60 * N+60, SWP_SHOWWINDOW);
	CDialogEx::OnMouseMove(nFlags, point);
}
