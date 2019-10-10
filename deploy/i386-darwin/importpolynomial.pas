unit ImportPolynomial;

{$mode objfpc}{$H+}

interface

type
  TPolynomial       = Pointer;
  TCopyFunc         = function (P: TPolynomial): TPolynomial;
  TConstructor      = function: TPolynomial; cdecl;
  TDestructor       = procedure (var P: TPolynomial); cdecl;
  TGetIntegerFunc   = function (P: TPolynomial): Integer; cdecl;
  TSetIntegerProc   = procedure (P: TPolynomial; AValue: Integer); cdecl;
  TGetDoubleAtIndex = function (P: TPolynomial; AnIndex: Integer): Double; cdecl;
  TSetDoubleAtIndex = procedure (P: TPolynomial; AnIndex: Integer; AValue: Double); cdecl;
  TGetValueFromArg  = function (P: TPolynomial; x: Double): Double; cdecl;
  TGetDerivation    = function(P: TPolynomial; n: Integer): TPolynomial; cdecl;
  TGetSecant        = function(P: TPolynomial; a, b: Double): TPolynomial; cdecl;
  TGetTangent       = function (P: TPolynomial; x0: Double): TPolynomial; cdecl;

var
  CreatePolynomial: TConstructor;
  CreateCopy: TCopyFunc;
  DestroyPolynomial: TDestructor;
  GetDegree: TGetIntegerFunc;
  SetDegree: TSetIntegerProc;
  GetCoefficient: TGetDoubleAtIndex;
  SetCoefficient: TSetDoubleAtIndex;
  GetPolynomialValue: TGetValueFromArg;
  GetDerivation: TGetDerivation;
  GetSecant: TGetSecant;
  GetTangent: TGetTangent;
  LibLoaded: Boolean;

implementation

uses DynLibs, SysUtils;

const
{$ifdef macos}
  LibFileName = '/Users/andreas/.lib/libpolynomial.dylib';
{$else}
  LibFileName = '/usr/local/lib/libpolynomial.so';
{$endif}

procedure LinkProc(Lib: TLibHandle; AFuncName: string; var AFuncVar);
begin
  Pointer(AFuncVar) := GetProcedureAddress(Lib, AFuncName);
  if Pointer(AFuncVar) = nil then
    raise Exception.CreateFmt('"%s" is not found in "%s"', [AFuncName, LibFileName]);
end;

var
  LibHandle: TLibHandle;

initialization

LibHandle := LoadLibrary(LibFileName);
if LibHandle <> NilHandle then begin
  LinkProc(LibHandle, 'CreatePolynomial', CreatePolynomial);
  LinkProc(LibHandle, 'CreateCopy', CreateCopy);
  LinkProc(LibHandle, 'DestroyPolynomial', DestroyPolynomial);
  LinkProc(LibHandle, 'GetDegree', GetDegree);
  LinkProc(LibHandle, 'SetDegree', SetDegree);
  LinkProc(LibHandle, 'GetCoefficient', GetCoefficient);
  LinkProc(LibHandle, 'SetCoefficient', SetCoefficient);
  LinkProc(LibHandle, 'GetPolynomialValue', GetPolynomialValue);
  LinkProc(LibHandle, 'GetDerivation', GetDerivation);
  LinkProc(LibHandle, 'GetSecant', GetSecant);
  LinkProc(LibHandle, 'GetTangent', GetTangent);
  LibLoaded := True;
end
else raise Exception.Create(GetLoadErrorStr);

finalization

LibLoaded := False;
if not UnloadLibrary(LibHandle) then
  raise Exception.CreateFmt('Unloading of "%s" is not possibly', [LibFileName]);

end.

