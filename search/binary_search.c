#include <stdio.h>

int array[100];

void main()
{
    for (int i = 0; i <= 100; i++)
    {
        array[i] = i * 3;
    }

    int num = 500;
    int comparissions = 0;
    int to_continue = 1;
    int start = 0;
    int end = 100;

    while (to_continue == 1)
    {
        comparissions++;
        int pivot = (start + end) / 2;
        if (array[pivot] == num)
        {
            printf("Número encontrado na posição %d\n", pivot);
            to_continue = 0;
        }
        else
        {
            if (num > array[pivot])
            {
                start = pivot + 1;
            }
            else
            {
                end = pivot - 1;
            }
        }
        if (end < start)
        {
            printf("Número não encontrado.\n");
            to_continue = 0;
        }
    }
    printf("Comparações: %d\n", comparissions);
}