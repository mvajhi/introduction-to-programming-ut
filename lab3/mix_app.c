#include <stdio.h>
#define True 1
#define False 0

int multiplication(void);
int triangle(void);
int is_buffer_free(void);
int error(void);

int main(void)
{
    int option = 0;
    int loop = True, success_input = True;

    printf("\n\n\n\n\n");

    while (loop)
    {
        printf("\n1. multiplication\n2. triangle\n\n\n0. exit\n\nEnter: ");
        success_input = scanf("%i", &option);

        if (!is_buffer_free() && !success_input)
        {
            option = 3;
        }

        switch (option)
        {
        case 0:
            loop = False;
            break;
        case 1:
            multiplication();
            break;
        case 2:
            triangle();
            break;
        default:
            error();
            break;
        }
    }
}

/*check buffer is free and if not clear that*/
int is_buffer_free(void)
{
    int c;
    int is_free = True;
    while ((c = getchar()) != '\n')
    {
        is_free = False;
    }
    return is_free;
}

int error(void)
{
    printf("\n\n\n\n\n\n\n\e[0;31mTry again\e[m\n\n");
    return 0;
}

int triangle(void)
{

    int length = 0;

    printf("enter length: ");
    scanf("%i", &length);

    if (!is_buffer_free() || length % 2 != 1 || length < 3)
    {
        error();
        return 0;
    }

    for (int i = 1; i <= length; i += 2)
    {
        for (int j = 0; j < (length - i + 1) / 2; j++)
        {
            printf("-");
        }
        for (int k = 0; k < i; k++)
        {
            printf("*");
        }
        for (int j = 0; j < (length - i + 1) / 2; j++)
        {
            printf("-");
        }
        printf("\n");
    }

    return 0;
}

int multiplication(void)
{

    int m = 0, n = 0;

    printf("enter two numbers with space: ");
    scanf("%i %i", &m, &n);

    if (!is_buffer_free() || m < 1 || n < 1)
    {
        error();
        return 0;
    }

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
