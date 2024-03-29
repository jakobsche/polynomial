/*

Include this to access the library libpolynomial.so!

Compile command example
gcc -g -wall -o pntest pntest.c libpolynomial.so

*/

typedef *void TPolynomial;

#ifdef macOS

/*Creates a new polynomial in memory and points to it.
Call this before the first access to a polynomial! Keep the result to handle the
polynomial*/
TPolynomial _CreatePolynomial();

TPolynomial _CreateCopy(TPolynomial P);

/*Destroys a polynomial by freeing its memory.
P is set to nil. Call this after the last access to a polynomial!*/
void _DestroyPolynomial(TPolynomial *P);

/*Returns the degree of the polynomial P*/
int _GetDegree(TPolynomial P);

/*Initializes or changes the degree of the polynomial.
Coefficients and derivation pointers become invalid*/
void _SetDegree(TPolynomial P; int AValue);

/*Returns the coefficient with the given index of the polynomial*/
double _GetCoefficient(TPolynomial P; int AnIndex);

/*Replaces the value of the coefficient with the given index*/
void _SetCoefficient(TPolynomial P; int AnIndex; double AValue);

/*Returns the value of the polynomial at argument x*/
double _GetPolynomialValue(TPolynomial P; double x);

/*Points to a polynomial, that is the n-th derivation of P. Its memory is managed by P,
so you must not call CreatePolynomial or DestroyPolynomial with a derivation
pointer. All other functions of this library can be applied to a derivation pointer
like for every other polynomial pointer.*/
TPolynomial _GetDerivation(TPolynomial P; int n);

TPolynomial _GetSecant(TPolynomial P; double a, b);

/*points to a polynomial, that describes the tangent of P at the position, x0.*/
TPolynomial _GetTangent(TPolynomial P; double x0);

// Translation of function names

TPolynomial (*CreatePolynomial) ()                                        = &_CreatePolynomial;
TPolynomial (*CreateCopy) (TPolynomial P)                                 = &_CreateCopy;
void        (*DestroyPolynomial) (TPolynomial *P)                         = &_DestroyPolynomial;
int         (*GetDegree) (TPolynomial P)                                  = &_GetDegree;
void        (*SetDegree) (TPolynomial P; int AValue)                      = &_SetDegree;
double      (*GetCoefficient) (TPolynomial P; int AnIndex)                = &_GetCoefficient;
void        (*SetCoefficient) (TPolynomial P; int AnIndex; double AValue) = &_SetCoefficient;
double      (*GetPolynomialValue) (TPolynomial P; double x)               = &_GetPolynomialValue;
TPolynomial (*GetDerivation) (TPolynomial P; int n)                       = &_GetDerivation;
TPolynomial (*GetSecant) (TPolynomial P; double a, b)                     = &_GetSecant;
TPolynomial (*GetTangent) (TPolynomial P; double x0)                      = &_GetTangent;

#else

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

TPolynomial GetSecant(TPolynomial P; double a, double b);

/*points to a polynomial, that describes the tangent of P at the position, x0.*/
TPolynomial GetTangent(TPolynomial P; double x0);

#endif
