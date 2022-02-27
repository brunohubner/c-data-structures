#include <stdio.h>

int num = 12;
float num2 = 13.5;
double num3 = 3.1415;
char text[] = "Bruno";

void main()
{
    printf("int: %d\n", num);
    printf("float: %.2f\n", num2);
    printf("double: %.1f\n", num3);
    printf("char: %s\n", text);
}