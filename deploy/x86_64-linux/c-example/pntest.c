#include "../importpolynomial.h"
#include <stdio.h>

int main()
{
    TPolynomial P1;
    TPolynomial P2;
    
    P1 = CreatePolynomial();
    P2 = CreateCopy(P1);
    printf("%p, %p %d\n", P1, P2, (int) sizeof P1);
    DestroyPolynomial(&P1);
    DestroyPolynomial(&P2);
    printf("%p, %p\n", P1, P2);
    return 0;
}
