#include <stdio.h>

int array[10] = {45, 78, 12, 36, 98, 26, 32, 56, 74, 65};

void linear_search(int values[], int value)
{
    for (int i = 0; i < 10; i++)
    {
        if (values[i] == value)
        {
            printf("Elemento encontrado na posição %d.\n", i);
            return;
        }
    }
    printf("Elemento não encontrado.\n");
}

void main()
{
    linear_search(array, 65);
}