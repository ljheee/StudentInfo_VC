#pragma once
#include "atltime.h"


// CBaseInfoDlg 对话框

class CBaseInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBaseInfoDlg)

public:
	CBaseInfoDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBaseInfoDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_BASEINFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
