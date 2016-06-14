#pragma once


// cancel dialog

class cancel : public CDialogEx
{
	DECLARE_DYNAMIC(cancel)

public:
	cancel(CWnd* pParent = NULL);   // standard constructor
	virtual ~cancel();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
