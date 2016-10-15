// BaseInfoDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCstudentInfo.h"
#include "BaseInfoDlg.h"
#include "afxdialogex.h"


// CBaseInfoDlg �Ի���

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


// CBaseInfoDlg ��Ϣ�������

//��д--���麯��
BOOL CBaseInfoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_tBirth = CTime::GetCurrentTime();
	UpdateColors(false);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣:  OCX ����ҳӦ���� FALSE
}



void CBaseInfoDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}



