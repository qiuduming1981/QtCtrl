#include <windows.h>
#include <stdio.h>

HWND g_hwnd;

LRESULT CALLBACK MainWndProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
);

DWORD WINAPI ThreadProc(LPVOID lpParam)
{
	Sleep(2000);
	::PostMessage(g_hwnd, WM_APP + 100, 0, 0);
	Sleep(2000);
	//while (1)
	{
		::PostMessage(g_hwnd, WM_APP + 101, 0, 0);
		Sleep(2000);
	}
	return 0;
}


int WINAPI WinMain(
  HINSTANCE hInstance,      // handle to current instance
  HINSTANCE hPrevInstance,  // handle to previous instance
  LPSTR lpCmdLine,          // command line
  int nCmdShow              // show state
)
{
	WNDCLASS wndcls;
	wndcls.cbClsExtra=1024;
	wndcls.cbWndExtra=1024;
	wndcls.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
	wndcls.hCursor=LoadCursor(NULL,IDC_ARROW);
	wndcls.hIcon=LoadIcon(NULL,IDI_QUESTION);
	wndcls.hInstance=hInstance;
	wndcls.lpfnWndProc=MainWndProc;
	wndcls.lpszClassName="duming";
	wndcls.lpszMenuName=NULL;
	wndcls.style=CS_HREDRAW | CS_VREDRAW;




	RegisterClass(&wndcls);

	HWND hwnd;

	g_hwnd = hwnd=CreateWindow("duming","duming2102",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInstance,NULL);

	
	

	ShowWindow(hwnd,SW_SHOW);
	
	UpdateWindow(hwnd);



	CreateThread(
		NULL,              // default security attributes
		0,                 // use default stack size  
		ThreadProc,        // thread function 
		0,             // argument to thread function 
		0,                 // use default creation flags 
		0);

	MSG msg;
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}


LRESULT CALLBACK MainWndProc(
  HWND hwnd,      // handle to window
  UINT uMsg,      // message identifier
  WPARAM wParam,  // first message parameter
  LPARAM lParam   // second message parameter
)
{
	switch(uMsg)
	{
	/*case WM_CHAR:
		char szChar[20];
		sprintf(szChar,"char is %d",wParam);
		MessageBox(hwnd,szChar,"windows",0);
		break;*/
	case WM_LBUTTONDOWN:
	{
		//MessageBox(hwnd, "mouse click", "app", 0);
		//HDC hdc;
		//hdc = GetDC(hwnd);
		//TextOut(hdc, 50, 50, "学习vc++", strlen("学习vc++"));
		//ReleaseDC(hwnd, hdc);

		OutputDebugString("start\r\n");

		ShellExecute(NULL, "open", "e:/abc.txt", 0, 0, SW_SHOW);

		OutputDebugString("end\r\n");



	}

		break;
	case WM_LBUTTONUP:
	{

		OutputDebugString("UP\r\n");


	}

	break;
	/*case WM_PAINT:
		HDC hDc;
		PAINTSTRUCT ps;
		hDc=BeginPaint(hwnd,&ps);
		TextOut(hDc,0,0,"加深学习",strlen("加深学习"));
		EndPaint(hwnd,&ps);
		break;
	case WM_CLOSE:
		if(IDYES==MessageBox(hwnd,"是否结束","学习",MB_YESNO))
		{
			DestroyWindow(hwnd);
		}
		break;*/
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_APP + 100:
	{
		int a = 0;
		//MessageBox(hwnd, "123", "123", MB_OK);
	

	}
		break;

	case WM_APP + 101:
	{
		int a = 0;
		//MessageBox(NULL, "456", "456", MB_OK);

	}
	break;
	default:
		return DefWindowProc(hwnd,uMsg,wParam,lParam);
	}
	return 0;
}
