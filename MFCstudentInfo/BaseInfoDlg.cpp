// BaseInfoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCstudentInfo.h"
#include "BaseInfoDlg.h"
#include "afxdialogex.h"


// CBaseInfoDlg 对话框

IMPLEMENT_DYNAMIC(CBaseInfoDlg, CDialogEx)

CBaseInfoDlg::CBaseInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBaseInfoDlg::IDD, pParent)
	, m_Edit_strNo(_T(""))
	, m_Edit_strName(_T(""))
	, m_Edit_strTele(_T(""))
	, m_Edit_strAddr(_T(""))
	, m_tBirth(0)
	, m_isMale(FALSE)
{

}

CBaseInfoDlg::~CBaseInfoDlg()
{
}

void CBaseInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_STRNO, m_Edit_strNo);
	DDX_Text(pDX, IDC_EDIT_STRNAME, m_Edit_strName);
	DDX_Text(pDX, IDC_EDIT_STRTELE, m_Edit_strTele);
	DDX_Text(pDX, IDC_EDIT_STRADDR, m_Edit_strAddr);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_tBirth);
	DDX_Radio(pDX, IDC_RADIO_MALE, m_isMale);
}


BEGIN_MESSAGE_MAP(CBaseInfoDlg, CDialogEx)
	
	ON_BN_CLICKED(IDOK, &CBaseInfoDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CBaseInfoDlg 消息处理程序

//重写--该虚函数
BOOL CBaseInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_tBirth = CTime::GetCurrentTime();
	UpdateColors(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常:  OCX 属性页应返回 FALSE
}



void CBaseInfoDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}



