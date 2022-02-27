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

void add(float x, float y)
{
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    p->next = pointList;
    pointList = p;
    lenght++;
}

void insert(float x, float y, int index)
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

void delete (int index)
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
    push(1, 2);
    push(3, 4);
    push(5, 6);

    insert(7, 8, 2);
    insert(9, 0, 4);
    insert(5, 8, 0);
    // delete (0);

    Point *auxList = pointList;
    print(auxList);
}