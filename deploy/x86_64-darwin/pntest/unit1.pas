unit Unit1;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, ComCtrls,
  TAGraph, {TASources,} TAExpressionSeries, TASeries, ImportPolynomial, TADrawUtils, TACustomSeries;

type

  { TForm1 }

  TForm1 = class(TForm)
    Chart: TChart;
    SecantSeries: TLineSeries;
    PolynomialSeries: TLineSeries;
    DerivationSeries: TLineSeries;
    TangentSeries: TLineSeries;
    Memo1: TMemo;
    PageControl1: TPageControl;
    TabSheet1: TTabSheet;
    TabSheet2: TTabSheet;
    procedure ChartLineSeries2CustomDrawPointer(ASender: TChartSeries;
      ADrawer: IChartDrawer; AIndex: Integer; ACenter: TPoint);
    procedure TangentSeriesCustomDrawPointer(ASender: TChartSeries;
      ADrawer: IChartDrawer; AIndex: Integer; ACenter: TPoint);
    procedure PolynomialSeriesCustomDrawPointer(ASender: TChartSeries;
      ADrawer: IChartDrawer; AIndex: Integer; ACenter: TPoint);
    procedure FormCreate(Sender: TObject);
    procedure FormDestroy(Sender: TObject);
  private
    XMin, XMax, DX, TangentPos: Extended;
    procedure CalculatePolynomial;
  public
    Polynomial: TPolynomial;
  end;

var
  Form1: TForm1;

implementation

uses FormEx;

{$R *.lfm}

{ TForm1 }

procedure TForm1.FormCreate(Sender: TObject);
begin
  FormAdjust(Self);
  with Memo1.Lines do begin
    Clear;
    Add(Format('CreatePolynomial   %p', [CreatePolynomial]));
    Add(Format('CreateCopy         %p', [CreateCopy]));
    Add(Format('DestroyPolynomial  %p', [DestroyPolynomial]));
    Add(Format('GetDegree          %p', [GetDegree]));
    Add(Format('SetDegree          %p', [SetDegree]));
    Add(Format('GetCoefficient     %p', [GetCoefficient]));
    Add(Format('SetCoefficient     %p', [SetCoefficient]));
    Add(Format('GetPolynomialValue %p', [GetPolynomialValue]));
    Add(Format('GetDerivation      %p', [GetDerivation]));
    Add(Format('GetSecant          %p', [GetSecant]));
    Add(Format('GetTangent         %p', [GetTangent]))
  end;
  Xmin := -5; Xmax := 5; DX := 0.1; TangentPos := -2;
  Polynomial := CreatePolynomial();
  SetDegree(Polynomial, 3);
  SetCoefficient(Polynomial, 0, 4);
  SetCoefficient(Polynomial, 1, -6);
  SetCoefficient(Polynomial, 2, -4);
  SetCoefficient(Polynomial, 3, 1);
  CalculatePolynomial;
end;

procedure TForm1.PolynomialSeriesCustomDrawPointer(ASender: TChartSeries;
  ADrawer: IChartDrawer; AIndex: Integer; ACenter: TPoint);
begin

end;

procedure TForm1.ChartLineSeries2CustomDrawPointer(ASender: TChartSeries;
  ADrawer: IChartDrawer; AIndex: Integer; ACenter: TPoint);
begin

end;

procedure TForm1.TangentSeriesCustomDrawPointer(ASender: TChartSeries;
  ADrawer: IChartDrawer; AIndex: Integer; ACenter: TPoint);
begin

end;

procedure TForm1.FormDestroy(Sender: TObject);
begin
  DestroyPolynomial(Polynomial)
end;

procedure TForm1.CalculatePolynomial;
var
  x, y: Double;
  D, S, T: TPolynomial;
begin
  x := XMin;
  D := GetDerivation(Polynomial, 1); {first Derivation}
  S := GetSecant(Polynomial, -3, 0);
  T := GetTangent(Polynomial, TangentPos); {Tangent at x = TangentPos}
  y := GetPolynomialValue(S, x);
  SecantSeries.AddXY(x, y);
  y := GetPolynomialValue(T, x);
  TangentSeries.AddXY(x, y);
  while x < Xmax do begin
      y := GetPolynomialValue(Polynomial, x);
      PolynomialSeries.AddXY(x, y);
      y := GetPolynomialValue(D, x);
      DerivationSeries.AddXY(x, y);
      x := x + DX
  end;
  y := GetPolynomialValue(S, x);
  SecantSeries.AddXY(x, y);
  y := GetPolynomialValue(T, x);
  TangentSeries.AddXY(x, y);
end;

end.

