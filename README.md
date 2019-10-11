# Library "polynomial" - example, how to use a shared library

This is an example, how a shared library, being written, compiled and linked with unknown tools but fullfilling the rules for shared libraries of the given system, can be used. The folder deploy contains everything, that is necessary to use the library polynomial and a usage example. I started with how to use it with Free Pascal Compiler. If somebody knows, how to use the library in other tools and languages, guids and examples are welcome.

## Exported functions

The use of a shared library is to use the exported functions with the advantage, that they are shared. That means, they have to be stored in a system only one time and can be used by many applications at runtime.
To see, whether a library is usefully, you have to find out, what functions it exports and whether you need them.
Therefore, a reference guide about the exported functions of the library polynomial follows.

On macOS you have to add a leading "_" to the function names (except if you use FPC). 

### CreatePolynomial

| FPC | function CreatePolynomial: TPolynomial; cdecl;

| C   | TPolynomial CreatePolynomial();

returns a handle to a newly created polynomial. The returned type is an unsigned 32 bit integer or a pointer.
This is the first parameter of every following function to identify the polynomial it works on.

### CreateCopy

function CreateCopy(P: TPolynomial): TPolynomial; cdecl;

TPolynomial CreateCopy(TPolynomial P);

returns a newly created copy of P

### DestroyPolynomial

procedure DestroyPolynomial(var P: TPolynomial); cdecl;

void DestroyPolynomial(TPolynomial *P);

frees the memory of P. It has to be called for polynomials being created with the function *CreatePolynomial* or *CreateCopy* only. Call it, before your program is terminated.
After that the handle P is invalid. 

### GetDegree

function GetDegree(P: TPolynomial): Integer; cdecl;

int GetDegree(TPolynomial P);

returns the degree of the polynomial.

### SetDegree

procedure SetDegree(P: TPolynomial; AValue: Integer); cdecl;

void SetDegree(TPolynomial P; int AValue);

sets the degree of P to AValue.

### GetCoefficient

function GetCoefficient(P: TPolynomial; AnIndex: Integer): Double; cdecl;

double GetCoefficient(TPolynomial P; int AnIndex);

returns the coefficient at the given index position of the polynomial.

### SetCoefficient

procedure SetCoefficient(P:TPolynomial; AnIndex:Integer; AValue: Double); cdecl;

void SetCoefficient(TPolynomial P; int AnIndex; double AValue);

sets the coefficient at the given index position of the polynomial.

### GetPolynomialValue

function GetPolynomialValue(P: TPolynomial; x: Double): Double; cdecl;

double GetPolynomialValue(TPolynomial P; double x);

returns the value of P for the given argument.

### GetDerivation

function GetDerivation(P: TPolynomial; n: Integer): TPolynomial; cdecl;

TPolynomial GetDerivation(TPolynomial P; int n);

returns a polynomial that is the n-th derivation of P.

### GetTangent

function GetTangent(P: TPolynomial; x0:Double): TPolynomial; cdecl;

TPolynomial GetTangent(TPolynomial P; double x0);

returns a polynomial describing the tangent touching P at position x0.

### GetSecant

function GetSecant(P: TPolynomial; a, b: Double): TPolynomial; cdecl;

TPolynomial GetSecant(TPolynomial P; double a, b);

returns a polynomial describing the secant of P through 2 points (arguments a and b).

## Shared library usage

The library and examples are in system related subdirectories. The file name of the shared library is \*polynomial.\* Example: For macOS (subdirectory deploy/i386-darwin) it is libpolynomial.dylib.

### Free Pascal

To use the exported functions of the library, use the Unit importpolynomial.pas! It is written for Object Pascal mode. For other modes you will perhaps have to adapt the syntax. Adapt the constant LibFileName to your requirements. 
How the function variables are used to call exported functions of the library is shown in pntest/unit1.pas. 

### Delphi

Fix the syntax in your copy of the Unit importpolynomial.pas! This might require, that you use a "_" at the beginning of function names you import, especially on macOS. You can send me your modification to publish it here, if you want to help other Delphi users.

Perhaps you have to use another unit than DynLibs in Delphi.
The constant LibFileName might require an adaptation to your environment.
The functions LoadLibrary, UnloadLibrary, and GetProcAddress might have other names in Delphi.

### C / C++

Include importpolynomial.h in your code!

### Other languages and development tools

Some IDE might have tools to explore and link to shared libraries and what they export / provide. You should find information about that in the developer documentation of your compiler or IDE. Alternatively, you could search for separate programs providing this functionality. If you are not successfuly, you have to translate the unit importpolynomial.pas into the language you use. This includes to translate (replace) the following declarations and functions:

- type TPolynomial:              can be declared as untyped pointer or as integer of equal size
- function LoadLibrary:          get the handle of the library
- function UnloadLibrary:        release the library in the end of its usage
- function GetProcedureAddress:  get the address of the function with the given name
