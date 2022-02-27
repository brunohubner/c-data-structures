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

void add(float x, float y)
{
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = x;
    p->y = y;
    p->next = pointList;
    pointList = p;
}

void print()
{
    Point *auxList = pointList;
    while (auxList)
    {
        printf("Ponto: [%.2f , %.2f]\n", auxList->x, auxList->y);
        auxList = auxList->next;
    }
}

void main()
{
    add(3, 7);
    add(9, 2);
    add(4, 6);
    print();
}