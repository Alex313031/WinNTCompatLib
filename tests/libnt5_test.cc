#include "libnt5_test.h"

#pragma comment(lib, "libnt5.lib")

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

  // Allow and allocate conhost
  if (!AllocConsole()) {
    return 1;
  } else {
    // File handler pointer to a dummy file, possibly an actual logfile
    FILE* fNonExistFile = fDummyFile;
    freopen_s(&fNonExistFile, "CONOUT$", "w", stdout);
    freopen_s(&fNonExistFile, "CONOUT$", "w", stderr);
  }

  DWORD currentTime = GetTickCount();
  std::cout << "GetTickCount() = " << currentTime << std::endl;

  OpenMessageBox(L"libnt5 Test Application", L"Hello, NT 5.0!");

  return 0;
}
