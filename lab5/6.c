#include <stdio.h>

#define MAX_WORD 21
#define array_lenght 5

int main()
{
    char input [array_lenght][MAX_WORD];
    
    for (int i = 0; i < array_lenght; i++)
    {
        printf("Enter string %i: ", i + 1);
        scanf("%s", &input[i]);
    }
    

    
    int buffer = 0;
    for (int i = 1; i < array_lenght; i++)
    {
        for(int j = 0; input[i][j] != '\0'; j++)
        {
            for(int k = 0; input[0][k] != '\0'; k++)
            {
                if (input[0][k] == input[i][j] || input[0][k] + 32 == input[i][j] || input[0][k] - 32 == input[i][j])
                {
                    input[i][j] = '$';
                }
            }
        }
    }
    
    for (int i = 0; i < array_lenght; i++)
    {
        printf("%s\n", input[i]);
    }
    
    return 0;
}
