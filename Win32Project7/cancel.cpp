// cancel.cpp : implementation file
//

#include "stdafx.h"
#include "cancel.h"
#include "afxdialogex.h"


// cancel dialog

IMPLEMENT_DYNAMIC(cancel, CDialogEx)

cancel::cancel(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

cancel::~cancel()
{
}

void cancel::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(cancel, CDialogEx)
END_MESSAGE_MAP()


// cancel message handlers
