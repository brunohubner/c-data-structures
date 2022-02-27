#include <stdio.h>
#include <stdlib.h>

struct dish
{
    char color;
    struct dish *next;
};

typedef struct dish Dish;

Dish *stack;

void add(char color)
{
    Dish *d = (Dish *)malloc(sizeof(Dish));
    d->color = color;
    d->next = stack;
    stack = d;
}

void rem()
{
    if (!stack)
    {
        printf("Pilha vazia.");
    }
    else
    {
        stack = stack->next;
    }
}

void imprime(Dish *dish)
{
    if (dish)
    {
        printf("Cor do prato: %c\n", dish->color);
        imprime(dish->next);
    }
}

void main()
{

    add('R');
    add('G');
    add('B');
    add('Y');

    rem();

    Dish *stackAux = stack;
    imprime(stackAux);
}