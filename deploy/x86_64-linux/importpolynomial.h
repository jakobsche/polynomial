/*

Include this to access the library libpolynomial.so!

Compile command example
gcc -g -wall -o pntest pntest.c libpolynomial.so

*/

// #define macos

typedef void *TPolynomial;

#ifdef macos

/*Creates a new polynomial in memory and points to it.
Call this before the first access to a polynomial! Keep the result to handle the
polynomial*/
extern TPolynomial _CreatePolynomial();

extern TPolynomial _CreateCopy(TPolynomial P);

/*Destroys a polynomial by freeing its memory.
P is set to nil. Call this after the last access to a polynomial!*/
extern void _DestroyPolynomial(TPolynomial *P);

/*Returns the degree of the polynomial P*/
extern int _GetDegree(TPolynomial P);

/*Initializes or changes the degree of the polynomial.
Coefficients and derivation pointers become invalid*/
extern void _SetDegree(TPolynomial P, int AValue);

/*Returns the coefficient with the given index of the polynomial*/
extern double _GetCoefficient(TPolynomial P, int AnIndex);

/*Replaces the value of the coefficient with the given index*/
extern void _SetCoefficient(TPolynomial P, int AnIndex, double AValue);

/*Returns the value of the polynomial at argument x*/
extern double _GetPolynomialValue(TPolynomial P, double x);

/*Points to a polynomial, that is the n-th derivation of P. Its memory is managed by P,
so you must not call CreatePolynomial or DestroyPolynomial with a derivation
pointer. All other functions of this library can be applied to a derivation pointer
like for every other polynomial pointer.*/
extern TPolynomial _GetDerivation(TPolynomial P, int n);

extern TPolynomial _GetSecant(TPolynomial P, double a, double b);

/*points to a polynomial, that describes the tangent of P at the position, x0.*/
extern TPolynomial _GetTangent(TPolynomial P, double x0);

#else

/*Creates a new polynomial in memory and points to it.
Call this before the first access to a polynomial! Keep the result to handle the
polynomial*/
extern TPolynomial CreatePolynomial();

extern TPolynomial CreateCopy(TPolynomial P);

/*Destroys a polynomial by freeing its memory.
P is set to nil. Call this after the last access to a polynomial!*/
extern void DestroyPolynomial(TPolynomial *P);

/*Returns the degree of the polynomial P*/
extern int GetDegree(TPolynomial P);

/*Initializes or changes the degree of the polynomial.
Coefficients and derivation pointers become invalid*/
extern void SetDegree(TPolynomial P, int AValue);

/*Returns the coefficient with the given index of the polynomial*/
extern double GetCoefficient(TPolynomial P, int AnIndex);

/*Replaces the value of the coefficient with the given index*/
extern void SetCoefficient(TPolynomial P, int AnIndex, double AValue);

/*Returns the value of the polynomial at argument x*/
extern double GetPolynomialValue(TPolynomial P, double x);

/*Points to a polynomial, that is the n-th derivation of P. Its memory is managed by P,
so you must not call CreatePolynomial or DestroyPolynomial with a derivation
pointer. All other functions of this library can be applied to a derivation pointer
like for every other polynomial pointer.*/
extern TPolynomial GetDerivation(TPolynomial P, int n);

extern TPolynomial GetSecant(TPolynomial P, double a, double b);

/*points to a polynomial, that describes the tangent of P at the position, x0.*/
extern TPolynomial GetTangent(TPolynomial P, double x0);

#endif
