#include <stdio.h>
#include <stdlib.h>

struct point
{
    float x;
    float y;
};

typedef struct point Point;

void main()
{
    Point *p = (Point *)malloc(sizeof(Point));
    p->x = 3.1415;
    p->y = 7.8985;
    printf("Ponto X: %.4f\nPonto Y: %.4f\n", p->x, p->y);
}