#include "libnt5_test.h"

#include <iostream>

HINSTANCE g_hInstance;

void OpenMessageBox(LPCWSTR MsgTitle, LPCWSTR MsgContent) {
  MessageBoxW(NULL, MsgContent, MsgTitle,
              MB_OK | MB_ICONINFORMATION);
}

int WINAPI wWinMain(HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPWSTR lpCmdLine,
                    int nCmdShow) {
  UNREFERENCED_PARAMETER(hPrevInstance);

  g_hInstance = hInstance;

  InitCommonControls();

  OpenMessageBox(L"libnt5 Test Application", L"Hello, NT 5.0!");

  return 0;
}
