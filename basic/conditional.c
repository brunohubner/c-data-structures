#include <stdio.h>

// && and operator
// || or operator
// !  negation operator

void main()
{
    int age;
    printf("Qual sua idade? ");
    scanf("%d", &age);

    if (age >= 18)
    {
        printf("Você é de maior!\n");
    }
    else
    {
        printf("Você é de menor!\n");
    }
}