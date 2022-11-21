#include <stdio.h>
int main()
{
    int array[100], n, c = 0, d, swap; /*we should set number for c*/
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers\n", n); /*&n is a pointer, not int*/

    while (c < n) /*array start 0 and when we want get n number, we should set number 0 to n-1*/
    {
        scanf("%d", &array[c]);
        c++;
    }
    for (c = 0; c < n - 1; c++)
    {
        for (d = 0; d < n - c - 1; d++)
        {
            if (array[d] > array[d + 1])
            {
                swap = array[d]; /*if we want to swap we should write this way*/
                array[d] = array[d + 1];
                array[d + 1] = swap;
            }
        }
    }
    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++) /*array start 0 and when we want print n number, we should set number 0 to n-1*/
        printf("%d\n", array[c]);
    return 0;
}
