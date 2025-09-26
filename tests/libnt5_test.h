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

#if _WIN32_WINNT == 0x0500 && defined(USING_LIBNT5)
#include <libnt5.h>
#endif // _WIN32_WINNT = 0x0500

#include <windows.h>
#include <commctrl.h>
#include <tchar.h>

extern HINSTANCE g_hInstance;

// Dummy file output for conhost
static FILE* fDummyFile;

void OpenMessageBox(LPCWSTR MsgTitle, LPCWSTR MsgContent);

#endif // LIBNT5_TEST_H_
