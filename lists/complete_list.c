#include <stdio.h>
#include <stdlib.h>

struct point
{
    float x;
    float y;
    struct point *next;
};

typedef struct point Point;

Point *pointList;

int lenght = 0;

void unshif(float x, float y)
{
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    p->next = pointList;
    pointList = p;
    lenght++;
}

void add(float x, float y, int index)
{
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;

    if (index > lenght)
    {
        printf("Posição inválida!\n");
    }
    else
    {
        if (index == 0)
        {
            p->next = pointList;
            pointList = p;
        }
        else
        {
            Point *auxList = pointList;
            int i = 0;
            while (i != index - 1)
            {
                auxList = auxList->next;
                i++;
            }
            p->next = auxList->next;
            auxList->next = p;
        }
        lenght++;
    }
}

void push(float x, float y)
{
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    p->next = NULL;
    if (!pointList)
    {
        pointList = p;
    }
    else
    {
        Point *auxList = pointList;
        while (auxList->next)
        {
            auxList = auxList->next;
        }
        auxList->next = p;
    }
    lenght++;
}

void del(int index)
{
    if (lenght == 0)
    {
        printf("Lista vazia.");
    }
    else if (index > lenght || index < 0)
    {
        printf("Índice inválido");
    }
    else
    {
        if (index == 0)
        {
            pointList = pointList->next;
        }
        else
        {
            Point *auxList = pointList;
            int i = 0;
            while (i != index - 1)
            {
                auxList = auxList->next;
                i++;
            }
            auxList->next = auxList->next->next;
        }
        lenght--;
    }
}

void pop()
{
    del(lenght - 1);
}

void shift()
{
    del(0);
}

void print(Point *point)
{
    if (point)
    {
        printf("Ponto: [%.2f , %.2f]\n", point->x, point->y);
        print(point->next);
    }
}

void main()
{
    push(10, 11);
    push(12, 13);
    push(14, 15);
    pop();
    unshif(6, 7);
    unshif(8, 9);
    shift();
    del(2);

    Point *auxList = pointList;
    print(auxList);
}