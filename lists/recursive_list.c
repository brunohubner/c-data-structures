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
    add(3, 7);
    add(9, 2);
    add(4, 6);

    Point *auxList = pointList;
    print(auxList);
}