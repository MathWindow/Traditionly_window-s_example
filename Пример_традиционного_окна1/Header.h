#pragma once

#define Buffer1 120

OPENFILENAMEA ofn1;
char filename1[Buffer1]{};

WNDCLASS NewWindowClass(HBRUSH BGColor, HCURSOR Cursor, HINSTANCE hInst, HICON Icon, LPCWSTR Name, WNDPROC Procedure);
LRESULT CALLBACK NewWindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
void AddMenu(HWND hWnd);
void AddElements(HWND hWnd);
void SetFile(HWND hWnd);

int widthWindow = 400;
int heightWindow = 400;