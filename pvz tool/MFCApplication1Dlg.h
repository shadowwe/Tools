
// MFCApplication1Dlg.h: 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedreadsun();
	afx_msg void OnBnClickedwritesun();
	int mSunShine;
	int gold;
	afx_msg void OnBnClickedreadsun2();
	afx_msg void OnBnClickedwritesun2();
	int huafei;
	int qvchongji;
	int qiaokeli;
	afx_msg void OnBnClickedreadsun3();
	afx_msg void OnBnClickedwritesun3();
	afx_msg void OnBnClickedreadsun4();
	afx_msg void OnBnClickedwritesun4();
	afx_msg void OnBnClickedreadsun5();
	afx_msg void OnBnClickedwritesun5();
};
