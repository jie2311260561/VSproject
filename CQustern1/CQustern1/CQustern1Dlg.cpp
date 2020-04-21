
// CQustern1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CQustern1.h"
#include "CQustern1Dlg.h"
#include "afxdialogex.h"
#include "Answer.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCQustern1Dlg �Ի���



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


// CCQustern1Dlg ��Ϣ�������

BOOL CCQustern1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	MessageBox(TEXT("���й㳡·���������ӻ����"), TEXT("���򿪵���"));
	m_hIcon = AfxGetApp()->LoadIconA(IDI_ICON2);
	//���þ�̬�ı��������С
	m_editFont.CreatePointFont(120, _T("����"));
	m_text1.SetFont(&m_editFont);
	m_text2.SetFont(&m_editFont);
	m_text3.SetFont(&m_editFont);

	//�����Ǿ�̬�ı���
	dlg.Create(IDD_ERROR);
	// �Ի���ĳ�ʼ��С����������ָ��
//int nDlgWidth = 400;
//int nDlgHeight = 200;
//     
//CRect rcClient;
//GetClientRect(&rcClient);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCQustern1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//��ȡ���������
	UpdateData(TRUE);
	char *a; char *b; char *c;
	//������Ϊ���˳�
	if (m_N.IsEmpty() || m_arr.IsEmpty() || m_arr1.IsEmpty())
	{
		MessageBox(TEXT("�����������������"),TEXT("����!!!"));
		return;
	}
	a = m_N.GetBuffer(); b = m_arr.GetBuffer(); c = m_arr1.GetBuffer();
	beifang = m_arr.GetBuffer();nanfang = m_arr1.GetBuffer();
	beilu = m_arr.GetBuffer();
	//ת�������֣���������
	//int N = a[0] - '0';
	N = atoi(a);
	int North = atoi(b);
	int Western = atoi(c);
	//������ȷ���ж�

	if ( correctNumGo(N,North,Western) == FALSE )
	{	//�� IDOK ѡ����OK��ť��	��return��
		//�� IDRETRY ѡ����Retry��ť��
		int tmp;
		tmp = AfxMessageBox(_T("��������·��δ�ҵ��Ƿ��������룿"), MB_ICONQUESTION | MB_YESNOCANCEL);
		//if (tmp == IDOK)//������ȷ�ϼ�
		//{
			m_N = TEXT("0");
			m_arr = TEXT("0");
			m_arr1 = TEXT("0");
			UpdateData(FALSE);
		//}
		//if (tmp == IDRETRY)//����ȡ����
		//{

		//}
	}
	/*CString tmp;
	tmp.Format("%d", N);
	MessageBox(tmp);*/
	//Ȼ��������λ��������
	
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
		} //�����������

		//if (dfs(1, 1, N) == TRUE) //�ҵ�·����ʱ·���ĵذ�ű�����ans�� û�����һ��
		//{

		//	//OnPaint();
		//	//dlg.DoModal();
		//}
		if (dfs(1, 1, N) == false)
		{
			MessageBox(TEXT("δ�ҵ�·��"), TEXT("������"));
			return;
		}
		//dfs(1, 1, N);
		//���ݴ����޶���
		CString str1 = "";
		CString str2 = "";
		str2.Format("%d, ", ans[0]);

		str1 += str2;
		for (int i = 1; ans[i]!= 0 ; ++i)
		{
			str2.Format("%d, ", ans[i]);
			str1 += str2;
		}
		MessageBox(str1,TEXT("�ҵ�·��������"));
		//if(dfs(1, 1, N) == true)

		dlg.ShowWindow(SW_SHOWNORMAL); //��ʾ�Ǿ�̬�ı���
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
		//�ж��Ƿ����м�������
		int flag = 0;
		for (int k = 1; k <= N; k++)
		{
			flag += arr[k][0];
			flag += arr[0][k];
			if (flag>2)
				break;
		}
		//�Ѿ��ҵ�����·��
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

	if (i<1 || i>N || j<1 || j>N)//��֦3��������Χ
		return false;
	if (arr[i][j] != 0)//��֦1���߹�
		return false;
	if (arr[i][0] == 0 || arr[0][j] == 0)//��֦2����������
		return false;
	guocheng[data] = (i - 1)*N + j - 1;
	data++;
	arr[i][j] = 1;//��Ϊ�ɵ㣬�γ��� �������ջ
	arr[i][0]--;
	arr[0][j]--;
	ans[count_ans++] = (i - 1)*N + j - 1;
	if (dfs(i + 1, j,N) || dfs(i - 1, j,N) || dfs(i, j + 1,N) || dfs(i, j - 1,N))
		return true;
	count_ans--;//��ԭ
	arr[i][0]++;
	arr[0][j]++;
	arr[i][j] = 0;
	return false;
}
//void CCQustern1Dlg::OnStnClickedtext2()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CCQustern1Dlg::OnBnClickedButton3()
{
	memset(arr, 0, sizeof(arr));
	memset(ans, 0, sizeof(ans));
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	MessageBox(TEXT("��ʼ���ɹ���"));
}
