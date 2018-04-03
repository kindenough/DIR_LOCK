
// DirLockDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DirLock.h"
#include "DirLockDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CDirLockDlg �Ի���



CDirLockDlg::CDirLockDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDirLockDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDirLockDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDirLockDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CDirLockDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CDirLockDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CDirLockDlg::OnBnClickedOk2)
END_MESSAGE_MAP()


// CDirLockDlg ��Ϣ�������

BOOL CDirLockDlg::OnInitDialog()
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDirLockDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDirLockDlg::OnPaint()
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
HCURSOR CDirLockDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDirLockDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();
	CEdit* pBoxOne;	
	pBoxOne = (CEdit*) GetDlgItem(IDC_EDIT1);
	//ȡֵ	
	CString str;	
	pBoxOne-> GetWindowText(str);
	if (str!=_T("huangshixing"))
	{
		MessageBox(_T("���������룡"),_T("����"),MB_OK);
		return;
	}
	
	//��ֵ
	pBoxOne-> SetWindowText( _T("") );




        TCHAR           szFolderPath[MAX_PATH] = {0};  
        CString         strFolderPath = TEXT("");  
          
        BROWSEINFO      sInfo;  
        ::ZeroMemory(&sInfo, sizeof(BROWSEINFO));  
        sInfo.pidlRoot   = 0;  
        sInfo.lpszTitle   = _T("��ѡ��һ���ļ��У�");  
        sInfo.ulFlags   = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;  
        sInfo.lpfn     = NULL;  
  
        // ��ʾ�ļ���ѡ��Ի���  
        LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);   
        if (lpidlBrowse != NULL)  
        {  
            // ȡ���ļ�����  
            if (::SHGetPathFromIDList(lpidlBrowse,szFolderPath))    
            {  
				 CString  str;   
				str.Format(_T("%s"),szFolderPath);  
				int index = str.Find(_T(".{"));
				if (index<0)
				{
					strFolderPath = szFolderPath + CString(".{2559a1f2-21d7-11d4-bdaf-00c04f60b9f0}"); 
				}
				else
				{
					strFolderPath = str.Left(str.Find(_T(".{")));
				}
				
				MoveFile(szFolderPath,strFolderPath);
            }  
        }  
        if(lpidlBrowse != NULL)  
        {  
            ::CoTaskMemFree(lpidlBrowse);  
        }  
   
}


void CDirLockDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();

}


void CDirLockDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnBnClickedOk();
}
