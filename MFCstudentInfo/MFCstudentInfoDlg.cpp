
// MFCstudentInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCstudentInfo.h"
#include "MFCstudentInfoDlg.h"
#include "afxdialogex.h"
#include "BaseInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCstudentInfoDlg 对话框



CMFCstudentInfoDlg::CMFCstudentInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCstudentInfoDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCstudentInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_lcstudent);
}

BEGIN_MESSAGE_MAP(CMFCstudentInfoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CMFCstudentInfoDlg::OnBnClickedButtonAdd)
END_MESSAGE_MAP()


// CMFCstudentInfoDlg 消息处理程序

BOOL CMFCstudentInfoDlg::OnInitDialog()
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

	// TODO:  在此添加额外的初始化代码---初始化List Contral表头及表格。
	CString strCol[] = { _T("学号"), _T("姓名"), _T("性别"), _T("出生日期"), _T("电话号码"), _T("联系地址") };
	int ncol[] = { 80, 80, 40, 100, 100, 100 };
	for (int i = 0; i<6; i++)
		m_lcstudent.InsertColumn(i, strCol[i], 0, ncol[i], -1);
	m_lcstudent.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCstudentInfoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCstudentInfoDlg::OnPaint()
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
HCURSOR CMFCstudentInfoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCstudentInfoDlg::OnBnClickedButtonAdd()
{
	// TODO:  在此添加控件通知处理程序代码
	CBaseInfoDlg dlg;
	dlg.DoModal();

	LVFINDINFO info;
	int nIndex;

	info.flags = LVFI_PARTIAL | LVFI_STRING;
	info.psz = dlg.m_Edit_strNo;
	if ((nIndex = m_lcstudent.FindItem(&info)) != -1){
		MessageBox(_T("你输入的记录已有相同的学号！"));
		return;
	}

	int nItemCount = m_lcstudent.GetItemCount();
	m_lcstudent.InsertItem(LVIF_TEXT | LVIF_STATE, nItemCount, dlg.m_Edit_strNo,
		(nItemCount % 2) == 0 ? LVIS_SELECTED : 0, LVIS_SELECTED, 0, 0);
	m_lcstudent.SetItemText(nItemCount, 1, dlg.m_Edit_strName);
	if (dlg.m_isMale){
		m_lcstudent.SetItemText(nItemCount, 2, _T("女"));
	}
	else{
		m_lcstudent.SetItemText(nItemCount, 2, _T("男"));
	}
	m_lcstudent.SetItemText(nItemCount, 3, dlg.m_tBirth.Format("%Y-%m-%d"));
	m_lcstudent.SetItemText(nItemCount, 4, dlg.m_Edit_strTele);
	m_lcstudent.SetItemText(nItemCount, 5, dlg.m_Edit_strAddr); 
		
	//dlg.DoModal();
}
