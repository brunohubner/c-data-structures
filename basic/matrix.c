#include <stdio.h>

int mat[2][3];

void main()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite um número: ");
            scanf("%d", &mat[i][j]);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("mat[%d][%d] = %d\n", i, j, mat[i][j]);
        }
    }
}