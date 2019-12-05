#ifndef D2INTERCEPTS_H
#define D2INTERCEPTS_H


void GameDraw_STUB();
BOOL GameMinimize_Interception(void);
HMODULE __stdcall Multi(LPSTR Class,LPSTR Window);
VOID  __fastcall InitMainMenu();
DWORD MainMenuAddress();
HANDLE __stdcall Windowname(DWORD dwExStyle,LPCSTR lpClassName,LPCSTR lpWindowName,DWORD dwStyle,int x,int y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam);
HANDLE __stdcall CacheFix(LPCSTR lpFileName,DWORD dwDesiredAccess,DWORD dwShareMode,LPSECURITY_ATTRIBUTES lpSecurityAttributes,DWORD dwCreationDisposition,DWORD dwFlagsAndAttributes,HANDLE hTemplateFile);
void GameDraw(void);
void GameDraw_STUB();

#endif
