// joystickDlg.cpp : implementation file
//

#include "stdafx.h"
#include "joystick.h"
#include "joystickDlg.h"
#include<time.h>

#include<iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


unsigned char kolko1 = 0x02;
unsigned char kolko2 = 0x01;

unsigned char krzyzyk1 = 0x04;
unsigned char krzyzyk2 = 0x01;

unsigned char kwadrat1 = 0x08;
unsigned char kwadrat2 = 0x01;

unsigned char trojkat1 = 0x01;
unsigned char trojkat2 = 0x01;


unsigned char *tablica_baza;
unsigned char *tablica_gry;
unsigned char *tablica_gry_pierwsza;
int wynik;
int punkty;

// CAboutDlg dialog used for App About
void inicjuj(unsigned char *&tab, unsigned char *&tab2, unsigned char *&tab3) {
	tab = new unsigned char[4];
	tab2 = new unsigned char[10];
	tab3 = new unsigned char[10];
}

void baza(unsigned char *&tab) {
	tab[0] = kolko1;
	tab[1] = krzyzyk1;
	tab[2] = kwadrat1;
	tab[3] = trojkat1;

}

int losuj() {
	srand(time(NULL));
	int los;
	los = (rand() % 4);
	return los;
}

void wprowadzenie(unsigned char *&tab, unsigned char *&tab2, int i, int k) {	
	tab2[i] = tab[k];
	
}

void wypel_gra(unsigned char *&tab, unsigned char *&tab3) {
	tab3[0] = tab[2];
	tab3[1] = tab[1];
	tab3[2] = tab[3];
	tab3[3] = tab[0];
	tab3[4] = tab[0];
	tab3[5] = tab[3];
	tab3[6] = tab[2];
	tab3[7] = tab[0];
	tab3[8] = tab[1];
	tab3[9] = tab[3];
}

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	
// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CjoystickDlg dialog




CjoystickDlg::CjoystickDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CjoystickDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CjoystickDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CjoystickDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CjoystickDlg message handlers

BOOL CjoystickDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	SetTimer( 101, 100, NULL );

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CjoystickDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CjoystickDlg::OnPaint()
{
	srand(time(NULL));
	CPaintDC dc(this); // device context for painting
	if (IsIconic())
	{
		

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);

		
	}
	else
	{
					
			inicjuj(tablica_baza,tablica_gry, tablica_gry_pierwsza);
			baza(tablica_baza);
			wypel_gra(tablica_baza,tablica_gry_pierwsza);
			for (int i = 0; i < 10; i++) {
				wprowadzenie(tablica_baza, tablica_gry, i, CjoystickDlg::losuj());
			}
		

		CString str;
		
		CString str2;

		if (punkty<11){

				for (int i = 0; i < 10; i++) {

					if (punkty == 2 || punkty == 5 || punkty == 9) {

						if (tablica_gry_pierwsza[i] == 0x01) {
							str.Format(L"Nacisnij   TROJKAT ");
							dc.TextOut(40, 30, str);

							if (joystickInfo.dwButtons == trojkat1 && joystickInfo.dwButtonNumber == trojkat2 && (joystickInfo.dwButtons == tablica_gry_pierwsza[i])) {
								str.Format(L"Wcisnieto TROJKAT, DOBRZE! ");
								dc.TextOut(40, 50, str);
								punkty = punkty + 1;

							}
						}
					}

					if (punkty == 3 || punkty == 4 || punkty == 7) {

						if (tablica_gry_pierwsza[i] == 0x02) {
							str.Format(L"Nacisnij     KOLKO ");
							dc.TextOut(40, 30, str);

							if (joystickInfo.dwButtons == kolko1 && joystickInfo.dwButtonNumber == kolko2 && (joystickInfo.dwButtons == tablica_gry_pierwsza[i])) {
								str.Format(L"Wcisnieto KOLKO, DOBRZE! ");
								dc.TextOut(40, 50, str);
								punkty = punkty + 1;

							}
						}
					}

					if (punkty == 1 || punkty == 8) {

						if (tablica_gry_pierwsza[i] == 0x04) {
							str.Format(L"Nacisnij   KRZYZYK ");
							dc.TextOut(40, 30, str);

							if (joystickInfo.dwButtons == krzyzyk1 && joystickInfo.dwButtonNumber == krzyzyk2 && (joystickInfo.dwButtons == tablica_gry_pierwsza[i])) {
								str.Format(L"Wcisnieto KRZYZYK, DOBRZE! ");
								dc.TextOut(40, 50, str);
								punkty = punkty + 1;

							}

						}
					}

					if (punkty ==0 || punkty == 6 ) {
						if (tablica_gry_pierwsza[i] == 0x08) {
							str.Format(L"Nacisnij   KWADRAT ");
							dc.TextOut(40, 30, str);

							if (joystickInfo.dwButtons == kwadrat1 && joystickInfo.dwButtonNumber == kwadrat2 && (joystickInfo.dwButtons == tablica_gry_pierwsza[i])) {
								str.Format(L"Wcisnieto KWADRAT, DOBRZE! ");
								dc.TextOut(40, 50, str);
								punkty = punkty + 1;

							}

						}

					}
		

				}
				if (punkty < 10) {
					str.Format(L"Twoje punkty to: %d   ", punkty);
					dc.TextOut(40, 70, str);
				}

				if (punkty == 10) {
					str.Format(L" KONIEC  WYGRALES! ");
					dc.TextOut(40, 50, str);
				}			
		}
			
		if (joystickInfo.dwButtons & 0x03 && joystickInfo.dwButtonNumber & 0x02 || gra2==true) {
			gra2 = true;
			str.Format(L"Naciskaj krzyzyk gdy zobaczysz KRZYZYK "); //tablica_baza[0], tablica_baza[1], tablica_baza[2]);
			dc.TextOut(40, 90, str);
			
			if (wynik < 10) {
				if (tablica_gry[0] == 0x01) {
					str.Format(L"Teraz jest  TROJKAT ");
					dc.TextOut(40, 110, str);
				}
				if (tablica_gry[0] == 0x02) {
					str.Format(L"Teraz jest    KOLKO ");
					dc.TextOut(40, 110, str);
				}
				if (tablica_gry[0] == 0x04) {
					str.Format(L"Teraz jest KRZYZYK  ");
					dc.TextOut(40, 110, str);
				}
				if (tablica_gry[0] == 0x08) {
					str.Format(L"Teraz jest KWADRAT ");
					dc.TextOut(40, 110, str);
				}
			}
			else {
				str.Format(L"KONIEC KONIEC KONIEC ");
				dc.TextOut(40, 110, str);
			}


			if (joystickInfo.dwButtons & krzyzyk1 && joystickInfo.dwButtonNumber & krzyzyk2 && joystickInfo.dwButtons &tablica_gry[0]) {
				wynik = wynik + 1;
			}

			if (wynik < 10) {
				str.Format(L"Twoje punkty to: %d   ", wynik);
				dc.TextOut(40, 180, str);
			}
			else {
				str.Format(L"BRAVO wygrales twoje punkty to: %d   ",wynik+punkty);
				dc.TextOut(40, 180, str);
			}


			
		}
		CDialog::OnPaint();
	}
	
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CjoystickDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CjoystickDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	MMRESULT joyRes = joyGetPosEx( JOYSTICKID1,&joystickInfo );
	if( joyRes == JOYERR_NOERROR ){
	// joystick podlaczony
	}else{
	// brak joysticka
	}; 
	RedrawWindow( NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW /*| RDW_ERASE*/ );
	

	CDialog::OnTimer(nIDEvent);
}
