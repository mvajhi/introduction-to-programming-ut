#include <stdio.h>

int main(void)
{
    int input = 0;

    printf("enter your number: ");
    scanf("%i", &input);

    if (input == 5)
    {
        printf("your number is 5.\n");
    }
    else if (input > 5)
    {
        printf("your number bigger than 5.\n");
    }
    else
    {
        printf("your number smaller than 5.\n");
    }
    return 0;
}