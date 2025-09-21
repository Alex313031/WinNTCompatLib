# LibNT5

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

A static/shared library to allow applications compiled with the Windows 7.1 SDK and v141_xp toolset to  
run on Windows 2000 SP4 and Windows XP RTM - SP2.

It is a fork of [EnlyzeWinCompatLib]() , modified, modernized  
and make to compile on MSVS 2022 AS WELL ASS with GN(), Ninja(), LLVM/Clang() for ease of development and code portability.

## Changes from upstream

 - Convert to all unicode
 - Update defines
 - Add more headers
 - Update toolchain and use static linking and /NODEFAULTLIB for everything
 - Profide spoofer functions for [*HeapQueryInformation*]() and [*HeapSetInformation*]().

## Building

<h3>Building with MSVS</h3>

<h3>Building with GN/Ninja && LLVM/Clang</h3>


There is also [a branch](https://github.com/enlyze/EnlyzeWinCompatLib/tree/clang-vs2022) to let Clang-compiled applications run  
on even older Windows versions, down to [Windows NT 4.0](https://en.wikipedia.org/wiki/Windows_NT_4.0) (with SP6 and I.E. 4).  

Read the [corresponding blog post](https://building.enlyze.com/posts/targeting-25-years-of-windows-with-visual-studio-2019/) for more information.

A large credit goes to [Colin Finck](https://github.com/ColinFinck) for the [original library code](https://github.com/enlyze/EnlyzeWinCompatLib/tree/msvc-v141-xp).
