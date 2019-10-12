/*

Include this to access the library libpolynomial.so!

Compile command example
gcc -g -wall -o pntest pntest.c libpolynomial.so

*/

type *void TPolynomial;

/*Creates a new polynomial in memory and points to it.
Call this before the first access to a polynomial! Keep the result to handle the
polynomial*/
TPolynomial CreatePolynomial();

TPolynomial CreateCopy(TPolynomial P);

/*Destroys a polynomial by freeing its memory.
P is set to nil. Call this after the last access to a polynomial!*/
void DestroyPolynomial(TPolynomial P);

/*Returns the degree of the polynomial P*/
int GetDegree(TPolynomial P);

/*Initializes or changes the degree of the polynomial.
Coefficients and derivation pointers become invalid*/
void SetDegree(TPolynomial P; int AValue);

/*Returns the coefficient with the given index of the polynomial*/
double GetCoefficient(TPolynomial P; int AnIndex);

/*Replaces the value of the coefficient with the given index*/
void SetCoefficient(TPolynomial P; int AnIndex; double AValue);

/*Returns the value of the polynomial at argument x*/
double GetPolynomialValue(TPolynomial P; double x);

/*Points to a polynomial, that is the n-th derivation of P. Its memory is managed by P,
so you must not call CreatePolynomial or DestroyPolynomial with a derivation
pointer. All other functions of this library can be applied to a derivation pointer
like for every other polynomial pointer.*/
TPolynomial GetDerivation(TPolynomial P; int n);

TPolynomial GetSecant(TPolynomial P; double a, b);

/*points to a polynomial, that describes the tangent of P at the position, x0.*/
TPolynomial GetTangent(TPolynomial P; double x0);

