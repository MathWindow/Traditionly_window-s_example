#include <windows.h>
#include "Header.h"
#include "resource.h"
using namespace std;

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
	WNDCLASS NewMainClass = NewWindowClass((HBRUSH)COLOR_WINDOW, LoadCursor(NULL, IDC_ARROW), hInst, LoadIcon(hInst, MAKEINTRESOURCE(IDI_ICON1)), L"MainWindow", NewWindowProcedure);

	if (!RegisterClassW(&NewMainClass))
		return -1;

	MSG NewMessageClass = { 0 };

	CreateWindow(L"MainWindow", L"Главное окно", WS_VISIBLE | WS_OVERLAPPEDWINDOW, 650, 330, widthWindow, heightWindow, NULL, NULL, NULL, NULL);

	while (GetMessageA(&NewMessageClass, NULL, NULL, NULL)) {
		TranslateMessage(&NewMessageClass);
		DispatchMessage(&NewMessageClass);
	}

	return 0;
}

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure) {
	WNDCLASS NWC = { 0 };

	NWC.hbrBackground = BGColor;
	NWC.hCursor = Cursor;
	NWC.hInstance = hInst;
	NWC.hIcon = Icon;
	NWC.lpszClassName = Name;
	NWC.lpfnWndProc = Procedure;

	return NWC;
}

LRESULT CALLBACK NewWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
	switch (msg) {
	case WM_COMMAND:
		switch (wp) {

		}
		break;
	case WM_CREATE:
		AddMenu(hWnd);

		SetFile(hWnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, msg, wp, lp);
		break;
	}
}

void AddMenu(HWND hWnd) {
	HMENU RootMenu = CreateMenu();
	HMENU FileMenu = CreateMenu();
	HMENU HelpMenu = CreateMenu();
	HMENU FileMenu2 = CreateMenu();
	HMENU HelpMenu2 = CreateMenu();

	AppendMenu(FileMenu2, MF_STRING, NULL, L"Прототип 5");
	AppendMenu(FileMenu2, MF_STRING, NULL, L"Прототип 6");

	AppendMenu(HelpMenu2, MF_STRING, NULL, L"Прототип 11");
	AppendMenu(HelpMenu2, MF_STRING, NULL, L"Прототип 12");

	AppendMenu(FileMenu, MF_STRING, NULL, L"Прототип 2");
	AppendMenu(FileMenu, MF_STRING, NULL, L"Прототип 3");
	AppendMenu(FileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(FileMenu, MF_POPUP, (UINT_PTR)FileMenu2, L"Прототип 4");

	AppendMenu(HelpMenu, MF_STRING, NULL, L"Прототип 8");
	AppendMenu(HelpMenu, MF_STRING, NULL, L"Прототип 9");
	AppendMenu(HelpMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(HelpMenu, MF_POPUP, (UINT_PTR)HelpMenu2, L"Прототип 10");

	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)FileMenu, L"Прототип 1");
	AppendMenu(RootMenu, MF_POPUP, (UINT_PTR)HelpMenu, L"Прототип 7");

	SetMenu(hWnd, RootMenu);
}

void AddElements(HWND hWnd) {

}

void SetFile(HWND hWnd) {
	ZeroMemory(&ofn1, sizeof(ofn1));
	ofn1.lStructSize = sizeof(ofn1);
	ofn1.hwndOwner = hWnd;
	ofn1.lpstrFile = filename1;
	ofn1.nMaxFile = sizeof(filename1);
	ofn1.lpstrFilter = "*.txt";
	ofn1.lpstrFileTitle = NULL;
	ofn1.nMaxFileTitle = 0;
	ofn1.lpstrInitialDir = "C:\\";
	ofn1.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
}