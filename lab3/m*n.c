#include <stdio.h>

int main(void)
{

    int m = 0, n = 0;

    printf("enter two numbers with space: ");
    scanf("%i %i", &m, &n);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%i\t", i * j);
        }
        printf("\n");
    }

    return 0;
}