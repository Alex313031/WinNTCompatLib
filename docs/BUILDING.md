## Building libnt5 from source

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

### How it works

To see a list of all of the win32 system/kernel functions that this library overrides, see [FUNCTIONS.md](FUNCTIONS.md).
