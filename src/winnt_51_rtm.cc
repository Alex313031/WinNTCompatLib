//
// libnt5 - Let MSVC v141_xp targeted applications run on even older Windows versions
// Copyright (c) 2025 Alex313031
// SPDX-License-Identifier: MIT
//

// This file implements required APIs not available in Windows XP RTM (NT 5.1).
#include "libnt5_internal.h"

typedef BOOL (WINAPI *PFN_SET_DLL_DIRECTORY)(LPCWSTR lpPathName);

static PFN_SET_DLL_DIRECTORY pfnSetDllDirectory = nullptr;

// Make all the below a no-op on x64.
#if !defined(_WIN64)

static BOOL WINAPI
_CompatSetDllDirectory(LPCWSTR lpPathName)
{
    return false;
}

extern "C" BOOL WINAPI
LibSetDllDirectory(LPCWSTR lpPathName)
{
    if (!pfnSetDllDirectory)
    {
        // Check if the API is provided by kernel32, otherwise fall back to our implementation.
        HMODULE hKernel32 = GetModuleHandleW(L"kernel32");
        pfnSetDllDirectory = reinterpret_cast<PFN_SET_DLL_DIRECTORY>(GetProcAddress(hKernel32, "SetDllDirectoryW"));
        if (!pfnSetDllDirectory)
        {
            pfnSetDllDirectory = _CompatSetDllDirectory;
        }
    }

    return pfnSetDllDirectory(lpPathName);
}

// _WIN64 is defined
#else

#endif // !defined(_WIN64)
