#pragma once
#include "atltime.h"


// CBaseInfoDlg �Ի���

class CBaseInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBaseInfoDlg)

public:
	CBaseInfoDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBaseInfoDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_BASEINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_Edit_strNo;
	CString m_Edit_strName;
	afx_msg void OnCbnSelchangeCombo1();
	CString m_Edit_strTele;
	CString m_Edit_strAddr;
	CTime m_tBirth;
	BOOL m_isMale;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
