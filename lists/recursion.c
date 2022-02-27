#include <stdio.h>

int potency(int base, int exponent)
{
    return exponent == 1 ? base : base * potency(base, exponent - 1);
}

void main()
{
    int v = potency(2, 4);
    printf("%d\n", v);
}