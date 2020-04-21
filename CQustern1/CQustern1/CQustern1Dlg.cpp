
// CQustern1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CQustern1.h"
#include "CQustern1Dlg.h"
#include "afxdialogex.h"
#include "Answer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCQustern1Dlg 对话框



CCQustern1Dlg::CCQustern1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CQUSTERN1_DIALOG, pParent)
	, m_N(_T(""))
	, m_arr(_T(""))
	, m_arr1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CCQustern1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_texe1, m_text1);
	DDX_Control(pDX, IDC_text2, m_text2);
	DDX_Control(pDX, IDC_text3, m_text3);
	DDX_Text(pDX, IDC_EDIT1, m_N);
	DDX_Text(pDX, IDC_EDIT2, m_arr);
	DDX_Text(pDX, IDC_EDIT3, m_arr1);
}

BEGIN_MESSAGE_MAP(CCQustern1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CCQustern1Dlg::OnBnClickedButton2)
	//ON_STN_CLICKED(IDC_text2, &CCQustern1Dlg::OnStnClickedtext2)
	ON_BN_CLICKED(IDC_BUTTON1, &CCQustern1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CCQustern1Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CCQustern1Dlg 消息处理程序

BOOL CCQustern1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	MessageBox(TEXT("箭靶广场路径搜索可视化设计"), TEXT("您打开的是"));
	m_hIcon = AfxGetApp()->LoadIconA(IDI_ICON2);
	//设置静态文本的字体大小
	m_editFont.CreatePointFont(120, _T("宋体"));
	m_text1.SetFont(&m_editFont);
	m_text2.SetFont(&m_editFont);
	m_text3.SetFont(&m_editFont);

	//创建非静态文本框
	dlg.Create(IDD_ERROR);
	// 对话框的初始大小可以在这里指定
//int nDlgWidth = 400;
//int nDlgHeight = 200;
//     
//CRect rcClient;
//GetClientRect(&rcClient);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}
//
void CCQustern1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCQustern1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCQustern1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int arr[22][22] = { 0 };
int arr1[22][22] = { 0 };
int count_ans = 0;
int ans[410];
int N;
char *beifang, *nanfang;
char *beilu;
void CCQustern1Dlg::OnBnClickedButton2()
{
	count_ans = 0;
	//arr[22][22] = { 0 };
	memset(arr, 0, sizeof(arr));
	memset(ans, 0, sizeof(ans));
	//for (int i = 0; i < 410; i++)
	//	ans[i] = 0;
	// TODO: 在此添加控件通知处理程序代码
	//读取框里的数字
	UpdateData(TRUE);
	char *a; char *b; char *c;
	//当输入为空退出
	if (m_N.IsEmpty() || m_arr.IsEmpty() || m_arr1.IsEmpty())
	{
		MessageBox(TEXT("输入错误请重新输入"),TEXT("错误!!!"));
		return;
	}
	a = m_N.GetBuffer(); b = m_arr.GetBuffer(); c = m_arr1.GetBuffer();
	beifang = m_arr.GetBuffer();nanfang = m_arr1.GetBuffer();
	beilu = m_arr.GetBuffer();
	//转换成数字（正整数）
	//int N = a[0] - '0';
	N = atoi(a);
	int North = atoi(b);
	int Western = atoi(c);
	//输入正确性判断

	if ( correctNumGo(N,North,Western) == FALSE )
	{	//· IDOK 选择了OK按钮。	（return）
		//· IDRETRY 选择了Retry按钮。
		int tmp;
		tmp = AfxMessageBox(_T("输入错误或路径未找到是否重新输入？"), MB_ICONQUESTION | MB_YESNOCANCEL);
		//if (tmp == IDOK)//按下了确认键
		//{
			m_N = TEXT("0");
			m_arr = TEXT("0");
			m_arr1 = TEXT("0");
			UpdateData(FALSE);
		//}
		//if (tmp == IDRETRY)//按下取消键
		//{

		//}
	}
	/*CString tmp;
	tmp.Format("%d", N);
	MessageBox(tmp);*/
	//然后将整数按位放入数组
	
	if (correctNumGo(N, North, Western) == TRUE)
	{
		//int count_ans = 0;
		for (int i = N - 1; i >= 0; i--)
		{
			
			arr[0][i + 1] = North % 10;
			arr[i + 1][0] = Western % 10;
			arr1[0][i + 1] = North % 10;
			arr1[i + 1][0] = Western % 10;
			North = North / 10;
			Western = Western / 10;
		} //数组输入完成

		//if (dfs(1, 1, N) == TRUE) //找到路径此时路径的地板号保存在ans中 没有最后一步
		//{

		//	//OnPaint();
		//	//dlg.DoModal();
		//}
		if (dfs(1, 1, N) == false)
		{
			MessageBox(TEXT("未找到路径"), TEXT("出错了"));
			return;
		}
		//dfs(1, 1, N);
		//数据处理无多余
		CString str1 = "";
		CString str2 = "";
		str2.Format("%d, ", ans[0]);

		str1 += str2;
		for (int i = 1; ans[i]!= 0 ; ++i)
		{
			str2.Format("%d, ", ans[i]);
			str1 += str2;
		}
		MessageBox(str1,TEXT("找到路啦，代号"));
		//if(dfs(1, 1, N) == true)

		dlg.ShowWindow(SW_SHOWNORMAL); //显示非静态文本框
	}
	
	
}
bool CCQustern1Dlg:: correctNumGo(int x, int y, int z)
{
	if (x < 0 || y < 0 || z < 0)
		return FALSE;
	else if (y / (10 * x)<0)
		return FALSE;
	else if (z / (10 * x)<0)
		return FALSE;
	else
		return TRUE;
	
}
int guocheng[1000] = {0};
bool CCQustern1Dlg:: dfs(int i, int j, int N)
{
	static int data=0;
	
	ans[410] = { 0 };
	//memset(ans, 0, sizeof(ans));
	if (i == N && j == N)
	{
		//判断是否所有箭都中了
		int flag = 0;
		for (int k = 1; k <= N; k++)
		{
			flag += arr[k][0];
			flag += arr[0][k];
			if (flag>2)
				break;
		}
		//已经找到这条路了
		if (flag == 2)
		{
			/*for (int k = 0; k<count_ans; k++)
				cout << ans[k] << " ";
			cout << N*N - 1;*/
			data = 0;
			ans[count_ans] = N*N - 1;
			return true;
		}
		else
			return false;
	}

	if (i<1 || i>N || j<1 || j>N)//剪枝3：超出范围
		return false;
	if (arr[i][j] != 0)//剪枝1：走过
		return false;
	if (arr[i][0] == 0 || arr[0][j] == 0)//剪枝2：箭不够了
		return false;
	guocheng[data] = (i - 1)*N + j - 1;
	data++;
	arr[i][j] = 1;//设为旧点，拔出箭 ，放入答案栈
	arr[i][0]--;
	arr[0][j]--;
	ans[count_ans++] = (i - 1)*N + j - 1;
	if (dfs(i + 1, j,N) || dfs(i - 1, j,N) || dfs(i, j + 1,N) || dfs(i, j - 1,N))
		return true;
	count_ans--;//复原
	arr[i][0]++;
	arr[0][j]++;
	arr[i][j] = 0;
	return false;
}
//void CCQustern1Dlg::OnStnClickedtext2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}


void CCQustern1Dlg::OnBnClickedButton1()
{
	//m_N = (CString)"4";
	//m_arr = (CString)"2434";
	//m_arr1 = (CString)"4333";
	m_N = TEXT("4");
	m_arr = TEXT("2434");
	m_arr1 = TEXT("4333");
	UpdateData(FALSE);
	// TODO: 在此添加控件通知处理程序代码
}


void CCQustern1Dlg::OnBnClickedButton3()
{
	memset(arr, 0, sizeof(arr));
	memset(ans, 0, sizeof(ans));
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(TEXT("初始化成功！"));
}
