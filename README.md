# LibNT5 <img src="assets/libnt5_logo.png" width="46">

<img src="assets/Designed_for_Windows_2000.png" height="168" align="right">

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.md)

A static/shared library to allow applications compiled with the [v141_xp toolset](https://learn.microsoft.com/en-us/cpp/build/configuring-programs-for-windows-xp/) 
to run on Windows 2000 SP4 and Windows XP RTM - SP2.  

It is a fork of [EnlyzeWinCompatLib](https://github.com/enlyze/EnlyzeWinCompatLib), modified, modernized 
and made to compile on Visual Studio 2022 *as well as* with [GN](https://gn.googlesource.com/gn/), [Ninja](https://ninja-build.org/), 
[LLVM](https://llvm.org/) & [Clang](https://clang.llvm.org/) for ease of development and code portability.

## Changes from upstream

 - Convert to [Unicode everywhere](https://utf8everywhere.org/).
 - Update defines
 - Add more headers
 - Update toolchain, use static linking and /NODEFAULTLIB for everything
 - Provide spoofer functions for [*HeapQueryInformation*](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapqueryinformation), 
   [*HeapSetInformation*](https://learn.microsoft.com/en-us/windows/win32/api/heapapi/nf-heapapi-heapsetinformation), and [*SetDllDirectory*](https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-setdlldirectoryw).

## Building

See [BUILDING.md](docs/BUILDING.md)

## Usage

### Target System Prerequisites
 Minimum requirements that the target system must have to run executables made with this project:  
 - For Windows 2000, [Service Pack 4](https://winworldpc.com/product/windows-nt-2000/patches) is required. 
   To use all common controls, [Internet Explorer 5.5](https://winworldpc.com/product/internet-explorer/ie-55) or higher is recommended.  
 - For Windows XP, [Service Pack 3](https://www.catalog.update.microsoft.com/Search.aspx?q=KB936929) is recommended, but not required.

### Using in Win32 Development
 To use this library in your own projects, see [USAGE.md](docs/USAGE.md).  
 To see all the win32 functions this library spoofs, see [FUNCTIONS.md](docs/FUNCTIONS.md).  

## More Information
 There is also [a branch](https://github.com/enlyze/EnlyzeWinCompatLib/tree/clang-vs2022) to let Clang-compiled applications run 
on even older Windows versions, down to [Windows NT 4.0](https://en.wikipedia.org/wiki/Windows_NT_4.0) (with SP6 and I.E. 4).  

Read the [corresponding blog post](https://building.enlyze.com/posts/targeting-25-years-of-windows-with-visual-studio-2019/) for more information.

### Credits
 A large credit goes to [Colin Finck](https://github.com/ColinFinck) for the 
 [original library code](https://github.com/enlyze/EnlyzeWinCompatLib/tree/msvc-v141-xp).
