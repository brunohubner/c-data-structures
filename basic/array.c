#include <stdio.h>

int v[5];

void main()
{
    for (int i = 0; i < 5; i++)
    {
        printf("Informe um número: ");
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", v[i]);
    }
}