#include <stdio.h>

int *pointer;
int value = 19;

void main()
{
    pointer = &value;
    printf("O valor do ponteiro é: %d\n", *pointer);
}