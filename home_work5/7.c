#include <stdio.h>
int main(){
	char array[][4] = { 'a','b','c','d','e','f','g','h'};
	char (*ptr)[4] = array;
	printf("%c %c\n", (*ptr)[2], (*ptr)[3]);
	ptr+= 1;
	printf("%c %c\n", (*ptr)[2], (*ptr)[3]);
	return 0;
} 
