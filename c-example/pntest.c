// testing the library polynomial by calculating some data about an example polynomial

// #define macos
#include "../importpolynomial.h"
#include <stdio.h>

int main()
{
    TPolynomial P1, P2, D, S, T;
    double TangentPos = -2;
    double SecantPos1 = -3;
    double SecantPos2 =  0;
    
    P1 = CreatePolynomial();
    SetDegree(P1, 3);
    SetCoefficient(P1, 0, 4);
    SetCoefficient(P1, 1, -6);
    SetCoefficient(P1, 2, -4);
    SetCoefficient(P1, 3, 1);

    D = GetDerivation(Polynomial, 1); //first Derivation
    printf("\nThe polynomial:\n p(x) = %gx^3 + %gx^2 + %gx + %g\n",
      GetCoefficient(P1, 3), GetCoefficient(P1, 2), GetCoefficient(P1, 1),
      GetCoefficient(P1, 0));
    printf("\nThe derivation:\n p'(x) = %gx^2 + %gx + %g\n",
      GetCoefficient(D, 2), GetCoefficient(D, 1),
      GetCoefficient(D, 0));

    S = GetSecant(Polynomial, SecantPos1, SecantPos2));
    printf("\nThe secant through x1 = %g and x2 = %g:\ns(x) = %gx + %g\n",
      SecantPos1, SecantPos2,
      GetCoefficient(S, 1),
      GetCoefficient(S, 0));
    printf("p(%g) = %g, s(%g) = %g\np(%g) = %g, s(%g) = %g");

    T = GetTangent(Polynomial, TangentPos); //Tangent at x = TangentPos
    printf("\nThe tangent at x = %g:\n t(x) = %gx + %g\n", TangentPos,
      GetCoefficient(T, 1),
      GetCoefficient(T, 0));
    printf("p(%g) = %g\np'(%g) = %g\nt(%g) = %g",
      TangentPos, GetPolynomialValue(P1, TangentPos),
      TangentPos, GetPolynomialValue(D, TangentPos),
      TangentPos, GetPolyNomialValue(T, TangentPos));

    P2 = CreateCopy(P1); //independent copy of P1
    printf("\nPointer values and size:\nP1 = %p, P2 = %p, memory size: %d\n",
      P1, P2, (int) sizeof P1);

    DestroyPolynomial(&P1);
    DestroyPolynomial(&P2);
    printf("After destruction: %p, %p\n", P1, P2);

    return 0;
}
