#include <stdio.h>
#include <stdlib.h>

int main()
{
    int p[5][5], q[5][5], mul[5][5], R, C, i, j, k;

    printf("Enter the number of rows: ");
    scanf("%d", &R);

    printf("Enter the number of columns: ");
    scanf("%d", &C);

    printf("Enter the elements of the first matrix:\\n");
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }

    printf("Enter the elements of the second matrix:\\n");

    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            scanf("%d", &q[i][j]);
        }
    }

    printf("Multiplication of the two matrices:\n");
    
    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            mul[i][j] = 0;
            for (k = 0; k < C; k++)
            {
                mul[i][j] += p[i][k] * q[k][j];
            }
        }
    }

    for (i = 0; i < R; i++)
    {
        for (j = 0; j < C; j++)
        {
            printf("%d\t", mul[i][j]);
        }
        printf("\n");
    }
    return 0;
}

