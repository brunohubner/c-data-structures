#include <stdio.h>

void main()
{
    int a = 0;

    while (a < 3)
    {
        printf("while %d\n", a);
        a++;
    }

    for (int i = 0; i < 3; i++)
    {
        printf("for %d\n", i);
    }
}