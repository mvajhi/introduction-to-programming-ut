#include <stdio.h>

int main()
{
    int input[100] = {0};
    int n = 0;
    printf("Enter n: ");
    scanf("%i", &n);
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter number %i: ", i + 1);
        scanf("%i", &input[i]);
    }
    int buffer = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if ( input[j] > input[i])
            {
                input[i] = input[j];
                break;
            }
            if (j == 0)
            {
                input[i] = 0;
            }
        }
    }
    // input[0] always 0
    input[0] = 0;
    for (int i = 0; i < n; i++)
    {
        printf("number %i: %i\n", i + 1, input[i]);
    }
    
    return 0;
}