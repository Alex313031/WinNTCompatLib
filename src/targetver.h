//
// EnlyzeWinCompatLib - Let MSVC v141_xp targeted applications run on even older Windows versions
// Copyright (c) 2021 Colin Finck, ENLYZE GmbH <c.finck@enlyze.com>
// SPDX-License-Identifier: MIT
//

#pragma once

#include <WinSDKVer.h>

#ifndef WINVER
#define WINVER _WIN32_WINNT_WIN2K
#endif // WINVER

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_WIN2K
#endif // _WIN32_WINNT

#ifndef _WIN64_WINNT
#define _WIN64_WINNT _WIN32_WINNT_WS03s
#endif // _WIN64_WINNT

#ifndef _WIN32_IE
#define _WIN32_IE 0x0501
#endif // _WIN32_IE

#include <SDKDDKVer.h>
