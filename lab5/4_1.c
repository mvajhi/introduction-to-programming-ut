#include <stdio.h>

int main()
{
    int input[10] = {0};
    
    for (int i = 0; i < 10; i++)
    {
        printf("Enter number %i: ", i + 1);
        scanf("%i", &input[i]);
    }
    int buffer = 0;
    for (int i = 0; i < 10; i++)
    {
        buffer += input[i];
    }
    printf("avg %f\n", (float)buffer / 10);
    
    return 0;
}