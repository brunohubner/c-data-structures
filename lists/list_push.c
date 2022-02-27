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

    Point *auxList = pointList;
    print(auxList);
}