#include <windows.h>
#include <string>
#include "resource1.h" 

const char g_szClassName[] = "myWindowClass";
int c = 0,d=0;
#define button1 1
#define ceva 2
#define button2 3
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	switch (Message)
	{
	case WM_CREATE:
	{
		CreateWindow(TEXT("button"), TEXT("ok"), WS_VISIBLE | WS_CHILD, 120, 40, 200, 20, hwnd, (HMENU) button1,NULL,NULL);
		CreateWindow(TEXT("button"), TEXT("cancel"), WS_VISIBLE | WS_CHILD, 120, 100, 200, 20, hwnd, (HMENU) button2, NULL, NULL);
	}
	case WM_COMMAND:
		
		if (LOWORD(wParam) == button2)
		{
		DestroyWindow(hwnd);
		}
		 if (LOWORD(wParam) == button1)
		{
			if (c == 3)
			{
				int nResult = MessageBox(NULL,
					"An example of Cancel,Retry,Continue",
					"Hello Message Box!",
					MB_ICONERROR | MB_ABORTRETRYIGNORE);



			}
			int msgboxID = MessageBox(
				NULL,
				"Resource not available\nDo you want to try again?",
				"Account Details",
				MB_ICONWARNING | MB_OKCANCEL | MB_DEFBUTTON2
			);
			
			switch (msgboxID)
			{
			case IDCANCEL:
				MessageBox(0, "", "fereastra", MB_OK | MB_ICONASTERISK);
				break;
			case IDOK:
				// TODO: add code
				break;
			case IDCONTINUE:
				// TODO: add code
				break;
			}
		}
		
		switch (LOWORD(wParam))
		{
		case ID_TIPULDECRIPTARE_L40008:
			c = 1;
			
			break;
		case ID_TIPULDECRIPTARE_M:
			c = 2;

			break;
		case ID_TIPULDECRIPTARE_Q:
			c = 3;

			break;
		case ID_TIPULDECRIPTARE_H:
			c = 4;

			break;
			
		case ID_TIPULDEDATE_TEXT:
			//std::string test1 = std::to_string(c);
			//MessageBoxA(NULL, test1.c_str(), "testx", MB_OK);
			d = 1;
			
			break;
		case ID_TIPULDEDATE_NUMERE:
			d = 2;

			break;
		}
		break;
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON));
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 4);
	wc.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wc.lpszClassName = g_szClassName;
	wc.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_MYICON), IMAGE_ICON, 16, 16, 0);

	if (!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		"MyWindow",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 500, 620,
		NULL, NULL, hInstance, NULL);
	SetDlgItemText(hwnd, IDC_TEXT, "This is a string");
	int len = GetWindowTextLength(GetDlgItem(hwnd, IDC_TEXT));
	if (len > 0)
	{
		int i;
		char* buf;
		buf = (char*)GlobalAlloc(GPTR, len + 1);
		GetDlgItemText(hwnd, IDC_TEXT, buf, len + 1);
		//... do stuff with text ...
		GlobalFree((HANDLE)buf);
	}
	
	if (hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	while (GetMessage(&Msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}
