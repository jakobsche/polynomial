# polynomial

This is an example, how a shared library, being written, compiled and linked with unknown tools but fullfilling the rules for shared libraries of the given system, can be used. The folder deploy contains everything, that is necessary to use the library polynomial and an usage example. I started with using it with Free Pascal Compiler. If somebody knows, how to use the library in other tools and languages, guids and examples are welcome.

## Shared library usage

The library and examples are in system related subdirectories. The file name of the shared library is *polynomial.* Example: For macOS (subdirectory deploy/i386-darwin) it is libpolynomial.dylib.

### Free Pascal

To use the exported functions of the library, use the Unit importpolynomial.pas. It is written in Object Pascal Mode. For other modes you will perhaps have to adapt the syntax.
