## libnt5 Usage

For building libnt5 itself from source, see [BUILDING.md](BUILDING.md).

### Using in C/C++ Win32 Development

 How to use this library in your projects to compile for NT 5.x:  

 - First, you should maybe read the [original blog post](https://colinfinck.de/posts/modern-visual-studio-meets-ancient-windows/).
 - The .lib MUST be linked in first, before any other windows or C runtime lib.

 __Note:__ To see a list of all of the win32 functions this library overrides, see [FUNCTIONS.md](FUNCTIONS.md).
