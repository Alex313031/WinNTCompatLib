#ifndef LIBNT5_TEST_H_
#define LIBNT5_TEST_H_

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

extern HINSTANCE g_hInstance;

void OpenMessageBox(LPCWSTR MsgTitle, LPCWSTR MsgContent);

#endif // LIBNT5_TEST_H_
