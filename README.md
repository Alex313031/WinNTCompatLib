# LibNT5 <img src="assets/libnt5_logo.png">

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.md)

A static/shared library to allow applications compiled with the [Windows 7.1 SDK + v141_xp toolset](https://learn.microsoft.com/en-us/cpp/build/configuring-programs-for-windows-xp) 
to run on Windows 2000 SP4 and Windows XP RTM - SP2.

<img src="assets/Designed_for_Windows_2000.png">

It is a fork of [EnlyzeWinCompatLib](https://github.com/enlyze/EnlyzeWinCompatLib), modified, modernized  
and made to compile on MSVS 2022 AS WELL AS with [GN](https://gn.googlesource.com/gn/), [Ninja](https://ninja-build.org/)
, [LLVM](https://llvm.org/) & [Clang](https://clang.llvm.org/) for ease of development and code portability.

## Changes from upstream

 - Convert to [Unicode everywhere](https://utf8everywhere.org/).
 - Update defines
 - Add more headers
 - Update toolchain, use static linking and /NODEFAULTLIB for everything
 - Provide spoofer functions for [*HeapQueryInformation*](), [*HeapSetInformation*](), and [*SetDllDirectoryW*]().

## Building

### Building with Visual Studio
Note: The shared library and test executables can't be built yet.

```code
 - Open .sln
 - Build as normal, the compiled .libs will be placed in "dist".
```

### Building with GN/Ninja && LLVM/Clang
This is the default way this library is built. It requires using my [gn-build](https://github.com/Alex313031/gn-build#readme) repository
as the build system. Using that also requires [downloading LLVM]().

```code
 - For your GN args, use the debug_args.gn or release_args.gn
```

## More Information

There is also [a branch](https://github.com/enlyze/EnlyzeWinCompatLib/tree/clang-vs2022) to let Clang-compiled applications run  
on even older Windows versions, down to [Windows NT 4.0](https://en.wikipedia.org/wiki/Windows_NT_4.0) (with SP6 and I.E. 4).  

Read the [corresponding blog post](https://building.enlyze.com/posts/targeting-25-years-of-windows-with-visual-studio-2019/) for more information.

#### Credits

A large credit goes to [Colin Finck](https://github.com/ColinFinck) for the [original library code](https://github.com/enlyze/EnlyzeWinCompatLib/tree/msvc-v141-xp).
