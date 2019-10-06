# polynomial

This is an example, how a shared library, being written, compiled and linked with unknown tools but fullfilling the rules for shared libraries of the given system, can be used. The folder deploy contains everything, that is necessary to use the library polynomial and an usage example. I started with using it with Free Pascal Compiler. If somebody knows, how to use the library in other tools and languages, guids and examples are welcome.

## Shared library usage

The library and examples are in system related subdirectories. The file name of the shared library is *polynomial.* Example: For macOS (subdirectory deploy/i386-darwin) it is libpolynomial.dylib.

### Free Pascal

To use the exported functions of the library, use the Unit importpolynomial.pas! It is written for Object Pascal mode. For other modes you will perhaps have to adapt the syntax. 
How the function variables are used to call exported functions of the library is shown in pntest/unit1.pas. 

### Delphi

Fix the syntax in a copy of the Unit importpolynomial.pas! This might require, that you use a "_" at the beginning of function names you import, especially on macOS. You can send me your modification to publish it here, if you want to help other Delphi. users.

Perhaps you have to use another unit than DynLibs in Delphi.
The constant LibFileName might require an adaptation to your environment.
The functions LoadLibrary, UnloadLibrary, and GetProcAddress might have other names in Delphi.
