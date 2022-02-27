#include <stdio.h>

struct pessoa
{
    int age;
    float height;
};

typedef struct pessoa Pessoa;

void main()
{
    Pessoa p;
    p.age = 22;
    p.height = 1.77;

    printf("Idade: %d. Altura: %.2f\n", p.age, p.height);
}