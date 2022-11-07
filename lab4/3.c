#include<stdio.h>
int g(int y){
int j = 2;
y = j * 3;
return y;
}
int f(int x){
return g(x);
}
int main()
{
int a = 10;
printf("%d", f(a));
printf("\nf return g and input g replace with (2 * 3) and return 6 so f return 6 and main print 6. \n");
return 0;
}
