#ifndef WIN32_LEAN_AND_MEAN
 #define WIN32_LEAN_AND_MEAN
#endif

#ifndef _UNICODE
 #define _UNICODE
#endif

#ifdef _UNICODE
 #ifndef UNICODE
  #define UNICODE
 #endif
#endif

#pragma comment(lib, "libnt5.lib")

#include <windows.h>
#include <commctrl.h>
#include <tchar.h>

#include <iostream>

HINSTANCE g_hInstance;

int WINAPI wWinMain(HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPWSTR lpCmdLine, int nCmdShow) {
  UNREFERENCED_PARAMETER(hPrevInstance);

  g_hInstance = hInstance;

  InitCommonControls();

  LPCWSTR MsgTitle = L"libnt5 Test Application";
  LPCWSTR MsgContent = L"Hello, NT 5.0!";

  MessageBox(NULL, MsgContent, MsgTitle,
             MB_OK | MB_ICONINFORMATION);

  return 0;
}
