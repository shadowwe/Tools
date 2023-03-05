
// MFCApplication1Dlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, mSunShine(0)
	, gold(0)
	, huafei(0)
	, qvchongji(0)
	, qiaokeli(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, mSunShine);
	DDX_Text(pDX, IDC_EDIT2, gold);
	DDX_Text(pDX, IDC_EDIT3, huafei);
	DDX_Text(pDX, IDC_EDIT4, qvchongji);
	DDX_Text(pDX, IDC_EDIT5, qiaokeli);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication1Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_readsun, &CMFCApplication1Dlg::OnBnClickedreadsun)
	ON_BN_CLICKED(IDC_writesun, &CMFCApplication1Dlg::OnBnClickedwritesun)
	ON_BN_CLICKED(IDC_readsun2, &CMFCApplication1Dlg::OnBnClickedreadsun2)
	ON_BN_CLICKED(IDC_writesun2, &CMFCApplication1Dlg::OnBnClickedwritesun2)
	ON_BN_CLICKED(IDC_readsun3, &CMFCApplication1Dlg::OnBnClickedreadsun3)
	ON_BN_CLICKED(IDC_writesun3, &CMFCApplication1Dlg::OnBnClickedwritesun3)
	ON_BN_CLICKED(IDC_readsun4, &CMFCApplication1Dlg::OnBnClickedreadsun4)
	ON_BN_CLICKED(IDC_writesun4, &CMFCApplication1Dlg::OnBnClickedwritesun4)
	ON_BN_CLICKED(IDC_readsun5, &CMFCApplication1Dlg::OnBnClickedreadsun5)
	ON_BN_CLICKED(IDC_writesun5, &CMFCApplication1Dlg::OnBnClickedwritesun5)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
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
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication1Dlg::OnBnClickedreadsun()
{
	unsigned long dwSunshineBaseAddress = 0x731C50;
	unsigned long dwSunshineOffsetFirst = 0x868;
	unsigned long dwSunshineOffsetSencond = 0x5578;


	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwSunshineAddressValue;
	unsigned long dwSize = 0;
	int SunshineNum = 0;
	ReadProcessMemory(GameProcess, (void*)(dwSunshineBaseAddress), &dwSunshineAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwSunshineAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwSunshineAddressValue + dwSunshineOffsetFirst), &dwSunshineAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == ReadProcessMemory(GameProcess, (void*)(dwSunshineAddressFirstOffset + dwSunshineOffsetSencond), &SunshineNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}
	mSunShine = SunshineNum;
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedwritesun()
{
	UpdateData(true);

	unsigned long dwSunshineBaseAddress = 0x731C50;
	unsigned long dwSunshineOffsetFirst = 0x868;
	unsigned long dwSunshineOffsetSencond = 0x5578;


	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwSunshineAddressValue;
	unsigned long dwSize = 0;
	int SunshineNum = 0;
	SunshineNum = mSunShine;
	
	ReadProcessMemory(GameProcess, (void*)(dwSunshineBaseAddress), &dwSunshineAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwSunshineAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwSunshineAddressValue + dwSunshineOffsetFirst), &dwSunshineAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == WriteProcessMemory(GameProcess, (void*)(dwSunshineAddressFirstOffset + dwSunshineOffsetSencond), &SunshineNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}

}


void CMFCApplication1Dlg::OnBnClickedreadsun2()
{
	unsigned long dwBaseAddress = 0x731C50;
	unsigned long dwGoldOffsetFirst = 0x94C;
	unsigned long dwGoldOffsetSencond = 0x54;


	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwGoldAddressValue;
	unsigned long dwSize = 0;
	int GoldNum = 0;
	ReadProcessMemory(GameProcess, (void*)(dwBaseAddress), &dwGoldAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwGoldAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwGoldAddressValue + dwGoldOffsetFirst), &dwGoldAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == ReadProcessMemory(GameProcess, (void*)(dwGoldAddressFirstOffset + dwGoldOffsetSencond), &GoldNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}
	gold = GoldNum*10;
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedwritesun2()
{
	unsigned long dwBaseAddress = 0x731C50;
	unsigned long dwGoldOffsetFirst = 0x94C;
	unsigned long dwGoldOffsetSencond = 0x54;
	UpdateData(true);



	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwGoldAddressValue;
	unsigned long dwSize = 0;
	int GoldNum = 0;
	GoldNum = gold/10;
	ReadProcessMemory(GameProcess, (void*)(dwBaseAddress), &dwGoldAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwGoldAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwGoldAddressValue + dwGoldOffsetFirst), &dwGoldAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == WriteProcessMemory(GameProcess, (void*)(dwGoldAddressFirstOffset + dwGoldOffsetSencond), &GoldNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}

}


void CMFCApplication1Dlg::OnBnClickedreadsun3()
{
	unsigned long dwBaseAddress = 0x731C50;
	unsigned long dwGoldOffsetFirst = 0x94C;
	unsigned long dwGoldOffsetSencond = 0x224;


	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwGoldAddressValue;
	unsigned long dwSize = 0;
	int GoldNum = 0;
	ReadProcessMemory(GameProcess, (void*)(dwBaseAddress), &dwGoldAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwGoldAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwGoldAddressValue + dwGoldOffsetFirst), &dwGoldAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == ReadProcessMemory(GameProcess, (void*)(dwGoldAddressFirstOffset + dwGoldOffsetSencond), &GoldNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}
	huafei = GoldNum-1000;
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedwritesun3()
{
	unsigned long dwBaseAddress = 0x731C50;
	unsigned long dwGoldOffsetFirst = 0x94C;
	unsigned long dwGoldOffsetSencond = 0x224;
	UpdateData(true);



	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwGoldAddressValue;
	unsigned long dwSize = 0;
	int GoldNum = 0;
	GoldNum = huafei+1000;
	ReadProcessMemory(GameProcess, (void*)(dwBaseAddress), &dwGoldAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwGoldAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwGoldAddressValue + dwGoldOffsetFirst), &dwGoldAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == WriteProcessMemory(GameProcess, (void*)(dwGoldAddressFirstOffset + dwGoldOffsetSencond), &GoldNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}

}
void CMFCApplication1Dlg::OnBnClickedreadsun4()
{
	unsigned long dwBaseAddress = 0x731C50;
	unsigned long dwGoldOffsetFirst = 0x94C;
	unsigned long dwGoldOffsetSencond = 0x228;


	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwGoldAddressValue;
	unsigned long dwSize = 0;
	int GoldNum = 0;
	ReadProcessMemory(GameProcess, (void*)(dwBaseAddress), &dwGoldAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwGoldAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwGoldAddressValue + dwGoldOffsetFirst), &dwGoldAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == ReadProcessMemory(GameProcess, (void*)(dwGoldAddressFirstOffset + dwGoldOffsetSencond), &GoldNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}
	qvchongji = GoldNum-1000;
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedwritesun4()
{
	unsigned long dwBaseAddress = 0x731C50;
	unsigned long dwGoldOffsetFirst = 0x94C;
	unsigned long dwGoldOffsetSencond = 0x228;
	UpdateData(true);



	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwGoldAddressValue;
	unsigned long dwSize = 0;
	int GoldNum = 0;
	GoldNum = huafei+1000;
	ReadProcessMemory(GameProcess, (void*)(dwBaseAddress), &dwGoldAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwGoldAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwGoldAddressValue + dwGoldOffsetFirst), &dwGoldAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == WriteProcessMemory(GameProcess, (void*)(dwGoldAddressFirstOffset + dwGoldOffsetSencond), &GoldNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}

}

void CMFCApplication1Dlg::OnBnClickedreadsun5()
{
	unsigned long dwBaseAddress = 0x731C50;
	unsigned long dwOffsetFirst = 0x94C;
	unsigned long dwOffsetSencond = 0x254;


	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwAddressValue;
	unsigned long dwSize = 0;
	int Num = 0;
	ReadProcessMemory(GameProcess, (void*)(dwBaseAddress), &dwAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwAddressValue + dwOffsetFirst), &dwAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == ReadProcessMemory(GameProcess, (void*)(dwAddressFirstOffset + dwOffsetSencond), &Num, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}
	qiaokeli = Num-1000;
	UpdateData(false);
}


void CMFCApplication1Dlg::OnBnClickedwritesun5()
{
	unsigned long dwBaseAddress = 0x731C50;
	unsigned long dwGoldOffsetFirst = 0x94C;
	unsigned long dwGoldOffsetSencond = 0x254;
	UpdateData(true);



	unsigned long GamePID;
	HWND Gamewnd;
	HANDLE GameProcess;

	Gamewnd = ::FindWindow(L"MainWindow", L"Plants vs. Zombies");
	GetWindowThreadProcessId(Gamewnd, &GamePID);
	GameProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GamePID);
	if (GameProcess == 0)
		MessageBox(L"获取游戏进程失败！");

	unsigned long dwGoldAddressValue;
	unsigned long dwSize = 0;
	int GoldNum = 0;
	GoldNum = qiaokeli+1000;
	ReadProcessMemory(GameProcess, (void*)(dwBaseAddress), &dwGoldAddressValue, sizeof(unsigned long), &dwSize);
	unsigned long dwGoldAddressFirstOffset;
	ReadProcessMemory(GameProcess, (void*)(dwGoldAddressValue + dwGoldOffsetFirst), &dwGoldAddressFirstOffset, sizeof(unsigned long), &dwSize);
	if (FALSE == WriteProcessMemory(GameProcess, (void*)(dwGoldAddressFirstOffset + dwGoldOffsetSencond), &GoldNum, sizeof(unsigned long), &dwSize))
	{
		MessageBox(L"不是一个版本吧，寄！\n");
		return;
	}

}