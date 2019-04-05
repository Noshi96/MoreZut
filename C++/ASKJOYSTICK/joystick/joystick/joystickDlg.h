// joystickDlg.h : header file
//

#pragma once
#include <mmsystem.h>

// CjoystickDlg dialog

class CjoystickDlg : public CDialog
{
// Construction
public:
	CjoystickDlg(CWnd* pParent = NULL);	// standard constructor
	
// Dialog Data
	enum { IDD = IDD_JOYSTICK_DIALOG };
	JOYINFOEX joystickInfo;
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	
	int losuj() {
		srand(time(NULL));
		int los;
		los = (rand() % 4);
		return los;
	}
	bool gra2;
	
// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
