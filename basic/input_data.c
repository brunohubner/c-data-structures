#include <stdio.h>

void main()
{
    char letra;
    int num;
    printf("Informe uma letra: ");
    scanf("%c", &letra);
    printf("Informe um número: ");
    scanf("%d", &num);
    int soma = num + 10;
    printf("letra: %c. soma: %d.\n", letra, soma);
}